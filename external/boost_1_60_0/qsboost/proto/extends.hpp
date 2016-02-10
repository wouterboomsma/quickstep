///////////////////////////////////////////////////////////////////////////////
/// \file extends.hpp
/// Macros and a base class for defining end-user expression types
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_EXTENDS_HPP_EAN_11_1_2006
#define QSBOOST_PROTO_EXTENDS_HPP_EAN_11_1_2006

#include <cstddef> // for offsetof
#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/preprocessor/facilities/empty.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/iteration/local.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <qsboost/preprocessor/seq/for_each.hpp>
#include <qsboost/utility/addressof.hpp>
#include <qsboost/utility/result_of.hpp>
#include <qsboost/proto/proto_fwd.hpp>
#include <qsboost/proto/traits.hpp>
#include <qsboost/proto/expr.hpp>
#include <qsboost/proto/args.hpp>
#include <qsboost/proto/traits.hpp>
#include <qsboost/proto/generate.hpp>
#include <qsboost/proto/detail/remove_typename.hpp>

#if defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable : 4714) // function 'xxx' marked as __forceinline not inlined
#endif

namespace qsboost { namespace proto
{
    #ifdef __GNUC__
    /// INTERNAL ONLY
    ///
    # define QSBOOST_PROTO_ADDROF(x) ((char const volatile*)qsboost::addressof(x))
    /// INTERNAL ONLY
    ///
    # define QSBOOST_PROTO_OFFSETOF(s,m) (QSBOOST_PROTO_ADDROF((((s *)this)->m)) - QSBOOST_PROTO_ADDROF(*((s *)this)))
    #else
    /// INTERNAL ONLY
    ///
    # define QSBOOST_PROTO_OFFSETOF offsetof
    #endif

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_CONST() const

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_TYPENAME() typename

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_TEMPLATE_YES_(Z, N) template<QSBOOST_PP_ENUM_PARAMS_Z(Z, N, typename A)>

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_TEMPLATE_NO_(Z, N)

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_FUN_OP_IMPL_(Z, N, DATA, Const)                                      \
        QSBOOST_PP_IF(N, QSBOOST_PROTO_TEMPLATE_YES_, QSBOOST_PROTO_TEMPLATE_NO_)(Z, N)                   \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        typename QSBOOST_PROTO_RESULT_OF<                                                             \
            proto_generator(                                                                        \
                typename qsboost::proto::result_of::QSBOOST_PP_CAT(funop, N)<                           \
                    proto_derived_expr Const()                                                      \
                  , proto_domain                                                                    \
                    QSBOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, const A)                                  \
                >::type                                                                             \
            )                                                                                       \
        >::type const                                                                               \
        operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, const &a)) Const()                       \
        {                                                                                           \
            typedef qsboost::proto::result_of::QSBOOST_PP_CAT(funop, N)<                                \
                proto_derived_expr Const()                                                          \
              , proto_domain                                                                        \
                QSBOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, const A)                                      \
            > funop;                                                                                \
            return proto_generator()(                                                               \
                funop::call(                                                                        \
                    *static_cast<proto_derived_expr Const() *>(this)                                \
                    QSBOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, a)                                        \
                )                                                                                   \
            );                                                                                      \
        }                                                                                           \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(Const)                                         \
        template<typename... A>                                                                     \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        typename QSBOOST_PROTO_RESULT_OF<                                                             \
            proto_generator(                                                                        \
                typename qsboost::proto::result_of::funop<                                            \
                    proto_derived_expr Const()(A const &...)                                        \
                  , proto_derived_expr                                                              \
                  , proto_domain                                                                    \
                >::type                                                                             \
            )                                                                                       \
        >::type const                                                                               \
        operator ()(A const &...a) Const()                                                          \
        {                                                                                           \
            typedef qsboost::proto::result_of::funop<                                                 \
                proto_derived_expr Const()(A const &...)                                            \
              , proto_derived_expr                                                                  \
              , proto_domain                                                                        \
            > funop;                                                                                \
            return proto_generator()(                                                               \
                funop::call(                                                                        \
                    *static_cast<proto_derived_expr Const() *>(this)                                \
                  , a...                                                                            \
                )                                                                                   \
            );                                                                                      \
        }                                                                                           \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_FUN_OP_CONST(Z, N, DATA)                                             \
        QSBOOST_PROTO_DEFINE_FUN_OP_IMPL_(Z, N, DATA, QSBOOST_PROTO_CONST)                              \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_FUN_OP_NON_CONST(Z, N, DATA)                                         \
        QSBOOST_PROTO_DEFINE_FUN_OP_IMPL_(Z, N, DATA, QSBOOST_PP_EMPTY)                                 \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_FUN_OP(Z, N, DATA)                                                   \
        QSBOOST_PROTO_DEFINE_FUN_OP_CONST(Z, N, DATA)                                                 \
        QSBOOST_PROTO_DEFINE_FUN_OP_NON_CONST(Z, N, DATA)                                             \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_EXTENDS_CHILD(Z, N, DATA)                                                   \
        typedef                                                                                     \
            typename proto_base_expr::QSBOOST_PP_CAT(proto_child, N)                                  \
        QSBOOST_PP_CAT(proto_child, N);                                                               \
        /**/

    #define QSBOOST_PROTO_BASIC_EXTENDS_(Expr, Derived, Domain)                                       \
        Expr proto_expr_;                                                                           \
                                                                                                    \
        typedef Expr proto_base_expr_; /**< INTERNAL ONLY */                                        \
        typedef typename proto_base_expr_::proto_base_expr proto_base_expr;                         \
        typedef QSBOOST_PROTO_REMOVE_TYPENAME(Domain) proto_domain;                                   \
        typedef Derived proto_derived_expr;                                                         \
        typedef Domain::proto_generator proto_generator;                                            \
        typedef typename proto_base_expr::proto_tag proto_tag;                                      \
        typedef typename proto_base_expr::proto_args proto_args;                                    \
        typedef typename proto_base_expr::proto_arity proto_arity;                                  \
        typedef typename proto_base_expr::proto_grammar proto_grammar;                              \
        typedef typename proto_base_expr::address_of_hack_type_ proto_address_of_hack_type_;        \
        typedef void proto_is_expr_; /**< INTERNAL ONLY */                                          \
        static const long proto_arity_c = proto_base_expr::proto_arity_c;                           \
        typedef qsboost::proto::tag::proto_expr<proto_tag, proto_domain> fusion_tag;                  \
        QSBOOST_PP_REPEAT(QSBOOST_PROTO_MAX_ARITY, QSBOOST_PROTO_EXTENDS_CHILD, ~)                        \
                                                                                                    \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        static proto_derived_expr const make(Expr const &e)                                         \
        {                                                                                           \
            proto_derived_expr that = {e};                                                          \
            return that;                                                                            \
        }                                                                                           \
                                                                                                    \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        proto_base_expr &proto_base()                                                               \
        {                                                                                           \
            return this->proto_expr_.proto_base();                                                  \
        }                                                                                           \
                                                                                                    \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        proto_base_expr const &proto_base() const                                                   \
        {                                                                                           \
            return this->proto_expr_.proto_base();                                                  \
        }                                                                                           \
                                                                                                    \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        operator proto_address_of_hack_type_() const                                                \
        {                                                                                           \
            return qsboost::addressof(this->proto_base().child0);                                     \
        }                                                                                           \
        /**/

    #define QSBOOST_PROTO_BASIC_EXTENDS(Expr, Derived, Domain)                                        \
        QSBOOST_PROTO_BASIC_EXTENDS_(Expr, Derived, Domain)                                           \
        typedef void proto_is_aggregate_;                                                           \
        /**< INTERNAL ONLY */

    #define QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_IMPL_(This, Const, Typename)                            \
        QSBOOST_PROTO_DISABLE_MSVC_C4522                                                              \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        Typename() QSBOOST_PROTO_RESULT_OF<                                                           \
            Typename() This::proto_generator(                                                       \
                Typename() qsboost::proto::base_expr<                                                 \
                    Typename() This::proto_domain                                                   \
                  , qsboost::proto::tag::assign                                                       \
                  , qsboost::proto::list2<                                                            \
                        This &                                                                      \
                      , This Const() &                                                              \
                    >                                                                               \
                >::type                                                                             \
            )                                                                                       \
        >::type const                                                                               \
        operator =(This Const() &a)                                                                 \
        {                                                                                           \
            typedef                                                                                 \
                Typename() qsboost::proto::base_expr<                                                 \
                    Typename() This::proto_domain                                                   \
                  , qsboost::proto::tag::assign                                                       \
                  , qsboost::proto::list2<                                                            \
                        This &                                                                      \
                      , This Const() &                                                              \
                    >                                                                               \
                >::type                                                                             \
            that_type;                                                                              \
            that_type const that = {                                                                \
                *this                                                                               \
              , a                                                                                   \
            };                                                                                      \
            return Typename() This::proto_generator()(that);                                        \
        }                                                                                           \
        /**/

        // MSVC 8.0 and higher seem to need copy-assignment operator to be overloaded on *both*
        // const and non-const rhs arguments.
    #if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1600)) && (QSBOOST_MSVC > 1310)
        #define QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(This, Typename)                                    \
            QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_IMPL_(This, QSBOOST_PP_EMPTY, Typename)                   \
            QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_IMPL_(This, QSBOOST_PROTO_CONST, Typename)                \
            /**/
    #else
        #define QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(This, Typename)                                    \
            QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_IMPL_(This, QSBOOST_PROTO_CONST, Typename)                \
            /**/
    #endif

        /// INTERNAL ONLY
        ///
    #define QSBOOST_PROTO_EXTENDS_ASSIGN_IMPL_(ThisConst, ThatConst)                                  \
        template<typename A>                                                                        \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        typename QSBOOST_PROTO_RESULT_OF<                                                             \
            proto_generator(                                                                        \
                typename qsboost::proto::base_expr<                                                   \
                    proto_domain                                                                    \
                  , qsboost::proto::tag::assign                                                       \
                  , qsboost::proto::list2<                                                            \
                        proto_derived_expr ThisConst() &                                            \
                      , typename qsboost::proto::result_of::as_child<A ThatConst(), proto_domain>::type \
                    >                                                                               \
                >::type                                                                             \
            )                                                                                       \
        >::type const                                                                               \
        operator =(A ThatConst() &a) ThisConst()                                                    \
        {                                                                                           \
            typedef                                                                                 \
                typename qsboost::proto::base_expr<                                                   \
                    proto_domain                                                                    \
                  , qsboost::proto::tag::assign                                                       \
                  , qsboost::proto::list2<                                                            \
                        proto_derived_expr ThisConst() &                                            \
                      , typename qsboost::proto::result_of::as_child<A ThatConst(), proto_domain>::type \
                    >                                                                               \
                >::type                                                                             \
            that_type;                                                                              \
            that_type const that = {                                                                \
                *static_cast<proto_derived_expr ThisConst() *>(this)                                \
              , qsboost::proto::as_child<proto_domain>(a)                                             \
            };                                                                                      \
            return proto_generator()(that);                                                         \
        }                                                                                           \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN_CONST_()                                                     \
        QSBOOST_PROTO_EXTENDS_ASSIGN_IMPL_(QSBOOST_PROTO_CONST, QSBOOST_PP_EMPTY)                         \
        QSBOOST_PROTO_EXTENDS_ASSIGN_IMPL_(QSBOOST_PROTO_CONST, QSBOOST_PROTO_CONST)                      \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN_NON_CONST_()                                                 \
        QSBOOST_PROTO_EXTENDS_ASSIGN_IMPL_(QSBOOST_PP_EMPTY, QSBOOST_PP_EMPTY)                            \
        QSBOOST_PROTO_EXTENDS_ASSIGN_IMPL_(QSBOOST_PP_EMPTY, QSBOOST_PROTO_CONST)                         \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN_()                                                           \
        QSBOOST_PROTO_EXTENDS_ASSIGN_CONST_()                                                         \
        QSBOOST_PROTO_EXTENDS_ASSIGN_NON_CONST_()                                                     \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN_CONST()                                                      \
        QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(proto_derived_expr, QSBOOST_PROTO_TYPENAME)                  \
        QSBOOST_PROTO_EXTENDS_ASSIGN_CONST_()                                                         \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN_NON_CONST()                                                  \
        QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(proto_derived_expr, QSBOOST_PROTO_TYPENAME)                  \
        QSBOOST_PROTO_EXTENDS_ASSIGN_NON_CONST_()                                                     \
        /**/

    #define QSBOOST_PROTO_EXTENDS_ASSIGN()                                                            \
        QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(proto_derived_expr, QSBOOST_PROTO_TYPENAME)                  \
        QSBOOST_PROTO_EXTENDS_ASSIGN_()                                                               \
        /**/

        /// INTERNAL ONLY
        ///
    #define QSBOOST_PROTO_EXTENDS_SUBSCRIPT_IMPL_(ThisConst, ThatConst)                               \
        template<typename A>                                                                        \
        QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                            \
        typename QSBOOST_PROTO_RESULT_OF<                                                             \
            proto_generator(                                                                        \
                typename qsboost::proto::base_expr<                                                   \
                    proto_domain                                                                    \
                  , qsboost::proto::tag::subscript                                                    \
                  , qsboost::proto::list2<                                                            \
                        proto_derived_expr ThisConst() &                                            \
                      , typename qsboost::proto::result_of::as_child<A ThatConst(), proto_domain>::type \
                    >                                                                               \
                >::type                                                                             \
            )                                                                                       \
        >::type const                                                                               \
        operator [](A ThatConst() &a) ThisConst()                                                   \
        {                                                                                           \
            typedef                                                                                 \
                typename qsboost::proto::base_expr<                                                   \
                    proto_domain                                                                    \
                  , qsboost::proto::tag::subscript                                                    \
                  , qsboost::proto::list2<                                                            \
                        proto_derived_expr ThisConst() &                                            \
                      , typename qsboost::proto::result_of::as_child<A ThatConst(), proto_domain>::type \
                    >                                                                               \
                >::type                                                                             \
            that_type;                                                                              \
            that_type const that = {                                                                \
                *static_cast<proto_derived_expr ThisConst() *>(this)                                \
              , qsboost::proto::as_child<proto_domain>(a)                                             \
            };                                                                                      \
            return proto_generator()(that);                                                         \
        }                                                                                           \
        /**/

    #define QSBOOST_PROTO_EXTENDS_SUBSCRIPT_CONST()                                                   \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_IMPL_(QSBOOST_PROTO_CONST, QSBOOST_PP_EMPTY)                      \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_IMPL_(QSBOOST_PROTO_CONST, QSBOOST_PROTO_CONST)                   \
        /**/

    #define QSBOOST_PROTO_EXTENDS_SUBSCRIPT_NON_CONST()                                               \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_IMPL_(QSBOOST_PP_EMPTY, QSBOOST_PP_EMPTY)                         \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_IMPL_(QSBOOST_PP_EMPTY, QSBOOST_PROTO_CONST)                      \
        /**/

    #define QSBOOST_PROTO_EXTENDS_SUBSCRIPT()                                                         \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_CONST()                                                       \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT_NON_CONST()                                                   \
        /**/

        /// INTERNAL ONLY
        ///
    #define QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
        template<typename Sig>                                                                      \
        struct result                                                                               \
        {                                                                                           \
            typedef                                                                                 \
                typename QSBOOST_PROTO_RESULT_OF<                                                     \
                    proto_generator(                                                                \
                        typename qsboost::proto::result_of::funop<                                    \
                            Sig                                                                     \
                          , proto_derived_expr                                                      \
                          , proto_domain                                                            \
                        >::type                                                                     \
                    )                                                                               \
                >::type const                                                                       \
            type;                                                                                   \
        };                                                                                          \
        /**/

    #ifndef QSBOOST_NO_CXX11_VARIADIC_TEMPLATES
        #define QSBOOST_PROTO_EXTENDS_FUNCTION_CONST()                                                \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(QSBOOST_PROTO_CONST)                             \
            /**/

        #define QSBOOST_PROTO_EXTENDS_FUNCTION_NON_CONST()                                            \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(QSBOOST_PP_EMPTY)                                \
            /**/

        #define QSBOOST_PROTO_EXTENDS_FUNCTION()                                                      \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(QSBOOST_PP_EMPTY)                                \
            QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(QSBOOST_PROTO_CONST)                             \
            /**/
    #else
        #define QSBOOST_PROTO_EXTENDS_FUNCTION_CONST()                                                \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PP_REPEAT_FROM_TO(                                                                \
                0                                                                                   \
              , QSBOOST_PROTO_MAX_FUNCTION_CALL_ARITY                                                 \
              , QSBOOST_PROTO_DEFINE_FUN_OP_CONST                                                     \
              , ~                                                                                   \
            )                                                                                       \
            /**/

        #define QSBOOST_PROTO_EXTENDS_FUNCTION_NON_CONST()                                            \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PP_REPEAT_FROM_TO(                                                                \
                0                                                                                   \
              , QSBOOST_PROTO_MAX_FUNCTION_CALL_ARITY                                                 \
              , QSBOOST_PROTO_DEFINE_FUN_OP_NON_CONST                                                 \
              , ~                                                                                   \
            )                                                                                       \
            /**/

        #define QSBOOST_PROTO_EXTENDS_FUNCTION()                                                      \
            QSBOOST_PROTO_EXTENDS_FUNCTION_()                                                         \
            QSBOOST_PP_REPEAT_FROM_TO(                                                                \
                0                                                                                   \
              , QSBOOST_PROTO_MAX_FUNCTION_CALL_ARITY                                                 \
              , QSBOOST_PROTO_DEFINE_FUN_OP                                                           \
              , ~                                                                                   \
            )                                                                                       \
            /**/
    #endif

    #define QSBOOST_PROTO_EXTENDS(Expr, Derived, Domain)                                              \
        QSBOOST_PROTO_BASIC_EXTENDS(Expr, Derived, Domain)                                            \
        QSBOOST_PROTO_EXTENDS_ASSIGN()                                                                \
        QSBOOST_PROTO_EXTENDS_SUBSCRIPT()                                                             \
        QSBOOST_PROTO_EXTENDS_FUNCTION()                                                              \
        /**/

    #define QSBOOST_PROTO_EXTENDS_USING_ASSIGN(Derived)                                               \
        typedef typename Derived::proto_extends proto_extends;                                      \
        using proto_extends::operator =;                                                            \
        QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(Derived, QSBOOST_PROTO_TYPENAME)                             \
        /**/

    #define QSBOOST_PROTO_EXTENDS_USING_ASSIGN_NON_DEPENDENT(Derived)                                 \
        typedef Derived::proto_extends proto_extends;                                               \
        using proto_extends::operator =;                                                            \
        QSBOOST_PROTO_EXTENDS_COPY_ASSIGN_(Derived, QSBOOST_PP_EMPTY)                                   \
        /**/

    namespace exprns_
    {
        /// \brief Empty type to be used as a dummy template parameter of
        ///     POD expression wrappers. It allows argument-dependent lookup
        ///     to find Proto's operator overloads.
        ///
        /// \c proto::is_proto_expr allows argument-dependent lookup
        ///     to find Proto's operator overloads. For example:
        ///
        /// \code
        /// template<typename T, typename Dummy = proto::is_proto_expr>
        /// struct my_terminal
        /// {
        ///     BOOST_PROTO_BASIC_EXTENDS(
        ///         typename proto::terminal<T>::type
        ///       , my_terminal<T>
        ///       , default_domain
        ///     )
        /// };
        ///
        /// // ...
        /// my_terminal<int> _1, _2;
        /// _1 + _2; // OK, uses proto::operator+
        /// \endcode
        ///
        /// Without the second \c Dummy template parameter, Proto's operator
        /// overloads would not be considered by name lookup.
        struct is_proto_expr
        {};

        /// \brief extends\<\> class template for adding behaviors to a Proto expression template
        ///
        template<
            typename Expr
          , typename Derived
          , typename Domain     // = proto::default_domain
          , long Arity          // = Expr::proto_arity_c
        >
        struct extends
        {
            QSBOOST_FORCEINLINE
            extends()
              : proto_expr_()
            {}

            QSBOOST_FORCEINLINE
            extends(extends const &that)
              : proto_expr_(that.proto_expr_)
            {}

            QSBOOST_FORCEINLINE
            extends(Expr const &expr_)
              : proto_expr_(expr_)
            {}

            typedef extends proto_extends;
            QSBOOST_PROTO_BASIC_EXTENDS_(Expr, Derived, typename Domain)
            QSBOOST_PROTO_EXTENDS_ASSIGN_CONST_()
            QSBOOST_PROTO_EXTENDS_SUBSCRIPT_CONST()

            // Instead of using BOOST_PROTO_EXTENDS_FUNCTION, which uses
            // nested preprocessor loops, use file iteration here to generate
            // the operator() overloads, which is more efficient.
            #include <qsboost/proto/detail/extends_funop_const.hpp>
        };

        /// \brief extends\<\> class template for adding behaviors to a Proto expression template
        ///
        template<typename Expr, typename Derived, typename Domain>
        struct extends<Expr, Derived, Domain, 0>
        {
            QSBOOST_FORCEINLINE
            extends()
              : proto_expr_()
            {}

            QSBOOST_FORCEINLINE
            extends(extends const &that)
              : proto_expr_(that.proto_expr_)
            {}

            QSBOOST_FORCEINLINE
            extends(Expr const &expr_)
              : proto_expr_(expr_)
            {}

            typedef extends proto_extends;
            QSBOOST_PROTO_BASIC_EXTENDS_(Expr, Derived, typename Domain)
            QSBOOST_PROTO_EXTENDS_ASSIGN_()
            QSBOOST_PROTO_EXTENDS_SUBSCRIPT()

            // Instead of using BOOST_PROTO_EXTENDS_FUNCTION, which uses
            // nested preprocessor loops, use file iteration here to generate
            // the operator() overloads, which is more efficient.
            #include <qsboost/proto/detail/extends_funop.hpp>
        };

        /// INTERNAL ONLY
        ///
        template<typename This, typename Fun, typename Domain>
        struct virtual_member
        {
            typedef Domain proto_domain;
            typedef typename Domain::proto_generator proto_generator;
            typedef virtual_member<This, Fun, Domain> proto_derived_expr;
            typedef tag::member proto_tag;
            typedef list2<This &, expr<tag::terminal, term<Fun> > const &> proto_args;
            typedef mpl::long_<2> proto_arity;
            typedef detail::not_a_valid_type proto_address_of_hack_type_;
            typedef void proto_is_expr_; /**< INTERNAL ONLY */
            static const long proto_arity_c = 2;
            typedef qsboost::proto::tag::proto_expr<proto_tag, Domain> fusion_tag;
            typedef This &proto_child0;
            typedef expr<tag::terminal, term<Fun> > const &proto_child1;
            typedef expr<proto_tag, proto_args, proto_arity_c> proto_base_expr;
            typedef basic_expr<proto_tag, proto_args, proto_arity_c> proto_grammar;
            typedef void proto_is_aggregate_; /**< INTERNAL ONLY */

            QSBOOST_PROTO_EXTENDS_ASSIGN_()
            QSBOOST_PROTO_EXTENDS_SUBSCRIPT()

            // Instead of using BOOST_PROTO_EXTENDS_FUNCTION, which uses
            // nested preprocessor loops, use file iteration here to generate
            // the operator() overloads, which is more efficient.
            #define QSBOOST_PROTO_NO_WAVE_OUTPUT
            #include <qsboost/proto/detail/extends_funop.hpp>
            #undef QSBOOST_PROTO_NO_WAVE_OUTPUT

            QSBOOST_FORCEINLINE
            proto_base_expr const proto_base() const
            {
                proto_base_expr that = {this->child0(), this->child1()};
                return that;
            }

            QSBOOST_FORCEINLINE
            proto_child0 child0() const
            {
                using std::size_t;
                return *(This *)((char *)this - QSBOOST_PROTO_OFFSETOF(This, proto_member_union_start_));
            }

            QSBOOST_FORCEINLINE
            proto_child1 child1() const
            {
                static expr<tag::terminal, term<Fun>, 0> const that = {Fun()};
                return that;
            }
        };

        /// INTERNAL ONLY
        ///
        #define QSBOOST_PROTO_EXTENDS_MEMBER_(R, DOMAIN, ELEM)                                            \
            qsboost::proto::exprns_::virtual_member<                                                      \
                proto_derived_expr                                                                      \
              , QSBOOST_PP_TUPLE_ELEM(2, 0, ELEM)                                                         \
              , DOMAIN                                                                                  \
            > QSBOOST_PP_TUPLE_ELEM(2, 1, ELEM);                                                          \
            /**/

        /// \brief For declaring virtual data members in an extension class.
        ///
        #define QSBOOST_PROTO_EXTENDS_MEMBERS_WITH_DOMAIN(SEQ, DOMAIN)                                    \
            union                                                                                       \
            {                                                                                           \
                char proto_member_union_start_;                                                         \
                QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PROTO_EXTENDS_MEMBER_, DOMAIN, SEQ)                         \
            };                                                                                          \
            /**/

        /// \brief For declaring virtual data members in an extension class.
        ///
        #define QSBOOST_PROTO_EXTENDS_MEMBERS(SEQ)                                                        \
            QSBOOST_PROTO_EXTENDS_MEMBERS_WITH_DOMAIN(SEQ, proto_domain)                                  \
            /**/

    }

}}

#if defined(_MSC_VER)
# pragma warning(pop)
#endif

#endif

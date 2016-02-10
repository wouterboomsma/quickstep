///////////////////////////////////////////////////////////////////////////////
/// \file operators.hpp
/// Contains all the overloaded operators that make it possible to build
/// Proto expression trees.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_OPERATORS_HPP_EAN_04_01_2005
#define QSBOOST_PROTO_OPERATORS_HPP_EAN_04_01_2005

#include <qsboost/config.hpp>
#include <qsboost/preprocessor/punctuation/comma.hpp>
#include <qsboost/mpl/logical.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/proto/proto_fwd.hpp>
#include <qsboost/proto/tags.hpp>
#include <qsboost/proto/domain.hpp>
#include <qsboost/proto/matches.hpp>
#include <qsboost/proto/generate.hpp>
#include <qsboost/proto/make_expr.hpp>

#if defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable : 4714) // function 'xxx' marked as __forceinline not inlined
#endif

namespace qsboost { namespace proto
{
    namespace detail
    {
        template<typename MakeExpr, typename Grammar>
        struct lazy_matches
          : proto::matches<typename MakeExpr::type, Grammar>
        {};

        template<typename Domain, typename Grammar, typename Trait, typename Tag, typename Arg>
        struct enable_unary
          : qsboost::lazy_enable_if_c<
                qsboost::mpl::and_<
                    Trait
                  , lazy_matches<result_of::make_expr<Tag, basic_default_domain, Arg>, Grammar>
                >::value
              , result_of::make_expr<Tag, Domain, Arg>
            >
        {};

        template<typename Domain, typename Trait, typename Tag, typename Arg>
        struct enable_unary<Domain, proto::_, Trait, Tag, Arg &>
          : qsboost::lazy_enable_if_c<
                Trait::value
              , result_of::make_expr<Tag, Domain, Arg &>
            >
        {};

        template<typename Trait, typename Tag, typename Arg>
        struct enable_unary<deduce_domain, not_a_grammar, Trait, Tag, Arg &>
          : enable_unary<
                typename domain_of<Arg>::type
              , typename domain_of<Arg>::type::proto_grammar
              , Trait
              , Tag
              , Arg &
            >
        {};

        template<typename Domain, typename Grammar, typename Trait, typename Tag, typename Left, typename Right>
        struct enable_binary
          : qsboost::lazy_enable_if_c<
                qsboost::mpl::and_<
                    Trait
                  , lazy_matches<result_of::make_expr<Tag, basic_default_domain, Left, Right>, Grammar>
                >::value
              , result_of::make_expr<Tag, Domain, Left, Right>
            >
        {};

        template<typename Domain, typename Trait, typename Tag, typename Left, typename Right>
        struct enable_binary<Domain, proto::_, Trait, Tag, Left &, Right &>
          : qsboost::lazy_enable_if_c<
                Trait::value
              , result_of::make_expr<Tag, Domain, Left &, Right &>
            >
        {};

        template<typename Trait, typename Tag, typename Left, typename Right>
        struct enable_binary<deduce_domain, not_a_grammar, Trait, Tag, Left &, Right &>
          : enable_binary<
                typename deduce_domain2<Left, Right>::type
              , typename deduce_domain2<Left, Right>::type::proto_grammar
              , Trait
              , Tag
              , Left &
              , Right &
            >
        {};

    } // detail

#define QSBOOST_PROTO_UNARY_OP_IS_POSTFIX_0
#define QSBOOST_PROTO_UNARY_OP_IS_POSTFIX_1 , int

#ifdef QSBOOST_NO_CXX11_RVALUE_REFERENCES

#define QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(OP, TAG, TRAIT, DOMAIN, POST)                             \
    template<typename Arg>                                                                          \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_unary<                                                    \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_UNARY_(TRAIT, Arg)                                                        \
      , TAG                                                                                         \
      , Arg &                                                                                       \
    >::type const                                                                                   \
    operator OP(Arg &arg QSBOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                                  \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Arg &>()(arg);                         \
    }                                                                                               \
                                                                                                    \
    template<typename Arg>                                                                          \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_unary<                                                    \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_UNARY_(TRAIT, Arg)                                                        \
      , TAG                                                                                         \
      , Arg const &                                                                                 \
    >::type const                                                                                   \
    operator OP(Arg const &arg QSBOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                            \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Arg const &>()(arg);                   \
    }                                                                                               \
    /**/

#define QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(OP, TAG, TRAIT, DOMAIN)                                  \
    template<typename Left, typename Right>                                                         \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_binary<                                                   \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_BINARY_(TRAIT, Left, Right)                                               \
      , TAG                                                                                         \
      , Left &                                                                                      \
      , Right &                                                                                     \
    >::type const                                                                                   \
    operator OP(Left &left, Right &right)                                                           \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Left &, Right &>()(left, right);       \
    }                                                                                               \
                                                                                                    \
    template<typename Left, typename Right>                                                         \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_binary<                                                   \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_BINARY_(TRAIT, Left, Right)                                               \
      , TAG                                                                                         \
      , Left &                                                                                      \
      , Right const &                                                                               \
    >::type const                                                                                   \
    operator OP(Left &left, Right const &right)                                                     \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Left &, Right const &>()(left, right); \
    }                                                                                               \
                                                                                                    \
    template<typename Left, typename Right>                                                         \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_binary<                                                   \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_BINARY_(TRAIT, Left, Right)                                               \
      , TAG                                                                                         \
      , Left const &                                                                                \
      , Right &                                                                                     \
    >::type const                                                                                   \
    operator OP(Left const &left, Right &right)                                                     \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Left const &, Right &>()(left, right); \
    }                                                                                               \
                                                                                                    \
    template<typename Left, typename Right>                                                         \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_binary<                                                   \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_BINARY_(TRAIT, Left, Right)                                               \
      , TAG                                                                                         \
      , Left const &                                                                                \
      , Right const &                                                                               \
    >::type const                                                                                   \
    operator OP(Left const &left, Right const &right)                                               \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Left const &, Right const &>()(left, right);\
    }                                                                                               \
    /**/

#else

#define QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(OP, TAG, TRAIT, DOMAIN, POST)                             \
    template<typename Arg>                                                                          \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_unary<                                                    \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_UNARY_(TRAIT, Arg)                                                        \
      , TAG                                                                                         \
      , Arg const &                                                                                 \
    >::type const                                                                                   \
    operator OP(Arg &&arg QSBOOST_PROTO_UNARY_OP_IS_POSTFIX_ ## POST)                                 \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Arg const &>()(arg);                   \
    }                                                                                               \
    /**/

#define QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(OP, TAG, TRAIT, DOMAIN)                                  \
    template<typename Left, typename Right>                                                         \
    QSBOOST_PROTO_DISABLE_MSVC_C4714 QSBOOST_FORCEINLINE                                                \
    typename qsboost::proto::detail::enable_binary<                                                   \
        DOMAIN                                                                                      \
      , DOMAIN::proto_grammar                                                                       \
      , QSBOOST_PROTO_APPLY_BINARY_(TRAIT, Left, Right)                                               \
      , TAG                                                                                         \
      , Left const &                                                                                \
      , Right const &                                                                               \
    >::type const                                                                                   \
    operator OP(Left &&left, Right &&right)                                                         \
    {                                                                                               \
        return qsboost::proto::detail::make_expr_<TAG, DOMAIN, Left const &, Right const &>()(left, right);\
    }                                                                                               \
    /**/

#endif

#define QSBOOST_PROTO_DEFINE_OPERATORS(TRAIT, DOMAIN)                                                 \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(+, qsboost::proto::tag::unary_plus, TRAIT, DOMAIN, 0)           \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(-, qsboost::proto::tag::negate, TRAIT, DOMAIN, 0)               \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(*, qsboost::proto::tag::dereference, TRAIT, DOMAIN, 0)          \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(~, qsboost::proto::tag::complement, TRAIT, DOMAIN, 0)           \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(&, qsboost::proto::tag::address_of, TRAIT, DOMAIN, 0)           \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(!, qsboost::proto::tag::logical_not, TRAIT, DOMAIN, 0)          \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(++, qsboost::proto::tag::pre_inc, TRAIT, DOMAIN, 0)             \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(--, qsboost::proto::tag::pre_dec, TRAIT, DOMAIN, 0)             \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(++, qsboost::proto::tag::post_inc, TRAIT, DOMAIN, 1)            \
    QSBOOST_PROTO_DEFINE_UNARY_OPERATOR(--, qsboost::proto::tag::post_dec, TRAIT, DOMAIN, 1)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(<<, qsboost::proto::tag::shift_left, TRAIT, DOMAIN)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(>>, qsboost::proto::tag::shift_right, TRAIT, DOMAIN)           \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(*, qsboost::proto::tag::multiplies, TRAIT, DOMAIN)             \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(/, qsboost::proto::tag::divides, TRAIT, DOMAIN)                \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(%, qsboost::proto::tag::modulus, TRAIT, DOMAIN)                \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(+, qsboost::proto::tag::plus, TRAIT, DOMAIN)                   \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(-, qsboost::proto::tag::minus, TRAIT, DOMAIN)                  \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(<, qsboost::proto::tag::less, TRAIT, DOMAIN)                   \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(>, qsboost::proto::tag::greater, TRAIT, DOMAIN)                \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(<=, qsboost::proto::tag::less_equal, TRAIT, DOMAIN)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(>=, qsboost::proto::tag::greater_equal, TRAIT, DOMAIN)         \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(==, qsboost::proto::tag::equal_to, TRAIT, DOMAIN)              \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(!=, qsboost::proto::tag::not_equal_to, TRAIT, DOMAIN)          \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(||, qsboost::proto::tag::logical_or, TRAIT, DOMAIN)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(&&, qsboost::proto::tag::logical_and, TRAIT, DOMAIN)           \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(&, qsboost::proto::tag::bitwise_and, TRAIT, DOMAIN)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(|, qsboost::proto::tag::bitwise_or, TRAIT, DOMAIN)             \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(^, qsboost::proto::tag::bitwise_xor, TRAIT, DOMAIN)            \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(QSBOOST_PP_COMMA(), qsboost::proto::tag::comma, TRAIT, DOMAIN)   \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(->*, qsboost::proto::tag::mem_ptr, TRAIT, DOMAIN)              \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(<<=, qsboost::proto::tag::shift_left_assign, TRAIT, DOMAIN)    \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(>>=, qsboost::proto::tag::shift_right_assign, TRAIT, DOMAIN)   \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(*=, qsboost::proto::tag::multiplies_assign, TRAIT, DOMAIN)     \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(/=, qsboost::proto::tag::divides_assign, TRAIT, DOMAIN)        \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(%=, qsboost::proto::tag::modulus_assign, TRAIT, DOMAIN)        \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(+=, qsboost::proto::tag::plus_assign, TRAIT, DOMAIN)           \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(-=, qsboost::proto::tag::minus_assign, TRAIT, DOMAIN)          \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(&=, qsboost::proto::tag::bitwise_and_assign, TRAIT, DOMAIN)    \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(|=, qsboost::proto::tag::bitwise_or_assign, TRAIT, DOMAIN)     \
    QSBOOST_PROTO_DEFINE_BINARY_OPERATOR(^=, qsboost::proto::tag::bitwise_xor_assign, TRAIT, DOMAIN)    \
    /**/

    // Extensions are a superset of Proto expressions
    template<typename T>
    struct is_extension
      : is_expr<T>
    {};

    template<typename T>
    struct is_extension<T &>
      : is_expr<T>
    {};

    #define QSBOOST_PROTO_APPLY_UNARY_(TRAIT, ARG) TRAIT<ARG>
    #define QSBOOST_PROTO_APPLY_BINARY_(TRAIT, LEFT, RIGHT) qsboost::mpl::or_<TRAIT<LEFT>, TRAIT<RIGHT> >

    namespace exprns_
    {
        // This defines all of Proto's built-in free operator overloads
        QSBOOST_PROTO_DEFINE_OPERATORS(is_extension, deduce_domain)

        // if_else, for the non-overloadable ternary conditional operator ?:
        template<typename A0, typename A1, typename A2>
        QSBOOST_FORCEINLINE
        typename result_of::make_expr<
            tag::if_else_
          , deduce_domain
          , A0 const &
          , A1 const &
          , A2 const &
        >::type const
        if_else(A0 const &a0, A1 const &a1, A2 const &a2)
        {
            return proto::detail::make_expr_<
                tag::if_else_
              , deduce_domain
              , A0 const &
              , A1 const &
              , A2 const &
            >()(a0, a1, a2);
        }
    }

    using exprns_::if_else;

    #undef QSBOOST_PROTO_APPLY_UNARY_
    #undef QSBOOST_PROTO_APPLY_BINARY_

    // Redefine BOOST_PROTO_APPLY_UNARY_ and BOOST_PROTO_APPLY_BINARY_ so that end users
    // can use BOOST_PROTO_DEFINE_OPERATORS to define Proto operator overloads that work
    // with their own terminal types.

#ifdef QSBOOST_NO_CXX11_RVALUE_REFERENCES

    #define QSBOOST_PROTO_APPLY_UNARY_(TRAIT, ARG)                                                    \
        qsboost::mpl::and_<                                                                           \
            TRAIT<ARG>                                                                              \
          , qsboost::mpl::not_<qsboost::proto::is_extension<ARG> >                                      \
        >                                                                                           \
        /**/

    #define QSBOOST_PROTO_APPLY_BINARY_(TRAIT, LEFT, RIGHT)                                           \
        qsboost::mpl::and_<                                                                           \
            qsboost::mpl::or_<TRAIT<LEFT>, TRAIT<RIGHT> >                                             \
          , qsboost::mpl::not_<                                                                       \
                qsboost::mpl::or_<                                                                    \
                    qsboost::proto::is_extension<LEFT>                                                \
                  , qsboost::proto::is_extension<RIGHT>                                               \
                >                                                                                   \
            >                                                                                       \
        >                                                                                           \
        /**/

#else

    #define QSBOOST_PROTO_APPLY_UNARY_(TRAIT, ARG)                                                    \
        qsboost::mpl::and_<                                                                           \
            TRAIT<QSBOOST_PROTO_UNCVREF(ARG) >                                                        \
          , qsboost::mpl::not_<qsboost::proto::is_extension<ARG> >                                      \
        >                                                                                           \
        /**/

    #define QSBOOST_PROTO_APPLY_BINARY_(TRAIT, LEFT, RIGHT)                                           \
        qsboost::mpl::and_<                                                                           \
            qsboost::mpl::or_<TRAIT<QSBOOST_PROTO_UNCVREF(LEFT) >, TRAIT<QSBOOST_PROTO_UNCVREF(RIGHT) > > \
          , qsboost::mpl::not_<                                                                       \
                qsboost::mpl::or_<                                                                    \
                    qsboost::proto::is_extension<LEFT>                                                \
                  , qsboost::proto::is_extension<RIGHT>                                               \
                >                                                                                   \
            >                                                                                       \
        >                                                                                           \
        /**/

#endif

}}

#if defined(_MSC_VER)
# pragma warning(pop)
#endif

#endif

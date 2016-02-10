//-----------------------------------------------------------------------------
// boost variant/detail/initializer.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_INITIALIZER_HPP
#define QSBOOST_VARIANT_DETAIL_INITIALIZER_HPP

#include <new> // for placement new

#include "qsboost/config.hpp"

#include "qsboost/call_traits.hpp"
#include "qsboost/detail/reference_content.hpp"
#include "qsboost/variant/recursive_wrapper_fwd.hpp"
#include "qsboost/variant/detail/move.hpp"

#if !defined(QSBOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)
#   include "qsboost/mpl/aux_/value_wknd.hpp"
#   include "qsboost/mpl/int.hpp"
#   include "qsboost/mpl/iter_fold.hpp"
#   include "qsboost/mpl/next.hpp"
#   include "qsboost/mpl/deref.hpp"
#   include "qsboost/mpl/pair.hpp"
#   include "qsboost/mpl/protect.hpp"
#else
#   include "qsboost/variant/variant_fwd.hpp"
#   include "qsboost/preprocessor/cat.hpp"
#   include "qsboost/preprocessor/enum.hpp"
#   include "qsboost/preprocessor/repeat.hpp"
#endif

namespace qsboost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) support to simulate standard overload resolution rules
//
// The below initializers allows variant to follow standard overload
// resolution rules over the specified set of bounded types.
//
// On compilers where using declarations in class templates can correctly
// avoid name hiding, use an optimal solution based on the variant's typelist.
//
// Otherwise, use a preprocessor workaround based on knowledge of the fixed
// size of the variant's psuedo-variadic template parameter list.
//

#if !defined(QSBOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

// (detail) quoted metafunction make_initializer_node
//
// Exposes a pair whose first type is a node in the initializer hierarchy.
//
struct make_initializer_node
{
    template <typename BaseIndexPair, typename Iterator>
    struct apply
    {
    private: // helpers, for metafunction result (below)

        typedef typename BaseIndexPair::first
            base;
        typedef typename BaseIndexPair::second
            index;

        class initializer_node
            : public base
        {
        private: // helpers, for static functions (below)

            typedef typename mpl::deref<Iterator>::type
                recursive_enabled_T;
            typedef typename unwrap_recursive<recursive_enabled_T>::type
                public_T;

#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
            typedef qsboost::is_reference<public_T> 
                is_reference_content_t;

            typedef typename qsboost::mpl::if_<is_reference_content_t, public_T, const public_T& >::type 
                param_T;

            template <class T> struct disable_overload{};

            typedef typename qsboost::mpl::if_<is_reference_content_t, disable_overload<public_T>, public_T&& >::type 
                param2_T;
#else
            typedef typename call_traits<public_T>::param_type
                param_T;
#endif

        public: // static functions

            using base::initialize;

            static int initialize(void* dest, param_T operand)
            {
                typedef typename qsboost::detail::make_reference_content<
                      recursive_enabled_T
                    >::type internal_T;

                new(dest) internal_T(operand);
                return QSBOOST_MPL_AUX_VALUE_WKND(index)::value; // which
            }

#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES            
            static int initialize(void* dest, param2_T operand)
            {
                // This assert must newer trigger, because all the reference contents are
                // handled by the initilize(void* dest, param_T operand) function above
                QSBOOST_ASSERT(!is_reference_content_t::value);

                typedef typename qsboost::mpl::if_<is_reference_content_t, param2_T, recursive_enabled_T>::type value_T;
                new(dest) value_T( qsboost::detail::variant::move(operand) );
                return QSBOOST_MPL_AUX_VALUE_WKND(index)::value; // which
            }
#endif
        };

        friend class initializer_node;

    public: // metafunction result

        typedef mpl::pair<
              initializer_node
            , typename mpl::next< index >::type
            > type;

    };
};

// (detail) class initializer_root
//
// Every level of the initializer hierarchy must expose the name
// "initialize," so initializer_root provides a dummy function:
//
class initializer_root
{
public: // static functions

    static void initialize();

};

#else // defined(BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

    // Obsolete. Remove.
    #define QSBOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_PARAMS \
          QSBOOST_VARIANT_ENUM_PARAMS(typename recursive_enabled_T) \
    /**/

    // Obsolete. Remove.
    #define QSBOOST_VARIANT_AUX_PP_INITIALIZER_DEFINE_PARAM_T(N) \
        typedef typename unwrap_recursive< \
              QSBOOST_PP_CAT(recursive_enabled_T,N) \
            >::type QSBOOST_PP_CAT(public_T,N); \
        typedef typename call_traits< \
              QSBOOST_PP_CAT(public_T,N) \
            >::param_type QSBOOST_PP_CAT(param_T,N); \
    /**/

template < QSBOOST_VARIANT_ENUM_PARAMS(typename recursive_enabled_T) >
struct preprocessor_list_initializer
{
public: // static functions

    #define QSBOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION(z,N,_) \
        typedef typename unwrap_recursive< \
              QSBOOST_PP_CAT(recursive_enabled_T,N) \
            >::type QSBOOST_PP_CAT(public_T,N); \
        typedef typename call_traits< \
              QSBOOST_PP_CAT(public_T,N) \
            >::param_type QSBOOST_PP_CAT(param_T,N); \
        static int initialize( \
              void* dest \
            , QSBOOST_PP_CAT(param_T,N) operand \
            ) \
        { \
            typedef typename qsboost::detail::make_reference_content< \
                  QSBOOST_PP_CAT(recursive_enabled_T,N) \
                >::type internal_T; \
            \
            new(dest) internal_T(operand); \
            return (N); /*which*/ \
        } \
        /**/

    QSBOOST_PP_REPEAT(
          QSBOOST_VARIANT_LIMIT_TYPES
        , QSBOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION
        , _
        )

    #undef QSBOOST_VARIANT_AUX_PP_INITIALIZE_FUNCTION

};

#endif // BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

}} // namespace detail::variant
} // namespace boost

///////////////////////////////////////////////////////////////////////////////
// macro BOOST_VARIANT_AUX_INITIALIZER_T
//
// Given both the variant's typelist and a basename for forming the list of
// bounded types (i.e., T becomes T1, T2, etc.), exposes the initializer
// most appropriate to the current compiler.
//

#if !defined(QSBOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

#define QSBOOST_VARIANT_AUX_INITIALIZER_T( mpl_seq, typename_base ) \
    ::qsboost::mpl::iter_fold< \
          mpl_seq \
        , ::qsboost::mpl::pair< \
              ::qsboost::detail::variant::initializer_root \
            , ::qsboost::mpl::int_<0> \
            > \
        , ::qsboost::mpl::protect< \
              ::qsboost::detail::variant::make_initializer_node \
            > \
        >::type::first \
    /**/

#else // defined(BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE)

    // Obsolete. Remove.
    #define QSBOOST_VARIANT_AUX_PP_INITIALIZER_TEMPLATE_ARGS(typename_base) \
          QSBOOST_VARIANT_ENUM_PARAMS(typename_base) \
        /**/

#define QSBOOST_VARIANT_AUX_INITIALIZER_T( mpl_seq, typename_base ) \
    ::qsboost::detail::variant::preprocessor_list_initializer< \
          QSBOOST_VARIANT_ENUM_PARAMS(typename_base) \
        > \
    /**/

#endif // BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE workaround

#endif // BOOST_VARIANT_DETAIL_INITIALIZER_HPP

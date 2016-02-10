//-----------------------------------------------------------------------------
// boost variant/recursive_variant.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003 Eric Friedman
// Copyright (c) 2013 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_RECURSIVE_VARIANT_HPP
#define QSBOOST_VARIANT_RECURSIVE_VARIANT_HPP

#include "qsboost/variant/variant_fwd.hpp"
#include "qsboost/variant/detail/enable_recursive.hpp"
#include "qsboost/variant/detail/substitute_fwd.hpp"
#include "qsboost/variant/detail/make_variant_list.hpp"
#include "qsboost/variant/detail/over_sequence.hpp"

#include "qsboost/mpl/aux_/lambda_arity_param.hpp"

#include "qsboost/mpl/equal.hpp"
#include "qsboost/mpl/eval_if.hpp"
#include "qsboost/mpl/identity.hpp"
#include "qsboost/mpl/if.hpp"
#include "qsboost/mpl/protect.hpp"
#include "qsboost/mpl/transform.hpp"
#include "qsboost/type_traits/is_same.hpp"
#include "qsboost/preprocessor/cat.hpp"
#include "qsboost/preprocessor/repeat.hpp"

#include "qsboost/mpl/bool.hpp"
#include "qsboost/mpl/is_sequence.hpp"
#include "qsboost/variant/variant.hpp"

namespace qsboost {

namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction specialization substitute
//
// Handles embedded variant types when substituting for recursive_variant_.
//

#if !defined(QSBOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

template <
      QSBOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::qsboost::variant<
          recursive_flag< T0 >
        , QSBOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        >
    , RecursiveVariant
    , ::qsboost::recursive_variant_
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
    typedef ::qsboost::variant<
          recursive_flag< T0 >
        , QSBOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;
};

template <
      QSBOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::qsboost::variant<
          ::qsboost::detail::variant::over_sequence< T0 >
        , QSBOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        >
    , RecursiveVariant
    , ::qsboost::recursive_variant_
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
private:

    typedef T0 initial_types;

    typedef typename mpl::transform<
          initial_types
        , mpl::protect< quoted_enable_recursive<RecursiveVariant,mpl::true_> >
        >::type types;

public:

    typedef typename mpl::if_<
          mpl::equal<initial_types, types, ::qsboost::is_same<mpl::_1, mpl::_2> >
        , ::qsboost::variant<
              ::qsboost::detail::variant::over_sequence< T0 >
            , QSBOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
            >
        , ::qsboost::variant< over_sequence<types> >
        >::type type;
};

template <
      QSBOOST_VARIANT_ENUM_PARAMS(typename T)
    , typename RecursiveVariant
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      ::qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >
    , RecursiveVariant
    , ::qsboost::recursive_variant_
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
#if !defined(QSBOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)
    
    typedef ::qsboost::variant<
        typename enable_recursive<   
              T0              
            , RecursiveVariant               
            , mpl::true_                     
        >::type,
        typename enable_recursive<   
              TN              
            , RecursiveVariant               
            , mpl::true_                     
        >::type...  
    > type;

#else // defined(BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)

private: // helpers, for metafunction result (below)

    #define QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS(z,N,_)  \
        typedef typename enable_recursive<   \
              QSBOOST_PP_CAT(T,N)              \
            , RecursiveVariant               \
            , mpl::true_                     \
            >::type QSBOOST_PP_CAT(wknd_T,N);  \
        /**/

    QSBOOST_PP_REPEAT(
          QSBOOST_VARIANT_LIMIT_TYPES
        , QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS
        , _
        )

    #undef QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_TYPEDEFS

public: // metafunction result

    typedef ::qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(wknd_T) > type;
#endif // BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES workaround
};

#else // defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

//
// no specializations: embedded variants unsupported on these compilers!
//

#endif // !defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant
//
// See docs and boost/variant/variant_fwd.hpp for more information.
//
template < QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
struct make_recursive_variant
{
public: // metafunction result

    typedef qsboost::variant<
          detail::variant::recursive_flag< T0 >
        , QSBOOST_VARIANT_ENUM_SHIFTED_PARAMS(T)
        > type;

};

///////////////////////////////////////////////////////////////////////////////
// metafunction make_recursive_variant_over
//
// See docs and boost/variant/variant_fwd.hpp for more information.
//
template <typename Types>
struct make_recursive_variant_over
{
private: // precondition assertions

    QSBOOST_STATIC_ASSERT(( ::qsboost::mpl::is_sequence<Types>::value ));

public: // metafunction result

    typedef typename make_recursive_variant<
          detail::variant::over_sequence< Types >
        >::type type;

};

} // namespace boost

#endif // BOOST_VARIANT_RECURSIVE_VARIANT_HPP

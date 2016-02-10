
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_INHERIT_HPP_INCLUDED
#define QSBOOST_MPL_INHERIT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/empty_base.hpp>
#   include <qsboost/mpl/aux_/na_spec.hpp>
#   include <qsboost/mpl/aux_/lambda_support.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER inherit.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/config/dtp.hpp>

#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/dec.hpp>
#   include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

// 'inherit<T1,T2,..,Tn>' metafunction; returns an unspecified class type
// produced by public derivation from all metafunction's parameters 
// (T1,T2,..,Tn), except the parameters of 'empty_base' class type; 
// regardless the position and number of 'empty_base' parameters in the 
// metafunction's argument list, derivation from them is always a no-op;
// for instance:
//      inherit<her>::type == her
//      inherit<her,my>::type == struct unspecified : her, my {};
//      inherit<empty_base,her>::type == her
//      inherit<empty_base,her,empty_base,empty_base>::type == her
//      inherit<her,empty_base,my>::type == struct unspecified : her, my {};
//      inherit<empty_base,empty_base>::type == empty_base

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< 
      typename QSBOOST_MPL_AUX_NA_PARAM(T1)
    , typename QSBOOST_MPL_AUX_NA_PARAM(T2)
    > 
struct inherit2
    : T1, T2
{
    typedef inherit2 type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2, inherit2, (T1,T2))
};

template< typename T1 > 
struct inherit2<T1,empty_base>
{
    typedef T1 type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (T1,empty_base))
};

template< typename T2 > 
struct inherit2<empty_base,T2>
{
    typedef T2 type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (empty_base,T2))
};

// needed to disambiguate the previous two in case when both 
// T1 and T2 == empty_base
template<> 
struct inherit2<empty_base,empty_base>
{
    typedef empty_base type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(2, inherit2, (empty_base,empty_base))
};

#else

namespace aux {

template< bool C1, bool C2 >
struct inherit2_impl
{
    template< typename Derived, typename T1, typename T2 > struct result_ 
        : T1, T2
    {
        typedef Derived type_;
    };
};

template<>
struct inherit2_impl<false,true>
{
    template< typename Derived, typename T1, typename T2 > struct result_
        : T1
    {
        typedef T1 type_;
    };
};

template<>
struct inherit2_impl<true,false>
{
    template< typename Derived, typename T1, typename T2 > struct result_
        : T2 
    {
        typedef T2 type_;
    };
};

template<>
struct inherit2_impl<true,true>
{
    template< typename Derived, typename T1, typename T2 > struct result_
    {
        typedef T1 type_;
    };
};

} // namespace aux

template< 
      typename QSBOOST_MPL_AUX_NA_PARAM(T1)
    , typename QSBOOST_MPL_AUX_NA_PARAM(T2)
    > 
struct inherit2
    : aux::inherit2_impl<
          is_empty_base<T1>::value
        , is_empty_base<T2>::value
        >::template result_< inherit2<T1,T2>,T1,T2 >
{
    typedef typename inherit2::type_ type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2, inherit2, (T1,T2))
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

QSBOOST_MPL_AUX_NA_SPEC(2, inherit2)

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(3, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/inherit.hpp>))
#include QSBOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_INHERIT_HPP_INCLUDED

///// iteration

#else
#define n_ QSBOOST_PP_FRAME_ITERATION(1)

template<
      QSBOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, na)
    >
struct QSBOOST_PP_CAT(inherit,n_)
    : inherit2<
          typename QSBOOST_PP_CAT(inherit,QSBOOST_PP_DEC(n_))<
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(n_), T)
            >::type
        , QSBOOST_PP_CAT(T,n_)
        >
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(
          n_
        , QSBOOST_PP_CAT(inherit,n_)
        , (QSBOOST_MPL_PP_PARAMS(n_, T))
        )
};

QSBOOST_MPL_AUX_NA_SPEC(n_, QSBOOST_PP_CAT(inherit,n_))

#if n_ == QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
/// primary template
template<
      QSBOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, empty_base)
    >
struct inherit
    : QSBOOST_PP_CAT(inherit,n_)<QSBOOST_MPL_PP_PARAMS(n_, T)>
{
};

// 'na' specialization
template<>
struct inherit< QSBOOST_MPL_PP_ENUM(5, na) >
{
    template<
#if !defined(QSBOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
          QSBOOST_MPL_PP_DEFAULT_PARAMS(n_, typename T, empty_base)
#else
          QSBOOST_MPL_PP_PARAMS(n_, typename T)
#endif
        >
    struct apply
        : inherit< QSBOOST_MPL_PP_PARAMS(n_, T) >
    {
    };
};

QSBOOST_MPL_AUX_NA_SPEC_LAMBDA(n_, inherit)
QSBOOST_MPL_AUX_NA_SPEC_ARITY(n_, inherit)
QSBOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(n_, n_, inherit)
#endif

#undef n_
#endif // BOOST_PP_IS_ITERATING

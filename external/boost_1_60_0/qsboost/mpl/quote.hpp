
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_QUOTE_HPP_INCLUDED
#define QSBOOST_MPL_QUOTE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2008
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
#   include <qsboost/mpl/void.hpp>
#   include <qsboost/mpl/aux_/has_type.hpp>
#endif

#include <qsboost/mpl/aux_/config/bcc.hpp>
#include <qsboost/mpl/aux_/config/ttp.hpp>

#if defined(QSBOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
    && !defined(QSBOOST_MPL_CFG_BCC590_WORKAROUNDS)
#   define QSBOOST_MPL_CFG_NO_QUOTE_TEMPLATE
#endif

#if !defined(QSBOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS) \
    && defined(QSBOOST_MPL_CFG_NO_HAS_XXX)
#   define QSBOOST_MPL_CFG_NO_IMPLICIT_METAFUNCTIONS
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER quote.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/config/workaround.hpp>

#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_QUOTE_TEMPLATE)

namespace qsboost { namespace mpl {

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename T, bool has_type_ >
struct quote_impl
// GCC has a problem with metafunction forwarding when T is a
// specialization of a template called 'type'.
# if QSBOOST_WORKAROUND(__GNUC__, QSBOOST_TESTED_AT(4)) \
    && QSBOOST_WORKAROUND(__GNUC_MINOR__, QSBOOST_TESTED_AT(0)) \
    && QSBOOST_WORKAROUND(__GNUC_PATCHLEVEL__, QSBOOST_TESTED_AT(2))
{
    typedef typename T::type type;
};
# else 
    : T
{
};
# endif 

template< typename T >
struct quote_impl<T,false>
{
    typedef T type;
};

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< bool > struct quote_impl
{
    template< typename T > struct result_
        : T
    {
    };
};

template<> struct quote_impl<false>
{
    template< typename T > struct result_
    {
        typedef T type;
    };
};

#endif 

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/quote.hpp>))
#include QSBOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_QUOTE_TEMPLATE

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_QUOTE_HPP_INCLUDED

///// iteration

#else
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

template<
      template< QSBOOST_MPL_PP_PARAMS(i_, typename P) > class F
    , typename Tag = void_
    >
struct QSBOOST_PP_CAT(quote,i_)
{
    template< QSBOOST_MPL_PP_PARAMS(i_, typename U) > struct apply
#if defined(QSBOOST_MPL_CFG_BCC590_WORKAROUNDS)
    {
        typedef typename quote_impl<
              F< QSBOOST_MPL_PP_PARAMS(i_, U) >
            , aux::has_type< F< QSBOOST_MPL_PP_PARAMS(i_, U) > >::value
            >::type type;
    };
#elif !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
        : quote_impl<
              F< QSBOOST_MPL_PP_PARAMS(i_, U) >
            , aux::has_type< F< QSBOOST_MPL_PP_PARAMS(i_, U) > >::value
            >
    {
    };
#else
        : quote_impl< aux::has_type< F< QSBOOST_MPL_PP_PARAMS(i_, U) > >::value >
            ::template result_< F< QSBOOST_MPL_PP_PARAMS(i_, U) > >
    {
    };
#endif
};

#undef i_
#endif // BOOST_PP_IS_ITERATING

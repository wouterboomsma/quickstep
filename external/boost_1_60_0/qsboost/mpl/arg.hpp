
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_ARG_HPP_INCLUDED
#define QSBOOST_MPL_ARG_HPP_INCLUDED

// Copyright Peter Dimov 2001-2002
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
#   include <qsboost/mpl/arg_fwd.hpp>
#   include <qsboost/mpl/aux_/na.hpp>
#   include <qsboost/mpl/aux_/na_assert.hpp>
#   include <qsboost/mpl/aux_/arity_spec.hpp>
#   include <qsboost/mpl/aux_/arg_typedef.hpp>
#endif

#include <qsboost/mpl/aux_/config/static_constant.hpp>
#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER arg.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/config/lambda.hpp>
#   include <qsboost/mpl/aux_/config/dtp.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>

#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

// local macro, #undef-ined at the end of the header
#if !defined(QSBOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define AUX778076_ARG_N_DEFAULT_PARAMS(param,value) \
    QSBOOST_MPL_PP_DEFAULT_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/
#else
#   define AUX778076_ARG_N_DEFAULT_PARAMS(param,value) \
    QSBOOST_MPL_PP_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        ) \
    /**/
#endif

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/arg.hpp>))
#include QSBOOST_PP_ITERATE()


#   undef AUX778076_ARG_N_DEFAULT_PARAMS

QSBOOST_MPL_AUX_NONTYPE_ARITY_SPEC(1,int,arg)

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_ARG_HPP_INCLUDED

///// iteration

#else
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

#if i_ > 0

template<> struct arg<i_>
{
    QSBOOST_STATIC_CONSTANT(int, value = i_);
    typedef arg<QSBOOST_PP_INC(i_)> next;
    QSBOOST_MPL_AUX_ARG_TYPEDEF(na, tag)
    QSBOOST_MPL_AUX_ARG_TYPEDEF(na, type)

    template<
          AUX778076_ARG_N_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
        typedef QSBOOST_PP_CAT(U,i_) type;
        QSBOOST_MPL_AUX_ASSERT_NOT_NA(type);
    };
};

#else

template<> struct arg<-1>
{
    QSBOOST_STATIC_CONSTANT(int, value = -1);
    QSBOOST_MPL_AUX_ARG_TYPEDEF(na, tag)
    QSBOOST_MPL_AUX_ARG_TYPEDEF(na, type)

    template<
          AUX778076_ARG_N_DEFAULT_PARAMS(typename U, na)
        >
    struct apply
    {
        typedef U1 type;
        QSBOOST_MPL_AUX_ASSERT_NOT_NA(type);
    };
};

#endif // i_ > 0

#undef i_
#endif // BOOST_PP_IS_ITERATING

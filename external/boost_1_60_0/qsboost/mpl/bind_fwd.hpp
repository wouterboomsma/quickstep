
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_BIND_FWD_HPP_INCLUDED
#define QSBOOST_MPL_BIND_FWD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
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
#   include <qsboost/mpl/aux_/na.hpp>
#endif

#include <qsboost/mpl/aux_/config/bind.hpp>
#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER bind_fwd.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/config/dmc_ambiguous_ctps.hpp>

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

// local macros, #undef-ined at the end of the header

#   if defined(QSBOOST_MPL_CFG_DMC_AMBIGUOUS_CTPS)
#       define AUX778076_DMC_PARAM() , int dummy_ = 0
#   else
#       define AUX778076_DMC_PARAM()
#   endif

#   define AUX778076_BIND_DEFAULT_PARAMS(param, value) \
    QSBOOST_MPL_PP_DEFAULT_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    AUX778076_DMC_PARAM() \
    /**/

#   define AUX778076_BIND_N_PARAMS(n, param) \
    QSBOOST_PP_COMMA_IF(n) QSBOOST_MPL_PP_PARAMS(n, param) \
    AUX778076_DMC_PARAM() \
    /**/

#if !defined(QSBOOST_MPL_CFG_NO_BIND_TEMPLATE)
template<
      typename F, AUX778076_BIND_DEFAULT_PARAMS(typename T, na)
    >
struct bind;
#endif

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/bind_fwd.hpp>))
#include QSBOOST_PP_ITERATE()

#   undef AUX778076_BIND_N_PARAMS
#   undef AUX778076_BIND_DEFAULT_PARAMS
#   undef AUX778076_DMC_PARAM
}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_BIND_FWD_HPP_INCLUDED

///// iteration

#else
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

template<
      typename F AUX778076_BIND_N_PARAMS(i_, typename T)
    >
struct QSBOOST_PP_CAT(bind,i_);

#undef i_
#endif // BOOST_PP_IS_ITERATING


#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_APPLY_FWD_HPP_INCLUDED
#define QSBOOST_MPL_APPLY_FWD_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER apply_fwd.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>

// agurt, 15/jan/02: top-level 'apply' template gives an ICE on MSVC
// (for known reasons)
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
#   define QSBOOST_MPL_CFG_NO_APPLY_TEMPLATE
#endif

namespace qsboost { namespace mpl {

// local macro, #undef-ined at the end of the header
#   define AUX778076_APPLY_DEF_PARAMS(param, value) \
    QSBOOST_MPL_PP_DEFAULT_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/

#   define AUX778076_APPLY_N_COMMA_PARAMS(n, param) \
    QSBOOST_PP_COMMA_IF(n) \
    QSBOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   if !defined(QSBOOST_MPL_CFG_NO_APPLY_TEMPLATE)

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
// forward declaration
template<
      typename F, AUX778076_APPLY_DEF_PARAMS(typename T, na)
    >
struct apply;
#else
namespace aux {
template< QSBOOST_AUX_NTTP_DECL(int, arity_) > struct apply_chooser;
}
#endif

#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/apply_fwd.hpp>))
#include QSBOOST_PP_ITERATE()


#   undef AUX778076_APPLY_N_COMMA_PARAMS
#   undef AUX778076_APPLY_DEF_PARAMS

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_APPLY_FWD_HPP_INCLUDED

///// iteration

#else
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct QSBOOST_PP_CAT(apply,i_);

#undef i_
#endif // BOOST_PP_IS_ITERATING

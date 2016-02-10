
#ifndef QSBOOST_MPL_AUX_ITER_FOLD_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_ITER_FOLD_IMPL_HPP_INCLUDED

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
#   include <qsboost/mpl/next_prior.hpp>
#   include <qsboost/mpl/apply.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#       include <qsboost/mpl/if.hpp>
#       include <qsboost/type_traits/is_same.hpp>
#   endif
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER iter_fold_impl.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   define AUX778076_FOLD_IMPL_OP(iter) iter
#   define AUX778076_FOLD_IMPL_NAME_PREFIX iter_fold
#   include <qsboost/mpl/aux_/fold_impl_body.hpp>

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX_ITER_FOLD_IMPL_HPP_INCLUDED

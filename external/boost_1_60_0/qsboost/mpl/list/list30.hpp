
#ifndef QSBOOST_MPL_LIST_LIST30_HPP_INCLUDED
#define QSBOOST_MPL_LIST_LIST30_HPP_INCLUDED

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
#   include <qsboost/mpl/list/list20.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER list30.hpp
#   include <qsboost/mpl/list/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/preprocessor/iterate.hpp>

namespace qsboost { namespace mpl {

#   define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(21, 30, <qsboost/mpl/list/aux_/numbered.hpp>))
#   include QSBOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // BOOST_MPL_LIST_LIST30_HPP_INCLUDED

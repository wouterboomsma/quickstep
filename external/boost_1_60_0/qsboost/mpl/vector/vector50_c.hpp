
#ifndef QSBOOST_MPL_VECTOR_VECTOR50_C_HPP_INCLUDED
#define QSBOOST_MPL_VECTOR_VECTOR50_C_HPP_INCLUDED

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
#   include <qsboost/mpl/vector/vector40_c.hpp>
#   include <qsboost/mpl/vector/vector50.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER vector50_c.hpp
#   include <qsboost/mpl/vector/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/aux_/config/typeof.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/preprocessor/iterate.hpp>

namespace qsboost { namespace mpl {

#   define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(41, 50, <qsboost/mpl/vector/aux_/numbered_c.hpp>))
#   include QSBOOST_PP_ITERATE()

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS

#endif // BOOST_MPL_VECTOR_VECTOR50_C_HPP_INCLUDED

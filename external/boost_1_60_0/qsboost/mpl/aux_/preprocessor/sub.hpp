
#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_SUB_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_SUB_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/preprocessor.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <qsboost/mpl/aux_/preprocessor/tuple.hpp>

#if defined(QSBOOST_MPL_CFG_BROKEN_PP_MACRO_EXPANSION)
#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_SUB(i,j) \
    QSBOOST_MPL_PP_SUB_DELAY(i,j) \
    /**/

#   define QSBOOST_MPL_PP_SUB_DELAY(i,j) \
    QSBOOST_PP_CAT(QSBOOST_MPL_PP_TUPLE_11_ELEM_##i,QSBOOST_MPL_PP_SUB_##j) \
    /**/
#else
#   define QSBOOST_MPL_PP_SUB(i,j) \
    QSBOOST_MPL_PP_SUB_DELAY(i,j) \
    /**/

#   define QSBOOST_MPL_PP_SUB_DELAY(i,j) \
    QSBOOST_MPL_PP_TUPLE_11_ELEM_##i QSBOOST_MPL_PP_SUB_##j \
    /**/
#endif

#   define QSBOOST_MPL_PP_SUB_0 (0,1,2,3,4,5,6,7,8,9,10)
#   define QSBOOST_MPL_PP_SUB_1 (0,0,1,2,3,4,5,6,7,8,9)
#   define QSBOOST_MPL_PP_SUB_2 (0,0,0,1,2,3,4,5,6,7,8)
#   define QSBOOST_MPL_PP_SUB_3 (0,0,0,0,1,2,3,4,5,6,7)
#   define QSBOOST_MPL_PP_SUB_4 (0,0,0,0,0,1,2,3,4,5,6)
#   define QSBOOST_MPL_PP_SUB_5 (0,0,0,0,0,0,1,2,3,4,5)
#   define QSBOOST_MPL_PP_SUB_6 (0,0,0,0,0,0,0,1,2,3,4)
#   define QSBOOST_MPL_PP_SUB_7 (0,0,0,0,0,0,0,0,1,2,3)
#   define QSBOOST_MPL_PP_SUB_8 (0,0,0,0,0,0,0,0,0,1,2)
#   define QSBOOST_MPL_PP_SUB_9 (0,0,0,0,0,0,0,0,0,0,1)
#   define QSBOOST_MPL_PP_SUB_10 (0,0,0,0,0,0,0,0,0,0,0)

#else

#   include <qsboost/preprocessor/arithmetic/sub.hpp>

#   define QSBOOST_MPL_PP_SUB(i,j) \
    QSBOOST_PP_SUB(i,j) \
    /**/
    
#endif

#endif // BOOST_MPL_AUX_PREPROCESSOR_SUB_HPP_INCLUDED


#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_REPEAT_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_REPEAT_HPP_INCLUDED

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

#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_REPEAT(n,f,param) \
    QSBOOST_PP_CAT(QSBOOST_MPL_PP_REPEAT_,n)(f,param) \
    /**/
    
#   define QSBOOST_MPL_PP_REPEAT_0(f,p)
#   define QSBOOST_MPL_PP_REPEAT_1(f,p) f(0,0,p)
#   define QSBOOST_MPL_PP_REPEAT_2(f,p) f(0,0,p) f(0,1,p)
#   define QSBOOST_MPL_PP_REPEAT_3(f,p) f(0,0,p) f(0,1,p) f(0,2,p)
#   define QSBOOST_MPL_PP_REPEAT_4(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p)
#   define QSBOOST_MPL_PP_REPEAT_5(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p)
#   define QSBOOST_MPL_PP_REPEAT_6(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p) f(0,5,p)
#   define QSBOOST_MPL_PP_REPEAT_7(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p) f(0,5,p) f(0,6,p)
#   define QSBOOST_MPL_PP_REPEAT_8(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p) f(0,5,p) f(0,6,p) f(0,7,p)
#   define QSBOOST_MPL_PP_REPEAT_9(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p) f(0,5,p) f(0,6,p) f(0,7,p) f(0,8,p)
#   define QSBOOST_MPL_PP_REPEAT_10(f,p) f(0,0,p) f(0,1,p) f(0,2,p) f(0,3,p) f(0,4,p) f(0,5,p) f(0,6,p) f(0,7,p) f(0,8,p) f(0,9,p)

#else 

#   include <qsboost/preprocessor/repeat.hpp>

#   define QSBOOST_MPL_PP_REPEAT(n,f,param) \
    QSBOOST_PP_REPEAT(n,f,param) \
    /**/

#endif 

#define QSBOOST_MPL_PP_REPEAT_IDENTITY_FUNC(unused1, unused2, x) x

#endif // BOOST_MPL_AUX_PREPROCESSOR_REPEAT_HPP_INCLUDED

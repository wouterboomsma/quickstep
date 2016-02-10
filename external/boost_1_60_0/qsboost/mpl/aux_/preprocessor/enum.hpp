
#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_ENUM_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_ENUM_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/preprocessor.hpp>

// BOOST_MPL_PP_ENUM(0,int): <nothing>
// BOOST_MPL_PP_ENUM(1,int): int
// BOOST_MPL_PP_ENUM(2,int): int, int
// BOOST_MPL_PP_ENUM(n,int): int, int, .., int

#if !defined(QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_ENUM(n, param) \
    QSBOOST_PP_CAT(QSBOOST_MPL_PP_ENUM_,n)(param) \
    /**/
    
#   define QSBOOST_MPL_PP_ENUM_0(p)
#   define QSBOOST_MPL_PP_ENUM_1(p) p
#   define QSBOOST_MPL_PP_ENUM_2(p) p,p
#   define QSBOOST_MPL_PP_ENUM_3(p) p,p,p
#   define QSBOOST_MPL_PP_ENUM_4(p) p,p,p,p
#   define QSBOOST_MPL_PP_ENUM_5(p) p,p,p,p,p
#   define QSBOOST_MPL_PP_ENUM_6(p) p,p,p,p,p,p
#   define QSBOOST_MPL_PP_ENUM_7(p) p,p,p,p,p,p,p
#   define QSBOOST_MPL_PP_ENUM_8(p) p,p,p,p,p,p,p,p
#   define QSBOOST_MPL_PP_ENUM_9(p) p,p,p,p,p,p,p,p,p

#else

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/repeat.hpp>

#   define QSBOOST_MPL_PP_AUX_ENUM_FUNC(unused, i, param) \
    QSBOOST_PP_COMMA_IF(i) param \
    /**/

#   define QSBOOST_MPL_PP_ENUM(n, param) \
    QSBOOST_PP_REPEAT( \
          n \
        , QSBOOST_MPL_PP_AUX_ENUM_FUNC \
        , param \
        ) \
    /**/

#endif

#endif // BOOST_MPL_AUX_PREPROCESSOR_ENUM_HPP_INCLUDED

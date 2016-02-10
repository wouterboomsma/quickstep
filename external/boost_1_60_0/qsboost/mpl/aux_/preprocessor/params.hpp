
#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_PARAMS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_PARAMS_HPP_INCLUDED

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

// BOOST_MPL_PP_PARAMS(0,T): <nothing>
// BOOST_MPL_PP_PARAMS(1,T): T1
// BOOST_MPL_PP_PARAMS(2,T): T1, T2
// BOOST_MPL_PP_PARAMS(n,T): T1, T2, .., Tn

#if !defined(QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_PARAMS(n,p) \
    QSBOOST_PP_CAT(QSBOOST_MPL_PP_PARAMS_,n)(p) \
    /**/

#   define QSBOOST_MPL_PP_PARAMS_0(p)
#   define QSBOOST_MPL_PP_PARAMS_1(p) p##1
#   define QSBOOST_MPL_PP_PARAMS_2(p) p##1,p##2
#   define QSBOOST_MPL_PP_PARAMS_3(p) p##1,p##2,p##3
#   define QSBOOST_MPL_PP_PARAMS_4(p) p##1,p##2,p##3,p##4
#   define QSBOOST_MPL_PP_PARAMS_5(p) p##1,p##2,p##3,p##4,p##5
#   define QSBOOST_MPL_PP_PARAMS_6(p) p##1,p##2,p##3,p##4,p##5,p##6
#   define QSBOOST_MPL_PP_PARAMS_7(p) p##1,p##2,p##3,p##4,p##5,p##6,p##7
#   define QSBOOST_MPL_PP_PARAMS_8(p) p##1,p##2,p##3,p##4,p##5,p##6,p##7,p##8
#   define QSBOOST_MPL_PP_PARAMS_9(p) p##1,p##2,p##3,p##4,p##5,p##6,p##7,p##8,p##9

#else

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/repeat.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_AUX_PARAM_FUNC(unused, i, param) \
    QSBOOST_PP_COMMA_IF(i) \
    QSBOOST_PP_CAT(param, QSBOOST_PP_INC(i)) \
    /**/

#   define QSBOOST_MPL_PP_PARAMS(n, param) \
    QSBOOST_PP_REPEAT( \
          n \
        , QSBOOST_MPL_PP_AUX_PARAM_FUNC \
        , param \
        ) \
    /**/

#endif 

#endif // BOOST_MPL_AUX_PREPROCESSOR_PARAMS_HPP_INCLUDED

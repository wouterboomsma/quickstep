
#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED

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

#include <qsboost/mpl/limits/arity.hpp>
#include <qsboost/mpl/aux_/config/dtp.hpp>
#include <qsboost/mpl/aux_/config/preprocessor.hpp>

#include <qsboost/preprocessor/comma_if.hpp>
#include <qsboost/preprocessor/logical/and.hpp>
#include <qsboost/preprocessor/identity.hpp>
#include <qsboost/preprocessor/empty.hpp>

// BOOST_MPL_PP_DEF_PARAMS_TAIL(1,T,value): , T1 = value, .., Tn = value
// BOOST_MPL_PP_DEF_PARAMS_TAIL(2,T,value): , T2 = value, .., Tn = value
// BOOST_MPL_PP_DEF_PARAMS_TAIL(n,T,value): <nothing>

#if !defined(QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)

#   include <qsboost/mpl/aux_/preprocessor/filter_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/sub.hpp>

#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, value_func) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_1( \
          i \
        , QSBOOST_MPL_PP_SUB(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY,i) \
        , param \
        , value_func \
        ) \
    /**/

#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_1(i, n, param, value_func) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_2(i,n,param,value_func) \
    /**/

#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_DELAY_2(i, n, param, value_func) \
    QSBOOST_PP_COMMA_IF(QSBOOST_PP_AND(i,n)) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_##i(n,param,value_func) \
    /**/

#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_0(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##1 v(),p##2 v(),p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v())
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_1(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##2 v(),p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_2(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##3 v(),p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_3(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##4 v(),p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_4(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##5 v(),p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_5(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##6 v(),p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4,p5)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_6(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##7 v(),p##8 v(),p##9 v(),p1,p2,p3,p4,p5,p6)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_7(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##8 v(),p##9 v(),p1,p2,p3,p4,p5,p6,p7)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_8(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p##9 v(),p1,p2,p3,p4,p5,p6,p7,p8)
#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_9(i,p,v) QSBOOST_MPL_PP_FILTER_PARAMS_##i(p1,p2,p3,p4,p5,p6,p7,p8,p9)

#else

#   include <qsboost/preprocessor/arithmetic/add.hpp>
#   include <qsboost/preprocessor/arithmetic/sub.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/tuple/elem.hpp>
#   include <qsboost/preprocessor/repeat.hpp>
#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_PP_AUX_TAIL_PARAM_FUNC(unused, i, op) \
    , QSBOOST_PP_CAT( \
          QSBOOST_PP_TUPLE_ELEM(3, 1, op) \
        , QSBOOST_PP_ADD_D(1, i, QSBOOST_PP_INC(QSBOOST_PP_TUPLE_ELEM(3, 0, op))) \
        ) QSBOOST_PP_TUPLE_ELEM(3, 2, op)() \
    /**/

#   define QSBOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, value_func) \
    QSBOOST_PP_REPEAT( \
          QSBOOST_PP_SUB_D(1, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, i) \
        , QSBOOST_MPL_PP_AUX_TAIL_PARAM_FUNC \
        , (i, param, value_func) \
        ) \
    /**/


#endif // BOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES

#define QSBOOST_MPL_PP_DEF_PARAMS_TAIL(i, param, value) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, QSBOOST_PP_IDENTITY(=value)) \
    /**/

#if !defined(QSBOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define QSBOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, param, value) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, QSBOOST_PP_IDENTITY(=value)) \
    /**/
#else
#   define QSBOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, param, value) \
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL_IMPL(i, param, QSBOOST_PP_EMPTY) \
    /**/
#endif

#endif // BOOST_MPL_AUX_PREPROCESSOR_DEF_PARAMS_TAIL_HPP_INCLUDED


#ifndef QSBOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !defined(QSBOOST_MPL_CFG_USE_OPERATORS_OVERLOADING) \
    && ( QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) \
        || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
        || QSBOOST_WORKAROUND(__EDG_VERSION__, <= 245) \
        || QSBOOST_WORKAROUND(QSBOOST_MPL_CFG_GCC, <= 0x0295) \
        || QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(600)) \
        || QSBOOST_WORKAROUND(__NVCC__, QSBOOST_TESTED_AT(1)) \
        )

#   define QSBOOST_MPL_CFG_USE_OPERATORS_OVERLOADING

#endif

#endif // BOOST_MPL_AUX_CONFIG_OPERATORS_HPP_INCLUDED

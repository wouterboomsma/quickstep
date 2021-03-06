
#ifndef QSBOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if    !defined(QSBOOST_MPL_CFG_BCC_INTEGRAL_CONSTANTS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610))

#   define QSBOOST_MPL_CFG_BCC_INTEGRAL_CONSTANTS

#endif

#if    !defined(QSBOOST_MPL_CFG_NO_NESTED_VALUE_ARITHMETIC) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && ( QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) \
        || QSBOOST_WORKAROUND(__EDG_VERSION__, <= 238) \
        )

#   define QSBOOST_MPL_CFG_NO_NESTED_VALUE_ARITHMETIC

#endif

#endif // BOOST_MPL_AUX_CONFIG_INTEGRAL_HPP_INCLUDED

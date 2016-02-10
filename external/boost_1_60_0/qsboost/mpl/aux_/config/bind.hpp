
#ifndef QSBOOST_MPL_AUX_CONFIG_BIND_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_BIND_HPP_INCLUDED

// Copyright David Abrahams 2002
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

#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if    !defined(QSBOOST_MPL_CFG_NO_BIND_TEMPLATE) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && (   QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) \
        || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
        )

#   define QSBOOST_MPL_CFG_NO_BIND_TEMPLATE

#endif

//#define BOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT

#endif // BOOST_MPL_AUX_CONFIG_BIND_HPP_INCLUDED

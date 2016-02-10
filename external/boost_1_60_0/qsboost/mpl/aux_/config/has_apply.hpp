
#ifndef QSBOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/has_xxx.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_HAS_APPLY) \
    && (   defined(QSBOOST_MPL_CFG_NO_HAS_XXX) \
        || QSBOOST_WORKAROUND(__EDG_VERSION__, < 300) \
        || QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) \
        || QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3202)) \
        )

#   define QSBOOST_MPL_CFG_NO_HAS_APPLY

#endif

#endif // BOOST_MPL_AUX_CONFIG_HAS_APPLY_HPP_INCLUDED

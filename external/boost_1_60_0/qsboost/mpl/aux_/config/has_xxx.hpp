
#ifndef QSBOOST_MPL_AUX_CONFIG_HAS_XXX_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_HAS_XXX_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
// Copyright David Abrahams 2002-2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/overload_resolution.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

// agurt, 11/jan/03: signals a stub-only 'has_xxx' implementation

#if !defined(QSBOOST_MPL_CFG_NO_HAS_XXX) \
    && (   defined(QSBOOST_MPL_CFG_BROKEN_OVERLOAD_RESOLUTION) \
        || QSBOOST_WORKAROUND(__GNUC__, <= 2) \
        || QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840)) \
        )

#   define QSBOOST_MPL_CFG_NO_HAS_XXX
#   define QSBOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE

#endif

#endif // BOOST_MPL_AUX_CONFIG_HAS_XXX_HPP_INCLUDED

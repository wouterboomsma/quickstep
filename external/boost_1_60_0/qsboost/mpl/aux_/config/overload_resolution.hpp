
#ifndef QSBOOST_MPL_AUX_CONFIG_OVERLOAD_RESOLUTION_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_OVERLOAD_RESOLUTION_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/workaround.hpp>

#if    !defined(QSBOOST_MPL_CFG_BROKEN_OVERLOAD_RESOLUTION) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && (   QSBOOST_WORKAROUND(__BORLANDC__, < 0x590) \
        || QSBOOST_WORKAROUND(__MWERKS__, < 0x3001) \
        )

#   define QSBOOST_MPL_CFG_BROKEN_OVERLOAD_RESOLUTION

#endif

#endif // BOOST_MPL_AUX_CONFIG_OVERLOAD_RESOLUTION_HPP_INCLUDED


#ifndef QSBOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if    !defined(QSBOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && ( QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
        || QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) \
        )

#   define QSBOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES

#endif

#endif // BOOST_MPL_AUX_CONFIG_ARRAYS_HPP_INCLUDED

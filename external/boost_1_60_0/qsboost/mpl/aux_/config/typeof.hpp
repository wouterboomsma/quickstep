
#ifndef QSBOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED

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

#if !defined(QSBOOST_MPL_CFG_HAS_TYPEOF) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && (   defined(QSBOOST_MPL_CFG_GCC) && QSBOOST_MPL_CFG_GCC >= 0x0302 \
        || defined(__MWERKS__) && __MWERKS__ >= 0x3000 \
        )

#   define QSBOOST_MPL_CFG_HAS_TYPEOF

#endif


#if !defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && defined(QSBOOST_MPL_CFG_HAS_TYPEOF)

#   define QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#endif

#endif // BOOST_MPL_AUX_CONFIG_TYPEOF_HPP_INCLUDED

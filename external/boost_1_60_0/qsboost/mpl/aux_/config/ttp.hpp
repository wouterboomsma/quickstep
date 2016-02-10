
#ifndef QSBOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
    && ( defined(QSBOOST_NO_TEMPLATE_TEMPLATES) \
      || QSBOOST_WORKAROUND( __BORLANDC__, QSBOOST_TESTED_AT( 0x590) ) \
       )

#   define QSBOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS

#endif


#if    !defined(QSBOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && (   QSBOOST_WORKAROUND(QSBOOST_MPL_CFG_GCC, QSBOOST_TESTED_AT(0x0302)) \
        || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
        )

#   define QSBOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING

#endif

#endif // BOOST_MPL_AUX_CONFIG_TTP_HPP_INCLUDED

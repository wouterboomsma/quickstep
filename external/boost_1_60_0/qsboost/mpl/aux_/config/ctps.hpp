
#ifndef QSBOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/workaround.hpp>
#include <qsboost/config.hpp>

#if    !defined(QSBOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE) \
    && QSBOOST_WORKAROUND(__BORLANDC__, < 0x582)

#   define QSBOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC

#endif

// BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION is defined in <boost/config.hpp>

#endif // BOOST_MPL_AUX_CONFIG_CTPS_HPP_INCLUDED

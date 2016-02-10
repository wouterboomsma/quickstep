
#ifndef QSBOOST_MPL_AUX_CONFIG_ADL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_ADL_HPP_INCLUDED

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
#include <qsboost/mpl/aux_/config/intel.hpp>
#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

// agurt, 25/apr/04: technically, the ADL workaround is only needed for GCC,
// but putting everything expect public, user-specializable metafunctions into
// a separate global namespace has a nice side effect of reducing the length 
// of template instantiation symbols, so we apply the workaround on all 
// platforms that can handle it

#if !defined(QSBOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE) \
    && (   QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1400)) \
        || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
        || QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840)) \
        || QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3202)) \
        || QSBOOST_WORKAROUND(QSBOOST_INTEL_CXX_VERSION, QSBOOST_TESTED_AT(810)) \
        )

#   define QSBOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE

#endif

#endif // BOOST_MPL_AUX_CONFIG_ADL_HPP_INCLUDED

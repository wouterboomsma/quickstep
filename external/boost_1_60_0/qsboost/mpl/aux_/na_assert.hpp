
#ifndef QSBOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED
#define QSBOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !QSBOOST_WORKAROUND(_MSC_FULL_VER, <= 140050601)    \
    && !QSBOOST_WORKAROUND(__EDG_VERSION__, <= 243)
#   include <qsboost/mpl/assert.hpp>
#   define QSBOOST_MPL_AUX_ASSERT_NOT_NA(x) \
    QSBOOST_MPL_ASSERT_NOT((qsboost::mpl::is_na<type>)) \
/**/
#else
#   include <qsboost/static_assert.hpp>
#   define QSBOOST_MPL_AUX_ASSERT_NOT_NA(x) \
    QSBOOST_STATIC_ASSERT(!qsboost::mpl::is_na<x>::value) \
/**/
#endif

#endif // BOOST_MPL_AUX_NA_ASSERT_HPP_INCLUDED

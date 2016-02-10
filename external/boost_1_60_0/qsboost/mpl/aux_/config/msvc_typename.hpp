
#ifndef QSBOOST_MPL_AUX_CONFIG_MSVC_TYPENAME_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_MSVC_TYPENAME_HPP_INCLUDED

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
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300)
#   define QSBOOST_MSVC_TYPENAME
#else
#   define QSBOOST_MSVC_TYPENAME typename
#endif

#endif // BOOST_MPL_AUX_CONFIG_MSVC_TYPENAME_HPP_INCLUDED

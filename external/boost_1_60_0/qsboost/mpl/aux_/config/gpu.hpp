
#ifndef QSBOOST_MPL_AUX_CONFIG_GPU_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_GPU_HPP_INCLUDED

// Copyright Eric Niebler 2014
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/config.hpp>

#if !defined(QSBOOST_MPL_CFG_GPU_ENABLED) \

#   define QSBOOST_MPL_CFG_GPU_ENABLED QSBOOST_GPU_ENABLED

#endif

#if defined __CUDACC__

#    define QSBOOST_MPL_CFG_GPU 1

#else

#    define QSBOOST_MPL_CFG_GPU 0

#endif

#endif // BOOST_MPL_AUX_CONFIG_GPU_HPP_INCLUDED


#ifndef QSBOOST_MPL_SIZE_T_FWD_HPP_INCLUDED
#define QSBOOST_MPL_SIZE_T_FWD_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/adl_barrier.hpp>
#include <qsboost/config.hpp> // make sure 'size_t' is placed into 'std'
#include <cstddef>

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

template< std::size_t N > struct size_t;

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE
QSBOOST_MPL_AUX_ADL_BARRIER_DECL(size_t)

#endif // BOOST_MPL_SIZE_T_FWD_HPP_INCLUDED

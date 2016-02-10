
#ifndef QSBOOST_MPL_REMOVE_HPP_INCLUDED
#define QSBOOST_MPL_REMOVE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/remove_if.hpp>
#include <qsboost/mpl/same_as.hpp>
#include <qsboost/mpl/aux_/inserter_algorithm.hpp>

namespace qsboost { namespace mpl {

namespace aux {

template<
      typename Sequence
    , typename T
    , typename Inserter 
    >
struct remove_impl
    : remove_if_impl< Sequence, same_as<T>, Inserter >
{
};

template<
      typename Sequence
    , typename T
    , typename Inserter 
    >
struct reverse_remove_impl
    : reverse_remove_if_impl< Sequence, same_as<T>, Inserter >
{
};

} // namespace aux

QSBOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(3, remove)

}}

#endif // BOOST_MPL_REMOVE_HPP_INCLUDED

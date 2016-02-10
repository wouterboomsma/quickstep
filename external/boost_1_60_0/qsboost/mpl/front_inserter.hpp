
#ifndef QSBOOST_MPL_FRONT_INSERTER_HPP_INCLUDED
#define QSBOOST_MPL_FRONT_INSERTER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
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

#include <qsboost/mpl/push_front.hpp>
#include <qsboost/mpl/inserter.hpp>

namespace qsboost { namespace mpl {

template<
      typename Sequence
    >
struct front_inserter
    : inserter< Sequence,push_front<> >
{
};

}}

#endif // BOOST_MPL_FRONT_INSERTER_HPP_INCLUDED

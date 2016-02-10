
#ifndef QSBOOST_MPL_MAP_AUX_INSERT_RANGE_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_MAP_AUX_INSERT_RANGE_IMPL_HPP_INCLUDED

// Copyright Bruno Dutra 2015
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/insert_range_fwd.hpp>
#include <qsboost/mpl/map/aux_/tag.hpp>
#include <qsboost/mpl/placeholders.hpp>
#include <qsboost/mpl/fold.hpp>
#include <qsboost/mpl/insert.hpp>

namespace qsboost { namespace mpl {

template<>
struct insert_range_impl< aux::map_tag >
{
    template<
          typename Sequence
        , typename /*Pos*/
        , typename Range
        >
    struct apply
        : fold<Range, Sequence, insert<_1, _2> >
    {
    };
};

}}

#endif // BOOST_MPL_MAP_AUX_INSERT_RANGE_IMPL_HPP_INCLUDED

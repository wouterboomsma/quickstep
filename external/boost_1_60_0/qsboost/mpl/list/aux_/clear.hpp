
#ifndef QSBOOST_MPL_LIST_AUX_CLEAR_HPP_INCLUDED
#define QSBOOST_MPL_LIST_AUX_CLEAR_HPP_INCLUDED

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

#include <qsboost/mpl/clear_fwd.hpp>
#include <qsboost/mpl/list/aux_/item.hpp>
#include <qsboost/mpl/list/aux_/tag.hpp>

namespace qsboost { namespace mpl {

template<>
struct clear_impl< aux::list_tag >
{
    template< typename List > struct apply
    {
        typedef l_end type;
    };
};

}}

#endif // BOOST_MPL_LIST_AUX_CLEAR_HPP_INCLUDED

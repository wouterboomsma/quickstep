
#ifndef QSBOOST_MPL_VECTOR_AUX_O1_SIZE_HPP_INCLUDED
#define QSBOOST_MPL_VECTOR_AUX_O1_SIZE_HPP_INCLUDED

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

#include <qsboost/mpl/O1_size_fwd.hpp>
#include <qsboost/mpl/minus.hpp>
#include <qsboost/mpl/long.hpp>
#include <qsboost/mpl/vector/aux_/tag.hpp>
#include <qsboost/mpl/aux_/config/typeof.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>

namespace qsboost { namespace mpl {

#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<>
struct O1_size_impl< aux::vector_tag >
{
    template< typename Vector > struct apply
        : Vector::size
    {
    };
};

#else

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< long N >
struct O1_size_impl< aux::vector_tag<N> >
{
    template< typename Vector > struct apply
        : mpl::long_<N>
    {
    };
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // BOOST_MPL_VECTOR_AUX_O1_SIZE_HPP_INCLUDED


#ifndef QSBOOST_MPL_VECTOR_AUX_EMPTY_HPP_INCLUDED
#define QSBOOST_MPL_VECTOR_AUX_EMPTY_HPP_INCLUDED

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

#include <qsboost/mpl/empty_fwd.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/vector/aux_/tag.hpp>
#include <qsboost/mpl/aux_/config/typeof.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>
#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace mpl {

#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<>
struct empty_impl< aux::vector_tag >
{
    template< typename Vector > struct apply
        : is_same<
              typename Vector::lower_bound_
            , typename Vector::upper_bound_
            >
    {
    };
};

#else

template<>
struct empty_impl< aux::vector_tag<0> >
{
    template< typename Vector > struct apply
        : true_
    {
    };
};

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< long N >
struct empty_impl< aux::vector_tag<N> >
{
    template< typename Vector > struct apply
        : false_
    {
    };
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

}}

#endif // BOOST_MPL_VECTOR_AUX_EMPTY_HPP_INCLUDED

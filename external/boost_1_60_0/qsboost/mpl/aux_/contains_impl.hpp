
#ifndef QSBOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED

// Copyright Eric Friedman 2002
// Copyright Aleksey Gurtovoy 2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/contains_fwd.hpp>
#include <qsboost/mpl/begin_end.hpp>
#include <qsboost/mpl/find.hpp>
#include <qsboost/mpl/not.hpp>
#include <qsboost/mpl/aux_/traits_lambda_spec.hpp>
#include <qsboost/mpl/aux_/config/forwarding.hpp>
#include <qsboost/mpl/aux_/config/static_constant.hpp>

#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace mpl {

template< typename Tag >
struct contains_impl
{
    template< typename Sequence, typename T > struct apply
#if !defined(QSBOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : not_< is_same<
              typename find<Sequence,T>::type
            , typename end<Sequence>::type
            > >
    {
#else
    {
        typedef not_< is_same<
              typename find<Sequence,T>::type
            , typename end<Sequence>::type
            > > type;

        QSBOOST_STATIC_CONSTANT(bool, value = 
              (not_< is_same<
                  typename find<Sequence,T>::type
                , typename end<Sequence>::type
                > >::value)
            );
#endif
    };
};

QSBOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(2,contains_impl)

}}

#endif // BOOST_MPL_AUX_CONTAINS_IMPL_HPP_INCLUDED

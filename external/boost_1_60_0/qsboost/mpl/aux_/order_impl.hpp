
#ifndef QSBOOST_MPL_AUX_ORDER_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_ORDER_IMPL_HPP_INCLUDED

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

#include <qsboost/mpl/order_fwd.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/long.hpp>
#include <qsboost/mpl/has_key.hpp>
#include <qsboost/mpl/aux_/overload_names.hpp>
#include <qsboost/mpl/aux_/static_cast.hpp>
#include <qsboost/mpl/aux_/type_wrapper.hpp>
#include <qsboost/mpl/aux_/traits_lambda_spec.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/static_constant.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

namespace qsboost { namespace mpl {

// default implementation; requires 'Seq' to provide corresponding overloads 
// of BOOST_MPL_AUX_OVERLOAD_ORDER_BY_KEY

template< typename Seq, typename Key > struct x_order_impl
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1400)) \
    || QSBOOST_WORKAROUND(__EDG_VERSION__, <= 245)
{
    QSBOOST_STATIC_CONSTANT(long, value = 
          sizeof( QSBOOST_MPL_AUX_OVERLOAD_CALL_ORDER_BY_KEY(
              Seq
            , QSBOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<Key>*, 0)
            ) )
        );

    typedef long_<value> type;

#else // ISO98 C++
    : long_< 
          sizeof( QSBOOST_MPL_AUX_OVERLOAD_CALL_ORDER_BY_KEY(
              Seq
            , QSBOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<Key>*, 0)
            ) )
        >
{
#endif
};

template< typename Tag >
struct order_impl
{
    template< typename Seq, typename Key > struct apply
        : if_<
              typename has_key_impl<Tag>::template apply<Seq,Key>
            , x_order_impl<Seq,Key>
            , void_
            >::type
    {
    };
};

QSBOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(2,order_impl)

}}

#endif // BOOST_MPL_AUX_ORDER_IMPL_HPP_INCLUDED

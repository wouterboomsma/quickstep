
#ifndef QSBOOST_MPL_SAME_AS_HPP_INCLUDED
#define QSBOOST_MPL_SAME_AS_HPP_INCLUDED

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

#include <qsboost/mpl/not.hpp>
#include <qsboost/mpl/aux_/lambda_spec.hpp>
#include <qsboost/mpl/aux_/config/forwarding.hpp>

#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace mpl {

template< typename T1 >
struct same_as
{
    template< typename T2 > struct apply
#if !defined(QSBOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : is_same<T1,T2>
    {
#else
    {
        typedef typename is_same<T1,T2>::type type;
#endif
    };
};

template< typename T1 >
struct not_same_as
{
    template< typename T2 > struct apply
#if !defined(QSBOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : not_< is_same<T1,T2> >
    {
#else
    {
        typedef typename not_< is_same<T1,T2> >::type type;
#endif
    };
};

}}

#endif // BOOST_MPL_SAME_AS_HPP_INCLUDED

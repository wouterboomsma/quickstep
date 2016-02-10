
#ifndef QSBOOST_MPL_EMPTY_BASE_HPP_INCLUDED
#define QSBOOST_MPL_EMPTY_BASE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

#include <qsboost/type_traits/integral_constant.hpp>
#include <qsboost/type_traits/is_empty.hpp>

namespace qsboost { namespace mpl {

// empty base class, guaranteed to have no members; inheritance from
// 'empty_base' through the 'inherit' metafunction is a no-op - see 
// "mpl/inherit.hpp> header for the details
struct empty_base {};

template< typename T >
struct is_empty_base
    : false_
{
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
    using false_::value;
#endif
};

template<>
struct is_empty_base<empty_base>
    : true_
{
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
    using true_::value;
#endif
};

}}

namespace qsboost {

template<> struct is_empty< mpl::empty_base >
    : public ::qsboost::integral_constant<bool,true>
{
public:
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(1,is_empty,(mpl::empty_base))
};

}

#endif // BOOST_MPL_EMPTY_BASE_HPP_INCLUDED

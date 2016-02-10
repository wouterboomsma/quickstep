
#ifndef QSBOOST_MPL_SET_AUX_SET0_HPP_INCLUDED
#define QSBOOST_MPL_SET_AUX_SET0_HPP_INCLUDED

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

#include <qsboost/mpl/long.hpp>
#include <qsboost/mpl/void.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/set/aux_/tag.hpp>
#include <qsboost/mpl/aux_/yes_no.hpp>
#include <qsboost/mpl/aux_/overload_names.hpp>
#include <qsboost/mpl/aux_/config/operators.hpp>

#include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

#if defined(QSBOOST_MPL_CFG_USE_OPERATORS_OVERLOADING)

#   define QSBOOST_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
    friend R QSBOOST_PP_CAT(QSBOOST_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define QSBOOST_MPL_AUX_SET_OVERLOAD(R, f, X, T) \
    QSBOOST_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
/**/

#else

#   define QSBOOST_MPL_AUX_SET0_OVERLOAD(R, f, X, T) \
    static R QSBOOST_PP_CAT(QSBOOST_MPL_AUX_OVERLOAD_,f)(X const&, T) \
/**/

#   define QSBOOST_MPL_AUX_SET_OVERLOAD(R, f, X, T) \
    QSBOOST_MPL_AUX_SET0_OVERLOAD(R, f, X, T); \
    using Base::QSBOOST_PP_CAT(QSBOOST_MPL_AUX_OVERLOAD_,f) \
/**/

#endif

template< typename Dummy = na > struct set0
{
    typedef set0<>          item_;
    typedef item_           type;
    typedef aux::set_tag    tag;
    typedef void_           last_masked_;
    typedef void_           item_type_;
    typedef long_<0>        size;
    typedef long_<1>        order;

    QSBOOST_MPL_AUX_SET0_OVERLOAD( aux::no_tag, ORDER_BY_KEY, set0<>, void const volatile* );
    QSBOOST_MPL_AUX_SET0_OVERLOAD( aux::yes_tag, IS_MASKED, set0<>, void const volatile* );
};

}}

#endif // BOOST_MPL_SET_AUX_SET0_HPP_INCLUDED

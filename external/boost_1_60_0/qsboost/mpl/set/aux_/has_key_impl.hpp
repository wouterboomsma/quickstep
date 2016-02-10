
#ifndef QSBOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED

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

#include <qsboost/mpl/set/aux_/tag.hpp>
#include <qsboost/mpl/has_key_fwd.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/aux_/overload_names.hpp>
#include <qsboost/mpl/aux_/static_cast.hpp>
#include <qsboost/mpl/aux_/yes_no.hpp>
#include <qsboost/mpl/aux_/type_wrapper.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>
#include <qsboost/mpl/aux_/config/static_constant.hpp>

namespace qsboost { namespace mpl {

template<>
struct has_key_impl< aux::set_tag >
{
    template< typename Set, typename T > struct apply
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1400)) \
    || QSBOOST_WORKAROUND(__EDG_VERSION__, <= 245)
    {
        QSBOOST_STATIC_CONSTANT(bool, value = 
              ( sizeof( QSBOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(
                    Set
                  , QSBOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<T>*, 0)
                  ) ) == sizeof(aux::no_tag) )
            );

        typedef bool_<value> type;

#else // ISO98 C++
        : bool_< 
              ( sizeof( QSBOOST_MPL_AUX_OVERLOAD_CALL_IS_MASKED(
                    Set
                  , QSBOOST_MPL_AUX_STATIC_CAST(aux::type_wrapper<T>*, 0)
                  ) ) == sizeof(aux::no_tag) )
            >
    {
#endif
    };
};

}}

#endif // BOOST_MPL_SET_AUX_HAS_KEY_IMPL_HPP_INCLUDED

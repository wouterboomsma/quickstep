
#ifndef QSBOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED
#define QSBOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/intel.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if QSBOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(QSBOOST_INTEL_CXX_VERSION)
#   include <qsboost/mpl/has_xxx.hpp>
#elif QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
#   include <qsboost/mpl/has_xxx.hpp>
#   include <qsboost/mpl/if.hpp>
#   include <qsboost/mpl/bool.hpp>
#   include <qsboost/mpl/aux_/msvc_is_class.hpp>
#elif QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610))
#   include <qsboost/mpl/if.hpp>
#   include <qsboost/mpl/bool.hpp>
#   include <qsboost/mpl/aux_/yes_no.hpp>
#   include <qsboost/mpl/aux_/config/static_constant.hpp>
#   include <qsboost/type_traits/is_class.hpp>
#else
#   include <qsboost/mpl/aux_/type_wrapper.hpp>
#   include <qsboost/mpl/aux_/yes_no.hpp>
#   include <qsboost/mpl/aux_/config/static_constant.hpp>
#endif

namespace qsboost { namespace mpl { namespace aux {

#if QSBOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(QSBOOST_INTEL_CXX_VERSION)

QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind, rebind, false)

#elif QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)

QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(has_rebind_impl, rebind, false)

template< typename T >
struct has_rebind
    : if_< 
          msvc_is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};

#else // the rest

template< typename T > struct has_rebind_tag {};
no_tag operator|(has_rebind_tag<int>, void const volatile*);

#   if !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610))
template< typename T >
struct has_rebind
{
    static has_rebind_tag<T>* get();
    QSBOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};
#   else // __BORLANDC__
template< typename T >
struct has_rebind_impl
{
    static T* get();
    QSBOOST_STATIC_CONSTANT(bool, value = 
          sizeof(has_rebind_tag<int>() | get()) == sizeof(yes_tag)
        );
};

template< typename T >
struct has_rebind
    : if_< 
          is_class<T>
        , has_rebind_impl<T>
        , bool_<false>
        >::type
{
};
#   endif // __BORLANDC__

#endif

}}}

#endif // BOOST_MPL_AUX_HAS_REBIND_HPP_INCLUDED

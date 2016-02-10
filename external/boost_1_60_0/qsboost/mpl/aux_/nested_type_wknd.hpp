
#ifndef QSBOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED
#define QSBOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if QSBOOST_WORKAROUND(QSBOOST_MPL_CFG_GCC, QSBOOST_TESTED_AT(0x0302)) \
    || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x561)) \
    || QSBOOST_WORKAROUND(__SUNPRO_CC, QSBOOST_TESTED_AT(0x530)) \
    || QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840))

namespace qsboost { namespace mpl { namespace aux {
template< typename T > struct nested_type_wknd
    : T::type
{
};
}}}

#if QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840))
#   define QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    aux::nested_type_wknd<T> \
/**/
#else
#   define QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T) \
    ::qsboost::mpl::aux::nested_type_wknd<T> \
/**/
#endif

#else // !BOOST_MPL_CFG_GCC et al.

#   define QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T) T::type

#endif 

#endif // BOOST_MPL_AUX_NESTED_TYPE_WKND_HPP_INCLUDED

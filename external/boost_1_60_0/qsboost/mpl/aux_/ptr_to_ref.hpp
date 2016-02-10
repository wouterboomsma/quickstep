
#ifndef QSBOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/static_cast.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>


#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1400)) \
    ||  ( QSBOOST_WORKAROUND(__EDG_VERSION__, <= 245) \
        && !(defined(__STD_STRICT_ANSI) \
            || defined(__STD_STRICT_ANSI_ERRORS)) )

#   define QSBOOST_MPL_AUX_PTR_TO_REF(X) \
    *QSBOOST_MPL_AUX_STATIC_CAST(X*, 0) \
/**/

#else

#   define QSBOOST_MPL_AUX_PTR_TO_REF(X) \
    aux::ptr_to_ref(QSBOOST_MPL_AUX_STATIC_CAST(X*, 0)) \
/**/

#endif


namespace qsboost { namespace mpl { namespace aux {

template< typename T > static T const& ptr_to_ref(T*);

}}}

#endif // BOOST_MPL_AUX_PTR_TO_REF_HPP_INCLUDED

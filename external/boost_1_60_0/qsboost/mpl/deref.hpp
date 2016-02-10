
#ifndef QSBOOST_MPL_DEREF_HPP_INCLUDED
#define QSBOOST_MPL_DEREF_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/msvc_type.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>
#include <qsboost/mpl/aux_/config/eti.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Iterator)
    >
struct deref
{
#if !defined(QSBOOST_MPL_CFG_MSVC_70_ETI_BUG)
    typedef typename Iterator::type type;
#else
    typedef typename aux::msvc_type<Iterator>::type type;
#endif
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,deref,(Iterator))
};

QSBOOST_MPL_AUX_NA_SPEC(1, deref)

}}

#endif // BOOST_MPL_DEREF_HPP_INCLUDED


#ifndef QSBOOST_MPL_NEXT_PRIOR_HPP_INCLUDED
#define QSBOOST_MPL_NEXT_PRIOR_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/common_name_wknd.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

QSBOOST_MPL_AUX_COMMON_NAME_WKND(next)
QSBOOST_MPL_AUX_COMMON_NAME_WKND(prior)

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(T)
    >
struct next
{
    typedef typename T::next type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,next,(T))
};

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(T)
    >
struct prior
{
    typedef typename T::prior type;
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,prior,(T))
};

QSBOOST_MPL_AUX_NA_SPEC(1, next)
QSBOOST_MPL_AUX_NA_SPEC(1, prior)

}}

#endif // BOOST_MPL_NEXT_PRIOR_HPP_INCLUDED

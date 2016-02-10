
#ifndef QSBOOST_MPL_FIND_HPP_INCLUDED
#define QSBOOST_MPL_FIND_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/find_if.hpp>
#include <qsboost/mpl/same_as.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(T)
    >
struct find
    : find_if< Sequence,same_as<T> >
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,find,(Sequence,T))
};

QSBOOST_MPL_AUX_NA_SPEC(2, find)

}}

#endif // BOOST_MPL_FIND_HPP_INCLUDED

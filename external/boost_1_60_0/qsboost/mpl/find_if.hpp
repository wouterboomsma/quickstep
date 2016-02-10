
#ifndef QSBOOST_MPL_FIND_IF_HPP_INCLUDED
#define QSBOOST_MPL_FIND_IF_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/find_if_pred.hpp>
#include <qsboost/mpl/arg.hpp>
#include <qsboost/mpl/iter_fold_if.hpp>
#include <qsboost/mpl/aux_/common_name_wknd.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

QSBOOST_MPL_AUX_COMMON_NAME_WKND(find_if)

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(Predicate)
    >
struct find_if
{
    typedef typename iter_fold_if<
          Sequence
        , void
        , mpl::arg<1> // ignore
        , protect< aux::find_if_pred<Predicate> >
        >::type result_;

    typedef typename second<result_>::type type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,find_if,(Sequence,Predicate))
};

QSBOOST_MPL_AUX_NA_SPEC(2,find_if)

}}

#endif // BOOST_MPL_FIND_IF_HPP_INCLUDED

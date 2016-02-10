
#ifndef QSBOOST_MPL_ITER_FOLD_HPP_INCLUDED
#define QSBOOST_MPL_ITER_FOLD_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
// Copyright David Abrahams 2001-2002
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/begin_end.hpp>
#include <qsboost/mpl/O1_size.hpp>
#include <qsboost/mpl/lambda.hpp>
#include <qsboost/mpl/aux_/iter_fold_impl.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(State)
    , typename QSBOOST_MPL_AUX_NA_PARAM(ForwardOp)
    >
struct iter_fold
{
    typedef typename aux::iter_fold_impl<
          ::qsboost::mpl::O1_size<Sequence>::value
        , typename begin<Sequence>::type
        , typename end<Sequence>::type
        , State
        , typename lambda<ForwardOp>::type
        >::state type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(3,iter_fold,(Sequence,State,ForwardOp))
};

QSBOOST_MPL_AUX_NA_SPEC(3, iter_fold)

}}

#endif // BOOST_MPL_ITER_FOLD_HPP_INCLUDED

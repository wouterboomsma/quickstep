
#ifndef QSBOOST_MPL_REVERSE_FOLD_HPP_INCLUDED
#define QSBOOST_MPL_REVERSE_FOLD_HPP_INCLUDED

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
#include <qsboost/mpl/arg.hpp>
#include <qsboost/mpl/aux_/reverse_fold_impl.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(State)
    , typename QSBOOST_MPL_AUX_NA_PARAM(BackwardOp)
    , typename ForwardOp = arg<1>
    >
struct reverse_fold
{
    typedef typename aux::reverse_fold_impl<
          ::qsboost::mpl::O1_size<Sequence>::value
        , typename begin<Sequence>::type
        , typename end<Sequence>::type
        , State
        , BackwardOp
        , ForwardOp
        >::state type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(3,reverse_fold,(Sequence,State,BackwardOp))
};

QSBOOST_MPL_AUX_NA_SPEC(3, reverse_fold)

}}

#endif // BOOST_MPL_REVERSE_FOLD_HPP_INCLUDED

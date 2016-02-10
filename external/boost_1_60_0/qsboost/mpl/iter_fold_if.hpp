
#ifndef QSBOOST_MPL_ITER_FOLD_IF_HPP_INCLUDED
#define QSBOOST_MPL_ITER_FOLD_IF_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright Eric Friedman 2003
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
#include <qsboost/mpl/logical.hpp>
#include <qsboost/mpl/always.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/pair.hpp>
#include <qsboost/mpl/apply.hpp>
#include <qsboost/mpl/aux_/iter_fold_if_impl.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>
#include <qsboost/mpl/aux_/config/forwarding.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace mpl {

namespace aux {

template< typename Predicate, typename LastIterator >
struct iter_fold_if_pred
{
    template< typename State, typename Iterator > struct apply
#if !defined(QSBOOST_MPL_CFG_NO_NESTED_FORWARDING)
        : and_<
              not_< is_same<Iterator,LastIterator> >
            , apply1<Predicate,Iterator>
            >
    {
#else
    {
        typedef and_<
              not_< is_same<Iterator,LastIterator> >
            , apply1<Predicate,Iterator>
            > type;
#endif
    };
};

} // namespace aux

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(State)
    , typename QSBOOST_MPL_AUX_NA_PARAM(ForwardOp)
    , typename QSBOOST_MPL_AUX_NA_PARAM(ForwardPredicate)
    , typename QSBOOST_MPL_AUX_NA_PARAM(BackwardOp)
    , typename QSBOOST_MPL_AUX_NA_PARAM(BackwardPredicate)
    >
struct iter_fold_if
{

    typedef typename begin<Sequence>::type first_;
    typedef typename end<Sequence>::type last_;

    typedef typename eval_if<
          is_na<BackwardPredicate>
        , if_< is_na<BackwardOp>, always<false_>, always<true_> >
        , identity<BackwardPredicate>
        >::type backward_pred_;

// cwpro8 doesn't like 'cut-off' type here (use typedef instead)
#if !QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3003)) && !QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(600))
    struct result_ :
#else
    typedef
#endif
        aux::iter_fold_if_impl<
          first_
        , State
        , ForwardOp
        , protect< aux::iter_fold_if_pred< ForwardPredicate,last_ > >
        , BackwardOp
        , backward_pred_
        >
#if !QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3003)) && !QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(600))
    { };
#else
    result_;
#endif

public:

    typedef pair<
          typename result_::state
        , typename result_::iterator
        > type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(
          6
        , iter_fold_if
        , (Sequence,State,ForwardOp,ForwardPredicate,BackwardOp,BackwardPredicate)
        )
};

QSBOOST_MPL_AUX_NA_SPEC(6, iter_fold_if)

}}

#endif // BOOST_MPL_ITER_FOLD_IF_HPP_INCLUDED

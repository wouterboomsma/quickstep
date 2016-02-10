
#ifndef QSBOOST_MPL_MAX_ELEMENT_HPP_INCLUDED
#define QSBOOST_MPL_MAX_ELEMENT_HPP_INCLUDED

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

#include <qsboost/mpl/less.hpp>
#include <qsboost/mpl/iter_fold.hpp>
#include <qsboost/mpl/begin_end.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/deref.hpp>
#include <qsboost/mpl/apply.hpp>
#include <qsboost/mpl/aux_/common_name_wknd.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>

namespace qsboost { namespace mpl {

QSBOOST_MPL_AUX_COMMON_NAME_WKND(max_element)

namespace aux {

template< typename Predicate >
struct select_max
{
    template< typename OldIterator, typename Iterator >
    struct apply
    {
        typedef typename apply2<
              Predicate
            , typename deref<OldIterator>::type
            , typename deref<Iterator>::type
            >::type condition_;

        typedef typename if_<
              condition_
            , Iterator
            , OldIterator
            >::type type;
    };
};

} // namespace aux 


template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename Predicate = less<_,_>
    >
struct max_element
    : iter_fold<
          Sequence
        , typename begin<Sequence>::type
        , protect< aux::select_max<Predicate> >
        >
{
};

QSBOOST_MPL_AUX_NA_SPEC(1, max_element)

}}

#endif // BOOST_MPL_MAX_ELEMENT_HPP_INCLUDED

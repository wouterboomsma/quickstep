
#ifndef QSBOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED
#define QSBOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED

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

#include <qsboost/mpl/begin_end.hpp>
#include <qsboost/mpl/lambda.hpp>
#include <qsboost/mpl/aux_/transform_iter.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(F)
    >
struct transform_view
{
 private:
    typedef typename lambda<F>::type f_;
    typedef typename begin<Sequence>::type first_;
    typedef typename end<Sequence>::type last_;
 
 public:
    struct tag;
    typedef transform_view type;
    typedef aux::transform_iter< first_,last_,f_ > begin;
    typedef aux::transform_iter< last_,last_,f_ > end;
};

QSBOOST_MPL_AUX_NA_SPEC(2, transform_view)

}}

#endif // BOOST_MPL_TRANSFORM_VIEW_HPP_INCLUDED

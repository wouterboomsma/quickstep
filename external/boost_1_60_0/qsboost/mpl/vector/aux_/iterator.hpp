
#ifndef QSBOOST_MPL_AUX_VECTOR_ITERATOR_HPP_INCLUDED
#define QSBOOST_MPL_AUX_VECTOR_ITERATOR_HPP_INCLUDED

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

#include <qsboost/mpl/vector/aux_/at.hpp>
#include <qsboost/mpl/iterator_tags.hpp>
#include <qsboost/mpl/plus.hpp>
#include <qsboost/mpl/minus.hpp>
#include <qsboost/mpl/advance_fwd.hpp>
#include <qsboost/mpl/distance_fwd.hpp>
#include <qsboost/mpl/next.hpp>
#include <qsboost/mpl/prior.hpp>
#include <qsboost/mpl/aux_/nttp_decl.hpp>
#include <qsboost/mpl/aux_/value_wknd.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

namespace qsboost { namespace mpl {

template<
      typename Vector
    , QSBOOST_MPL_AUX_NTTP_DECL(long, n_)
    >
struct v_iter
{
    typedef aux::v_iter_tag tag;
    typedef random_access_iterator_tag category;
    typedef typename v_at<Vector,n_>::type type;

    typedef Vector vector_;
    typedef mpl::long_<n_> pos;

#if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    enum { 
          next_ = n_ + 1
        , prior_ = n_ - 1
        , pos_ = n_
    };
    
    typedef v_iter<Vector,next_> next;
    typedef v_iter<Vector,prior_> prior;
#endif

};


#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template<
      typename Vector
    , QSBOOST_MPL_AUX_NTTP_DECL(long, n_)
    >
struct next< v_iter<Vector,n_> >
{
    typedef v_iter<Vector,(n_ + 1)> type;
};

template<
      typename Vector
    , QSBOOST_MPL_AUX_NTTP_DECL(long, n_)
    >
struct prior< v_iter<Vector,n_> >
{
    typedef v_iter<Vector,(n_ - 1)> type;
};

template<
      typename Vector
    , QSBOOST_MPL_AUX_NTTP_DECL(long, n_)
    , typename Distance
    >
struct advance< v_iter<Vector,n_>,Distance>
{
    typedef v_iter<
          Vector
        , (n_ + QSBOOST_MPL_AUX_NESTED_VALUE_WKND(long, Distance))
        > type;
};

template< 
      typename Vector
    , QSBOOST_MPL_AUX_NTTP_DECL(long, n_)
    , QSBOOST_MPL_AUX_NTTP_DECL(long, m_)
    > 
struct distance< v_iter<Vector,n_>, v_iter<Vector,m_> >
    : mpl::long_<(m_ - n_)>
{
};

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template<> struct advance_impl<aux::v_iter_tag>
{
    template< typename Iterator, typename N > struct apply
    {
        enum { pos_ = Iterator::pos_, n_ = N::value };
        typedef v_iter<
              typename Iterator::vector_
            , (pos_ + n_)
            > type;
    };
};

template<> struct distance_impl<aux::v_iter_tag>
{
    template< typename Iter1, typename Iter2 > struct apply
    {
        enum { pos1_ = Iter1::pos_, pos2_ = Iter2::pos_ };
        typedef long_<( pos2_ - pos1_ )> type;
        QSBOOST_STATIC_CONSTANT(long, value = ( pos2_ - pos1_ ));
    };
};

#endif

}}

#endif // BOOST_MPL_AUX_VECTOR_ITERATOR_HPP_INCLUDED

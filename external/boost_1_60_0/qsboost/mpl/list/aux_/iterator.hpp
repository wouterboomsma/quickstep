
#ifndef QSBOOST_MPL_LIST_AUX_ITERATOR_HPP_INCLUDED
#define QSBOOST_MPL_LIST_AUX_ITERATOR_HPP_INCLUDED

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

#include <qsboost/mpl/iterator_tags.hpp>
#include <qsboost/mpl/next_prior.hpp>
#include <qsboost/mpl/deref.hpp>
#include <qsboost/mpl/list/aux_/item.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/lambda_spec.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>

namespace qsboost { namespace mpl {

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Node >
struct l_iter
{
    typedef aux::l_iter_tag tag;
    typedef forward_iterator_tag category;
};

template< typename Node >
struct deref< l_iter<Node> >
{
    typedef typename Node::item type;
};

template< typename Node >
struct next< l_iter<Node> >
{
    typedef l_iter< typename Node::next > type;
};

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< typename Node >
struct l_iter
{
    typedef aux::l_iter_tag tag;
    typedef forward_iterator_tag category;
    typedef typename Node::item type;
    typedef l_iter< typename mpl::next<Node>::type > next;
};

#endif


template<> struct l_iter<l_end>
{
    typedef aux::l_iter_tag tag;
    typedef forward_iterator_tag category;
#if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    typedef na type;
    typedef l_iter next;
#endif
};

QSBOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(1, l_iter)

}}

#endif // BOOST_MPL_LIST_AUX_ITERATOR_HPP_INCLUDED

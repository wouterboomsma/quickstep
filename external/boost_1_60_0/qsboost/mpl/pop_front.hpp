
#ifndef QSBOOST_MPL_POP_FRONT_HPP_INCLUDED
#define QSBOOST_MPL_POP_FRONT_HPP_INCLUDED

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

#include <qsboost/mpl/pop_front_fwd.hpp>
#include <qsboost/mpl/aux_/pop_front_impl.hpp>
#include <qsboost/mpl/sequence_tag.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    >
struct pop_front
    : pop_front_impl< typename sequence_tag<Sequence>::type >
        ::template apply< Sequence >
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,pop_front,(Sequence))
};

QSBOOST_MPL_AUX_NA_SPEC(1, pop_front)

}}

#endif // BOOST_MPL_POP_FRONT_HPP_INCLUDED

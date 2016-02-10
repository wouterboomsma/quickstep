
#ifndef QSBOOST_MPL_AT_HPP_INCLUDED
#define QSBOOST_MPL_AT_HPP_INCLUDED

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

#include <qsboost/mpl/at_fwd.hpp>
#include <qsboost/mpl/aux_/at_impl.hpp>
#include <qsboost/mpl/long.hpp>
#include <qsboost/mpl/sequence_tag.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>
#include <qsboost/mpl/aux_/nttp_decl.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(Sequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(N)
    >
struct at
    : at_impl< typename sequence_tag<Sequence>::type >
        ::template apply< Sequence,N >
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,at,(Sequence,N))
};

template<
      typename Sequence
    , QSBOOST_MPL_AUX_NTTP_DECL(long, N)
    >
struct at_c
    : at_impl< typename sequence_tag<Sequence>::type >
        ::template apply< Sequence,mpl::long_<N> >
{
};

QSBOOST_MPL_AUX_NA_SPEC(2, at)

}}

#endif // BOOST_MPL_AT_HPP_INCLUDED


#ifndef QSBOOST_MPL_HAS_KEY_HPP_INCLUDED
#define QSBOOST_MPL_HAS_KEY_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/has_key_fwd.hpp>
#include <qsboost/mpl/sequence_tag.hpp>
#include <qsboost/mpl/aux_/has_key_impl.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(AssociativeSequence)
    , typename QSBOOST_MPL_AUX_NA_PARAM(Key)
    >
struct has_key
    : has_key_impl< typename sequence_tag<AssociativeSequence>::type >
        ::template apply<AssociativeSequence,Key>
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,has_key,(AssociativeSequence,Key))
};

QSBOOST_MPL_AUX_NA_SPEC(2, has_key)

}}

#endif // BOOST_MPL_HAS_KEY_HPP_INCLUDED

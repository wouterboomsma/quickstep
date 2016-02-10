
#ifndef QSBOOST_MPL_AUX_CLEAR_IMPL_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CLEAR_IMPL_HPP_INCLUDED

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

#include <qsboost/mpl/clear_fwd.hpp>
#include <qsboost/mpl/aux_/traits_lambda_spec.hpp>
#include <qsboost/mpl/aux_/config/eti.hpp>

namespace qsboost { namespace mpl {

// no default implementation; the definition is needed to make MSVC happy

template< typename Tag >
struct clear_impl
{
    template< typename Sequence > struct apply;
};

QSBOOST_MPL_ALGORITM_TRAITS_LAMBDA_SPEC(1, clear_impl)

}}

#endif // BOOST_MPL_AUX_CLEAR_IMPL_HPP_INCLUDED

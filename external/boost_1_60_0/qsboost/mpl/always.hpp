
#ifndef QSBOOST_MPL_ALWAYS_HPP_INCLUDED
#define QSBOOST_MPL_ALWAYS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/arity_spec.hpp>

namespace qsboost { namespace mpl {

template< typename Value > struct always
{
    template<
        QSBOOST_MPL_PP_DEFAULT_PARAMS(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, typename T, na)
        >
    struct apply
    {
        typedef Value type;
    };
};

QSBOOST_MPL_AUX_ARITY_SPEC(0, always)

}}

#endif // BOOST_MPL_ALWAYS_HPP_INCLUDED

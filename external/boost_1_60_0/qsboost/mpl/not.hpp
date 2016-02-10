
#ifndef QSBOOST_MPL_NOT_HPP_INCLUDED
#define QSBOOST_MPL_NOT_HPP_INCLUDED

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

#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/aux_/nttp_decl.hpp>
#include <qsboost/mpl/aux_/nested_type_wknd.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>

namespace qsboost { namespace mpl {

namespace aux {

template< QSBOOST_MPL_AUX_NTTP_DECL(long, C_) > // 'long' is intentional here
struct not_impl
    : bool_<!C_>
{
};

} // namespace aux


template<
      typename QSBOOST_MPL_AUX_NA_PARAM(T)
    >
struct not_
    : aux::not_impl<
          QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T)::value
        >
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,not_,(T))
};

QSBOOST_MPL_AUX_NA_SPEC(1,not_)

}}

#endif // BOOST_MPL_NOT_HPP_INCLUDED

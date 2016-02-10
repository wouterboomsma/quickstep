
#ifndef QSBOOST_MPL_LAMBDA_FWD_HPP_INCLUDED
#define QSBOOST_MPL_LAMBDA_FWD_HPP_INCLUDED

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

#include <qsboost/mpl/void_fwd.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/config/lambda.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   include <qsboost/mpl/int.hpp>
#   include <qsboost/mpl/aux_/lambda_arity_param.hpp>
#   include <qsboost/mpl/aux_/template_arity_fwd.hpp>

namespace qsboost { namespace mpl {

template< 
      typename T = na
    , typename Tag = void_
    QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity = int_< aux::template_arity<T>::value >
        )
    >
struct lambda;

}}

#else // BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#   include <qsboost/mpl/bool.hpp>

namespace qsboost { namespace mpl {

template< 
      typename T = na
    , typename Tag = void_
    , typename Protect = true_
    > 
struct lambda;

}}

#endif

#endif // BOOST_MPL_LAMBDA_FWD_HPP_INCLUDED

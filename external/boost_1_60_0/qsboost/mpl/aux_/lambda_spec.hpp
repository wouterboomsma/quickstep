
#ifndef QSBOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED
#define QSBOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2007
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/void.hpp>
#include <qsboost/mpl/lambda_fwd.hpp>
#include <qsboost/mpl/int_fwd.hpp>
#include <qsboost/mpl/aux_/preprocessor/params.hpp>
#include <qsboost/mpl/aux_/lambda_arity_param.hpp>
#include <qsboost/mpl/aux_/config/lambda.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define QSBOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(i, name) \
template< \
      QSBOOST_MPL_PP_PARAMS(i, typename T) \
    , typename Tag \
    > \
struct lambda< \
      name< QSBOOST_MPL_PP_PARAMS(i, T) > \
    , Tag \
    QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(int_<i>) \
    > \
{ \
    typedef false_ is_le; \
    typedef name< QSBOOST_MPL_PP_PARAMS(i, T) > result_; \
    typedef result_ type; \
}; \
/**/

#else

#   define QSBOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(i, name) /**/

#endif

#endif // BOOST_MPL_AUX_LAMBDA_SPEC_HPP_INCLUDED


#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED

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

#include <qsboost/mpl/limits/arity.hpp>
#include <qsboost/mpl/aux_/preprocessor/params.hpp>
#include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#include <qsboost/mpl/aux_/preprocessor/sub.hpp>
#include <qsboost/preprocessor/comma_if.hpp>

#define QSBOOST_MPL_PP_PARTIAL_SPEC_PARAMS(n, param, def) \
QSBOOST_MPL_PP_PARAMS(n, param) \
QSBOOST_PP_COMMA_IF(QSBOOST_MPL_PP_SUB(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY,n)) \
QSBOOST_MPL_PP_ENUM( \
      QSBOOST_MPL_PP_SUB(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY,n) \
    , def \
    ) \
/**/

#endif // BOOST_MPL_AUX_PREPROCESSOR_PARTIAL_SPEC_PARAMS_HPP_INCLUDED

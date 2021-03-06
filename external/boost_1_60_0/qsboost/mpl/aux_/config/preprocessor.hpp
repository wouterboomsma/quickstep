
#ifndef QSBOOST_MPL_AUX_CONFIG_PREPROCESSOR_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_PREPROCESSOR_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !defined(QSBOOST_MPL_CFG_BROKEN_PP_MACRO_EXPANSION) \
    && (   QSBOOST_WORKAROUND(__MWERKS__, <= 0x3003) \
        || QSBOOST_WORKAROUND(__BORLANDC__, < 0x582) \
        || QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(502)) \
        )

#   define QSBOOST_MPL_CFG_BROKEN_PP_MACRO_EXPANSION

#endif

#if !defined(QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES)
#   define QSBOOST_MPL_CFG_NO_OWN_PP_PRIMITIVES
#endif

#if !defined(QSBOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING) \
    && QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840))
#   define QSBOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING
#endif


#endif // BOOST_MPL_AUX_CONFIG_PREPROCESSOR_HPP_INCLUDED

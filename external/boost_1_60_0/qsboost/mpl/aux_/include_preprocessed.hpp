
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/compiler.hpp>
#include <qsboost/mpl/aux_/config/preprocessor.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/stringize.hpp>

#if !defined(QSBOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_PREPROCESSED_HEADER \
    QSBOOST_MPL_CFG_COMPILER_DIR/QSBOOST_MPL_PREPROCESSED_HEADER \
/**/
#else
#   define AUX778076_PREPROCESSED_HEADER \
    QSBOOST_PP_CAT(QSBOOST_MPL_CFG_COMPILER_DIR,/)##QSBOOST_MPL_PREPROCESSED_HEADER \
/**/
#endif

#if QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING QSBOOST_PP_STRINGIZE(qsboost/mpl/aux_/preprocessed/AUX778076_PREPROCESSED_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include QSBOOST_PP_STRINGIZE(qsboost/mpl/aux_/preprocessed/AUX778076_PREPROCESSED_HEADER)
#endif

#   undef AUX778076_PREPROCESSED_HEADER

#undef QSBOOST_MPL_PREPROCESSED_HEADER

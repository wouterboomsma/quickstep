
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

// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

#include <qsboost/mpl/aux_/config/typeof.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>
#include <qsboost/mpl/aux_/config/preprocessor.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/stringize.hpp>

#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
#   define AUX778076_INCLUDE_DIR typeof_based
#elif defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#   define AUX778076_INCLUDE_DIR no_ctps
#else
#   define AUX778076_INCLUDE_DIR plain
#endif

#if !defined(QSBOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_HEADER \
    AUX778076_INCLUDE_DIR/QSBOOST_MPL_PREPROCESSED_HEADER \
/**/
#else
#   define AUX778076_HEADER \
    QSBOOST_PP_CAT(AUX778076_INCLUDE_DIR,/)##QSBOOST_MPL_PREPROCESSED_HEADER \
/**/
#endif

#if QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING QSBOOST_PP_STRINGIZE(qsboost/mpl/map/aux_/preprocessed/AUX778076_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include QSBOOST_PP_STRINGIZE(qsboost/mpl/map/aux_/preprocessed/AUX778076_HEADER)
#endif

#   undef AUX778076_HEADER
#   undef AUX778076_INCLUDE_DIR

#undef QSBOOST_MPL_PREPROCESSED_HEADER

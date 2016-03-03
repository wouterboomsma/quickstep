
// Copyright Aleksey Gurtovoy 2001-2006
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

#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/stringize.hpp>

#   define AUX778076_HEADER \
    aux_/preprocessed/plain/QSBOOST_MPL_PREPROCESSED_HEADER \
/**/

#if QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(700))
#   define AUX778076_INCLUDE_STRING QSBOOST_PP_STRINGIZE(qsboost/mpl/list/AUX778076_HEADER)
#   include AUX778076_INCLUDE_STRING
#   undef AUX778076_INCLUDE_STRING
#else
#   include QSBOOST_PP_STRINGIZE(qsboost/mpl/list/AUX778076_HEADER)
#endif

#   undef AUX778076_HEADER

#undef QSBOOST_MPL_PREPROCESSED_HEADER
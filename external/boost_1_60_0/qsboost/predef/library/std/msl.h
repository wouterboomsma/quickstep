/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_MSL_H
#define QSBOOST_PREDEF_LIBRARY_STD_MSL_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_MSL`]

[@http://www.freescale.com/ Metrowerks] Standard C++ Library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__MSL_CPP__`] [__predef_detection__]]
    [[`__MSL__`] [__predef_detection__]]

    [[`__MSL_CPP__`] [V.R.P]]
    [[`__MSL__`] [V.R.P]]
    ]
 */

#define QSBOOST_LIB_STD_MSL QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__MSL_CPP__) || defined(__MSL__)
#   undef QSBOOST_LIB_STD_MSL
#   if defined(__MSL_CPP__)
#       define QSBOOST_LIB_STD_MSL QSBOOST_PREDEF_MAKE_0X_VRPP(__MSL_CPP__)
#   else
#       define QSBOOST_LIB_STD_MSL QSBOOST_PREDEF_MAKE_0X_VRPP(__MSL__)
#   endif
#endif

#if QSBOOST_LIB_STD_MSL
#   define QSBOOST_LIB_STD_MSL_AVAILABLE
#endif

#define QSBOOST_LIB_STD_MSL_NAME "Metrowerks"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_MSL,QSBOOST_LIB_STD_MSL_NAME)

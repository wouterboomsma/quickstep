/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_DIAB_H
#define QSBOOST_PREDEF_COMPILER_DIAB_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_DIAB`]

[@http://www.windriver.com/products/development_suite/wind_river_compiler/ Diab C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DCC__`] [__predef_detection__]]

    [[`__VERSION_NUMBER__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_DIAB QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DCC__)
#   define QSBOOST_COMP_DIAB_DETECTION QSBOOST_PREDEF_MAKE_10_VRPP(__VERSION_NUMBER__)
#endif

#ifdef QSBOOST_COMP_DIAB_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_DIAB_EMULATED QSBOOST_COMP_DIAB_DETECTION
#   else
#       undef QSBOOST_COMP_DIAB
#       define QSBOOST_COMP_DIAB QSBOOST_COMP_DIAB_DETECTION
#   endif
#   define QSBOOST_COMP_DIAB_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_DIAB_NAME "Diab C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DIAB,QSBOOST_COMP_DIAB_NAME)

#ifdef QSBOOST_COMP_DIAB_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DIAB_EMULATED,QSBOOST_COMP_DIAB_NAME)
#endif

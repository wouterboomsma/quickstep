/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_KAI_H
#define QSBOOST_PREDEF_COMPILER_KAI_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_KCC`]

Kai C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__KCC`] [__predef_detection__]]

    [[`__KCC_VERSION`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_KCC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__KCC)
#   define QSBOOST_COMP_KCC_DETECTION QSBOOST_PREDEF_MAKE_0X_VRPP(__KCC_VERSION)
#endif

#ifdef QSBOOST_COMP_KCC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_KCC_EMULATED QSBOOST_COMP_KCC_DETECTION
#   else
#       undef QSBOOST_COMP_KCC
#       define QSBOOST_COMP_KCC QSBOOST_COMP_KCC_DETECTION
#   endif
#   define QSBOOST_COMP_KCC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_KCC_NAME "Kai C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_KCC,QSBOOST_COMP_KCC_NAME)

#ifdef QSBOOST_COMP_KCC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_KCC_EMULATED,QSBOOST_COMP_KCC_NAME)
#endif

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_CLANG_H
#define QSBOOST_PREDEF_COMPILER_CLANG_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_CLANG`]

[@http://en.wikipedia.org/wiki/Clang Clang] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__clang__`] [__predef_detection__]]

    [[`__clang_major__`, `__clang_minor__`, `__clang_patchlevel__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_CLANG QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__clang__)
#   define QSBOOST_COMP_CLANG_DETECTION QSBOOST_VERSION_NUMBER(__clang_major__,__clang_minor__,__clang_patchlevel__)
#endif

#ifdef QSBOOST_COMP_CLANG_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_CLANG_EMULATED QSBOOST_COMP_CLANG_DETECTION
#   else
#       undef QSBOOST_COMP_CLANG
#       define QSBOOST_COMP_CLANG QSBOOST_COMP_CLANG_DETECTION
#   endif
#   define QSBOOST_COMP_CLANG_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_CLANG_NAME "Clang"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_CLANG,QSBOOST_COMP_CLANG_NAME)

#ifdef QSBOOST_COMP_CLANG_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_CLANG_EMULATED,QSBOOST_COMP_CLANG_NAME)
#endif

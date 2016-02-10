/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_GCC_H
#define QSBOOST_PREDEF_COMPILER_GCC_H

/* Other compilers that emulate this one need to be detected first. */

#include <qsboost/predef/compiler/clang.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_GNUC`]

[@http://en.wikipedia.org/wiki/GNU_Compiler_Collection Gnu GCC C/C++] compiler.
Version number available as major, minor, and patch (if available).

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__GNUC__`] [__predef_detection__]]

    [[`__GNUC__`, `__GNUC_MINOR__`, `__GNUC_PATCHLEVEL__`] [V.R.P]]
    [[`__GNUC__`, `__GNUC_MINOR__`] [V.R.0]]
    ]
 */

#define QSBOOST_COMP_GNUC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GNUC__)
#   if !defined(QSBOOST_COMP_GNUC_DETECTION) && defined(__GNUC_PATCHLEVEL__)
#       define QSBOOST_COMP_GNUC_DETECTION \
            QSBOOST_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
#   endif
#   if !defined(QSBOOST_COMP_GNUC_DETECTION)
#       define QSBOOST_COMP_GNUC_DETECTION \
            QSBOOST_VERSION_NUMBER(__GNUC__,__GNUC_MINOR__,0)
#   endif
#endif

#ifdef QSBOOST_COMP_GNUC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_GNUC_EMULATED QSBOOST_COMP_GNUC_DETECTION
#   else
#       undef QSBOOST_COMP_GNUC
#       define QSBOOST_COMP_GNUC QSBOOST_COMP_GNUC_DETECTION
#   endif
#   define QSBOOST_COMP_GNUC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_GNUC_NAME "Gnu GCC C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GNUC,QSBOOST_COMP_GNUC_NAME)

#ifdef QSBOOST_COMP_GNUC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GNUC_EMULATED,QSBOOST_COMP_GNUC_NAME)
#endif

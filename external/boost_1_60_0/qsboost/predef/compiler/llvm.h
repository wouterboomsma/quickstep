/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_LLVM_H
#define QSBOOST_PREDEF_COMPILER_LLVM_H

/* Other compilers that emulate this one need to be detected first. */

#include <qsboost/predef/compiler/clang.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_LLVM`]

[@http://en.wikipedia.org/wiki/LLVM LLVM] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__llvm__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_COMP_LLVM QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__llvm__)
#   define QSBOOST_COMP_LLVM_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#ifdef QSBOOST_COMP_LLVM_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_LLVM_EMULATED QSBOOST_COMP_LLVM_DETECTION
#   else
#       undef QSBOOST_COMP_LLVM
#       define QSBOOST_COMP_LLVM QSBOOST_COMP_LLVM_DETECTION
#   endif
#   define QSBOOST_COMP_LLVM_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_LLVM_NAME "LLVM"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_LLVM,QSBOOST_COMP_LLVM_NAME)

#ifdef QSBOOST_COMP_LLVM_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_LLVM_EMULATED,QSBOOST_COMP_LLVM_NAME)
#endif

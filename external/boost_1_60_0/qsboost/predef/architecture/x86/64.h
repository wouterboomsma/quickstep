/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_X86_64_H
#define QSBOOST_PREDEF_ARCHITECTURE_X86_64_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_X86_64`]

[@http://en.wikipedia.org/wiki/Ia64 Intel IA-64] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__x86_64`] [__predef_detection__]]
    [[`__x86_64__`] [__predef_detection__]]
    [[`__amd64__`] [__predef_detection__]]
    [[`__amd64`] [__predef_detection__]]
    [[`_M_X64`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_X86_64 QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__x86_64) || defined(__x86_64__) || \
    defined(__amd64__) || defined(__amd64) || \
    defined(_M_X64)
#   undef QSBOOST_ARCH_X86_64
#   define QSBOOST_ARCH_X86_64 QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_X86_64
#   define QSBOOST_ARCH_X86_64_AVAILABLE
#endif

#define QSBOOST_ARCH_X86_64_NAME "Intel x86-64"

#include <qsboost/predef/architecture/x86.h>

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_X86_64,QSBOOST_ARCH_X86_64_NAME)

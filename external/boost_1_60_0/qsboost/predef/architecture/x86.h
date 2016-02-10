/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <qsboost/predef/architecture/x86/32.h>
#include <qsboost/predef/architecture/x86/64.h>

#ifndef QSBOOST_PREDEF_ARCHITECTURE_X86_H
#define QSBOOST_PREDEF_ARCHITECTURE_X86_H

/*`
[heading `BOOST_ARCH_X86`]

[@http://en.wikipedia.org/wiki/X86 Intel x86] architecture. This is
a category to indicate that either `BOOST_ARCH_X86_32` or
`BOOST_ARCH_X86_64` is detected.
 */

#define QSBOOST_ARCH_X86 QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if QSBOOST_ARCH_X86_32 || QSBOOST_ARCH_X86_64
#   undef QSBOOST_ARCH_X86
#   define QSBOOST_ARCH_X86 QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_X86
#   define QSBOOST_ARCH_X86_AVAILABLE
#endif

#define QSBOOST_ARCH_X86_NAME "Intel x86"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_X86,QSBOOST_ARCH_X86_NAME)

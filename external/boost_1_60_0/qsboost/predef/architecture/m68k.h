/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_M68K_H
#define QSBOOST_PREDEF_ARCHITECTURE_M68K_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_M68K`]

[@http://en.wikipedia.org/wiki/M68k Motorola 68k] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__m68k__`] [__predef_detection__]]
    [[`M68000`] [__predef_detection__]]

    [[`__mc68060__`] [6.0.0]]
    [[`mc68060`] [6.0.0]]
    [[`__mc68060`] [6.0.0]]
    [[`__mc68040__`] [4.0.0]]
    [[`mc68040`] [4.0.0]]
    [[`__mc68040`] [4.0.0]]
    [[`__mc68030__`] [3.0.0]]
    [[`mc68030`] [3.0.0]]
    [[`__mc68030`] [3.0.0]]
    [[`__mc68020__`] [2.0.0]]
    [[`mc68020`] [2.0.0]]
    [[`__mc68020`] [2.0.0]]
    [[`__mc68010__`] [1.0.0]]
    [[`mc68010`] [1.0.0]]
    [[`__mc68010`] [1.0.0]]
    [[`__mc68000__`] [0.0.1]]
    [[`mc68000`] [0.0.1]]
    [[`__mc68000`] [0.0.1]]
    ]
 */

#define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__m68k__) || defined(M68000)
#   undef QSBOOST_ARCH_M68K
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68060__) || defined(mc68060) || defined(__mc68060))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER(6,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68040__) || defined(mc68040) || defined(__mc68040))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68030__) || defined(mc68030) || defined(__mc68030))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68020__) || defined(mc68020) || defined(__mc68020))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER(2,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68010__) || defined(mc68010) || defined(__mc68010))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER(1,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_M68K) && (defined(__mc68000__) || defined(mc68000) || defined(__mc68000))
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#   if !defined(QSBOOST_ARCH_M68K)
#       define QSBOOST_ARCH_M68K QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_ARCH_M68K
#   define QSBOOST_ARCH_M68K_AVAILABLE
#endif

#define QSBOOST_ARCH_M68K_NAME "Motorola 68k"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_M68K,QSBOOST_ARCH_M68K_NAME)

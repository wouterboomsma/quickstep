/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_SPARC_H
#define QSBOOST_PREDEF_ARCHITECTURE_SPARC_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_SPARC`]

[@http://en.wikipedia.org/wiki/SPARC SPARC] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sparc__`] [__predef_detection__]]
    [[`__sparc`] [__predef_detection__]]

    [[`__sparcv9`] [9.0.0]]
    [[`__sparcv8`] [8.0.0]]
    ]
 */

#define QSBOOST_ARCH_SPARC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sparc__) || defined(__sparc)
#   undef QSBOOST_ARCH_SPARC
#   if !defined(QSBOOST_ARCH_SPARC) && defined(__sparcv9)
#       define QSBOOST_ARCH_SPARC QSBOOST_VERSION_NUMBER(9,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_SPARC) && defined(__sparcv8)
#       define QSBOOST_ARCH_SPARC QSBOOST_VERSION_NUMBER(8,0,0)
#   endif
#   if !defined(QSBOOST_ARCH_SPARC)
#       define QSBOOST_ARCH_SPARC QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_ARCH_SPARC
#   define QSBOOST_ARCH_SPARC_AVAILABLE
#endif

#define QSBOOST_ARCH_SPARC_NAME "SPARC"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_SPARC,QSBOOST_ARCH_SPARC_NAME)

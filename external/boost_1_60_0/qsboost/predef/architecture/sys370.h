/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_SYS370_H
#define QSBOOST_PREDEF_ARCHITECTURE_SYS370_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_SYS370`]

[@http://en.wikipedia.org/wiki/System/370 System/370] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__370__`] [__predef_detection__]]
    [[`__THW_370__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_SYS370 QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__370__) || defined(__THW_370__)
#   undef QSBOOST_ARCH_SYS370
#   define QSBOOST_ARCH_SYS370 QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_SYS370
#   define QSBOOST_ARCH_SYS370_AVAILABLE
#endif

#define QSBOOST_ARCH_SYS370_NAME "System/370"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_SYS370,QSBOOST_ARCH_SYS370_NAME)

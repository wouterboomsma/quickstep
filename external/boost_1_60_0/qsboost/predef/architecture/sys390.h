/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_SYS390_H
#define QSBOOST_PREDEF_ARCHITECTURE_SYS390_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_SYS390`]

[@http://en.wikipedia.org/wiki/System/390 System/390] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__s390__`] [__predef_detection__]]
    [[`__s390x__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_SYS390 QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__s390__) || defined(__s390x__)
#   undef QSBOOST_ARCH_SYS390
#   define QSBOOST_ARCH_SYS390 QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_SYS390
#   define QSBOOST_ARCH_SYS390_AVAILABLE
#endif

#define QSBOOST_ARCH_SYS390_NAME "System/390"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_SYS390,QSBOOST_ARCH_SYS390_NAME)

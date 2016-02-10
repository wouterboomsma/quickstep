/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_Z_H
#define QSBOOST_PREDEF_ARCHITECTURE_Z_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_Z`]

[@http://en.wikipedia.org/wiki/Z/Architecture z/Architecture] architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SYSC_ZARCH__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_Z QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC_ZARCH__)
#   undef QSBOOST_ARCH_Z
#   define QSBOOST_ARCH_Z QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_Z
#   define QSBOOST_ARCH_Z_AVAILABLE
#endif

#define QSBOOST_ARCH_Z_NAME "z/Architecture"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_Z,QSBOOST_ARCH_Z_NAME)

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_LINUX_H
#define QSBOOST_PREDEF_OS_LINUX_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_LINUX`]

[@http://en.wikipedia.org/wiki/Linux Linux] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`linux`] [__predef_detection__]]
    [[`__linux`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_LINUX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(linux) || defined(__linux) \
    )
#   undef QSBOOST_OS_LINUX
#   define QSBOOST_OS_LINUX QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_LINUX
#   define QSBOOST_OS_LINUX_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_LINUX_NAME "Linux"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_LINUX,QSBOOST_OS_LINUX_NAME)

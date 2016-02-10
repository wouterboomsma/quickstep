/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_IRIX_H
#define QSBOOST_PREDEF_OS_IRIX_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_IRIX`]

[@http://en.wikipedia.org/wiki/Irix IRIX] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`sgi`] [__predef_detection__]]
    [[`__sgi`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_IRIX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(sgi) || defined(__sgi) \
    )
#   undef QSBOOST_OS_IRIX
#   define QSBOOST_OS_IRIX QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_IRIX
#   define QSBOOST_OS_IRIX_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_IRIX_NAME "IRIX"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_IRIX,QSBOOST_OS_IRIX_NAME)

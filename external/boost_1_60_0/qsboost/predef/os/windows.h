/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_WINDOWS_H
#define QSBOOST_PREDEF_OS_WINDOWS_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_WINDOWS`]

[@http://en.wikipedia.org/wiki/Category:Microsoft_Windows Microsoft Windows] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_WIN32`] [__predef_detection__]]
    [[`_WIN64`] [__predef_detection__]]
    [[`__WIN32__`] [__predef_detection__]]
    [[`__TOS_WIN__`] [__predef_detection__]]
    [[`__WINDOWS__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_WINDOWS QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || \
    defined(__WINDOWS__) \
    )
#   undef QSBOOST_OS_WINDOWS
#   define QSBOOST_OS_WINDOWS QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_WINDOWS
#   define QSBOOST_OS_WINDOWS_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_WINDOWS_NAME "Microsoft Windows"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_WINDOWS,QSBOOST_OS_WINDOWS_NAME)

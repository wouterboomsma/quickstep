/*
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_ADROID_H
#define QSBOOST_PREDEF_OS_ADROID_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_ANDROID`]

[@http://en.wikipedia.org/wiki/Android_%28operating_system%29 Android] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ANDROID__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_ANDROID QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__ANDROID__) \
    )
#   undef QSBOOST_OS_ANDROID
#   define QSBOOST_OS_ANDROID QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_ANDROID
#   define QSBOOST_OS_ANDROID_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_ANDROID_NAME "Android"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_ANDROID,QSBOOST_OS_ANDROID_NAME)

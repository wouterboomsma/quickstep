/*
Copyright Jessica Hamilton 2014
Copyright Rene Rivera 2014-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_HAIKU_H
#define QSBOOST_PREDEF_OS_HAIKU_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_HAIKU`]

[@http://en.wikipedia.org/wiki/Haiku_(operating_system) Haiku] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__HAIKU__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_HAIKU QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__HAIKU__) \
    )
#   undef QSBOOST_OS_HAIKU
#   define QSBOOST_OS_HAIKU QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_HAIKU
#   define QSBOOST_OS_HAIKU_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_HAIKU_NAME "Haiku"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_HAIKU,QSBOOST_OS_HAIKU_NAME)

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_HPUX_H
#define QSBOOST_PREDEF_OS_HPUX_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_HPUX`]

[@http://en.wikipedia.org/wiki/HP-UX HP-UX] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`hpux`] [__predef_detection__]]
    [[`_hpux`] [__predef_detection__]]
    [[`__hpux`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_HPUX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(hpux) || defined(_hpux) || defined(__hpux) \
    )
#   undef QSBOOST_OS_HPUX
#   define QSBOOST_OS_HPUX QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_OS_HPUX
#   define QSBOOST_OS_HPUX_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_HPUX_NAME "HP-UX"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_HPUX,QSBOOST_OS_HPUX_NAME)

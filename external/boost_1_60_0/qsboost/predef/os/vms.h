/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_VMS_H
#define QSBOOST_PREDEF_OS_VMS_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_VMS`]

[@http://en.wikipedia.org/wiki/Vms VMS] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`VMS`] [__predef_detection__]]
    [[`__VMS`] [__predef_detection__]]

    [[`__VMS_VER`] [V.R.P]]
    ]
 */

#define QSBOOST_OS_VMS QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(VMS) || defined(__VMS) \
    )
#   undef QSBOOST_OS_VMS
#   if defined(__VMS_VER)
#       define QSBOOST_OS_VMS QSBOOST_PREDEF_MAKE_10_VVRR00PP00(__VMS_VER)
#   else
#       define QSBOOST_OS_VMS QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_OS_VMS
#   define QSBOOST_OS_VMS_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_VMS_NAME "VMS"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_VMS,QSBOOST_OS_VMS_NAME)

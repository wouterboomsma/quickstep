/*
Copyright (c) Microsoft Corporation 2014
Copyright Rene Rivera 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_PLAT_WINDOWS_DESKTOP_H
#define QSBOOST_PREDEF_PLAT_WINDOWS_DESKTOP_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>
#include <qsboost/predef/os/windows.h>

/*`
[heading `BOOST_PLAT_WINDOWS_DESKTOP`]

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`!WINAPI_FAMILY`] [__predef_detection__]]
    [[`WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP`] [__predef_detection__]]
    ]
 */

#define QSBOOST_PLAT_WINDOWS_DESKTOP QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if QSBOOST_OS_WINDOWS && \
    ( !defined(WINAPI_FAMILY) || (WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP) )
#   undef QSBOOST_PLAT_WINDOWS_DESKTOP
#   define QSBOOST_PLAT_WINDOWS_DESKTOP QSBOOST_VERSION_NUMBER_AVAILABLE
#endif
 
#if QSBOOST_PLAT_WINDOWS_DESKTOP
#   define QSBOOST_PLAT_WINDOWS_DESKTOP_AVAILABLE
#   include <qsboost/predef/detail/platform_detected.h>
#endif

#define QSBOOST_PLAT_WINDOWS_DESKTOP_NAME "Windows Desktop"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_PLAT_WINDOWS_DESKTOP,QSBOOST_PLAT_WINDOWS_DESKTOP_NAME)

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_AIX_H
#define QSBOOST_PREDEF_OS_AIX_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_AIX`]

[@http://en.wikipedia.org/wiki/AIX_operating_system IBM AIX] operating system.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_AIX`] [__predef_detection__]]
    [[`__TOS_AIX__`] [__predef_detection__]]

    [[`_AIX43`] [4.3.0]]
    [[`_AIX41`] [4.1.0]]
    [[`_AIX32`] [3.2.0]]
    [[`_AIX3`] [3.0.0]]
    ]
 */

#define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(_AIX) || defined(__TOS_AIX__) \
    )
#   undef QSBOOST_OS_AIX
#   if !defined(QSBOOST_OS_AIX) && defined(_AIX43)
#       define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER(4,3,0)
#   endif
#   if !defined(QSBOOST_OS_AIX) && defined(_AIX41)
#       define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER(4,1,0)
#   endif
#   if !defined(QSBOOST_OS_AIX) && defined(_AIX32)
#       define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER(3,2,0)
#   endif
#   if !defined(QSBOOST_OS_AIX) && defined(_AIX3)
#       define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(QSBOOST_OS_AIX)
#       define QSBOOST_OS_AIX QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_OS_AIX
#   define QSBOOST_OS_AIX_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_AIX_NAME "IBM AIX"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_AIX,QSBOOST_OS_AIX_NAME)

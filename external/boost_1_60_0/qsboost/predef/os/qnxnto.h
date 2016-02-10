/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_QNXNTO_H
#define QSBOOST_PREDEF_OS_QNXNTO_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_OS_QNX`]

[@http://en.wikipedia.org/wiki/QNX QNX] operating system.
Version number available as major, and minor if possible. And
version 4 is specifically detected.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__QNX__`] [__predef_detection__]]
    [[`__QNXNTO__`] [__predef_detection__]]

    [[`_NTO_VERSION`] [V.R.0]]
    [[`__QNX__`] [4.0.0]]
    ]
 */

#define QSBOOST_OS_QNX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__QNX__) || defined(__QNXNTO__) \
    )
#   undef QSBOOST_OS_QNX
#   if !defined(QSBOOST_OS_QNX) && defined(_NTO_VERSION)
#       define QSBOOST_OS_QNX QSBOOST_PREDEF_MAKE_10_VVRR(_NTO_VERSION)
#   endif
#   if !defined(QSBOOST_OS_QNX) && defined(__QNX__)
#       define QSBOOST_OS_QNX QSBOOST_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(QSBOOST_OS_QNX)
#       define QSBOOST_OS_QNX QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_OS_QNX
#   define QSBOOST_OS_QNX_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_QNX_NAME "QNX"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_QNX,QSBOOST_OS_QNX_NAME)

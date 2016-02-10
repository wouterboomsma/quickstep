/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_BSD_FREE_H
#define QSBOOST_PREDEF_OS_BSD_FREE_H

#include <qsboost/predef/os/bsd.h>

/*`
[heading `BOOST_OS_BSD_FREE`]

[@http://en.wikipedia.org/wiki/Freebsd FreeBSD] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__FreeBSD__`] [__predef_detection__]]

    [[`__FreeBSD_version`] [V.R.P]]
    ]
 */

#define QSBOOST_OS_BSD_FREE QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__FreeBSD__) \
    )
#   ifndef QSBOOST_OS_BSD_AVAILABLE
#       define QSBOOST_OS_BSD QSBOOST_VERSION_NUMBER_AVAILABLE
#       define QSBOOST_OS_BSD_AVAILABLE
#   endif
#   undef QSBOOST_OS_BSD_FREE
#   if defined(__FreeBSD_version)
#       if __FreeBSD_version < 500000
#           define QSBOOST_OS_BSD_FREE \
                QSBOOST_PREDEF_MAKE_10_VRP000(__FreeBSD_version)
#       else
#           define QSBOOST_OS_BSD_FREE \
                QSBOOST_PREDEF_MAKE_10_VRR000(__FreeBSD_version)
#       endif
#   else
#       define QSBOOST_OS_BSD_FREE QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_OS_BSD_FREE
#   define QSBOOST_OS_BSD_FREE_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_BSD_FREE_NAME "Free BSD"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_BSD_FREE,QSBOOST_OS_BSD_FREE_NAME)

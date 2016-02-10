/*
Copyright Rene Rivera 2012-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_OS_BSD_DRAGONFLY_H
#define QSBOOST_PREDEF_OS_BSD_DRAGONFLY_H

#include <qsboost/predef/os/bsd.h>

/*`
[heading `BOOST_OS_BSD_DRAGONFLY`]

[@http://en.wikipedia.org/wiki/DragonFly_BSD DragonFly BSD] operating system.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DragonFly__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_OS_BSD_DRAGONFLY QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(QSBOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
    defined(__DragonFly__) \
    )
#   ifndef QSBOOST_OS_BSD_AVAILABLE
#       define QSBOOST_OS_BSD QSBOOST_VERSION_NUMBER_AVAILABLE
#       define QSBOOST_OS_BSD_AVAILABLE
#   endif
#   undef QSBOOST_OS_BSD_DRAGONFLY
#   if defined(__DragonFly__)
#       define QSBOOST_OS_DRAGONFLY_BSD QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_OS_BSD_DRAGONFLY
#   define QSBOOST_OS_BSD_DRAGONFLY_AVAILABLE
#   include <qsboost/predef/detail/os_detected.h>
#endif

#define QSBOOST_OS_BSD_DRAGONFLY_NAME "DragonFly BSD"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_OS_BSD_DRAGONFLY,QSBOOST_OS_BSD_DRAGONFLY_NAME)

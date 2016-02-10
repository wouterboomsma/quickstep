/*
Copyright Rene Rivera 2013-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_BLACKFIN_H
#define QSBOOST_PREDEF_ARCHITECTURE_BLACKFIN_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_BLACKFIN`]

Blackfin Processors from Analog Devices.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__bfin__`] [__predef_detection__]]
    [[`__BFIN__`] [__predef_detection__]]
    [[`bfin`] [__predef_detection__]]
    [[`BFIN`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_BLACKFIN QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__bfin__) || defined(__BFIN__) || \
    defined(bfin) || defined(BFIN)
#   undef QSBOOST_ARCH_BLACKFIN
#   define QSBOOST_ARCH_BLACKFIN QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_BLACKFIN
#   define QSBOOST_ARCH_BLACKFIN_AVAILABLE
#endif

#define QSBOOST_ARCH_BLACKFIN_NAME "Blackfin"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_BLACKFIN,QSBOOST_ARCH_BLACKFIN_NAME)

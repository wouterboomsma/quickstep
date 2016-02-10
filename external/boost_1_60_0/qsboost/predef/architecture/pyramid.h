/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_ARCHITECTURE_PYRAMID_H
#define QSBOOST_PREDEF_ARCHITECTURE_PYRAMID_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_ARCH_PYRAMID`]

Pyramid 9810 architecture.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`pyr`] [__predef_detection__]]
    ]
 */

#define QSBOOST_ARCH_PYRAMID QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(pyr)
#   undef QSBOOST_ARCH_PYRAMID
#   define QSBOOST_ARCH_PYRAMID QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_ARCH_PYRAMID
#   define QSBOOST_ARCH_PYRAMID_AVAILABLE
#endif

#define QSBOOST_ARCH_PYRAMID_NAME "Pyramid 9810"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_ARCH_PYRAMID,QSBOOST_ARCH_PYRAMID_NAME)

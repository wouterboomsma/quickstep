/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LANGUAGE_OBJC_H
#define QSBOOST_PREDEF_LANGUAGE_OBJC_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LANG_OBJC`]

[@http://en.wikipedia.org/wiki/Objective-C Objective-C] language.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__OBJC__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_LANG_OBJC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__OBJC__)
#   undef QSBOOST_LANG_OBJC
#   define QSBOOST_LANG_OBJC QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_LANG_OBJC
#   define QSBOOST_LANG_OBJC_AVAILABLE
#endif

#define QSBOOST_LANG_OBJC_NAME "Objective-C"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LANG_OBJC,QSBOOST_LANG_OBJC_NAME)

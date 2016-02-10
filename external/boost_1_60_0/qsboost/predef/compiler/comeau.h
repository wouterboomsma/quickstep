/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_COMEAU_H
#define QSBOOST_PREDEF_COMPILER_COMEAU_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

#define QSBOOST_COMP_COMO QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

/*`
[heading `BOOST_COMP_COMO`]

[@http://en.wikipedia.org/wiki/Comeau_C/C%2B%2B Comeau C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__COMO__`] [__predef_detection__]]

    [[`__COMO_VERSION__`] [V.R.P]]
    ]
 */

#if defined(__COMO__)
#   if !defined(QSBOOST_COMP_COMO_DETECTION) && defined(__COMO_VERSION__)
#       define QSBOOST_COMP_COMO_DETECTION QSBOOST_PREDEF_MAKE_0X_VRP(__COMO_VERSION__)
#   endif
#   if !defined(QSBOOST_COMP_COMO_DETECTION)
#       define QSBOOST_COMP_COMO_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_COMO_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_COMO_EMULATED QSBOOST_COMP_COMO_DETECTION
#   else
#       undef QSBOOST_COMP_COMO
#       define QSBOOST_COMP_COMO QSBOOST_COMP_COMO_DETECTION
#   endif
#   define QSBOOST_COMP_COMO_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_COMO_NAME "Comeau C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_COMO,QSBOOST_COMP_COMO_NAME)

#ifdef QSBOOST_COMP_COMO_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_COMO_EMULATED,QSBOOST_COMP_COMO_NAME)
#endif

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_EDG_H
#define QSBOOST_PREDEF_COMPILER_EDG_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_EDG`]

[@http://en.wikipedia.org/wiki/Edison_Design_Group EDG C++ Frontend] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__EDG__`] [__predef_detection__]]

    [[`__EDG_VERSION__`] [V.R.0]]
    ]
 */

#define QSBOOST_COMP_EDG QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__EDG__)
#   define QSBOOST_COMP_EDG_DETECTION QSBOOST_PREDEF_MAKE_10_VRR(__EDG_VERSION__)
#endif

#ifdef QSBOOST_COMP_EDG_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_EDG_EMULATED QSBOOST_COMP_EDG_DETECTION
#   else
#       undef QSBOOST_COMP_EDG
#       define QSBOOST_COMP_EDG QSBOOST_COMP_EDG_DETECTION
#   endif
#   define QSBOOST_COMP_EDG_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_EDG_NAME "EDG C++ Frontend"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_EDG,QSBOOST_COMP_EDG_NAME)

#ifdef QSBOOST_COMP_EDG_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_EDG_EMULATED,QSBOOST_COMP_EDG_NAME)
#endif

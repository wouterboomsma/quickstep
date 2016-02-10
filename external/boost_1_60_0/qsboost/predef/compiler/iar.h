/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_IAR_H
#define QSBOOST_PREDEF_COMPILER_IAR_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_IAR`]

IAR C/C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IAR_SYSTEMS_ICC__`] [__predef_detection__]]

    [[`__VER__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_IAR QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IAR_SYSTEMS_ICC__)
#   define QSBOOST_COMP_IAR_DETECTION QSBOOST_PREDEF_MAKE_10_VVRR(__VER__)
#endif

#ifdef QSBOOST_COMP_IAR_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_IAR_EMULATED QSBOOST_COMP_IAR_DETECTION
#   else
#       undef QSBOOST_COMP_IAR
#       define QSBOOST_COMP_IAR QSBOOST_COMP_IAR_DETECTION
#   endif
#   define QSBOOST_COMP_IAR_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_IAR_NAME "IAR C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_IAR,QSBOOST_COMP_IAR_NAME)

#ifdef QSBOOST_COMP_IAR_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_IAR_EMULATED,QSBOOST_COMP_IAR_NAME)
#endif

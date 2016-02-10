/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_PALM_H
#define QSBOOST_PREDEF_COMPILER_PALM_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_PALM`]

Palm C/C++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_PACC_VER`] [__predef_detection__]]

    [[`_PACC_VER`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_PALM QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_PACC_VER)
#   define QSBOOST_COMP_PALM_DETECTION QSBOOST_PREDEF_MAKE_0X_VRRPP000(_PACC_VER)
#endif

#ifdef QSBOOST_COMP_PALM_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_PALM_EMULATED QSBOOST_COMP_PALM_DETECTION
#   else
#       undef QSBOOST_COMP_PALM
#       define QSBOOST_COMP_PALM QSBOOST_COMP_PALM_DETECTION
#   endif
#   define QSBOOST_COMP_PALM_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_PALM_NAME "Palm C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PALM,QSBOOST_COMP_PALM_NAME)

#ifdef QSBOOST_COMP_PALM_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PALM_EMULATED,QSBOOST_COMP_PALM_NAME)
#endif

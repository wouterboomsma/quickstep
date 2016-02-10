/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_WATCOM_H
#define QSBOOST_PREDEF_COMPILER_WATCOM_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_WATCOM`]

[@http://en.wikipedia.org/wiki/Watcom Watcom C++] compiler.
Version number available as major, and minor.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__WATCOMC__`] [__predef_detection__]]

    [[`__WATCOMC__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_WATCOM QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__WATCOMC__)
#   define QSBOOST_COMP_WATCOM_DETECTION QSBOOST_PREDEF_MAKE_10_VVRR(__WATCOMC__)
#endif

#ifdef QSBOOST_COMP_WATCOM_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_WATCOM_EMULATED QSBOOST_COMP_WATCOM_DETECTION
#   else
#       undef QSBOOST_COMP_WATCOM
#       define QSBOOST_COMP_WATCOM QSBOOST_COMP_WATCOM_DETECTION
#   endif
#   define QSBOOST_COMP_WATCOM_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_WATCOM_NAME "Watcom C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_WATCOM,QSBOOST_COMP_WATCOM_NAME)

#ifdef QSBOOST_COMP_WATCOM_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_WATCOM_EMULATED,QSBOOST_COMP_WATCOM_NAME)
#endif

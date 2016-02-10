/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_GREENHILLS_H
#define QSBOOST_PREDEF_COMPILER_GREENHILLS_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_GHS`]

[@http://en.wikipedia.org/wiki/Green_Hills_Software Green Hills C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__ghs`] [__predef_detection__]]
    [[`__ghs__`] [__predef_detection__]]

    [[`__GHS_VERSION_NUMBER__`] [V.R.P]]
    [[`__ghs`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_GHS QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__ghs) || defined(__ghs__)
#   if !defined(QSBOOST_COMP_GHS_DETECTION) && defined(__GHS_VERSION_NUMBER__)
#       define QSBOOST_COMP_GHS_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(__GHS_VERSION_NUMBER__)
#   endif
#   if !defined(QSBOOST_COMP_GHS_DETECTION) && defined(__ghs)
#       define QSBOOST_COMP_GHS_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(__ghs)
#   endif
#   if !defined(QSBOOST_COMP_GHS_DETECTION)
#       define QSBOOST_COMP_GHS_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_GHS_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_GHS_EMULATED QSBOOST_COMP_GHS_DETECTION
#   else
#       undef QSBOOST_COMP_GHS
#       define QSBOOST_COMP_GHS QSBOOST_COMP_GHS_DETECTION
#   endif
#   define QSBOOST_COMP_GHS_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_GHS_NAME "Green Hills C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GHS,QSBOOST_COMP_GHS_NAME)

#ifdef QSBOOST_COMP_GHS_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GHS_EMULATED,QSBOOST_COMP_GHS_NAME)
#endif

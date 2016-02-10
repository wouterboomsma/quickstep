/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_DIGITALMARS_H
#define QSBOOST_PREDEF_COMPILER_DIGITALMARS_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_DMC`]

[@http://en.wikipedia.org/wiki/Digital_Mars Digital Mars] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DMC__`] [__predef_detection__]]

    [[`__DMC__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_DMC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DMC__)
#   define QSBOOST_COMP_DMC_DETECTION QSBOOST_PREDEF_MAKE_0X_VRP(__DMC__)
#endif

#ifdef QSBOOST_COMP_DMC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_DMC_EMULATED QSBOOST_COMP_DMC_DETECTION
#   else
#       undef QSBOOST_COMP_DMC
#       define QSBOOST_COMP_DMC QSBOOST_COMP_DMC_DETECTION
#   endif
#   define QSBOOST_COMP_DMC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_DMC_NAME "Digital Mars"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DMC,QSBOOST_COMP_DMC_NAME)

#ifdef QSBOOST_COMP_DMC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DMC_EMULATED,QSBOOST_COMP_DMC_NAME)
#endif

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_SGI_MIPSPRO_H
#define QSBOOST_PREDEF_COMPILER_SGI_MIPSPRO_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_SGI`]

[@http://en.wikipedia.org/wiki/MIPSpro SGI MIPSpro] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__sgi`] [__predef_detection__]]
    [[`sgi`] [__predef_detection__]]

    [[`_SGI_COMPILER_VERSION`] [V.R.P]]
    [[`_COMPILER_VERSION`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_SGI QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__sgi) || defined(sgi)
#   if !defined(QSBOOST_COMP_SGI_DETECTION) && defined(_SGI_COMPILER_VERSION)
#       define QSBOOST_COMP_SGI_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(_SGI_COMPILER_VERSION)
#   endif
#   if !defined(QSBOOST_COMP_SGI_DETECTION) && defined(_COMPILER_VERSION)
#       define QSBOOST_COMP_SGI_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(_COMPILER_VERSION)
#   endif
#   if !defined(QSBOOST_COMP_SGI_DETECTION)
#       define QSBOOST_COMP_SGI_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_SGI_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_SGI_EMULATED QSBOOST_COMP_SGI_DETECTION
#   else
#       undef QSBOOST_COMP_SGI
#       define QSBOOST_COMP_SGI QSBOOST_COMP_SGI_DETECTION
#   endif
#   define QSBOOST_COMP_SGI_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_SGI_NAME "SGI MIPSpro"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SGI,QSBOOST_COMP_SGI_NAME)

#ifdef QSBOOST_COMP_SGI_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SGI_EMULATED,QSBOOST_COMP_SGI_NAME)
#endif

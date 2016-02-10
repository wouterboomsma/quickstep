/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_INTEL_H
#define QSBOOST_PREDEF_COMPILER_INTEL_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_INTEL`]

[@http://en.wikipedia.org/wiki/Intel_C%2B%2B Intel C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__INTEL_COMPILER`] [__predef_detection__]]
    [[`__ICL`] [__predef_detection__]]
    [[`__ICC`] [__predef_detection__]]
    [[`__ECC`] [__predef_detection__]]

    [[`__INTEL_COMPILER`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_INTEL QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || \
    defined(__ECC)
#   if !defined(QSBOOST_COMP_INTEL_DETECTION) && defined(__INTEL_COMPILER)
#       define QSBOOST_COMP_INTEL_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(__INTEL_COMPILER)
#   endif
#   if !defined(QSBOOST_COMP_INTEL_DETECTION)
#       define QSBOOST_COMP_INTEL_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_INTEL_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_INTEL_EMULATED QSBOOST_COMP_INTEL_DETECTION
#   else
#       undef QSBOOST_COMP_INTEL
#       define QSBOOST_COMP_INTEL QSBOOST_COMP_INTEL_DETECTION
#   endif
#   define QSBOOST_COMP_INTEL_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_INTEL_NAME "Intel C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_INTEL,QSBOOST_COMP_INTEL_NAME)

#ifdef QSBOOST_COMP_INTEL_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_INTEL_EMULATED,QSBOOST_COMP_INTEL_NAME)
#endif

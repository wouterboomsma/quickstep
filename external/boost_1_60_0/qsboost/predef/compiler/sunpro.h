/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_SUNPRO_H
#define QSBOOST_PREDEF_COMPILER_SUNPRO_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_SUNPRO`]

[@http://en.wikipedia.org/wiki/Oracle_Solaris_Studio Oracle Solaris Studio] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SUNPRO_CC`] [__predef_detection__]]
    [[`__SUNPRO_C`] [__predef_detection__]]

    [[`__SUNPRO_CC`] [V.R.P]]
    [[`__SUNPRO_C`] [V.R.P]]
    [[`__SUNPRO_CC`] [VV.RR.P]]
    [[`__SUNPRO_C`] [VV.RR.P]]
    ]
 */

#define QSBOOST_COMP_SUNPRO QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C)
#   if !defined(QSBOOST_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_CC)
#       if (__SUNPRO_CC < 0x5100)
#           define QSBOOST_COMP_SUNPRO_DETECTION QSBOOST_PREDEF_MAKE_0X_VRP(__SUNPRO_CC)
#       else
#           define QSBOOST_COMP_SUNPRO_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRRP(__SUNPRO_CC)
#       endif
#   endif
#   if !defined(QSBOOST_COMP_SUNPRO_DETECTION) && defined(__SUNPRO_C)
#       if (__SUNPRO_C < 0x5100)
#           define QSBOOST_COMP_SUNPRO_DETECTION QSBOOST_PREDEF_MAKE_0X_VRP(__SUNPRO_C)
#       else
#           define QSBOOST_COMP_SUNPRO_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRRP(__SUNPRO_C)
#       endif
#   endif
#   if !defined(QSBOOST_COMP_SUNPRO_DETECTION)
#       define QSBOOST_COMP_SUNPRO_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_SUNPRO_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_SUNPRO_EMULATED QSBOOST_COMP_SUNPRO_DETECTION
#   else
#       undef QSBOOST_COMP_SUNPRO
#       define QSBOOST_COMP_SUNPRO QSBOOST_COMP_SUNPRO_DETECTION
#   endif
#   define QSBOOST_COMP_SUNPRO_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_SUNPRO_NAME "Oracle Solaris Studio"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SUNPRO,QSBOOST_COMP_SUNPRO_NAME)

#ifdef QSBOOST_COMP_SUNPRO_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SUNPRO_EMULATED,QSBOOST_COMP_SUNPRO_NAME)
#endif

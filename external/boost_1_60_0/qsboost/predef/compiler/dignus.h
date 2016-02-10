/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_DIGNUS_H
#define QSBOOST_PREDEF_COMPILER_DIGNUS_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_SYSC`]

[@http://www.dignus.com/dcxx/ Dignus Systems/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SYSC__`] [__predef_detection__]]

    [[`__SYSC_VER__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_SYSC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SYSC__)
#   define QSBOOST_COMP_SYSC_DETECTION QSBOOST_PREDEF_MAKE_10_VRRPP(__SYSC_VER__)
#endif

#ifdef QSBOOST_COMP_SYSC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_SYSC_EMULATED QSBOOST_COMP_SYSC_DETECTION
#   else
#       undef QSBOOST_COMP_SYSC
#       define QSBOOST_COMP_SYSC QSBOOST_COMP_SYSC_DETECTION
#   endif
#   define QSBOOST_COMP_SYSC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_SYSC_NAME "Dignus Systems/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SYSC,QSBOOST_COMP_SYSC_NAME)

#ifdef QSBOOST_COMP_SYSC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_SYSC_EMULATED,QSBOOST_COMP_SYSC_NAME)
#endif

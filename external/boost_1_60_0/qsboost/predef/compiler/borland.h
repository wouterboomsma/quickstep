/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_BORLAND_H
#define QSBOOST_PREDEF_COMPILER_BORLAND_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_BORLAND`]

[@http://en.wikipedia.org/wiki/C_plus_plus_builder Borland C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__BORLANDC__`] [__predef_detection__]]
    [[`__CODEGEARC__`] [__predef_detection__]]

    [[`__BORLANDC__`] [V.R.P]]
    [[`__CODEGEARC__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_BORLAND QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
#   if !defined(QSBOOST_COMP_BORLAND_DETECTION) && (defined(__CODEGEARC__))
#       define QSBOOST_COMP_BORLAND_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRP(__CODEGEARC__)
#   endif
#   if !defined(QSBOOST_COMP_BORLAND_DETECTION)
#       define QSBOOST_COMP_BORLAND_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRP(__BORLANDC__)
#   endif
#endif

#ifdef QSBOOST_COMP_BORLAND_DETECTION
#   define QSBOOST_COMP_BORLAND_AVAILABLE
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_BORLAND_EMULATED QSBOOST_COMP_BORLAND_DETECTION
#   else
#       undef QSBOOST_COMP_BORLAND
#       define QSBOOST_COMP_BORLAND QSBOOST_COMP_BORLAND_DETECTION
#   endif
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_BORLAND_NAME "Borland C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_BORLAND,QSBOOST_COMP_BORLAND_NAME)

#ifdef QSBOOST_COMP_BORLAND_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_BORLAND_EMULATED,QSBOOST_COMP_BORLAND_NAME)
#endif

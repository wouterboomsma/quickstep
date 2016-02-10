/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_TENDRA_H
#define QSBOOST_PREDEF_COMPILER_TENDRA_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_TENDRA`]

[@http://en.wikipedia.org/wiki/TenDRA_Compiler TenDRA C/C++] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__TenDRA__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_COMP_TENDRA QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__TenDRA__)
#   define QSBOOST_COMP_TENDRA_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#ifdef QSBOOST_COMP_TENDRA_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_TENDRA_EMULATED QSBOOST_COMP_TENDRA_DETECTION
#   else
#       undef QSBOOST_COMP_TENDRA
#       define QSBOOST_COMP_TENDRA QSBOOST_COMP_TENDRA_DETECTION
#   endif
#   define QSBOOST_COMP_TENDRA_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_TENDRA_NAME "TenDRA C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_TENDRA,QSBOOST_COMP_TENDRA_NAME)

#ifdef QSBOOST_COMP_TENDRA_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_TENDRA_EMULATED,QSBOOST_COMP_TENDRA_NAME)
#endif

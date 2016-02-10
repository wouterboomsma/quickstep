/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_PGI_H
#define QSBOOST_PREDEF_COMPILER_PGI_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_PGI`]

[@http://en.wikipedia.org/wiki/The_Portland_Group Portland Group C/C++] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__PGI`] [__predef_detection__]]

    [[`__PGIC__`, `__PGIC_MINOR__`, `__PGIC_PATCHLEVEL__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_PGI QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__PGI)
#   if !defined(QSBOOST_COMP_PGI_DETECTION) && (defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__))
#       define QSBOOST_COMP_PGI_DETECTION QSBOOST_VERSION_NUMBER(__PGIC__,__PGIC_MINOR__,__PGIC_PATCHLEVEL__)
#   endif
#   if !defined(QSBOOST_COMP_PGI_DETECTION)
#       define QSBOOST_COMP_PGI_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_PGI_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_PGI_EMULATED QSBOOST_COMP_PGI_DETECTION
#   else
#       undef QSBOOST_COMP_PGI
#       define QSBOOST_COMP_PGI QSBOOST_COMP_PGI_DETECTION
#   endif
#   define QSBOOST_COMP_PGI_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_PGI_NAME "Portland Group C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PGI,QSBOOST_COMP_PGI_NAME)

#ifdef QSBOOST_COMP_PGI_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PGI_EMULATED,QSBOOST_COMP_PGI_NAME)
#endif

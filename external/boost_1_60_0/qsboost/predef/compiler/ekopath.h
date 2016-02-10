/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_EKOPATH_H
#define QSBOOST_PREDEF_COMPILER_EKOPATH_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_PATH`]

[@http://en.wikipedia.org/wiki/PathScale EKOpath] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__PATHCC__`] [__predef_detection__]]

    [[`__PATHCC__`, `__PATHCC_MINOR__`, `__PATHCC_PATCHLEVEL__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_PATH QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__PATHCC__)
#   define QSBOOST_COMP_PATH_DETECTION \
        QSBOOST_VERSION_NUMBER(__PATHCC__,__PATHCC_MINOR__,__PATHCC_PATCHLEVEL__)
#endif

#ifdef QSBOOST_COMP_PATH_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_PATH_EMULATED QSBOOST_COMP_PATH_DETECTION
#   else
#       undef QSBOOST_COMP_PATH
#       define QSBOOST_COMP_PATH QSBOOST_COMP_PATH_DETECTION
#   endif
#   define QSBOOST_COMP_PATH_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_PATH_NAME "EKOpath"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PATH,QSBOOST_COMP_PATH_NAME)

#ifdef QSBOOST_COMP_PATH_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_PATH_EMULATED,QSBOOST_COMP_PATH_NAME)
#endif

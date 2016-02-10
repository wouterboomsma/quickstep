/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_MICROTEC_H
#define QSBOOST_PREDEF_COMPILER_MICROTEC_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_MRI`]

[@http://www.mentor.com/microtec/ Microtec C/C++] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_MRI`] [__predef_detection__]]
    ]
 */

#define QSBOOST_COMP_MRI QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_MRI)
#   define QSBOOST_COMP_MRI_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#ifdef QSBOOST_COMP_MRI_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_MRI_EMULATED QSBOOST_COMP_MRI_DETECTION
#   else
#       undef QSBOOST_COMP_MRI
#       define QSBOOST_COMP_MRI QSBOOST_COMP_MRI_DETECTION
#   endif
#   define QSBOOST_COMP_MRI_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_MRI_NAME "Microtec C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_MRI,QSBOOST_COMP_MRI_NAME)

#ifdef QSBOOST_COMP_MRI_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_MRI_EMULATED,QSBOOST_COMP_MRI_NAME)
#endif

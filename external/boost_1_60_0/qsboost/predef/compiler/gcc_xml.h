/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_GCC_XML_H
#define QSBOOST_PREDEF_COMPILER_GCC_XML_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_GCCXML`]

[@http://www.gccxml.org/ GCC XML] compiler.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__GCCXML__`] [__predef_detection__]]
    ]
 */

#define QSBOOST_COMP_GCCXML QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GCCXML__)
#   define QSBOOST_COMP_GCCXML_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#ifdef QSBOOST_COMP_GCCXML_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_GCCXML_EMULATED QSBOOST_COMP_GCCXML_DETECTION
#   else
#       undef QSBOOST_COMP_GCCXML
#       define QSBOOST_COMP_GCCXML QSBOOST_COMP_GCCXML_DETECTION
#   endif
#   define QSBOOST_COMP_GCCXML_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_GCCXML_NAME "GCC XML"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GCCXML,QSBOOST_COMP_GCCXML_NAME)

#ifdef QSBOOST_COMP_GCCXML_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_GCCXML_EMULATED,QSBOOST_COMP_GCCXML_NAME)
#endif

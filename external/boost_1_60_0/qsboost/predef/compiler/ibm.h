/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_IBM_H
#define QSBOOST_PREDEF_COMPILER_IBM_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_IBM`]

[@http://en.wikipedia.org/wiki/VisualAge IBM XL C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__IBMCPP__`] [__predef_detection__]]
    [[`__xlC__`] [__predef_detection__]]
    [[`__xlc__`] [__predef_detection__]]

    [[`__COMPILER_VER__`] [V.R.P]]
    [[`__xlC__`] [V.R.P]]
    [[`__xlc__`] [V.R.P]]
    [[`__IBMCPP__`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_IBM QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__IBMCPP__) || defined(__xlC__) || defined(__xlc__)
#   if !defined(QSBOOST_COMP_IBM_DETECTION) && defined(__COMPILER_VER__)
#       define QSBOOST_COMP_IBM_DETECTION QSBOOST_PREDEF_MAKE_0X_VRRPPPP(__COMPILER_VER__)
#   endif
#   if !defined(QSBOOST_COMP_IBM_DETECTION) && defined(__xlC__)
#       define QSBOOST_COMP_IBM_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRR(__xlC__)
#   endif
#   if !defined(QSBOOST_COMP_IBM_DETECTION) && defined(__xlc__)
#       define QSBOOST_COMP_IBM_DETECTION QSBOOST_PREDEF_MAKE_0X_VVRR(__xlc__)
#   endif
#   if !defined(QSBOOST_COMP_IBM_DETECTION)
#       define QSBOOST_COMP_IBM_DETECTION QSBOOST_PREDEF_MAKE_10_VRP(__IBMCPP__)
#   endif
#endif

#ifdef QSBOOST_COMP_IBM_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_IBM_EMULATED QSBOOST_COMP_IBM_DETECTION
#   else
#       undef QSBOOST_COMP_IBM
#       define QSBOOST_COMP_IBM QSBOOST_COMP_IBM_DETECTION
#   endif
#   define QSBOOST_COMP_IBM_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_IBM_NAME "IBM XL C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_IBM,QSBOOST_COMP_IBM_NAME)

#ifdef QSBOOST_COMP_IBM_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_IBM_EMULATED,QSBOOST_COMP_IBM_NAME)
#endif

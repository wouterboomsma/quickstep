/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_DINKUMWARE_H
#define QSBOOST_PREDEF_LIBRARY_STD_DINKUMWARE_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_DINKUMWARE`]

[@http://en.wikipedia.org/wiki/Dinkumware Dinkumware] Standard C++ Library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_YVALS`, `__IBMCPP__`] [__predef_detection__]]
    [[`_CPPLIB_VER`] [__predef_detection__]]

    [[`_CPPLIB_VER`] [V.R.0]]
    ]
 */

#define QSBOOST_LIB_STD_DINKUMWARE QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)
#   undef QSBOOST_LIB_STD_DINKUMWARE
#   if defined(_CPPLIB_VER)
#       define QSBOOST_LIB_STD_DINKUMWARE QSBOOST_PREDEF_MAKE_10_VVRR(_CPPLIB_VER)
#   else
#       define QSBOOST_LIB_STD_DINKUMWARE QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_LIB_STD_DINKUMWARE
#   define QSBOOST_LIB_STD_DINKUMWARE_AVAILABLE
#endif

#define QSBOOST_LIB_STD_DINKUMWARE_NAME "Dinkumware"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_DINKUMWARE,QSBOOST_LIB_STD_DINKUMWARE_NAME)

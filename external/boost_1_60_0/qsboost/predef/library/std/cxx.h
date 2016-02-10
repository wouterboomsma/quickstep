/*
Copyright Rene Rivera 2011-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_CXX_H
#define QSBOOST_PREDEF_LIBRARY_STD_CXX_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_CXX`]

[@http://libcxx.llvm.org/ libc++] C++ Standard Library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`_LIBCPP_VERSION`] [__predef_detection__]]

    [[`_LIBCPP_VERSION`] [V.0.P]]
    ]
 */

#define QSBOOST_LIB_STD_CXX QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_LIBCPP_VERSION)
#   undef QSBOOST_LIB_STD_CXX
#   define QSBOOST_LIB_STD_CXX QSBOOST_PREDEF_MAKE_10_VPPP(_LIBCPP_VERSION)
#endif

#if QSBOOST_LIB_STD_CXX
#   define QSBOOST_LIB_STD_CXX_AVAILABLE
#endif

#define QSBOOST_LIB_STD_CXX_NAME "libc++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_CXX,QSBOOST_LIB_STD_CXX_NAME)

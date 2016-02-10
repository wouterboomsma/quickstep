/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_SGI_H
#define QSBOOST_PREDEF_LIBRARY_STD_SGI_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_SGI`]

[@http://www.sgi.com/tech/stl/ SGI] Standard C++ library.
If available version number as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__STL_CONFIG_H`] [__predef_detection__]]

    [[`__SGI_STL`] [V.R.P]]
    ]
 */

#define QSBOOST_LIB_STD_SGI QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__STL_CONFIG_H)
#   undef QSBOOST_LIB_STD_SGI
#   if defined(__SGI_STL)
#       define QSBOOST_LIB_STD_SGI QSBOOST_PREDEF_MAKE_0X_VRP(__SGI_STL)
#   else
#       define QSBOOST_LIB_STD_SGI QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_LIB_STD_SGI
#   define QSBOOST_LIB_STD_SGI_AVAILABLE
#endif

#define QSBOOST_LIB_STD_SGI_NAME "SGI"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_SGI,QSBOOST_LIB_STD_SGI_NAME)

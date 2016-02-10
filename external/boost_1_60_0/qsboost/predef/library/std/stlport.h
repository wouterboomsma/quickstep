/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_STLPORT_H
#define QSBOOST_PREDEF_LIBRARY_STD_STLPORT_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_STLPORT`]

[@http://sourceforge.net/projects/stlport/ STLport Standard C++] library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__SGI_STL_PORT`] [__predef_detection__]]
    [[`_STLPORT_VERSION`] [__predef_detection__]]

    [[`_STLPORT_MAJOR`, `_STLPORT_MINOR`, `_STLPORT_PATCHLEVEL`] [V.R.P]]
    [[`_STLPORT_VERSION`] [V.R.P]]
    [[`__SGI_STL_PORT`] [V.R.P]]
    ]
 */

#define QSBOOST_LIB_STD_STLPORT QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#   undef QSBOOST_LIB_STD_STLPORT
#   if !defined(QSBOOST_LIB_STD_STLPORT) && defined(_STLPORT_MAJOR)
#       define QSBOOST_LIB_STD_STLPORT \
            QSBOOST_VERSION_NUMBER(_STLPORT_MAJOR,_STLPORT_MINOR,_STLPORT_PATCHLEVEL)
#   endif
#   if !defined(QSBOOST_LIB_STD_STLPORT) && defined(_STLPORT_VERSION)
#       define QSBOOST_LIB_STD_STLPORT QSBOOST_PREDEF_MAKE_0X_VRP(_STLPORT_VERSION)
#   endif
#   if !defined(QSBOOST_LIB_STD_STLPORT)
#       define QSBOOST_LIB_STD_STLPORT QSBOOST_PREDEF_MAKE_0X_VRP(__SGI_STL_PORT)
#   endif
#endif

#if QSBOOST_LIB_STD_STLPORT
#   define QSBOOST_LIB_STD_STLPORT_AVAILABLE
#endif

#define QSBOOST_LIB_STD_STLPORT_NAME "STLport"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_STLPORT,QSBOOST_LIB_STD_STLPORT_NAME)

/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_C_ZOS_H
#define QSBOOST_PREDEF_LIBRARY_C_ZOS_H

#include <qsboost/predef/library/c/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_C_ZOS`]

z/OS libc Standard C library.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__LIBREL__`] [__predef_detection__]]

    [[`__LIBREL__`] [V.R.P]]
    [[`__TARGET_LIB__`] [V.R.P]]
    ]
 */

#define QSBOOST_LIB_C_ZOS QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBREL__)
#   undef QSBOOST_LIB_C_ZOS
#   if !defined(QSBOOST_LIB_C_ZOS) && defined(__LIBREL__)
#       define QSBOOST_LIB_C_ZOS QSBOOST_PREDEF_MAKE_0X_VRRPPPP(__LIBREL__)
#   endif
#   if !defined(QSBOOST_LIB_C_ZOS) && defined(__TARGET_LIB__)
#       define QSBOOST_LIB_C_ZOS QSBOOST_PREDEF_MAKE_0X_VRRPPPP(__TARGET_LIB__)
#   endif
#   if !defined(QSBOOST_LIB_C_ZOS)
#       define QSBOOST_LIB_C_ZOS QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if QSBOOST_LIB_C_ZOS
#   define QSBOOST_LIB_C_ZOS_AVAILABLE
#endif

#define QSBOOST_LIB_C_ZOS_NAME "z/OS"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_C_ZOS,QSBOOST_LIB_C_ZOS_NAME)

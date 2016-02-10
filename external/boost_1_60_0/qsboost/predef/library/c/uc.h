/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_C_UC_H
#define QSBOOST_PREDEF_LIBRARY_C_UC_H

#include <qsboost/predef/library/c/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_C_UC`]

[@http://en.wikipedia.org/wiki/Uclibc uClibc] Standard C library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__UCLIBC__`] [__predef_detection__]]

    [[`__UCLIBC_MAJOR__`, `__UCLIBC_MINOR__`, `__UCLIBC_SUBLEVEL__`] [V.R.P]]
    ]
 */

#define QSBOOST_LIB_C_UC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__UCLIBC__)
#   undef QSBOOST_LIB_C_UC
#   define QSBOOST_LIB_C_UC QSBOOST_VERSION_NUMBER(\
        __UCLIBC_MAJOR__,__UCLIBC_MINOR__,__UCLIBC_SUBLEVEL__)
#endif

#if QSBOOST_LIB_C_UC
#   define QSBOOST_LIB_C_UC_AVAILABLE
#endif

#define QSBOOST_LIB_C_UC_NAME "uClibc"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_C_UC,QSBOOST_LIB_C_UC_NAME)

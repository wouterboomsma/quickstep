/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_MODENA_H
#define QSBOOST_PREDEF_LIBRARY_STD_MODENA_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_MSIPL`]

[@http://modena.us/ Modena Software Lib++] Standard C++ Library.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`MSIPL_COMPILE_H`] [__predef_detection__]]
    [[`__MSIPL_COMPILE_H`] [__predef_detection__]]
    ]
 */

#define QSBOOST_LIB_STD_MSIPL QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(MSIPL_COMPILE_H) || defined(__MSIPL_COMPILE_H)
#   undef QSBOOST_LIB_STD_MSIPL
#   define QSBOOST_LIB_STD_MSIPL QSBOOST_VERSION_NUMBER_AVAILABLE
#endif

#if QSBOOST_LIB_STD_MSIPL
#   define QSBOOST_LIB_STD_MSIPL_AVAILABLE
#endif

#define QSBOOST_LIB_STD_MSIPL_NAME "Modena Software Lib++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_MSIPL,QSBOOST_LIB_STD_MSIPL_NAME)

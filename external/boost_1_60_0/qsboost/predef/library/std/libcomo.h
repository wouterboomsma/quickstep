/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_LIBRARY_STD_LIBCOMO_H
#define QSBOOST_PREDEF_LIBRARY_STD_LIBCOMO_H

#include <qsboost/predef/library/std/_prefix.h>

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_LIB_STD_COMO`]

[@http://www.comeaucomputing.com/libcomo/ Comeau Computing] Standard C++ Library.
Version number available as major.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__LIBCOMO__`] [__predef_detection__]]

    [[`__LIBCOMO_VERSION__`] [V.0.0]]
    ]
 */

#define QSBOOST_LIB_STD_COMO QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__LIBCOMO__)
#   undef QSBOOST_LIB_STD_COMO
#   define QSBOOST_LIB_STD_COMO QSBOOST_VERSION_NUMBER(__LIBCOMO_VERSION__,0,0)
#endif

#if QSBOOST_LIB_STD_COMO
#   define QSBOOST_LIB_STD_COMO_AVAILABLE
#endif

#define QSBOOST_LIB_STD_COMO_NAME "Comeau Computing"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_LIB_STD_COMO,QSBOOST_LIB_STD_COMO_NAME)

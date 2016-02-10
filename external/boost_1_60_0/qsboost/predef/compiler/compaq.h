/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_COMPAQ_H
#define QSBOOST_PREDEF_COMPILER_COMPAQ_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_DEC`]

[@http://www.openvms.compaq.com/openvms/brochures/deccplus/ Compaq C/C++] compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__DECCXX`] [__predef_detection__]]
    [[`__DECC`] [__predef_detection__]]

    [[`__DECCXX_VER`] [V.R.P]]
    [[`__DECC_VER`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_DEC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__DECC) || defined(__DECCXX)
#   if !defined(QSBOOST_COMP_DEC_DETECTION) && defined(__DECCXX_VER)
#       define QSBOOST_COMP_DEC_DETECTION QSBOOST_PREDEF_MAKE_10_VVRR0PP00(__DECCXX_VER)
#   endif
#   if !defined(QSBOOST_COMP_DEC_DETECTION) && defined(__DECC_VER)
#       define QSBOOST_COMP_DEC_DETECTION QSBOOST_PREDEF_MAKE_10_VVRR0PP00(__DECC_VER)
#   endif
#   if !defined(QSBOOST_COMP_DEC_DETECTION)
#       define QSBOOST_COM_DEC_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_DEC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_DEC_EMULATED QSBOOST_COMP_DEC_DETECTION
#   else
#       undef QSBOOST_COMP_DEC
#       define QSBOOST_COMP_DEC QSBOOST_COMP_DEC_DETECTION
#   endif
#   define QSBOOST_COMP_DEC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_DEC_NAME "Compaq C/C++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DEC,QSBOOST_COMP_DEC_NAME)

#ifdef QSBOOST_COMP_DEC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_DEC_EMULATED,QSBOOST_COMP_DEC_NAME)
#endif

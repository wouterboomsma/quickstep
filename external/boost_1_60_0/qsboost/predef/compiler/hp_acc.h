/*
Copyright Rene Rivera 2008-2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_COMPILER_HP_ACC_H
#define QSBOOST_PREDEF_COMPILER_HP_ACC_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/make.h>

/*`
[heading `BOOST_COMP_HPACC`]

HP aC++ compiler.
Version number available as major, minor, and patch.

[table
    [[__predef_symbol__] [__predef_version__]]

    [[`__HP_aCC`] [__predef_detection__]]

    [[`__HP_aCC`] [V.R.P]]
    ]
 */

#define QSBOOST_COMP_HPACC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__HP_aCC)
#   if !defined(QSBOOST_COMP_HPACC_DETECTION) && (__HP_aCC > 1)
#       define QSBOOST_COMP_HPACC_DETECTION QSBOOST_PREDEF_MAKE_10_VVRRPP(__HP_aCC)
#   endif
#   if !defined(QSBOOST_COMP_HPACC_DETECTION)
#       define QSBOOST_COMP_HPACC_DETECTION QSBOOST_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#ifdef QSBOOST_COMP_HPACC_DETECTION
#   if defined(QSBOOST_PREDEF_DETAIL_COMP_DETECTED)
#       define QSBOOST_COMP_HPACC_EMULATED QSBOOST_COMP_HPACC_DETECTION
#   else
#       undef QSBOOST_COMP_HPACC
#       define QSBOOST_COMP_HPACC QSBOOST_COMP_HPACC_DETECTION
#   endif
#   define QSBOOST_COMP_HPACC_AVAILABLE
#   include <qsboost/predef/detail/comp_detected.h>
#endif

#define QSBOOST_COMP_HPACC_NAME "HP aC++"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_HPACC,QSBOOST_COMP_HPACC_NAME)

#ifdef QSBOOST_COMP_HPACC_EMULATED
#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_COMP_HPACC_EMULATED,QSBOOST_COMP_HPACC_NAME)
#endif

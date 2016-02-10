/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_HARDWARE_SIMD_PPC_H
#define QSBOOST_PREDEF_HARDWARE_SIMD_PPC_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/hardware/simd/ppc/versions.h>

/*`
 [heading `BOOST_HW_SIMD_PPC`]

 The SIMD extension for PowerPC (*if detected*).
 Version number depends on the most recent detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__VECTOR4DOUBLE__`] [__predef_detection__]]

     [[`__ALTIVEC__`] [__predef_detection__]]
     [[`__VEC__`] [__predef_detection__]]

     [[`__VSX__`] [__predef_detection__]]
     ]

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__VECTOR4DOUBLE__`] [BOOST_HW_SIMD_PPC_QPX_VERSION]]

     [[`__ALTIVEC__`] [BOOST_HW_SIMD_PPC_VMX_VERSION]]
     [[`__VEC__`] [BOOST_HW_SIMD_PPC_VMX_VERSION]]

     [[`__VSX__`] [BOOST_HW_SIMD_PPC_VSX_VERSION]]
     ]

 */

#define QSBOOST_HW_SIMD_PPC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

#undef QSBOOST_HW_SIMD_PPC
#if !defined(QSBOOST_HW_SIMD_PPC) && defined(__VECTOR4DOUBLE__)
#   define QSBOOST_HW_SIMD_PPC QSBOOST_HW_SIMD_PPC_QPX_VERSION
#endif
#if !defined(QSBOOST_HW_SIMD_PPC) && defined(__VSX__)
#   define QSBOOST_HW_SIMD_PPC QSBOOST_HW_SIMD_PPC_VSX_VERSION
#endif
#if !defined(QSBOOST_HW_SIMD_PPC) && (defined(__ALTIVEC__) || defined(__VEC__))
#   define QSBOOST_HW_SIMD_PPC QSBOOST_HW_SIMD_PPC_VMX_VERSION
#endif

#if !defined(QSBOOST_HW_SIMD_PPC)
#   define QSBOOST_HW_SIMD_PPC QSBOOST_VERSION_NUMBER_NOT_AVAILABLE
#else
#   define QSBOOST_HW_SIMD_PPC_AVAILABLE
#endif

#define QSBOOST_HW_SIMD_PPC_NAME "PPC SIMD"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_HW_SIMD_PPC, QSBOOST_HW_SIMD_PPC_NAME)

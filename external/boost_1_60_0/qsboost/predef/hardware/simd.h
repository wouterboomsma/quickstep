/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <qsboost/predef/hardware/simd/x86.h>
#include <qsboost/predef/hardware/simd/x86_amd.h>
#include <qsboost/predef/hardware/simd/arm.h>
#include <qsboost/predef/hardware/simd/ppc.h>

#ifndef QSBOOST_PREDEF_HARDWARE_SIMD_H
#define QSBOOST_PREDEF_HARDWARE_SIMD_H

#include <qsboost/predef/version_number.h>

/*`
 [section Using the `BOOST_HW_SIMD_*` predefs]
 [include ../doc/hardware_simd.qbk]
 [endsect]

 [/ --------------------------- ]

 [section `BOOST_HW_SIMD_*`]

 [heading `BOOST_HW_SIMD`]

 The SIMD extension detected for a specific architectures.
 Version number depends on the detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`BOOST_HW_SIMD_X86_AVAILABLE`] [__predef_detection__]]
     [[`BOOST_HW_SIMD_X86_AMD_AVAILABLE`] [__predef_detection__]]
     [[`BOOST_HW_SIMD_ARM_AVAILABLE`] [__predef_detection__]]
     [[`BOOST_HW_SIMD_PPC_AVAILABLE`] [__predef_detection__]]
     ]

 [include ../include/boost/predef/hardware/simd/x86.h]
 [include ../include/boost/predef/hardware/simd/x86_amd.h]
 [include ../include/boost/predef/hardware/simd/arm.h]
 [include ../include/boost/predef/hardware/simd/ppc.h]

 [endsect]

 [/ --------------------------- ]

 [section `BOOST_HW_SIMD_X86_*_VERSION`]
 [include ../include/boost/predef/hardware/simd/x86/versions.h]
 [endsect]

 [section `BOOST_HW_SIMD_X86_AMD_*_VERSION`]
 [include ../include/boost/predef/hardware/simd/x86_amd/versions.h]
 [endsect]

 [section `BOOST_HW_SIMD_ARM_*_VERSION`]
 [include ../include/boost/predef/hardware/simd/arm/versions.h]
 [endsect]

 [section `BOOST_HW_SIMD_PPC_*_VERSION`]
 [include ../include/boost/predef/hardware/simd/ppc/versions.h]
 [endsect]

 */

// We check if SIMD extension of multiples architectures have been detected,
// if yes, then this is an error!
//
// NOTE: _X86_AMD implies _X86, so there is no need to check for it here!
//
#if defined(QSBOOST_HW_SIMD_ARM_AVAILABLE) && defined(QSBOOST_HW_SIMD_PPC_AVAILABLE) ||\
    defined(QSBOOST_HW_SIMD_ARM_AVAILABLE) && defined(QSBOOST_HW_SIMD_X86_AVAILABLE) ||\
    defined(QSBOOST_HW_SIMD_PPC_AVAILABLE) && defined(QSBOOST_HW_SIMD_X86_AVAILABLE)
#   error "Multiple SIMD architectures detected, this cannot happen!"
#endif

#if defined(QSBOOST_HW_SIMD_X86_AVAILABLE)
#   define QSBOOST_HW_SIMD QSBOOST_HW_SIMD_X86
#endif

#if defined(QSBOOST_HW_SIMD_X86_AMD_AVAILABLE)
#   define QSBOOST_HW_SIMD QSBOOST_HW_SIMD_X86_AMD
#endif

#if defined(QSBOOST_HW_SIMD_ARM_AVAILABLE)
#   define QSBOOST_HW_SIMD QSBOOST_HW_SIMD_ARM
#endif

#if defined(QSBOOST_HW_SIMD_PPC_AVAILABLE)
#   define QSBOOST_HW_SIMD QSBOOST_HW_SIMD_PPC
#endif

#if defined(QSBOOST_HW_SIMD)
#   define QSBOOST_HW_SIMD_AVAILABLE
#else
#   define QSBOOST_HW_SIMD QSBOOST_VERSION_NUMBER_NOT_AVAILABLE
#endif

#define QSBOOST_HW_SIMD_NAME "Hardware SIMD"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_HW_SIMD, QSBOOST_HW_SIMD_NAME)

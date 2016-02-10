/*
Copyright Charly Chevalier 2015
Copyright Joel Falcou 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_HARDWARE_SIMD_X86_AMD_H
#define QSBOOST_PREDEF_HARDWARE_SIMD_X86_AMD_H

#include <qsboost/predef/version_number.h>
#include <qsboost/predef/hardware/simd/x86_amd/versions.h>

/*`
 [heading `BOOST_HW_SIMD_X86_AMD`]

 The SIMD extension for x86 (AMD) (*if detected*).
 Version number depends on the most recent detected extension.

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE4A__`] [__predef_detection__]]

     [[`__FMA4__`] [__predef_detection__]]

     [[`__XOP__`] [__predef_detection__]]

     [[`BOOST_HW_SIMD_X86`] [__predef_detection__]]
     ]

 [table
     [[__predef_symbol__] [__predef_version__]]

     [[`__SSE4A__`] [BOOST_HW_SIMD_x86_SSE4A_VERSION]]

     [[`__FMA4__`] [BOOST_HW_SIMD_x86_FMA4_VERSION]]

     [[`__XOP__`] [BOOST_HW_SIMD_x86_XOP_VERSION]]

     [[`BOOST_HW_SIMD_X86`] [BOOST_HW_SIMD_x86]]
     ]

 [note This predef includes every other x86 SIMD extensions and also has other
 more specific extensions (FMA4, XOP, SSE4a). You should use this predef
 instead of `BOOST_HW_SIMD_X86` to test if those specific extensions have
 been detected.]

 */

#define QSBOOST_HW_SIMD_X86_AMD QSBOOST_VERSION_NUMBER_NOT_AVAILABLE

// AMD CPUs also use x86 architecture. We first try to detect if any AMD
// specific extension are detected, if yes, then try to detect more recent x86
// common extensions.

#undef QSBOOST_HW_SIMD_X86_AMD
#if !defined(QSBOOST_HW_SIMD_X86_AMD) && defined(__XOP__)
#   define QSBOOST_HW_SIMD_X86_AMD QSBOOST_HW_SIMD_X86_AMD_XOP_VERSION
#endif
#if !defined(QSBOOST_HW_SIMD_X86_AMD) && defined(__FMA4__)
#   define QSBOOST_HW_SIMD_X86_AMD QSBOOST_HW_SIMD_X86_AMD_FMA4_VERSION
#endif
#if !defined(QSBOOST_HW_SIMD_X86_AMD) && defined(__SSE4A__)
#   define QSBOOST_HW_SIMD_X86_AMD QSBOOST_HW_SIMD_X86_AMD_SSE4A_VERSION
#endif

#if !defined(QSBOOST_HW_SIMD_X86_AMD)
#   define QSBOOST_HW_SIMD_X86_AMD QSBOOST_VERSION_NUMBER_NOT_AVAILABLE
#else
    // At this point, we know that we have an AMD CPU, we do need to check for
    // other x86 extensions to determine the final version number.
#   include <qsboost/predef/hardware/simd/x86.h>
#   if QSBOOST_HW_SIMD_X86 > QSBOOST_HW_SIMD_X86_AMD
#      undef QSBOOST_HW_SIMD_X86_AMD
#      define QSBOOST_HW_SIMD_X86_AMD QSBOOST_HW_SIMD_X86
#   endif
#   define QSBOOST_HW_SIMD_X86_AMD_AVAILABLE
#endif

#define QSBOOST_HW_SIMD_X86_AMD_NAME "x86 (AMD) SIMD"

#endif

#include <qsboost/predef/detail/test.h>
QSBOOST_PREDEF_DECLARE_TEST(QSBOOST_HW_SIMD_X86_AMD, QSBOOST_HW_SIMD_X86_AMD_NAME)

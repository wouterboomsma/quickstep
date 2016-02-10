//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Martin Wille 2003.
//  (C) Copyright Guillaume Melquiond 2003.
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for most recent version.

// locate which compiler we are using and define
// BOOST_COMPILER_CONFIG as needed: 

#if defined __CUDACC__
//  NVIDIA CUDA C++ compiler for GPU
#   include "qsboost/config/compiler/nvcc.hpp"

#endif

#if defined(__GCCXML__)
// GCC-XML emulates other compilers, it has to appear first here!
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/gcc_xml.hpp"

#elif defined(_CRAYC)
// EDG based Cray compiler:
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/cray.hpp"

#elif defined __COMO__
//  Comeau C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/comeau.hpp"

#elif defined(__PATHSCALE__) && (__PATHCC__ >= 4)
// PathScale EKOPath compiler (has to come before clang and gcc)
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/pathscale.hpp"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
//  Intel
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/intel.hpp"

#elif defined __clang__ && !defined(__CUDACC__) && !defined(__ibmxl__)
// when using clang and cuda at same time, you want to appear as gcc
//  Clang C++ emulates GCC, so it has to appear early.
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/clang.hpp"

#elif defined __DMC__
//  Digital Mars C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/digitalmars.hpp"

# elif defined(__GNUC__) && !defined(__ibmxl__)
//  GNU C++:
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/gcc.hpp"

#elif defined __KCC
//  Kai C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/kai.hpp"

#elif defined __sgi
//  SGI MIPSpro C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/sgi_mipspro.hpp"

#elif defined __DECCXX
//  Compaq Tru64 Unix cxx
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/compaq_cxx.hpp"

#elif defined __ghs
//  Greenhills C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/greenhills.hpp"

#elif defined __CODEGEARC__
//  CodeGear - must be checked for before Borland
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/codegear.hpp"

#elif defined __BORLANDC__
//  Borland
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/borland.hpp"

#elif defined  __MWERKS__
//  Metrowerks CodeWarrior
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/metrowerks.hpp"

#elif defined  __SUNPRO_CC
//  Sun Workshop Compiler C++
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/sunpro_cc.hpp"

#elif defined __HP_aCC
//  HP aCC
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/hp_acc.hpp"

#elif defined(__MRC__) || defined(__SC__)
//  MPW MrCpp or SCpp
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/mpw.hpp"

#elif defined(__ibmxl__)
// IBM XL C/C++ for Linux (Little Endian)
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/xlcpp.hpp"

#elif defined(__IBMCPP__)
//  IBM Visual Age or IBM XL C/C++ for Linux (Big Endian)
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/vacpp.hpp"

#elif defined(__PGI)
//  Portland Group Inc.
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/pgi.hpp"

#elif defined _MSC_VER
//  Microsoft Visual C++
//
//  Must remain the last #elif since some other vendors (Metrowerks, for
//  example) also #define _MSC_VER
#   define QSBOOST_COMPILER_CONFIG "qsboost/config/compiler/visualc.hpp"

#elif defined (QSBOOST_ASSERT_CONFIG)
// this must come last - generate an error if we don't
// recognise the compiler:
#  error "Unknown compiler - please configure (http://www.boost.org/libs/config/config.htm#configuring) and report the results to the main boost mailing list (http://www.boost.org/more/mailing_lists.htm#main)"

#endif

#if 0
//
// This section allows dependency scanners to find all the headers we *might* include:
//
#include "qsboost/config/compiler/gcc_xml.hpp"
#include "qsboost/config/compiler/cray.hpp"
#include "qsboost/config/compiler/comeau.hpp"
#include "qsboost/config/compiler/pathscale.hpp"
#include "qsboost/config/compiler/intel.hpp"
#include "qsboost/config/compiler/clang.hpp"
#include "qsboost/config/compiler/digitalmars.hpp"
#include "qsboost/config/compiler/gcc.hpp"
#include "qsboost/config/compiler/kai.hpp"
#include "qsboost/config/compiler/sgi_mipspro.hpp"
#include "qsboost/config/compiler/compaq_cxx.hpp"
#include "qsboost/config/compiler/greenhills.hpp"
#include "qsboost/config/compiler/codegear.hpp"
#include "qsboost/config/compiler/borland.hpp"
#include "qsboost/config/compiler/metrowerks.hpp"
#include "qsboost/config/compiler/sunpro_cc.hpp"
#include "qsboost/config/compiler/hp_acc.hpp"
#include "qsboost/config/compiler/mpw.hpp"
#include "qsboost/config/compiler/vacpp.hpp"
#include "qsboost/config/compiler/pgi.hpp"
#include "qsboost/config/compiler/visualc.hpp"

#endif


//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Jens Maurer 2001 - 2003. 
//  (C) Copyright David Abrahams 2002. 
//  (C) Copyright Toon Knapen 2003. 
//  (C) Copyright Boris Gubenko 2006 - 2007.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  hpux specific config options:

#define QSBOOST_PLATFORM "HP-UX"

// In principle, HP-UX has a nice <stdint.h> under the name <inttypes.h>
// However, it has the following problem:
// Use of UINT32_C(0) results in "0u l" for the preprocessed source
// (verifyable with gcc 2.95.3)
#if (defined(__GNUC__) && (__GNUC__ >= 3)) || defined(__HP_aCC)
#  define QSBOOST_HAS_STDINT_H
#endif

#if !(defined(__HP_aCC) || !defined(_INCLUDE__STDC_A1_SOURCE))
#  define QSBOOST_NO_SWPRINTF
#endif
#if defined(__HP_aCC) && !defined(_INCLUDE__STDC_A1_SOURCE)
#  define QSBOOST_NO_CWCTYPE
#endif

#if defined(__GNUC__)
#  if (__GNUC__ < 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ < 3))
      // GNU C on HP-UX does not support threads (checked up to gcc 3.3)
#     define QSBOOST_DISABLE_THREADS
#  elif !defined(QSBOOST_DISABLE_THREADS)
      // threads supported from gcc-3.3 onwards:
#     define QSBOOST_HAS_THREADS
#     define QSBOOST_HAS_PTHREADS
#  endif
#elif defined(__HP_aCC) && !defined(QSBOOST_DISABLE_THREADS)
#  define QSBOOST_HAS_PTHREADS
#endif

// boilerplate code:
#define QSBOOST_HAS_UNISTD_H
#include <qsboost/config/posix_features.hpp>

// the following are always available:
#ifndef QSBOOST_HAS_GETTIMEOFDAY
#  define QSBOOST_HAS_GETTIMEOFDAY
#endif
#ifndef QSBOOST_HAS_SCHED_YIELD
#    define QSBOOST_HAS_SCHED_YIELD
#endif
#ifndef QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#    define QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#endif
#ifndef QSBOOST_HAS_NL_TYPES_H
#    define QSBOOST_HAS_NL_TYPES_H
#endif
#ifndef QSBOOST_HAS_NANOSLEEP
#    define QSBOOST_HAS_NANOSLEEP
#endif
#ifndef QSBOOST_HAS_GETTIMEOFDAY
#    define QSBOOST_HAS_GETTIMEOFDAY
#endif
#ifndef QSBOOST_HAS_DIRENT_H
#    define QSBOOST_HAS_DIRENT_H
#endif
#ifndef QSBOOST_HAS_CLOCK_GETTIME
#    define QSBOOST_HAS_CLOCK_GETTIME
#endif
#ifndef QSBOOST_HAS_SIGACTION
#  define QSBOOST_HAS_SIGACTION
#endif
#ifndef QSBOOST_HAS_NRVO 
#  ifndef __parisc
#    define QSBOOST_HAS_NRVO
#  endif
#endif
#ifndef QSBOOST_HAS_LOG1P 
#  define QSBOOST_HAS_LOG1P
#endif
#ifndef QSBOOST_HAS_EXPM1
#  define QSBOOST_HAS_EXPM1
#endif


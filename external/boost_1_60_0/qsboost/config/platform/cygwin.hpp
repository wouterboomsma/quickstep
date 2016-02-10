//  (C) Copyright John Maddock 2001 - 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  cygwin specific config options:

#define QSBOOST_PLATFORM "Cygwin"
#define QSBOOST_HAS_DIRENT_H
#define QSBOOST_HAS_LOG1P
#define QSBOOST_HAS_EXPM1

//
// Threading API:
// See if we have POSIX threads, if we do use them, otherwise
// revert to native Win threads.
#define QSBOOST_HAS_UNISTD_H
#include <unistd.h>
#if defined(_POSIX_THREADS) && (_POSIX_THREADS+0 >= 0) && !defined(QSBOOST_HAS_WINTHREADS)
#  define QSBOOST_HAS_PTHREADS
#  define QSBOOST_HAS_SCHED_YIELD
#  define QSBOOST_HAS_GETTIMEOFDAY
#  define QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#  define QSBOOST_HAS_SIGACTION
#else
#  if !defined(QSBOOST_HAS_WINTHREADS)
#     define QSBOOST_HAS_WINTHREADS
#  endif
#  define QSBOOST_HAS_FTIME
#endif

//
// find out if we have a stdint.h, there should be a better way to do this:
//
#include <sys/types.h>
#ifdef _STDINT_H
#define QSBOOST_HAS_STDINT_H
#endif

/// Cygwin has no fenv.h
#define QSBOOST_NO_FENV_H

// boilerplate code:
#include <qsboost/config/posix_features.hpp>

//
// Cygwin lies about XSI conformance, there is no nl_types.h:
//
#ifdef QSBOOST_HAS_NL_TYPES_H
#  undef QSBOOST_HAS_NL_TYPES_H
#endif
 





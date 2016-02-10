//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Jens Maurer 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


//  See http://www.boost.org for most recent version.

//  SGI Irix specific config options:

#define QSBOOST_PLATFORM "SGI Irix"

#define QSBOOST_NO_SWPRINTF 
//
// these are not auto detected by POSIX feature tests:
//
#define QSBOOST_HAS_GETTIMEOFDAY
#define QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE

#ifdef __GNUC__
   // GNU C on IRIX does not support threads (checked up to gcc 3.3)
#  define QSBOOST_DISABLE_THREADS
#endif

// boilerplate code:
#define QSBOOST_HAS_UNISTD_H
#include <qsboost/config/posix_features.hpp>




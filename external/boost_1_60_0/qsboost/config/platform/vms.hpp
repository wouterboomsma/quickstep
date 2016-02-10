//  (C) Copyright Artyom Beilis 2010.  
//  Use, modification and distribution are subject to the  
//  Boost Software License, Version 1.0. (See accompanying file  
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) 

#ifndef QSBOOST_CONFIG_PLATFORM_VMS_HPP 
#define QSBOOST_CONFIG_PLATFORM_VMS_HPP 

#define QSBOOST_PLATFORM "OpenVMS" 

#undef  QSBOOST_HAS_STDINT_H 
#define QSBOOST_HAS_UNISTD_H 
#define QSBOOST_HAS_NL_TYPES_H 
#define QSBOOST_HAS_GETTIMEOFDAY 
#define QSBOOST_HAS_DIRENT_H 
#define QSBOOST_HAS_PTHREADS 
#define QSBOOST_HAS_NANOSLEEP 
#define QSBOOST_HAS_CLOCK_GETTIME 
#define QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE 
#define QSBOOST_HAS_LOG1P 
#define QSBOOST_HAS_EXPM1 
#define QSBOOST_HAS_THREADS 
#undef  QSBOOST_HAS_SCHED_YIELD 

#endif 

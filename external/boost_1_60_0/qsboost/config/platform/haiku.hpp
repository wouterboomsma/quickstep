//  (C) Copyright Jessica Hamilton 2014.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  Haiku specific config options:

#define QSBOOST_PLATFORM "Haiku"

#define QSBOOST_HAS_UNISTD_H
#define QSBOOST_HAS_STDINT_H

#ifndef QSBOOST_DISABLE_THREADS
#  define QSBOOST_HAS_THREADS
#endif

#define QSBOOST_NO_CXX11_HDR_TYPE_TRAITS
#define QSBOOST_NO_CXX11_ATOMIC_SMART_PTR
#define QSBOOST_NO_CXX11_STATIC_ASSERT
#define QSBOOST_NO_CXX11_VARIADIC_MACROS

//
// thread API's not auto detected:
//
#define QSBOOST_HAS_SCHED_YIELD
#define QSBOOST_HAS_GETTIMEOFDAY

// boilerplate code:
#include <qsboost/config/posix_features.hpp>

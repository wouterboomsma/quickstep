//  (C) Copyright John Maddock 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  BeOS specific config options:

#define QSBOOST_PLATFORM "BeOS"

#define QSBOOST_NO_CWCHAR
#define QSBOOST_NO_CWCTYPE
#define QSBOOST_HAS_UNISTD_H

#define QSBOOST_HAS_BETHREADS

#ifndef QSBOOST_DISABLE_THREADS
#  define QSBOOST_HAS_THREADS
#endif

// boilerplate code:
#include <qsboost/config/posix_features.hpp>
 



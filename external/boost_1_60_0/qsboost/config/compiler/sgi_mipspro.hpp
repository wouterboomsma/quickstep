//  (C) Copyright John Maddock 2001 - 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  SGI C++ compiler setup:

#define QSBOOST_COMPILER "SGI Irix compiler version " QSBOOST_STRINGIZE(_COMPILER_VERSION)

#include "qsboost/config/compiler/common_edg.hpp"

//
// Threading support:
// Turn this on unconditionally here, it will get turned off again later
// if no threading API is detected.
//
#define QSBOOST_HAS_THREADS
#define QSBOOST_NO_TWO_PHASE_NAME_LOOKUP

#undef QSBOOST_NO_SWPRINTF
#undef QSBOOST_DEDUCED_TYPENAME

//
// version check:
// probably nothing to do here?



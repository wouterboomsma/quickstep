//  (C) Copyright John Maddock 2005.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// The aim of this header is just to include <memory> but to do
// so in a way that does not result in recursive inclusion of
// the Boost TR1 components if boost/tr1/tr1/memory is in the
// include search path.  We have to do this to avoid circular
// dependencies:
//

#ifndef QSBOOST_CONFIG_MEMORY
#  define QSBOOST_CONFIG_MEMORY

#  ifndef QSBOOST_TR1_NO_RECURSION
#     define QSBOOST_TR1_NO_RECURSION
#     define QSBOOST_CONFIG_NO_MEMORY_RECURSION
#  endif

#  include <memory>

#  ifdef QSBOOST_CONFIG_NO_MEMORY_RECURSION
#     undef QSBOOST_TR1_NO_RECURSION
#     undef QSBOOST_CONFIG_NO_MEMORY_RECURSION
#  endif

#endif

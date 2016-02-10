//  (C) Copyright John Maddock 2001 - 2002. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

#if __IBMCPP__ <= 501
#  define QSBOOST_NO_STD_ALLOCATOR
#endif

#define QSBOOST_HAS_MACRO_USE_FACET
#define QSBOOST_NO_STD_MESSAGES

// Apple doesn't seem to reliably defined a *unix* macro
#if !defined(CYGWIN) && (  defined(__unix__)  \
                        || defined(__unix)    \
                        || defined(unix)      \
                        || defined(__APPLE__) \
                        || defined(__APPLE)   \
                        || defined(APPLE))
#  include <unistd.h>
#endif

//  C++0x headers not yet implemented
//
#  define QSBOOST_NO_CXX11_HDR_ARRAY
#  define QSBOOST_NO_CXX11_HDR_CHRONO
#  define QSBOOST_NO_CXX11_HDR_CODECVT
#  define QSBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#  define QSBOOST_NO_CXX11_HDR_FORWARD_LIST
#  define QSBOOST_NO_CXX11_HDR_FUTURE
#  define QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#  define QSBOOST_NO_CXX11_HDR_MUTEX
#  define QSBOOST_NO_CXX11_HDR_RANDOM
#  define QSBOOST_NO_CXX11_HDR_RATIO
#  define QSBOOST_NO_CXX11_HDR_REGEX
#  define QSBOOST_NO_CXX11_HDR_SYSTEM_ERROR
#  define QSBOOST_NO_CXX11_HDR_THREAD
#  define QSBOOST_NO_CXX11_HDR_TUPLE
#  define QSBOOST_NO_CXX11_HDR_TYPE_TRAITS
#  define QSBOOST_NO_CXX11_HDR_TYPEINDEX
#  define QSBOOST_NO_CXX11_HDR_UNORDERED_MAP
#  define QSBOOST_NO_CXX11_HDR_UNORDERED_SET
#  define QSBOOST_NO_CXX11_NUMERIC_LIMITS
#  define QSBOOST_NO_CXX11_ALLOCATOR
#  define QSBOOST_NO_CXX11_ATOMIC_SMART_PTR
#  define QSBOOST_NO_CXX11_SMART_PTR
#  define QSBOOST_NO_CXX11_HDR_FUNCTIONAL
#  define QSBOOST_NO_CXX11_HDR_ATOMIC
#  define QSBOOST_NO_CXX11_STD_ALIGN
#  define QSBOOST_NO_CXX11_ADDRESSOF

#if defined(__has_include)
#if !__has_include(<shared_mutex>)
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#elif __cplusplus < 201402
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif
#else
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif

#define QSBOOST_STDLIB "Visual Age default standard library"

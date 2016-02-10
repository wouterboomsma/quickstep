//  (C) Copyright Christopher Jefferson 2011.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  config for libc++
//  Might need more in here later.

#if !defined(_LIBCPP_VERSION)
#  include <ciso646>
#  if !defined(_LIBCPP_VERSION)
#      error "This is not libc++!"
#  endif
#endif

#define QSBOOST_STDLIB "libc++ version " QSBOOST_STRINGIZE(_LIBCPP_VERSION)

#define QSBOOST_HAS_THREADS

#ifdef _LIBCPP_HAS_NO_VARIADICS
#    define QSBOOST_NO_CXX11_HDR_TUPLE
#endif

// BOOST_NO_CXX11_ALLOCATOR should imply no support for the C++11
// allocator model. The C++11 allocator model requires a conforming
// std::allocator_traits which is only possible with C++11 template
// aliases since members rebind_alloc and rebind_traits require it.
#if defined(_LIBCPP_HAS_NO_TEMPLATE_ALIASES)
#    define QSBOOST_NO_CXX11_ALLOCATOR
#endif

#if __cplusplus < 201103
#  define QSBOOST_NO_CXX11_HDR_ARRAY
#  define QSBOOST_NO_CXX11_HDR_CODECVT
#  define QSBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#  define QSBOOST_NO_CXX11_HDR_FORWARD_LIST
#  define QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#  define QSBOOST_NO_CXX11_HDR_MUTEX
#  define QSBOOST_NO_CXX11_HDR_RANDOM
#  define QSBOOST_NO_CXX11_HDR_RATIO
#  define QSBOOST_NO_CXX11_HDR_REGEX
#  define QSBOOST_NO_CXX11_HDR_SYSTEM_ERROR
#  define QSBOOST_NO_CXX11_HDR_THREAD
#  define QSBOOST_NO_CXX11_HDR_TUPLE
#  define QSBOOST_NO_CXX11_HDR_TYPEINDEX
#  define QSBOOST_NO_CXX11_HDR_UNORDERED_MAP
#  define QSBOOST_NO_CXX11_HDR_UNORDERED_SET
#  define QSBOOST_NO_CXX11_NUMERIC_LIMITS
#  define QSBOOST_NO_CXX11_ALLOCATOR
#  define QSBOOST_NO_CXX11_SMART_PTR
#  define QSBOOST_NO_CXX11_HDR_FUNCTIONAL
#  define QSBOOST_NO_CXX11_STD_ALIGN
#  define QSBOOST_NO_CXX11_ADDRESSOF
#endif

//
// These appear to be unusable/incomplete so far:
//
#  define QSBOOST_NO_CXX11_HDR_CHRONO
#  define QSBOOST_NO_CXX11_HDR_FUTURE
#  define QSBOOST_NO_CXX11_HDR_TYPE_TRAITS
#  define QSBOOST_NO_CXX11_ATOMIC_SMART_PTR
#  define QSBOOST_NO_CXX11_HDR_ATOMIC

// libc++ uses a non-standard messages_base
#define QSBOOST_NO_STD_MESSAGES

#if defined(__has_include)
#if !__has_include(<shared_mutex>)
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#elif __cplusplus <= 201103
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif
#elif __cplusplus < 201402
#  define QSBOOST_NO_CXX14_HDR_SHARED_MUTEX
#endif

//  --- end ---

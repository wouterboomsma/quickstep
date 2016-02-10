//  Boost config.hpp configuration header file  ------------------------------//
//  boostinspect:ndprecated_macros -- tell the inspect tool to ignore this file

//  Copyright (c) 2001-2003 John Maddock
//  Copyright (c) 2001 Darin Adler
//  Copyright (c) 2001 Peter Dimov
//  Copyright (c) 2002 Bill Kempf
//  Copyright (c) 2002 Jens Maurer
//  Copyright (c) 2002-2003 David Abrahams
//  Copyright (c) 2003 Gennaro Prota
//  Copyright (c) 2003 Eric Friedman
//  Copyright (c) 2010 Eric Jourdanneau, Joel Falcou
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for most recent version.

//  Boost config.hpp policy and rationale documentation has been moved to
//  http://www.boost.org/libs/config/
//
//  This file is intended to be stable, and relatively unchanging.
//  It should contain boilerplate code only - no compiler specific
//  code unless it is unavoidable - no changes unless unavoidable.

#ifndef QSBOOST_CONFIG_SUFFIX_HPP
#define QSBOOST_CONFIG_SUFFIX_HPP

#if defined(__GNUC__) && (__GNUC__ >= 4)
//
// Some GCC-4.x versions issue warnings even when __extension__ is used,
// so use this as a workaround:
//
#pragma GCC system_header
#endif

//
// ensure that visibility macros are always defined, thus symplifying use
//
#ifndef QSBOOST_SYMBOL_EXPORT
# define QSBOOST_SYMBOL_EXPORT
#endif
#ifndef QSBOOST_SYMBOL_IMPORT
# define QSBOOST_SYMBOL_IMPORT
#endif
#ifndef QSBOOST_SYMBOL_VISIBLE
# define QSBOOST_SYMBOL_VISIBLE
#endif

//
// look for long long by looking for the appropriate macros in <limits.h>.
// Note that we use limits.h rather than climits for maximal portability,
// remember that since these just declare a bunch of macros, there should be
// no namespace issues from this.
//
#if !defined(QSBOOST_HAS_LONG_LONG) && !defined(QSBOOST_NO_LONG_LONG)                                              \
   && !defined(QSBOOST_MSVC) && !defined(__BORLANDC__)
# include <limits.h>
# if (defined(ULLONG_MAX) || defined(ULONG_LONG_MAX) || defined(ULONGLONG_MAX))
#   define QSBOOST_HAS_LONG_LONG
# else
#   define QSBOOST_NO_LONG_LONG
# endif
#endif

// GCC 3.x will clean up all of those nasty macro definitions that
// BOOST_NO_CTYPE_FUNCTIONS is intended to help work around, so undefine
// it under GCC 3.x.
#if defined(__GNUC__) && (__GNUC__ >= 3) && defined(QSBOOST_NO_CTYPE_FUNCTIONS)
#  undef QSBOOST_NO_CTYPE_FUNCTIONS
#endif

//
// Assume any extensions are in namespace std:: unless stated otherwise:
//
#  ifndef QSBOOST_STD_EXTENSION_NAMESPACE
#    define QSBOOST_STD_EXTENSION_NAMESPACE std
#  endif

//
// If cv-qualified specializations are not allowed, then neither are cv-void ones:
//
#  if defined(QSBOOST_NO_CV_SPECIALIZATIONS) \
      && !defined(QSBOOST_NO_CV_VOID_SPECIALIZATIONS)
#     define QSBOOST_NO_CV_VOID_SPECIALIZATIONS
#  endif

//
// If there is no numeric_limits template, then it can't have any compile time
// constants either!
//
#  if defined(QSBOOST_NO_LIMITS) \
      && !defined(QSBOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS)
#     define QSBOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
#     define QSBOOST_NO_MS_INT64_NUMERIC_LIMITS
#     define QSBOOST_NO_LONG_LONG_NUMERIC_LIMITS
#  endif

//
// if there is no long long then there is no specialisation
// for numeric_limits<long long> either:
//
#if !defined(QSBOOST_HAS_LONG_LONG) && !defined(QSBOOST_NO_LONG_LONG_NUMERIC_LIMITS)
#  define QSBOOST_NO_LONG_LONG_NUMERIC_LIMITS
#endif

//
// if there is no __int64 then there is no specialisation
// for numeric_limits<__int64> either:
//
#if !defined(QSBOOST_HAS_MS_INT64) && !defined(QSBOOST_NO_MS_INT64_NUMERIC_LIMITS)
#  define QSBOOST_NO_MS_INT64_NUMERIC_LIMITS
#endif

//
// if member templates are supported then so is the
// VC6 subset of member templates:
//
#  if !defined(QSBOOST_NO_MEMBER_TEMPLATES) \
       && !defined(QSBOOST_MSVC6_MEMBER_TEMPLATES)
#     define QSBOOST_MSVC6_MEMBER_TEMPLATES
#  endif

//
// Without partial specialization, can't test for partial specialisation bugs:
//
#  if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
      && !defined(QSBOOST_BCB_PARTIAL_SPECIALIZATION_BUG)
#     define QSBOOST_BCB_PARTIAL_SPECIALIZATION_BUG
#  endif

//
// Without partial specialization, we can't have array-type partial specialisations:
//
#  if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
      && !defined(QSBOOST_NO_ARRAY_TYPE_SPECIALIZATIONS)
#     define QSBOOST_NO_ARRAY_TYPE_SPECIALIZATIONS
#  endif

//
// Without partial specialization, std::iterator_traits can't work:
//
#  if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
      && !defined(QSBOOST_NO_STD_ITERATOR_TRAITS)
#     define QSBOOST_NO_STD_ITERATOR_TRAITS
#  endif

//
// Without partial specialization, partial
// specialization with default args won't work either:
//
#  if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
      && !defined(QSBOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS)
#     define QSBOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS
#  endif

//
// Without member template support, we can't have template constructors
// in the standard library either:
//
#  if defined(QSBOOST_NO_MEMBER_TEMPLATES) \
      && !defined(QSBOOST_MSVC6_MEMBER_TEMPLATES) \
      && !defined(QSBOOST_NO_TEMPLATED_ITERATOR_CONSTRUCTORS)
#     define QSBOOST_NO_TEMPLATED_ITERATOR_CONSTRUCTORS
#  endif

//
// Without member template support, we can't have a conforming
// std::allocator template either:
//
#  if defined(QSBOOST_NO_MEMBER_TEMPLATES) \
      && !defined(QSBOOST_MSVC6_MEMBER_TEMPLATES) \
      && !defined(QSBOOST_NO_STD_ALLOCATOR)
#     define QSBOOST_NO_STD_ALLOCATOR
#  endif

//
// without ADL support then using declarations will break ADL as well:
//
#if defined(QSBOOST_NO_ARGUMENT_DEPENDENT_LOOKUP) && !defined(QSBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL)
#  define QSBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#endif

//
// Without typeid support we have no dynamic RTTI either:
//
#if defined(QSBOOST_NO_TYPEID) && !defined(QSBOOST_NO_RTTI)
#  define QSBOOST_NO_RTTI
#endif

//
// If we have a standard allocator, then we have a partial one as well:
//
#if !defined(QSBOOST_NO_STD_ALLOCATOR)
#  define QSBOOST_HAS_PARTIAL_STD_ALLOCATOR
#endif

//
// We can't have a working std::use_facet if there is no std::locale:
//
#  if defined(QSBOOST_NO_STD_LOCALE) && !defined(QSBOOST_NO_STD_USE_FACET)
#     define QSBOOST_NO_STD_USE_FACET
#  endif

//
// We can't have a std::messages facet if there is no std::locale:
//
#  if defined(QSBOOST_NO_STD_LOCALE) && !defined(QSBOOST_NO_STD_MESSAGES)
#     define QSBOOST_NO_STD_MESSAGES
#  endif

//
// We can't have a working std::wstreambuf if there is no std::locale:
//
#  if defined(QSBOOST_NO_STD_LOCALE) && !defined(QSBOOST_NO_STD_WSTREAMBUF)
#     define QSBOOST_NO_STD_WSTREAMBUF
#  endif

//
// We can't have a <cwctype> if there is no <cwchar>:
//
#  if defined(QSBOOST_NO_CWCHAR) && !defined(QSBOOST_NO_CWCTYPE)
#     define QSBOOST_NO_CWCTYPE
#  endif

//
// We can't have a swprintf if there is no <cwchar>:
//
#  if defined(QSBOOST_NO_CWCHAR) && !defined(QSBOOST_NO_SWPRINTF)
#     define QSBOOST_NO_SWPRINTF
#  endif

//
// If Win32 support is turned off, then we must turn off
// threading support also, unless there is some other
// thread API enabled:
//
#if defined(QSBOOST_DISABLE_WIN32) && defined(_WIN32) \
   && !defined(QSBOOST_DISABLE_THREADS) && !defined(QSBOOST_HAS_PTHREADS)
#  define QSBOOST_DISABLE_THREADS
#endif

//
// Turn on threading support if the compiler thinks that it's in
// multithreaded mode.  We put this here because there are only a
// limited number of macros that identify this (if there's any missing
// from here then add to the appropriate compiler section):
//
#if (defined(__MT__) || defined(_MT) || defined(_REENTRANT) \
    || defined(_PTHREADS) || defined(__APPLE__) || defined(__DragonFly__)) \
    && !defined(QSBOOST_HAS_THREADS)
#  define QSBOOST_HAS_THREADS
#endif

//
// Turn threading support off if BOOST_DISABLE_THREADS is defined:
//
#if defined(QSBOOST_DISABLE_THREADS) && defined(QSBOOST_HAS_THREADS)
#  undef QSBOOST_HAS_THREADS
#endif

//
// Turn threading support off if we don't recognise the threading API:
//
#if defined(QSBOOST_HAS_THREADS) && !defined(QSBOOST_HAS_PTHREADS)\
      && !defined(QSBOOST_HAS_WINTHREADS) && !defined(QSBOOST_HAS_BETHREADS)\
      && !defined(QSBOOST_HAS_MPTASKS)
#  undef QSBOOST_HAS_THREADS
#endif

//
// Turn threading detail macros off if we don't (want to) use threading
//
#ifndef QSBOOST_HAS_THREADS
#  undef QSBOOST_HAS_PTHREADS
#  undef QSBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE
#  undef QSBOOST_HAS_PTHREAD_YIELD
#  undef QSBOOST_HAS_PTHREAD_DELAY_NP
#  undef QSBOOST_HAS_WINTHREADS
#  undef QSBOOST_HAS_BETHREADS
#  undef QSBOOST_HAS_MPTASKS
#endif

//
// If the compiler claims to be C99 conformant, then it had better
// have a <stdint.h>:
//
#  if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#     define QSBOOST_HAS_STDINT_H
#     ifndef QSBOOST_HAS_LOG1P
#        define QSBOOST_HAS_LOG1P
#     endif
#     ifndef QSBOOST_HAS_EXPM1
#        define QSBOOST_HAS_EXPM1
#     endif
#  endif

//
// Define BOOST_NO_SLIST and BOOST_NO_HASH if required.
// Note that this is for backwards compatibility only.
//
#  if !defined(QSBOOST_HAS_SLIST) && !defined(QSBOOST_NO_SLIST)
#     define QSBOOST_NO_SLIST
#  endif

#  if !defined(QSBOOST_HAS_HASH) && !defined(QSBOOST_NO_HASH)
#     define QSBOOST_NO_HASH
#  endif

//
// Set BOOST_SLIST_HEADER if not set already:
//
#if defined(QSBOOST_HAS_SLIST) && !defined(QSBOOST_SLIST_HEADER)
#  define QSBOOST_SLIST_HEADER <slist>
#endif

//
// Set BOOST_HASH_SET_HEADER if not set already:
//
#if defined(QSBOOST_HAS_HASH) && !defined(QSBOOST_HASH_SET_HEADER)
#  define QSBOOST_HASH_SET_HEADER <hash_set>
#endif

//
// Set BOOST_HASH_MAP_HEADER if not set already:
//
#if defined(QSBOOST_HAS_HASH) && !defined(QSBOOST_HASH_MAP_HEADER)
#  define QSBOOST_HASH_MAP_HEADER <hash_map>
#endif

//  BOOST_HAS_ABI_HEADERS
//  This macro gets set if we have headers that fix the ABI,
//  and prevent ODR violations when linking to external libraries:
#if defined(QSBOOST_ABI_PREFIX) && defined(QSBOOST_ABI_SUFFIX) && !defined(QSBOOST_HAS_ABI_HEADERS)
#  define QSBOOST_HAS_ABI_HEADERS
#endif

#if defined(QSBOOST_HAS_ABI_HEADERS) && defined(QSBOOST_DISABLE_ABI_HEADERS)
#  undef QSBOOST_HAS_ABI_HEADERS
#endif

//  BOOST_NO_STDC_NAMESPACE workaround  --------------------------------------//
//  Because std::size_t usage is so common, even in boost headers which do not
//  otherwise use the C library, the <cstddef> workaround is included here so
//  that ugly workaround code need not appear in many other boost headers.
//  NOTE WELL: This is a workaround for non-conforming compilers; <cstddef>
//  must still be #included in the usual places so that <cstddef> inclusion
//  works as expected with standard conforming compilers.  The resulting
//  double inclusion of <cstddef> is harmless.

# if defined(QSBOOST_NO_STDC_NAMESPACE) && defined(__cplusplus)
#   include <cstddef>
    namespace std { using ::ptrdiff_t; using ::size_t; }
# endif

//  Workaround for the unfortunate min/max macros defined by some platform headers

#define QSBOOST_PREVENT_MACRO_SUBSTITUTION

#ifndef QSBOOST_USING_STD_MIN
#  define QSBOOST_USING_STD_MIN() using std::min
#endif

#ifndef QSBOOST_USING_STD_MAX
#  define QSBOOST_USING_STD_MAX() using std::max
#endif

//  BOOST_NO_STD_MIN_MAX workaround  -----------------------------------------//

#  if defined(QSBOOST_NO_STD_MIN_MAX) && defined(__cplusplus)

namespace std {
  template <class _Tp>
  inline const _Tp& min QSBOOST_PREVENT_MACRO_SUBSTITUTION (const _Tp& __a, const _Tp& __b) {
    return __b < __a ? __b : __a;
  }
  template <class _Tp>
  inline const _Tp& max QSBOOST_PREVENT_MACRO_SUBSTITUTION (const _Tp& __a, const _Tp& __b) {
    return  __a < __b ? __b : __a;
  }
}

#  endif

// BOOST_STATIC_CONSTANT workaround --------------------------------------- //
// On compilers which don't allow in-class initialization of static integral
// constant members, we must use enums as a workaround if we want the constants
// to be available at compile-time. This macro gives us a convenient way to
// declare such constants.

#  ifdef QSBOOST_NO_INCLASS_MEMBER_INITIALIZATION
#       define QSBOOST_STATIC_CONSTANT(type, assignment) enum { assignment }
#  else
#     define QSBOOST_STATIC_CONSTANT(type, assignment) static const type assignment
#  endif

// BOOST_USE_FACET / HAS_FACET workaround ----------------------------------//
// When the standard library does not have a conforming std::use_facet there
// are various workarounds available, but they differ from library to library.
// The same problem occurs with has_facet.
// These macros provide a consistent way to access a locale's facets.
// Usage:
//    replace
//       std::use_facet<Type>(loc);
//    with
//       BOOST_USE_FACET(Type, loc);
//    Note do not add a std:: prefix to the front of BOOST_USE_FACET!
//  Use for BOOST_HAS_FACET is analogous.

#if defined(QSBOOST_NO_STD_USE_FACET)
#  ifdef QSBOOST_HAS_TWO_ARG_USE_FACET
#     define QSBOOST_USE_FACET(Type, loc) std::use_facet(loc, static_cast<Type*>(0))
#     define QSBOOST_HAS_FACET(Type, loc) std::has_facet(loc, static_cast<Type*>(0))
#  elif defined(QSBOOST_HAS_MACRO_USE_FACET)
#     define QSBOOST_USE_FACET(Type, loc) std::_USE(loc, Type)
#     define QSBOOST_HAS_FACET(Type, loc) std::_HAS(loc, Type)
#  elif defined(QSBOOST_HAS_STLP_USE_FACET)
#     define QSBOOST_USE_FACET(Type, loc) (*std::_Use_facet<Type >(loc))
#     define QSBOOST_HAS_FACET(Type, loc) std::has_facet< Type >(loc)
#  endif
#else
#  define QSBOOST_USE_FACET(Type, loc) std::use_facet< Type >(loc)
#  define QSBOOST_HAS_FACET(Type, loc) std::has_facet< Type >(loc)
#endif

// BOOST_NESTED_TEMPLATE workaround ------------------------------------------//
// Member templates are supported by some compilers even though they can't use
// the A::template member<U> syntax, as a workaround replace:
//
// typedef typename A::template rebind<U> binder;
//
// with:
//
// typedef typename A::BOOST_NESTED_TEMPLATE rebind<U> binder;

#ifndef QSBOOST_NO_MEMBER_TEMPLATE_KEYWORD
#  define QSBOOST_NESTED_TEMPLATE template
#else
#  define QSBOOST_NESTED_TEMPLATE
#endif

// BOOST_UNREACHABLE_RETURN(x) workaround -------------------------------------//
// Normally evaluates to nothing, unless BOOST_NO_UNREACHABLE_RETURN_DETECTION
// is defined, in which case it evaluates to return x; Use when you have a return
// statement that can never be reached.

#ifndef QSBOOST_UNREACHABLE_RETURN
#  ifdef QSBOOST_NO_UNREACHABLE_RETURN_DETECTION
#     define QSBOOST_UNREACHABLE_RETURN(x) return x;
#  else
#     define QSBOOST_UNREACHABLE_RETURN(x)
#  endif
#endif

// BOOST_DEDUCED_TYPENAME workaround ------------------------------------------//
//
// Some compilers don't support the use of `typename' for dependent
// types in deduced contexts, e.g.
//
//     template <class T> void f(T, typename T::type);
//                                  ^^^^^^^^
// Replace these declarations with:
//
//     template <class T> void f(T, BOOST_DEDUCED_TYPENAME T::type);

#ifndef QSBOOST_NO_DEDUCED_TYPENAME
#  define QSBOOST_DEDUCED_TYPENAME typename
#else
#  define QSBOOST_DEDUCED_TYPENAME
#endif

#ifndef QSBOOST_NO_TYPENAME_WITH_CTOR
#  define QSBOOST_CTOR_TYPENAME typename
#else
#  define QSBOOST_CTOR_TYPENAME
#endif

// long long workaround ------------------------------------------//
// On gcc (and maybe other compilers?) long long is alway supported
// but it's use may generate either warnings (with -ansi), or errors
// (with -pedantic -ansi) unless it's use is prefixed by __extension__
//
#if defined(QSBOOST_HAS_LONG_LONG) && defined(__cplusplus)
namespace qsboost{
#  ifdef __GNUC__
   __extension__ typedef long long long_long_type;
   __extension__ typedef unsigned long long ulong_long_type;
#  else
   typedef long long long_long_type;
   typedef unsigned long long ulong_long_type;
#  endif
}
#endif
// same again for __int128:
#if defined(QSBOOST_HAS_INT128) && defined(__cplusplus)
namespace qsboost{
#  ifdef __GNUC__
   __extension__ typedef __int128 int128_type;
   __extension__ typedef unsigned __int128 uint128_type;
#  else
   typedef __int128 int128_type;
   typedef unsigned __int128 uint128_type;
#  endif
}
#endif
// same again for __float128:
#if defined(QSBOOST_HAS_FLOAT128) && defined(__cplusplus)
namespace qsboost {
#  ifdef __GNUC__
   __extension__ typedef __float128 float128_type;
#  else
   typedef __float128 float128_type;
#  endif
}
#endif

// BOOST_[APPEND_]EXPLICIT_TEMPLATE_[NON_]TYPE macros --------------------------//

// These macros are obsolete. Port away and remove.

#  define QSBOOST_EXPLICIT_TEMPLATE_TYPE(t)
#  define QSBOOST_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define QSBOOST_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define QSBOOST_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

#  define QSBOOST_APPEND_EXPLICIT_TEMPLATE_TYPE(t)
#  define QSBOOST_APPEND_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define QSBOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define QSBOOST_APPEND_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

// When BOOST_NO_STD_TYPEINFO is defined, we can just import
// the global definition into std namespace:
#if defined(QSBOOST_NO_STD_TYPEINFO) && defined(__cplusplus)
#include <typeinfo>
namespace std{ using ::type_info; }
#endif

// ---------------------------------------------------------------------------//

//
// Helper macro BOOST_STRINGIZE:
// Converts the parameter X to a string after macro replacement
// on X has been performed.
//
#define QSBOOST_STRINGIZE(X) QSBOOST_DO_STRINGIZE(X)
#define QSBOOST_DO_STRINGIZE(X) #X

//
// Helper macro BOOST_JOIN:
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in BOOST_DO_JOIN2 but does in BOOST_DO_JOIN.
//
#define QSBOOST_JOIN( X, Y ) QSBOOST_DO_JOIN( X, Y )
#define QSBOOST_DO_JOIN( X, Y ) QSBOOST_DO_JOIN2(X,Y)
#define QSBOOST_DO_JOIN2( X, Y ) X##Y

//
// Set some default values for compiler/library/platform names.
// These are for debugging config setup only:
//
#  ifndef QSBOOST_COMPILER
#     define QSBOOST_COMPILER "Unknown ISO C++ Compiler"
#  endif
#  ifndef QSBOOST_STDLIB
#     define QSBOOST_STDLIB "Unknown ISO standard library"
#  endif
#  ifndef QSBOOST_PLATFORM
#     if defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) \
         || defined(_POSIX_SOURCE)
#        define QSBOOST_PLATFORM "Generic Unix"
#     else
#        define QSBOOST_PLATFORM "Unknown"
#     endif
#  endif

//
// Set some default values GPU support
//
#  ifndef QSBOOST_GPU_ENABLED
#  define QSBOOST_GPU_ENABLED
#  endif

// BOOST_FORCEINLINE ---------------------------------------------//
// Macro to use in place of 'inline' to force a function to be inline
#if !defined(QSBOOST_FORCEINLINE)
#  if defined(_MSC_VER)
#    define QSBOOST_FORCEINLINE __forceinline
#  elif defined(__GNUC__) && __GNUC__ > 3
     // Clang also defines __GNUC__ (as 4)
#    define QSBOOST_FORCEINLINE inline __attribute__ ((__always_inline__))
#  else
#    define QSBOOST_FORCEINLINE inline
#  endif
#endif

// BOOST_NOINLINE ---------------------------------------------//
// Macro to use in place of 'inline' to prevent a function to be inlined
#if !defined(QSBOOST_NOINLINE)
#  if defined(_MSC_VER)
#    define QSBOOST_NOINLINE __declspec(noinline)
#  elif defined(__GNUC__) && __GNUC__ > 3
     // Clang also defines __GNUC__ (as 4)
#    if defined(__CUDACC__)
       // nvcc doesn't always parse __noinline__, 
       // see: https://svn.boost.org/trac/boost/ticket/9392
#      define QSBOOST_NOINLINE __attribute__ ((noinline))
#    else
#      define QSBOOST_NOINLINE __attribute__ ((__noinline__))
#    endif
#  else
#    define QSBOOST_NOINLINE
#  endif
#endif

// BOOST_NORETURN ---------------------------------------------//
// Macro to use before a function declaration/definition to designate
// the function as not returning normally (i.e. with a return statement
// or by leaving the function scope, if the function return type is void).
#if !defined(QSBOOST_NORETURN)
#  if defined(_MSC_VER)
#    define QSBOOST_NORETURN __declspec(noreturn)
#  elif defined(__GNUC__)
#    define QSBOOST_NORETURN __attribute__ ((__noreturn__))
#  else
#    define QSBOOST_NO_NORETURN
#    define QSBOOST_NORETURN
#  endif
#endif

// Branch prediction hints
// These macros are intended to wrap conditional expressions that yield true or false
//
//  if (BOOST_LIKELY(var == 10))
//  {
//     // the most probable code here
//  }
//
#if !defined(QSBOOST_LIKELY)
#  define QSBOOST_LIKELY(x) x
#endif
#if !defined(QSBOOST_UNLIKELY)
#  define QSBOOST_UNLIKELY(x) x
#endif

// Type and data alignment specification
//
#if !defined(QSBOOST_NO_CXX11_ALIGNAS)
#  define QSBOOST_ALIGNMENT(x) alignas(x)
#elif defined(_MSC_VER)
#  define QSBOOST_ALIGNMENT(x) __declspec(align(x))
#elif defined(__GNUC__)
#  define QSBOOST_ALIGNMENT(x) __attribute__ ((__aligned__(x)))
#else
#  define QSBOOST_NO_ALIGNMENT
#  define QSBOOST_ALIGNMENT(x)
#endif

// Lack of non-public defaulted functions is implied by the lack of any defaulted functions
#if !defined(QSBOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS) && defined(QSBOOST_NO_CXX11_DEFAULTED_FUNCTIONS)
#  define QSBOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS
#endif

// Defaulted and deleted function declaration helpers
// These macros are intended to be inside a class definition.
// BOOST_DEFAULTED_FUNCTION accepts the function declaration and its
// body, which will be used if the compiler doesn't support defaulted functions.
// BOOST_DELETED_FUNCTION only accepts the function declaration. It
// will expand to a private function declaration, if the compiler doesn't support
// deleted functions. Because of this it is recommended to use BOOST_DELETED_FUNCTION
// in the end of the class definition.
//
//  class my_class
//  {
//  public:
//      // Default-constructible
//      BOOST_DEFAULTED_FUNCTION(my_class(), {})
//      // Copying prohibited
//      BOOST_DELETED_FUNCTION(my_class(my_class const&))
//      BOOST_DELETED_FUNCTION(my_class& operator= (my_class const&))
//  };
//
#if !(defined(QSBOOST_NO_CXX11_DEFAULTED_FUNCTIONS) || defined(QSBOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS))
#   define QSBOOST_DEFAULTED_FUNCTION(fun, body) fun = default;
#else
#   define QSBOOST_DEFAULTED_FUNCTION(fun, body) fun body
#endif

#if !defined(QSBOOST_NO_CXX11_DELETED_FUNCTIONS)
#   define QSBOOST_DELETED_FUNCTION(fun) fun = delete;
#else
#   define QSBOOST_DELETED_FUNCTION(fun) private: fun;
#endif

//
// Set BOOST_NO_DECLTYPE_N3276 when BOOST_NO_DECLTYPE is defined
//
#if defined(QSBOOST_NO_CXX11_DECLTYPE) && !defined(QSBOOST_NO_CXX11_DECLTYPE_N3276)
#define QSBOOST_NO_CXX11_DECLTYPE_N3276 QSBOOST_NO_CXX11_DECLTYPE
#endif

//  -------------------- Deprecated macros for 1.50 ---------------------------
//  These will go away in a future release

//  Use BOOST_NO_CXX11_HDR_UNORDERED_SET or BOOST_NO_CXX11_HDR_UNORDERED_MAP
//           instead of BOOST_NO_STD_UNORDERED
#if defined(QSBOOST_NO_CXX11_HDR_UNORDERED_MAP) || defined (QSBOOST_NO_CXX11_HDR_UNORDERED_SET)
# ifndef QSBOOST_NO_CXX11_STD_UNORDERED
#  define QSBOOST_NO_CXX11_STD_UNORDERED
# endif
#endif

//  Use BOOST_NO_CXX11_HDR_INITIALIZER_LIST instead of BOOST_NO_INITIALIZER_LISTS
#if defined(QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST) && !defined(QSBOOST_NO_INITIALIZER_LISTS)
#  define QSBOOST_NO_INITIALIZER_LISTS
#endif

//  Use BOOST_NO_CXX11_HDR_ARRAY instead of BOOST_NO_0X_HDR_ARRAY
#if defined(QSBOOST_NO_CXX11_HDR_ARRAY) && !defined(QSBOOST_NO_0X_HDR_ARRAY)
#  define QSBOOST_NO_0X_HDR_ARRAY
#endif
//  Use BOOST_NO_CXX11_HDR_CHRONO instead of BOOST_NO_0X_HDR_CHRONO
#if defined(QSBOOST_NO_CXX11_HDR_CHRONO) && !defined(QSBOOST_NO_0X_HDR_CHRONO)
#  define QSBOOST_NO_0X_HDR_CHRONO
#endif
//  Use BOOST_NO_CXX11_HDR_CODECVT instead of BOOST_NO_0X_HDR_CODECVT
#if defined(QSBOOST_NO_CXX11_HDR_CODECVT) && !defined(QSBOOST_NO_0X_HDR_CODECVT)
#  define QSBOOST_NO_0X_HDR_CODECVT
#endif
//  Use BOOST_NO_CXX11_HDR_CONDITION_VARIABLE instead of BOOST_NO_0X_HDR_CONDITION_VARIABLE
#if defined(QSBOOST_NO_CXX11_HDR_CONDITION_VARIABLE) && !defined(QSBOOST_NO_0X_HDR_CONDITION_VARIABLE)
#  define QSBOOST_NO_0X_HDR_CONDITION_VARIABLE
#endif
//  Use BOOST_NO_CXX11_HDR_FORWARD_LIST instead of BOOST_NO_0X_HDR_FORWARD_LIST
#if defined(QSBOOST_NO_CXX11_HDR_FORWARD_LIST) && !defined(QSBOOST_NO_0X_HDR_FORWARD_LIST)
#  define QSBOOST_NO_0X_HDR_FORWARD_LIST
#endif
//  Use BOOST_NO_CXX11_HDR_FUTURE instead of BOOST_NO_0X_HDR_FUTURE
#if defined(QSBOOST_NO_CXX11_HDR_FUTURE) && !defined(QSBOOST_NO_0X_HDR_FUTURE)
#  define QSBOOST_NO_0X_HDR_FUTURE
#endif

//  Use BOOST_NO_CXX11_HDR_INITIALIZER_LIST
//  instead of BOOST_NO_0X_HDR_INITIALIZER_LIST or BOOST_NO_INITIALIZER_LISTS
#ifdef QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST
# ifndef QSBOOST_NO_0X_HDR_INITIALIZER_LIST
#  define QSBOOST_NO_0X_HDR_INITIALIZER_LIST
# endif
# ifndef QSBOOST_NO_INITIALIZER_LISTS
#  define QSBOOST_NO_INITIALIZER_LISTS
# endif
#endif

//  Use BOOST_NO_CXX11_HDR_MUTEX instead of BOOST_NO_0X_HDR_MUTEX
#if defined(QSBOOST_NO_CXX11_HDR_MUTEX) && !defined(QSBOOST_NO_0X_HDR_MUTEX)
#  define QSBOOST_NO_0X_HDR_MUTEX
#endif
//  Use BOOST_NO_CXX11_HDR_RANDOM instead of BOOST_NO_0X_HDR_RANDOM
#if defined(QSBOOST_NO_CXX11_HDR_RANDOM) && !defined(QSBOOST_NO_0X_HDR_RANDOM)
#  define QSBOOST_NO_0X_HDR_RANDOM
#endif
//  Use BOOST_NO_CXX11_HDR_RATIO instead of BOOST_NO_0X_HDR_RATIO
#if defined(QSBOOST_NO_CXX11_HDR_RATIO) && !defined(QSBOOST_NO_0X_HDR_RATIO)
#  define QSBOOST_NO_0X_HDR_RATIO
#endif
//  Use BOOST_NO_CXX11_HDR_REGEX instead of BOOST_NO_0X_HDR_REGEX
#if defined(QSBOOST_NO_CXX11_HDR_REGEX) && !defined(QSBOOST_NO_0X_HDR_REGEX)
#  define QSBOOST_NO_0X_HDR_REGEX
#endif
//  Use BOOST_NO_CXX11_HDR_SYSTEM_ERROR instead of BOOST_NO_0X_HDR_SYSTEM_ERROR
#if defined(QSBOOST_NO_CXX11_HDR_SYSTEM_ERROR) && !defined(QSBOOST_NO_0X_HDR_SYSTEM_ERROR)
#  define QSBOOST_NO_0X_HDR_SYSTEM_ERROR
#endif
//  Use BOOST_NO_CXX11_HDR_THREAD instead of BOOST_NO_0X_HDR_THREAD
#if defined(QSBOOST_NO_CXX11_HDR_THREAD) && !defined(QSBOOST_NO_0X_HDR_THREAD)
#  define QSBOOST_NO_0X_HDR_THREAD
#endif
//  Use BOOST_NO_CXX11_HDR_TUPLE instead of BOOST_NO_0X_HDR_TUPLE
#if defined(QSBOOST_NO_CXX11_HDR_TUPLE) && !defined(QSBOOST_NO_0X_HDR_TUPLE)
#  define QSBOOST_NO_0X_HDR_TUPLE
#endif
//  Use BOOST_NO_CXX11_HDR_TYPE_TRAITS instead of BOOST_NO_0X_HDR_TYPE_TRAITS
#if defined(QSBOOST_NO_CXX11_HDR_TYPE_TRAITS) && !defined(QSBOOST_NO_0X_HDR_TYPE_TRAITS)
#  define QSBOOST_NO_0X_HDR_TYPE_TRAITS
#endif
//  Use BOOST_NO_CXX11_HDR_TYPEINDEX instead of BOOST_NO_0X_HDR_TYPEINDEX
#if defined(QSBOOST_NO_CXX11_HDR_TYPEINDEX) && !defined(QSBOOST_NO_0X_HDR_TYPEINDEX)
#  define QSBOOST_NO_0X_HDR_TYPEINDEX
#endif
//  Use BOOST_NO_CXX11_HDR_UNORDERED_MAP instead of BOOST_NO_0X_HDR_UNORDERED_MAP
#if defined(QSBOOST_NO_CXX11_HDR_UNORDERED_MAP) && !defined(QSBOOST_NO_0X_HDR_UNORDERED_MAP)
#  define QSBOOST_NO_0X_HDR_UNORDERED_MAP
#endif
//  Use BOOST_NO_CXX11_HDR_UNORDERED_SET instead of BOOST_NO_0X_HDR_UNORDERED_SET
#if defined(QSBOOST_NO_CXX11_HDR_UNORDERED_SET) && !defined(QSBOOST_NO_0X_HDR_UNORDERED_SET)
#  define QSBOOST_NO_0X_HDR_UNORDERED_SET
#endif

//  ------------------ End of deprecated macros for 1.50 ---------------------------

//  -------------------- Deprecated macros for 1.51 ---------------------------
//  These will go away in a future release

//  Use     BOOST_NO_CXX11_AUTO_DECLARATIONS instead of   BOOST_NO_AUTO_DECLARATIONS
#if defined(QSBOOST_NO_CXX11_AUTO_DECLARATIONS) && !defined(QSBOOST_NO_AUTO_DECLARATIONS)
#  define QSBOOST_NO_AUTO_DECLARATIONS
#endif
//  Use     BOOST_NO_CXX11_AUTO_MULTIDECLARATIONS instead of   BOOST_NO_AUTO_MULTIDECLARATIONS
#if defined(QSBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS) && !defined(QSBOOST_NO_AUTO_MULTIDECLARATIONS)
#  define QSBOOST_NO_AUTO_MULTIDECLARATIONS
#endif
//  Use     BOOST_NO_CXX11_CHAR16_T instead of   BOOST_NO_CHAR16_T
#if defined(QSBOOST_NO_CXX11_CHAR16_T) && !defined(QSBOOST_NO_CHAR16_T)
#  define QSBOOST_NO_CHAR16_T
#endif
//  Use     BOOST_NO_CXX11_CHAR32_T instead of   BOOST_NO_CHAR32_T
#if defined(QSBOOST_NO_CXX11_CHAR32_T) && !defined(QSBOOST_NO_CHAR32_T)
#  define QSBOOST_NO_CHAR32_T
#endif
//  Use     BOOST_NO_CXX11_TEMPLATE_ALIASES instead of   BOOST_NO_TEMPLATE_ALIASES
#if defined(QSBOOST_NO_CXX11_TEMPLATE_ALIASES) && !defined(QSBOOST_NO_TEMPLATE_ALIASES)
#  define QSBOOST_NO_TEMPLATE_ALIASES
#endif
//  Use     BOOST_NO_CXX11_CONSTEXPR instead of   BOOST_NO_CONSTEXPR
#if defined(QSBOOST_NO_CXX11_CONSTEXPR) && !defined(QSBOOST_NO_CONSTEXPR)
#  define QSBOOST_NO_CONSTEXPR
#endif
//  Use     BOOST_NO_CXX11_DECLTYPE_N3276 instead of   BOOST_NO_DECLTYPE_N3276
#if defined(QSBOOST_NO_CXX11_DECLTYPE_N3276) && !defined(QSBOOST_NO_DECLTYPE_N3276)
#  define QSBOOST_NO_DECLTYPE_N3276
#endif
//  Use     BOOST_NO_CXX11_DECLTYPE instead of   BOOST_NO_DECLTYPE
#if defined(QSBOOST_NO_CXX11_DECLTYPE) && !defined(QSBOOST_NO_DECLTYPE)
#  define QSBOOST_NO_DECLTYPE
#endif
//  Use     BOOST_NO_CXX11_DEFAULTED_FUNCTIONS instead of   BOOST_NO_DEFAULTED_FUNCTIONS
#if defined(QSBOOST_NO_CXX11_DEFAULTED_FUNCTIONS) && !defined(QSBOOST_NO_DEFAULTED_FUNCTIONS)
#  define QSBOOST_NO_DEFAULTED_FUNCTIONS
#endif
//  Use     BOOST_NO_CXX11_DELETED_FUNCTIONS instead of   BOOST_NO_DELETED_FUNCTIONS
#if defined(QSBOOST_NO_CXX11_DELETED_FUNCTIONS) && !defined(QSBOOST_NO_DELETED_FUNCTIONS)
#  define QSBOOST_NO_DELETED_FUNCTIONS
#endif
//  Use     BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS instead of   BOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#if defined(QSBOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS) && !defined(QSBOOST_NO_EXPLICIT_CONVERSION_OPERATORS)
#  define QSBOOST_NO_EXPLICIT_CONVERSION_OPERATORS
#endif
//  Use     BOOST_NO_CXX11_EXTERN_TEMPLATE instead of   BOOST_NO_EXTERN_TEMPLATE
#if defined(QSBOOST_NO_CXX11_EXTERN_TEMPLATE) && !defined(QSBOOST_NO_EXTERN_TEMPLATE)
#  define QSBOOST_NO_EXTERN_TEMPLATE
#endif
//  Use     BOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS instead of   BOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#if defined(QSBOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS) && !defined(QSBOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS)
#  define QSBOOST_NO_FUNCTION_TEMPLATE_DEFAULT_ARGS
#endif
//  Use     BOOST_NO_CXX11_LAMBDAS instead of   BOOST_NO_LAMBDAS
#if defined(QSBOOST_NO_CXX11_LAMBDAS) && !defined(QSBOOST_NO_LAMBDAS)
#  define QSBOOST_NO_LAMBDAS
#endif
//  Use     BOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS instead of   BOOST_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS
#if defined(QSBOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS) && !defined(QSBOOST_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS)
#  define QSBOOST_NO_LOCAL_CLASS_TEMPLATE_PARAMETERS
#endif
//  Use     BOOST_NO_CXX11_NOEXCEPT instead of   BOOST_NO_NOEXCEPT
#if defined(QSBOOST_NO_CXX11_NOEXCEPT) && !defined(QSBOOST_NO_NOEXCEPT)
#  define QSBOOST_NO_NOEXCEPT
#endif
//  Use     BOOST_NO_CXX11_NULLPTR instead of   BOOST_NO_NULLPTR
#if defined(QSBOOST_NO_CXX11_NULLPTR) && !defined(QSBOOST_NO_NULLPTR)
#  define QSBOOST_NO_NULLPTR
#endif
//  Use     BOOST_NO_CXX11_RAW_LITERALS instead of   BOOST_NO_RAW_LITERALS
#if defined(QSBOOST_NO_CXX11_RAW_LITERALS) && !defined(QSBOOST_NO_RAW_LITERALS)
#  define QSBOOST_NO_RAW_LITERALS
#endif
//  Use     BOOST_NO_CXX11_RVALUE_REFERENCES instead of   BOOST_NO_RVALUE_REFERENCES
#if defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(QSBOOST_NO_RVALUE_REFERENCES)
#  define QSBOOST_NO_RVALUE_REFERENCES
#endif
//  Use     BOOST_NO_CXX11_SCOPED_ENUMS instead of   BOOST_NO_SCOPED_ENUMS
#if defined(QSBOOST_NO_CXX11_SCOPED_ENUMS) && !defined(QSBOOST_NO_SCOPED_ENUMS)
#  define QSBOOST_NO_SCOPED_ENUMS
#endif
//  Use     BOOST_NO_CXX11_STATIC_ASSERT instead of   BOOST_NO_STATIC_ASSERT
#if defined(QSBOOST_NO_CXX11_STATIC_ASSERT) && !defined(QSBOOST_NO_STATIC_ASSERT)
#  define QSBOOST_NO_STATIC_ASSERT
#endif
//  Use     BOOST_NO_CXX11_STD_UNORDERED instead of   BOOST_NO_STD_UNORDERED
#if defined(QSBOOST_NO_CXX11_STD_UNORDERED) && !defined(QSBOOST_NO_STD_UNORDERED)
#  define QSBOOST_NO_STD_UNORDERED
#endif
//  Use     BOOST_NO_CXX11_UNICODE_LITERALS instead of   BOOST_NO_UNICODE_LITERALS
#if defined(QSBOOST_NO_CXX11_UNICODE_LITERALS) && !defined(QSBOOST_NO_UNICODE_LITERALS)
#  define QSBOOST_NO_UNICODE_LITERALS
#endif
//  Use     BOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX instead of   BOOST_NO_UNIFIED_INITIALIZATION_SYNTAX
#if defined(QSBOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX) && !defined(QSBOOST_NO_UNIFIED_INITIALIZATION_SYNTAX)
#  define QSBOOST_NO_UNIFIED_INITIALIZATION_SYNTAX
#endif
//  Use     BOOST_NO_CXX11_VARIADIC_TEMPLATES instead of   BOOST_NO_VARIADIC_TEMPLATES
#if defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(QSBOOST_NO_VARIADIC_TEMPLATES)
#  define QSBOOST_NO_VARIADIC_TEMPLATES
#endif
//  Use     BOOST_NO_CXX11_VARIADIC_MACROS instead of   BOOST_NO_VARIADIC_MACROS
#if defined(QSBOOST_NO_CXX11_VARIADIC_MACROS) && !defined(QSBOOST_NO_VARIADIC_MACROS)
#  define QSBOOST_NO_VARIADIC_MACROS
#endif
//  Use     BOOST_NO_CXX11_NUMERIC_LIMITS instead of   BOOST_NO_NUMERIC_LIMITS_LOWEST
#if defined(QSBOOST_NO_CXX11_NUMERIC_LIMITS) && !defined(QSBOOST_NO_NUMERIC_LIMITS_LOWEST)
#  define QSBOOST_NO_NUMERIC_LIMITS_LOWEST
#endif
//  ------------------ End of deprecated macros for 1.51 ---------------------------



//
// Helper macros BOOST_NOEXCEPT, BOOST_NOEXCEPT_IF, BOOST_NOEXCEPT_EXPR
// These aid the transition to C++11 while still supporting C++03 compilers
//
#ifdef QSBOOST_NO_CXX11_NOEXCEPT
#  define QSBOOST_NOEXCEPT
#  define QSBOOST_NOEXCEPT_OR_NOTHROW throw()
#  define QSBOOST_NOEXCEPT_IF(Predicate)
#  define QSBOOST_NOEXCEPT_EXPR(Expression) false
#else
#  define QSBOOST_NOEXCEPT noexcept
#  define QSBOOST_NOEXCEPT_OR_NOTHROW noexcept
#  define QSBOOST_NOEXCEPT_IF(Predicate) noexcept((Predicate))
#  define QSBOOST_NOEXCEPT_EXPR(Expression) noexcept((Expression))
#endif
//
// Helper macro BOOST_FALLTHROUGH
// Fallback definition of BOOST_FALLTHROUGH macro used to mark intended
// fall-through between case labels in a switch statement. We use a definition
// that requires a semicolon after it to avoid at least one type of misuse even
// on unsupported compilers.
//
#ifndef QSBOOST_FALLTHROUGH
#  define QSBOOST_FALLTHROUGH ((void)0)
#endif

//
// constexpr workarounds
//
#if defined(QSBOOST_NO_CXX11_CONSTEXPR)
#define QSBOOST_CONSTEXPR
#define QSBOOST_CONSTEXPR_OR_CONST const
#else
#define QSBOOST_CONSTEXPR constexpr
#define QSBOOST_CONSTEXPR_OR_CONST constexpr
#endif
#if defined(QSBOOST_NO_CXX14_CONSTEXPR)
#define QSBOOST_CXX14_CONSTEXPR
#else
#define QSBOOST_CXX14_CONSTEXPR constexpr
#endif

//
// Unused variable/typedef workarounds:
//
#ifndef QSBOOST_ATTRIBUTE_UNUSED
#  define QSBOOST_ATTRIBUTE_UNUSED
#endif

#define QSBOOST_STATIC_CONSTEXPR  static QSBOOST_CONSTEXPR_OR_CONST

//
// Set BOOST_HAS_STATIC_ASSERT when BOOST_NO_CXX11_STATIC_ASSERT is not defined
//
#if !defined(QSBOOST_NO_CXX11_STATIC_ASSERT) && !defined(QSBOOST_HAS_STATIC_ASSERT)
#  define QSBOOST_HAS_STATIC_ASSERT
#endif

//
// Set BOOST_HAS_RVALUE_REFS when BOOST_NO_CXX11_RVALUE_REFERENCES is not defined
//
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(QSBOOST_HAS_RVALUE_REFS)
#define QSBOOST_HAS_RVALUE_REFS
#endif

//
// Set BOOST_HAS_VARIADIC_TMPL when BOOST_NO_CXX11_VARIADIC_TEMPLATES is not defined
//
#if !defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(QSBOOST_HAS_VARIADIC_TMPL)
#define QSBOOST_HAS_VARIADIC_TMPL
#endif
//
// Set BOOST_NO_CXX11_FIXED_LENGTH_VARIADIC_TEMPLATE_EXPANSION_PACKS when
// BOOST_NO_CXX11_VARIADIC_TEMPLATES is set:
//
#if defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(QSBOOST_NO_CXX11_FIXED_LENGTH_VARIADIC_TEMPLATE_EXPANSION_PACKS)
#  define QSBOOST_NO_CXX11_FIXED_LENGTH_VARIADIC_TEMPLATE_EXPANSION_PACKS
#endif

//
// Finish off with checks for macros that are depricated / no longer supported,
// if any of these are set then it's very likely that much of Boost will no
// longer work.  So stop with a #error for now, but give the user a chance
// to continue at their own risk if they really want to:
//
#if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) && !defined(QSBOOST_CONFIG_ALLOW_DEPRECATED)
#  error "You are using a compiler which lacks features which are now a minimum requirement in order to use Boost, define BOOST_CONFIG_ALLOW_DEPRECATED if you want to continue at your own risk!!!"
#endif

#endif

//  Copyright (c) 2006-7 John Maddock
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_MATH_TOOLS_CONFIG_HPP
#define QSBOOST_MATH_TOOLS_CONFIG_HPP

#ifdef _MSC_VER
#pragma once
#endif

#include <qsboost/config.hpp>
#include <qsboost/predef.h>
#include <qsboost/cstdint.hpp> // for boost::uintmax_t
#include <qsboost/detail/workaround.hpp>
#include <qsboost/type_traits/is_integral.hpp>
#include <algorithm>  // for min and max
#include <qsboost/config/no_tr1/cmath.hpp>
#include <climits>
#include <cfloat>
#if (defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))
#  include <math.h>
#endif
#ifndef QSBOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
#  include <limits>
#endif

#include <qsboost/math/tools/user.hpp>

#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
   || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
   && !defined(QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
#  define QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x582))
//
// Borland post 5.8.2 uses Dinkumware's std C lib which
// doesn't have true long double precision.  Earlier
// versions are problematic too:
//
#  define QSBOOST_MATH_NO_REAL_CONCEPT_TESTS
#  define QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#  define QSBOOST_MATH_CONTROL_FP _control87(MCW_EM,MCW_EM)
#  include <float.h>
#endif
#ifdef __IBMCPP__
//
// For reasons I don't unserstand, the tests with IMB's compiler all
// pass at long double precision, but fail with real_concept, those tests
// are disabled for now.  (JM 2012).
#  define QSBOOST_MATH_NO_REAL_CONCEPT_TESTS
#endif
#ifdef sun
// Any use of __float128 in program startup code causes a segfault  (tested JM 2015, Solaris 11).
#  define QSBOOST_MATH_DISABLE_FLOAT128
#endif
#ifdef __HAIKU__
//
// Not sure what's up with the math detection on Haiku, but linking fails with
// float128 code enabled, and we don't have an implementation of __expl, so
// disabling long double functions for now as well.
#  define QSBOOST_MATH_DISABLE_FLOAT128
#  define QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if (defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)) && ((LDBL_MANT_DIG == 106) || (__LDBL_MANT_DIG__ == 106)) && !defined(QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
//
// Darwin's rather strange "double double" is rather hard to
// support, it should be possible given enough effort though...
//
#  define QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if defined(unix) && defined(__INTEL_COMPILER) && (__INTEL_COMPILER <= 1000) && !defined(QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
//
// Intel compiler prior to version 10 has sporadic problems
// calling the long double overloads of the std lib math functions:
// calling ::powl is OK, but std::pow(long double, long double) 
// may segfault depending upon the value of the arguments passed 
// and the specific Linux distribution.
//
// We'll be conservative and disable long double support for this compiler.
//
// Comment out this #define and try building the tests to determine whether
// your Intel compiler version has this issue or not.
//
#  define QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#endif
#if defined(unix) && defined(__INTEL_COMPILER)
//
// Intel compiler has sporadic issues compiling std::fpclassify depending on
// the exact OS version used.  Use our own code for this as we know it works
// well on Intel processors:
//
#define QSBOOST_MATH_DISABLE_STD_FPCLASSIFY
#endif

#if defined(QSBOOST_MSVC) && !defined(_WIN32_WCE)
   // Better safe than sorry, our tests don't support hardware exceptions:
#  define QSBOOST_MATH_CONTROL_FP _control87(MCW_EM,MCW_EM)
#endif

#ifdef __IBMCPP__
#  define QSBOOST_MATH_NO_DEDUCED_FUNCTION_POINTERS
#endif

#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901))
#  define QSBOOST_MATH_USE_C99
#endif

#if (defined(__hpux) && !defined(__hppa))
#  define QSBOOST_MATH_USE_C99
#endif

#if defined(__GNUC__) && defined(_GLIBCXX_USE_C99)
#  define QSBOOST_MATH_USE_C99
#endif

#if defined(_LIBCPP_VERSION) && !defined(_MSC_VER)
#  define QSBOOST_MATH_USE_C99
#endif

#if defined(__CYGWIN__) || defined(__HP_aCC) || defined(QSBOOST_INTEL) \
  || defined(QSBOOST_NO_NATIVE_LONG_DOUBLE_FP_CLASSIFY) \
  || (defined(__GNUC__) && !defined(QSBOOST_MATH_USE_C99))\
  || defined(QSBOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
#  define QSBOOST_MATH_NO_NATIVE_LONG_DOUBLE_FP_CLASSIFY
#endif

#if QSBOOST_WORKAROUND(__SUNPRO_CC, <= 0x590)

#  include "qsboost/type.hpp"
#  include "qsboost/non_type.hpp"

#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)         qsboost::type<t>* = 0
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)    qsboost::type<t>*
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)  qsboost::non_type<t, v>* = 0
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)  qsboost::non_type<t, v>*

#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE(t)         \
             , QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE_SPEC(t)    \
             , QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(t, v)  \
             , QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)  \
             , QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

#else

// no workaround needed: expand to nothing

#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE(t)
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define QSBOOST_MATH_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)

#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE(t)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_TYPE_SPEC(t)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE(t, v)
#  define QSBOOST_MATH_APPEND_EXPLICIT_TEMPLATE_NON_TYPE_SPEC(t, v)


#endif // __SUNPRO_CC

#if (defined(__SUNPRO_CC) || defined(__hppa) || defined(__GNUC__)) && !defined(QSBOOST_MATH_SMALL_CONSTANT)
// Sun's compiler emits a hard error if a constant underflows,
// as does aCC on PA-RISC, while gcc issues a large number of warnings:
#  define QSBOOST_MATH_SMALL_CONSTANT(x) 0.0
#else
#  define QSBOOST_MATH_SMALL_CONSTANT(x) x
#endif


#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1400)
//
// Define if constants too large for a float cause "bad"
// values to be stored in the data, rather than infinity
// or a suitably large value.
//
#  define QSBOOST_MATH_BUGGY_LARGE_FLOAT_CONSTANTS
#endif
//
// Tune performance options for specific compilers:
//
#ifdef QSBOOST_MSVC
#  define QSBOOST_MATH_POLY_METHOD 2
#  define QSBOOST_MATH_RATIONAL_METHOD 1
#elif defined(QSBOOST_INTEL)
#  define QSBOOST_MATH_POLY_METHOD 2
#  define QSBOOST_MATH_RATIONAL_METHOD 1
#elif defined(__GNUC__)
#if __GNUC__ < 4
#  define QSBOOST_MATH_POLY_METHOD 3
#  define QSBOOST_MATH_RATIONAL_METHOD 3
#  define QSBOOST_MATH_INT_TABLE_TYPE(RT, IT) RT
#  define QSBOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##.0L
#else
#  define QSBOOST_MATH_POLY_METHOD 3
#  define QSBOOST_MATH_RATIONAL_METHOD 1
#endif
#endif

#if defined(QSBOOST_NO_LONG_LONG) && !defined(QSBOOST_MATH_INT_TABLE_TYPE)
#  define QSBOOST_MATH_INT_TABLE_TYPE(RT, IT) RT
#  define QSBOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##.0L
#endif

//
// constexpr support, early GCC implementations can't cope so disable
// constexpr for them:
//
#if !defined(__clang) && defined(__GNUC__)
#if (__GNUC__ * 100 + __GNUC_MINOR__) < 490
#  define QSBOOST_MATH_DISABLE_CONSTEXPR
#endif
#endif

#ifdef QSBOOST_MATH_DISABLE_CONSTEXPR
#  define QSBOOST_MATH_CONSTEXPR
#else
#  define QSBOOST_MATH_CONSTEXPR QSBOOST_CONSTEXPR
#endif

//
// noexcept support:
//
#ifndef QSBOOST_NO_CXX11_NOEXCEPT
#ifndef QSBOOST_NO_CXX11_HDR_TYPE_TRAITS
#include <type_traits>
#  define QSBOOST_MATH_NOEXCEPT(T) noexcept(std::is_floating_point<T>::value)
#  define QSBOOST_MATH_IS_FLOAT(T) (std::is_floating_point<T>::value)
#else
#include <qsboost/type_traits/is_floating_point.hpp>
#  define QSBOOST_MATH_NOEXCEPT(T) noexcept(qsboost::is_floating_point<T>::value)
#  define QSBOOST_MATH_IS_FLOAT(T) (qsboost::is_floating_point<T>::value)
#endif
#else
#  define QSBOOST_MATH_NOEXCEPT(T)
#  define QSBOOST_MATH_IS_FLOAT(T) false
#endif

//
// The maximum order of polynomial that will be evaluated 
// via an unrolled specialisation:
//
#ifndef QSBOOST_MATH_MAX_POLY_ORDER
#  define QSBOOST_MATH_MAX_POLY_ORDER 20
#endif 
//
// Set the method used to evaluate polynomials and rationals:
//
#ifndef QSBOOST_MATH_POLY_METHOD
#  define QSBOOST_MATH_POLY_METHOD 2
#endif 
#ifndef QSBOOST_MATH_RATIONAL_METHOD
#  define QSBOOST_MATH_RATIONAL_METHOD 1
#endif 
//
// decide whether to store constants as integers or reals:
//
#ifndef QSBOOST_MATH_INT_TABLE_TYPE
#  define QSBOOST_MATH_INT_TABLE_TYPE(RT, IT) IT
#endif
#ifndef QSBOOST_MATH_INT_VALUE_SUFFIX
#  define QSBOOST_MATH_INT_VALUE_SUFFIX(RV, SUF) RV##SUF
#endif
//
// Test whether to support __float128, if we don't have quadmath.h then this can't currently work:
//
#ifndef QSBOOST_MATH_USE_FLOAT128
#ifdef __has_include
#if ! __has_include("quadmath.h")
#define QSBOOST_MATH_DISABLE_FLOAT128
#endif
#elif !defined(QSBOOST_ARCH_X86)
#define QSBOOST_MATH_DISABLE_FLOAT128
#endif
#endif
//
// And then the actual configuration:
//
#if defined(_GLIBCXX_USE_FLOAT128) && defined(QSBOOST_GCC) && !defined(__STRICT_ANSI__) \
   && !defined(QSBOOST_MATH_DISABLE_FLOAT128) || defined(QSBOOST_MATH_USE_FLOAT128)
//
// Only enable this when the compiler really is GCC as clang and probably 
// intel too don't support __float128 yet :-(
//
#ifndef QSBOOST_MATH_USE_FLOAT128
#  define QSBOOST_MATH_USE_FLOAT128
#endif

#  if defined(QSBOOST_INTEL) && defined(QSBOOST_INTEL_CXX_VERSION) && (QSBOOST_INTEL_CXX_VERSION >= 1310) && defined(__GNUC__)
#    if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 6))
#      define QSBOOST_MATH_FLOAT128_TYPE __float128
#    endif
#  elif defined(__GNUC__)
#      define QSBOOST_MATH_FLOAT128_TYPE __float128
#  endif

#  ifndef QSBOOST_MATH_FLOAT128_TYPE
#      define QSBOOST_MATH_FLOAT128_TYPE _Quad
#  endif
#endif
//
// Check for WinCE with no iostream support:
//
#if defined(_WIN32_WCE) && !defined(__SGI_STL_PORT)
#  define QSBOOST_MATH_NO_LEXICAL_CAST
#endif

//
// Helper macro for controlling the FP behaviour:
//
#ifndef QSBOOST_MATH_CONTROL_FP
#  define QSBOOST_MATH_CONTROL_FP
#endif
//
// Helper macro for using statements:
//
#define QSBOOST_MATH_STD_USING_CORE \
   using std::abs;\
   using std::acos;\
   using std::cos;\
   using std::fmod;\
   using std::modf;\
   using std::tan;\
   using std::asin;\
   using std::cosh;\
   using std::frexp;\
   using std::pow;\
   using std::tanh;\
   using std::atan;\
   using std::exp;\
   using std::ldexp;\
   using std::sin;\
   using std::atan2;\
   using std::fabs;\
   using std::log;\
   using std::sinh;\
   using std::ceil;\
   using std::floor;\
   using std::log10;\
   using std::sqrt;

#define QSBOOST_MATH_STD_USING QSBOOST_MATH_STD_USING_CORE

namespace qsboost{ namespace math{
namespace tools
{

template <class T>
inline T max QSBOOST_PREVENT_MACRO_SUBSTITUTION(T a, T b, T c) QSBOOST_MATH_NOEXCEPT(T)
{
   return (std::max)((std::max)(a, b), c);
}

template <class T>
inline T max QSBOOST_PREVENT_MACRO_SUBSTITUTION(T a, T b, T c, T d) QSBOOST_MATH_NOEXCEPT(T)
{
   return (std::max)((std::max)(a, b), (std::max)(c, d));
}

} // namespace tools

template <class T>
void suppress_unused_variable_warning(const T&) QSBOOST_MATH_NOEXCEPT(T)
{
}

namespace detail{

template <class T>
struct is_integer_for_rounding
{
   static const bool value = qsboost::is_integral<T>::value
#ifndef QSBOOST_NO_LIMITS_COMPILE_TIME_CONSTANTS
      || (std::numeric_limits<T>::is_specialized && std::numeric_limits<T>::is_integer)
#endif
      ;
};

}

}} // namespace boost namespace math

#ifdef __GLIBC_PREREQ
#  if __GLIBC_PREREQ(2,14)
#     define QSBOOST_MATH_HAVE_FIXED_GLIBC
#  endif
#endif

#if ((defined(__linux__) && !defined(__UCLIBC__) && !defined(QSBOOST_MATH_HAVE_FIXED_GLIBC)) || defined(__QNX__) || defined(__IBMCPP__)) && !defined(QSBOOST_NO_FENV_H)
//
// This code was introduced in response to this glibc bug: http://sourceware.org/bugzilla/show_bug.cgi?id=2445
// Basically powl and expl can return garbage when the result is small and certain exception flags are set
// on entrance to these functions.  This appears to have been fixed in Glibc 2.14 (May 2011).
// Much more information in this message thread: https://groups.google.com/forum/#!topic/boost-list/ZT99wtIFlb4
//

   #include <qsboost/detail/fenv.hpp>

#  ifdef FE_ALL_EXCEPT

namespace qsboost{ namespace math{
   namespace detail
   {
   struct fpu_guard
   {
      fpu_guard()
      {
         fegetexceptflag(&m_flags, FE_ALL_EXCEPT);
         feclearexcept(FE_ALL_EXCEPT);
      }
      ~fpu_guard()
      {
         fesetexceptflag(&m_flags, FE_ALL_EXCEPT);
      }
   private:
      fexcept_t m_flags;
   };

   } // namespace detail
   }} // namespaces

#    define QSBOOST_FPU_EXCEPTION_GUARD qsboost::math::detail::fpu_guard local_guard_object;
#    define QSBOOST_MATH_INSTRUMENT_FPU do{ fexcept_t cpu_flags; fegetexceptflag(&cpu_flags, FE_ALL_EXCEPT); QSBOOST_MATH_INSTRUMENT_VARIABLE(cpu_flags); } while(0); 

#  else

#    define QSBOOST_FPU_EXCEPTION_GUARD
#    define QSBOOST_MATH_INSTRUMENT_FPU

#  endif

#else // All other platforms.
#  define QSBOOST_FPU_EXCEPTION_GUARD
#  define QSBOOST_MATH_INSTRUMENT_FPU
#endif

#ifdef QSBOOST_MATH_INSTRUMENT

#  include <iostream>
#  include <iomanip>
#  include <typeinfo>

#  define QSBOOST_MATH_INSTRUMENT_CODE(x) \
      std::cout << std::setprecision(35) << __FILE__ << ":" << __LINE__ << " " << x << std::endl;
#  define QSBOOST_MATH_INSTRUMENT_VARIABLE(name) QSBOOST_MATH_INSTRUMENT_CODE(QSBOOST_STRINGIZE(name) << " = " << name)

#else

#  define QSBOOST_MATH_INSTRUMENT_CODE(x)
#  define QSBOOST_MATH_INSTRUMENT_VARIABLE(name)

#endif

#endif // BOOST_MATH_TOOLS_CONFIG_HPP






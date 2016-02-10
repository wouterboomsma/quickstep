//  (C) Copyright Noel Belcourt 2007.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  PGI C++ compiler setup:

#define QSBOOST_COMPILER_VERSION __PGIC__##__PGIC_MINOR__
#define QSBOOST_COMPILER "PGI compiler version " QSBOOST_STRINGIZE(QSBOOST_COMPILER_VERSION)

//
// Threading support:
// Turn this on unconditionally here, it will get turned off again later
// if no threading API is detected.
//

#if __PGIC__ >= 11

// options requested by configure --enable-test
#define QSBOOST_HAS_PTHREADS
#define QSBOOST_HAS_THREADS
#define QSBOOST_HAS_PTHREAD_YIELD
#define QSBOOST_HAS_NRVO
#define QSBOOST_HAS_LONG_LONG

// options --enable-test wants undefined
#undef QSBOOST_NO_STDC_NAMESPACE
#undef QSBOOST_NO_EXCEPTION_STD_NAMESPACE
#undef QSBOOST_DEDUCED_TYPENAME

#define QSBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#define QSBOOST_NO_TWO_PHASE_NAME_LOOKUP
#define QSBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define QSBOOST_NO_CXX11_AUTO_DECLARATIONS

#elif __PGIC__ >= 10

// options requested by configure --enable-test
#define QSBOOST_HAS_THREADS
#define QSBOOST_HAS_NRVO
#define QSBOOST_HAS_LONG_LONG
#if defined(linux) || defined(__linux) || defined(__linux__)
#  define QSBOOST_HAS_STDINT_H
#endif

// options --enable-test wants undefined
#undef QSBOOST_NO_STDC_NAMESPACE
#undef QSBOOST_NO_EXCEPTION_STD_NAMESPACE
#undef QSBOOST_DEDUCED_TYPENAME

#elif __PGIC__ >= 7

#define QSBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#define QSBOOST_NO_TWO_PHASE_NAME_LOOKUP
#define QSBOOST_NO_SWPRINTF
#define QSBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define QSBOOST_NO_CXX11_AUTO_DECLARATIONS

#else

#  error "Pgi compiler not configured - please reconfigure"

#endif
//
// C++0x features
//
//   See boost\config\suffix.hpp for BOOST_NO_LONG_LONG
//
#define QSBOOST_NO_CXX11_CHAR16_T
#define QSBOOST_NO_CXX11_CHAR32_T
#define QSBOOST_NO_CXX11_CONSTEXPR
#define QSBOOST_NO_CXX11_DECLTYPE
#define QSBOOST_NO_CXX11_DECLTYPE_N3276
#define QSBOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define QSBOOST_NO_CXX11_DELETED_FUNCTIONS
#define QSBOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#define QSBOOST_NO_CXX11_EXTERN_TEMPLATE
#define QSBOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS
#define QSBOOST_NO_CXX11_LAMBDAS
#define QSBOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define QSBOOST_NO_CXX11_NOEXCEPT
#define QSBOOST_NO_CXX11_NULLPTR
#define QSBOOST_NO_CXX11_NUMERIC_LIMITS
#define QSBOOST_NO_CXX11_RANGE_BASED_FOR
#define QSBOOST_NO_CXX11_RAW_LITERALS
#define QSBOOST_NO_CXX11_RVALUE_REFERENCES
#define QSBOOST_NO_CXX11_SCOPED_ENUMS
#define QSBOOST_NO_SFINAE_EXPR
#define QSBOOST_NO_CXX11_STATIC_ASSERT
#define QSBOOST_NO_SWPRINTF
#define QSBOOST_NO_CXX11_TEMPLATE_ALIASES
#define QSBOOST_NO_CXX11_UNICODE_LITERALS
#define QSBOOST_NO_CXX11_VARIADIC_TEMPLATES
#define QSBOOST_NO_CXX11_VARIADIC_MACROS
#define QSBOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX

#define QSBOOST_NO_CXX11_HDR_UNORDERED_SET
#define QSBOOST_NO_CXX11_HDR_UNORDERED_MAP
#define QSBOOST_NO_CXX11_HDR_TYPEINDEX
#define QSBOOST_NO_CXX11_HDR_TYPE_TRAITS
#define QSBOOST_NO_CXX11_HDR_TUPLE
#define QSBOOST_NO_CXX11_HDR_THREAD
#define QSBOOST_NO_CXX11_HDR_SYSTEM_ERROR
#define QSBOOST_NO_CXX11_HDR_REGEX
#define QSBOOST_NO_CXX11_HDR_RATIO
#define QSBOOST_NO_CXX11_HDR_RANDOM
#define QSBOOST_NO_CXX11_HDR_MUTEX
#define QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define QSBOOST_NO_CXX11_HDR_FUTURE
#define QSBOOST_NO_CXX11_HDR_FORWARD_LIST
#define QSBOOST_NO_CXX11_HDR_CONDITION_VARIABLE
#define QSBOOST_NO_CXX11_HDR_CODECVT
#define QSBOOST_NO_CXX11_HDR_CHRONO
#define QSBOOST_NO_CXX11_HDR_ARRAY
#define QSBOOST_NO_CXX11_USER_DEFINED_LITERALS
#define QSBOOST_NO_CXX11_ALIGNAS
#define QSBOOST_NO_CXX11_TRAILING_RESULT_TYPES
#define QSBOOST_NO_CXX11_INLINE_NAMESPACES
#define QSBOOST_NO_CXX11_REF_QUALIFIERS
#define QSBOOST_NO_CXX11_FINAL

// C++ 14:
#if !defined(__cpp_aggregate_nsdmi) || (__cpp_aggregate_nsdmi < 201304)
#  define QSBOOST_NO_CXX14_AGGREGATE_NSDMI
#endif
#if !defined(__cpp_binary_literals) || (__cpp_binary_literals < 201304)
#  define QSBOOST_NO_CXX14_BINARY_LITERALS
#endif
#if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#  define QSBOOST_NO_CXX14_CONSTEXPR
#endif
#if !defined(__cpp_decltype_auto) || (__cpp_decltype_auto < 201304)
#  define QSBOOST_NO_CXX14_DECLTYPE_AUTO
#endif
#if (__cplusplus < 201304) // There's no SD6 check for this....
#  define QSBOOST_NO_CXX14_DIGIT_SEPARATORS
#endif
#if !defined(__cpp_generic_lambdas) || (__cpp_generic_lambdas < 201304)
#  define QSBOOST_NO_CXX14_GENERIC_LAMBDAS
#endif
#if !defined(__cpp_init_captures) || (__cpp_init_captures < 201304)
#  define QSBOOST_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES
#endif
#if !defined(__cpp_return_type_deduction) || (__cpp_return_type_deduction < 201304)
#  define QSBOOST_NO_CXX14_RETURN_TYPE_DEDUCTION
#endif
#if !defined(__cpp_variable_templates) || (__cpp_variable_templates < 201304)
#  define QSBOOST_NO_CXX14_VARIABLE_TEMPLATES
#endif
//
// version check:
// probably nothing to do here?


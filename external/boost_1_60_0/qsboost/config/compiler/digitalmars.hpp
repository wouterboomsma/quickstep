//  Copyright (C) Christof Meerwald 2003
//  Copyright (C) Dan Watkins 2003
//
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  Digital Mars C++ compiler setup:
#define QSBOOST_COMPILER __DMC_VERSION_STRING__

#define QSBOOST_HAS_LONG_LONG
#define QSBOOST_HAS_PRAGMA_ONCE

#if !defined(QSBOOST_STRICT_CONFIG)
#define QSBOOST_NO_MEMBER_TEMPLATE_FRIENDS
#define QSBOOST_NO_OPERATORS_IN_NAMESPACE
#define QSBOOST_NO_UNREACHABLE_RETURN_DETECTION
#define QSBOOST_NO_SFINAE
#define QSBOOST_NO_USING_TEMPLATE
#define QSBOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
#endif

//
// has macros:
#define QSBOOST_HAS_DIRENT_H
#define QSBOOST_HAS_STDINT_H
#define QSBOOST_HAS_WINTHREADS

#if (__DMC__ >= 0x847)
#define QSBOOST_HAS_EXPM1
#define QSBOOST_HAS_LOG1P
#endif

//
// Is this really the best way to detect whether the std lib is in namespace std?
//
#ifdef __cplusplus
#include <cstddef>
#endif
#if !defined(__STL_IMPORT_VENDOR_CSTD) && !defined(_STLP_IMPORT_VENDOR_CSTD)
#  define QSBOOST_NO_STDC_NAMESPACE
#endif


// check for exception handling support:
#if !defined(_CPPUNWIND) && !defined(QSBOOST_NO_EXCEPTIONS)
#  define QSBOOST_NO_EXCEPTIONS
#endif

//
// C++0x features
//
#define QSBOOST_NO_CXX11_AUTO_DECLARATIONS
#define QSBOOST_NO_CXX11_AUTO_MULTIDECLARATIONS
#define QSBOOST_NO_CXX11_CHAR16_T
#define QSBOOST_NO_CXX11_CHAR32_T
#define QSBOOST_NO_CXX11_CONSTEXPR
#define QSBOOST_NO_CXX11_DECLTYPE
#define QSBOOST_NO_CXX11_DECLTYPE_N3276
#define QSBOOST_NO_CXX11_DEFAULTED_FUNCTIONS
#define QSBOOST_NO_CXX11_DELETED_FUNCTIONS
#define QSBOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#define QSBOOST_NO_CXX11_EXTERN_TEMPLATE
#define QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST
#define QSBOOST_NO_CXX11_LAMBDAS
#define QSBOOST_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#define QSBOOST_NO_CXX11_NOEXCEPT
#define QSBOOST_NO_CXX11_NULLPTR
#define QSBOOST_NO_CXX11_RANGE_BASED_FOR
#define QSBOOST_NO_CXX11_RAW_LITERALS
#define QSBOOST_NO_CXX11_RVALUE_REFERENCES
#define QSBOOST_NO_CXX11_SCOPED_ENUMS
#define QSBOOST_NO_SFINAE_EXPR
#define QSBOOST_NO_CXX11_STATIC_ASSERT
#define QSBOOST_NO_CXX11_TEMPLATE_ALIASES
#define QSBOOST_NO_CXX11_UNICODE_LITERALS
#define QSBOOST_NO_CXX11_VARIADIC_TEMPLATES
#define QSBOOST_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
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

#if (__DMC__ <= 0x840)
#error "Compiler not supported or configured - please reconfigure"
#endif
//
// last known and checked version is ...:
#if (__DMC__ > 0x848)
#  if defined(QSBOOST_ASSERT_CONFIG)
#     error "Unknown compiler version - please run the configure tests and report the results"
#  endif
#endif

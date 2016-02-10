
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_CONFIG_HPP_INCLUDED
#define QSBOOST_TT_CONFIG_HPP_INCLUDED

#ifndef QSBOOST_CONFIG_HPP
#include <qsboost/config.hpp>
#endif
#include <qsboost/version.hpp>
#include <qsboost/detail/workaround.hpp>

//
// whenever we have a conversion function with ellipses
// it needs to be declared __cdecl to suppress compiler
// warnings from MS and Borland compilers (this *must*
// appear before we include is_same.hpp below):
#if defined(QSBOOST_MSVC) || (defined(__BORLANDC__) && !defined(QSBOOST_DISABLE_WIN32))
#   define QSBOOST_TT_DECL __cdecl
#else
#   define QSBOOST_TT_DECL /**/
#endif

# if (QSBOOST_WORKAROUND(__MWERKS__, < 0x3000)                         \
    || QSBOOST_WORKAROUND(__IBMCPP__, < 600 )                         \
    || QSBOOST_WORKAROUND(__BORLANDC__, < 0x5A0)                      \
    || defined(__ghs)                                               \
    || QSBOOST_WORKAROUND(__HP_aCC, < 60700)           \
    || QSBOOST_WORKAROUND(MPW_CPLUS, QSBOOST_TESTED_AT(0x890))          \
    || QSBOOST_WORKAROUND(__SUNPRO_CC, QSBOOST_TESTED_AT(0x580)))       \
    && defined(QSBOOST_NO_IS_ABSTRACT)

#   define QSBOOST_TT_NO_CONFORMING_IS_CLASS_IMPLEMENTATION 1

#endif

#ifndef QSBOOST_TT_NO_CONFORMING_IS_CLASS_IMPLEMENTATION
# define QSBOOST_TT_HAS_CONFORMING_IS_CLASS_IMPLEMENTATION 1
#endif

//
// define BOOST_TT_TEST_MS_FUNC_SIGS
// when we want to test __stdcall etc function types with is_function etc
// (Note, does not work with Borland, even though it does support __stdcall etc):
//
#if defined(_MSC_EXTENSIONS) && !defined(__BORLANDC__)
#  define QSBOOST_TT_TEST_MS_FUNC_SIGS
#endif

//
// define BOOST_TT_NO_CV_FUNC_TEST
// if tests for cv-qualified member functions don't 
// work in is_member_function_pointer
//
#if QSBOOST_WORKAROUND(__MWERKS__, < 0x3000) || QSBOOST_WORKAROUND(__IBMCPP__, <= 600)
#  define QSBOOST_TT_NO_CV_FUNC_TEST
#endif

//
// Macros that have been deprecated, defined here for backwards compatibility:
//
#define QSBOOST_BROKEN_COMPILER_TYPE_TRAITS_SPECIALIZATION(x)
#define QSBOOST_TT_BROKEN_COMPILER_SPEC(x)

#endif // BOOST_TT_CONFIG_HPP_INCLUDED



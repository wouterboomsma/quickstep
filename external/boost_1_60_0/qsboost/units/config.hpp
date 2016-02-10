// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_CONFIG_HPP
#define QSBOOST_UNITS_CONFIG_HPP

#include <qsboost/config.hpp>
#include <qsboost/version.hpp>

#ifndef QSBOOST_UNITS_HAS_QSBOOST_TYPEOF
    #if (QSBOOST_VERSION >= 103400)
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_QSBOOST_TYPEOF    1
    #else
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_QSBOOST_TYPEOF    0
    #endif
#endif 

#if (QSBOOST_UNITS_HAS_QSBOOST_TYPEOF)
    #include <qsboost/typeof/typeof.hpp> 
    ///INTERNAL ONLY
    #define QSBOOST_UNITS_HAS_TYPEOF          1
#else    
    #if (__GNUC__ && __cplusplus)
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_TYPEOF          1
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_GNU_TYPEOF      1
    #elif defined(__MWERKS__)
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_TYPEOF          1
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_MWERKS_TYPEOF   1
    #else
        ///INTERNAL ONLY
        #define QSBOOST_UNITS_HAS_TYPEOF          0
    #endif
#endif

// uncomment this to test without typeof support at all
//#undef BOOST_UNITS_HAS_TYPEOF
//#define BOOST_UNITS_HAS_TYPEOF          0

#ifndef QSBOOST_UNITS_NO_COMPILER_CHECK

    #ifdef QSBOOST_NO_MEMBER_TEMPLATES
        #error Boost.Units requires member template
    #endif

    #ifdef QSBOOST_NO_MEMBER_TEMPLATE_KEYWORD
        #error Boost.Units requires member template keyword
    #endif

    #ifdef QSBOOST_NO_INCLASS_MEMBER_INITIALIZATION
        #error Boost.Units requires in class member initialization
    #endif

    #ifdef QSBOOST_NO_FUNCTION_TEMPLATE_ORDERING
        #error Boost.Units requires function template partial ordering
    #endif


#endif

#ifdef QSBOOST_UNITS_REQUIRE_LAYOUT_COMPATIBILITY
    ///INTERNAL ONLY
    #define QSBOOST_UNITS_CHECK_LAYOUT_COMPATIBILITY(a, b) QSBOOST_STATIC_ASSERT((sizeof(a) == sizeof(b)))
#else
    ///INTERNAL ONLY
    #define QSBOOST_UNITS_CHECK_LAYOUT_COMPATIBILITY(a, b) ((void)0)
#endif

#ifdef QSBOOST_UNITS_DOXYGEN

/// If defined will trigger a static assertion if quantity<Unit, T>
/// is not layout compatible with T
#define QSBOOST_UNITS_REQUIRE_LAYOUT_COMPATIBILITY

/// If defined will disable a preprocessor check that the
/// compiler is able to handle the library.
#define QSBOOST_UNITS_NO_COMPILER_CHECK

/// Enable checking to verify that a homogeneous system
/// is actually capable of representing all the dimensions
/// that it is used with.  Off by default.
#define QSBOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

#endif

#endif

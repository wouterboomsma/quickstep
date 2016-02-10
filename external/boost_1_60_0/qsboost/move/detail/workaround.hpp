//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2014-2014. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/interprocess for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef QSBOOST_MOVE_DETAIL_WORKAROUND_HPP
#define QSBOOST_MOVE_DETAIL_WORKAROUND_HPP

#ifndef QSBOOST_CONFIG_HPP
#  include <qsboost/config.hpp>
#endif
#
#if defined(QSBOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#if    !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES)
   #define QSBOOST_MOVE_PERFECT_FORWARDING
#endif

#if defined(__has_feature)
   #define QSBOOST_MOVE_HAS_FEATURE __has_feature
#else
   #define QSBOOST_MOVE_HAS_FEATURE(x) 0
#endif

#if QSBOOST_MOVE_HAS_FEATURE(address_sanitizer) || defined(__SANITIZE_ADDRESS__)
   #define QSBOOST_MOVE_ADDRESS_SANITIZER_ON
#endif

//Macros for documentation purposes. For code, expands to the argument
#define QSBOOST_MOVE_IMPDEF(TYPE) TYPE
#define QSBOOST_MOVE_SEEDOC(TYPE) TYPE
#define QSBOOST_MOVE_DOC0PTR(TYPE) TYPE
#define QSBOOST_MOVE_DOC1ST(TYPE1, TYPE2) TYPE2
#define QSBOOST_MOVE_I ,
#define QSBOOST_MOVE_DOCIGN(T1) T1

#if defined(__GNUC__) && (__GNUC__ == 4) && (__GNUC_MINOR__ < 5) && !defined(__clang__)
   //Pre-standard rvalue binding rules
   #define QSBOOST_MOVE_OLD_RVALUE_REF_BINDING_RULES
#elif defined(_MSC_VER) && (_MSC_VER == 1600)
   //Standard rvalue binding rules but with some bugs
   #define QSBOOST_MOVE_MSVC_10_MEMBER_RVALUE_REF_BUG
   #define QSBOOST_MOVE_MSVC_AUTO_MOVE_RETURN_BUG
#elif defined(_MSC_VER) && (_MSC_VER == 1700)
   #define QSBOOST_MOVE_MSVC_AUTO_MOVE_RETURN_BUG
#endif

#endif   //#ifndef BOOST_MOVE_DETAIL_WORKAROUND_HPP

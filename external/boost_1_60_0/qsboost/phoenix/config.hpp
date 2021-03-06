/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010      Eric Niebler
    Copyright (c) 2014-2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CONFIG_HPP
#define QSBOOST_PHOENIX_CONFIG_HPP

#include <qsboost/config.hpp>

//////////////////////////////////////////////////////////////////////////
// This section is to sort out whether hash types or unordered types
// are available. This depends on whether stdlib or libc++ is being used
// and also whether C++11 or C++03 is being used.
//////////////////////////////////////////////////////////////////////////
// The idea is to set up the configuration without including the actual
// headers unless that is unavoidable.
//
// The client code should contain the following to include headers
//
// #ifdef BOOST_PHOENIX_HAS_HASH
// #include BOOST_PHOENIX_HASH_SET_HEADER
// #include BOOST_PHOENIX_HASH_MAP_HEADER
// #endif
//
// #ifdef BOOST_PHOENIX_HAS_UNORDERED_SET_AND_MAP
// #define BOOST_PHOENIX_UNORDERED_SET_HEADER <unordered_set>
// #define BOOST_PHOENIX_UNORDERED_MAP_HEADER <unordered_map>
// #endif
//
// The client code can then chose the implementation provided.
// See the example in test/stl/querying_find2.cpp
//
//////////////////////////////////////////////////////////////////////////
//
// There is no specific thing in Boost Config for libc++
#ifdef _LIBCPP_VERSION
#define QSBOOST_PHOENIX_USING_LIBCPP
// This may not be true for some very old version of libc++
// Current libc++ supports unordered_set and unordered_map without C++11.
#undef QSBOOST_NO_CXX11_HDR_UNORDERED_MAP
#undef QSBOOST_NO_CXX11_HDR_UNORDERED_SET
#endif

#if (!defined(QSBOOST_PHOENIX_USING_LIBCPP) \
  && (defined (QSBOOST_NO_CXX11_HDR_UNORDERED_MAP) || \
     defined (QSBOOST_NO_CXX11_HDR_UNORDERED_SET) ) )
#ifdef QSBOOST_HAS_HASH
// This is to sort out case of Clang when using stdlib from gcc
// as Clang thinks it is gcc 4.2.1
// This prevents the failure to include a header with a warning.
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#define QSBOOST_PHOENIX_PERMIT_BACKWARD_HASH
#define QSBOOST_PHOENIX_HASH_SET_HEADER QSBOOST_HASH_SET_HEADER
#define QSBOOST_PHOENIX_HASH_MAP_HEADER QSBOOST_HASH_MAP_HEADER
#define QSBOOST_PHOENIX_HAS_HASH
#define QSBOOST_PHOENIX_HASH_NAMESPACE QSBOOST_STD_EXTENSION_NAMESPACE

#elif defined(QSBOOST_DINKUMWARE_STDLIB) && (QSBOOST_DINKUMWARE_STDLIB < 610)
#define QSBOOST_PHOENIX_HASH_SET_HEADER <hash_set>
#define QSBOOST_PHOENIX_HASH_MAP_HEADER <hash_map>
#define QSBOOST_PHOENIX_HAS_HASH
#define QSBOOST_PHOENIX_HASH_NAMESPACE stdext
#endif
#else
// This is either libc++ or C++11 or later
#define QSBOOST_PHOENIX_HAS_UNORDERED_SET_AND_MAP
#define QSBOOST_PHOENIX_UNORDERED_SET_HEADER <unordered_set>
#define QSBOOST_PHOENIX_UNORDERED_MAP_HEADER <unordered_map>
#define QSBOOST_PHOENIX_UNORDERED_NAMESPACE std
#endif

#endif

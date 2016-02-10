
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED
#define QSBOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_default_constructible.hpp>

#ifdef QSBOOST_HAS_TRIVIAL_CONSTRUCTOR
#ifdef QSBOOST_HAS_SGI_TYPE_TRAITS
#include <qsboost/type_traits/is_same.hpp>
#elif defined(__GNUC__) || defined(__SUNPRO_CC)
#include <qsboost/type_traits/is_volatile.hpp>
#ifdef QSBOOST_INTEL
#include <qsboost/type_traits/is_pod.hpp>
#endif
#endif
#endif


#if (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 409)) || defined(QSBOOST_CLANG) || (defined(__SUNPRO_CC) && defined(QSBOOST_HAS_TRIVIAL_CONSTRUCTOR))
#include <qsboost/type_traits/is_default_constructible.hpp>
#define QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX && is_default_constructible<T>::value
#else
//
// Mot all compilers, particularly older GCC versions can handle the fix above.
#define QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX
#endif

namespace qsboost {

template <typename T> struct has_trivial_constructor
#ifdef QSBOOST_HAS_TRIVIAL_CONSTRUCTOR
   : public integral_constant <bool, ((::qsboost::is_pod<T>::value || QSBOOST_HAS_TRIVIAL_CONSTRUCTOR(T)) QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX)>{};
#else
   : public integral_constant <bool, ::qsboost::is_pod<T>::value>{};
#endif

template <> struct has_trivial_constructor<void> : public qsboost::false_type{};
template <> struct has_trivial_constructor<void const> : public qsboost::false_type{};
template <> struct has_trivial_constructor<void const volatile> : public qsboost::false_type{};
template <> struct has_trivial_constructor<void volatile> : public qsboost::false_type{};

template <class T> struct has_trivial_default_constructor : public has_trivial_constructor<T> {};

#undef QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX

} // namespace boost

#endif // BOOST_TT_HAS_TRIVIAL_CONSTRUCTOR_HPP_INCLUDED

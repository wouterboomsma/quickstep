
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  (C) Copyright Eric Friedman 2002-2003.
//  (C) Copyright Antony Polukhin 2013.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_TRIVIAL_MOVE_CONSTRUCTOR_HPP_INCLUDED
#define QSBOOST_TT_HAS_TRIVIAL_MOVE_CONSTRUCTOR_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>

#ifdef QSBOOST_HAS_TRIVIAL_MOVE_CONSTRUCTOR

#if defined(QSBOOST_MSVC) || defined(QSBOOST_INTEL)
#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#endif

#if defined(__GNUC__) || defined(__clang)
#include <qsboost/type_traits/is_constructible.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#endif


namespace qsboost {

template <typename T> struct has_trivial_move_constructor : public integral_constant<bool, QSBOOST_HAS_TRIVIAL_MOVE_CONSTRUCTOR(T)>{};

#else

#ifdef __SUNPRO_CC
#include <qsboost/type_traits/is_constructible.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#if __cplusplus >= 201103
#define SOLARIS_EXTRA_CHECK && is_constructible<typename remove_const<T>::type, typename remove_const<T>::type&&>::value
#endif
#endif

#ifndef SOLARIS_EXTRA_CHECK
#define SOLARIS_EXTRA_CHECK
#endif

#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_volatile.hpp>

namespace qsboost {

template <typename T> struct has_trivial_move_constructor 
   : public integral_constant<bool, ::qsboost::is_pod<T>::value && !::qsboost::is_volatile<T>::value SOLARIS_EXTRA_CHECK>{};

#undef SOLARIS_EXTRA_CHECK

#endif

template <> struct has_trivial_move_constructor<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_trivial_move_constructor<void const> : public false_type{};
template <> struct has_trivial_move_constructor<void volatile> : public false_type{};
template <> struct has_trivial_move_constructor<void const volatile> : public false_type{};
#endif
// What should we do with reference types??? The standard seems to suggest these are trivial, even if the thing they reference is not:
template <class T> struct has_trivial_move_constructor<T&> : public true_type{};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct has_trivial_move_constructor<T&&> : public true_type{};
#endif
// Arrays can not be explicitly copied:
template <class T, std::size_t N> struct has_trivial_move_constructor<T[N]> : public false_type{};
template <class T> struct has_trivial_move_constructor<T[]> : public false_type{};

} // namespace boost

#endif // BOOST_TT_HAS_TRIVIAL_MOVE_CONSTRUCTOR_HPP_INCLUDED


//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  (C) Copyright Eric Friedman 2002-2003.
//  (C) Copyright Antony Polukhin 2013.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_TRIVIAL_MOVE_ASSIGN_HPP_INCLUDED
#define QSBOOST_TT_HAS_TRIVIAL_MOVE_ASSIGN_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>

#if !defined(QSBOOST_HAS_TRIVIAL_MOVE_ASSIGN) || defined(QSBOOST_MSVC) || defined(QSBOOST_INTEL)
#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_const.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#ifdef QSBOOST_MSVC
#include <qsboost/type_traits/is_reference.hpp>
#endif
#endif

#if defined(__GNUC__) || defined(__clang)
#include <qsboost/type_traits/is_assignable.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#endif

#ifdef __SUNPRO_CC
#include <qsboost/type_traits/is_assignable.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#if __cplusplus >= 201103
#define SOLARIS_EXTRA_CHECK && is_assignable<typename remove_const<T>::type&, typename remove_const<T>::type&&>::value
#endif
#endif

#ifndef SOLARIS_EXTRA_CHECK
#define SOLARIS_EXTRA_CHECK
#endif

namespace qsboost{

template <typename T>
struct has_trivial_move_assign : public integral_constant<bool,
#ifdef QSBOOST_HAS_TRIVIAL_MOVE_ASSIGN
   QSBOOST_HAS_TRIVIAL_MOVE_ASSIGN(T)
#else
   ::qsboost::is_pod<T>::value && !::qsboost::is_const<T>::value && !::qsboost::is_volatile<T>::value SOLARIS_EXTRA_CHECK
#endif
   > {};

template <> struct has_trivial_move_assign<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_trivial_move_assign<void const> : public false_type{};
template <> struct has_trivial_move_assign<void const volatile> : public false_type{};
template <> struct has_trivial_move_assign<void volatile> : public false_type{};
#endif
template <class T> struct has_trivial_move_assign<T&> : public false_type{};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct has_trivial_move_assign<T&&> : public false_type{};
#endif
// Array types are not assignable:
template <class T, std::size_t N> struct has_trivial_move_assign<T[N]> : public false_type{};
template <class T> struct has_trivial_move_assign<T[]> : public false_type{};

} // namespace boost

#undef SOLARIS_EXTRA_CHECK

#endif // BOOST_TT_HAS_TRIVIAL_MOVE_ASSIGN_HPP_INCLUDED

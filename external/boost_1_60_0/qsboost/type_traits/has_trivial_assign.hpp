
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_TRIVIAL_ASSIGN_HPP_INCLUDED
#define QSBOOST_TT_HAS_TRIVIAL_ASSIGN_HPP_INCLUDED

#include <qsboost/type_traits/detail/config.hpp>
#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>

#if !defined(QSBOOST_HAS_TRIVIAL_ASSIGN) || defined(QSBOOST_MSVC) || defined(__GNUC__) || defined(QSBOOST_INTEL) || defined(__SUNPRO_CC) || defined(__clang)
#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_const.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#include <qsboost/type_traits/is_assignable.hpp>
#endif

namespace qsboost {

   template <typename T>
   struct has_trivial_assign : public integral_constant < bool,
#ifdef QSBOOST_HAS_TRIVIAL_ASSIGN
      QSBOOST_HAS_TRIVIAL_ASSIGN(T)
#else
      ::qsboost::is_pod<T>::value && !::qsboost::is_const<T>::value && !::qsboost::is_volatile<T>::value
#endif
   > {};

   template<> struct has_trivial_assign<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
   template<> struct has_trivial_assign<void const> : public false_type{};
   template<> struct has_trivial_assign<void const volatile> : public false_type{};
   template<> struct has_trivial_assign<void volatile> : public false_type{};
#endif
   template <class T> struct has_trivial_assign<T volatile> : public false_type{};
   template <class T> struct has_trivial_assign<T&> : public false_type{};
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)
   template <class T> struct has_trivial_assign<T&&> : public false_type{};
#endif
   // Arrays are not explictly assignable:
   template <typename T, std::size_t N> struct has_trivial_assign<T[N]> : public false_type{};
   template <typename T> struct has_trivial_assign<T[]> : public false_type{};

} // namespace boost

#endif // BOOST_TT_HAS_TRIVIAL_ASSIGN_HPP_INCLUDED

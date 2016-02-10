
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED
#define QSBOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>

#ifdef QSBOOST_HAS_NOTHROW_COPY

#if defined(QSBOOST_CLANG) || defined(__GNUC__) || defined(__ghs__) || defined(__CODEGEARC__) || defined(__SUNPRO_CC)
#include <qsboost/type_traits/is_volatile.hpp>
#include <qsboost/type_traits/is_copy_constructible.hpp>
#include <qsboost/type_traits/is_reference.hpp>
#include <qsboost/type_traits/is_array.hpp>
#ifdef QSBOOST_INTEL
#include <qsboost/type_traits/is_pod.hpp>
#endif
#elif defined(QSBOOST_MSVC) || defined(QSBOOST_INTEL)
#include <qsboost/type_traits/has_trivial_copy.hpp>
#include <qsboost/type_traits/is_array.hpp>
#ifdef QSBOOST_INTEL
#include <qsboost/type_traits/add_lvalue_reference.hpp>
#include <qsboost/type_traits/add_const.hpp>
#endif
#endif

namespace qsboost {

template <class T> struct has_nothrow_copy_constructor : public integral_constant<bool, QSBOOST_HAS_NOTHROW_COPY(T)>{};

#elif !defined(QSBOOST_NO_CXX11_NOEXCEPT)

#include <qsboost/type_traits/declval.hpp>
#include <qsboost/type_traits/is_copy_constructible.hpp>

namespace qsboost{

namespace detail{

template <class T, bool b>
struct has_nothrow_copy_constructor_imp : public qsboost::integral_constant<bool, false>{};
template <class T>
struct has_nothrow_copy_constructor_imp<T, true> : public qsboost::integral_constant<bool, noexcept(T(qsboost::declval<const T&>()))>{};

}

template <class T> struct has_nothrow_copy_constructor : public detail::has_nothrow_copy_constructor_imp<T, qsboost::is_copy_constructible<T>::value>{};

#else

#include <qsboost/type_traits/has_trivial_copy.hpp>

namespace qsboost{

template <class T> struct has_nothrow_copy_constructor : public integral_constant<bool, ::qsboost::has_trivial_copy<T>::value>{};

#endif

template <> struct has_nothrow_copy_constructor<void> : public false_type{};
template <class T> struct has_nothrow_copy_constructor<T volatile> : public false_type{};
template <class T> struct has_nothrow_copy_constructor<T&> : public false_type{};
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) 
template <class T> struct has_nothrow_copy_constructor<T&&> : public false_type{};
#endif
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_nothrow_copy_constructor<void const> : public false_type{};
template <> struct has_nothrow_copy_constructor<void volatile> : public false_type{};
template <> struct has_nothrow_copy_constructor<void const volatile> : public false_type{};
#endif

template <class T> struct has_nothrow_copy : public has_nothrow_copy_constructor<T>{};

} // namespace boost

#endif // BOOST_TT_HAS_NOTHROW_COPY_HPP_INCLUDED


//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED
#define QSBOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/is_pod.hpp>
#include <qsboost/type_traits/is_reference.hpp>

#if (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__ >= 409)) || defined(QSBOOST_CLANG) || (defined(__SUNPRO_CC) && defined(QSBOOST_HAS_TRIVIAL_COPY))
#include <qsboost/type_traits/is_copy_constructible.hpp>
#define QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX && is_copy_constructible<T>::value
#else
#define QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX
#endif

#ifdef QSBOOST_INTEL
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/add_lvalue_reference.hpp>
#endif

namespace qsboost {

template <typename T> struct has_trivial_copy 
: public integral_constant<bool, 
#ifdef QSBOOST_HAS_TRIVIAL_COPY
   QSBOOST_HAS_TRIVIAL_COPY(T) QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX
#else
   ::qsboost::is_pod<T>::value
#endif
>{};
// Arrays are not explicitly copyable:
template <typename T, std::size_t N> struct has_trivial_copy<T[N]> : public false_type{};
template <typename T> struct has_trivial_copy<T[]> : public false_type{};
// Are volatile types ever trivial?  We don't really know, so assume not:
template <typename T> struct has_trivial_copy<T volatile> : public false_type{};

template <> struct has_trivial_copy<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct has_trivial_copy<void const> : public false_type{};
template <> struct has_trivial_copy<void volatile> : public false_type{};
template <> struct has_trivial_copy<void const volatile> : public false_type{};
#endif

template <class T> struct has_trivial_copy<T&> : public false_type{};
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) 
template <class T> struct has_trivial_copy<T&&> : public false_type{};
#endif

template <class T> struct has_trivial_copy_constructor : public has_trivial_copy<T>{};

#undef QSBOOST_TT_TRIVIAL_CONSTRUCT_FIX

} // namespace boost

#endif // BOOST_TT_HAS_TRIVIAL_COPY_HPP_INCLUDED

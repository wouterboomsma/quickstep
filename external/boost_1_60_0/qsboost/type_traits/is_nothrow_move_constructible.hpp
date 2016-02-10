
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  (C) Copyright Eric Friedman 2002-2003.
//  (C) Copyright Antony Polukhin 2013.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED
#define QSBOOST_TT_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED

#include <qsboost/config.hpp>
#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>
#include <qsboost/detail/workaround.hpp>

#ifdef QSBOOST_IS_NOTHROW_MOVE_CONSTRUCT

namespace qsboost {

template <class T>
struct is_nothrow_move_constructible : public integral_constant<bool, QSBOOST_IS_NOTHROW_MOVE_CONSTRUCT(T)>{};

template <class T> struct is_nothrow_move_constructible<volatile T> : public ::qsboost::false_type {};
template <class T> struct is_nothrow_move_constructible<const volatile T> : public ::qsboost::false_type{};

#elif !defined(QSBOOST_NO_CXX11_NOEXCEPT) && !defined(QSBOOST_NO_SFINAE_EXPR) && !QSBOOST_WORKAROUND(QSBOOST_GCC_VERSION, < 40700)

#include <qsboost/type_traits/declval.hpp>
#include <qsboost/utility/enable_if.hpp>

namespace qsboost{ namespace detail{

template <class T, class Enable = void>
struct false_or_cpp11_noexcept_move_constructible: public ::qsboost::false_type {};

template <class T>
struct false_or_cpp11_noexcept_move_constructible <
        T,
        typename ::qsboost::enable_if_c<sizeof(T) && QSBOOST_NOEXCEPT_EXPR(T(::qsboost::declval<T>()))>::type
    > : public ::qsboost::integral_constant<bool, QSBOOST_NOEXCEPT_EXPR(T(::qsboost::declval<T>()))>
{};

}

template <class T> struct is_nothrow_move_constructible
   : public integral_constant<bool, ::qsboost::detail::false_or_cpp11_noexcept_move_constructible<T>::value>{};

template <class T> struct is_nothrow_move_constructible<volatile T> : public ::qsboost::false_type {};
template <class T> struct is_nothrow_move_constructible<const volatile T> : public ::qsboost::false_type{};
template <class T, std::size_t N> struct is_nothrow_move_constructible<T[N]> : public ::qsboost::false_type{};
template <class T> struct is_nothrow_move_constructible<T[]> : public ::qsboost::false_type{};

#else

#include <qsboost/type_traits/has_trivial_move_constructor.hpp>
#include <qsboost/type_traits/has_nothrow_copy.hpp>
#include <qsboost/type_traits/is_array.hpp>

namespace qsboost{

template <class T>
struct is_nothrow_move_constructible
   : public integral_constant<bool,
   (::qsboost::has_trivial_move_constructor<T>::value || ::qsboost::has_nothrow_copy<T>::value) && !::qsboost::is_array<T>::value>
{};

#endif

template <> struct is_nothrow_move_constructible<void> : false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct is_nothrow_move_constructible<void const> : false_type{};
template <> struct is_nothrow_move_constructible<void volatile> : false_type{};
template <> struct is_nothrow_move_constructible<void const volatile> : false_type{};
#endif
// References are always trivially constructible, even if the thing they reference is not:
template <class T> struct is_nothrow_move_constructible<T&> : public ::qsboost::true_type{};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct is_nothrow_move_constructible<T&&> : public ::qsboost::true_type{};
#endif

} // namespace boost

#endif // BOOST_TT_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP_INCLUDED

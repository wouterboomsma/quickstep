
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  (C) Copyright Eric Friedman 2002-2003.
//  (C) Copyright Antony Polukhin 2013.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED
#define QSBOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED

#include <qsboost/config.hpp>
#include <qsboost/type_traits/has_trivial_move_assign.hpp>
#include <qsboost/type_traits/has_nothrow_assign.hpp>
#include <qsboost/type_traits/is_array.hpp>
#include <qsboost/type_traits/is_reference.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/type_traits/declval.hpp>

namespace qsboost {

#ifdef QSBOOST_IS_NOTHROW_MOVE_ASSIGN

template <class T>
struct is_nothrow_move_assignable : public integral_constant<bool, QSBOOST_IS_NOTHROW_MOVE_ASSIGN(T)>{};
template <class T> struct is_nothrow_move_assignable<T const> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T volatile> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T const volatile> : public false_type{};
template <class T> struct is_nothrow_move_assignable<T&> : public false_type{};
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) 
template <class T> struct is_nothrow_move_assignable<T&&> : public false_type{};
#endif

#elif !defined(QSBOOST_NO_CXX11_NOEXCEPT) && !defined(QSBOOST_NO_SFINAE_EXPR)

namespace detail{

template <class T, class Enable = void>
struct false_or_cpp11_noexcept_move_assignable: public ::qsboost::false_type {};

template <class T>
struct false_or_cpp11_noexcept_move_assignable <
        T,
        typename ::qsboost::enable_if_c<sizeof(T) && QSBOOST_NOEXCEPT_EXPR(::qsboost::declval<T&>() = ::qsboost::declval<T>())>::type
    > : public ::qsboost::integral_constant<bool, QSBOOST_NOEXCEPT_EXPR(::qsboost::declval<T&>() = ::qsboost::declval<T>())>
{};

}

template <class T>
struct is_nothrow_move_assignable : public integral_constant<bool, ::qsboost::detail::false_or_cpp11_noexcept_move_assignable<T>::value>{};

template <class T> struct is_nothrow_move_assignable<T const> : public ::qsboost::false_type {};
template <class T> struct is_nothrow_move_assignable<T const volatile> : public ::qsboost::false_type{};
template <class T> struct is_nothrow_move_assignable<T volatile> : public ::qsboost::false_type{};
template <class T> struct is_nothrow_move_assignable<T&> : public ::qsboost::false_type{};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct is_nothrow_move_assignable<T&&> : public ::qsboost::false_type{};
#endif

#else

template <class T>
struct is_nothrow_move_assignable : public integral_constant<bool,
   (::qsboost::has_trivial_move_assign<T>::value || ::qsboost::has_nothrow_assign<T>::value) &&  ! ::qsboost::is_array<T>::value>{};

#endif


template <> struct is_nothrow_move_assignable<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template <> struct is_nothrow_move_assignable<void const> : public false_type{};
template <> struct is_nothrow_move_assignable<void const volatile> : public false_type{};
template <> struct is_nothrow_move_assignable<void volatile> : public false_type{};
#endif

} // namespace boost

#endif // BOOST_TT_IS_NOTHROW_MOVE_ASSIGNABLE_HPP_INCLUDED


//  Copyright 2000 John Maddock (john@johnmaddock.co.uk)
//  Copyright 2002 Aleksey Gurtovoy (agurtovoy@meta-comm.com)
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_FUNCTION_HPP_INCLUDED
#define QSBOOST_TT_IS_FUNCTION_HPP_INCLUDED

#include <qsboost/type_traits/is_reference.hpp>
#include <qsboost/type_traits/detail/config.hpp>

#if !defined(QSBOOST_TT_TEST_MS_FUNC_SIGS)
#   include <qsboost/type_traits/detail/is_function_ptr_helper.hpp>
#else
#   include <qsboost/type_traits/detail/is_function_ptr_tester.hpp>
#   include <qsboost/type_traits/detail/yes_no_type.hpp>
#endif

// is a type a function?
// Please note that this implementation is unnecessarily complex:
// we could just use !is_convertible<T*, const volatile void*>::value,
// except that some compilers erroneously allow conversions from
// function pointers to void*.

namespace qsboost {

#if !defined( __CODEGEARC__ )

namespace detail {

#if !defined(QSBOOST_TT_TEST_MS_FUNC_SIGS)
template<bool is_ref = true>
struct is_function_chooser
{
   template< typename T > struct result_
      : public false_type {};
};

template <>
struct is_function_chooser<false>
{
    template< typename T > struct result_
        : public ::qsboost::type_traits::is_function_ptr_helper<T*> {};
};

template <typename T>
struct is_function_impl
    : public is_function_chooser< ::qsboost::is_reference<T>::value >
        ::QSBOOST_NESTED_TEMPLATE result_<T>
{
};

#else

template <typename T>
struct is_function_impl
{
#if QSBOOST_WORKAROUND(QSBOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(push)
#pragma warning(disable:6334)
#endif
    static T* t;
    QSBOOST_STATIC_CONSTANT(
        bool, value = sizeof(::qsboost::type_traits::is_function_ptr_tester(t))
        == sizeof(::qsboost::type_traits::yes_type)
        );
#if QSBOOST_WORKAROUND(QSBOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(pop)
#endif
};

template <typename T>
struct is_function_impl<T&> : public false_type
{};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <typename T>
struct is_function_impl<T&&> : public false_type
{};
#endif

#endif

} // namespace detail

#endif // !defined( __CODEGEARC__ )

#if defined( __CODEGEARC__ )
template <class T> struct is_function : integral_constant<bool, __is_function(T)> {};
#else
template <class T> struct is_function : integral_constant<bool, ::qsboost::detail::is_function_impl<T>::value> {};
#ifndef QSBOOST_NO_CXX11_RVALUE_REFERENCES
template <class T> struct is_function<T&&> : public false_type {};
#endif
#endif
} // namespace boost

#endif // BOOST_TT_IS_FUNCTION_HPP_INCLUDED


//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, Howard
//  Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef QSBOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED
#define QSBOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED

#include <qsboost/type_traits/detail/config.hpp>
#include <qsboost/detail/workaround.hpp>

#if !QSBOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(QSBOOST_TT_TEST_MS_FUNC_SIGS)
   //
   // Note: we use the "workaround" version for MSVC because it works for 
   // __stdcall etc function types, where as the partial specialisation
   // version does not do so.
   //
#   include <qsboost/type_traits/detail/is_mem_fun_pointer_impl.hpp>
#   include <qsboost/type_traits/remove_cv.hpp>
#   include <qsboost/type_traits/integral_constant.hpp>
#else
#   include <qsboost/type_traits/is_reference.hpp>
#   include <qsboost/type_traits/is_array.hpp>
#   include <qsboost/type_traits/detail/yes_no_type.hpp>
#   include <qsboost/type_traits/detail/is_mem_fun_pointer_tester.hpp>
#endif

namespace qsboost {

#if defined( __CODEGEARC__ )
template <class T> struct is_member_function_pointer : public integral_constant<bool, __is_member_function_pointer( T )> {};
#elif !QSBOOST_WORKAROUND(__BORLANDC__, < 0x600) && !defined(QSBOOST_TT_TEST_MS_FUNC_SIGS)

template <class T> struct is_member_function_pointer 
   : public ::qsboost::integral_constant<bool, ::qsboost::type_traits::is_mem_fun_pointer_impl<typename remove_cv<T>::type>::value>{};

#else

namespace detail {

#ifndef __BORLANDC__

template <bool>
struct is_mem_fun_pointer_select
{
   template <class T> struct result_ : public false_type{};
};

template <>
struct is_mem_fun_pointer_select<false>
{
    template <typename T> struct result_
    {
#if QSBOOST_WORKAROUND(QSBOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(push)
#pragma warning(disable:6334)
#endif
        static T* make_t;
        typedef result_<T> self_type;

        QSBOOST_STATIC_CONSTANT(
            bool, value = (
                1 == sizeof(::qsboost::type_traits::is_mem_fun_pointer_tester(self_type::make_t))
            ));
#if QSBOOST_WORKAROUND(QSBOOST_MSVC_FULL_VER, >= 140050000)
#pragma warning(pop)
#endif
    };
};

template <typename T>
struct is_member_function_pointer_impl
    : public is_mem_fun_pointer_select< 
      ::qsboost::is_reference<T>::value || ::qsboost::is_array<T>::value>::template result_<T>{};

template <typename T>
struct is_member_function_pointer_impl<T&> : public false_type{};

#else // Borland C++

template <typename T>
struct is_member_function_pointer_impl
{
   static T* m_t;
   QSBOOST_STATIC_CONSTANT(
              bool, value =
               (1 == sizeof(type_traits::is_mem_fun_pointer_tester(m_t))) );
};

template <typename T>
struct is_member_function_pointer_impl<T&>
{
   QSBOOST_STATIC_CONSTANT(bool, value = false);
};

#endif

template<> struct is_member_function_pointer_impl<void> : public false_type{};
#ifndef QSBOOST_NO_CV_VOID_SPECIALIZATIONS
template<> struct is_member_function_pointer_impl<void const> : public false_type{};
template<> struct is_member_function_pointer_impl<void const volatile> : public false_type{};
template<> struct is_member_function_pointer_impl<void volatile> : public false_type{};
#endif

} // namespace detail

template <class T>
struct is_member_function_pointer
   : public integral_constant<bool, ::qsboost::detail::is_member_function_pointer_impl<T>::value>{};

#endif

} // namespace boost

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED

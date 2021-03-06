
//  (C) Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_ASSIGNABLE_HPP_INCLUDED
#define QSBOOST_TT_IS_ASSIGNABLE_HPP_INCLUDED

#include <qsboost/type_traits/integral_constant.hpp>
#include <qsboost/detail/workaround.hpp>

namespace qsboost{

   template <class T, class U = T> struct is_assignable;

}

#if !defined(QSBOOST_NO_CXX11_DECLTYPE) && !QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1800)

#include <qsboost/type_traits/detail/yes_no_type.hpp>
#include <qsboost/type_traits/declval.hpp>

namespace qsboost{

   namespace detail{

      struct is_assignable_imp
      {
         template<typename T, typename U, typename = decltype(qsboost::declval<T>() = qsboost::declval<U>())>
         static qsboost::type_traits::yes_type test(int);

         template<typename, typename>
         static qsboost::type_traits::no_type test(...);
      };

   }

   template <class T, class U> struct is_assignable : public integral_constant<bool, sizeof(detail::is_assignable_imp::test<T, U>(0)) == sizeof(qsboost::type_traits::yes_type)>{};
   template <class T, std::size_t N, class U> struct is_assignable<T[N], U> : public is_assignable<T, U>{};
   template <class T, std::size_t N, class U> struct is_assignable<T(&)[N], U> : public is_assignable<T&, U>{};
   template <class T, class U> struct is_assignable<T[], U> : public is_assignable<T, U>{};
   template <class T, class U> struct is_assignable<T(&)[], U> : public is_assignable<T&, U>{};
   template <class U> struct is_assignable<void, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void const, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void volatile, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void const volatile, U> : public integral_constant<bool, false>{};

#else

#include <qsboost/type_traits/has_trivial_assign.hpp>
#include <qsboost/type_traits/remove_reference.hpp>

namespace qsboost{

   // We don't know how to implement this:
   template <class T, class U> struct is_assignable : public integral_constant<bool, false>{};
   template <class T, class U> struct is_assignable<T&, U> : public integral_constant<bool, is_pod<T>::value && is_pod<typename remove_reference<U>::type>::value>{};
   template <class T, class U> struct is_assignable<const T&, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void const, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void volatile, U> : public integral_constant<bool, false>{};
   template <class U> struct is_assignable<void const volatile, U> : public integral_constant<bool, false>{};
   /*
   template <> struct is_assignable<void, void> : public integral_constant<bool, false>{};
   template <> struct is_assignable<void const, void const> : public integral_constant<bool, false>{};
   template <> struct is_assignable<void volatile, void volatile> : public integral_constant<bool, false>{};
   template <> struct is_assignable<void const volatile, void const volatile> : public integral_constant<bool, false>{};
   */
#endif

} // namespace boost

#endif // BOOST_TT_IS_ASSIGNABLE_HPP_INCLUDED


//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef QSBOOST_TT_IS_UNSIGNED_HPP_INCLUDED
#define QSBOOST_TT_IS_UNSIGNED_HPP_INCLUDED

#include <qsboost/type_traits/is_integral.hpp>
#include <qsboost/type_traits/is_enum.hpp>
#include <qsboost/type_traits/remove_cv.hpp>

#include <climits>

namespace qsboost {

#if !defined( __CODEGEARC__ )

#if !(defined(QSBOOST_MSVC) && QSBOOST_MSVC <= 1310) &&\
    !(defined(__EDG_VERSION__) && __EDG_VERSION__ <= 238) &&\
    !defined(QSBOOST_NO_INCLASS_MEMBER_INITIALIZATION)

namespace detail{

template <class T>
struct is_unsigned_values
{
   //
   // Note that we cannot use BOOST_STATIC_CONSTANT here, using enum's
   // rather than "real" static constants simply doesn't work or give
   // the correct answer.
   //
   typedef typename remove_cv<T>::type no_cv_t;
   static const no_cv_t minus_one = (static_cast<no_cv_t>(-1));
   static const no_cv_t zero = (static_cast<no_cv_t>(0));
};

template <class T>
struct is_ununsigned_helper
{
   QSBOOST_STATIC_CONSTANT(bool, value = (::qsboost::detail::is_unsigned_values<T>::minus_one > ::qsboost::detail::is_unsigned_values<T>::zero));
};

template <bool integral_type>
struct is_unsigned_select_helper
{
   template <class T>
   struct rebind
   {
      typedef is_ununsigned_helper<T> type;
   };
};

template <>
struct is_unsigned_select_helper<false>
{
   template <class T>
   struct rebind
   {
      typedef false_type type;
   };
};

template <class T>
struct is_unsigned
{
   typedef ::qsboost::detail::is_unsigned_select_helper< ::qsboost::is_integral<T>::value || ::qsboost::is_enum<T>::value > selector;
   typedef typename selector::template rebind<T> binder;
   typedef typename binder::type type;
   QSBOOST_STATIC_CONSTANT(bool, value = type::value);
};

} // namespace detail

template <class T> struct is_unsigned : public integral_constant<bool, qsboost::detail::is_unsigned<T>::value> {};

#else

template <class T> struct is_unsigned : public false_type{};

#endif

#else // defined( __CODEGEARC__ )
template <class T> struct is_unsigned : public integral_constant<bool, __is_unsigned(T)> {};
#endif

template <> struct is_unsigned<unsigned char> : public true_type{};
template <> struct is_unsigned<const unsigned char> : public true_type{};
template <> struct is_unsigned<volatile unsigned char> : public true_type{};
template <> struct is_unsigned<const volatile unsigned char> : public true_type{};
template <> struct is_unsigned<unsigned short> : public true_type{};
template <> struct is_unsigned<const unsigned short> : public true_type{};
template <> struct is_unsigned<volatile unsigned short> : public true_type{};
template <> struct is_unsigned<const volatile unsigned short> : public true_type{};
template <> struct is_unsigned<unsigned int> : public true_type{};
template <> struct is_unsigned<const unsigned int> : public true_type{};
template <> struct is_unsigned<volatile unsigned int> : public true_type{};
template <> struct is_unsigned<const volatile unsigned int> : public true_type{};
template <> struct is_unsigned<unsigned long> : public true_type{};
template <> struct is_unsigned<const unsigned long> : public true_type{};
template <> struct is_unsigned<volatile unsigned long> : public true_type{};
template <> struct is_unsigned<const volatile unsigned long> : public true_type{};

template <> struct is_unsigned<signed char> : public false_type{};
template <> struct is_unsigned<const signed char> : public false_type{};
template <> struct is_unsigned<volatile signed char> : public false_type{};
template <> struct is_unsigned<const volatile signed char> : public false_type{};
template <> struct is_unsigned< short> : public false_type{};
template <> struct is_unsigned<const  short> : public false_type{};
template <> struct is_unsigned<volatile  short> : public false_type{};
template <> struct is_unsigned<const volatile  short> : public false_type{};
template <> struct is_unsigned< int> : public false_type{};
template <> struct is_unsigned<const  int> : public false_type{};
template <> struct is_unsigned<volatile  int> : public false_type{};
template <> struct is_unsigned<const volatile  int> : public false_type{};
template <> struct is_unsigned< long> : public false_type{};
template <> struct is_unsigned<const  long> : public false_type{};
template <> struct is_unsigned<volatile  long> : public false_type{};
template <> struct is_unsigned<const volatile  long> : public false_type{};
#ifdef QSBOOST_HAS_LONG_LONG
template <> struct is_unsigned< ::qsboost::ulong_long_type> : public true_type{};
template <> struct is_unsigned<const ::qsboost::ulong_long_type> : public true_type{};
template <> struct is_unsigned<volatile ::qsboost::ulong_long_type> : public true_type{};
template <> struct is_unsigned<const volatile ::qsboost::ulong_long_type> : public true_type{};

template <> struct is_unsigned< ::qsboost::long_long_type> : public false_type{};
template <> struct is_unsigned<const ::qsboost::long_long_type> : public false_type{};
template <> struct is_unsigned<volatile ::qsboost::long_long_type> : public false_type{};
template <> struct is_unsigned<const volatile ::qsboost::long_long_type> : public false_type{};
#endif
#if defined(CHAR_MIN) 
#if CHAR_MIN == 0
template <> struct is_unsigned<char> : public true_type{};
template <> struct is_unsigned<const char> : public true_type{};
template <> struct is_unsigned<volatile char> : public true_type{};
template <> struct is_unsigned<const volatile char> : public true_type{};
#else
template <> struct is_unsigned<char> : public false_type{};
template <> struct is_unsigned<const char> : public false_type{};
template <> struct is_unsigned<volatile char> : public false_type{};
template <> struct is_unsigned<const volatile char> : public false_type{};
#endif
#endif
#if !defined(QSBOOST_NO_INTRINSIC_WCHAR_T) && defined(WCHAR_MIN)
#if WCHAR_MIN == 0
template <> struct is_unsigned<wchar_t> : public true_type{};
template <> struct is_unsigned<const wchar_t> : public true_type{};
template <> struct is_unsigned<volatile wchar_t> : public true_type{};
template <> struct is_unsigned<const volatile wchar_t> : public true_type{};
#else
template <> struct is_unsigned<wchar_t> : public false_type{};
template <> struct is_unsigned<const wchar_t> : public false_type{};
template <> struct is_unsigned<volatile wchar_t> : public false_type{};
template <> struct is_unsigned<const volatile wchar_t> : public false_type{};
#endif
#endif
} // namespace boost

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED


//  (C) Copyright John Maddock 2005.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef QSBOOST_TT_IS_SIGNED_HPP_INCLUDED
#define QSBOOST_TT_IS_SIGNED_HPP_INCLUDED

#include <qsboost/type_traits/is_integral.hpp>
#include <qsboost/type_traits/remove_cv.hpp>
#include <qsboost/type_traits/is_enum.hpp>
#include <climits>

namespace qsboost {

#if !defined( __CODEGEARC__ )

#if !(defined(QSBOOST_MSVC) && QSBOOST_MSVC <= 1310) && \
    !(defined(__EDG_VERSION__) && __EDG_VERSION__ <= 238) &&\
    !defined(QSBOOST_NO_INCLASS_MEMBER_INITIALIZATION)

namespace detail{

template <class T>
struct is_signed_values
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
struct is_signed_helper
{
   typedef typename remove_cv<T>::type no_cv_t;
   QSBOOST_STATIC_CONSTANT(bool, value = (!(::qsboost::detail::is_signed_values<T>::minus_one  > qsboost::detail::is_signed_values<T>::zero)));
};

template <bool integral_type>
struct is_signed_select_helper
{
   template <class T>
   struct rebind
   {
      typedef is_signed_helper<T> type;
   };
};

template <>
struct is_signed_select_helper<false>
{
   template <class T>
   struct rebind
   {
      typedef false_type type;
   };
};

template <class T>
struct is_signed_impl
{
   typedef ::qsboost::detail::is_signed_select_helper< ::qsboost::is_integral<T>::value || ::qsboost::is_enum<T>::value> selector;
   typedef typename selector::template rebind<T> binder;
   typedef typename binder::type type;
   QSBOOST_STATIC_CONSTANT(bool, value = type::value);
};

}

template <class T> struct is_signed : public integral_constant<bool, qsboost::detail::is_signed_impl<T>::value> {};

#else

template <class T> struct is_signed : public false_type{};

#endif

#else //defined( __CODEGEARC__ )
   template <class T> struct is_signed : public integral_constant<bool, __is_signed(T)>{};
#endif

template <> struct is_signed<signed char> : public true_type{};
template <> struct is_signed<const signed char> : public true_type{};
template <> struct is_signed<volatile signed char> : public true_type{};
template <> struct is_signed<const volatile signed char> : public true_type{};
template <> struct is_signed<short> : public true_type{};
template <> struct is_signed<const short> : public true_type{};
template <> struct is_signed<volatile short> : public true_type{};
template <> struct is_signed<const volatile short> : public true_type{};
template <> struct is_signed<int> : public true_type{};
template <> struct is_signed<const int> : public true_type{};
template <> struct is_signed<volatile int> : public true_type{};
template <> struct is_signed<const volatile int> : public true_type{};
template <> struct is_signed<long> : public true_type{};
template <> struct is_signed<const long> : public true_type{};
template <> struct is_signed<volatile long> : public true_type{};
template <> struct is_signed<const volatile long> : public true_type{};

template <> struct is_signed<unsigned char> : public false_type{};
template <> struct is_signed<const unsigned char> : public false_type{};
template <> struct is_signed<volatile unsigned char> : public false_type{};
template <> struct is_signed<const volatile unsigned char> : public false_type{};
template <> struct is_signed<unsigned short> : public false_type{};
template <> struct is_signed<const unsigned short> : public false_type{};
template <> struct is_signed<volatile unsigned short> : public false_type{};
template <> struct is_signed<const volatile unsigned short> : public false_type{};
template <> struct is_signed<unsigned int> : public false_type{};
template <> struct is_signed<const unsigned int> : public false_type{};
template <> struct is_signed<volatile unsigned int> : public false_type{};
template <> struct is_signed<const volatile unsigned int> : public false_type{};
template <> struct is_signed<unsigned long> : public false_type{};
template <> struct is_signed<const unsigned long> : public false_type{};
template <> struct is_signed<volatile unsigned long> : public false_type{};
template <> struct is_signed<const volatile unsigned long> : public false_type{};
#ifdef QSBOOST_HAS_LONG_LONG
template <> struct is_signed< ::qsboost::long_long_type> : public true_type{};
template <> struct is_signed<const ::qsboost::long_long_type> : public true_type{};
template <> struct is_signed<volatile ::qsboost::long_long_type> : public true_type{};
template <> struct is_signed<const volatile ::qsboost::long_long_type> : public true_type{};

template <> struct is_signed< ::qsboost::ulong_long_type> : public false_type{};
template <> struct is_signed<const ::qsboost::ulong_long_type> : public false_type{};
template <> struct is_signed<volatile ::qsboost::ulong_long_type> : public false_type{};
template <> struct is_signed<const volatile ::qsboost::ulong_long_type> : public false_type{};
#endif
#if defined(CHAR_MIN) 
#if CHAR_MIN != 0
template <> struct is_signed<char> : public true_type{};
template <> struct is_signed<const char> : public true_type{};
template <> struct is_signed<volatile char> : public true_type{};
template <> struct is_signed<const volatile char> : public true_type{};
#else
template <> struct is_signed<char> : public false_type{};
template <> struct is_signed<const char> : public false_type{};
template <> struct is_signed<volatile char> : public false_type{};
template <> struct is_signed<const volatile char> : public false_type{};
#endif
#endif
#if defined(WCHAR_MIN) && !defined(QSBOOST_NO_INTRINSIC_WCHAR_T)
#if WCHAR_MIN != 0
template <> struct is_signed<wchar_t> : public true_type{};
template <> struct is_signed<const wchar_t> : public true_type{};
template <> struct is_signed<volatile wchar_t> : public true_type{};
template <> struct is_signed<const volatile wchar_t> : public true_type{};
#else
template <> struct is_signed<wchar_t> : public false_type{};
template <> struct is_signed<const wchar_t> : public false_type{};
template <> struct is_signed<volatile wchar_t> : public false_type{};
template <> struct is_signed<const volatile wchar_t> : public false_type{};
#endif
#endif
} // namespace boost

#endif // BOOST_TT_IS_MEMBER_FUNCTION_POINTER_HPP_INCLUDED

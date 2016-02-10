
//  (C) Copyright John Maddock 2007.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_MAKE_UNSIGNED_HPP_INCLUDED
#define QSBOOST_TT_MAKE_UNSIGNED_HPP_INCLUDED

#include <qsboost/type_traits/conditional.hpp>
#include <qsboost/type_traits/is_integral.hpp>
#include <qsboost/type_traits/is_signed.hpp>
#include <qsboost/type_traits/is_unsigned.hpp>
#include <qsboost/type_traits/is_enum.hpp>
#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/type_traits/remove_cv.hpp>
#include <qsboost/type_traits/is_const.hpp>
#include <qsboost/type_traits/is_volatile.hpp>
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/add_volatile.hpp>
#include <qsboost/static_assert.hpp>

namespace qsboost {

template <class T>
struct make_unsigned
{
private:
   QSBOOST_STATIC_ASSERT_MSG((::qsboost::is_integral<T>::value || ::qsboost::is_enum<T>::value), "The template argument to make_unsigned must be an integer or enum type.");
   QSBOOST_STATIC_ASSERT_MSG((! ::qsboost::is_same<typename remove_cv<T>::type, bool>::value), "The template argument to make_unsigned must not be the type bool");

   typedef typename remove_cv<T>::type t_no_cv;
   typedef typename conditional<
      (::qsboost::is_unsigned<T>::value && ::qsboost::is_integral<T>::value 
      && ! ::qsboost::is_same<t_no_cv, char>::value
      && ! ::qsboost::is_same<t_no_cv, wchar_t>::value
      && ! ::qsboost::is_same<t_no_cv, bool>::value),
      T,
      typename conditional<
         (::qsboost::is_integral<T>::value 
         && ! ::qsboost::is_same<t_no_cv, char>::value
         && ! ::qsboost::is_same<t_no_cv, wchar_t>::value
         && ! ::qsboost::is_same<t_no_cv, bool>::value),
         typename conditional<
            is_same<t_no_cv, signed char>::value,
            unsigned char,
            typename conditional<
               is_same<t_no_cv, short>::value,
               unsigned short,
               typename conditional<
                  is_same<t_no_cv, int>::value,
                  unsigned int,
                  typename conditional<
                     is_same<t_no_cv, long>::value,
                     unsigned long,
#if defined(QSBOOST_HAS_LONG_LONG)
#ifdef QSBOOST_HAS_INT128
                     typename conditional<
                        sizeof(t_no_cv) == sizeof(qsboost::ulong_long_type), 
                        qsboost::ulong_long_type, 
                        qsboost::uint128_type
                     >::type
#else
                     qsboost::ulong_long_type
#endif
#elif defined(QSBOOST_HAS_MS_INT64)
                     unsigned __int64
#else
                     unsigned long
#endif
                  >::type
               >::type
            >::type
         >::type,
         // Not a regular integer type:
         typename conditional<
            sizeof(t_no_cv) == sizeof(unsigned char),
            unsigned char,
            typename conditional<
               sizeof(t_no_cv) == sizeof(unsigned short),
               unsigned short,
               typename conditional<
                  sizeof(t_no_cv) == sizeof(unsigned int),
                  unsigned int,
                  typename conditional<
                     sizeof(t_no_cv) == sizeof(unsigned long),
                     unsigned long,
#if defined(QSBOOST_HAS_LONG_LONG)
#ifdef QSBOOST_HAS_INT128
                     typename conditional<
                        sizeof(t_no_cv) == sizeof(qsboost::ulong_long_type), 
                        qsboost::ulong_long_type, 
                        qsboost::uint128_type
                     >::type
#else
                     qsboost::ulong_long_type
#endif
#elif defined(QSBOOST_HAS_MS_INT64)
                     unsigned __int64
#else
                     unsigned long
#endif
                  >::type
               >::type
            >::type
         >::type
      >::type
   >::type base_integer_type;
   
   // Add back any const qualifier:
   typedef typename conditional<
      is_const<T>::value,
      typename add_const<base_integer_type>::type,
      base_integer_type
   >::type const_base_integer_type;
public:
   // Add back any volatile qualifier:
   typedef typename conditional<
      is_volatile<T>::value,
      typename add_volatile<const_base_integer_type>::type,
      const_base_integer_type
   >::type type;
};

} // namespace boost

#endif // BOOST_TT_ADD_REFERENCE_HPP_INCLUDED


//  (C) Copyright John Maddock 2000. 
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_POLYMORPHIC_HPP
#define QSBOOST_TT_IS_POLYMORPHIC_HPP

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>
#ifndef QSBOOST_IS_POLYMORPHIC
#include <qsboost/type_traits/is_class.hpp>
#endif
#include <qsboost/detail/workaround.hpp>

#if defined(QSBOOST_MSVC) && (QSBOOST_MSVC >= 1700)
#pragma warning(push)
#pragma warning(disable:4250)
#endif

namespace qsboost{

#ifndef QSBOOST_IS_POLYMORPHIC

namespace detail{

template <class T>
struct is_polymorphic_imp1
{
# if QSBOOST_WORKAROUND(__MWERKS__, <= 0x2407) // CWPro7 should return false always.
    typedef char d1, (&d2)[2];
# else 
   struct d1 : public T
   {
      d1();
#  if !defined(__GNUC__) // this raises warnings with some classes, and buys nothing with GCC
      ~d1()throw();
#  endif 
      char padding[256];
   private:
      // keep some picky compilers happy:
      d1(const d1&);
      d1& operator=(const d1&);
   };
   struct d2 : public T
   {
      d2();
      virtual ~d2()throw();
#  if !defined(QSBOOST_MSVC) && !defined(__ICL)
      // for some reason this messes up VC++ when T has virtual bases,
      // probably likewise for compilers that use the same ABI:
      struct unique{};
      virtual void unique_name_to_qsboost5487629(unique*);
#  endif
      char padding[256];
   private:
      // keep some picky compilers happy:
      d2(const d2&);
      d2& operator=(const d2&);
   };
# endif 
   QSBOOST_STATIC_CONSTANT(bool, value = (sizeof(d2) == sizeof(d1)));
};

template <class T> struct is_polymorphic_imp1<T const> : public is_polymorphic_imp1<T>{};
template <class T> struct is_polymorphic_imp1<T const volatile> : public is_polymorphic_imp1<T>{};
template <class T> struct is_polymorphic_imp1<T volatile> : public is_polymorphic_imp1<T>{};

template <class T>
struct is_polymorphic_imp2
{
   QSBOOST_STATIC_CONSTANT(bool, value = false);
};

template <bool is_class>
struct is_polymorphic_selector
{
   template <class T>
   struct rebind
   {
      typedef is_polymorphic_imp2<T> type;
   };
};

template <>
struct is_polymorphic_selector<true>
{
   template <class T>
   struct rebind
   {
      typedef is_polymorphic_imp1<T> type;
   };
};

template <class T>
struct is_polymorphic_imp
{
   typedef is_polymorphic_selector< ::qsboost::is_class<T>::value> selector;
   typedef typename selector::template rebind<T> binder;
   typedef typename binder::type imp_type;
   QSBOOST_STATIC_CONSTANT(bool, value = imp_type::value);
};

} // namespace detail

template <class T> struct is_polymorphic : public integral_constant<bool, ::qsboost::detail::is_polymorphic_imp<T>::value> {};

#else // BOOST_IS_POLYMORPHIC

template <class T> struct is_polymorphic : public integral_constant<bool, QSBOOST_IS_POLYMORPHIC(T)> {};

#endif

} // namespace boost

#if defined(QSBOOST_MSVC) && (QSBOOST_MSVC >= 1700)
#pragma warning(pop)
#endif

#endif

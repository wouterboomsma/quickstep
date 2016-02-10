//  (C) Copyright John Maddock 2015. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP
#define QSBOOST_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

#if (QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1400)) \
   || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
   || QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840)) \
   || QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3202)) \
   || QSBOOST_WORKAROUND(QSBOOST_INTEL_CXX_VERSION, QSBOOST_TESTED_AT(810)) )


namespace qsboost{
   namespace mpl
   {
      template <bool B> struct bool_;
      template <class I, I val> struct integral_c;
      struct integral_c_tag;
   }
}

#else

namespace qsmpl_{

   template <bool B> struct bool_;
   template <class I, I val> struct integral_c;
   struct integral_c_tag;
}

namespace qsboost
{
   namespace mpl
   {
      using ::qsmpl_::bool_;
      using ::qsmpl_::integral_c;
      using ::qsmpl_::integral_c_tag;
   }
}

#endif

namespace qsboost{

   template <class T, T val>
   struct integral_constant
   {
      typedef mpl::integral_c_tag tag;
      typedef T value_type;
      typedef integral_constant<T, val> type;
      static const T value = val;
      //
      // This helper function is just to disable type-punning 
      // warnings from GCC:
      //
      template <class U>
      static U& dereference(U* p) { return *p; }

      operator const mpl::integral_c<T, val>& ()const
      {
         static const char data[sizeof(long)] = { 0 };
         return dereference(reinterpret_cast<const mpl::integral_c<T, val>*>(&data));
      }
      QSBOOST_CONSTEXPR operator T()const { return val; }
   };

   template <class T, T val>
   T const integral_constant<T, val>::value;
      
   template <bool val>
   struct integral_constant<bool, val>
   {
      typedef mpl::integral_c_tag tag;
      typedef bool value_type;
      typedef integral_constant<bool, val> type;
      static const bool value = val;
      //
      // This helper function is just to disable type-punning 
      // warnings from GCC:
      //
      template <class T>
      static T& dereference(T* p) { return *p; }

      operator const mpl::bool_<val>& ()const
      {
         static const char data = 0;
         return dereference(reinterpret_cast<const mpl::bool_<val>*>(&data));
      }
      QSBOOST_CONSTEXPR operator bool()const { return val; }
   };

   template <bool val>
   bool const integral_constant<bool, val>::value;

   typedef integral_constant<bool, true> true_type;
   typedef integral_constant<bool, false> false_type;

}

#endif

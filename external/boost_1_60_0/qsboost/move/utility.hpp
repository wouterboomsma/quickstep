//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2012.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/move for documentation.
//
//////////////////////////////////////////////////////////////////////////////

//! \file
//! This header includes core utilities from <tt><boost/move/utility_core.hpp></tt> and defines
//! some more advanced utilities such as:

#ifndef QSBOOST_MOVE_MOVE_UTILITY_HPP
#define QSBOOST_MOVE_MOVE_UTILITY_HPP

#ifndef QSBOOST_CONFIG_HPP
#  include <qsboost/config.hpp>
#endif
#
#if defined(QSBOOST_HAS_PRAGMA_ONCE)
#  pragma once
#endif

#include <qsboost/move/detail/config_begin.hpp>
#include <qsboost/move/utility_core.hpp>
#include <qsboost/move/traits.hpp>

#if defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(QSBOOST_MOVE_DOXYGEN_INVOKED)

   namespace qsboost {

   //////////////////////////////////////////////////////////////////////////////
   //
   //                            move_if_noexcept()
   //
   //////////////////////////////////////////////////////////////////////////////

   template <class T>
   inline typename ::qsboost::move_detail::enable_if_c
      < enable_move_utility_emulation<T>::value && !has_move_emulation_enabled<T>::value
      , typename ::qsboost::move_detail::add_const<T>::type &
      >::type
         move_if_noexcept(T& x) QSBOOST_NOEXCEPT
   {
      return x;
   }

   template <class T>
   inline typename ::qsboost::move_detail::enable_if_c
      < enable_move_utility_emulation<T>::value && has_move_emulation_enabled<T>::value
            && ::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value, rv<T>&>::type
         move_if_noexcept(T& x) QSBOOST_NOEXCEPT
   {
      return *static_cast<rv<T>* >(::qsboost::move_detail::addressof(x));
   }

   template <class T>
   inline typename ::qsboost::move_detail::enable_if_c
      < enable_move_utility_emulation<T>::value && has_move_emulation_enabled<T>::value
            && ::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value
      , rv<T>&
      >::type
         move_if_noexcept(rv<T>& x) QSBOOST_NOEXCEPT
   {
      return x;
   }

   template <class T>
   inline typename ::qsboost::move_detail::enable_if_c
      < enable_move_utility_emulation<T>::value && has_move_emulation_enabled<T>::value
            && !::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value
      , typename ::qsboost::move_detail::add_const<T>::type &
      >::type
         move_if_noexcept(T& x) QSBOOST_NOEXCEPT
   {
      return x;
   }

   template <class T>
   inline typename ::qsboost::move_detail::enable_if_c
      < enable_move_utility_emulation<T>::value && has_move_emulation_enabled<T>::value
            && !::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value
      , typename ::qsboost::move_detail::add_const<T>::type &
      >::type
         move_if_noexcept(rv<T>& x) QSBOOST_NOEXCEPT
   {
      return x;
   }

   }  //namespace boost

#else    //#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && !defined(BOOST_MOVE_DOXYGEN_INVOKED)

   #if defined(QSBOOST_MOVE_USE_STANDARD_LIBRARY_MOVE)
      #include <utility>

      namespace qsboost{

      using ::std::move_if_noexcept;

      }  //namespace boost

   #else //!BOOST_MOVE_USE_STANDARD_LIBRARY_MOVE

      namespace qsboost {

      //////////////////////////////////////////////////////////////////////////////
      //
      //                            move_if_noexcept()
      //
      //////////////////////////////////////////////////////////////////////////////
      #if defined(QSBOOST_MOVE_DOXYGEN_INVOKED)
         //! This function provides a way to convert a reference into a rvalue reference
         //! in compilers with rvalue references. For other compilers converts T & into
         //! <i>::boost::rv<T> &</i> so that move emulation is activated. Reference
         //! would be converted to rvalue reference only if input type is nothrow move
         //! constructible or if it has no copy constructor. In all other cases const
         //! reference would be returned
         template <class T>
         rvalue_reference_or_const_lvalue_reference move_if_noexcept(input_reference) noexcept;

      #else //BOOST_MOVE_DOXYGEN_INVOKED

         template <class T>
         typename ::qsboost::move_detail::enable_if_c
            < ::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value, T&&>::type
               move_if_noexcept(T& x) QSBOOST_NOEXCEPT
         {  return ::qsboost::move(x);   }

         template <class T>
         typename ::qsboost::move_detail::enable_if_c
            < !::qsboost::move_detail::is_nothrow_move_constructible_or_uncopyable<T>::value, const T&>::type
               move_if_noexcept(T& x) QSBOOST_NOEXCEPT
         {  return x;  }

      #endif //BOOST_MOVE_DOXYGEN_INVOKED

      }  //namespace boost {

   #endif   //#if defined(BOOST_MOVE_USE_STANDARD_LIBRARY_MOVE)

#endif   //BOOST_NO_CXX11_RVALUE_REFERENCES

#include <qsboost/move/detail/config_end.hpp>

#endif //#ifndef BOOST_MOVE_MOVE_UTILITY_HPP

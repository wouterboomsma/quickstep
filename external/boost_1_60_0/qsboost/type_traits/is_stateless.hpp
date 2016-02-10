
//  (C) Copyright Steve Cleary, Beman Dawes, Howard Hinnant & John Maddock 2000.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_IS_STATELESS_HPP_INCLUDED
#define QSBOOST_TT_IS_STATELESS_HPP_INCLUDED

#include <qsboost/type_traits/has_trivial_constructor.hpp>
#include <qsboost/type_traits/has_trivial_copy.hpp>
#include <qsboost/type_traits/has_trivial_destructor.hpp>
#include <qsboost/type_traits/is_class.hpp>
#include <qsboost/type_traits/is_empty.hpp>
#include <qsboost/config.hpp>

namespace qsboost {

template <typename T>
struct is_stateless
 : public integral_constant<bool,  
      (::qsboost::has_trivial_constructor<T>::value
      && ::qsboost::has_trivial_copy<T>::value
      && ::qsboost::has_trivial_destructor<T>::value
      && ::qsboost::is_class<T>::value
      && ::qsboost::is_empty<T>::value)>
{};

} // namespace boost

#endif // BOOST_TT_IS_STATELESS_HPP_INCLUDED

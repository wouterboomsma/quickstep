
//  Copyright (c) 2014 Agustin Berge
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.


#ifndef QSBOOST_TT_IS_FINAL_HPP_INCLUDED
#define QSBOOST_TT_IS_FINAL_HPP_INCLUDED

#include <qsboost/type_traits/intrinsics.hpp>
#include <qsboost/type_traits/integral_constant.hpp>
#ifdef QSBOOST_IS_FINAL
#include <qsboost/type_traits/remove_cv.hpp>
#endif

namespace qsboost {

#ifdef QSBOOST_IS_FINAL
template <class T> struct is_final : public integral_constant<bool, QSBOOST_IS_FINAL(typename remove_cv<T>::type)> {};
#else
template <class T> struct is_final : public integral_constant<bool, false> {};
#endif

} // namespace boost

#endif // BOOST_TT_IS_FINAL_HPP_INCLUDED

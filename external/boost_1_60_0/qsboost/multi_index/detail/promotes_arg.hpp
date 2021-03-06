/* Copyright 2003-2014 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_DETAIL_PROMOTES_ARG_HPP
#define QSBOOST_MULTI_INDEX_DETAIL_PROMOTES_ARG_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <qsboost/mpl/bool.hpp>
#include <qsboost/type_traits/intrinsics.hpp>

/* Metafunctions to check if f(arg1,arg2) promotes either arg1 to the type of
 * arg2 or viceversa. By default, (i.e. if it cannot be determined), no
 * promotion is assumed.
 */

#if !defined(QSBOOST_IS_CONVERTIBLE)

namespace qsboost{

namespace multi_index{

namespace detail{

template<typename F,typename Arg1,typename Arg2>
struct promotes_1st_arg:mpl::false_{};

template<typename F,typename Arg1,typename Arg2>
struct promotes_2nd_arg:mpl::false_{};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#else

#include <qsboost/mpl/and.hpp>
#include <qsboost/mpl/not.hpp>
#include <qsboost/multi_index/detail/is_transparent.hpp>
#include <qsboost/type_traits/is_convertible.hpp>

namespace qsboost{

namespace multi_index{

namespace detail{
  
template<typename F,typename Arg1,typename Arg2>
struct promotes_1st_arg:
  mpl::and_<
    mpl::not_<is_transparent<F,Arg1,Arg2> >,
    is_convertible<const Arg1,Arg2>,
    is_transparent<F,Arg2,Arg2>
  >
{};

template<typename F,typename Arg1,typename Arg2>
struct promotes_2nd_arg:
  mpl::and_<
    mpl::not_<is_transparent<F,Arg1,Arg2> >,
    is_convertible<const Arg2,Arg1>,
    is_transparent<F,Arg1,Arg1>
  >
{};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#endif /* defined(BOOST_IS_CONVERTIBLE) */
#endif

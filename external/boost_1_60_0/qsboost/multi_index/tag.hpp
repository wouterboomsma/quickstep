/* Copyright 2003-2013 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_TAG_HPP
#define QSBOOST_MULTI_INDEX_TAG_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <qsboost/multi_index/detail/no_duplicate_tags.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/transform.hpp>
#include <qsboost/mpl/vector.hpp>
#include <qsboost/preprocessor/facilities/intercept.hpp> 
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp> 
#include <qsboost/preprocessor/repetition/enum_params.hpp> 
#include <qsboost/static_assert.hpp>
#include <qsboost/type_traits/is_base_and_derived.hpp>

/* A wrapper of mpl::vector used to hide MPL from the user.
 * tag contains types used as tag names for indices in get() functions.
 */

/* This user_definable macro limits the number of elements of a tag;
 * useful for shortening resulting symbol names (MSVC++ 6.0, for instance,
 * has problems coping with very long symbol names.)
 */

#if !defined(QSBOOST_MULTI_INDEX_LIMIT_TAG_SIZE)
#define QSBOOST_MULTI_INDEX_LIMIT_TAG_SIZE QSBOOST_MPL_LIMIT_VECTOR_SIZE
#endif

#if QSBOOST_MULTI_INDEX_LIMIT_TAG_SIZE<QSBOOST_MPL_LIMIT_VECTOR_SIZE
#define QSBOOST_MULTI_INDEX_TAG_SIZE QSBOOST_MULTI_INDEX_LIMIT_TAG_SIZE
#else
#define QSBOOST_MULTI_INDEX_TAG_SIZE QSBOOST_MPL_LIMIT_VECTOR_SIZE
#endif

namespace qsboost{

namespace multi_index{

namespace detail{

struct tag_marker{};

template<typename T>
struct is_tag
{
  QSBOOST_STATIC_CONSTANT(bool,value=(is_base_and_derived<tag_marker,T>::value));
};

} /* namespace multi_index::detail */

template<
  QSBOOST_PP_ENUM_BINARY_PARAMS(
    QSBOOST_MULTI_INDEX_TAG_SIZE,
    typename T,
    =mpl::na QSBOOST_PP_INTERCEPT) 
>
struct tag:private detail::tag_marker
{
  /* The mpl::transform pass produces shorter symbols (without
   * trailing mpl::na's.)
   */

  typedef typename mpl::transform<
    mpl::vector<QSBOOST_PP_ENUM_PARAMS(QSBOOST_MULTI_INDEX_TAG_SIZE,T)>,
    mpl::identity<mpl::_1>
  >::type type;

  QSBOOST_STATIC_ASSERT(detail::no_duplicate_tags<type>::value);
};

} /* namespace multi_index */

} /* namespace boost */

#undef QSBOOST_MULTI_INDEX_TAG_SIZE

#endif

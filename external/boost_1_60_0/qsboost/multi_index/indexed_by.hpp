/* Copyright 2003-2013 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_INDEXED_BY_HPP
#define QSBOOST_MULTI_INDEX_INDEXED_BY_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <qsboost/mpl/vector.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/control/expr_if.hpp>
#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp> 

/* An alias to mpl::vector used to hide MPL from the user.
 * indexed_by contains the index specifiers for instantiation
 * of a multi_index_container.
 */

/* This user_definable macro limits the number of elements of an index list;
 * useful for shortening resulting symbol names (MSVC++ 6.0, for instance,
 * has problems coping with very long symbol names.)
 */

#if !defined(QSBOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE)
#define QSBOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE QSBOOST_MPL_LIMIT_VECTOR_SIZE
#endif

#if QSBOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE<QSBOOST_MPL_LIMIT_VECTOR_SIZE
#define QSBOOST_MULTI_INDEX_INDEXED_BY_SIZE \
  QSBOOST_MULTI_INDEX_LIMIT_INDEXED_BY_SIZE
#else
#define QSBOOST_MULTI_INDEX_INDEXED_BY_SIZE QSBOOST_MPL_LIMIT_VECTOR_SIZE
#endif

#define QSBOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM(z,n,var) \
  typename QSBOOST_PP_CAT(var,n) QSBOOST_PP_EXPR_IF(n,=mpl::na)

namespace qsboost{

namespace multi_index{

template<
  QSBOOST_PP_ENUM(
    QSBOOST_MULTI_INDEX_INDEXED_BY_SIZE,
    QSBOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM,T)
>
struct indexed_by:
  mpl::vector<QSBOOST_PP_ENUM_PARAMS(QSBOOST_MULTI_INDEX_INDEXED_BY_SIZE,T)>
{
};

} /* namespace multi_index */

} /* namespace boost */

#undef QSBOOST_MULTI_INDEX_INDEXED_BY_TEMPLATE_PARM
#undef QSBOOST_MULTI_INDEX_INDEXED_BY_SIZE

#endif

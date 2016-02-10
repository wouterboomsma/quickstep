/* Copyright 2003-2013 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_DETAIL_BASE_TYPE_HPP
#define QSBOOST_MULTI_INDEX_DETAIL_BASE_TYPE_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <qsboost/detail/workaround.hpp>
#include <qsboost/mpl/at.hpp>
#include <qsboost/mpl/apply.hpp>
#include <qsboost/mpl/size.hpp>
#include <qsboost/multi_index/detail/index_base.hpp>
#include <qsboost/multi_index/detail/is_index_list.hpp>
#include <qsboost/static_assert.hpp>

namespace qsboost{

namespace multi_index{

namespace detail{

/* MPL machinery to construct a linear hierarchy of indices out of
 * a index list.
 */

struct index_applier
{
  template<typename IndexSpecifierMeta,typename SuperMeta>
  struct apply
  {
    typedef typename IndexSpecifierMeta::type            index_specifier;
    typedef typename index_specifier::
      QSBOOST_NESTED_TEMPLATE index_class<SuperMeta>::type type;
  }; 
};

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
struct nth_layer
{
  QSBOOST_STATIC_CONSTANT(int,length=mpl::size<IndexSpecifierList>::value);

  typedef typename  mpl::eval_if_c<
    N==length,
    mpl::identity<index_base<Value,IndexSpecifierList,Allocator> >,
    mpl::apply2<
      index_applier,
      mpl::at_c<IndexSpecifierList,N>,
      nth_layer<N+1,Value,IndexSpecifierList,Allocator>
    >
  >::type type;
};

template<typename Value,typename IndexSpecifierList,typename Allocator>
struct multi_index_base_type:nth_layer<0,Value,IndexSpecifierList,Allocator>
{
  QSBOOST_STATIC_ASSERT(detail::is_index_list<IndexSpecifierList>::value);
};

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#endif

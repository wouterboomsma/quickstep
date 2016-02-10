
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_DETAIL_TO_SEQUENCE_HPP_INCLUDED
#define QSBOOST_FT_DETAIL_TO_SEQUENCE_HPP_INCLUDED

#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/is_sequence.hpp>
#include <qsboost/mpl/placeholders.hpp>
#include <qsboost/type_traits/add_reference.hpp>

#include <qsboost/function_types/is_callable_builtin.hpp>

namespace qsboost { namespace function_types { namespace detail {

// wrap first arguments in components, if callable builtin type
template<typename T>
struct to_sequence
{
  typedef typename
   mpl::eval_if
   < is_callable_builtin<T>
   , to_sequence< components<T> >
   , mpl::identity< T >
   >::type
  type;
};

// reduce template instantiations, if possible
template<typename T, typename U>
struct to_sequence< components<T,U> > 
{
  typedef typename components<T,U>::types type;
};

} } } // namespace ::boost::function_types::detail

#endif



// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_PARAMETER_TYPES_HPP_INCLUDED
#define QSBOOST_FT_PARAMETER_TYPES_HPP_INCLUDED

#include <qsboost/blank.hpp>
#include <qsboost/mpl/if.hpp>

#include <qsboost/mpl/aux_/lambda_support.hpp>

#include <qsboost/mpl/pop_front.hpp>

#include <qsboost/function_types/is_callable_builtin.hpp>
#include <qsboost/function_types/components.hpp>

namespace qsboost 
{ 
  namespace function_types 
  {
    using mpl::placeholders::_;
 
    template< typename T, typename ClassTypeTransform = add_reference<_> >
    struct parameter_types;

    namespace detail
    {
      template<typename T, typename ClassTypeTransform> 
      struct parameter_types_impl
        : mpl::pop_front
          < typename function_types::components<T,ClassTypeTransform>::types 
          >::type
      { };
    }

    template<typename T, typename ClassTypeTransform> struct parameter_types
      : mpl::if_
        < function_types::is_callable_builtin<T>
        , detail::parameter_types_impl<T,ClassTypeTransform>, qsboost::blank
        >::type
    {
      QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,parameter_types,(T,ClassTypeTransform)) 
    };
  }
}

#endif


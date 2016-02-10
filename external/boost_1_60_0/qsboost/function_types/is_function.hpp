
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).
//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_IS_FUNCTION_HPP_INCLUDED
#define QSBOOST_FT_IS_FUNCTION_HPP_INCLUDED

#include <qsboost/mpl/aux_/lambda_support.hpp>

#include <qsboost/function_types/components.hpp>

namespace qsboost 
{ 
  namespace function_types 
  {
    template< typename T, typename Tag = null_tag > 
    struct is_function
      : function_types::represents
        < function_types::components<T>
        , function_types::tag<Tag ,detail::function_tag> 
        >
    { 
      QSBOOST_MPL_AUX_LAMBDA_SUPPORT(2,is_function,(T,Tag))
    };
  }
} 

#endif


/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_FUNCTION_FUNCTION_HPP
#define QSBOOST_PHOENIX_FUNCTION_FUNCTION_HPP

#include <qsboost/phoenix/config.hpp>
//#include <boost/phoenix/function/function_handling.hpp>
#include <qsboost/phoenix/core/detail/function_eval.hpp>
#include <qsboost/preprocessor/facilities/expand.hpp>
#include <qsboost/preprocessor/logical/or.hpp>
#include <qsboost/utility/result_of.hpp>

namespace qsboost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    // Functions
    /////////////////////////////////////////////////////////////////////////////
    
    namespace expression
    {
        template <typename F, QSBOOST_PHOENIX_typename_A_void(QSBOOST_PHOENIX_ACTOR_LIMIT)>
        struct function
            : detail::expression::function_eval<F, QSBOOST_PHOENIX_A(QSBOOST_PHOENIX_ACTOR_LIMIT)>
        {};
    }

    // functor which returns our lazy function call extension
    template<typename F>
    struct function
    {
        QSBOOST_CONSTEXPR function()
          : f()
        {}

        QSBOOST_CONSTEXPR function(F f_)
          : f(f_)
        {}

        template <typename Sig>
        struct result;

        typename detail::expression::function_eval<F>::type const
        operator()() const
        {
            return detail::expression::function_eval<F>::make(f);
        }

        // Bring in the rest
        #include <qsboost/phoenix/function/detail/function_operator.hpp>

      // Solves the result problem for F(X)
        template <typename This, typename A0>
        struct result<This(A0)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type>
        {};
      // Solves the result problem for F(X,Y)
        template <typename This, typename A0, typename A1>
        struct result<This(A0,A1)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type>
        {};
      // Solves the result problem for F(X,Y,Z)
        template <typename This, typename A0, typename A1, typename A2>
        struct result<This(A0,A1,A2)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type,
            typename qsboost::remove_reference<A2>::type>
        {};

      // Solves the result problem for F(W,X,Y,Z)
      template <typename This, typename A0, typename A1,
                               typename A2, typename A3>
      struct result<This(A0,A1,A2,A3)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type,
            typename qsboost::remove_reference<A2>::type,
            typename qsboost::remove_reference<A3>::type>
         {};

      // Solves the result problem for F(V,W,X,Y,Z)
      template <typename This, typename A0, typename A1,
                typename A2, typename A3,typename A4>
      struct result<This(A0,A1,A2,A3,A4)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type,
            typename qsboost::remove_reference<A2>::type,
            typename qsboost::remove_reference<A3>::type,
            typename qsboost::remove_reference<A4>::type>
       {};

      // Solves the result problem for F(U,V,W,X,Y,Z)
      template <typename This, typename A0, typename A1,
                typename A2, typename A3,typename A4,
                typename A5>
      struct result<This(A0,A1,A2,A3,A4,A5)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type,
            typename qsboost::remove_reference<A2>::type,
            typename qsboost::remove_reference<A3>::type,
            typename qsboost::remove_reference<A4>::type,
            typename qsboost::remove_reference<A5>::type>
       {};

      // Solves the result problem for F(T,U,V,W,X,Y,Z)
      template <typename This, typename A0, typename A1,
                typename A2, typename A3,typename A4,
                typename A5, typename A6>
      struct result<This(A0,A1,A2,A3,A4,A5,A6)>
          : detail::expression::function_eval<F,
            typename qsboost::remove_reference<A0>::type,
            typename qsboost::remove_reference<A1>::type,
            typename qsboost::remove_reference<A2>::type,
            typename qsboost::remove_reference<A3>::type,
            typename qsboost::remove_reference<A4>::type,
            typename qsboost::remove_reference<A5>::type,
            typename qsboost::remove_reference<A6>::type>
       {};

        F f;
    };
}

    template<typename F>
    struct result_of<phoenix::function<F>()>
      : phoenix::detail::expression::function_eval<F>
    {};

}

#endif


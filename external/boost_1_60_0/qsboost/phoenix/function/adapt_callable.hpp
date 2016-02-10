/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_FUNCTION_ADAPT_CALLABLE_HPP
#define QSBOOST_PHOENIX_FUNCTION_ADAPT_CALLABLE_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/core/detail/function_eval.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>

#define QSBOOST_PHOENIX_ADAPT_CALLABLE_NULLARY(NAME, FUNC)                        \
    inline                                                                      \
    qsboost::phoenix::detail::expression::function_eval<FUNC>::type const         \
    NAME()                                                                      \
    {                                                                           \
        return qsboost::phoenix::detail::expression::                             \
                function_eval<FUNC>::make(FUNC());                              \
    }                                                                           \
/**/


#define QSBOOST_PHOENIX_ADAPT_CALLABLE(NAME, FUNC, N)                             \
    template <QSBOOST_PHOENIX_typename_A(N)>                                      \
    inline                                                                      \
    typename                                                                    \
        qsboost::phoenix::detail::expression::function_eval<                      \
            FUNC                                                                \
          , QSBOOST_PHOENIX_A(N)>::type const                                     \
    NAME(QSBOOST_PHOENIX_A_const_ref_a(N))                                        \
    {                                                                           \
        return qsboost::phoenix::detail::expression::                             \
            function_eval<FUNC, QSBOOST_PHOENIX_A(N)>::                           \
                make(FUNC(), QSBOOST_PHOENIX_a(N));                               \
    }                                                                           \
/**/


#define QSBOOST_PHOENIX_ADAPT_CALLABLE_VARARG(NAME, FUNC)                         \
    QSBOOST_PHOENIX_ADAPT_CALLABLE_NULLARY(NAME, FUNC)                            \
    QSBOOST_PP_REPEAT_FROM_TO(                                                    \
        1                                                                       \
      , QSBOOST_PHOENIX_LIMIT                                                     \
      , QSBOOST_PHOENIX_ADAPT_CALLABLE_VARARG_R                                   \
      , (NAME, FUNC)                                                            \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_ADAPT_CALLABLE_VARARG_R(Z, N, D)                          \
    QSBOOST_PHOENIX_ADAPT_CALLABLE(                                               \
        QSBOOST_PP_TUPLE_ELEM(2, 0, D)                                            \
      , QSBOOST_PP_TUPLE_ELEM(2, 1, D)                                            \
      , N                                                                       \
    )                                                                           \
/**/

#endif

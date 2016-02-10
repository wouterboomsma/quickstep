/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller
    Copyright (c) 2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_FUNCTION_ADAPT_FUNCTION_HPP
#define QSBOOST_PHOENIX_FUNCTION_ADAPT_FUNCTION_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/core/detail/function_eval.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>

#define QSBOOST_PHOENIX_ADAPT_FUNCTION_NULLARY(RESULT, NAME, FUNC)                \
    namespace detail0                                                            \
    {                                                                           \
        struct QSBOOST_PP_CAT(NAME, _impl_nullary)                                \
        {                                                                       \
            typedef RESULT result_type;                                         \
                                                                                \
            result_type                                                         \
            operator()() const                                                  \
            {                                                                   \
                return FUNC();                                                  \
            }                                                                   \
        };                                                                      \
    }                                                                           \
                                                                                \
    inline                                                                      \
    qsboost::phoenix::detail::expression::function_eval<                          \
        detail0:: QSBOOST_PP_CAT(NAME, _impl_nullary)                              \
    >::type const                                                               \
    NAME()                                                                      \
    {                                                                           \
        return qsboost::phoenix::detail::expression::                             \
                function_eval<detail0:: QSBOOST_PP_CAT(NAME, _impl_nullary)>       \
                    ::make(detail0:: QSBOOST_PP_CAT(NAME, _impl_nullary)());       \
    }                                                                           \
/**/

#define QSBOOST_PHOENIX_ADAPT_FUNCTION(RESULT, NAME, FUNC, N)                     \
    namespace detail1                                                            \
    {                                                                           \
        struct QSBOOST_PP_CAT(QSBOOST_PP_CAT(NAME, _impl_), N)                      \
        {                                                                       \
            template <typename Sig>                                             \
            struct result;                                                      \
                                                                                \
            template <typename This, QSBOOST_PHOENIX_typename_A(N)>               \
            struct result<This(QSBOOST_PHOENIX_A(N))>                             \
            {typedef RESULT type;};                                             \
                                                                                \
            template <QSBOOST_PHOENIX_typename_A(N)>                              \
            RESULT                                                              \
            operator()(QSBOOST_PHOENIX_A_ref_a(N)) const                          \
            {                                                                   \
                return FUNC(QSBOOST_PHOENIX_a(N));                                \
            }                                                                   \
        };                                                                      \
    }                                                                           \
                                                                                \
    template <QSBOOST_PHOENIX_typename_A(N)>                                      \
    inline                                                                      \
    typename                                                                    \
        qsboost::phoenix::detail::expression::function_eval<                      \
        detail1:: QSBOOST_PP_CAT(QSBOOST_PP_CAT(NAME, _impl_), N)                    \
          , QSBOOST_PHOENIX_A(N)>::type const                                     \
    NAME(QSBOOST_PHOENIX_A_const_ref_a(N))                                        \
    {                                                                           \
        return qsboost::phoenix::detail::expression::                             \
            function_eval<                                                      \
                detail1:: QSBOOST_PP_CAT(QSBOOST_PP_CAT(NAME, _impl_), N)            \
              , QSBOOST_PHOENIX_A(N)                                              \
            >::make(                                                            \
                detail1:: QSBOOST_PP_CAT(QSBOOST_PP_CAT(NAME, _impl_), N)()          \
              , QSBOOST_PHOENIX_a(N)                                              \
            );                                                                  \
    }                                                                           \
/**/

#define QSBOOST_PHOENIX_ADAPT_FUNCTION_VARARG(RESULT, NAME, FUNC)                 \
    QSBOOST_PHOENIX_ADAPT_FUNCTION_NULLARY(NAME, FUNC)                            \
    QSBOOST_PP_REPEAT_FROM_TO(                                                    \
        1                                                                       \
      , QSBOOST_PHOENIX_LIMIT                                                     \
      , QSBOOST_PHOENIX_ADAPT_FUNCTION_VARARG_R                                   \
      , (RESULT, NAME, FUNC)                                                    \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_ADAPT_FUNCTION_VARARG_R(Z, N, D)                          \
    QSBOOST_PHOENIX_ADAPT_FUNCTION(                                               \
        QSBOOST_PP_TUPLE_ELEM(3, 0, D)                                            \
      , QSBOOST_PP_TUPLE_ELEM(3, 1, D)                                            \
      , QSBOOST_PP_TUPLE_ELEM(3, 2, D)                                            \
      , N                                                                       \
    )                                                                           \
/**/

#endif

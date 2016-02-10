
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP
#define QSBOOST_PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP

#include <qsboost/phoenix/function/detail/preprocessed/function_operator.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP
#define QSBOOST_PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/function_operator_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
    (3, (1, QSBOOST_PHOENIX_ACTOR_LIMIT,                                          \
    <qsboost/phoenix/function/detail/function_operator.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        template <typename This, QSBOOST_PHOENIX_typename_A>
        struct result<This(QSBOOST_PHOENIX_A_const_ref)>
            : detail::expression::function_eval<F, QSBOOST_PHOENIX_A>
        {};

        template <QSBOOST_PHOENIX_typename_A>
        typename detail::expression::function_eval<F, QSBOOST_PHOENIX_A>::type const
        operator()(QSBOOST_PHOENIX_A_const_ref_a) const
        {
            return detail::expression::function_eval<F, QSBOOST_PHOENIX_A>::make(f, QSBOOST_PHOENIX_a);
        }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_RESULT_OF_HPP
#define QSBOOST_PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_RESULT_OF_HPP

#define QSBOOST_PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD(Z, N, D)                 \
            typedef                                                             \
                typename                                                        \
                evaluator::impl<                                                \
                    QSBOOST_PP_CAT(A, N)                                          \
                  , Context                                                     \
                  , proto::empty_env                                            \
                >::result_type                                                  \
                QSBOOST_PP_CAT(child, N);                                         \
        /**/

        #define QSBOOST_PHOENIX_ITERATION_PARAMS                                  \
            (3, (2, QSBOOST_PHOENIX_LIMIT,                                        \
                 <qsboost/phoenix/operator/detail/mem_fun_ptr_eval_result_of.hpp>))
        #include QSBOOST_PHOENIX_ITERATE()

#undef QSBOOST_PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD

#endif

#else

        template <typename Context, QSBOOST_PHOENIX_typename_A>
        struct mem_fun_ptr_eval<Context, QSBOOST_PHOENIX_A>
        {
            QSBOOST_PP_REPEAT(
                QSBOOST_PHOENIX_ITERATION
              , QSBOOST_PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD
              , _
            )

            typedef
                typename qsboost::result_of<
                    child1(
                        QSBOOST_PP_ENUM_SHIFTED_PARAMS(
                            QSBOOST_PHOENIX_ITERATION
                          , child
                        )
                    )
                >::type
                type;
        };

#endif

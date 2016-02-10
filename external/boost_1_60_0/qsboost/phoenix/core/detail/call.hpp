
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_CORE_DETAIL_CALL_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_CALL_HPP

#include <qsboost/phoenix/core/detail/preprocessed/call.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_CALL_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_CALL_HPP

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/call_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <qsboost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define M0(Z, N ,D) \
            typedef \
                typename proto::result_of::child_c<Expr, N>::type \
                QSBOOST_PP_CAT(A, N); \
/**/
#define M1(Z, N ,D) \
    QSBOOST_PP_COMMA_IF(N) proto::child_c<N>(e)
/**/
    

    namespace detail
    {
#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
    (3, (1, QSBOOST_PHOENIX_LIMIT,                                                \
    <qsboost/phoenix/core/detail/call.hpp>))
#include QSBOOST_PHOENIX_ITERATE()
    }

#undef M0
#undef M1

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, QSBOOST_PHOENIX_ITERATION>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename qsboost::phoenix::result_of::context<State, Data>::type
                context_type;

            QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M0, _)

            typedef
                typename qsboost::result_of<
                    Fun(QSBOOST_PHOENIX_A, context_type)
                >::type
                result_type;

            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return
                    Fun()(
                        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M1, _)
                      , qsboost::phoenix::context(s, d)
                    );
            }
        };

#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES

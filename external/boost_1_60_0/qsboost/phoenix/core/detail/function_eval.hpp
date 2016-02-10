#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/detail/phx2_result.hpp>
#include <qsboost/utility/result_of.hpp>

#include <qsboost/phoenix/core/detail/preprocessed/function_eval.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_FUNCTION_EVAL_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/detail/phx2_result.hpp>
#include <qsboost/utility/result_of.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/function_eval_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif
/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/


#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG(
    (qsboost)(phoenix)(detail)(function_eval)
  , (meta_grammar)
    (meta_grammar)
  , QSBOOST_PP_DEC(QSBOOST_PHOENIX_COMPOSITE_LIMIT)
)

namespace qsboost { namespace phoenix {
    namespace detail
    {
        template <typename T>
        T& help_rvalue_deduction(T& x)
        {
            return x;
        }
        
        template <typename T>
        T const& help_rvalue_deduction(T const& x)
        {
            return x;
        }

        struct function_eval
        {
            template <typename Sig>
            struct result;

            template <typename This, typename F, typename Context>
            struct result<This(F, Context)>
            {
                typedef typename
                    remove_reference<
                        typename qsboost::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;

                typedef typename qsboost::result_of<fn()>::type type;
            };

            template <typename F, typename Context>
            typename result<function_eval(F const&, Context const&)>::type
            operator()(F const & f, Context const & ctx) const
            {
                return qsboost::phoenix::eval(f, ctx)();
            }

            template <typename F, typename Context>
            typename result<function_eval(F &, Context const&)>::type
            operator()(F & f, Context const & ctx) const
            {
                return qsboost::phoenix::eval(f, ctx)();
            }

        #define PHOENIX_GET_ARG(z, n, data)                                     \
            typedef                                                             \
                typename qsboost::add_reference<                                  \
                    typename qsboost::add_const<                                  \
                        typename qsboost::result_of<                              \
                            qsboost::phoenix::evaluator(                          \
                                QSBOOST_PP_CAT(A, n)                              \
                              , Context                                         \
                            )                                                   \
                        >::type                                                 \
                    >::type                                                     \
                >::type                                                         \
                QSBOOST_PP_CAT(a, n);

        #define PHOENIX_EVAL_ARG(z, n, data)                                    \
            help_rvalue_deduction(qsboost::phoenix::eval(QSBOOST_PP_CAT(a, n), ctx))
        
        #define M0(z, n, data)                                     \
            typename proto::detail::uncvref<QSBOOST_PP_CAT(a, n)>::type

        #define QSBOOST_PHOENIX_ITERATION_PARAMS                                  \
            (3, (1, QSBOOST_PP_DEC(QSBOOST_PHOENIX_ACTOR_LIMIT),                    \
            <qsboost/phoenix/core/detail/function_eval.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

        #undef PHOENIX_GET_ARG
        #undef PHOENIX_EVAL_ARG
        #undef M0
        
        };
        
    }

    template <typename Dummy>
    struct default_actions::when<detail::rule::function_eval, Dummy>
        : phoenix::call<detail::function_eval>
    {};
}}

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif


#endif

#else
            template <
                typename This
              , typename F
              , QSBOOST_PHOENIX_typename_A
              , typename Context
            >
            struct result<This(F, QSBOOST_PHOENIX_A, Context)>
            {
                typedef typename
                    remove_reference<
                        typename qsboost::result_of<evaluator(F, Context)>::type
                    >::type
                    fn;

                QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, PHOENIX_GET_ARG, _)

                typedef typename
                    qsboost::result_of<fn(QSBOOST_PHOENIX_a)>::type
                    type;
                /*
                typedef typename
                    mpl::eval_if_c<
                        has_phx2_result<
                            fn
                          , BOOST_PP_ENUM(BOOST_PHOENIX_ITERATION, M0, _)
                        >::value
                      , boost::result_of<
                            fn(
                                BOOST_PHOENIX_a
                            )
                        >
                      , phx2_result<
                            fn
                          , BOOST_PHOENIX_a
                        >
                    >::type
                    type;
                */
            };

            template <typename F, QSBOOST_PHOENIX_typename_A, typename Context>
            typename result<
                function_eval(
                    F const &
                  , QSBOOST_PHOENIX_A_ref
                  , Context const &
                )
            >::type
            operator()(F const & f, QSBOOST_PHOENIX_A_ref_a, Context const & ctx) const
            {
                return qsboost::phoenix::eval(f, ctx)(QSBOOST_PP_ENUM(QSBOOST_PHOENIX_ITERATION, PHOENIX_EVAL_ARG, _));
            }

            template <typename F, QSBOOST_PHOENIX_typename_A, typename Context>
            typename result<
                function_eval(
                    F &
                  , QSBOOST_PHOENIX_A_ref
                  , Context const &
                )
            >::type
            operator()(F & f, QSBOOST_PHOENIX_A_ref_a, Context const & ctx) const
            {
                return qsboost::phoenix::eval(f, ctx)(QSBOOST_PP_ENUM(QSBOOST_PHOENIX_ITERATION, PHOENIX_EVAL_ARG, _));
            }
#endif

#endif

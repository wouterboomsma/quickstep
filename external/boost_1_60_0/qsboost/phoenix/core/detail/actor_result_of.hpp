
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP

#include <qsboost/phoenix/support/iterate.hpp>

#include <qsboost/phoenix/core/detail/preprocessed/actor_result_of.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP

#include <qsboost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/actor_result_of_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
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

    namespace result_of
    {
        template <typename Expr
            , QSBOOST_PHOENIX_typename_A_void(QSBOOST_PHOENIX_ACTOR_LIMIT)
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct nullary_actor_result
        {
            typedef
                typename qsboost::phoenix::evaluator::impl<
                    Expr const&
                  , vector2<
                        vector1<const ::qsboost::phoenix::actor<Expr> *> &
                      , default_actions
                    > const &
                  , proto::empty_env
                >::result_type
                type;
        };

        template <typename Expr>
        struct actor<Expr>
        {
            typedef
                // avoid calling result_of::actor when this is false
                typename mpl::eval_if_c<
                    result_of::is_nullary<Expr>::value
                  , nullary_actor_result<Expr>
                  , mpl::identity<detail::error_expecting_arguments>
                >::type
            type;
        };

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
    (3, (1, QSBOOST_PHOENIX_ACTOR_LIMIT,                                          \
    <qsboost/phoenix/core/detail/actor_result_of.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

    }

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename Expr, QSBOOST_PHOENIX_typename_A>
        struct actor<Expr, QSBOOST_PHOENIX_A>
        {
            typedef
                typename phoenix::evaluator::
                    impl<
                        Expr const&
                      , vector2<
                            QSBOOST_PP_CAT(
                                vector
                              , QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION)
                            )<const ::qsboost::phoenix::actor<Expr> *, QSBOOST_PHOENIX_A> &
                          , default_actions
                        > const &
                      , proto::empty_env
                    >::result_type
                type;
        };

#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES

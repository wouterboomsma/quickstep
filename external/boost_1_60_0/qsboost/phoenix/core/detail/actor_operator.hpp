
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP

#include <qsboost/phoenix/support/iterate.hpp>

#include <qsboost/phoenix/core/detail/preprocessed/actor_operator.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_ACTOR_OPERATOR_HPP

#include <qsboost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/actor_operator_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
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

#define M0(Z, N, D)                                                             \
    typename detail::result_type_deduction_helper<QSBOOST_PP_CAT(A, N)>::type     \
/**/

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
        (3, (1, QSBOOST_PHOENIX_ACTOR_LIMIT,                                      \
        <qsboost/phoenix/core/detail/actor_operator.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

#undef M0

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

#if QSBOOST_PHOENIX_ITERATION >= QSBOOST_PHOENIX_PERFECT_FORWARD_LIMIT

        template <typename This, QSBOOST_PHOENIX_typename_A>
        struct result<This(QSBOOST_PHOENIX_A)>
            : result<This(QSBOOST_PHOENIX_A_const_ref)>
        {};

        template <typename This, QSBOOST_PHOENIX_typename_A>
        struct result<This(QSBOOST_PHOENIX_A_ref)>
            : result_of::actor<proto_base_expr, QSBOOST_PHOENIX_A_ref>
        {};

        template <QSBOOST_PHOENIX_typename_A>
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_A_ref>::type
        operator()(QSBOOST_PHOENIX_A_ref_a)
        {
            typedef
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<
                    const actor<Expr> *, QSBOOST_PHOENIX_A_ref
                >
                env_type;
            env_type env = {this, QSBOOST_PHOENIX_a};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

        template <QSBOOST_PHOENIX_typename_A>
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_A_ref>::type
        operator()(QSBOOST_PHOENIX_A_ref_a) const
        {
            typedef
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<
                    const actor<Expr> *, QSBOOST_PHOENIX_A_ref
                >
                env_type;
            env_type env = {this, QSBOOST_PHOENIX_a};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

        template <QSBOOST_PHOENIX_typename_A>
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_A_const_ref>::type
        operator()(QSBOOST_PHOENIX_A_const_ref_a)
        {
            typedef
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<
                    const actor<Expr> *, QSBOOST_PHOENIX_A_const_ref
                >
                env_type;
            env_type env = {this, QSBOOST_PHOENIX_a};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

        template <QSBOOST_PHOENIX_typename_A>
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_A_const_ref>::type
        operator()(QSBOOST_PHOENIX_A_const_ref_a) const
        {
            typedef
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<
                    const actor<Expr> *, QSBOOST_PHOENIX_A_const_ref
                >
                env_type;
            env_type env = {this, QSBOOST_PHOENIX_a};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

#else

// We need to define operator() for all permutations of reference types.
// For BOOST_PHOENIX_ITERATION <= BOOST_PHOENIX_LIMIT_PREFECT_FORWARD
// 2^BOOST_PHOENIX_ITERATION overloads are created
// For compile time reasons,
// if BOOST_PHOENIX_ITERATION > BOOST_PHOENIX_LIMIT_PERFECT_FORWARD
// only operator()(A const &...a) and operator()(A &...a) are generated
// this is all handled by the PP mumbo jumbo above
#define QSBOOST_PHOENIX_ACTOR_OPERATOR(_, I, __)                                  \
        template <typename This, QSBOOST_PHOENIX_typename_A>                      \
        struct result<This(QSBOOST_PHOENIX_PERM_A(I))>                            \
            : result_of::actor<proto_base_expr, QSBOOST_PHOENIX_PERM_A(I)>        \
        {};                                                                     \
                                                                                \
        template <QSBOOST_PHOENIX_typename_A>                                     \
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_PERM_A(I)>::type\
        operator()(QSBOOST_PHOENIX_PERM_A_a(I)) const                             \
        {                                                                       \
            typedef                                                             \
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<    \
                    const actor<Expr> *, QSBOOST_PHOENIX_PERM_A(I)                \
                >                                                               \
                env_type;                                                       \
            env_type env = {this, QSBOOST_PHOENIX_a};                             \
                                                                                \
            return phoenix::eval(*this, phoenix::context(env, default_actions()));\
        }                                                                       \
                                                                                \
        template <QSBOOST_PHOENIX_typename_A>                                     \
        typename result_of::actor<proto_base_expr, QSBOOST_PHOENIX_PERM_A(I)>::type\
        operator()(QSBOOST_PHOENIX_PERM_A_a(I))                                   \
        {                                                                       \
            typedef                                                             \
                QSBOOST_PP_CAT(vector, QSBOOST_PP_INC(QSBOOST_PHOENIX_ITERATION))<    \
                    const actor<Expr> *, QSBOOST_PHOENIX_PERM_A(I)                \
                >                                                               \
                env_type;                                                       \
            env_type env = {this, QSBOOST_PHOENIX_a};                             \
                                                                                \
            return phoenix::eval(*this, phoenix::context(env, default_actions()));\
        }                                                                       \
        /**/

        template <typename This, QSBOOST_PHOENIX_typename_A>
        struct result<This(QSBOOST_PHOENIX_A)>
            : result<This(QSBOOST_PP_ENUM(QSBOOST_PHOENIX_ITERATION, M0, _))>
        {};

        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_PERM_SIZE, QSBOOST_PHOENIX_ACTOR_OPERATOR, _)

#undef QSBOOST_PHOENIX_ACTOR_OPERATOR

#endif

#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES

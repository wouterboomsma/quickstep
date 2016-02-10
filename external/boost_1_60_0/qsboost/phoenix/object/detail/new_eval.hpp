
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP
#define QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP

#include <qsboost/phoenix/object/detail/preprocessed/new_eval.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP
#define QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP

#include <qsboost/preprocessor/repetition/enum_shifted_binary_params.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/new_eval_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
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
    (3, (2, QSBOOST_PHOENIX_COMPOSITE_LIMIT,                                      \
    <qsboost/phoenix/object/detail/new_eval.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename This, QSBOOST_PHOENIX_typename_A, typename Context>
        struct result<This(QSBOOST_PHOENIX_A, Context)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename proto::result_of::value<A0>::type
                >::type
            target_type;
            typedef typename target_type::type  construct_type;
            typedef typename target_type::type * type;
        };

        template <QSBOOST_PHOENIX_typename_A, typename Context>
        typename result<new_eval(QSBOOST_PHOENIX_A_const_ref, Context &)>::type
        operator()(
            A0 const&
          , QSBOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(
                QSBOOST_PHOENIX_ITERATION
              , A
              , const& a
            )
          , Context const & ctx
        ) const
        {
#define EVAL_a(_,n,__) \
            QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) qsboost::phoenix::eval(a ## n, ctx)
            return
                new typename result<
                    new_eval(QSBOOST_PHOENIX_A_const_ref, Context &)
                    >::construct_type(
                        QSBOOST_PP_REPEAT_FROM_TO(
                            1
                          , QSBOOST_PHOENIX_ITERATION
                          , EVAL_a
                          , _
                        )
                );
#undef EVAL_a
        }

#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES


#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_OPERATOR_MEMBER_HPP
#define QSBOOST_PHOENIX_OPERATOR_MEMBER_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/get_pointer.hpp>
#include <qsboost/phoenix/core/domain.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/type_traits/is_member_function_pointer.hpp>
#include <qsboost/proto/operators.hpp>

#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#include <qsboost/phoenix/operator/preprocessed/member.hpp>

#else

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/member_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
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

#include <qsboost/phoenix/operator/detail/define_operator.hpp>

namespace qsboost { namespace phoenix
{
    QSBOOST_PHOENIX_BINARY_OPERATORS((mem_ptr))

    template<>
    struct phoenix_generator::case_<proto::tag::mem_ptr>
      : proto::or_<
            proto::when<
                proto::and_<
                    proto::mem_ptr<meta_grammar, proto::terminal<proto::_> >
                  , proto::if_<is_member_function_pointer<qsboost::remove_reference<proto::call<proto::_value(proto::_right)> > >()>
                >
              , proto::call<detail::make_mem_fun_ptr_gen(proto::_left, proto::call<proto::_value(proto::_right)>)>
            >
          , proto::otherwise<
                proto::call<proto::pod_generator<actor>(proto::_)>
            >
        >
    {};

    namespace result_of
    {
        template <
            typename Context
          , QSBOOST_PHOENIX_typename_A_void(QSBOOST_PHOENIX_LIMIT)
          , typename Dummy = void
        >
        struct mem_fun_ptr_eval;

        #include <qsboost/phoenix/operator/detail/mem_fun_ptr_eval_result_of.hpp>
    }

    struct mem_fun_ptr_eval
    {
        template<typename Sig>
        struct result;

    #define QSBOOST_PHOENIX_MEMBER_EVAL(Z, N, D)                                  \
        QSBOOST_PP_COMMA_IF(QSBOOST_PP_NOT(QSBOOST_PP_EQUAL(N, 2)))                   \
        qsboost::phoenix::eval(QSBOOST_PP_CAT(a, N), ctx)                           \
    /**/

    #define QSBOOST_PHOENIX_ITERATION_PARAMS                                      \
        (3, (2, QSBOOST_PHOENIX_LIMIT,                                            \
        <qsboost/phoenix/operator/member.hpp>))                                   \
    /**/
        #include QSBOOST_PHOENIX_ITERATE()
    #undef QSBOOST_PHOENIX_MEMBER_EVAL
    };

    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : call<mem_fun_ptr_eval>
    {};
}}

#include <qsboost/phoenix/operator/detail/undef_operator.hpp>

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES

#endif

#else // BOOST_PHOENIX_IS_ITERATING

        template <typename This, QSBOOST_PHOENIX_typename_A, typename Context>
        struct result<This(QSBOOST_PHOENIX_A, Context)>
            : result<This(QSBOOST_PHOENIX_A_const_ref, Context)>
        {};

        template <typename This, QSBOOST_PHOENIX_typename_A, typename Context>
        struct result<This(QSBOOST_PHOENIX_A_ref, Context)>
            : result_of::mem_fun_ptr_eval<Context, QSBOOST_PHOENIX_A>
        {};

        template <QSBOOST_PHOENIX_typename_A, typename Context>
        typename result_of::mem_fun_ptr_eval<Context, QSBOOST_PHOENIX_A>::type
        operator()(
            QSBOOST_PHOENIX_A_const_ref_a
          , Context const & ctx
        ) const
        {
            return
                (
                    get_pointer(qsboost::phoenix::eval(a0, ctx))
                    ->*qsboost::phoenix::eval(a1, ctx)
                )(
                    QSBOOST_PP_REPEAT_FROM_TO(
                        2
                      , QSBOOST_PHOENIX_ITERATION
                      , QSBOOST_PHOENIX_MEMBER_EVAL
                      , QSBOOST_PHOENIX_ITERATION
                    )
                );
        }
        

#endif

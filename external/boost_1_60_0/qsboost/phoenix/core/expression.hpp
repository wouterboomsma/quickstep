
#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_CORE_EXPRESSION_HPP
#define QSBOOST_PHOENIX_CORE_EXPRESSION_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/call_traits.hpp>
#include <qsboost/fusion/sequence/intrinsic/at.hpp>
#include <qsboost/phoenix/core/as_actor.hpp>
#include <qsboost/phoenix/core/detail/expression.hpp>
#include <qsboost/phoenix/core/domain.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/preprocessor/comparison/equal.hpp>
#include <qsboost/proto/domain.hpp>
#include <qsboost/proto/make_expr.hpp>
#include <qsboost/proto/transform/pass_through.hpp>

#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#include <qsboost/phoenix/core/preprocessed/expression.hpp>

#else

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/expression_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace qsboost { namespace phoenix
{
    template <typename Expr> struct actor;
    
    template <
        template <typename> class Actor
      , typename Tag
      , QSBOOST_PHOENIX_typename_A_void(QSBOOST_PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void>
    struct expr_ext;

    template <
        typename Tag
      , QSBOOST_PHOENIX_typename_A_void(QSBOOST_PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void
    >
    struct expr : expr_ext<actor, Tag, QSBOOST_PHOENIX_A(QSBOOST_PHOENIX_COMPOSITE_LIMIT)> {};

#define M0(Z, N, D)                                                             \
    QSBOOST_PP_COMMA_IF(N)                                                        \
    typename proto::detail::uncvref<typename call_traits<QSBOOST_PP_CAT(A, N)>::value_type>::type

#define M1(Z, N, D)                                                             \
    QSBOOST_PP_COMMA_IF(N) typename call_traits<QSBOOST_PP_CAT(A, N)>::param_type QSBOOST_PP_CAT(a, N)

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
    (3, (1, QSBOOST_PHOENIX_COMPOSITE_LIMIT,                                      \
    <qsboost/phoenix/core/expression.hpp>))                                       \
/**/
    #include QSBOOST_PHOENIX_ITERATE()

#undef M0
#undef M1

}}

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES

#endif

#else
    template <template <typename> class Actor, typename Tag, QSBOOST_PHOENIX_typename_A>
    struct expr_ext<Actor, Tag, QSBOOST_PHOENIX_A>
        : proto::transform<expr_ext<Actor, Tag, QSBOOST_PHOENIX_A>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , phoenix_default_domain //proto::basic_default_domain
              , QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M0, _)
            >::type
            base_type;

        typedef Actor<base_type> type;

        typedef
            typename proto::nary_expr<Tag, QSBOOST_PHOENIX_A>::proto_grammar
            proto_grammar;
        
        static type make(QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M1, _))
      { //?? actor or Actor??
        //Actor<base_type> const e =
                actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , phoenix_default_domain // proto::basic_default_domain
                    >(QSBOOST_PHOENIX_a)
                };
            return e;
        }

        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::pass_through<expr_ext>::template impl<Expr, State, Data>
        {};
        
        typedef Tag proto_tag;
    #define QSBOOST_PHOENIX_ENUM_CHILDREN(_, N, __)                               \
        typedef QSBOOST_PP_CAT(A, N) QSBOOST_PP_CAT(proto_child, N);                \
    /**/
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, QSBOOST_PHOENIX_ENUM_CHILDREN, _)
    #undef QSBOOST_PHOENIX_ENUM_CHILDREN
    };

#endif

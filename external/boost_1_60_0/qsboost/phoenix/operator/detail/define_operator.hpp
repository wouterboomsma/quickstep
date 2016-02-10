/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_PHOENIX_DEFINE_OPERATOR_HPP
#define QSBOOST_PHOENIX_DEFINE_OPERATOR_HPP

#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/preprocessor/seq/for_each.hpp>

#define QSBOOST_PHOENIX_UNARY_EXPRESSION(__, ___, name)                           \
    template <typename Operand>                                                 \
    struct name                                                                 \
        : expr<proto::tag::name, Operand>                                       \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_UNARY_RULE(__, ___, name)                                 \
    struct name                                                                 \
        : expression::name<meta_grammar>                                        \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_UNARY_FUNCTIONAL(__, ___, name)                           \
    namespace functional                                                        \
    {                                                                           \
        typedef                                                                 \
            proto::functional::make_expr<proto::tag::name>                      \
            QSBOOST_PP_CAT(make_, name);                                          \
    }                                                                           \
    namespace result_of                                                         \
    {                                                                           \
        template <typename Operand>                                             \
        struct QSBOOST_PP_CAT(make_, name)                                        \
            : qsboost::result_of<                                                 \
                functional:: QSBOOST_PP_CAT(make_, name)(                         \
                    Operand                                                     \
                )                                                               \
            >                                                                   \
        {};                                                                     \
    }                                                                           \
    template <typename Operand>                                                 \
    inline                                                                      \
    typename result_of::QSBOOST_PP_CAT(make_, name)<Operand>::type                \
    QSBOOST_PP_CAT(make_, name)(Operand const & operand)                          \
    {                                                                           \
        return functional::QSBOOST_PP_CAT(make_, name)()(operand);                \
    }                                                                           \
/**/

#define QSBOOST_PHOENIX_BINARY_EXPRESSION(__, ___, name)                          \
    template <typename Lhs, typename Rhs>                                       \
    struct name                                                                 \
        : expr<proto::tag::name, Lhs, Rhs>                                      \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_BINARY_RULE(__, ___, name)                                \
    struct name                                                                 \
        : expression::name<meta_grammar, meta_grammar>                          \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_BINARY_FUNCTIONAL(__, ___, name)                          \
    namespace functional                                                        \
    {                                                                           \
        typedef                                                                 \
            proto::functional::make_expr<proto::tag::name>                      \
            QSBOOST_PP_CAT(make_, name);                                          \
    }                                                                           \
    namespace result_of                                                         \
    {                                                                           \
        template <typename Lhs, typename Rhs>                                   \
        struct QSBOOST_PP_CAT(make_, name)                                        \
            : qsboost::result_of<                                                 \
                functional:: QSBOOST_PP_CAT(make_, name)(                         \
                    Lhs, Rhs                                                    \
                )                                                               \
            >                                                                   \
        {};                                                                     \
    }                                                                           \
    template <typename Rhs, typename Lhs>                                       \
    inline                                                                      \
    typename result_of::QSBOOST_PP_CAT(make_, name)<Rhs, Lhs>::type               \
    QSBOOST_PP_CAT(make_, name)(Lhs const & lhs, Rhs const & rhs)                 \
    {                                                                           \
        return functional::QSBOOST_PP_CAT(make_, name)()(lhs, rhs);               \
    }                                                                           \
/**/

#define QSBOOST_PHOENIX_GRAMMAR(_, __, name)                                      \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<proto::tag::name, Dummy>                         \
        : enable_rule<rule::name, Dummy>                                        \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_UNARY_OPERATORS(ops)                                      \
    namespace expression {                                                      \
        QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_UNARY_EXPRESSION, _, ops)           \
    }                                                                           \
    namespace rule {                                                            \
        QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_UNARY_RULE, _, ops)                 \
    }                                                                           \
    QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_GRAMMAR, _, ops)                        \
    QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_UNARY_FUNCTIONAL, _, ops)               \
/**/


#define QSBOOST_PHOENIX_BINARY_OPERATORS(ops)                                     \
    namespace expression {                                                      \
        QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_BINARY_EXPRESSION, _, ops)          \
    }                                                                           \
    namespace rule {                                                            \
        QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_BINARY_RULE, _, ops)                \
    }                                                                           \
    QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_GRAMMAR, _, ops)                        \
    QSBOOST_PP_SEQ_FOR_EACH(QSBOOST_PHOENIX_BINARY_FUNCTIONAL, _, ops)              \
/**/

#endif

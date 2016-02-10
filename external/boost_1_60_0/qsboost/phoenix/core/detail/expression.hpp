/*=============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_PHOENIX_CORE_DETAIL_EXPRESSION_HPP
#define QSBOOST_PHOENIX_CORE_DETAIL_EXPRESSION_HPP

#include <qsboost/preprocessor/empty.hpp>
#include <qsboost/preprocessor/arithmetic/add.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/comma_if.hpp>
#include <qsboost/preprocessor/comparison/equal.hpp>
#include <qsboost/preprocessor/seq/size.hpp>
#include <qsboost/preprocessor/seq/enum.hpp>
#include <qsboost/preprocessor/seq/for_each.hpp>
#include <qsboost/preprocessor/seq/pop_back.hpp>
#include <qsboost/preprocessor/seq/reverse.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/preprocessor/enum_params.hpp>
#include <qsboost/preprocessor/repeat_from_to.hpp>

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION(NAME_SEQ, SEQ)                          \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_BASE(                                       \
        NAME_SEQ                                                                \
      , SEQ                                                                     \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_DEFAULT                      \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_DEFAULT                            \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_DEFAULT                  \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_DEFAULT                 \
      , _                                                                       \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG(NAME_SEQ, GRAMMAR_SEQ, LIMIT)    \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_BASE(                                       \
        NAME_SEQ                                                                \
      , GRAMMAR_SEQ                                                             \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_VARARG                       \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_VARARG                             \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_VARARG                   \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_VARARG                  \
      , LIMIT                                                                   \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXT(ACTOR, NAME_SEQ, GRAMMAR_SEQ)       \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_BASE(                                       \
        NAME_SEQ                                                                \
      , GRAMMAR_SEQ                                                             \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_EXT                          \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_DEFAULT                            \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_DEFAULT                  \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_DEFAULT                 \
      , ACTOR                                                                   \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXT_VARARG(ACTOR, NAME, GRAMMAR, LIMIT) \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_BASE(                                       \
        NAME_SEQ                                                                \
      , GRAMMAR_SEQ                                                             \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_VARARG_EXT                   \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_VARARG                             \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_VARARG                   \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_VARARG                  \
      , ACTOR                                                                   \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_NAMESPACE(R, D, E)                      \
namespace E {                                                                   \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_NAMESPACE_END(R, D, E)                  \
}                                                                               \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_NS(R, D, E)                             \
E ::                                                                            \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_BASE(NAME_SEQ, GRAMMAR_SEQ, EXPRESSION, RULE, RESULT_OF_MAKE, MAKE_EXPRESSION, DATA) \
QSBOOST_PP_SEQ_FOR_EACH(                                                          \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_NAMESPACE                                   \
  , _                                                                           \
  , QSBOOST_PP_SEQ_POP_BACK(NAME_SEQ)                                             \
)                                                                               \
    namespace tag                                                               \
    {                                                                           \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ)) {};            \
        template <typename Ostream>                                             \
        inline Ostream &operator<<(                                             \
            Ostream & os                                                        \
          , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ)))                  \
        {                                                                       \
            os << QSBOOST_PP_STRINGIZE(                                           \
                QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))               \
            );                                                                  \
            return os;                                                          \
        }                                                                       \
    }                                                                           \
    namespace expression                                                        \
    {                                                                           \
        EXPRESSION(NAME_SEQ, GRAMMAR_SEQ, DATA)                                 \
    }                                                                           \
    namespace rule                                                              \
    {                                                                           \
        RULE(NAME_SEQ, GRAMMAR_SEQ, DATA)                                       \
    }                                                                           \
    namespace functional                                                        \
    {                                                                           \
        typedef                                                                 \
            qsboost::proto::functional::make_expr<                                \
                    tag:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))     \
            >                                                                   \
            QSBOOST_PP_CAT(                                                       \
                make_                                                           \
              , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))               \
            );                                                                  \
    }                                                                           \
    namespace result_of                                                         \
    {                                                                           \
        RESULT_OF_MAKE(NAME_SEQ, GRAMMAR_SEQ, DATA)                             \
    }                                                                           \
    MAKE_EXPRESSION(NAME_SEQ, GRAMMAR_SEQ, DATA)                                \
                                                                                \
QSBOOST_PP_SEQ_FOR_EACH(                                                          \
    QSBOOST_PHOENIX_DEFINE_EXPRESSION_NAMESPACE_END                               \
  , _                                                                           \
  , QSBOOST_PP_SEQ_POP_BACK(NAME_SEQ)                                             \
)                                                                               \
namespace qsboost { namespace phoenix                                             \
{                                                                               \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<                                                 \
        :: QSBOOST_PP_SEQ_FOR_EACH(                                               \
            QSBOOST_PHOENIX_DEFINE_EXPRESSION_NS                                  \
          , _                                                                   \
          , QSBOOST_PP_SEQ_POP_BACK(NAME_SEQ)                                     \
        ) tag:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))               \
      , Dummy                                                                   \
    >                                                                           \
        : enable_rule<                                                          \
            :: QSBOOST_PP_SEQ_FOR_EACH(                                           \
                QSBOOST_PHOENIX_DEFINE_EXPRESSION_NS                              \
              , _                                                               \
              , QSBOOST_PP_SEQ_POP_BACK(NAME_SEQ)                                 \
            ) rule:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))          \
         , Dummy                                                                \
        >                                                                       \
    {};                                                                         \
} }                                                                             \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_DEFAULT(NAME_SEQ, GRAMMAR_SEQ, D) \
        template <QSBOOST_PHOENIX_typename_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))>     \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                \
            : qsboost::phoenix::expr<                                             \
                :: QSBOOST_PP_SEQ_FOR_EACH(                                       \
                    QSBOOST_PHOENIX_DEFINE_EXPRESSION_NS                          \
                  , _                                                           \
                  , QSBOOST_PP_SEQ_POP_BACK(NAME_SEQ)                             \
                ) tag:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))       \
              , QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ), A)>        \
        {};                                                                     \
/**/
        
#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_DEFAULT(NAME_SEQ, GRAMMAR_SEQ, D)  \
    struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                    \
        : expression:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))        \
            <QSBOOST_PP_SEQ_ENUM(GRAMMAR_SEQ)>                                    \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_DEFAULT(NAME_SEQ, GRAMMAR_SEQ, D) \
    template <QSBOOST_PHOENIX_typename_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))>         \
    struct QSBOOST_PP_CAT(make_, QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))) \
        : qsboost::result_of<                                                     \
            functional::                                                        \
                QSBOOST_PP_CAT(                                                   \
                    make_                                                       \
                  , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))           \
                )(QSBOOST_PHOENIX_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ)))              \
        >                                                                       \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_DEFAULT(NAME_SEQ, GRAMMAR_SEQ, D) \
    template <QSBOOST_PHOENIX_typename_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))>         \
    inline                                                                      \
    typename                                                                    \
        result_of::QSBOOST_PP_CAT(                                                \
            make_                                                               \
          , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                   \
        )<                                                                      \
            QSBOOST_PHOENIX_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))                     \
        >::type const                                                           \
    QSBOOST_PP_CAT(                                                               \
        make_                                                                   \
      , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                       \
    )(                                                                          \
        QSBOOST_PHOENIX_A_const_ref_a(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))             \
    )                                                                           \
    {                                                                           \
        return                                                                  \
            functional::QSBOOST_PP_CAT(                                           \
                make_                                                           \
              , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))               \
            )()(                                                                \
              QSBOOST_PHOENIX_a(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))                   \
            );                                                                  \
    }                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG_R(_, N, NAME)                    \
    template <                                                                  \
        QSBOOST_PHOENIX_typename_A(                                               \
            QSBOOST_PP_ADD(                                                       \
                N                                                               \
              , QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(2, 1, NAME))              \
            )                                                                   \
        )                                                                       \
    >                                                                           \
    struct QSBOOST_PP_TUPLE_ELEM(2, 0, NAME)<                                     \
        QSBOOST_PHOENIX_A(                                                        \
            QSBOOST_PP_ADD(N, QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(2, 1, NAME))) \
        )                                                                       \
    >                                                                           \
        : qsboost::phoenix::expr<                                                 \
            tag:: QSBOOST_PP_TUPLE_ELEM(2, 0, NAME)                               \
          , QSBOOST_PHOENIX_A(                                                    \
                QSBOOST_PP_ADD(                                                   \
                    N                                                           \
                  , QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(2, 1, NAME))          \
                )                                                               \
            )                                                                   \
        >                                                                       \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_VARARG(NAME_SEQ, GRAMMAR_SEQ, LIMIT) \
        template <                                                              \
            QSBOOST_PHOENIX_typename_A_void(                                      \
                QSBOOST_PP_ADD(                                                   \
                    LIMIT, QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ)))        \
            )                                                                   \
          , typename Dummy = void                                               \
        >                                                                       \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ));               \
                                                                                \
        QSBOOST_PP_REPEAT_FROM_TO(                                                \
            1                                                                   \
          , QSBOOST_PP_ADD(LIMIT, QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ)))   \
          , QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG_R                            \
          , (                                                                   \
                QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))               \
              , QSBOOST_PP_SEQ_POP_BACK(GRAMMAR_SEQ)                              \
            )                                                                   \
        )                                                                       \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_VARARG(NAME_SEQ, GRAMMAR_SEQ, LIMIT) \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                \
            : expression:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ)) <  \
                QSBOOST_PP_IF(                                                    \
                    QSBOOST_PP_EQUAL(1, QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))           \
                  , QSBOOST_PP_EMPTY                                              \
                  , QSBOOST_PP_IDENTITY(                                          \
                      QSBOOST_PP_SEQ_ENUM(QSBOOST_PP_SEQ_POP_BACK(GRAMMAR_SEQ))     \
                    )                                                           \
                )()                                                             \
                QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))) \
                qsboost::proto::vararg<                                           \
                    QSBOOST_PP_SEQ_ELEM(                                          \
                        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))            \
                      , GRAMMAR_SEQ                                             \
                    )                                                           \
                >                                                               \
            >                                                                   \
        {};                                                                     \
/**/
        
#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_VARARG_R(Z, N, NAME)     \
    template <QSBOOST_PHOENIX_typename_A(N)>                                      \
    struct QSBOOST_PP_CAT(make_, NAME) <QSBOOST_PHOENIX_A(N)>                        \
        : qsboost::result_of<                                                     \
            functional:: QSBOOST_PP_CAT(make_, NAME)(                              \
                QSBOOST_PHOENIX_A(N)                                              \
            )                                                                   \
        >                                                                       \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_VARARG(NAME_SEQ, GRAMMAR_SEQ, LIMIT) \
    template <QSBOOST_PHOENIX_typename_A_void(LIMIT), typename Dummy = void>      \
    struct QSBOOST_PP_CAT(                                                        \
        make_                                                                   \
      , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                       \
    );                                                                          \
    QSBOOST_PP_REPEAT_FROM_TO(                                                    \
        1                                                                       \
      , LIMIT                                                                   \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_RESULT_OF_MAKE_VARARG_R                 \
      , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                       \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_VARARG_R(Z, N, NAME)    \
    template <QSBOOST_PHOENIX_typename_A(N)>                                      \
    inline                                                                      \
    typename                                                                    \
        result_of:: QSBOOST_PP_CAT(make_, NAME)<                                  \
            QSBOOST_PHOENIX_A(N)                                                  \
        >::type                                                                 \
    QSBOOST_PP_CAT(make_, NAME)(QSBOOST_PHOENIX_A_const_ref_a(N))                   \
    {                                                                           \
        return functional::QSBOOST_PP_CAT(make_, NAME)()(QSBOOST_PHOENIX_a(N));     \
    }                                                                           \

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_VARARG(NAME_SEQ, GRAMMAR_SEQ, LIMIT) \
    QSBOOST_PP_REPEAT_FROM_TO(                                                    \
        1                                                                       \
      , LIMIT                                                                   \
      , QSBOOST_PHOENIX_DEFINE_EXPRESSION_MAKE_EXPRESSION_VARARG_R                \
      , QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                       \
    )                                                                           \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXPRESSION_EXT(NAME_SEQ, GRAMMAR_SEQ, ACTOR) \
        template <QSBOOST_PHOENIX_typename_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))>     \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))                \
            : ::qsboost::phoenix::expr_ext<                                       \
                ACTOR                                                           \
              , tag:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(NAME_SEQ))         \
              , QSBOOST_PHOENIX_A(QSBOOST_PP_SEQ_SIZE(GRAMMAR_SEQ))>                \
        {};                                                                     \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXT_VARARG_R(_, N, NAME)                \
    template <                                                                  \
        QSBOOST_PHOENIX_typename_A(                                               \
            QSBOOST_PP_ADD(                                                       \
                N                                                               \
              , QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(3, 1, NAME))              \
            )                                                                   \
        )                                                                       \
    >                                                                           \
    struct QSBOOST_PP_TUPLE_ELEM(3, 0, NAME)<                                     \
        QSBOOST_PHOENIX_A(                                                        \
            QSBOOST_PP_ADD(N, QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(3, 1, NAME))) \
        )                                                                       \
    >                                                                           \
        : expr_ext<                                                             \
            QSBOOST_PP_TUPLE_ELEM(3, 2, NAME)                                     \
          , tag:: QSBOOST_PP_TUPLE_ELEM(3, 0, NAME)                               \
          , QSBOOST_PHOENIX_A(                                                    \
                QSBOOST_PP_ADD(                                                   \
                    N                                                           \
                  , QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(3, 1, NAME))          \
                )                                                               \
            )                                                                   \
        >                                                                       \
    {};                                                                         \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXRPESSION_VARARG_EXT(N, G, D)          \
        template <                                                              \
            QSBOOST_PHOENIX_typename_A_void(                                      \
                QSBOOST_PP_ADD(LIMIT, QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(G)))         \
            )                                                                   \
          , typename Dummy = void                                               \
        >                                                                       \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(N));                      \
                                                                                \
        QSBOOST_PP_REPEAT_FROM_TO(                                                \
            1                                                                   \
          , QSBOOST_PP_ADD(LIMIT, QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(G)))             \
          , QSBOOST_PHOENIX_DEFINE_EXPRESSION_EXT_VARARG_R                        \
          , (                                                                   \
              QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(N))                        \
            , QSBOOST_PP_SEQ_POP_BACK(G)                                          \
            , ACTOR                                                             \
          )                                                                     \
        )                                                                       \
/**/

#define QSBOOST_PHOENIX_DEFINE_EXPRESSION_RULE_VARARG_EXT(N, GRAMMAR, D)          \
        struct QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(N))                       \
            : expression:: QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_SEQ_REVERSE(N)) <         \
                QSBOOST_PP_IF(                                                    \
                    QSBOOST_PP_EQUAL(1, QSBOOST_PP_SEQ_SIZE(GRAMMAR))               \
                  , QSBOOST_PP_EMPTY                                              \
                  , QSBOOST_PP_IDENTITY(                                          \
                      QSBOOST_PP_SEQ_ENUM(QSBOOST_PP_SEQ_POP_BACK(GRAMMAR))         \
                    )                                                           \
                )()                                                             \
                QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR)))     \
                proto::vararg<                                                  \
                    QSBOOST_PP_SEQ_ELEM(                                          \
                        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(GRAMMAR))                \
                      , GRAMMAR                                                 \
                    )                                                           \
                >                                                               \
            >                                                                   \
        {};                                                                     \


#endif

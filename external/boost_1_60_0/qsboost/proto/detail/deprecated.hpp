///////////////////////////////////////////////////////////////////////////////
/// \file deprecated.hpp
/// Definition of the deprecated BOOST_PROTO_DEFINE_FUCTION_TEMPLATE and
/// BOOST_PROTO_DEFINE_VARARG_FUCTION_TEMPLATE macros
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_DETAIL_DEPRECATED_HPP_EAN_11_25_2008
#define QSBOOST_PROTO_DETAIL_DEPRECATED_HPP_EAN_11_25_2008

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/facilities/intercept.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/arithmetic/sub.hpp>
#include <qsboost/preprocessor/punctuation/comma_if.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/control/expr_if.hpp>
#include <qsboost/preprocessor/comparison/greater.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/preprocessor/tuple/to_list.hpp>
#include <qsboost/preprocessor/logical/and.hpp>
#include <qsboost/preprocessor/seq/size.hpp>
#include <qsboost/preprocessor/seq/enum.hpp>
#include <qsboost/preprocessor/seq/seq.hpp>
#include <qsboost/preprocessor/seq/to_tuple.hpp>
#include <qsboost/preprocessor/seq/for_each_i.hpp>
#include <qsboost/preprocessor/seq/pop_back.hpp>
#include <qsboost/preprocessor/seq/push_back.hpp>
#include <qsboost/preprocessor/seq/push_front.hpp>
#include <qsboost/preprocessor/list/for_each_i.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_binary_params.hpp>
#include <qsboost/proto/proto_fwd.hpp>

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TEMPLATE_AUX_(R, DATA, I, ELEM)                                      \
    (ELEM QSBOOST_PP_CAT(QSBOOST_PP_CAT(X, DATA), QSBOOST_PP_CAT(_, I)))                              \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TEMPLATE_YES_(R, DATA, I, ELEM)                                      \
    QSBOOST_PP_LIST_FOR_EACH_I_R(                                                                 \
        R                                                                                       \
      , QSBOOST_PROTO_VARARG_TEMPLATE_AUX_                                                        \
      , I                                                                                       \
      , QSBOOST_PP_TUPLE_TO_LIST(                                                                 \
            QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ELEM))                                               \
          , QSBOOST_PP_SEQ_TO_TUPLE(QSBOOST_PP_SEQ_TAIL(ELEM))                                      \
        )                                                                                       \
    )                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TEMPLATE_NO_(R, DATA, I, ELEM)                                       \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TEMPLATE_(R, DATA, I, ELEM)                                          \
    QSBOOST_PP_IF(                                                                                \
        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ELEM))                                                   \
      , QSBOOST_PROTO_VARARG_TEMPLATE_YES_                                                        \
      , QSBOOST_PROTO_VARARG_TEMPLATE_NO_                                                         \
    )(R, DATA, I, ELEM)                                                                         \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TYPE_AUX_(R, DATA, I, ELEM)                                          \
    (QSBOOST_PP_CAT(QSBOOST_PP_CAT(X, DATA), QSBOOST_PP_CAT(_, I)))                                   \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_TEMPLATE_PARAMS_YES_(R, DATA, I, ELEM)                                      \
    <                                                                                           \
        QSBOOST_PP_SEQ_ENUM(                                                                      \
            QSBOOST_PP_LIST_FOR_EACH_I_R(                                                         \
                R                                                                               \
              , QSBOOST_PROTO_VARARG_TYPE_AUX_                                                    \
              , I                                                                               \
              , QSBOOST_PP_TUPLE_TO_LIST(                                                         \
                    QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ELEM))                                       \
                  , QSBOOST_PP_SEQ_TO_TUPLE(QSBOOST_PP_SEQ_TAIL(ELEM))                              \
                )                                                                               \
            )                                                                                   \
        )                                                                                       \
    >                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_TEMPLATE_PARAMS_NO_(R, DATA, I, ELEM)                                       \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_TYPE_(R, DATA, I, ELEM)                                              \
    QSBOOST_PP_COMMA_IF(I)                                                                        \
    QSBOOST_PP_SEQ_HEAD(ELEM)                                                                     \
    QSBOOST_PP_IF(                                                                                \
        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ELEM))                                                   \
      , QSBOOST_PROTO_TEMPLATE_PARAMS_YES_                                                        \
      , QSBOOST_PROTO_TEMPLATE_PARAMS_NO_                                                         \
    )(R, DATA, I, ELEM) QSBOOST_PP_EXPR_IF(QSBOOST_PP_GREATER(I, 1), const)                         \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_AS_EXPR_(R, DATA, I, ELEM)                                           \
    QSBOOST_PP_EXPR_IF(                                                                           \
        QSBOOST_PP_GREATER(I, 1)                                                                  \
      , ((                                                                                      \
            QSBOOST_PP_SEQ_HEAD(ELEM)                                                             \
            QSBOOST_PP_IF(                                                                        \
                QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ELEM))                                           \
              , QSBOOST_PROTO_TEMPLATE_PARAMS_YES_                                                \
              , QSBOOST_PROTO_TEMPLATE_PARAMS_NO_                                                 \
            )(R, DATA, I, ELEM)()                                                               \
        ))                                                                                      \
    )                                                                                           \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_AS_CHILD_(Z, N, DATA)                                                \
    (QSBOOST_PP_CAT(DATA, N))                                                                     \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_SEQ_PUSH_FRONT(SEQ, ELEM)                                                   \
    QSBOOST_PP_SEQ_POP_BACK(QSBOOST_PP_SEQ_PUSH_FRONT(QSBOOST_PP_SEQ_PUSH_BACK(SEQ, _dummy_), ELEM))  \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_AS_PARAM_(Z, N, DATA)                                                \
    (QSBOOST_PP_CAT(DATA, N))                                                                     \
    /**/

/// INTERNAL ONLY
///
#define QSBOOST_PROTO_VARARG_FUN_(Z, N, DATA)                                                     \
    template<                                                                                   \
        QSBOOST_PP_SEQ_ENUM(                                                                      \
            QSBOOST_PP_SEQ_FOR_EACH_I(                                                            \
                QSBOOST_PROTO_VARARG_TEMPLATE_, ~                                                 \
              , QSBOOST_PP_SEQ_PUSH_FRONT(                                                        \
                    QSBOOST_PROTO_SEQ_PUSH_FRONT(                                                 \
                        QSBOOST_PP_TUPLE_ELEM(4, 2, DATA)                                         \
                      , (QSBOOST_PP_TUPLE_ELEM(4, 3, DATA))                                       \
                    )                                                                           \
                  , QSBOOST_PP_TUPLE_ELEM(4, 1, DATA)                                             \
                )                                                                               \
            )                                                                                   \
            QSBOOST_PP_REPEAT_ ## Z(N, QSBOOST_PROTO_VARARG_AS_PARAM_, typename A)                  \
        )                                                                                       \
    >                                                                                           \
    typename qsboost::proto::result_of::make_expr<                                                \
        QSBOOST_PP_SEQ_FOR_EACH_I(                                                                \
            QSBOOST_PROTO_VARARG_TYPE_, ~                                                         \
          , QSBOOST_PP_SEQ_PUSH_FRONT(                                                            \
                QSBOOST_PROTO_SEQ_PUSH_FRONT(                                                     \
                    QSBOOST_PP_TUPLE_ELEM(4, 2, DATA)                                             \
                  , (QSBOOST_PP_TUPLE_ELEM(4, 3, DATA))                                           \
                )                                                                               \
              , QSBOOST_PP_TUPLE_ELEM(4, 1, DATA)                                                 \
            )                                                                                   \
        )                                                                                       \
        QSBOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(Z, N, A, const & QSBOOST_PP_INTERCEPT)             \
    >::type const                                                                               \
    QSBOOST_PP_TUPLE_ELEM(4, 0, DATA)(QSBOOST_PP_ENUM_BINARY_PARAMS_Z(Z, N, A, const &a))           \
    {                                                                                           \
        return qsboost::proto::detail::make_expr_<                                                \
            QSBOOST_PP_SEQ_FOR_EACH_I(                                                            \
                QSBOOST_PROTO_VARARG_TYPE_, ~                                                     \
              , QSBOOST_PP_SEQ_PUSH_FRONT(                                                        \
                    QSBOOST_PROTO_SEQ_PUSH_FRONT(                                                 \
                        QSBOOST_PP_TUPLE_ELEM(4, 2, DATA)                                         \
                      , (QSBOOST_PP_TUPLE_ELEM(4, 3, DATA))                                       \
                    )                                                                           \
                  , QSBOOST_PP_TUPLE_ELEM(4, 1, DATA)                                             \
                )                                                                               \
            )                                                                                   \
            QSBOOST_PP_ENUM_TRAILING_BINARY_PARAMS_Z(Z, N, A, const & QSBOOST_PP_INTERCEPT)         \
        >()(                                                                                    \
            QSBOOST_PP_SEQ_ENUM(                                                                  \
                QSBOOST_PP_SEQ_FOR_EACH_I(                                                        \
                    QSBOOST_PROTO_VARARG_AS_EXPR_, ~                                              \
                  , QSBOOST_PP_SEQ_PUSH_FRONT(                                                    \
                        QSBOOST_PROTO_SEQ_PUSH_FRONT(                                             \
                            QSBOOST_PP_TUPLE_ELEM(4, 2, DATA)                                     \
                          , (QSBOOST_PP_TUPLE_ELEM(4, 3, DATA))                                   \
                        )                                                                       \
                      , QSBOOST_PP_TUPLE_ELEM(4, 1, DATA)                                         \
                    )                                                                           \
                )                                                                               \
                QSBOOST_PP_REPEAT_ ## Z(N, QSBOOST_PROTO_VARARG_AS_CHILD_, a)                       \
            )                                                                                   \
        );                                                                                      \
    }                                                                                           \
    /**/

/// \code
/// BOOST_PROTO_DEFINE_FUNCTION_TEMPLATE(
///     1
///   , construct
///   , boost::proto::default_domain
///   , (boost::proto::tag::function)
///   , ((op::construct)(typename)(int))
/// )
/// \endcode
#define QSBOOST_PROTO_DEFINE_FUNCTION_TEMPLATE(ARGCOUNT, NAME, DOMAIN, TAG, BOUNDARGS)            \
    QSBOOST_PP_REPEAT_FROM_TO(                                                                    \
        ARGCOUNT                                                                                \
      , QSBOOST_PP_INC(ARGCOUNT)                                                                  \
      , QSBOOST_PROTO_VARARG_FUN_                                                                 \
      , (NAME, TAG, BOUNDARGS, DOMAIN)                                                          \
    )\
    /**/

/// \code
/// BOOST_PROTO_DEFINE_VARARG_FUNCTION_TEMPLATE(
///     construct
///   , boost::proto::default_domain
///   , (boost::proto::tag::function)
///   , ((op::construct)(typename)(int))
/// )
/// \endcode
#define QSBOOST_PROTO_DEFINE_VARARG_FUNCTION_TEMPLATE(NAME, DOMAIN, TAG, BOUNDARGS)               \
    QSBOOST_PP_REPEAT(                                                                            \
        QSBOOST_PP_SUB(QSBOOST_PP_INC(QSBOOST_PROTO_MAX_ARITY), QSBOOST_PP_SEQ_SIZE(BOUNDARGS))         \
      , QSBOOST_PROTO_VARARG_FUN_                                                                 \
      , (NAME, TAG, BOUNDARGS, DOMAIN)                                                          \
    )                                                                                           \
    /**/

#endif

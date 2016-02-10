/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !QSBOOST_PHOENIX_IS_ITERATING

#define QSBOOST_PHOENIX_typename_A(N)                                             \
    QSBOOST_PP_ENUM_PARAMS(N, typename A)                                         \
/**/

#define QSBOOST_PHOENIX_typename_A_void(N)                                        \
    QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(N, typename A, void)                    \
/**/

#define QSBOOST_PHOENIX_A(N)                                                      \
    QSBOOST_PP_ENUM_PARAMS(N, A)                                                  \
/**/

#define QSBOOST_PHOENIX_A_ref(N)                                                  \
    QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & QSBOOST_PP_INTERCEPT)                     \
/**/

#define QSBOOST_PHOENIX_A_const_ref(N)                                            \
    QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const& QSBOOST_PP_INTERCEPT)                \
/**/

#define QSBOOST_PHOENIX_A_a(N)                                                    \
    QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, a)                                        \
/**/

#define QSBOOST_PHOENIX_A_ref_a(N)                                                \
    QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & a)                                      \
/**/

#define QSBOOST_PHOENIX_A_const_ref_a(N)                                          \
    QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a)                                 \
/**/

#define QSBOOST_PHOENIX_a(N)                                                      \
    QSBOOST_PP_ENUM_PARAMS(N, a)                                                  \
/**/

#else

#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/seq/elem.hpp>
#include <qsboost/preprocessor/seq/enum.hpp>
#include <qsboost/preprocessor/seq/for_each_i.hpp>
#include <qsboost/preprocessor/seq/for_each_product.hpp>
#include <qsboost/preprocessor/seq/size.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>

#define QSBOOST_PHOENIX_ITERATION                                                 \
    QSBOOST_PP_ITERATION()                                                        \
/**/

#define QSBOOST_PHOENIX_typename_A                                                \
    QSBOOST_PP_ENUM_PARAMS(QSBOOST_PHOENIX_ITERATION, typename A)                   \
/**/

#define QSBOOST_PHOENIX_typename_A_void                                           \
    QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(QSBOOST_PHOENIX_ITERATION, typename A, void)
/**/

#define QSBOOST_PHOENIX_A                                                          \
    QSBOOST_PP_ENUM_PARAMS(QSBOOST_PHOENIX_ITERATION, A)                             \
/**/

#define QSBOOST_PHOENIX_A_ref                                                      \
    QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PHOENIX_ITERATION, A, & QSBOOST_PP_INTERCEPT)\
/**/

#define QSBOOST_PHOENIX_A_const_ref                                                \
    QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PHOENIX_ITERATION, A, const& QSBOOST_PP_INTERCEPT)\
/**/

#define QSBOOST_PHOENIX_A_a                                                        \
    QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PHOENIX_ITERATION, A, a)                   \
/**/

#define QSBOOST_PHOENIX_A_ref_a                                                    \
    QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PHOENIX_ITERATION, A, & a)                 \
/**/

#define QSBOOST_PHOENIX_A_const_ref_a                                              \
    QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PHOENIX_ITERATION, A, const& a)            \
/**/

#define QSBOOST_PHOENIX_a                                                          \
    QSBOOST_PP_ENUM_PARAMS(QSBOOST_PHOENIX_ITERATION, a)                             \
/**/

    /////////////////////////////////////////////////////////////////////////////
    // Begin Perfect Forward argument permutation calculation
    /////////////////////////////////////////////////////////////////////////////
#define QSBOOST_PHOENIX_M0_R(_, N, __)                                            \
    (((A ## N)(&))((A ## N)(const&)))                                           \
/**/

#define QSBOOST_PHOENIX_M0                                                        \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, QSBOOST_PHOENIX_M0_R, _)             \
/**/

#define QSBOOST_PHOENIX_M1_R_R(_, N, SEQ)                                         \
    QSBOOST_PP_SEQ_ELEM(N, SEQ)                                                   \
/**/

#define QSBOOST_PHOENIX_M1_R(R, __, ___, ELEM)                                    \
    (QSBOOST_PP_REPEAT(QSBOOST_PP_SEQ_SIZE(ELEM), QSBOOST_PHOENIX_M1_R_R, ELEM))      \
/**/

#define QSBOOST_PHOENIX_M1(R, PRODUCT)                                            \
    ((QSBOOST_PP_SEQ_ENUM                                                         \
        (QSBOOST_PP_SEQ_FOR_EACH_I_R                                              \
            (R, QSBOOST_PHOENIX_M1_R, _, PRODUCT))))                              \
/**/

#define QSBOOST_PHOENIX_PERM_SEQ                                                  \
    QSBOOST_PP_SEQ_FOR_EACH_PRODUCT(QSBOOST_PHOENIX_M1, QSBOOST_PHOENIX_M0)           \
/**/
    ////////////////////////////////////////////////////////////////////////////
    // End
    ////////////////////////////////////////////////////////////////////////////

#define QSBOOST_PHOENIX_PERM_SIZE                                                 \
    QSBOOST_PP_SEQ_SIZE(QSBOOST_PHOENIX_PERM_SEQ)                                   \
/**/

#define QSBOOST_PHOENIX_M2(_, N, TUPLE)                                           \
    QSBOOST_PP_COMMA_IF(N) QSBOOST_PP_TUPLE_ELEM(QSBOOST_PHOENIX_ITERATION, N, TUPLE) \
/**/
    
#define QSBOOST_PHOENIX_M3(_, N, TUPLE)                                           \
    QSBOOST_PP_COMMA_IF(N) QSBOOST_PP_TUPLE_ELEM(QSBOOST_PHOENIX_ITERATION, N, TUPLE) a ## N\
/**/

#define QSBOOST_PHOENIX_PERM_ELEM(N)                                              \
    QSBOOST_PP_SEQ_ELEM(N, QSBOOST_PHOENIX_PERM_SEQ)                                \
/**/

#define QSBOOST_PHOENIX_PERM_A(N)                                                 \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, QSBOOST_PHOENIX_M2, QSBOOST_PHOENIX_PERM_ELEM(N))\
/**/

#define QSBOOST_PHOENIX_PERM_A_a(N)                                               \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, QSBOOST_PHOENIX_M3, QSBOOST_PHOENIX_PERM_ELEM(N))\
/**/

#endif

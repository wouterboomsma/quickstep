#ifdef QSBOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4512) // assignment operator could not be generated
#pragma warning(disable: 4510) // default constructor could not be generated
#pragma warning(disable: 4610) // can never be instantiated - user defined constructor required
#endif
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#ifndef QSBOOST_PHOENIX_SUPPORT_VECTOR_HPP
#define QSBOOST_PHOENIX_SUPPORT_VECTOR_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_shifted_params.hpp>
#include <qsboost/fusion/adapted/struct/adapt_struct.hpp>

#define QSBOOST_FUSION_ADAPT_TPL_STRUCT_NO_PARTIAL QSBOOST_FUSION_ADAPT_TPL_STRUCT

#include <qsboost/phoenix/support/preprocessed/vector.hpp>

#endif

#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_SUPPORT_VECTOR_HPP
#define QSBOOST_PHOENIX_SUPPORT_VECTOR_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_shifted_params.hpp>
#include <qsboost/fusion/adapted/struct/adapt_struct.hpp>

#define QSBOOST_FUSION_ADAPT_TPL_STRUCT_NO_PARTIAL QSBOOST_FUSION_ADAPT_TPL_STRUCT

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vector_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
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
    typedef QSBOOST_PP_CAT(A, N) QSBOOST_PP_CAT(member_type, N);                    \
    QSBOOST_PP_CAT(A, N) QSBOOST_PP_CAT(a, N);                                      \
/**/
#define M1(Z, N, D)                                                             \
    (QSBOOST_PP_CAT(A, N))                                                        \
/**/
#define M2(Z, N, D)                                                             \
    (QSBOOST_PP_CAT(T, N))                                                        \
/**/
#define M3(Z, N, D)                                                             \
    (QSBOOST_PP_CAT(A, N), QSBOOST_PP_CAT(a, N))                                    \
/**/

namespace qsboost { namespace phoenix
{
    template <typename Dummy = void>
    struct vector0
    {
        typedef mpl::int_<0> size_type;
        static const int size_value = 0;
    };
}}


#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
        (3, (1, QSBOOST_PP_INC(QSBOOST_PHOENIX_LIMIT),                              \
        <qsboost/phoenix/support/vector.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

#undef M0
#undef M1
#undef M2
#undef M3

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

namespace qsboost { namespace phoenix
{
    template <QSBOOST_PHOENIX_typename_A>
    struct QSBOOST_PP_CAT(vector, QSBOOST_PHOENIX_ITERATION)
    {
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M0, _)
        
        typedef mpl::int_<QSBOOST_PHOENIX_ITERATION> size_type;
        static const int size_value = QSBOOST_PHOENIX_ITERATION;

        typedef
            QSBOOST_PP_CAT(vector, QSBOOST_PP_DEC(QSBOOST_PHOENIX_ITERATION))<QSBOOST_PP_ENUM_SHIFTED_PARAMS(QSBOOST_PHOENIX_ITERATION, A)>
            args_type;

        args_type args() const
        {
            args_type r = {QSBOOST_PP_ENUM_SHIFTED_PARAMS(QSBOOST_PHOENIX_ITERATION, a)};
            return r;
        }
    };
}}

#define QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM0                                \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M1, _)                             \
/**/
#define QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM1                                \
   (                                                                            \
        QSBOOST_PP_CAT(                                                           \
            qsboost::phoenix::vector                                              \
          , QSBOOST_PHOENIX_ITERATION                                             \
        )                                                                       \
    )                                                                           \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M1, _)                             \
/**/
#define QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM2                                \
    QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ITERATION, M3, _)                             \
/**/

QSBOOST_FUSION_ADAPT_TPL_STRUCT_NO_PARTIAL(
    QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM0
  , QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM1
  , QSBOOST_PHOENIX_SUPPORT_VECTOR_ADAT_PARAM2
)

#endif

#endif

#ifdef QSBOOST_MSVC
#pragma warning(pop)
#endif

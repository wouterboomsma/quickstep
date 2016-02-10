/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PP_IS_ITERATING
#if !defined(FUSION_VECTOR_N_CHOOSER_07072005_1248)
#define FUSION_VECTOR_N_CHOOSER_07072005_1248

#include <qsboost/fusion/container/vector/detail/cpp03/limits.hpp>

//  include vector0..N where N is FUSION_MAX_VECTOR_SIZE
#include <qsboost/fusion/container/vector/detail/cpp03/vector10.hpp>
#if (FUSION_MAX_VECTOR_SIZE > 10)
#include <qsboost/fusion/container/vector/detail/cpp03/vector20.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 20)
#include <qsboost/fusion/container/vector/detail/cpp03/vector30.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 30)
#include <qsboost/fusion/container/vector/detail/cpp03/vector40.hpp>
#endif
#if (FUSION_MAX_VECTOR_SIZE > 40)
#include <qsboost/fusion/container/vector/detail/cpp03/vector50.hpp>
#endif

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/arithmetic/sub.hpp>
#include <qsboost/preprocessor/facilities/intercept.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>

namespace qsboost { namespace fusion
{
    struct void_;
}}

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/vector/detail/cpp03/preprocessed/vector_chooser.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vector_chooser" FUSION_MAX_VECTOR_SIZE_STR ".hpp")
#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace qsboost { namespace fusion { namespace detail
{
    template <QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename T)>
    struct vector_n_chooser
    {
        typedef QSBOOST_PP_CAT(vector, FUSION_MAX_VECTOR_SIZE)<QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, T)> type;
    };

    template <>
    struct vector_n_chooser<QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, void_ QSBOOST_PP_INTERCEPT)>
    {
        typedef vector0<> type;
    };

#define QSBOOST_PP_FILENAME_1 \
    <qsboost/fusion/container/vector/detail/cpp03/vector_n_chooser.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (1, QSBOOST_PP_DEC(FUSION_MAX_VECTOR_SIZE))
#include QSBOOST_PP_ITERATE()

}}}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(BOOST_PP_IS_ITERATING)

#define N QSBOOST_PP_ITERATION()

    template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
    struct vector_n_chooser<
        QSBOOST_PP_ENUM_PARAMS(N, T)
        QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_SUB(FUSION_MAX_VECTOR_SIZE, N), void_ QSBOOST_PP_INTERCEPT)>
    {
        typedef QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> type;
    };

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)

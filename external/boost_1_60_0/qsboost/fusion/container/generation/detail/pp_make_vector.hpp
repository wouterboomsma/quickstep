/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PP_IS_ITERATING
#if !defined(FUSION_MAKE_VECTOR_07162005_0243)
#define FUSION_MAKE_VECTOR_07162005_0243

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/fusion/container/vector/vector.hpp>
#include <qsboost/fusion/support/detail/as_fusion_element.hpp>

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/generation/detail/preprocessed/make_vector.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_vector" FUSION_MAX_VECTOR_SIZE_STR".hpp")
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

namespace qsboost { namespace fusion
{
    struct void_;

    namespace result_of
    {
        template <
            QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_VECTOR_SIZE, typename T, void_)
          , typename Extra = void_
        >
        struct make_vector;

        template <>
        struct make_vector<>
        {
            typedef vector0<> type;
        };
    }

    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline vector0<>
    make_vector()
    {
        return vector0<>();
    }

#define QSBOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename detail::as_fusion_element<QSBOOST_PP_CAT(T, n)>::type

#define QSBOOST_PP_FILENAME_1 <qsboost/fusion/container/generation/detail/pp_make_vector.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include QSBOOST_PP_ITERATE()

#undef QSBOOST_FUSION_AS_FUSION_ELEMENT

}}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif
#else // defined(BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N QSBOOST_PP_ITERATION()

    namespace result_of
    {
        template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
        #define TEXT(z, n, text) , text
        struct make_vector< QSBOOST_PP_ENUM_PARAMS(N, T) QSBOOST_PP_REPEAT_FROM_TO(QSBOOST_PP_DEC(N), FUSION_MAX_VECTOR_SIZE, TEXT, void_) >
        #undef TEXT
        {
            typedef QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)> type;
        };
    }

    template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_vector(QSBOOST_PP_ENUM_BINARY_PARAMS(N, T, const& arg))
    {
        return QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            QSBOOST_PP_ENUM_PARAMS(N, arg));
    }

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)


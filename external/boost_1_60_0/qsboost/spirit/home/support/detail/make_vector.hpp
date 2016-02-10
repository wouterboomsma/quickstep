/*=============================================================================
    Copyright (c) 2001-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <qsboost/version.hpp>

// This is the same as the one in fusion in Boost 1.41. This is provided
// for compatibility with Boost 1.40 and below.

#if (QSBOOST_VERSION > 104000)

#include <qsboost/fusion/include/make_vector.hpp>

namespace qsboost { namespace spirit { namespace detail
{
    namespace result_of
    {
        using fusion::result_of::make_vector;
    }
    using fusion::make_vector;
}}}

#else

#ifndef QSBOOST_PP_IS_ITERATING
#if !defined(SPIRIT_MAKE_VECTOR_07162005_0243)
#define SPIRIT_MAKE_VECTOR_07162005_0243

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/fusion/container/vector/vector.hpp>
#include <qsboost/fusion/support/detail/as_fusion_element.hpp>

namespace qsboost { namespace fusion
{
    struct void_;
}}

namespace qsboost { namespace spirit { namespace detail
{
    namespace result_of
    {
        template <
            QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
                FUSION_MAX_VECTOR_SIZE, typename T, fusion::void_)
          , typename Extra = fusion::void_
        >
        struct make_vector;

        template <>
        struct make_vector<>
        {
            typedef fusion::vector0 type;
        };
    }

    inline fusion::vector0
    make_vector()
    {
        return fusion::vector0();
    }

#define QSBOOST_FUSION_AS_FUSION_ELEMENT(z, n, data)                               \
    typename fusion::detail::as_fusion_element<QSBOOST_PP_CAT(T, n)>::type

#define QSBOOST_PP_FILENAME_1 <qsboost/spirit/home/support/detail/make_vector.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include QSBOOST_PP_ITERATE()

#undef QSBOOST_FUSION_AS_FUSION_ELEMENT

}}}

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
#if defined(QSBOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS)
        #define TEXT(z, n, text) , text
        struct make_vector< QSBOOST_PP_ENUM_PARAMS(N, T) QSBOOST_PP_REPEAT_FROM_TO(QSBOOST_PP_DEC(N), FUSION_MAX_VECTOR_SIZE, TEXT, fusion::void_) >
        #undef TEXT
#else
        struct make_vector<QSBOOST_PP_ENUM_PARAMS(N, T)>
#endif
        {
            typedef QSBOOST_PP_CAT(fusion::vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)> type;
        };
    }

    template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
    inline QSBOOST_PP_CAT(fusion::vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)>
    make_vector(QSBOOST_PP_ENUM_BINARY_PARAMS(N, T, const& _))
    {
        return QSBOOST_PP_CAT(fusion::vector, N)<QSBOOST_PP_ENUM(N, QSBOOST_FUSION_AS_FUSION_ELEMENT, _)>(
            QSBOOST_PP_ENUM_PARAMS(N, _));
    }

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)
#endif // (BOOST_VERSION > 103800)

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PP_IS_ITERATING
#if !defined(FUSION_AS_VECTOR_09222005_0950)
#define FUSION_AS_VECTOR_09222005_0950

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/inc.hpp>
#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/fusion/container/vector/vector.hpp>
#include <qsboost/fusion/iterator/value_of.hpp>
#include <qsboost/fusion/iterator/deref.hpp>
#include <qsboost/fusion/iterator/next.hpp>

namespace qsboost { namespace fusion { namespace detail
{
QSBOOST_FUSION_BARRIER_BEGIN

    template <int size>
    struct as_vector;

    template <>
    struct as_vector<0>
    {
        template <typename Iterator>
        struct apply
        {
            typedef vector0<> type;
        };

        template <typename Iterator>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static typename apply<Iterator>::type
        call(Iterator)
        {
            return vector0<>();
        }
    };

QSBOOST_FUSION_BARRIER_END
}}}

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/vector/detail/cpp03/preprocessed/as_vector.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/as_vector" FUSION_MAX_VECTOR_SIZE_STR ".hpp")
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
QSBOOST_FUSION_BARRIER_BEGIN

#define QSBOOST_FUSION_NEXT_ITERATOR(z, n, data)                                  \
    typedef typename fusion::result_of::next<QSBOOST_PP_CAT(I, n)>::type          \
        QSBOOST_PP_CAT(I, QSBOOST_PP_INC(n));

#define QSBOOST_FUSION_NEXT_CALL_ITERATOR(z, n, data)                             \
    typename gen::QSBOOST_PP_CAT(I, QSBOOST_PP_INC(n))                              \
        QSBOOST_PP_CAT(i, QSBOOST_PP_INC(n)) = fusion::next(QSBOOST_PP_CAT(i, n));

#define QSBOOST_FUSION_VALUE_OF_ITERATOR(z, n, data)                              \
    typedef typename fusion::result_of::value_of<QSBOOST_PP_CAT(I, n)>::type      \
        QSBOOST_PP_CAT(T, n);

#define QSBOOST_PP_FILENAME_1 <qsboost/fusion/container/vector/detail/cpp03/as_vector.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (1, FUSION_MAX_VECTOR_SIZE)
#include QSBOOST_PP_ITERATE()

#undef QSBOOST_FUSION_NEXT_ITERATOR
#undef QSBOOST_FUSION_NEXT_CALL_ITERATOR
#undef QSBOOST_FUSION_VALUE_OF_ITERATOR

QSBOOST_FUSION_BARRIER_END
}}}

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

    template <>
    struct as_vector<N>
    {
        template <typename I0>
        struct apply
        {
            QSBOOST_PP_REPEAT(N, QSBOOST_FUSION_NEXT_ITERATOR, _)
            QSBOOST_PP_REPEAT(N, QSBOOST_FUSION_VALUE_OF_ITERATOR, _)
            typedef QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> type;
        };

        template <typename Iterator>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static typename apply<Iterator>::type
        call(Iterator const& i0)
        {
            typedef apply<Iterator> gen;
            typedef typename gen::type result;
            QSBOOST_PP_REPEAT(QSBOOST_PP_DEC(N), QSBOOST_FUSION_NEXT_CALL_ITERATOR, _)
            return result(QSBOOST_PP_ENUM_PARAMS(N, *i));
        }
    };

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)


/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PP_IS_ITERATING
#if !defined(QSBOOST_SPIRIT_AS_VARIANT_NOVEMBER_16_2007_0420PM)
#define QSBOOST_SPIRIT_AS_VARIANT_NOVEMBER_16_2007_0420PM

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/variant/variant_fwd.hpp>
#include <qsboost/fusion/include/size.hpp>
#include <qsboost/fusion/include/begin.hpp>
#include <qsboost/fusion/include/next.hpp>
#include <qsboost/fusion/include/value_of.hpp>
#include <qsboost/mpl/fold.hpp>
#include <qsboost/mpl/vector.hpp>
#include <qsboost/mpl/push_back.hpp>
#include <qsboost/mpl/equal_to.hpp>
#include <qsboost/mpl/contains.hpp>
#include <qsboost/mpl/limits/list.hpp>
#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace spirit { namespace detail
{
    template <int size>
    struct as_variant_impl;

#if !defined(QSBOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)
#else
    template <>
    struct as_variant_impl<0>
    {
        template <typename Iterator>
        struct apply
        {
            typedef variant<> type;
        };
    };
#endif

#define QSBOOST_FUSION_NEXT_ITERATOR(z, n, data)                                  \
    typedef typename fusion::result_of::next<QSBOOST_PP_CAT(I, n)>::type          \
        QSBOOST_PP_CAT(I, QSBOOST_PP_INC(n));

#define QSBOOST_FUSION_NEXT_CALL_ITERATOR(z, n, data)                             \
    typename gen::QSBOOST_PP_CAT(I, QSBOOST_PP_INC(n))                              \
        QSBOOST_PP_CAT(i, QSBOOST_PP_INC(n)) = fusion::next(QSBOOST_PP_CAT(i, n));

#define QSBOOST_FUSION_VALUE_OF_ITERATOR(z, n, data)                              \
    typedef typename fusion::result_of::value_of<QSBOOST_PP_CAT(I, n)>::type      \
        QSBOOST_PP_CAT(T, n);

#define QSBOOST_PP_FILENAME_1 <qsboost/spirit/home/support/detail/as_variant.hpp>

#if !defined(QSBOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)
#define QSBOOST_PP_ITERATION_LIMITS (1, QSBOOST_MPL_LIMIT_LIST_SIZE)
#else
#define QSBOOST_PP_ITERATION_LIMITS (1, QSBOOST_VARIANT_LIMIT_TYPES)
#endif

#include QSBOOST_PP_ITERATE()

#undef QSBOOST_FUSION_NEXT_ITERATOR
#undef QSBOOST_FUSION_NEXT_CALL_ITERATOR
#undef QSBOOST_FUSION_VALUE_OF_ITERATOR

    template <typename Sequence>
    struct as_variant
    {
        // build a variant generator being able to generate a variant holding
        // all of the types as given in the typelist
        typedef typename
            detail::as_variant_impl<fusion::result_of::size<Sequence>::value>
        gen;

        // use this generator to create the actual variant
        typedef typename gen::template apply<
                typename fusion::result_of::begin<Sequence>::type
            >::type
        type;
    };
}}}

#endif
#else // defined(BOOST_PP_IS_ITERATING)
///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////

#define N QSBOOST_PP_ITERATION()

    template <>
    struct as_variant_impl<N>
    {
        template <typename I0>
        struct apply
        {
            QSBOOST_PP_REPEAT(N, QSBOOST_FUSION_NEXT_ITERATOR, _)
            QSBOOST_PP_REPEAT(N, QSBOOST_FUSION_VALUE_OF_ITERATOR, _)
            typedef variant<QSBOOST_PP_ENUM_PARAMS(N, T)> type;
        };
    };

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)


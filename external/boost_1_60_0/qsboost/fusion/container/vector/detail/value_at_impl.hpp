/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_VALUE_AT_IMPL_16122014_1641
#define QSBOOSTFUSION_VALUE_AT_IMPL_16122014_1641

#include <qsboost/config.hpp>
#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/detail/config.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <qsboost/fusion/container/vector/detail/cpp03/value_at_impl.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <qsboost/fusion/container/vector/vector_fwd.hpp>
#include <qsboost/type_traits/declval.hpp>
#include <qsboost/type_traits/remove_cv.hpp>

namespace qsboost { namespace fusion
{
    struct vector_tag;

    namespace vector_detail
    {
        template <typename I, typename ...T>
        struct vector_data;
    }

    namespace extension
    {
        template <typename Tag>
        struct value_at_impl;

        template <>
        struct value_at_impl<vector_tag>
        {
            template <typename Sequence, typename N>
            struct apply
            {
                typedef typename qsboost::remove_cv<Sequence>::type seq;
                typedef typename mpl::identity<decltype(seq::template value_at_impl<N::value>(qsboost::declval<seq*>()))>::type::type type;
            };
        };
    }
}}

#endif
#endif


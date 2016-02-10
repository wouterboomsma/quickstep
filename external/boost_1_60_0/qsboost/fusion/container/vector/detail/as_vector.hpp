/*=============================================================================
    Copyright (c) 2014-2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_AS_VECTOR_11052014_1801
#define QSBOOSTFUSION_AS_VECTOR_11052014_1801

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/detail/config.hpp>

///////////////////////////////////////////////////////////////////////////////
// Without variadics, we will use the PP version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <qsboost/fusion/container/vector/detail/cpp03/as_vector.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <qsboost/fusion/support/detail/index_sequence.hpp>
#include <qsboost/fusion/container/vector/vector.hpp>
#include <qsboost/fusion/iterator/value_of.hpp>
#include <qsboost/fusion/iterator/deref.hpp>
#include <qsboost/fusion/iterator/advance.hpp>
#include <cstddef>

namespace qsboost { namespace fusion { namespace detail
{
QSBOOST_FUSION_BARRIER_BEGIN

    template <typename Indices>
    struct as_vector_impl;

    template <std::size_t ...Indices>
    struct as_vector_impl<index_sequence<Indices...> >
    {
        template <typename Iterator>
        struct apply
        {
            typedef vector<
                typename result_of::value_of<
                    typename result_of::advance_c<Iterator, Indices>::type
                >::type...
            > type;
        };

        template <typename Iterator>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static typename apply<Iterator>::type
        call(Iterator i)
        {
            typedef typename apply<Iterator>::type result;
            return result(*advance_c<Indices>(i)...);
        }
    };

    template <int size>
    struct as_vector
        : as_vector_impl<typename make_index_sequence<size>::type> {};

QSBOOST_FUSION_BARRIER_END
}}}

#endif
#endif



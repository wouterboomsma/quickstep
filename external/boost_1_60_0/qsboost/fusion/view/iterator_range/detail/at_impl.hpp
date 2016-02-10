/*=============================================================================
    Copyright (c) 2007 Tobias Schwinger

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(QSBOOST_FUSION_ITERATOR_RANGE_AT_IMPL_HPP_INCLUDED)
#define QSBOOST_FUSION_ITERATOR_RANGE_AT_IMPL_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/iterator/advance.hpp>
#include <qsboost/fusion/iterator/deref.hpp>

namespace qsboost { namespace fusion
{
    struct iterator_range_tag;

    namespace extension
    {
        template <typename Tag>
        struct at_impl;

        template <>
        struct at_impl<iterator_range_tag>
        {
            template <typename Seq, typename N>
            struct apply
            {
                typedef typename Seq::begin_type begin_type;
                typedef typename result_of::advance<begin_type,N>::type pos;
                typedef typename result_of::deref<pos>::type type;

                QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
                static type
                call(Seq& s)
                {
                    return * fusion::advance<N>(s.first);
                }
            };
        };
    }
}}

#endif


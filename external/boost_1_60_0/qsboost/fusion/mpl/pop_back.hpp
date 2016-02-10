/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_POP_BACK_10022005_1801)
#define FUSION_POP_BACK_10022005_1801

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/pop_back.hpp>
#include <qsboost/fusion/support/tag_of.hpp>
#include <qsboost/fusion/algorithm/transformation/pop_back.hpp>
#include <qsboost/fusion/sequence/convert.hpp>

namespace qsboost { namespace mpl
{
    template <typename Tag>
    struct pop_back_impl;

    template <>
    struct pop_back_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence>
        struct apply
        {
            typedef typename
                fusion::result_of::pop_back<Sequence>::type
            result;

            typedef typename
                fusion::result_of::convert<
                    typename fusion::detail::tag_of<Sequence>::type, result>::type
            type;
        };
    };
}}

#endif


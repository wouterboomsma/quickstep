/*=============================================================================
    Copyright (c) 2009 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_DEREF_DATA_IMPL_HPP
#define QSBOOST_FUSION_VIEW_REVERSE_VIEW_DETAIL_DEREF_DATA_IMPL_HPP

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/iterator/deref_data.hpp>

namespace qsboost { namespace fusion { namespace extension
{
    template <typename>
    struct deref_data_impl;

    template <>
    struct deref_data_impl<reverse_view_iterator_tag>
    {
        template <typename It>
        struct apply
        {
            typedef typename
                result_of::deref_data<typename It::first_type>::type
            type;

            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type
            call(It const& it)
            {
                return fusion::deref_data(it.first);
            }
        };
    };
}}}

#endif

/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(QSBOOST_FUSION_SINGLE_VIEW_VALUE_AT_IMPL_JUL_07_2011_1348PM)
#define QSBOOST_FUSION_SINGLE_VIEW_VALUE_AT_IMPL_JUL_07_2011_1348PM

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/mpl/equal_to.hpp>
#include <qsboost/fusion/sequence/intrinsic/value_at.hpp>

namespace qsboost { namespace fusion 
{
    struct single_view_tag;

    namespace extension
    {
        template<typename Tag>
        struct value_at_impl;

        template<>
        struct value_at_impl<single_view_tag>
        {
            template<typename Sequence, typename N>
            struct apply
            {
                QSBOOST_MPL_ASSERT((mpl::equal_to<N, mpl::int_<0> >));
                typedef typename Sequence::value_type type;
            };
        };
    }

}}

#endif

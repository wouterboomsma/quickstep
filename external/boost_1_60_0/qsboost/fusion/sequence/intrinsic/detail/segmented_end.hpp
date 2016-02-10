/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SEGMENTED_END_HPP_INCLUDED)
#define QSBOOST_FUSION_SEGMENTED_END_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/sequence/intrinsic/detail/segmented_end_impl.hpp>
#include <qsboost/fusion/iterator/segmented_iterator.hpp>
#include <qsboost/fusion/container/list/cons.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    //auto segmented_end( seq )
    //{
    //    return make_segmented_iterator( segmented_end_impl( seq ) );
    //}

    template <typename Sequence, typename Nil_ = fusion::nil_>
    struct segmented_end
    {
        typedef
            segmented_iterator<
                typename segmented_end_impl<Sequence, Nil_>::type
            >
        type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static type call(Sequence & seq)
        {
            return type(
                segmented_end_impl<Sequence, Nil_>::call(seq, Nil_()));
        }
    };

}}}

#endif

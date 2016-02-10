/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SEGMENTED_BEGIN_HPP_INCLUDED)
#define QSBOOST_FUSION_SEGMENTED_BEGIN_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/sequence/intrinsic/detail/segmented_begin_impl.hpp>
#include <qsboost/fusion/iterator/segmented_iterator.hpp>
#include <qsboost/fusion/view/iterator_range.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/sequence/intrinsic/end.hpp>
#include <qsboost/fusion/sequence/intrinsic/empty.hpp>
#include <qsboost/fusion/container/list/cons.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    //auto segmented_begin( seq )
    //{
    //    return make_segmented_iterator( segmented_begin_impl( seq, nil_ ) );
    //}

    template <typename Sequence, typename Nil_ = fusion::nil_>
    struct segmented_begin
    {
        typedef
            segmented_iterator<
                typename segmented_begin_impl<Sequence, Nil_>::type
            >
        type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static type call(Sequence& seq)
        {
            return type(
                segmented_begin_impl<Sequence, Nil_>::call(seq, Nil_()));
        }
    };

}}}

#endif

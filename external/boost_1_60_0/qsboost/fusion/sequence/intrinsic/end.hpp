/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_END_04052005_1141)
#define FUSION_END_04052005_1141

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/mpl/empty_base.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/fusion/sequence/intrinsic_fwd.hpp>
#include <qsboost/fusion/support/tag_of.hpp>
#include <qsboost/fusion/support/is_sequence.hpp>
#include <qsboost/fusion/support/is_segmented.hpp>
#include <qsboost/fusion/sequence/intrinsic/detail/segmented_end.hpp>

namespace qsboost { namespace fusion
{
    // Special tags:
    struct sequence_facade_tag;
    struct qsboost_tuple_tag; // boost::tuples::tuple tag
    struct qsboost_array_tag; // boost::array tag
    struct mpl_sequence_tag; // mpl sequence tag
    struct std_pair_tag; // std::pair tag

    namespace extension
    {
        template <typename Tag>
        struct end_impl
        {
            template <typename Sequence>
            struct apply
              : mpl::if_<
                    traits::is_segmented<Sequence>
                  , detail::segmented_end<Sequence>
                  , mpl::empty_base
                >::type
            {};
        };

        template <>
        struct end_impl<sequence_facade_tag>
        {
            template <typename Sequence>
            struct apply : Sequence::template end<Sequence> {};
        };

        template <>
        struct end_impl<qsboost_tuple_tag>;

        template <>
        struct end_impl<qsboost_array_tag>;

        template <>
        struct end_impl<mpl_sequence_tag>;

        template <>
        struct end_impl<std_pair_tag>;
    }

    namespace result_of
    {
        template <typename Sequence>
        struct end
            : extension::end_impl<typename detail::tag_of<Sequence>::type>::
                template apply<Sequence>
        {};
    }

    template <typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename
        lazy_enable_if<
            traits::is_sequence<Sequence>
          , result_of::end<Sequence>
        >::type const
    end(Sequence& seq)
    {
        return result_of::end<Sequence>::call(seq);
    }

    template <typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename
        lazy_enable_if<
            traits::is_sequence<Sequence>
          , result_of::end<Sequence const>
        >::type const
    end(Sequence const& seq)
    {
        return result_of::end<Sequence const>::call(seq);
    }
}}

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_SIZE_05052005_0214)
#define FUSION_SIZE_05052005_0214

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/fusion/sequence/intrinsic_fwd.hpp>
#include <qsboost/fusion/support/tag_of.hpp>
#include <qsboost/fusion/support/is_segmented.hpp>
#include <qsboost/fusion/sequence/intrinsic/detail/segmented_size.hpp>

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
        struct size_impl
        {
            template<typename Sequence>
            struct unsegmented_size : Sequence::size {};

            template <typename Sequence>
            struct apply
              : mpl::if_<
                    traits::is_segmented<Sequence>
                  , detail::segmented_size<Sequence>
                  , unsegmented_size<Sequence>
                >::type
            {};
        };

        template <>
        struct size_impl<sequence_facade_tag>
        {
            template <typename Sequence>
            struct apply : Sequence::template size<Sequence> {};
        };

        template <>
        struct size_impl<qsboost_tuple_tag>;

        template <>
        struct size_impl<qsboost_array_tag>;

        template <>
        struct size_impl<mpl_sequence_tag>;

        template <>
        struct size_impl<std_pair_tag>;
    }

    namespace result_of
    {
        template <typename Sequence>
        struct size
            : mpl::int_<
                  extension::size_impl<typename detail::tag_of<Sequence>::type>
                      ::template apply<Sequence>::type::value
              > {};
    }

    template <typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::size<Sequence>::type
    size(Sequence const&)
    {
        typedef typename result_of::size<Sequence>::type result;
        return result();
    }
}}

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VALUE_AT_KEY_05052005_0229)
#define FUSION_VALUE_AT_KEY_05052005_0229

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/empty_base.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/or.hpp>
#include <qsboost/fusion/sequence/intrinsic_fwd.hpp>
#include <qsboost/fusion/sequence/intrinsic/has_key.hpp>
#include <qsboost/fusion/iterator/value_of_data.hpp>
#include <qsboost/fusion/algorithm/query/find.hpp>
#include <qsboost/fusion/support/tag_of.hpp>
#include <qsboost/fusion/support/category_of.hpp>

namespace qsboost { namespace fusion
{
    // Special tags:
    struct sequence_facade_tag;
    struct qsboost_array_tag; // boost::array tag
    struct mpl_sequence_tag; // mpl sequence tag
    struct std_pair_tag; // std::pair tag

    namespace extension
    {
        template <typename Tag>
        struct value_at_key_impl
        {
            template <typename Seq, typename Key>
            struct apply
              : result_of::value_of_data<
                    typename result_of::find<Seq, Key>::type
                >
            {};
        };

        template <>
        struct value_at_key_impl<sequence_facade_tag>
        {
            template <typename Sequence, typename Key>
            struct apply : Sequence::template value_at_key<Sequence, Key> {};
        };

        template <>
        struct value_at_key_impl<qsboost_array_tag>;

        template <>
        struct value_at_key_impl<mpl_sequence_tag>;

        template <>
        struct value_at_key_impl<std_pair_tag>;
    }

    namespace detail
    {
        template <typename Sequence, typename N, typename Tag>
        struct value_at_key_impl
            : mpl::if_<
                  mpl::or_<
                      typename extension::has_key_impl<Tag>::template apply<Sequence, N>
                    , traits::is_unbounded<Sequence>
                  >
                , typename extension::value_at_key_impl<Tag>::template apply<Sequence, N>
                , mpl::empty_base
              >::type
        {};
    }

    namespace result_of
    {
        template <typename Sequence, typename N>
        struct value_at_key
            : detail::value_at_key_impl<Sequence, N, typename detail::tag_of<Sequence>::type>
        {};
    }
}}

#endif


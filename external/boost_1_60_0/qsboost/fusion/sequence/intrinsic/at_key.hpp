/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_AT_KEY_20060304_1755)
#define QSBOOST_FUSION_AT_KEY_20060304_1755

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/type_traits/is_const.hpp>
#include <qsboost/fusion/sequence/intrinsic_fwd.hpp>
#include <qsboost/fusion/sequence/intrinsic/has_key.hpp>
#include <qsboost/fusion/algorithm/query/find.hpp>
#include <qsboost/fusion/iterator/deref_data.hpp>
#include <qsboost/fusion/support/tag_of.hpp>
#include <qsboost/fusion/support/category_of.hpp>
#include <qsboost/fusion/support/detail/access.hpp>
#include <qsboost/mpl/empty_base.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/or.hpp>

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
        struct at_key_impl
        {
            template <typename Seq, typename Key>
            struct apply
            {
                typedef typename
                    result_of::deref_data<
                        typename result_of::find<Seq, Key>::type
                    >::type
                type;

                QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
                static type
                call(Seq& seq)
                {
                    return fusion::deref_data(fusion::find<Key>(seq));
                }
            };
        };

        template <>
        struct at_key_impl<sequence_facade_tag>
        {
            template <typename Sequence, typename Key>
            struct apply : Sequence::template at_key_impl<Sequence, Key> {};
        };

        template <>
        struct at_key_impl<qsboost_array_tag>;

        template <>
        struct at_key_impl<mpl_sequence_tag>;

        template <>
        struct at_key_impl<std_pair_tag>;
    }

    namespace detail
    {
        template <typename Sequence, typename Key, typename Tag>
        struct at_key_impl
            : mpl::if_<
                  mpl::or_<
                      typename extension::has_key_impl<Tag>::template apply<Sequence, Key>
                    , traits::is_unbounded<Sequence>
                  >
                , typename extension::at_key_impl<Tag>::template apply<Sequence, Key>
                , mpl::empty_base
              >::type
        {};
    }

    namespace result_of
    {
        template <typename Sequence, typename Key>
        struct at_key
            : detail::at_key_impl<Sequence, Key, typename detail::tag_of<Sequence>::type>
        {};
    }

    template <typename Key, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename 
        lazy_disable_if<
            is_const<Sequence>
          , result_of::at_key<Sequence, Key>
        >::type
    at_key(Sequence& seq)
    {
        return result_of::at_key<Sequence, Key>::call(seq);
    }

    template <typename Key, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::at_key<Sequence const, Key>::type
    at_key(Sequence const& seq)
    {
        return result_of::at_key<Sequence const, Key>::call(seq);
    }
}}

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_TAG_OF_09232005_0845)
#define FUSION_TAG_OF_09232005_0845

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#include <qsboost/fusion/support/tag_of_fwd.hpp>
#include <qsboost/fusion/support/detail/is_mpl_sequence.hpp>
#include <qsboost/mpl/has_xxx.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/config/no_tr1/utility.hpp>

namespace qsboost
{
    template <typename T, std::size_t N>
    class array; // forward

    namespace tuples
    {
        struct null_type;

        template <
            class T0, class T1, class T2, class T3, class T4,
            class T5, class T6, class T7, class T8, class T9
        >
        class tuple;

        template <class Head, class Tail>
        struct cons;
    }
}

namespace qsboost { namespace fusion
{
    struct non_fusion_tag;
    struct mpl_sequence_tag;

    namespace detail
    {
        QSBOOST_MPL_HAS_XXX_TRAIT_DEF(fusion_tag)

        template <typename Sequence, typename Active>
        struct tag_of_impl
          : mpl::if_<fusion::detail::is_mpl_sequence<Sequence>,
              mpl::identity<mpl_sequence_tag>,
              mpl::identity<non_fusion_tag> >::type
        {};

        template <typename Sequence>
        struct tag_of_impl<
            Sequence
          , typename qsboost::enable_if<detail::has_fusion_tag<Sequence> >::type>
        {
            typedef typename Sequence::fusion_tag type;
        };
    }

    namespace traits
    {
        template <typename Sequence, typename Active>
        struct tag_of
            : qsboost::fusion::detail::tag_of_impl<Sequence, Active>
        {};
    }

    namespace detail
    {
        template<typename T>
        struct tag_of
            : traits::tag_of<typename remove_const<T>::type>
        {};
    }
}}
#endif

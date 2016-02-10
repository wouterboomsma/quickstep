/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_SEQUENCE_FILTER_VIEW_HPP)
#define FUSION_SEQUENCE_FILTER_VIEW_HPP

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/support/detail/access.hpp>
#include <qsboost/fusion/support/sequence_base.hpp>
#include <qsboost/fusion/support/is_view.hpp>
#include <qsboost/fusion/view/filter_view/filter_view_iterator.hpp>
#include <qsboost/fusion/view/filter_view/detail/begin_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/end_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/size_impl.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/sequence/intrinsic/end.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/inherit.hpp>
#include <qsboost/mpl/identity.hpp>

namespace qsboost { namespace fusion
{
    struct filter_view_tag;
    struct forward_traversal_tag;
    struct fusion_sequence_tag;

    template <typename Sequence, typename Pred>
    struct filter_view : sequence_base<filter_view<Sequence, Pred> >
    {
        typedef filter_view_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef typename
            mpl::eval_if<
                traits::is_associative<Sequence>
              , mpl::inherit2<forward_traversal_tag,associative_tag>
              , mpl::identity<forward_traversal_tag>
            >::type
        category;
        typedef mpl::true_ is_view;

        typedef typename result_of::begin<Sequence>::type first_type;
        typedef typename result_of::end<Sequence>::type last_type;
        typedef Pred pred_type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        filter_view(Sequence& in_seq)
            : seq(in_seq)
        {}

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        first_type first() const { return fusion::begin(seq); }
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        last_type last() const { return fusion::end(seq); }
        typename mpl::if_<traits::is_view<Sequence>, Sequence, Sequence&>::type seq;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        filter_view& operator= (filter_view const&);
    };
}}

#endif



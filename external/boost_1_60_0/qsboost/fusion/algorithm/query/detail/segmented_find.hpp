/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SEGMENTED_FIND_HPP_INCLUDED)
#define QSBOOST_FUSION_SEGMENTED_FIND_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/fusion/algorithm/query/find_fwd.hpp>
#include <qsboost/fusion/iterator/equal_to.hpp>
#include <qsboost/fusion/sequence/intrinsic/end.hpp>
#include <qsboost/fusion/support/segmented_fold_until.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    template <typename T>
    struct segmented_find_fun
    {
        template <typename Sequence, typename State, typename Context>
        struct apply
        {
            typedef
                typename result_of::find<Sequence, T>::type
            iterator_type;

            typedef
                typename result_of::equal_to<
                    iterator_type
                  , typename result_of::end<Sequence>::type
                >::type
            continue_type;

            typedef
                typename mpl::eval_if<
                    continue_type
                  , mpl::identity<State>
                  , result_of::make_segmented_iterator<
                        iterator_type
                      , Context
                    >
                >::type
            type;

            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type call(Sequence& seq, State const&state, Context const& context, segmented_find_fun)
            {
                return call_impl(seq, state, context, continue_type());
            }

            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type call_impl(Sequence&, State const&state, Context const&, mpl::true_)
            {
                return state;
            }

            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type call_impl(Sequence& seq, State const&, Context const& context, mpl::false_)
            {
                return fusion::make_segmented_iterator(fusion::find<T>(seq), context);
            }
        };
    };

    template <typename Sequence, typename T>
    struct result_of_segmented_find
    {
        struct filter
        {
            typedef
                typename result_of::segmented_fold_until<
                    Sequence
                  , typename result_of::end<Sequence>::type
                  , segmented_find_fun<T>
                >::type
            type;

            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type call(Sequence& seq)
            {
                return fusion::segmented_fold_until(
                    seq
                  , fusion::end(seq)
                  , detail::segmented_find_fun<T>());
            }
        };

        typedef typename filter::type type;
    };
}}}

#endif

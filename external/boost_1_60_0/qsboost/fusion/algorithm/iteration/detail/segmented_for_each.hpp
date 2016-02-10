/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SEGMENTED_FOR_EACH_HPP_INCLUDED)
#define QSBOOST_FUSION_SEGMENTED_FOR_EACH_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/fusion/support/void.hpp>
#include <qsboost/fusion/algorithm/iteration/for_each_fwd.hpp>
#include <qsboost/fusion/support/segmented_fold_until.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    template <typename Fun>
    struct segmented_for_each_fun
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit segmented_for_each_fun(Fun const& f)
          : fun(f)
        {}

        Fun const& fun;

        template <typename Sequence, typename State, typename Context>
        struct apply
        {
            typedef void_ type;
            typedef mpl::true_ continue_type;

            QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            static type call(Sequence& seq, State const&, Context const&, segmented_for_each_fun const& fun)
            {
                fusion::for_each(seq, fun.fun);
                return void_();
            }
        };
    };

    template <typename Sequence, typename F>
    QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline void
    for_each(Sequence& seq, F const& f, mpl::true_) // segmented implementation
    {
        fusion::segmented_fold_until(seq, void_(), segmented_for_each_fun<F>(f));
    }
}}}

#endif

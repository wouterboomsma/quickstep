/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DISTANCE_09172005_0730)
#define FUSION_DISTANCE_09172005_0730

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/next.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/fusion/iterator/next.hpp>
#include <qsboost/fusion/iterator/equal_to.hpp>

namespace qsboost { namespace fusion { namespace distance_detail
{
    // Default distance implementation, linear
    // search for the Last iterator.

    template <typename First, typename Last>
    struct linear_distance;

    template <typename First, typename Last>
    struct next_distance
    {
        typedef typename 
            mpl::next<
                typename linear_distance<
                    typename result_of::next<First>::type
                  , Last
                >::type
            >::type 
        type;
    };

    template <typename First, typename Last>
    struct linear_distance
        : mpl::eval_if<
            result_of::equal_to<First, Last>
          , mpl::identity<mpl::int_<0> >
          , next_distance<First, Last>
        >::type
    {
        typedef typename
            mpl::eval_if<
                result_of::equal_to<First, Last>
              , mpl::identity<mpl::int_<0> >
              , next_distance<First, Last>
            >::type
        type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static type
        call(First const&, Last const&)
        {
            return type();
        }
    };

}}}

#endif

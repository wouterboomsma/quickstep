/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SEGMENTED_SIZE_08112006_1141)
#define QSBOOST_FUSION_SEGMENTED_SIZE_08112006_1141

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/mpl/fold.hpp>
#include <qsboost/mpl/plus.hpp>
#include <qsboost/mpl/size_t.hpp>
#include <qsboost/mpl/placeholders.hpp>
#include <qsboost/fusion/sequence/intrinsic_fwd.hpp>
#include <qsboost/fusion/mpl/begin.hpp>
#include <qsboost/fusion/mpl/end.hpp>
#include <qsboost/fusion/support/is_segmented.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    // calculates the size of any segmented data structure.
    template<typename Sequence>
    struct segmented_size;

    ///////////////////////////////////////////////////////////////////////////
    template<typename Sequence, bool IsSegmented = traits::is_segmented<Sequence>::value>
    struct segmented_size_impl
      : mpl::fold<
            typename remove_reference<
                typename add_const<
                    typename result_of::segments<Sequence>::type
                >::type
            >::type
          , mpl::size_t<0>
          , mpl::plus<mpl::_1, segmented_size<remove_reference<mpl::_2> > >
        >::type
    {};

    template<typename Sequence>
    struct segmented_size_impl<Sequence, false>
      : result_of::size<Sequence>::type
    {};

    template<typename Sequence>
    struct segmented_size
      : segmented_size_impl<Sequence>
    {};

}}}

#endif

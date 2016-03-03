/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_EQUAL_TO_05052005_1142)
#define FUSION_EQUAL_TO_05052005_1142

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/fusion/iterator/deref.hpp>
#include <qsboost/fusion/iterator/next.hpp>
#include <qsboost/fusion/iterator/equal_to.hpp>
#include <qsboost/fusion/support/as_const.hpp>

namespace qsboost { namespace fusion { namespace detail
{
    template <typename Seq1, typename Seq2, bool same_size>
    struct sequence_equal_to
    {
        typedef typename result_of::end<Seq1>::type end1_type;
        typedef typename result_of::end<Seq2>::type end2_type;

        template <typename I1, typename I2>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static bool
        call(I1 const&, I2 const&, mpl::true_)
        {
            return true;
        }

        template <typename I1, typename I2>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static bool
        call(I1 const& a, I2 const& b, mpl::false_)
        {
            return extension::as_const(*a) == extension::as_const(*b)
                && call(fusion::next(a), fusion::next(b));
        }

        template <typename I1, typename I2>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static bool
        call(I1 const& a, I2 const& b)
        {
            typename result_of::equal_to<I1, end1_type>::type eq;
            return call(a, b, eq);
        }
    };

    template <typename Seq1, typename Seq2>
    struct sequence_equal_to<Seq1, Seq2, false>
    {
        template <typename I1, typename I2>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        static bool
        call(I1 const& /*a*/, I2 const& /*b*/)
        {
            return false;
        }
    };
}}}

#endif
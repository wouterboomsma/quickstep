/*=============================================================================
    Copyright (c) 1999-2003 Jaakko Jarvi
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_EQUAL_TO_05052005_0431)
#define FUSION_EQUAL_TO_05052005_0431

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/sequence/intrinsic/end.hpp>
#include <qsboost/fusion/sequence/intrinsic/size.hpp>
#include <qsboost/fusion/sequence/comparison/detail/equal_to.hpp>
#include <qsboost/fusion/sequence/comparison/enable_comparison.hpp>
#include <qsboost/config.hpp>

#if defined (QSBOOST_MSVC)
#  pragma warning(push)
#  pragma warning (disable: 4100) // unreferenced formal parameter
#endif

namespace qsboost { namespace fusion
{
    template <typename Seq1, typename Seq2>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline bool
    equal_to(Seq1 const& a, Seq2 const& b)
    {
        return result_of::size<Seq1>::value == result_of::size<Seq2>::value
            && detail::sequence_equal_to<
            Seq1 const, Seq2 const
            , result_of::size<Seq1>::value == result_of::size<Seq2>::value>::
            call(fusion::begin(a), fusion::begin(b));
    }

    namespace operators
    {
        template <typename Seq1, typename Seq2>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        inline typename
            qsboost::enable_if<
                traits::enable_equality<Seq1, Seq2>
              , bool
            >::type
        operator==(Seq1 const& a, Seq2 const& b)
        {
            return fusion::equal_to(a, b);
        }
    }
    using operators::operator==;
}}

#if defined (QSBOOST_MSVC)
#  pragma warning(pop)
#endif

#endif
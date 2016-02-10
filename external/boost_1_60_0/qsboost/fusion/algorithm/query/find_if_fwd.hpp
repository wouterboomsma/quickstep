/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_FIND_IF_FWD_HPP_INCLUDED)
#define QSBOOST_FUSION_FIND_IF_FWD_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/type_traits/is_const.hpp>

// Forward declaration of find_if algorithm
namespace qsboost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename Pred>
        struct find_if;
    }

    template <typename Pred, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename
        lazy_disable_if<
            is_const<Sequence>
          , result_of::find_if<Sequence, Pred>
        >::type
    find_if(Sequence& seq);

    template <typename Pred, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::find_if<Sequence const, Pred>::type const
    find_if(Sequence const& seq);
}}

#endif

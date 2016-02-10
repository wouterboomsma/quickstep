/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_FIND_FWD_HPP_INCLUDED)
#define QSBOOST_FUSION_FIND_FWD_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/utility/enable_if.hpp>
#include <qsboost/type_traits/is_const.hpp>

namespace qsboost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename T>
        struct find;
    }

    template <typename T, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename
        lazy_disable_if<
            is_const<Sequence>
          , result_of::find<Sequence, T>
        >::type const
    find(Sequence& seq);

    template <typename T, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::find<Sequence const, T>::type const
    find(Sequence const& seq);
}}

#endif

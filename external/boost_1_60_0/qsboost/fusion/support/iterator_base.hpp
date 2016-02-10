/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ITERATOR_BASE_05042005_1008)
#define FUSION_ITERATOR_BASE_05042005_1008

#include <qsboost/config.hpp>
#include <qsboost/fusion/support/config.hpp>

namespace qsboost { namespace fusion
{
    struct iterator_root {};

    template <typename Iterator>
    struct iterator_base : iterator_root
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        Iterator const&
        cast() const QSBOOST_NOEXCEPT
        {
            return static_cast<Iterator const&>(*this);
        }

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        Iterator&
        cast() QSBOOST_NOEXCEPT
        {
            return static_cast<Iterator&>(*this);
        }
    };
}}

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_ERASE_KEY_10022005_1851)
#define FUSION_ERASE_KEY_10022005_1851

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/algorithm/query/find.hpp>
#include <qsboost/fusion/algorithm/transformation/erase.hpp>
#include <qsboost/mpl/not.hpp>
#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace fusion
{
    namespace result_of
    {
        template <typename Sequence, typename Key>
        struct erase_key
          : erase<Sequence, typename find<Sequence, Key>::type>
        {};
    }

    template <typename Key, typename Sequence>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::erase_key<Sequence const, Key>::type
    erase_key(Sequence const& seq)
    {
        return erase(seq, find<Key>(seq));
    }
}}

#endif


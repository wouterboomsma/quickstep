/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_FRONT_10022005_1618)
#define FUSION_FRONT_10022005_1618

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/front.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/iterator/value_of.hpp>

namespace qsboost { namespace mpl
{
    template <typename Tag>
    struct front_impl;

    template <>
    struct front_impl<fusion::fusion_sequence_tag>
    {
        template <typename Sequence>
        struct apply : 
            fusion::result_of::value_of<typename fusion::result_of::begin<Sequence>::type> {};
    };
}}

#endif

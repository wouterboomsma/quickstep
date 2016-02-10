/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DISTANCE_09172005_0721)
#define FUSION_DISTANCE_09172005_0721

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/iterator/detail/distance.hpp>
#include <qsboost/fusion/support/category_of.hpp>

#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/type_traits/is_same.hpp>

#include <qsboost/fusion/support/tag_of.hpp>

namespace qsboost { namespace fusion
{
    struct random_access_traversal_tag;

    // Special tags:
    struct iterator_facade_tag; // iterator facade tag
    struct qsboost_array_iterator_tag; // boost::array iterator tag
    struct mpl_iterator_tag; // mpl sequence iterator tag
    struct std_pair_iterator_tag; // std::pair iterator tag

    namespace extension
    {
        template <typename Tag>
        struct distance_impl
        {
            // default implementation
            template <typename First, typename Last>
            struct apply : distance_detail::linear_distance<First, Last> 
            {};
        };

        template <>
        struct distance_impl<iterator_facade_tag>
        {
            template <typename First, typename Last>
            struct apply : First::template distance<First, Last> {};
        };

        template <>
        struct distance_impl<qsboost_array_iterator_tag>;

        template <>
        struct distance_impl<mpl_iterator_tag>;

        template <>
        struct distance_impl<std_pair_iterator_tag>;
    }

    namespace result_of
    {
        template <typename First, typename Last>
        struct distance
          : extension::distance_impl<typename detail::tag_of<First>::type>::
                template apply<First, Last>
        {
            typedef typename extension::distance_impl<typename detail::tag_of<First>::type>:: 
            template apply<First, Last>::type distance_application;
            QSBOOST_STATIC_CONSTANT(int, value = distance_application::value);
        };
    }
        
    template <typename First, typename Last>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::distance<First, Last>::type
    distance(First const& a, Last const& b)
    {
        return result_of::distance<First, Last>::call(a,b);
    }
}}

#endif

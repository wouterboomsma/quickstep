/*=============================================================================
    Copyright (c) 2011 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(QSBOOST_FUSION_SINGLE_VIEW_ITERATOR_JUL_07_2011_1348PM)
#define QSBOOST_FUSION_SINGLE_VIEW_ITERATOR_JUL_07_2011_1348PM

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/mpl/equal_to.hpp>
#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/type_traits/add_const.hpp>

namespace qsboost { namespace fusion 
{
    struct single_view_iterator_tag;

    namespace extension
    {
        template<typename Tag>
        struct equal_to_impl;

        template<>
        struct equal_to_impl<single_view_iterator_tag>
        {
            template<typename It1, typename It2>
            struct apply
              : mpl::equal_to<typename It1::position, typename It2::position>
            {
                QSBOOST_MPL_ASSERT((is_same<typename add_const<typename It1::single_view_type>::type, 
                    typename add_const<typename It2::single_view_type>::type>));
            };
        };
    }
}}

#endif

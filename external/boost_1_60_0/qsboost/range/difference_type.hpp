// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_DIFFERENCE_TYPE_HPP
#define QSBOOST_RANGE_DIFFERENCE_TYPE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/mpl/and.hpp>
#include <qsboost/range/config.hpp>
#include <qsboost/range/iterator.hpp>
#include <qsboost/range/has_range_iterator.hpp>
#include <qsboost/iterator/iterator_traits.hpp>
#include <qsboost/type_traits/remove_reference.hpp>

namespace qsboost
{
    namespace range_detail
    {
        template< class T, bool B = has_type<range_iterator<T> >::value >
        struct range_difference
        { };

        template< class T >
        struct range_difference<T, true>
          : iterator_difference<
                QSBOOST_DEDUCED_TYPENAME range_iterator<T>::type
            >
        { };
    }

    template< class T >
    struct range_difference
      : range_detail::range_difference<QSBOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    { };
}

#endif

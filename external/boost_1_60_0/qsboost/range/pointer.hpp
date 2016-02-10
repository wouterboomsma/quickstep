// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_POINTER_TYPE_HPP
#define QSBOOST_RANGE_POINTER_TYPE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/range/config.hpp>
#include <qsboost/range/iterator.hpp>
#include <qsboost/iterator/iterator_traits.hpp>

namespace qsboost
{
    template< class T >
    struct range_pointer
            : iterator_pointer< QSBOOST_DEDUCED_TYPENAME range_iterator<T>::type >
    { };
}

#endif

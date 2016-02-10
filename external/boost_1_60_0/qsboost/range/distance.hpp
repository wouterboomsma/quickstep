// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2006. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_DISTANCE_HPP
#define QSBOOST_RANGE_DISTANCE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/range/begin.hpp>
#include <qsboost/range/end.hpp>
#include <qsboost/range/difference_type.hpp>

namespace qsboost 
{

    template< class T >
    inline QSBOOST_DEDUCED_TYPENAME range_difference<T>::type 
    distance( const T& r )
    {
        return std::distance( qsboost::begin( r ), qsboost::end( r ) );
    }

} // namespace 'boost'

#endif

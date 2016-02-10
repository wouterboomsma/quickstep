// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_REND_HPP
#define QSBOOST_RANGE_REND_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/range/begin.hpp>
#include <qsboost/range/reverse_iterator.hpp>

namespace qsboost
{

#ifdef QSBOOST_NO_FUNCTION_TEMPLATE_ORDERING

template< class C >
inline QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rend( C& c )
{
    return QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type( qsboost::begin( c ) );
}

#else

template< class C >
inline QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
rend( C& c )
{
    typedef QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<C>::type
               iter_type;
    return iter_type( qsboost::begin( c ) );
}

template< class C >
inline QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
rend( const C& c )
{
    typedef QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<const C>::type
        iter_type;
    return iter_type( qsboost::begin( c ) );
}

#endif

template< class T >
inline QSBOOST_DEDUCED_TYPENAME range_reverse_iterator<const T>::type
const_rend( const T& r )
{
    return qsboost::rend( r );
}

} // namespace 'boost'

#endif


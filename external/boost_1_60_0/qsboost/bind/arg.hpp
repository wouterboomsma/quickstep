#ifndef QSBOOST_BIND_ARG_HPP_INCLUDED
#define QSBOOST_BIND_ARG_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/arg.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//  See http://www.boost.org/libs/bind/bind.html for documentation.
//

#include <qsboost/config.hpp>
#include <qsboost/is_placeholder.hpp>
#include <qsboost/static_assert.hpp>

namespace qsboost
{

template< int I > struct arg
{
    QSBOOST_CONSTEXPR arg()
    {
    }

    template< class T > QSBOOST_CONSTEXPR arg( T const & /* t */ )
    {
        QSBOOST_STATIC_ASSERT( I == is_placeholder<T>::value );
    }
};

template< int I > QSBOOST_CONSTEXPR bool operator==( arg<I> const &, arg<I> const & )
{
    return true;
}

#if !defined( QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION )

template< int I > struct is_placeholder< arg<I> >
{
    enum _vt { value = I };
};

template< int I > struct is_placeholder< arg<I> (*) () >
{
    enum _vt { value = I };
};

#endif

} // namespace boost

#endif // #ifndef BOOST_BIND_ARG_HPP_INCLUDED

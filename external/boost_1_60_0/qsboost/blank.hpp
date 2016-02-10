//-----------------------------------------------------------------------------
// boost blank.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_BLANK_HPP
#define QSBOOST_BLANK_HPP

#include "qsboost/blank_fwd.hpp"

#if !defined(QSBOOST_NO_IOSTREAM)
#include <iosfwd> // for std::basic_ostream forward declare
#include "qsboost/detail/templated_streams.hpp"
#endif // BOOST_NO_IOSTREAM

#include "qsboost/mpl/bool.hpp"
#include "qsboost/type_traits/is_empty.hpp"
#include "qsboost/type_traits/is_pod.hpp"
#include "qsboost/type_traits/is_stateless.hpp"

namespace qsboost {

struct blank
{
};

// type traits specializations
//

template <>
struct is_pod< blank >
    : mpl::true_
{
};

template <>
struct is_empty< blank >
    : mpl::true_
{
};

template <>
struct is_stateless< blank >
    : mpl::true_
{
};

// relational operators
//

inline bool operator==(const blank&, const blank&)
{
    return true;
}

inline bool operator<=(const blank&, const blank&)
{
    return true;
}

inline bool operator>=(const blank&, const blank&)
{
    return true;
}

inline bool operator!=(const blank&, const blank&)
{
    return false;
}

inline bool operator<(const blank&, const blank&)
{
    return false;
}

inline bool operator>(const blank&, const blank&)
{
    return false;
}

// streaming support
//
#if !defined(QSBOOST_NO_IOSTREAM)

QSBOOST_TEMPLATED_STREAM_TEMPLATE(E,T)
inline QSBOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      QSBOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const blank&
    )
{
    // (output nothing)
    return out;
}

#endif // BOOST_NO_IOSTREAM

} // namespace boost

#endif // BOOST_BLANK_HPP

#ifndef QSBOOST_BIND_PLACEHOLDERS_HPP_INCLUDED
#define QSBOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  bind/placeholders.hpp - _N definitions
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright 2015 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  See http://www.boost.org/libs/bind/bind.html for documentation.
//

#include <qsboost/bind/arg.hpp>
#include <qsboost/config.hpp>

namespace qsboost
{

namespace placeholders
{

#if defined(__BORLANDC__) || defined(__GNUC__) && (__GNUC__ < 4)

inline qsboost::arg<1> _1() { return qsboost::arg<1>(); }
inline qsboost::arg<2> _2() { return qsboost::arg<2>(); }
inline qsboost::arg<3> _3() { return qsboost::arg<3>(); }
inline qsboost::arg<4> _4() { return qsboost::arg<4>(); }
inline qsboost::arg<5> _5() { return qsboost::arg<5>(); }
inline qsboost::arg<6> _6() { return qsboost::arg<6>(); }
inline qsboost::arg<7> _7() { return qsboost::arg<7>(); }
inline qsboost::arg<8> _8() { return qsboost::arg<8>(); }
inline qsboost::arg<9> _9() { return qsboost::arg<9>(); }

#else

QSBOOST_STATIC_CONSTEXPR qsboost::arg<1> _1;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<2> _2;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<3> _3;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<4> _4;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<5> _5;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<6> _6;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<7> _7;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<8> _8;
QSBOOST_STATIC_CONSTEXPR qsboost::arg<9> _9;

#endif

} // namespace placeholders

} // namespace boost

#endif // #ifndef BOOST_BIND_PLACEHOLDERS_HPP_INCLUDED

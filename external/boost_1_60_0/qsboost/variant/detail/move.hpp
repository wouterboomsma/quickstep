//-----------------------------------------------------------------------------
// boost variant/detail/move.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
//  Copyright (c) 2002-2003 Eric Friedman
//  Copyright (c) 2002 by Andrei Alexandrescu
//  Copyright (c) 2013-2014 Antony Polukhin
//
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//  This file derivative of MoJO. Much thanks to Andrei for his initial work.
//  See <http://www.cuj.com/experts/2102/alexandr.htm> for information on MOJO.
//  Re-issued here under the Boost Software License, with permission of the original
//  author (Andrei Alexandrescu).


#ifndef QSBOOST_VARIANT_DETAIL_MOVE_HPP
#define QSBOOST_VARIANT_DETAIL_MOVE_HPP

#include <iterator> // for iterator_traits
#include <new> // for placement new

#include "qsboost/config.hpp"
#include "qsboost/detail/workaround.hpp"
#include "qsboost/move/move.hpp"
#include "qsboost/move/adl_move_swap.hpp"

namespace qsboost { namespace detail { namespace variant {

using qsboost::move;

//////////////////////////////////////////////////////////////////////////
// function template move_swap
//
// Swaps using Koenig lookup but falls back to move-swap for primitive
// types and on non-conforming compilers.
//

template <typename T>
inline void move_swap(T& lhs, T& rhs)
{
    ::qsboost::adl_move_swap(lhs, rhs);
}

}}} // namespace boost::detail::variant

#endif // BOOST_VARIANT_DETAIL_MOVE_HPP





// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  Based on Peter Dimov's proposal
//  http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2005/n1756.pdf
//  issue 6.18. 

#if !defined(QSBOOST_FUNCTIONAL_HASH_FWD_HPP)
#define QSBOOST_FUNCTIONAL_HASH_FWD_HPP

#include <qsboost/config.hpp>
#if defined(QSBOOST_HAS_PRAGMA_ONCE)
#pragma once
#endif

#include <cstddef>
#include <qsboost/detail/workaround.hpp>

namespace qsboost
{
    template <class T> struct hash;

    template <class T> void hash_combine(std::size_t& seed, T const& v);

    template <class It> std::size_t hash_range(It, It);
    template <class It> void hash_range(std::size_t&, It, It);

#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x551))
    template <class T> inline std::size_t hash_range(T*, T*);
    template <class T> inline void hash_range(std::size_t&, T*, T*);
#endif
}

#endif

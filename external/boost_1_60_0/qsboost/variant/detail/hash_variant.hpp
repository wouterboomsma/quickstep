//-----------------------------------------------------------------------------
// boost variant/detail/hash_variant.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2011
// Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)


#ifndef QSBOOST_HASH_VARIANT_FUNCTION_HPP
#define QSBOOST_HASH_VARIANT_FUNCTION_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/variant/variant_fwd.hpp>
#include <qsboost/variant/static_visitor.hpp>
#include <qsboost/variant/apply_visitor.hpp>
#include <qsboost/functional/hash_fwd.hpp>

namespace qsboost {

    namespace detail { namespace variant {
        struct variant_hasher: public qsboost::static_visitor<std::size_t> {
            template <class T>
            std::size_t operator()(T const& val) const {
                qsboost::hash<T> hasher;
                return hasher(val);
            }
        };
    }}

    template < QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
    std::size_t hash_value(variant< QSBOOST_VARIANT_ENUM_PARAMS(T) > const& val) {
        std::size_t seed = qsboost::apply_visitor(detail::variant::variant_hasher(), val);
        hash_combine(seed, val.which());
        return seed;
    }
}

#endif

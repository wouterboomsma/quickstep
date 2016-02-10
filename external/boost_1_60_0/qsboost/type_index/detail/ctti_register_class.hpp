//
// Copyright (c) Antony Polukhin, 2013-2014.
//
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef QSBOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP
#define QSBOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP

/// \file ctti_register_class.hpp
/// \brief Contains BOOST_TYPE_INDEX_REGISTER_CLASS macro implementation that uses boost::typeindex::ctti_type_index.
/// Not intended for inclusion from user's code.

#include <qsboost/type_index/ctti_type_index.hpp>

#ifdef QSBOOST_HAS_PRAGMA_ONCE
# pragma once
#endif

namespace qsboost { namespace typeindex { namespace detail {

template <class T>
inline const ctti_data& ctti_construct_typeid_ref(const T*) QSBOOST_NOEXCEPT {
    return ctti_construct<T>();
}

}}} // namespace boost::typeindex::detail

/// @cond
#define QSBOOST_TYPE_INDEX_REGISTER_CLASS                                                                             \
    virtual const qsboost::typeindex::detail::ctti_data& qsboost_type_index_type_id_runtime_() const QSBOOST_NOEXCEPT {   \
        return qsboost::typeindex::detail::ctti_construct_typeid_ref(this);                                           \
    }                                                                                                               \
/**/
/// @endcond

#endif // BOOST_TYPE_INDEX_CTTI_REGISTER_CLASS_HPP


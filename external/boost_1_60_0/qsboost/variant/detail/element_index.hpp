//-----------------------------------------------------------------------------
// boost variant/detail/element_index.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2014-2015 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP
#define QSBOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP

#include "qsboost/config.hpp"
#include "qsboost/variant/recursive_wrapper_fwd.hpp"
#include "qsboost/variant/variant_fwd.hpp"

#include "qsboost/type_traits/remove_cv.hpp"
#include "qsboost/type_traits/remove_reference.hpp"
#include "qsboost/mpl/find_if.hpp"

namespace qsboost { namespace detail { namespace variant {

template <class VariantElement, class T>
struct variant_element_functor :
    qsboost::mpl::or_<
        qsboost::is_same<VariantElement, T>,
        qsboost::is_same<VariantElement, qsboost::recursive_wrapper<T> >,
        qsboost::is_same<VariantElement, T& >
    >
{};

template <class Types, class T>
struct element_iterator_impl :
    qsboost::mpl::find_if<
        Types,
        qsboost::mpl::or_<
            variant_element_functor<qsboost::mpl::_1, T>,
            variant_element_functor<qsboost::mpl::_1, typename qsboost::remove_cv<T>::type >
        >
    >
{};

template <class Variant, class T>
struct element_iterator :
    element_iterator_impl< typename Variant::types, typename qsboost::remove_reference<T>::type >
{};

template <class Variant, class T>
struct holds_element :
    qsboost::mpl::not_<
        qsboost::is_same<
            typename qsboost::mpl::end<typename Variant::types>::type,
            typename element_iterator<Variant, T>::type
        >
    >
{};


}}} // namespace boost::detail::variant

#endif // BOOST_VARIANT_DETAIL_ELEMENT_INDEX_HPP

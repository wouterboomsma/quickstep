// Copyright David Abrahams 2003.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOSTITERATOR_TRAITS_DWA200347_HPP
# define QSBOOSTITERATOR_TRAITS_DWA200347_HPP

# include <qsboost/detail/iterator.hpp>
# include <qsboost/detail/workaround.hpp>

namespace qsboost {
namespace iterators {

// Macro for supporting old compilers, no longer needed but kept
// for backwards compatibility (it was documented).
#define QSBOOST_ITERATOR_CATEGORY iterator_category


template <class Iterator>
struct iterator_value
{
    typedef typename qsboost::detail::iterator_traits<Iterator>::value_type type;
};

template <class Iterator>
struct iterator_reference
{
    typedef typename qsboost::detail::iterator_traits<Iterator>::reference type;
};


template <class Iterator>
struct iterator_pointer
{
    typedef typename qsboost::detail::iterator_traits<Iterator>::pointer type;
};

template <class Iterator>
struct iterator_difference
{
    typedef typename qsboost::detail::iterator_traits<Iterator>::difference_type type;
};

template <class Iterator>
struct iterator_category
{
    typedef typename qsboost::detail::iterator_traits<Iterator>::iterator_category type;
};

} // namespace iterators

using iterators::iterator_value;
using iterators::iterator_reference;
using iterators::iterator_pointer;
using iterators::iterator_difference;
using iterators::iterator_category;

} // namespace boost

#endif // QSBOOSTITERATOR_TRAITS_DWA200347_HPP

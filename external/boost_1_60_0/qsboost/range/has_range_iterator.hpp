// Boost.Range library
//
//  Copyright Neil Groves 2010. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
// Acknowledgments:
// Ticket #8341: Arno Schoedl - improved handling of has_range_iterator upon
// use-cases where T was const.
#ifndef QSBOOST_RANGE_HAS_ITERATOR_HPP_INCLUDED
#define QSBOOST_RANGE_HAS_ITERATOR_HPP_INCLUDED

#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/has_xxx.hpp>
#include <qsboost/range/iterator.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/utility/enable_if.hpp>

namespace qsboost
{
    namespace range_detail
    {
        QSBOOST_MPL_HAS_XXX_TRAIT_DEF(type)

        template<class T, class Enabler = void>
        struct has_range_iterator_impl
            : qsboost::mpl::false_
        {
        };

        template<class T>
        struct has_range_iterator_impl<
            T,
            QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
                QSBOOST_DEDUCED_TYPENAME mpl::eval_if<is_const<T>,
                    has_type<range_const_iterator<
                                QSBOOST_DEDUCED_TYPENAME remove_const<T>::type> >,
                    has_type<range_mutable_iterator<T> >
                >::type
            >::type
        >
            : qsboost::mpl::true_
        {
        };

        template<class T, class Enabler = void>
        struct has_range_const_iterator_impl
            : qsboost::mpl::false_
        {
        };

        template<class T>
        struct has_range_const_iterator_impl<
            T,
            QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
                has_type<range_const_iterator<T> >
            >::type
        >
            : qsboost::mpl::true_
        {
        };

    } // namespace range_detail

    template<class T>
    struct has_range_iterator
        : range_detail::has_range_iterator_impl<
            QSBOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    {};

    template<class T>
    struct has_range_const_iterator
        : range_detail::has_range_const_iterator_impl<
            QSBOOST_DEDUCED_TYPENAME remove_reference<T>::type>
    {};
} // namespace boost

#endif // include guard


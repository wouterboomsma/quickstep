/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_REVERSE_VIEW_ITERATOR_07202005_0835)
#define FUSION_REVERSE_VIEW_ITERATOR_07202005_0835

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/support/iterator_base.hpp>
#include <qsboost/fusion/support/category_of.hpp>
#include <qsboost/fusion/iterator/mpl/convert_iterator.hpp>
#include <qsboost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <qsboost/fusion/view/reverse_view/detail/deref_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/next_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/prior_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/advance_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/distance_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/value_of_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/deref_data_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/value_of_data_impl.hpp>
#include <qsboost/fusion/view/reverse_view/detail/key_of_impl.hpp>
#include <qsboost/type_traits/is_base_of.hpp>
#include <qsboost/static_assert.hpp>

namespace qsboost { namespace fusion
{
    struct reverse_view_iterator_tag;

    template <typename First>
    struct reverse_view_iterator
        : iterator_base<reverse_view_iterator<First> >
    {
        typedef convert_iterator<First> converter;
        typedef typename converter::type first_type;
        typedef reverse_view_iterator_tag fusion_tag;
        typedef typename traits::category_of<first_type>::type category;

        QSBOOST_STATIC_ASSERT((
            is_base_of<
                bidirectional_traversal_tag
              , category>::value));

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        reverse_view_iterator(First const& in_first)
            : first(converter::call(in_first)) {}

        first_type first;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        reverse_view_iterator& operator= (reverse_view_iterator const&);
    };
}}

#ifdef QSBOOST_FUSION_WORKAROUND_FOR_LWG_2408
namespace std
{
    template <typename First>
    struct iterator_traits< ::qsboost::fusion::reverse_view_iterator<First> >
    { };
}
#endif

#endif


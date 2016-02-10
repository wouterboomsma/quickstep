/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_FILTER_VIEW_ITERATOR_05062005_0849)
#define FUSION_FILTER_VIEW_ITERATOR_05062005_0849

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/iterator/mpl/convert_iterator.hpp>
#include <qsboost/fusion/adapted/mpl/mpl_iterator.hpp>
#include <qsboost/fusion/iterator/value_of.hpp>
#include <qsboost/fusion/support/iterator_base.hpp>
#include <qsboost/fusion/algorithm/query/detail/find_if.hpp>
#include <qsboost/mpl/lambda.hpp>
#include <qsboost/mpl/quote.hpp>
#include <qsboost/mpl/bind.hpp>
#include <qsboost/mpl/placeholders.hpp>

#include <qsboost/fusion/view/filter_view/detail/deref_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/next_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/value_of_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/equal_to_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/deref_data_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/value_of_data_impl.hpp>
#include <qsboost/fusion/view/filter_view/detail/key_of_impl.hpp>

namespace qsboost { namespace fusion
{
    struct filter_view_iterator_tag;
    struct forward_traversal_tag;

    template <typename Category, typename First, typename Last, typename Pred>
    struct filter_iterator : iterator_base<filter_iterator<Category, First, Last, Pred> >
    {
        typedef convert_iterator<First> first_converter;
        typedef typename first_converter::type first_iter;
        typedef convert_iterator<Last> last_converter;
        typedef typename last_converter::type last_iter;

        typedef filter_view_iterator_tag fusion_tag;
        typedef Category category;
        typedef
            detail::static_find_if<
                first_iter
              , last_iter
              , mpl::bind1<
                    typename mpl::lambda<Pred>::type
                  , mpl::bind1<mpl::quote1<result_of::value_of>,mpl::_1>
                >
            >
        filter;
        typedef typename filter::type first_type;
        typedef last_iter last_type;
        typedef Pred pred_type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        filter_iterator(First const& in_first)
            : first(filter::iter_call(first_converter::call(in_first))) {}

        first_type first;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        filter_iterator& operator= (filter_iterator const&);
    };
}}

#ifdef QSBOOST_FUSION_WORKAROUND_FOR_LWG_2408
namespace std
{
    template <typename Category, typename First, typename Last, typename Pred>
    struct iterator_traits< ::qsboost::fusion::filter_iterator<Category, First, Last, Pred> >
    { };
}
#endif

#endif



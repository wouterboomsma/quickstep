/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DEREF_05042005_1019)
#define FUSION_DEREF_05042005_1019

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/support/iterator_base.hpp>
#include <qsboost/fusion/support/tag_of.hpp>

namespace qsboost { namespace fusion
{
    // Special tags:
    struct iterator_facade_tag; // iterator facade tag
    struct qsboost_array_iterator_tag; // boost::array iterator tag
    struct mpl_iterator_tag; // mpl sequence iterator tag
    struct std_pair_iterator_tag; // std::pair iterator tag

    namespace extension
    {
        template <typename Tag>
        struct deref_impl
        {
            template <typename Iterator>
            struct apply {};
        };

        template <>
        struct deref_impl<iterator_facade_tag>
        {
            template <typename Iterator>
            struct apply : Iterator::template deref<Iterator> {};
       };

        template <>
        struct deref_impl<qsboost_array_iterator_tag>;

        template <>
        struct deref_impl<mpl_iterator_tag>;

        template <>
        struct deref_impl<std_pair_iterator_tag>;
    }

    namespace result_of
    {
        template <typename Iterator>
        struct deref
            : extension::deref_impl<typename detail::tag_of<Iterator>::type>::
                template apply<Iterator>
        {};
    }

    template <typename Iterator>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::deref<Iterator>::type
    deref(Iterator const& i)
    {
        typedef result_of::deref<Iterator> deref_meta;
        return deref_meta::call(i);
    }

    template <typename Iterator>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::deref<Iterator>::type
    operator*(iterator_base<Iterator> const& i)
    {
        return fusion::deref(i.cast());
    }
}}

#endif
/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_CONS_ITERATOR_07172005_0849)
#define FUSION_CONS_ITERATOR_07172005_0849

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/fusion/support/iterator_base.hpp>
#include <qsboost/fusion/container/list/detail/deref_impl.hpp>
#include <qsboost/fusion/container/list/detail/next_impl.hpp>
#include <qsboost/fusion/container/list/detail/value_of_impl.hpp>
#include <qsboost/fusion/container/list/detail/equal_to_impl.hpp>
#include <qsboost/fusion/container/list/list_fwd.hpp>

namespace qsboost { namespace fusion
{
    struct nil_;
    struct cons_iterator_tag;
    struct forward_traversal_tag;

    template <typename Cons>
    struct cons_iterator_identity;

    template <typename Cons = nil_>
    struct cons_iterator : iterator_base<cons_iterator<Cons> >
    {
        typedef cons_iterator_tag fusion_tag;
        typedef forward_traversal_tag category;
        typedef Cons cons_type;
        typedef cons_iterator_identity<
            typename add_const<Cons>::type> 
        identity;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit cons_iterator(cons_type& in_cons) QSBOOST_NOEXCEPT
            : cons(in_cons) {}

        cons_type& cons;

    private:
        // silence MSVC warning C4512: assignment operator could not be generated
        cons_iterator& operator= (cons_iterator const&);
    };

    struct nil_iterator : iterator_base<nil_iterator>
    {
        typedef forward_traversal_tag category;
        typedef cons_iterator_tag fusion_tag;
        typedef nil_ cons_type;
        typedef cons_iterator_identity<
            add_const<nil_>::type> 
        identity;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        nil_iterator() QSBOOST_NOEXCEPT {}
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit nil_iterator(nil_ const&) QSBOOST_NOEXCEPT {}
    };

    template <>
    struct cons_iterator<nil_> : nil_iterator 
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        cons_iterator() QSBOOST_NOEXCEPT {}
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit cons_iterator(nil_ const&) QSBOOST_NOEXCEPT {}
    };

    template <>
    struct cons_iterator<nil_ const> : nil_iterator 
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        cons_iterator() QSBOOST_NOEXCEPT {}
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit cons_iterator(nil_ const&) QSBOOST_NOEXCEPT {}
    };

    template <>
    struct cons_iterator<list<> > : nil_iterator 
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        cons_iterator() QSBOOST_NOEXCEPT {}
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit cons_iterator(nil_ const&) QSBOOST_NOEXCEPT {}
    };

    template <>
    struct cons_iterator<list<> const> : nil_iterator 
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        cons_iterator() QSBOOST_NOEXCEPT {}
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        explicit cons_iterator(nil_ const&) QSBOOST_NOEXCEPT {}
    };
}}

#ifdef QSBOOST_FUSION_WORKAROUND_FOR_LWG_2408
namespace std
{
    template <typename Cons>
    struct iterator_traits< ::qsboost::fusion::cons_iterator<Cons> >
    { };
}
#endif

#endif

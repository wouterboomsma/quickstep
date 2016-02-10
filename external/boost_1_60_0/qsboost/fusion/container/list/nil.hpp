/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005, 2014 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_NIL_04232014_0843)
#define FUSION_NIL_04232014_0843

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/list/cons_fwd.hpp>
#include <qsboost/fusion/support/sequence_base.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/bool.hpp>

namespace qsboost { namespace fusion
{
    struct void_;
    struct cons_tag;
    struct forward_traversal_tag;
    struct fusion_sequence_tag;

    struct nil_ : sequence_base<nil_>
    {
        typedef mpl::int_<0> size;
        typedef cons_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef mpl::false_ is_view;
        typedef forward_traversal_tag category;
        typedef void_ car_type;
        typedef void_ cdr_type;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        nil_() QSBOOST_NOEXCEPT {}

        template <typename Iterator>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        nil_(Iterator const& /*iter*/, mpl::true_ /*this_is_an_iterator*/) QSBOOST_NOEXCEPT
        {}

        template <typename Iterator>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        void assign_from_iter(Iterator const& /*iter*/) QSBOOST_NOEXCEPT
        {
        }
    };
}}

#endif


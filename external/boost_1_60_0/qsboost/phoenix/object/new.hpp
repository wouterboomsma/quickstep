/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_OBJECT_NEW_HPP
#define QSBOOST_PHOENIX_OBJECT_NEW_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/object/detail/target.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>

QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG(
    (qsboost)(phoenix)(new_)
  , (proto::terminal<detail::target<proto::_> >)
    (meta_grammar)
  , QSBOOST_PHOENIX_COMPOSITE_LIMIT
)

namespace qsboost { namespace phoenix
{
    struct new_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename A0, typename Context>
        struct result<This(A0, Context)>
        {
            typedef typename detail::result_of::target<A0> target_type;
            typedef typename target_type::type * type;
        };

        template <typename Target, typename Context>
        typename detail::result_of::target<Target>::type *
        operator()(Target, Context const &) const
        {
            return new typename detail::result_of::target<Target>::type;
        }

        // Bring in the rest
        #include <qsboost/phoenix/object/detail/new_eval.hpp>
    };

    template <typename Dummy>
    struct default_actions::when<rule::new_, Dummy>
        : call<new_eval, Dummy>
    {};

    template <typename T>
    inline
    typename expression::new_<detail::target<T> >::type const
    new_()
    {
        return
            expression::
                new_<detail::target<T> >::
                    make(detail::target<T>());
    }

    // Bring in the rest
    #include <qsboost/phoenix/object/detail/new.hpp>
}}

#endif


/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_OBJECT_REINTERPRET_CAST_HPP
#define QSBOOST_PHOENIX_OBJECT_REINTERPRET_CAST_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/object/detail/target.hpp>
#include <qsboost/proto/transform/lazy.hpp>

QSBOOST_PHOENIX_DEFINE_EXPRESSION(
    (qsboost)(phoenix)(reinterpret_cast_)
  , (proto::terminal<detail::target<proto::_> >)
    (meta_grammar)
)

namespace qsboost { namespace phoenix
{
    struct reinterpret_cast_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Target, typename Source, typename Context>
        struct result<This(Target, Source, Context)>
            : detail::result_of::target<Target>
        {};

        template <typename Target, typename Source, typename Context>
        typename detail::result_of::target<Target>::type
        operator()(Target, Source const& u, Context const& ctx) const
        {
            return
                reinterpret_cast<
                    typename detail::result_of::target<Target>::type
                >(qsboost::phoenix::eval(u, ctx));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::reinterpret_cast_, Dummy>
        : call<reinterpret_cast_eval, Dummy>
    {};

    template <typename T, typename U>
    inline
    typename expression::reinterpret_cast_<detail::target<T>, U>::type const
    reinterpret_cast_(U const& u)
    {
        return
            expression::
                reinterpret_cast_<detail::target<T>, U>::
                    make(detail::target<T>(), u);
    }
}}

#endif

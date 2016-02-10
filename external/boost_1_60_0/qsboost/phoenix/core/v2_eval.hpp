/*=============================================================================
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_V2_EVAL_HPP
#define QSBOOST_PHOENIX_CORE_V2_EVAL_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/core/environment.hpp>
#include <qsboost/phoenix/core/is_actor.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/terminal_fwd.hpp>
#include <qsboost/phoenix/support/vector.hpp>
#include <qsboost/proto/transform/fold.hpp>
#include <qsboost/proto/transform/lazy.hpp>

namespace qsboost { namespace phoenix
{
    struct v2_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Eval, typename Env>
        struct result<This(Eval, Env)>
            : Eval::template result<typename proto::detail::uncvref<Env>::type>
        {};

        template <typename This, typename Eval, typename Env>
        struct result<This(Eval &, Env)>
            : Eval::template result<typename proto::detail::uncvref<Env>::type>
        {};

        template <typename This, typename Eval, typename Env>
        struct result<This(Eval const &, Env)>
            : Eval::template result<typename proto::detail::uncvref<Env>::type>
        {};

        template <typename Eval, typename Env>
        typename result<v2_eval(Eval const&, Env)>::type
        operator()(Eval const & e, Env const & env) const
        {
            return e.eval(env);
        }
    };
}}

#endif

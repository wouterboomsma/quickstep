/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_TERMINAL_HPP
#define QSBOOST_PHOENIX_CORE_TERMINAL_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/call_traits.hpp>
#include <qsboost/is_placeholder.hpp>
#include <qsboost/phoenix/core/actor.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/core/terminal_fwd.hpp>
#include <qsboost/proto/matches.hpp>
#include <qsboost/proto/transform/lazy.hpp>
#include <qsboost/proto/functional/fusion/at.hpp>
#include <qsboost/type_traits/remove_pointer.hpp>

#define QSBOOST_PHOENIX_DEFINE_CUSTOM_TERMINAL(Template, Terminal, IsNullary, EvalFun)\
    namespace qsboost { namespace phoenix                                         \
    {                                                                           \
        namespace result_of                                                     \
        {                                                                       \
            Template                                                            \
            struct is_nullary<                                                  \
                custom_terminal<                                                \
                    Terminal                                                    \
                >                                                               \
            >                                                                   \
                : IsNullary                                                     \
            {};                                                                 \
        }                                                                       \
        Template                                                                \
        struct is_custom_terminal<Terminal >: mpl::true_ {};                    \
                                                                                \
        Template                                                                \
        struct custom_terminal<Terminal > : proto::call<EvalFun > {};           \
    }}                                                                          \
/**/

namespace qsboost { namespace phoenix
{
    template <typename T, typename Dummy>
    struct is_custom_terminal
        : mpl::false_ {};

    template <typename T, typename Dummy>
    struct custom_terminal;

    namespace tag {
      struct terminal /*: public proto::tag::terminal */ {};
    }
 
    namespace expression
    {
        template <typename T, template <typename> class Actor = actor>
        struct terminal
            : proto::terminal<
                T//typename call_traits<T>::value_type
            >
        {
            typedef
                proto::basic_expr<
                proto::tag::terminal
            // tag::terminal //cannot change to use phoenix tag - breaks code.
                  , proto::term<T>
                  , 0
                >
                base_type;
            typedef Actor<base_type> type;
            
            static const type make(typename call_traits<T>::param_type t)
            {
            // ?? Should the next line be Actor not actor which is the default?
                actor<base_type> const e = {base_type::make(t)};
                //Actor<base_type> const e = {base_type::make(t)};
                return e;
            }
        };
    }

    namespace rule
    {
        struct argument
            : proto::if_<qsboost::is_placeholder<proto::_value>()>
        {};

        struct custom_terminal
            : proto::if_<qsboost::phoenix::is_custom_terminal<proto::_value>()>
        {};
        
        struct terminal
            : proto::terminal<proto::_>
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<proto::tag::terminal, Dummy>
        : proto::or_<
            enable_rule<rule::argument       , Dummy>
          , enable_rule<rule::custom_terminal, Dummy>
          , enable_rule<rule::terminal       , Dummy>
        >
    {};

    template <typename Dummy>
    struct default_actions::when<rule::custom_terminal, Dummy>
        : proto::lazy<
            custom_terminal<proto::_value>(
                proto::_value
              , _context
            )
        >
    {};

    namespace detail
    {
        template <typename N>
        struct placeholder_idx
            : mpl::int_<N::value>
        {};
    }
    
    template <typename Grammar>
    struct default_actions::when<rule::argument, Grammar>
        : proto::call<
            proto::functional::at(
                _env
              , proto::make<
                    detail::placeholder_idx<
                        proto::make<
                            qsboost::is_placeholder<proto::_value>()
                        >
                    >()
                >
            )
        >
    {};
}}

#endif

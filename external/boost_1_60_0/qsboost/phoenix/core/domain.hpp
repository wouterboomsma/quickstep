/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_DOMAIN_HPP
#define QSBOOST_PHOENIX_CORE_DOMAIN_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/proto/matches.hpp>
#include <qsboost/proto/transform/call.hpp>
#include <qsboost/proto/transform/when.hpp>
#include <qsboost/proto/domain.hpp>

namespace qsboost { namespace phoenix
{
    template <typename Expr>
    struct actor;
    
    struct meta_grammar;

    struct phoenix_generator
        : proto::switch_<phoenix_generator>
    {

        QSBOOST_PROTO_USE_BASIC_EXPR()

        template<typename Tag>
        struct case_
            : proto::otherwise<proto::call<proto::pod_generator<actor>(proto::_)> >
        {};
    };

    struct phoenix_default_domain
        : proto::domain<
           proto::basic_default_generator
         , proto::_
         , proto::basic_default_domain
        >
    {
        template <typename T>
        struct as_child
        //: proto_base_domain::as_expr<T> // proto lambda example.
          : as_expr<T>
        {};
    };

    struct phoenix_domain
        : proto::domain<
            phoenix_generator
          , meta_grammar
          , proto::basic_default_domain
        >
    {
        template <typename T>
        struct as_child
        //: proto_base_domain::as_expr<T> // proto lambda example.
          : as_expr<T>
        {};
    };
}}

#endif

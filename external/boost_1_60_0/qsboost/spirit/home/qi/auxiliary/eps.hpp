/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_EPS_MARCH_23_2007_0454PM)
#define QSBOOST_SPIRIT_EPS_MARCH_23_2007_0454PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/qi/domain.hpp>
#include <qsboost/spirit/home/qi/skip_over.hpp>
#include <qsboost/spirit/home/qi/meta_compiler.hpp>
#include <qsboost/spirit/home/support/unused.hpp>
#include <qsboost/spirit/home/support/info.hpp>
#include <qsboost/spirit/home/support/common_terminals.hpp>
#include <qsboost/fusion/include/at.hpp>
#include <qsboost/type_traits/is_convertible.hpp>

namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_terminal<qi::domain, tag::eps>       // enables eps
      : mpl::true_ {};

    template <typename A0>
    struct use_terminal<qi::domain
      , terminal_ex<tag::eps, fusion::vector1<A0> > // enables eps(bool-condition)
    > : is_convertible<A0, bool> {};

    template <>                                     // enables eps(f)
    struct use_lazy_terminal<
        qi::domain, tag::eps, 1 /*arity*/
    > : mpl::true_ {};
}}

namespace qsboost { namespace spirit { namespace qi
{
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    using spirit::eps;
#endif
    using spirit::eps_type;

    struct eps_parser : primitive_parser<eps_parser>
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& /*attr*/) const
        {
            qi::skip_over(first, last, skipper);
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("eps");
        }
    };

    struct semantic_predicate : primitive_parser<semantic_predicate>
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        semantic_predicate(bool predicate_)
          : predicate(predicate_) {}

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& /*attr*/) const
        {
            qi::skip_over(first, last, skipper);
            return predicate;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("semantic-predicate");
        }

        bool predicate;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers>
    struct make_primitive<tag::eps, Modifiers>
    {
        typedef eps_parser result_type;
        result_type operator()(unused_type, unused_type) const
        {
            return result_type();
        }
    };

    template <typename Modifiers, typename A0>
    struct make_primitive<
        terminal_ex<tag::eps, fusion::vector1<A0> >
      , Modifiers>
    {
        typedef semantic_predicate result_type;
        template <typename Terminal>
        result_type operator()(Terminal const& term, unused_type) const
        {
            return result_type(fusion::at_c<0>(term.args) ? true : false);
        }
    };
}}}

#endif

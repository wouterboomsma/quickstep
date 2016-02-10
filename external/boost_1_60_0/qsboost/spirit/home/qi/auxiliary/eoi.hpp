/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_EOI_APRIL_18_2008_0751PM)
#define QSBOOST_SPIRIT_EOI_APRIL_18_2008_0751PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/mpl/bool.hpp>
#include <qsboost/spirit/home/qi/domain.hpp>
#include <qsboost/spirit/home/qi/parser.hpp>
#include <qsboost/spirit/home/qi/meta_compiler.hpp>
#include <qsboost/spirit/home/qi/skip_over.hpp>
#include <qsboost/spirit/home/support/common_terminals.hpp>

namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_terminal<qi::domain, tag::eoi>       // enables eoi
      : mpl::true_ {};
}}

namespace qsboost { namespace spirit { namespace qi
{
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    using spirit::eoi;
#endif
    using spirit::eoi_type;

    struct eoi_parser : primitive_parser<eoi_parser>
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
            return first == last;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("eoi");
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers>
    struct make_primitive<tag::eoi, Modifiers>
    {
        typedef eoi_parser result_type;
        result_type operator()(unused_type, unused_type) const
        {
            return result_type();
        }
    };
}}}

#endif



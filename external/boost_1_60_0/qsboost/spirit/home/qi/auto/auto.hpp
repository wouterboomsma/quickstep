//  Copyright (c) 2001-2011 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(QSBOOST_SPIRIT_QI_AUTO_NOV_29_2009_0336PM)
#define QSBOOST_SPIRIT_QI_AUTO_NOV_29_2009_0336PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/support/common_terminals.hpp>
#include <qsboost/spirit/home/support/info.hpp>
#include <qsboost/spirit/home/support/container.hpp>
#include <qsboost/spirit/home/support/detail/hold_any.hpp>
#include <qsboost/spirit/home/qi/domain.hpp>
#include <qsboost/spirit/home/qi/meta_compiler.hpp>
#include <qsboost/spirit/home/qi/skip_over.hpp>
#include <qsboost/spirit/home/qi/parser.hpp>
#include <qsboost/spirit/home/qi/auto/create_parser.hpp>
#include <qsboost/mpl/bool.hpp>

///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_terminal<qi::domain, tag::auto_>     // enables auto_
      : mpl::true_ {};
}}

///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace spirit { namespace qi
{
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    using spirit::auto_;
#endif
    using spirit::auto_type;

    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers>
    struct auto_parser
      : parser<auto_parser<Modifiers> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef spirit::hold_any type;
        };

        auto_parser(Modifiers const& modifiers)
          : modifiers_(modifiers) {}

        template <typename Iterator, typename Context, typename Skipper
          , typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& context, Skipper const& skipper, Attribute& attr) const
        {
            return compile<qi::domain>(create_parser<Attribute>(), modifiers_)
                      .parse(first, last, context, skipper, attr);
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info("auto_");
        }

        Modifiers modifiers_;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Generator generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Modifiers>
    struct make_primitive<tag::auto_, Modifiers>
    {
        typedef auto_parser<Modifiers> result_type;

        result_type operator()(unused_type, Modifiers const& modifiers) const
        {
            return result_type(modifiers);
        }
    };
}}}

#endif

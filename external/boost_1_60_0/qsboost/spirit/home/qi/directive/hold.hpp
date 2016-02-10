/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(SPIRIT_HOLD_FEBRUARY_6_2010_0917AM)
#define SPIRIT_HOLD_FEBRUARY_6_2010_0917AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/qi/meta_compiler.hpp>
#include <qsboost/spirit/home/qi/skip_over.hpp>
#include <qsboost/spirit/home/qi/parser.hpp>
#include <qsboost/spirit/home/support/attributes.hpp>
#include <qsboost/spirit/home/support/info.hpp>
#include <qsboost/spirit/home/support/common_terminals.hpp>
#include <qsboost/spirit/home/support/unused.hpp>
#include <qsboost/spirit/home/support/has_semantic_action.hpp>
#include <qsboost/spirit/home/support/handles_container.hpp>

namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    template <>
    struct use_directive<qi::domain, tag::hold> // enables hold
      : mpl::true_ {};
}}

namespace qsboost { namespace spirit { namespace qi
{
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    using spirit::hold;
#endif
    using spirit::hold_type;

    template <typename Subject>
    struct hold_directive : unary_parser<hold_directive<Subject> >
    {
        typedef Subject subject_type;
        hold_directive(Subject const& subject_)
          : subject(subject_) {}

        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef typename
                traits::attribute_of<subject_type, Context, Iterator>::type
            type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& context, Skipper const& skipper, Attribute& attr_) const
        {
            Attribute copy(attr_);
            if (subject.parse(first, last, context, skipper, copy))
            {
                traits::swap_impl(copy, attr_);
                return true;
            }
            return false;
        }

        template <typename Context>
        info what(Context& context) const
        {
            return info("hold", subject.what(context));

        }

        Subject subject;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename Subject, typename Modifiers>
    struct make_directive<tag::hold, Subject, Modifiers>
    {
        typedef hold_directive<Subject> result_type;
        result_type operator()(unused_type, Subject const& subject, unused_type) const
        {
            return result_type(subject);
        }
    };
}}}

namespace qsboost { namespace spirit { namespace traits
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Subject>
    struct has_semantic_action<qi::hold_directive<Subject> >
      : unary_has_semantic_action<Subject> {};

    ///////////////////////////////////////////////////////////////////////////
    template <typename Subject, typename Attribute, typename Context
        , typename Iterator>
    struct handles_container<qi::hold_directive<Subject>, Attribute
        , Context, Iterator>
      : unary_handles_container<Subject, Attribute, Context, Iterator> {};
}}}

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_WHAT_APRIL_21_2007_0732AM)
#define QSBOOST_SPIRIT_WHAT_APRIL_21_2007_0732AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/mpl/assert.hpp>
#include <qsboost/spirit/home/support/info.hpp>
#include <qsboost/spirit/home/qi/meta_compiler.hpp>

namespace qsboost { namespace spirit { namespace qi
{
    template <typename Expr>
    inline info what(Expr const& expr)
    {
        // Report invalid expression error as early as possible.
        // If you got an error_expr_is_not_convertible_to_a_parser
        // error message here, then the expression (expr) is not a
        // valid spirit qi expression.
        QSBOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
        return compile<qi::domain>(expr).what(unused);
    }
}}}

#endif


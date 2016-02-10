/*=============================================================================
    Copyright (c) 2001-2012 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_COPY_FEBRUARY_7_2012_0159PM)
#define QSBOOST_SPIRIT_COPY_FEBRUARY_7_2012_0159PM

#include <qsboost/config.hpp>
#include <qsboost/proto/proto.hpp>

#if defined(_MSC_VER)
#pragma once
#endif

#if !defined(QSBOOST_NO_CXX11_AUTO_DECLARATIONS)

namespace qsboost { namespace spirit { namespace qi
{
    template <typename Expr>
    typename qsboost::proto::result_of::deep_copy<Expr>::type
    copy(Expr const& expr)
    {
        QSBOOST_SPIRIT_ASSERT_MATCH(qsboost::spirit::qi::domain, Expr);
        return qsboost::proto::deep_copy(expr);
    }
}}}

#endif
#endif

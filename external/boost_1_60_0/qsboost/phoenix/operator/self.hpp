/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_OPERATOR_SELF_HPP
#define QSBOOST_PHOENIX_OPERATOR_SELF_HPP

#include <qsboost/phoenix/operator/detail/define_operator.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/proto/operators.hpp>

namespace qsboost { namespace phoenix
{
    QSBOOST_PHOENIX_UNARY_OPERATORS(
        (address_of)
        (dereference)
    )
    QSBOOST_PHOENIX_BINARY_OPERATORS(
        (assign)
        (subscript)
    )
    
    using proto::exprns_::operator&;
    using proto::exprns_::operator*;
}}

#include <qsboost/phoenix/operator/detail/undef_operator.hpp>

#endif

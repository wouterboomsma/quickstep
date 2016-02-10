/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_NOTHING_HPP
#define QSBOOST_PHOENIX_CORE_NOTHING_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/mpl/void.hpp>
#include <qsboost/phoenix/core/actor.hpp>
#include <qsboost/phoenix/core/call.hpp>
#include <qsboost/phoenix/core/expression.hpp>
#include <qsboost/phoenix/core/value.hpp>

namespace qsboost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    //  null_actor
    //
    //      An actor that does nothing (a "bum", if you will :-).
    //
    /////////////////////////////////////////////////////////////////////////////
    
    namespace detail
    {
        struct nothing {};
    }
    
    namespace expression
    {
        struct null
            : expression::value<detail::nothing>
        {};
    }
    
    template<typename Dummy>
    struct is_custom_terminal<detail::nothing, Dummy>
      : mpl::true_
    {};

    template<typename Dummy>
    struct custom_terminal<detail::nothing, Dummy>
    {
        typedef void result_type;
        template <typename Context>
        void operator()(detail::nothing, Context &) const
        {
        }
    };

    typedef expression::null::type nothing_type;
#ifndef QSBOOST_PHOENIX_NO_PREDEFINED_TERMINALS
    nothing_type const nothing = {{{}}};
#endif
}}

#endif

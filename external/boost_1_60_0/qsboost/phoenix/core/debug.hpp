/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller
    Copyright (c) 2014 John Fletcher
 
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_DEBUG_HPP
#define QSBOOST_PHOENIX_CORE_DEBUG_HPP

#include <iostream>
#include <qsboost/phoenix/version.hpp>
// Some other things may be needed here...

// Include all proto for the time being...
#include <qsboost/proto/proto.hpp>

namespace qsboost { namespace phoenix
  {

    // For now just drop through to the Proto versions.

    /// \brief Pretty-print a Phoenix expression tree using the Proto code.
    ///
    /// \note Equivalent to <tt>functional::display_expr(0, sout)(expr)</tt>
    /// \param expr The Phoenix expression tree to pretty-print
    /// \param sout The \c ostream to which the output should be
    ///             written. If not specified, defaults to
    ///             <tt>std::cout</tt>.
    template<typename Expr>
    void display_expr(Expr const &expr, std::ostream &sout)
    {
      qsboost::proto::display_expr(expr,sout);
    }

    /// \overload
    ///
    template<typename Expr>
    void display_expr(Expr const &expr)
    {
      qsboost::proto::display_expr(expr);
    }

  } // namespace phoenix
} // namespace boost



#endif

//  Boost string_algo library config.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef QSBOOST_STRING_CONFIG_HPP
#define QSBOOST_STRING_CONFIG_HPP

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

#ifdef QSBOOST_STRING_DEDUCED_TYPENAME
#   error "macro already defined!"
#endif

#define QSBOOST_STRING_TYPENAME QSBOOST_DEDUCED_TYPENAME

// Metrowerks workaround
#if QSBOOST_WORKAROUND(__MWERKS__, <= 0x3003) // 8.x
#pragma parse_func_templ off
#endif

#endif  // BOOST_STRING_CONFIG_HPP

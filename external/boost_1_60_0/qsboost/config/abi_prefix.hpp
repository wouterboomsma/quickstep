//  abi_prefix header  -------------------------------------------------------//

// (c) Copyright John Maddock 2003
   
// Use, modification and distribution are subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt).

#ifndef QSBOOST_CONFIG_ABI_PREFIX_HPP
# define QSBOOST_CONFIG_ABI_PREFIX_HPP
#else
# error double inclusion of header qsboost/config/abi_prefix.hpp is an error
#endif

#include <qsboost/config.hpp>

// this must occur after all other includes and before any code appears:
#ifdef QSBOOST_HAS_ABI_HEADERS
#  include QSBOOST_ABI_PREFIX
#endif

#if defined( __BORLANDC__ )
#pragma nopushoptwarn
#endif


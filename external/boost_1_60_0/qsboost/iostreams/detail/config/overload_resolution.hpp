// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

// Adapted from <boost/config/auto_link.hpp> and from
// http://www.boost.org/more/separate_compilation.html, by John Maddock.

#ifndef QSBOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif             

#include <qsboost/config.hpp> // BOOST_MSVC.
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/config/gcc.hpp>

#if !defined(QSBOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION)
# if QSBOOST_WORKAROUND(__MWERKS__, <= 0x3003) || \
     QSBOOST_WORKAROUND(__BORLANDC__, < 0x600) || \
     QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) || \
     QSBOOST_WORKAROUND(QSBOOST_IOSTREAMS_GCC, <= 295) \
     /**/
#  define QSBOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION
# endif
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_CONFIG_BROKEN_OVERLOAD_RESOLUTION_HPP_INCLUDED

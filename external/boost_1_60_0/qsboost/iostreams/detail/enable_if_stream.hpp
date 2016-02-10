// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <qsboost/config.hpp>                // BOOST_NO_SFINAE.
#include <qsboost/utility/enable_if.hpp>                  
#include <qsboost/iostreams/traits_fwd.hpp>  // is_std_io.

#if !defined(QSBOOST_NO_SFINAE) && \
    !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x592))
# define QSBOOST_IOSTREAMS_ENABLE_IF_STREAM(T) \
    , typename qsboost::enable_if< qsboost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
# define QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T) \
    , typename qsboost::disable_if< qsboost::iostreams::is_std_io<T> >::type* = 0 \
    /**/
#else 
# define QSBOOST_IOSTREAMS_ENABLE_IF_STREAM(T)
# define QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T)
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_ENABLE_IF_STREAM_HPP_INCLUDED

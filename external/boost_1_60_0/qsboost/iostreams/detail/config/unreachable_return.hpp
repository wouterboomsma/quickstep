// (C) Copyright 2010 Daniel James
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_UNREACHABLE_RETURN_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_UNREACHABLE_RETURN_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <qsboost/config.hpp>

// If Boost.Exception has BOOST_ATTRIBUTE_NORETURN
#if defined(_MSC_VER) || defined(__GNUC__)
#define QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(x) \
    QSBOOST_UNREACHABLE_RETURN(x)
#else
#define QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(x) \
    return x;
#endif

#endif

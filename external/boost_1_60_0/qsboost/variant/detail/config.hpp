//-----------------------------------------------------------------------------
// boost variant/detail/config.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_CONFIG_HPP
#define QSBOOST_VARIANT_DETAIL_CONFIG_HPP

#include "qsboost/config.hpp"
#include "qsboost/detail/workaround.hpp"

///////////////////////////////////////////////////////////////////////////////
// macro BOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING
//
#if QSBOOST_WORKAROUND(__MWERKS__, <= 0x3201) \
 || QSBOOST_WORKAROUND(QSBOOST_INTEL, <= 700) \
 && !defined(QSBOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING)
#   define QSBOOST_VARIANT_AUX_BROKEN_CONSTRUCTOR_TEMPLATE_ORDERING
#endif

///////////////////////////////////////////////////////////////////////////////
// macro BOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND
//
#if !defined(QSBOOST_NO_SFINAE) \
 && !QSBOOST_WORKAROUND(QSBOOST_INTEL, <= 700) \
 && !defined(QSBOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND)
#   define QSBOOST_VARIANT_AUX_HAS_CONSTRUCTOR_TEMPLATE_ORDERING_SFINAE_WKND
#endif

#endif // BOOST_VARIANT_DETAIL_CONFIG_HPP

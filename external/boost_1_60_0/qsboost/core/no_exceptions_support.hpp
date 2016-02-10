#ifndef QSBOOST_CORE_NO_EXCEPTIONS_SUPPORT_HPP
#define QSBOOST_CORE_NO_EXCEPTIONS_SUPPORT_HPP

#if defined(_MSC_VER)
#  pragma once
#endif

//----------------------------------------------------------------------
// (C) Copyright 2004 Pavel Vozenilek.
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
// This file contains helper macros used when exception support may be
// disabled (as indicated by macro BOOST_NO_EXCEPTIONS).
//
// Before picking up these macros you may consider using RAII techniques
// to deal with exceptions - their syntax can be always the same with 
// or without exception support enabled.
//----------------------------------------------------------------------

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

#if !(defined QSBOOST_NO_EXCEPTIONS)
#    define QSBOOST_TRY { try
#    define QSBOOST_CATCH(x) catch(x)
#    define QSBOOST_RETHROW throw;
#    define QSBOOST_CATCH_END }
#else
#    if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x564))
#        define QSBOOST_TRY { if ("")
#        define QSBOOST_CATCH(x) else if (!"")
#    else
#        define QSBOOST_TRY { if (true)
#        define QSBOOST_CATCH(x) else if (false)
#    endif
#    define QSBOOST_RETHROW
#    define QSBOOST_CATCH_END }
#endif


#endif 

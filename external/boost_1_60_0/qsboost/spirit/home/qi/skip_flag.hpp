/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_SKIP_FLAG_DEC_02_2009_0412PM)
#define QSBOOST_SPIRIT_SKIP_FLAG_DEC_02_2009_0412PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/support/detail/scoped_enum_emulation.hpp>

namespace qsboost { namespace spirit { namespace qi 
{
    ///////////////////////////////////////////////////////////////////////////
    QSBOOST_SCOPED_ENUM_START(skip_flag) 
    { 
        postskip,           // force post-skipping in phrase_parse()
        dont_postskip       // inhibit post-skipping in phrase_parse()
    };
    QSBOOST_SCOPED_ENUM_END

}}}

#endif


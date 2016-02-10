/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_OUTPUT_UTREE_TRAITS_FWD_FEB_14_2011_0632AM)
#define QSBOOST_SPIRIT_OUTPUT_UTREE_TRAITS_FWD_FEB_14_2011_0632AM

///////////////////////////////////////////////////////////////////////////////
// forward declarations only
///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace spirit 
{ 
    class utree;
}}

namespace qsboost
{
    template <typename T>
    inline T get(qsboost::spirit::utree const& x);
}

#endif

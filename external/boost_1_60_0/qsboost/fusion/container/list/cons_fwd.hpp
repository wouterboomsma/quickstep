/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2005 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_CONS_FWD_HPP_INCLUDED)
#define QSBOOST_FUSION_CONS_FWD_HPP_INCLUDED

namespace qsboost { namespace fusion
{
    struct nil_;
    #ifndef nil
    typedef nil_ nil;
    #endif

    template <typename Car, typename Cdr = nil_>
    struct cons;
}}

#endif


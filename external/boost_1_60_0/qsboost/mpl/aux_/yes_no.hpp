
#ifndef QSBOOST_MPL_AUX_YES_NO_HPP_INCLUDED
#define QSBOOST_MPL_AUX_YES_NO_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/nttp_decl.hpp>
#include <qsboost/mpl/aux_/config/arrays.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>


namespace qsboost { namespace mpl { namespace aux {

typedef char (&no_tag)[1];
typedef char (&yes_tag)[2];

template< bool C_ > struct yes_no_tag
{
    typedef no_tag type;
};

template<> struct yes_no_tag<true>
{
    typedef yes_tag type;
};


template< QSBOOST_MPL_AUX_NTTP_DECL(long, n) > struct weighted_tag
{
#if !QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
    typedef char (&type)[n];
#else
    char buf[n];
    typedef weighted_tag type;
#endif
};

#if defined(QSBOOST_MPL_CFG_NO_DEPENDENT_ARRAY_TYPES)
template<> struct weighted_tag<0>
{
    typedef char (&type)[1];
};
#endif

}}}

#endif // BOOST_MPL_AUX_YES_NO_HPP_INCLUDED

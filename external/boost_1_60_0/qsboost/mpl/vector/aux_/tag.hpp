
#ifndef QSBOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED
#define QSBOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/typeof.hpp>
#include <qsboost/mpl/aux_/nttp_decl.hpp>

namespace qsboost { namespace mpl { namespace aux {

struct v_iter_tag;

#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)
struct vector_tag;
#else
template< QSBOOST_MPL_AUX_NTTP_DECL(long, N) > struct vector_tag;
#endif

}}}

#endif // BOOST_MPL_VECTOR_AUX_TAG_HPP_INCLUDED

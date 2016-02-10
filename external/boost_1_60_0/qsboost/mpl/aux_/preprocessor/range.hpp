
#ifndef QSBOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED
#define QSBOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/preprocessor/seq/subseq.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/arithmetic/add.hpp>

#define QSBOOST_MPL_PP_RANGE_ITEM(z,n,_) (n)

#define QSBOOST_MPL_PP_RANGE(first, length) \
    QSBOOST_PP_SEQ_SUBSEQ( \
        QSBOOST_PP_REPEAT(QSBOOST_PP_ADD(first,length), QSBOOST_MPL_PP_RANGE_ITEM, _), \
        first, length \
    ) \
/**/

#endif // BOOST_MPL_AUX_PREPROCESSOR_RANGE_HPP_INCLUDED

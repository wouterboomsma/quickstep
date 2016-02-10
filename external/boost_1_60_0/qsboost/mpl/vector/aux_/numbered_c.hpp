
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

#if defined(QSBOOST_PP_IS_ITERATING)

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

#include <qsboost/preprocessor/enum_params.hpp>
#include <qsboost/preprocessor/enum_shifted_params.hpp>
#include <qsboost/preprocessor/comma_if.hpp>
#include <qsboost/preprocessor/repeat.hpp>
#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/cat.hpp>

#define i_ QSBOOST_PP_FRAME_ITERATION(1)

#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

#   define AUX778076_VECTOR_TAIL(vector, i_, C) \
    QSBOOST_PP_CAT(QSBOOST_PP_CAT(vector,i_),_c)<T \
          QSBOOST_PP_COMMA_IF(i_) QSBOOST_PP_ENUM_PARAMS(i_, C) \
        > \
    /**/

#if i_ > 0
template<
      typename T
    , QSBOOST_PP_ENUM_PARAMS(i_, T C)
    >
struct QSBOOST_PP_CAT(QSBOOST_PP_CAT(vector,i_),_c)
    : v_item<
          integral_c<T,QSBOOST_PP_CAT(C,QSBOOST_PP_DEC(i_))>
        , AUX778076_VECTOR_TAIL(vector,QSBOOST_PP_DEC(i_),C)
        >
{
    typedef QSBOOST_PP_CAT(QSBOOST_PP_CAT(vector,i_),_c) type;
    typedef T value_type;
};
#endif

#   undef AUX778076_VECTOR_TAIL

#else // "brute force" implementation

#   define AUX778076_VECTOR_C_PARAM_FUNC(unused, i_, param) \
    QSBOOST_PP_COMMA_IF(i_) \
    integral_c<T,QSBOOST_PP_CAT(param,i_)> \
    /**/

template<
      typename T
    , QSBOOST_PP_ENUM_PARAMS(i_, T C)
    >
struct QSBOOST_PP_CAT(QSBOOST_PP_CAT(vector,i_),_c)
    : QSBOOST_PP_CAT(vector,i_)< QSBOOST_PP_REPEAT(i_,AUX778076_VECTOR_C_PARAM_FUNC,C) >
{
    typedef QSBOOST_PP_CAT(QSBOOST_PP_CAT(vector,i_),_c) type;
    typedef T value_type;
};

#   undef AUX778076_VECTOR_C_PARAM_FUNC

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#undef i_

#endif // BOOST_PP_IS_ITERATING

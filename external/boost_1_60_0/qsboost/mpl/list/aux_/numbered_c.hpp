
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

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

#if defined(QSBOOST_PP_IS_ITERATING)

#include <qsboost/preprocessor/enum_params.hpp>
#include <qsboost/preprocessor/enum_shifted_params.hpp>
#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/cat.hpp>

#define i QSBOOST_PP_FRAME_ITERATION(1)

#if i == 1

template<
      typename T
    , QSBOOST_PP_ENUM_PARAMS(i, T C)
    >
struct list1_c
    : l_item<
          long_<1>
        , integral_c<T,C0>
        , l_end
        >
{
    typedef list1_c type;
    typedef T value_type;
};

#else

#   define MPL_AUX_LIST_C_TAIL(list, i, C) \
    QSBOOST_PP_CAT(QSBOOST_PP_CAT(list,QSBOOST_PP_DEC(i)),_c)<T, \
      QSBOOST_PP_ENUM_SHIFTED_PARAMS(i, C) \
    > \
    /**/
    
template<
      typename T
    , QSBOOST_PP_ENUM_PARAMS(i, T C)
    >
struct QSBOOST_PP_CAT(QSBOOST_PP_CAT(list,i),_c)
    : l_item<
          long_<i>
        , integral_c<T,C0>
        , MPL_AUX_LIST_C_TAIL(list,i,C)
        >
{
    typedef QSBOOST_PP_CAT(QSBOOST_PP_CAT(list,i),_c) type;
    typedef T value_type;
};

#   undef MPL_AUX_LIST_C_TAIL

#endif // i == 1

#undef i

#endif // BOOST_PP_IS_ITERATING


// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

#if !defined(QSBOOST_PP_IS_ITERATING)

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

#else

#include <qsboost/mpl/aux_/config/typeof.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>
#include <qsboost/preprocessor/enum_params.hpp>
#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/cat.hpp>

#define i_ QSBOOST_PP_FRAME_ITERATION(1)

#   define AUX778076_MAP_TAIL(map, i_, P) \
    QSBOOST_PP_CAT(map,i_)< \
          QSBOOST_PP_ENUM_PARAMS(i_, P) \
        > \
    /**/


#if defined(QSBOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES)

template<
      QSBOOST_PP_ENUM_PARAMS(i_, typename P)
    >
struct QSBOOST_PP_CAT(map,i_)
    : m_item<
          typename QSBOOST_PP_CAT(P,QSBOOST_PP_DEC(i_))::first
        , typename QSBOOST_PP_CAT(P,QSBOOST_PP_DEC(i_))::second
        , AUX778076_MAP_TAIL(map,QSBOOST_PP_DEC(i_),P)
        >
{
    typedef QSBOOST_PP_CAT(map,i_) type;
};

#else // "brute force" implementation

#   if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename Map>
struct m_at<Map,QSBOOST_PP_DEC(i_)>
{
    typedef typename Map::QSBOOST_PP_CAT(item,QSBOOST_PP_DEC(i_)) type;
};

template< typename Key, typename T, typename Base >
struct m_item<i_,Key,T,Base>
    : m_item_<Key,T,Base>
{
    typedef pair<Key,T> QSBOOST_PP_CAT(item,QSBOOST_PP_DEC(i_));
};

#   else

template<>
struct m_at_impl<QSBOOST_PP_DEC(i_)>
{
    template< typename Map > struct result_
    {
        typedef typename Map::QSBOOST_PP_CAT(item,QSBOOST_PP_DEC(i_)) type;
    };
};

template<>
struct m_item_impl<i_>
{
    template< typename Key, typename T, typename Base > struct result_
        : m_item_<Key,T,Base>
    {
        typedef pair<Key,T> QSBOOST_PP_CAT(item,QSBOOST_PP_DEC(i_));
    };
};

#   endif

template<
      QSBOOST_PP_ENUM_PARAMS(i_, typename P)
    >
struct QSBOOST_PP_CAT(map,i_)
    : m_item<
          i_
        , typename QSBOOST_PP_CAT(P,QSBOOST_PP_DEC(i_))::first
        , typename QSBOOST_PP_CAT(P,QSBOOST_PP_DEC(i_))::second
        , AUX778076_MAP_TAIL(map,QSBOOST_PP_DEC(i_),P)
        >
{
    typedef QSBOOST_PP_CAT(map,i_) type;
};

#endif // BOOST_MPL_CFG_TYPEOF_BASED_SEQUENCES

#   undef AUX778076_MAP_TAIL

#undef i_

#endif // BOOST_PP_IS_ITERATING

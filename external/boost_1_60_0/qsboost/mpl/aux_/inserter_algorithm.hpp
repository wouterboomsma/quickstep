
#ifndef QSBOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED
#define QSBOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2003-2004
// Copyright David Abrahams 2003-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/back_inserter.hpp>
#include <qsboost/mpl/front_inserter.hpp>
#include <qsboost/mpl/push_back.hpp>
#include <qsboost/mpl/push_front.hpp>
#include <qsboost/mpl/back_inserter.hpp>
#include <qsboost/mpl/front_inserter.hpp>
#include <qsboost/mpl/clear.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/common_name_wknd.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/preprocessor/params.hpp>
#include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>

#include <qsboost/preprocessor/arithmetic/dec.hpp>

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#   define QSBOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(arity, name) \
QSBOOST_MPL_AUX_COMMON_NAME_WKND(name) \
template< \
      QSBOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct name \
    : aux::name##_impl<QSBOOST_MPL_PP_PARAMS(arity, P)> \
{ \
}; \
\
template< \
      QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), typename P) \
    > \
struct name< QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P),na > \
    : if_< has_push_back< typename clear<P1>::type> \
        , aux::name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::reverse_##name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
\
template< \
      QSBOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct reverse_##name \
    : aux::reverse_##name##_impl<QSBOOST_MPL_PP_PARAMS(arity, P)> \
{ \
}; \
\
template< \
      QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), typename P) \
    > \
struct reverse_##name< QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P),na > \
    : if_< has_push_back<P1> \
        , aux::reverse_##name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
QSBOOST_MPL_AUX_NA_SPEC(arity, name) \
QSBOOST_MPL_AUX_NA_SPEC(arity, reverse_##name) \
/**/

#else

#   define QSBOOST_MPL_AUX_INSERTER_ALGORITHM_DEF(arity, name) \
QSBOOST_MPL_AUX_COMMON_NAME_WKND(name) \
template< \
      QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), typename P) \
    > \
struct def_##name##_impl \
    : if_< has_push_back<P1> \
        , aux::name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::reverse_##name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
\
template< \
      QSBOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct name \
{ \
    typedef typename eval_if< \
          is_na<QSBOOST_PP_CAT(P, arity)> \
        , def_##name##_impl<QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P)> \
        , aux::name##_impl<QSBOOST_MPL_PP_PARAMS(arity, P)> \
        >::type type; \
}; \
\
template< \
      QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), typename P) \
    > \
struct def_reverse_##name##_impl \
    : if_< has_push_back<P1> \
        , aux::reverse_##name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , back_inserter< typename clear<P1>::type > \
            > \
        , aux::name##_impl< \
              QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P) \
            , front_inserter< typename clear<P1>::type > \
            > \
        >::type \
{ \
}; \
template< \
      QSBOOST_MPL_PP_DEFAULT_PARAMS(arity, typename P, na) \
    > \
struct reverse_##name \
{ \
    typedef typename eval_if< \
          is_na<QSBOOST_PP_CAT(P, arity)> \
        , def_reverse_##name##_impl<QSBOOST_MPL_PP_PARAMS(QSBOOST_PP_DEC(arity), P)> \
        , aux::reverse_##name##_impl<QSBOOST_MPL_PP_PARAMS(arity, P)> \
        >::type type; \
}; \
QSBOOST_MPL_AUX_NA_SPEC(arity, name) \
QSBOOST_MPL_AUX_NA_SPEC(arity, reverse_##name) \
/**/

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#endif // BOOST_MPL_AUX_INSERTER_ALGORITHM_HPP_INCLUDED

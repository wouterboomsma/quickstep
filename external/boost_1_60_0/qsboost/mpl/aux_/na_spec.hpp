
#ifndef QSBOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED
#define QSBOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/lambda_fwd.hpp>
#   include <qsboost/mpl/int.hpp>
#   include <qsboost/mpl/bool.hpp>
#   include <qsboost/mpl/aux_/na.hpp>
#   include <qsboost/mpl/aux_/arity.hpp>
#   include <qsboost/mpl/aux_/template_arity_fwd.hpp>
#endif

#include <qsboost/mpl/aux_/preprocessor/params.hpp>
#include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#include <qsboost/mpl/aux_/preprocessor/def_params_tail.hpp>
#include <qsboost/mpl/aux_/lambda_arity_param.hpp>
#include <qsboost/mpl/aux_/config/dtp.hpp>
#include <qsboost/mpl/aux_/config/eti.hpp>
#include <qsboost/mpl/aux_/nttp_decl.hpp>
#include <qsboost/mpl/aux_/config/ttp.hpp>
#include <qsboost/mpl/aux_/config/lambda.hpp>
#include <qsboost/mpl/aux_/config/overload_resolution.hpp>


#define QSBOOST_MPL_AUX_NA_PARAMS(i) \
    QSBOOST_MPL_PP_ENUM(i, na) \
/**/

#if defined(QSBOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#   define QSBOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
namespace aux { \
template< QSBOOST_MPL_AUX_NTTP_DECL(int, N) > \
struct arity< \
          name< QSBOOST_MPL_AUX_NA_PARAMS(i) > \
        , N \
        > \
    : int_< QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY > \
{ \
}; \
} \
/**/
#else
#   define QSBOOST_MPL_AUX_NA_SPEC_ARITY(i, name) /**/
#endif

#define QSBOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
template<> \
struct name< QSBOOST_MPL_AUX_NA_PARAMS(i) > \
{ \
    template< \
          QSBOOST_MPL_PP_PARAMS(i, typename T) \
        QSBOOST_MPL_PP_NESTED_DEF_PARAMS_TAIL(i, typename T, na) \
        > \
    struct apply \
        : name< QSBOOST_MPL_PP_PARAMS(i, T) > \
    { \
    }; \
}; \
/**/

#if defined(QSBOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
#   define QSBOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
template<> \
struct lambda< \
      name< QSBOOST_MPL_AUX_NA_PARAMS(i) > \
    , void_ \
    , true_ \
    > \
{ \
    typedef false_ is_le; \
    typedef name< QSBOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
template<> \
struct lambda< \
      name< QSBOOST_MPL_AUX_NA_PARAMS(i) > \
    , void_ \
    , false_ \
    > \
{ \
    typedef false_ is_le; \
    typedef name< QSBOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
/**/
#else
#   define QSBOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
template< typename Tag > \
struct lambda< \
      name< QSBOOST_MPL_AUX_NA_PARAMS(i) > \
    , Tag \
    QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(int_<-1>) \
    > \
{ \
    typedef false_ is_le; \
    typedef name< QSBOOST_MPL_AUX_NA_PARAMS(i) > result_; \
    typedef name< QSBOOST_MPL_AUX_NA_PARAMS(i) > type; \
}; \
/**/
#endif

#if defined(QSBOOST_MPL_CFG_EXTENDED_TEMPLATE_PARAMETERS_MATCHING) \
    || defined(QSBOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT) \
        && defined(QSBOOST_MPL_CFG_BROKEN_OVERLOAD_RESOLUTION)
#   define QSBOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) \
namespace aux { \
template< QSBOOST_MPL_PP_PARAMS(j, typename T) > \
struct template_arity< \
          name< QSBOOST_MPL_PP_PARAMS(j, T) > \
        > \
    : int_<j> \
{ \
}; \
\
template<> \
struct template_arity< \
          name< QSBOOST_MPL_PP_ENUM(i, na) > \
        > \
    : int_<-1> \
{ \
}; \
} \
/**/
#else
#   define QSBOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) /**/
#endif

#if defined(QSBOOST_MPL_CFG_MSVC_ETI_BUG)
#   define QSBOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
template<> \
struct name< QSBOOST_MPL_PP_ENUM(i, int) > \
{ \
    typedef int type; \
    enum { value = 0 }; \
}; \
/**/
#else
#   define QSBOOST_MPL_AUX_NA_SPEC_ETI(i, name) /**/
#endif

#define QSBOOST_MPL_AUX_NA_PARAM(param) param = na

#define QSBOOST_MPL_AUX_NA_SPEC_NO_ETI(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, i, name) \
/**/

#define QSBOOST_MPL_AUX_NA_SPEC(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_NO_ETI(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
/**/

#define QSBOOST_MPL_AUX_NA_SPEC2(i, j, name) \
QSBOOST_MPL_AUX_NA_SPEC_MAIN(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_ETI(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_LAMBDA(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_ARITY(i, name) \
QSBOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(i, j, name) \
/**/


#endif // BOOST_MPL_AUX_NA_SPEC_HPP_INCLUDED

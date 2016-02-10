
#ifndef QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED
#define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED

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

#include <qsboost/mpl/aux_/config/lambda.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) /**/
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i,name,params) /**/

#else

#   include <qsboost/mpl/int_fwd.hpp>
#   include <qsboost/mpl/aux_/yes_no.hpp>
#   include <qsboost/mpl/aux_/na_fwd.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#   include <qsboost/mpl/aux_/config/msvc.hpp>
#   include <qsboost/mpl/aux_/config/workaround.hpp>

#   include <qsboost/preprocessor/tuple/to_list.hpp>
#   include <qsboost/preprocessor/list/for_each_i.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC(R,typedef_,i,param) \
    typedef_ param QSBOOST_PP_CAT(arg,QSBOOST_PP_INC(i)); \
    /**/

// agurt, 07/mar/03: restore an old revision for the sake of SGI MIPSpro C++
#if QSBOOST_WORKAROUND(__EDG_VERSION__, <= 238) 

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    typedef QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    QSBOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , QSBOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , QSBOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind \
    { \
        template< QSBOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
            : name< QSBOOST_MPL_PP_PARAMS(i,U) > \
        { \
        }; \
    }; \
    /**/

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    /**/

#elif QSBOOST_WORKAROUND(__EDG_VERSION__, <= 244) && !defined(QSBOOST_INTEL_CXX_VERSION)
// agurt, 18/jan/03: old EDG-based compilers actually enforce 11.4 para 9
// (in strict mode), so we have to provide an alternative to the 
// MSVC-optimized implementation

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    QSBOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , QSBOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , QSBOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    struct rebind; \
/**/

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
template< QSBOOST_MPL_PP_PARAMS(i,typename T) > \
struct name<QSBOOST_MPL_PP_PARAMS(i,T)>::rebind \
{ \
    template< QSBOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< QSBOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/

#else // __EDG_VERSION__

namespace qsboost { namespace mpl { namespace aux {
template< typename T > struct has_rebind_tag;
}}}

#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
    typedef QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::int_<i> arity; \
    QSBOOST_PP_LIST_FOR_EACH_I_R( \
          1 \
        , QSBOOST_MPL_AUX_LAMBDA_SUPPORT_ARG_TYPEDEF_FUNC \
        , typedef \
        , QSBOOST_PP_TUPLE_TO_LIST(i,params) \
        ) \
    friend class QSBOOST_PP_CAT(name,_rebind); \
    typedef QSBOOST_PP_CAT(name,_rebind) rebind; \
/**/

#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610))
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< QSBOOST_MPL_PP_PARAMS(i,typename T) > \
::qsboost::mpl::aux::yes_tag operator|( \
      ::qsboost::mpl::aux::has_rebind_tag<int> \
    , name<QSBOOST_MPL_PP_PARAMS(i,T)>* \
    ); \
::qsboost::mpl::aux::no_tag operator|( \
      ::qsboost::mpl::aux::has_rebind_tag<int> \
    , name< QSBOOST_MPL_PP_ENUM(i,::qsboost::mpl::na) >* \
    ); \
/**/
#elif !QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
template< QSBOOST_MPL_PP_PARAMS(i,typename T) > \
::qsboost::mpl::aux::yes_tag operator|( \
      ::qsboost::mpl::aux::has_rebind_tag<int> \
    , ::qsboost::mpl::aux::has_rebind_tag< name<QSBOOST_MPL_PP_PARAMS(i,T)> >* \
    ); \
/**/
#else
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) /**/
#endif

#   if !defined(__BORLANDC__)
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class QSBOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< QSBOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
        : name< QSBOOST_MPL_PP_PARAMS(i,U) > \
    { \
    }; \
/**/
#   else
#   define QSBOOST_MPL_AUX_LAMBDA_SUPPORT(i, name, params) \
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(i, name, params) \
}; \
QSBOOST_MPL_AUX_LAMBDA_SUPPORT_HAS_REBIND(i, name, params) \
class QSBOOST_PP_CAT(name,_rebind) \
{ \
 public: \
    template< QSBOOST_MPL_PP_PARAMS(i,typename U) > struct apply \
    { \
        typedef typename name< QSBOOST_MPL_PP_PARAMS(i,U) >::type type; \
    }; \
/**/
#   endif // __BORLANDC__

#endif // __EDG_VERSION__

#endif // BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT

#endif // BOOST_MPL_AUX_LAMBDA_SUPPORT_HPP_INCLUDED

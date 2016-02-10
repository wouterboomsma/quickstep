
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

// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/bool.hpp>
#   include <qsboost/mpl/aux_/nested_type_wknd.hpp>
#   include <qsboost/mpl/aux_/na_spec.hpp>
#   include <qsboost/mpl/aux_/lambda_support.hpp>
#endif

#include <qsboost/mpl/limits/arity.hpp>
#include <qsboost/mpl/aux_/preprocessor/params.hpp>
#include <qsboost/mpl/aux_/preprocessor/ext_params.hpp>
#include <qsboost/mpl/aux_/preprocessor/def_params_tail.hpp>
#include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#include <qsboost/mpl/aux_/preprocessor/sub.hpp>
#include <qsboost/mpl/aux_/config/ctps.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/inc.hpp>
#include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

#   define AUX778076_PARAMS(param, sub) \
    QSBOOST_MPL_PP_PARAMS( \
          QSBOOST_MPL_PP_SUB(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, sub) \
        , param \
        ) \
    /**/

#   define AUX778076_SHIFTED_PARAMS(param, sub) \
    QSBOOST_MPL_PP_EXT_PARAMS( \
          2, QSBOOST_MPL_PP_SUB(QSBOOST_PP_INC(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY), sub) \
        , param \
        ) \
    /**/

#   define AUX778076_SPEC_PARAMS(param) \
    QSBOOST_MPL_PP_ENUM( \
          QSBOOST_PP_DEC(QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY) \
        , param \
        ) \
    /**/

namespace aux {

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< bool C_, AUX778076_PARAMS(typename T, 1) >
struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)
    : QSBOOST_PP_CAT(AUX778076_OP_VALUE1,_)
{
};

template< AUX778076_PARAMS(typename T, 1) >
struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)< AUX778076_OP_VALUE2,AUX778076_PARAMS(T, 1) >
    : QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        , AUX778076_SHIFTED_PARAMS(T, 1)
        , QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_)
        >
{
};

template<>
struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          AUX778076_OP_VALUE2
        , AUX778076_SPEC_PARAMS(QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_))
        >
    : QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_)
{
};

#else

template< bool C_ > struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)
{
    template< AUX778076_PARAMS(typename T, 1) > struct result_
        : QSBOOST_PP_CAT(AUX778076_OP_VALUE1,_)
    {
    };
};

template<> struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)<AUX778076_OP_VALUE2>
{
    template< AUX778076_PARAMS(typename T, 1) > struct result_
        : QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)< 
              QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
            >::template result_< AUX778076_SHIFTED_PARAMS(T,1),QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_) >
    {
    };

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1300)
    template<> struct result_<AUX778076_SPEC_PARAMS(QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_))>
        : QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_)
    {
    };
};
#else
};

template<>
struct QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)<AUX778076_OP_VALUE2>
    ::result_< AUX778076_SPEC_PARAMS(QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_)) >
        : QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_)
{
};
#endif // BOOST_MSVC == 1300

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

} // namespace aux

template<
      typename QSBOOST_MPL_AUX_NA_PARAM(T1)
    , typename QSBOOST_MPL_AUX_NA_PARAM(T2)
    QSBOOST_MPL_PP_DEF_PARAMS_TAIL(2, typename T, QSBOOST_PP_CAT(AUX778076_OP_VALUE2,_))
    >
struct AUX778076_OP_NAME
#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
    : aux::QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)<
          QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        , AUX778076_SHIFTED_PARAMS(T,0)
        >
#else
    : aux::QSBOOST_PP_CAT(AUX778076_OP_NAME,impl)< 
          QSBOOST_MPL_AUX_NESTED_TYPE_WKND(T1)::value
        >::template result_< AUX778076_SHIFTED_PARAMS(T,0) >
#endif
{
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
        , AUX778076_OP_NAME
        , (AUX778076_PARAMS(T, 0))
        )
};

QSBOOST_MPL_AUX_NA_SPEC2(
      2
    , QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
    , AUX778076_OP_NAME
    )

}}

#undef AUX778076_SPEC_PARAMS
#undef AUX778076_SHIFTED_PARAMS
#undef AUX778076_PARAMS
#undef AUX778076_OP_NAME
#undef AUX778076_OP_VALUE1
#undef AUX778076_OP_VALUE2


#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_APPLY_HPP_INCLUDED
#define QSBOOST_MPL_APPLY_HPP_INCLUDED

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

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/apply_fwd.hpp>
#   include <qsboost/mpl/apply_wrap.hpp>
#   include <qsboost/mpl/placeholders.hpp>
#   include <qsboost/mpl/lambda.hpp>
#   include <qsboost/mpl/aux_/na.hpp>
#   include <qsboost/mpl/aux_/lambda_support.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER apply.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/partial_spec_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#   include <qsboost/mpl/aux_/config/lambda.hpp>
#   include <qsboost/mpl/aux_/config/dtp.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>
#   include <qsboost/mpl/aux_/config/eti.hpp>
#   include <qsboost/mpl/aux_/config/msvc.hpp>
#   include <qsboost/mpl/aux_/config/workaround.hpp>

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

// local macros, #undef-ined at the end of the header
#   define AUX778076_APPLY_PARAMS(param) \
    QSBOOST_MPL_PP_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        ) \
    /**/

#   define AUX778076_APPLY_DEF_PARAMS(param, value) \
    QSBOOST_MPL_PP_DEFAULT_PARAMS( \
          QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY \
        , param \
        , value \
        ) \
    /**/

#   define AUX778076_APPLY_N_PARAMS(n, param) \
    QSBOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_APPLY_N_COMMA_PARAMS(n, param) \
    QSBOOST_PP_COMMA_IF(n) \
    QSBOOST_MPL_PP_PARAMS(n, param) \
    /**/

#   define AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS(n, param, def) \
    QSBOOST_PP_COMMA_IF(n) \
    QSBOOST_MPL_PP_PARTIAL_SPEC_PARAMS(n, param, def) \
    /**/
    
#   define AUX778076_APPLY_N_SPEC_PARAMS(n, param) \
    QSBOOST_MPL_PP_ENUM(QSBOOST_PP_INC(n), param) \
    /**/


#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/apply.hpp>))
#include QSBOOST_PP_ITERATE()

#   if !defined(QSBOOST_MPL_CFG_NO_APPLY_TEMPLATE)
// real C++ version is already taken care of
#   if defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

namespace aux {
// apply_count_args
#define AUX778076_COUNT_ARGS_PREFIX apply
#define AUX778076_COUNT_ARGS_DEFAULT na
#define AUX778076_COUNT_ARGS_ARITY QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
#include <qsboost/mpl/aux_/count_args.hpp>
}


template<
      typename F, AUX778076_APPLY_DEF_PARAMS(typename T, na)
    >
struct apply
    : aux::apply_chooser< 
          aux::apply_count_args< AUX778076_APPLY_PARAMS(T) >::value
        >::template result_< F, AUX778076_APPLY_PARAMS(T) >::type
{
};

#   endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#   undef AUX778076_APPLY_N_SPEC_PARAMS
#   undef AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS
#   undef AUX778076_APPLY_N_COMMA_PARAMS
#   undef AUX778076_APPLY_N_PARAMS
#   undef AUX778076_APPLY_DEF_PARAMS
#   undef AUX778076_APPLY_PARAMS

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_APPLY_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if QSBOOST_PP_ITERATION_DEPTH() == 1

#   define i_ QSBOOST_PP_FRAME_ITERATION(1)

template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct QSBOOST_PP_CAT(apply,i_)
#if !QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
    : QSBOOST_PP_CAT(apply_wrap,i_)< 
          typename lambda<F>::type
        AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
        >
{
#else
{
    typedef typename QSBOOST_PP_CAT(apply_wrap,i_)< 
          typename lambda<F>::type
        AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
        >::type type;
#endif
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(
          QSBOOST_PP_INC(i_)
        , QSBOOST_PP_CAT(apply,i_)
        , (F AUX778076_APPLY_N_COMMA_PARAMS(i_,T))
        )
};


#if defined(QSBOOST_MPL_CFG_MSVC_ETI_BUG)
/// workaround for ETI bug
template<>
struct QSBOOST_PP_CAT(apply,i_)<AUX778076_APPLY_N_SPEC_PARAMS(i_, int)>
{
    typedef int type;
};
#endif

#   if !defined(QSBOOST_MPL_CFG_NO_APPLY_TEMPLATE)
#   if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

#if i_ == QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
/// primary template (not a specialization!)
template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct apply
    : QSBOOST_PP_CAT(apply,i_)< F AUX778076_APPLY_N_COMMA_PARAMS(i_, T) >
{
};
#else
template<
      typename F AUX778076_APPLY_N_COMMA_PARAMS(i_, typename T)
    >
struct apply< F AUX778076_APPLY_N_PARTIAL_SPEC_PARAMS(i_, T, na) >
    : QSBOOST_PP_CAT(apply,i_)< F AUX778076_APPLY_N_COMMA_PARAMS(i_, T) >
{
};
#endif

#   else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#if !defined(QSBOOST_MPL_CFG_NO_APPLY_TEMPLATE)
namespace aux {

template<>
struct apply_chooser<i_>
{
    template<
          typename F, AUX778076_APPLY_PARAMS(typename T)
        >
    struct result_
    {
        typedef QSBOOST_PP_CAT(apply,i_)<
              F AUX778076_APPLY_N_COMMA_PARAMS(i_, T)
            > type;
    };
};

} // namespace aux
#endif

#   endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION
#   endif // BOOST_MPL_CFG_NO_APPLY_TEMPLATE

#   undef i_

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING

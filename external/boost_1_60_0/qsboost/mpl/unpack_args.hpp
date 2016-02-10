
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_UNPACK_ARGS_HPP_INCLUDED
#define QSBOOST_MPL_UNPACK_ARGS_HPP_INCLUDED

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

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/apply.hpp>
#   include <qsboost/mpl/at.hpp>
#   include <qsboost/mpl/size.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>
#   include <qsboost/mpl/aux_/lambda_spec.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER unpack_args.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/repeat.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/config/forwarding.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>


namespace qsboost { namespace mpl {

// local macros, #undef-ined at the end of the header

#   define AUX778076_UNPACK(unused, i, Args) \
    , typename at_c<Args,i>::type \
    /**/

#   define AUX778076_UNPACKED_ARGS(n, Args) \
    QSBOOST_MPL_PP_REPEAT(n, AUX778076_UNPACK, Args) \
    /**/

namespace aux {

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
template< int size, typename F, typename Args >
struct unpack_args_impl;
#else
template< QSBOOST_MPL_AUX_NTTP_DECL(int, size) > struct unpack_args_impl
{
    template< typename F, typename Args > struct apply;
};
#endif

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/unpack_args.hpp>))
#include QSBOOST_PP_ITERATE()

}

template<
      typename F
    >
struct unpack_args
{
    template< typename Args > struct apply
#if !defined(QSBOOST_MPL_CFG_NO_NESTED_FORWARDING)
#   if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
        : aux::unpack_args_impl< size<Args>::value,F,Args >
#   else
        : aux::unpack_args_impl< size<Args>::value >
            ::template apply< F,Args >
#   endif
    {
#else // BOOST_MPL_CFG_NO_NESTED_FORWARDING
    {
        typedef typename aux::unpack_args_impl< 
              size<Args>::value
            , F
            , Args
            >::type type;
#endif
    };
};

QSBOOST_MPL_AUX_PASS_THROUGH_LAMBDA_SPEC(1, unpack_args)

#   undef AUX778076_UNPACK
#   undef AUX778076_UNPACKED_ARGS

}}

#endif // BOOST_MPL_CFG_USE_PREPROCESSED_HEADERS
#endif // BOOST_MPL_UNPACK_ARGS_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if QSBOOST_PP_ITERATION_DEPTH() == 1

#   define i_ QSBOOST_PP_FRAME_ITERATION(1)

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)

template< typename F, typename Args >
struct unpack_args_impl<i_,F,Args>
    : QSBOOST_PP_CAT(apply,i_)<
          F
        AUX778076_UNPACKED_ARGS(i_, Args)
        >
{
};

#else

template<> struct unpack_args_impl<i_>
{
    template< typename F, typename Args > struct apply
        : QSBOOST_PP_CAT(apply,i_)<
              F
            AUX778076_UNPACKED_ARGS(i_, Args)
            >
    {
    };
};

#endif

#   undef i_

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING

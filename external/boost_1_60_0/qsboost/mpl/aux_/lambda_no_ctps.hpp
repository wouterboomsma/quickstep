
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_AUX_LAMBDA_NO_CTPS_HPP_INCLUDED
#define QSBOOST_MPL_AUX_LAMBDA_NO_CTPS_HPP_INCLUDED

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
#   include <qsboost/mpl/lambda_fwd.hpp>
#   include <qsboost/mpl/bind_fwd.hpp>
#   include <qsboost/mpl/protect.hpp>
#   include <qsboost/mpl/is_placeholder.hpp>
#   include <qsboost/mpl/if.hpp>
#   include <qsboost/mpl/identity.hpp>
#   include <qsboost/mpl/bool.hpp>
#   include <qsboost/mpl/aux_/na_spec.hpp>
#   include <qsboost/mpl/aux_/lambda_support.hpp>
#   include <qsboost/mpl/aux_/template_arity.hpp>
#   include <qsboost/mpl/aux_/value_wknd.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if    !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER lambda_no_ctps.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/mpl/aux_/preprocessor/params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/default_params.hpp>
#   include <qsboost/mpl/aux_/preprocessor/repeat.hpp>
#   include <qsboost/mpl/aux_/preprocessor/enum.hpp>
#   include <qsboost/mpl/aux_/config/msvc.hpp>
#   include <qsboost/mpl/aux_/config/workaround.hpp>

#   include <qsboost/preprocessor/comma_if.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>

namespace qsboost { namespace mpl {

#   define AUX778076_LAMBDA_PARAMS(i_, param) \
    QSBOOST_MPL_PP_PARAMS(i_, param) \
    /**/

namespace aux {

#define n_ QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY
template<
      QSBOOST_MPL_PP_DEFAULT_PARAMS(n_,bool C,false)
    >
struct lambda_or
    : true_
{
};

template<>
struct lambda_or< QSBOOST_MPL_PP_ENUM(n_,false) >
    : false_
{
};
#undef n_

template< typename Arity > struct lambda_impl
{
    template< typename T, typename Tag, typename Protect > struct result_
    {
        typedef T type;
        typedef is_placeholder<T> is_le;
    };
};

#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, <qsboost/mpl/aux_/lambda_no_ctps.hpp>))
#include QSBOOST_PP_ITERATE()

} // namespace aux

template<
      typename T
    , typename Tag
    , typename Protect
    >
struct lambda
{
    /// Metafunction forwarding confuses MSVC 6.x
    typedef typename aux::template_arity<T>::type arity_;
    typedef typename aux::lambda_impl<arity_>
        ::template result_< T,Tag,Protect > l_;

    typedef typename l_::type type;
    typedef typename l_::is_le is_le;
    
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(3, lambda, (T, Tag, Protect))
};

QSBOOST_MPL_AUX_NA_SPEC2(1, 3, lambda)

template<
      typename T
    >
struct is_lambda_expression
    : lambda<T>::is_le
{
};

#   undef AUX778076_LAMBDA_PARAMS

}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX_LAMBDA_NO_CTPS_HPP_INCLUDED

///// iteration, depth == 1

#else

#define i_ QSBOOST_PP_FRAME_ITERATION(1)

#   define AUX778076_LAMBDA_TYPEDEF(unused, i_, F) \
    typedef lambda< \
          typename F::QSBOOST_PP_CAT(arg,QSBOOST_PP_INC(i_)) \
        , Tag \
        , false_ \
        > QSBOOST_PP_CAT(l,QSBOOST_PP_INC(i_)); \
    /**/

#   define AUX778076_IS_LE_TYPEDEF(unused, i_, unused2) \
    typedef typename QSBOOST_PP_CAT(l,QSBOOST_PP_INC(i_))::is_le \
        QSBOOST_PP_CAT(is_le,QSBOOST_PP_INC(i_)); \
    /**/

#   define AUX778076_IS_LAMBDA_EXPR(unused, i_, unused2) \
    QSBOOST_PP_COMMA_IF(i_) \
    QSBOOST_MPL_AUX_MSVC_VALUE_WKND(QSBOOST_PP_CAT(is_le,QSBOOST_PP_INC(i_)))::value \
    /**/

#   define AUX778076_LAMBDA_RESULT(unused, i_, unused2) \
    , typename QSBOOST_PP_CAT(l,QSBOOST_PP_INC(i_))::type \
    /**/

template<> struct lambda_impl< int_<i_> >
{
    template< typename F, typename Tag, typename Protect > struct result_
    {
        QSBOOST_MPL_PP_REPEAT(i_, AUX778076_LAMBDA_TYPEDEF, F)
        QSBOOST_MPL_PP_REPEAT(i_, AUX778076_IS_LE_TYPEDEF, unused)

        typedef aux::lambda_or<
              QSBOOST_MPL_PP_REPEAT(i_, AUX778076_IS_LAMBDA_EXPR, unused)
            > is_le;

        typedef QSBOOST_PP_CAT(bind,i_)<
              typename F::rebind
            QSBOOST_MPL_PP_REPEAT(i_, AUX778076_LAMBDA_RESULT, unused)
            > bind_;

        typedef typename if_<
              is_le
            , if_< Protect, mpl::protect<bind_>, bind_ >
            , identity<F>
            >::type type_;
    
        typedef typename type_::type type;
    };
};

#   undef AUX778076_LAMBDA_RESULT
#   undef AUX778076_IS_LAMBDA_EXPR
#   undef AUX778076_IS_LE_TYPEDEF
#   undef AUX778076_LAMBDA_TYPEDEF

#undef i_

#endif // BOOST_PP_IS_ITERATING

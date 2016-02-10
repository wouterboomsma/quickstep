
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

//-----------------------------------------------------------------------------
// boost variant/detail/substitute.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_SUBSTITUTE_HPP
#define QSBOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

#include "qsboost/mpl/aux_/config/ctps.hpp"

#include "qsboost/variant/detail/substitute_fwd.hpp"
#include "qsboost/variant/variant_fwd.hpp" // for BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES
#include "qsboost/mpl/aux_/lambda_arity_param.hpp"
#include "qsboost/mpl/aux_/preprocessor/params.hpp"
#include "qsboost/mpl/aux_/preprocessor/repeat.hpp"
#include "qsboost/mpl/int_fwd.hpp"
#include "qsboost/mpl/limits/arity.hpp"
#include "qsboost/preprocessor/cat.hpp"
#include "qsboost/preprocessor/empty.hpp"
#include "qsboost/preprocessor/arithmetic/inc.hpp"
#include "qsboost/preprocessor/iterate.hpp"

namespace qsboost {
namespace detail { namespace variant {

#if !defined(QSBOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction substitute
//
// Substitutes one type for another in the given type expression.
//

//
// primary template
//
template <
      typename T, typename Dest, typename Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity /* = ... (see substitute_fwd.hpp) */
        )
    >
struct substitute
{
    typedef T type;
};

//
// tag substitution specializations
//

#define QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(CV_) \
    template <typename Dest, typename Source> \
    struct substitute< \
          CV_ Source \
        , Dest \
        , Source \
          QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef CV_ Dest type; \
    }; \
    /**/

QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG( QSBOOST_PP_EMPTY() )
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const)
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(volatile)
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG(const volatile)

#undef QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_SUBSTITUTE_TAG

//
// pointer specializations
//
#define QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(CV_) \
    template <typename T, typename Dest, typename Source> \
    struct substitute< \
          T * CV_ \
        , Dest \
        , Source \
          QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>) \
        > \
    { \
        typedef typename substitute< \
              T, Dest, Source \
            >::type * CV_ type; \
    }; \
    /**/

QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER( QSBOOST_PP_EMPTY() )
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const)
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(volatile)
QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER(const volatile)

#undef QSBOOST_VARIANT_AUX_ENABLE_RECURSIVE_IMPL_HANDLE_POINTER

//
// reference specializations
//
template <typename T, typename Dest, typename Source>
struct substitute<
      T&
    , Dest
    , Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
    typedef typename substitute<
          T, Dest, Source
        >::type & type;
};

//
// template expression (i.e., F<...>) specializations
//

#if !defined(QSBOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)
template <
      template <typename...> class F
    , typename... Ts
    , typename Dest
    , typename Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(typename Arity)
    >
struct substitute<
      F<Ts...>
    , Dest
    , Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(Arity)
    >
{
    typedef F<typename substitute<
          Ts, Dest, Source
        >::type...> type;
};
#endif // !defined(BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)

#define QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL(N) \
    typedef typename substitute< \
          QSBOOST_PP_CAT(U,N), Dest, Source \
        >::type QSBOOST_PP_CAT(u,N); \
    /**/

#define QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF(z, N, _) \
    QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL( QSBOOST_PP_INC(N) ) \
    /**/

#define QSBOOST_PP_ITERATION_LIMITS (0,QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY)
#define QSBOOST_PP_FILENAME_1 "qsboost/variant/detail/substitute.hpp"
#include QSBOOST_PP_ITERATE()

#undef QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF_IMPL
#undef QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF

#endif // !defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_SUBSTITUTE_HPP

///// iteration, depth == 1

#elif QSBOOST_PP_ITERATION_DEPTH() == 1
#define i QSBOOST_PP_FRAME_ITERATION(1)

#if i > 0

//
// template specializations
//
template <
      template < QSBOOST_MPL_PP_PARAMS(i,typename P) > class T
    , QSBOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      T< QSBOOST_MPL_PP_PARAMS(i,U) >
    , Dest
    , Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<( i )>)
    >
{
private:
    QSBOOST_MPL_PP_REPEAT(i, QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef T< QSBOOST_MPL_PP_PARAMS(i,u) > type;
};

//
// function specializations
//
template <
      typename R
    , QSBOOST_MPL_PP_PARAMS(i,typename U)
    , typename Dest
    , typename Source
    >
struct substitute<
      R (*)( QSBOOST_MPL_PP_PARAMS(i,U) )
    , Dest
    , Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;
    QSBOOST_MPL_PP_REPEAT(i, QSBOOST_VARIANT_AUX_SUBSTITUTE_TYPEDEF, _)

public:
    typedef r (*type)( QSBOOST_MPL_PP_PARAMS(i,u) );
};

#elif i == 0

//
// zero-arg function specialization
//
template <
      typename R, typename Dest, typename Source
    >
struct substitute<
      R (*)( void )
    , Dest
    , Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(mpl::int_<-1>)
    >
{
private:
    typedef typename substitute< R, Dest, Source >::type r;

public:
    typedef r (*type)( void );
};

#endif // i

#undef i
#endif // BOOST_PP_IS_ITERATING

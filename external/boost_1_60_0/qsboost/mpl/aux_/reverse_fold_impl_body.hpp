
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION!

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

#   include <qsboost/mpl/limits/unrolling.hpp>
#   include <qsboost/mpl/aux_/preprocessor/repeat.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>

#   include <qsboost/preprocessor/arithmetic/sub.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/dec.hpp>
#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>

// local macros, #undef-ined at the end of the header

#   define AUX778076_ITER_FOLD_FORWARD_STEP(unused, n_, unused2) \
    typedef typename apply2< \
          ForwardOp \
        , QSBOOST_PP_CAT(fwd_state,n_) \
        , AUX778076_FOLD_IMPL_OP(QSBOOST_PP_CAT(iter,n_)) \
        >::type QSBOOST_PP_CAT(fwd_state,QSBOOST_PP_INC(n_)); \
    typedef typename mpl::next<QSBOOST_PP_CAT(iter,n_)>::type \
        QSBOOST_PP_CAT(iter,QSBOOST_PP_INC(n_)); \
    /**/

#   define AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC(n_) \
    typedef typename apply2< \
          BackwardOp \
        , QSBOOST_PP_CAT(bkwd_state,n_) \
        , AUX778076_FOLD_IMPL_OP(QSBOOST_PP_CAT(iter,QSBOOST_PP_DEC(n_))) \
        >::type QSBOOST_PP_CAT(bkwd_state,QSBOOST_PP_DEC(n_)); \
    /**/

#   define AUX778076_ITER_FOLD_BACKWARD_STEP(unused, n_, j) \
    AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC( \
          QSBOOST_PP_SUB_D(1,j,n_) \
        ) \
    /**/

#   define AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(n_) \
    typedef typename nested_chunk::state QSBOOST_PP_CAT(bkwd_state,n_);
    /**/

#   define AUX778076_FOLD_IMPL_NAME \
    QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_impl) \
    /**/

#   define AUX778076_FOLD_CHUNK_NAME \
    QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_chunk) \
    /**/

namespace qsboost { namespace mpl { namespace aux {

/// forward declaration
template<
      QSBOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME;

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(QSBOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)

#   define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_UNROLLING, <qsboost/mpl/aux_/reverse_fold_impl_body.hpp>))
#   include QSBOOST_PP_ITERATE()

// implementation for N that exceeds BOOST_MPL_LIMIT_UNROLLING
template<
      QSBOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
{
    typedef First iter0;
    typedef State fwd_state0;

    QSBOOST_MPL_PP_REPEAT(
          QSBOOST_MPL_LIMIT_UNROLLING
        , AUX778076_ITER_FOLD_FORWARD_STEP
        , unused
        )

    typedef AUX778076_FOLD_IMPL_NAME<
          ( (N - QSBOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - QSBOOST_MPL_LIMIT_UNROLLING )
        , QSBOOST_PP_CAT(iter,QSBOOST_MPL_LIMIT_UNROLLING)
        , Last
        , QSBOOST_PP_CAT(fwd_state,QSBOOST_MPL_LIMIT_UNROLLING)
        , BackwardOp
        , ForwardOp
        > nested_chunk;
        
    AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(QSBOOST_MPL_LIMIT_UNROLLING)

    QSBOOST_MPL_PP_REPEAT(
          QSBOOST_MPL_LIMIT_UNROLLING
        , AUX778076_ITER_FOLD_BACKWARD_STEP
        , QSBOOST_MPL_LIMIT_UNROLLING
        )

    typedef bkwd_state0 state;
    typedef typename nested_chunk::iterator iterator;
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,First,Last,State,BackwardOp,ForwardOp>
{
    typedef AUX778076_FOLD_IMPL_NAME<
          -1
        , typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , BackwardOp
        , ForwardOp
        > nested_step;

    typedef typename apply2<
          BackwardOp
        , typename nested_step::state
        , AUX778076_FOLD_IMPL_OP(First)
        >::type state;

    typedef typename nested_step::iterator iterator;
};

template<
      typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME<-1,Last,Last,State,BackwardOp,ForwardOp>
{
    typedef State state;
    typedef Last iterator;
};

#else // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

template< QSBOOST_MPL_AUX_NTTP_DECL(long, N) >
struct AUX778076_FOLD_CHUNK_NAME;

#   define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_UNROLLING, <qsboost/mpl/aux_/reverse_fold_impl_body.hpp>))
#   include QSBOOST_PP_ITERATE()

// implementation for N that exceeds BOOST_MPL_LIMIT_UNROLLING
template< QSBOOST_MPL_AUX_NTTP_DECL(long, N) > 
struct AUX778076_FOLD_CHUNK_NAME
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        > 
    struct result_
    {
        typedef First iter0;
        typedef State fwd_state0;

        QSBOOST_MPL_PP_REPEAT(
              QSBOOST_MPL_LIMIT_UNROLLING
            , AUX778076_ITER_FOLD_FORWARD_STEP
            , unused
            )

        typedef AUX778076_FOLD_IMPL_NAME<
              ( (N - QSBOOST_MPL_LIMIT_UNROLLING) < 0 ? 0 : N - QSBOOST_MPL_LIMIT_UNROLLING )
            , QSBOOST_PP_CAT(iter,QSBOOST_MPL_LIMIT_UNROLLING)
            , Last
            , QSBOOST_PP_CAT(fwd_state,QSBOOST_MPL_LIMIT_UNROLLING)
            , BackwardOp
            , ForwardOp
            > nested_chunk;
            
        AUX778076_FIRST_BACKWARD_STATE_TYPEDEF(QSBOOST_MPL_LIMIT_UNROLLING)

        QSBOOST_MPL_PP_REPEAT(
              QSBOOST_MPL_LIMIT_UNROLLING
            , AUX778076_ITER_FOLD_BACKWARD_STEP
            , QSBOOST_MPL_LIMIT_UNROLLING
            )

        typedef bkwd_state0 state;
        typedef typename nested_chunk::iterator iterator;
    };
};

// fallback implementation for sequences of unknown size
template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step);

template<
      typename Last
    , typename State
    >
struct QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_null_step)
{
    typedef Last iterator;
    typedef State state;
};

template<> 
struct AUX778076_FOLD_CHUNK_NAME<-1>
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        > 
    struct result_
    {
        typedef typename if_<
              typename is_same<First,Last>::type
            , QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_null_step)<Last,State>
            , QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)<First,Last,State,BackwardOp,ForwardOp>
            >::type res_;

        typedef typename res_::state state;
        typedef typename res_::iterator iterator;
    };

#if defined(QSBOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int,int>
    {
        typedef int state;
        typedef int iterator;
    };
#endif
};

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct QSBOOST_PP_CAT(AUX778076_FOLD_IMPL_NAME_PREFIX,_step)
{
    typedef AUX778076_FOLD_CHUNK_NAME<-1>::template result_<
          typename mpl::next<First>::type
        , Last
        , typename apply2<ForwardOp,State,AUX778076_FOLD_IMPL_OP(First)>::type
        , BackwardOp
        , ForwardOp
        > nested_step;

    typedef typename apply2<
          BackwardOp
        , typename nested_step::state
        , AUX778076_FOLD_IMPL_OP(First)
        >::type state;

    typedef typename nested_step::iterator iterator;
};

template<
      QSBOOST_MPL_AUX_NTTP_DECL(long, N)
    , typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    > 
struct AUX778076_FOLD_IMPL_NAME
    : AUX778076_FOLD_CHUNK_NAME<N>
        ::template result_<First,Last,State,BackwardOp,ForwardOp>
{
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

}}}

#   undef AUX778076_FIRST_BACKWARD_STATE_TYPEDEF
#   undef AUX778076_ITER_FOLD_BACKWARD_STEP
#   undef AUX778076_ITER_FOLD_BACKWARD_STEP_FUNC
#   undef AUX778076_ITER_FOLD_FORWARD_STEP

#undef AUX778076_FOLD_IMPL_OP
#undef AUX778076_FOLD_IMPL_NAME_PREFIX

///// iteration

#else

#   define n_ QSBOOST_PP_FRAME_ITERATION(1)

#if !defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION) \
    && !defined(QSBOOST_MPL_CFG_NO_NONTYPE_TEMPLATE_PARTIAL_SPEC)

template<
      typename First
    , typename Last
    , typename State
    , typename BackwardOp
    , typename ForwardOp
    >
struct AUX778076_FOLD_IMPL_NAME<n_,First,Last,State,BackwardOp,ForwardOp>
{
    typedef First iter0;
    typedef State fwd_state0;

    QSBOOST_MPL_PP_REPEAT(
          n_
        , AUX778076_ITER_FOLD_FORWARD_STEP
        , unused
        )

    typedef QSBOOST_PP_CAT(fwd_state,n_) QSBOOST_PP_CAT(bkwd_state,n_);

    QSBOOST_MPL_PP_REPEAT(
          n_
        , AUX778076_ITER_FOLD_BACKWARD_STEP
        , n_
        )

    typedef bkwd_state0 state;
    typedef QSBOOST_PP_CAT(iter,n_) iterator;
};

#else

template<> struct AUX778076_FOLD_CHUNK_NAME<n_>
{
    template<
          typename First
        , typename Last
        , typename State
        , typename BackwardOp
        , typename ForwardOp
        >
    struct result_
    {
        typedef First iter0;
        typedef State fwd_state0;

        QSBOOST_MPL_PP_REPEAT(
              n_
            , AUX778076_ITER_FOLD_FORWARD_STEP
            , unused
            )

        typedef QSBOOST_PP_CAT(fwd_state,n_) QSBOOST_PP_CAT(bkwd_state,n_);

        QSBOOST_MPL_PP_REPEAT(
              n_
            , AUX778076_ITER_FOLD_BACKWARD_STEP
            , n_
            )

        typedef bkwd_state0 state;
        typedef QSBOOST_PP_CAT(iter,n_) iterator;
    };

#if defined(QSBOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct result_<int,int,int,int,int>
    {
        typedef int state;
        typedef int iterator;
    };
#endif
};

#endif // BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION

#   undef n_

#endif // BOOST_PP_IS_ITERATING

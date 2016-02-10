
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED
#define QSBOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED

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
#   include <qsboost/mpl/next.hpp>
#   include <qsboost/mpl/apply_wrap.hpp>
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if    !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER advance_forward.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/unrolling.hpp>
#   include <qsboost/mpl/aux_/nttp_decl.hpp>
#   include <qsboost/mpl/aux_/config/eti.hpp>

#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>
#   include <qsboost/preprocessor/inc.hpp>

namespace qsboost { namespace mpl { namespace aux {

// forward declaration
template< QSBOOST_MPL_AUX_NTTP_DECL(long, N) > struct advance_forward;

#   define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(0, QSBOOST_MPL_LIMIT_UNROLLING, <qsboost/mpl/aux_/advance_forward.hpp>))
#   include QSBOOST_PP_ITERATE()

// implementation for N that exceeds BOOST_MPL_LIMIT_UNROLLING
template< QSBOOST_MPL_AUX_NTTP_DECL(long, N) > 
struct advance_forward
{
    template< typename Iterator > struct apply
    {
        typedef typename apply_wrap1<
              advance_forward<QSBOOST_MPL_LIMIT_UNROLLING>
            , Iterator
            >::type chunk_result_;

        typedef typename apply_wrap1<
              advance_forward<(
                (N - QSBOOST_MPL_LIMIT_UNROLLING) < 0
                    ? 0
                    : N - QSBOOST_MPL_LIMIT_UNROLLING
                    )>
            , chunk_result_
            >::type type;
    };
};

}}}

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_AUX_ADVANCE_FORWARD_HPP_INCLUDED

///// iteration, depth == 1

// For gcc 4.4 compatability, we must include the
// BOOST_PP_ITERATION_DEPTH test inside an #else clause.
#else // BOOST_PP_IS_ITERATING
#if QSBOOST_PP_ITERATION_DEPTH() == 1
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

template<>
struct advance_forward< QSBOOST_PP_FRAME_ITERATION(1) >
{
    template< typename Iterator > struct apply
    {
        typedef Iterator iter0;

#if i_ > 0
#   define QSBOOST_PP_ITERATION_PARAMS_2 \
    (3,(1, i_, <qsboost/mpl/aux_/advance_forward.hpp>))
#   include QSBOOST_PP_ITERATE()
#endif
        typedef QSBOOST_PP_CAT(iter,i_) type;
    };

#if defined(QSBOOST_MPL_CFG_MSVC_60_ETI_BUG)
    /// ETI workaround
    template<> struct apply<int>
    {
        typedef int type;
    };
#endif
};

#undef i_

///// iteration, depth == 2

#elif QSBOOST_PP_ITERATION_DEPTH() == 2

#   define AUX778076_ITER_0 QSBOOST_PP_CAT(iter,QSBOOST_PP_DEC(QSBOOST_PP_FRAME_ITERATION(2)))
#   define AUX778076_ITER_1 QSBOOST_PP_CAT(iter,QSBOOST_PP_FRAME_ITERATION(2))

        typedef typename next<AUX778076_ITER_0>::type AUX778076_ITER_1;
        
#   undef AUX778076_ITER_1
#   undef AUX778076_ITER_0

#endif // BOOST_PP_ITERATION_DEPTH()
#endif // BOOST_PP_IS_ITERATING

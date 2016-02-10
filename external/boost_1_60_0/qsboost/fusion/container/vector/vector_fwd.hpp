/*=============================================================================
    Copyright (c) 2014-2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_VECTOR_FORWARD_11052014_1626
#define QSBOOSTFUSION_VECTOR_FORWARD_11052014_1626

#include <qsboost/config.hpp>
#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/detail/config.hpp>

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <qsboost/fusion/container/vector/detail/cpp03/vector_fwd.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>

namespace qsboost { namespace fusion
{
    template <typename ...T>
    struct vector;

#define FUSION_VECTOR_N_ALIASES(z, N, d)                                    \
    template <typename ...T>                                                \
    using QSBOOST_PP_CAT(vector, N) = vector<T...>;

    QSBOOST_PP_REPEAT(51, FUSION_VECTOR_N_ALIASES, ~)

#undef FUSION_VECTOR_N_ALIASES
}}

#endif
#endif


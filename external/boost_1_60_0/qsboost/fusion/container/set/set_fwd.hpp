/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_SET_FORWARD_11062014_1720
#define QSBOOSTFUSION_SET_FORWARD_11062014_1720

#include <qsboost/config.hpp>
#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/detail/config.hpp>

#if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR) \
  || (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_SET)
#   undef QSBOOST_FUSION_HAS_VARIADIC_SET
# endif
#else
# if !defined(QSBOOST_FUSION_HAS_VARIADIC_SET)
#   define QSBOOST_FUSION_HAS_VARIADIC_SET
# endif
#endif

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_SET)
# include <qsboost/fusion/container/set/detail/cpp03/set_fwd.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace fusion
{
    struct set_tag;
    struct set_iterator_tag;

    template <typename ...T>
    struct set;
}}

#endif
#endif


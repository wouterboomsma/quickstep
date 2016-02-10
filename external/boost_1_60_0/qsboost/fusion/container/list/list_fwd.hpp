/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_LIST_FORWARD_10262014_0528
#define QSBOOSTFUSION_LIST_FORWARD_10262014_0528

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/config.hpp>

#if  defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) \
  || (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_LIST)
#   undef QSBOOST_FUSION_HAS_VARIADIC_LIST
# endif
#else
# if !defined(QSBOOST_FUSION_HAS_VARIADIC_LIST)
#   define QSBOOST_FUSION_HAS_VARIADIC_LIST
# endif
#endif

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_LIST)
# include <qsboost/fusion/container/list/detail/cpp03/list_fwd.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace fusion
{
    struct void_;

    template <typename ...T>
    struct list;
}}

#endif
#endif

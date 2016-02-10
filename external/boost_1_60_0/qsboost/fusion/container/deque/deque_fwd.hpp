/*=============================================================================
    Copyright (c) 2005-2012 Joel de Guzman
    Copyright (c) 2005-2007 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_DEQUE_FORWARD_02092007_0749)
#define FUSION_DEQUE_FORWARD_02092007_0749

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/config.hpp>

#if (defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES)   \
  || defined(QSBOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS))   \
  || (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_DEQUE)
#   undef QSBOOST_FUSION_HAS_VARIADIC_DEQUE
# endif
#else
# if !defined(QSBOOST_FUSION_HAS_VARIADIC_DEQUE)
#   define QSBOOST_FUSION_HAS_VARIADIC_DEQUE
# endif
#endif

// MSVC variadics at this point in time is not ready yet (ICE!)
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1900))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_DEQUE)
#   undef QSBOOST_FUSION_HAS_VARIADIC_DEQUE
# endif
#endif

///////////////////////////////////////////////////////////////////////////////
// With no variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_DEQUE)
# include <qsboost/fusion/container/deque/detail/cpp03/deque_fwd.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace fusion
{
    template <typename ...T>
    struct deque;
}}

#endif
#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_MAP_FORWARD_MAIN_07212005_1105)
#define FUSION_MAP_FORWARD_MAIN_07212005_1105

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/config.hpp>

#if (defined(QSBOOST_NO_CXX11_DECLTYPE)             \
  || defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES)   \
  || defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES))   \
  || (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_MAP)
#   undef QSBOOST_FUSION_HAS_VARIADIC_MAP
# endif
#else
# if !defined(QSBOOST_FUSION_HAS_VARIADIC_MAP)
#   define QSBOOST_FUSION_HAS_VARIADIC_MAP
# endif
#endif

// MSVC variadics at this point in time is not ready yet (ICE!)
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1900))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_MAP)
#   undef QSBOOST_FUSION_HAS_VARIADIC_MAP
# endif
#endif

///////////////////////////////////////////////////////////////////////////////
// With no decltype and variadics, we will use the C++03 version
///////////////////////////////////////////////////////////////////////////////
#if !defined(QSBOOST_FUSION_HAS_VARIADIC_MAP)
# include <qsboost/fusion/container/map/detail/cpp03/map_fwd.hpp>
#else

#include <qsboost/fusion/container/map/detail/map_impl.hpp>

///////////////////////////////////////////////////////////////////////////////
// C++11 interface
///////////////////////////////////////////////////////////////////////////////
namespace qsboost { namespace fusion
{
    template <typename ...T>
    struct map;
}}

#endif
#endif

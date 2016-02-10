/*=============================================================================
    Copyright (c) 2014-2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_VECTOR_CONFIG_11052014_1720
#define QSBOOSTFUSION_VECTOR_CONFIG_11052014_1720

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/fusion/support/config.hpp>

#if (defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) \
  || defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) \
  || defined(QSBOOST_NO_CXX11_TEMPLATE_ALIASES)  \
  || defined(QSBOOST_NO_CXX11_DECLTYPE)) \
  || (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
#   undef QSBOOST_FUSION_HAS_VARIADIC_VECTOR
# endif
#else
# if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
#   define QSBOOST_FUSION_HAS_VARIADIC_VECTOR
# endif
#endif

// Sometimes, MSVC 12 shows compile error with std::size_t of template parameter.
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1800))
# if defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
#   undef QSBOOST_FUSION_HAS_VARIADIC_VECTOR
# endif
#endif

#endif


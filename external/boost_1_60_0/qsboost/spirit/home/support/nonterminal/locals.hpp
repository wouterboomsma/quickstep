/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_LOCALS_APRIL_03_2007_0506PM)
#define QSBOOST_SPIRIT_LOCALS_APRIL_03_2007_0506PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/mpl/vector.hpp>
#include <qsboost/mpl/bool.hpp>

#if !defined(QSBOOST_SPIRIT_MAX_LOCALS_SIZE)
# define QSBOOST_SPIRIT_MAX_LOCALS_SIZE 10
#else
# if QSBOOST_SPIRIT_MAX_LOCALS_SIZE < 3
#   undef QSBOOST_SPIRIT_MAX_LOCALS_SIZE
#   define QSBOOST_SPIRIT_MAX_LOCALS_SIZE 10
# endif
#endif

namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    template <
        QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
            QSBOOST_SPIRIT_MAX_LOCALS_SIZE, typename T, mpl::na)
    >
    struct locals
      : mpl::vector<QSBOOST_PP_ENUM_PARAMS(QSBOOST_SPIRIT_MAX_LOCALS_SIZE, T)> {};

    ///////////////////////////////////////////////////////////////////////////
    namespace detail
    {
        template <typename T>
        struct is_locals
          : mpl::false_
        {};

        template <QSBOOST_PP_ENUM_PARAMS(QSBOOST_SPIRIT_MAX_LOCALS_SIZE, typename T)>
        struct is_locals<locals<QSBOOST_PP_ENUM_PARAMS(QSBOOST_SPIRIT_MAX_LOCALS_SIZE, T)> >
          : mpl::true_
        {};
    }
}}

#endif

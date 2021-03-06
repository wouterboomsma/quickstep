#ifndef QSBOOST_PP_IS_ITERATING
/*=============================================================================
    Copyright (c) 2011 Eric Niebler
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_VECTOR20_FWD_HPP_INCLUDED)
#define QSBOOST_FUSION_VECTOR20_FWD_HPP_INCLUDED

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/iteration/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/vector/detail/cpp03/preprocessed/vector20_fwd.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vector20_fwd.hpp")
#endif

/*=============================================================================
    Copyright (c) 2011 Eric Niebler
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace qsboost { namespace fusion
{
    // expand vector11 to vector20
    #define QSBOOST_PP_FILENAME_1 <qsboost/fusion/container/vector/detail/cpp03/vector20_fwd.hpp>
    #define QSBOOST_PP_ITERATION_LIMITS (11, 20)
    #include QSBOOST_PP_ITERATE()
}}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif

#else

    template <QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_ITERATION(), typename T)>
    struct QSBOOST_PP_CAT(vector, QSBOOST_PP_ITERATION());

#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2007 Dan Marsden
    Copyright (c) 2009-2010 Christopher Schmidt
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_FUSION_ALGORITHM_ITERATION_FOLD_HPP
#define QSBOOST_FUSION_ALGORITHM_ITERATION_FOLD_HPP

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/algorithm/iteration/fold_fwd.hpp>
#include <qsboost/config.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/sequence/intrinsic/size.hpp>
#include <qsboost/fusion/support/is_segmented.hpp>
#include <qsboost/fusion/support/is_sequence.hpp>
#include <qsboost/fusion/iterator/deref.hpp>
#include <qsboost/fusion/iterator/value_of.hpp>
#include <qsboost/fusion/iterator/next.hpp>
#include <qsboost/utility/result_of.hpp>
#include <qsboost/core/enable_if.hpp>
#include <qsboost/type_traits/add_reference.hpp>

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/algorithm/iteration/detail/preprocessed/fold.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "detail/preprocessed/fold.hpp")
#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2007 Dan Marsden
    Copyright (c) 2009-2010 Christopher Schmidt

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#include <qsboost/fusion/algorithm/iteration/detail/fold.hpp>

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#include <qsboost/fusion/algorithm/iteration/detail/segmented_fold.hpp>

#endif

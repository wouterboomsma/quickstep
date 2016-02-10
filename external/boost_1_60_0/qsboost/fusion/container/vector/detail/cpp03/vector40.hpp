/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VECTOR40_05052005_0208)
#define FUSION_VECTOR40_05052005_0208

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/detail/cpp03/vector40_fwd.hpp>
#include <qsboost/fusion/support/sequence_base.hpp>
#include <qsboost/fusion/support/is_sequence.hpp>
#include <qsboost/fusion/support/detail/access.hpp>
#include <qsboost/fusion/iterator/next.hpp>
#include <qsboost/fusion/iterator/deref.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/fusion/container/vector/detail/at_impl.hpp>
#include <qsboost/fusion/container/vector/detail/value_at_impl.hpp>
#include <qsboost/fusion/container/vector/detail/begin_impl.hpp>
#include <qsboost/fusion/container/vector/detail/end_impl.hpp>

#include <qsboost/mpl/void.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/at.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/vector/vector40.hpp>
#include <qsboost/type_traits/is_convertible.hpp>
#include <qsboost/utility/enable_if.hpp>

#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/iteration/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_shifted.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/vector/detail/cpp03/preprocessed/vector40.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vector40.hpp")
#endif

/*=============================================================================
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
    struct vector_tag;
    struct fusion_sequence_tag;
    struct random_access_traversal_tag;

#define FUSION_HASH #
// expand vector31 to vector40
#define QSBOOST_PP_FILENAME_1 <qsboost/fusion/container/vector/detail/cpp03/vector_n.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (31, 40)
#include QSBOOST_PP_ITERATE()
#undef FUSION_HASH
}}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#endif


/*==============================================================================
    Copyright (c) 2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(QSBOOST_PHOENIX_PREPROCESSED_CONSTRUCT)
#define QSBOOST_PHOENIX_PREPROCESSED_CONSTRUCT

#if QSBOOST_PHOENIX_LIMIT <= 10
#include <qsboost/phoenix/object/detail/preprocessed/construct_10.hpp>
#elif QSBOOST_PHOENIX_LIMIT <= 20
#include <qsboost/phoenix/object/detail/preprocessed/construct_20.hpp>
#elif QSBOOST_PHOENIX_LIMIT <= 30
#include <qsboost/phoenix/object/detail/preprocessed/construct_30.hpp>
#elif QSBOOST_PHOENIX_LIMIT <= 40
#include <qsboost/phoenix/object/detail/preprocessed/construct_40.hpp>
#elif QSBOOST_PHOENIX_LIMIT <= 50
#include <qsboost/phoenix/object/detail/preprocessed/construct_50.hpp>
#else
#error "BOOST_PHOENIX_LIMIT out of bounds for preprocessed headers"
#endif

#endif

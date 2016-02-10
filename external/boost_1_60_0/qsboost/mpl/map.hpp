
#ifndef QSBOOST_MPL_MAP_HPP_INCLUDED
#define QSBOOST_MPL_MAP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
#   include <qsboost/mpl/limits/map.hpp>
#   include <qsboost/mpl/aux_/na.hpp>
#   include <qsboost/mpl/aux_/config/preprocessor.hpp>

#   include <qsboost/preprocessor/inc.hpp>
#   include <qsboost/preprocessor/cat.hpp>
#   include <qsboost/preprocessor/stringize.hpp>

#if !defined(QSBOOST_NEEDS_TOKEN_PASTING_OP_FOR_TOKENS_JUXTAPOSING)
#   define AUX778076_MAP_HEADER \
    QSBOOST_PP_CAT(map, QSBOOST_MPL_LIMIT_MAP_SIZE).hpp \
    /**/
#else
#   define AUX778076_MAP_HEADER \
    QSBOOST_PP_CAT(map, QSBOOST_MPL_LIMIT_MAP_SIZE)##.hpp \
    /**/
#endif

#   include QSBOOST_PP_STRINGIZE(qsboost/mpl/map/AUX778076_MAP_HEADER)
#   undef AUX778076_MAP_HEADER
#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
    && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER map.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/limits/map.hpp>

#   define AUX778076_SEQUENCE_NAME map
#   define AUX778076_SEQUENCE_LIMIT QSBOOST_MPL_LIMIT_MAP_SIZE
#   include <qsboost/mpl/aux_/sequence_wrapper.hpp>

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_MAP_HPP_INCLUDED

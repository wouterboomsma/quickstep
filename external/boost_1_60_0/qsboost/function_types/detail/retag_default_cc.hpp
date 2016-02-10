
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_DETAIL_RETAG_DEFAULT_CC_HPP_INCLUDED
#define QSBOOST_FT_DETAIL_RETAG_DEFAULT_CC_HPP_INCLUDED

#include <qsboost/mpl/bitand.hpp>

#include <qsboost/function_types/components.hpp>

#if defined(QSBOOST_FT_PREPROCESSING_MODE)
#   include <qsboost/function_types/detail/pp_retag_default_cc/master.hpp>
#else
#   include <qsboost/function_types/detail/pp_retag_default_cc/preprocessed.hpp>
#endif

#endif


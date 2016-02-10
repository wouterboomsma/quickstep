
#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_MPL_PLACEHOLDERS_HPP_INCLUDED
#define QSBOOST_MPL_PLACEHOLDERS_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
// Copyright Peter Dimov 2001-2003
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
#   include <qsboost/mpl/arg.hpp>
#   include <qsboost/mpl/aux_/adl_barrier.hpp>

#   if !defined(QSBOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE)
#       define QSBOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(type) \
        using ::QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::type; \
        /**/
#   else
#       define QSBOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(type) /**/
#   endif

#endif

#include <qsboost/mpl/aux_/config/use_preprocessed.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_PREPROCESSED_HEADERS) \
 && !defined(QSBOOST_MPL_PREPROCESSING_MODE)

#   define QSBOOST_MPL_PREPROCESSED_HEADER placeholders.hpp
#   include <qsboost/mpl/aux_/include_preprocessed.hpp>

#else

#   include <qsboost/mpl/aux_/nttp_decl.hpp>
#   include <qsboost/mpl/limits/arity.hpp>
#   include <qsboost/preprocessor/iterate.hpp>
#   include <qsboost/preprocessor/cat.hpp>

// watch out for GNU gettext users, who #define _(x)
#if !defined(_) || defined(QSBOOST_MPL_CFG_NO_UNNAMED_PLACEHOLDER_SUPPORT)
QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN
typedef arg<-1> _;
QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

namespace qsboost { namespace mpl { 

QSBOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(_)

namespace placeholders {
using QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::_;
}

}}
#endif

/// agurt, 17/mar/02: one more placeholder for the last 'apply#' 
/// specialization
#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3,(1, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY + 1, <qsboost/mpl/placeholders.hpp>))
#include QSBOOST_PP_ITERATE()

#endif // BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#endif // BOOST_MPL_PLACEHOLDERS_HPP_INCLUDED

///// iteration

#else
#define i_ QSBOOST_PP_FRAME_ITERATION(1)

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

typedef arg<i_> QSBOOST_PP_CAT(_,i_);

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

namespace qsboost { namespace mpl { 

QSBOOST_MPL_AUX_ARG_ADL_BARRIER_DECL(QSBOOST_PP_CAT(_,i_))

namespace placeholders {
using QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::QSBOOST_PP_CAT(_,i_);
}

}}

#undef i_
#endif // BOOST_PP_IS_ITERATING

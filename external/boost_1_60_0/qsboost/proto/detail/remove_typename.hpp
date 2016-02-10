//==============================================================================
//         Copyright 2003 - 2011  LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011  LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011         Eric Niebler
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef QSBOOST_PROTO_PREPROCESSOR_REMOVE_TYPENAME_HPP_INCLUDED
#define QSBOOST_PROTO_PREPROCESSOR_REMOVE_TYPENAME_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the BOOST_PROTO_REMOVE_TYPENAME macro
 */
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/expand.hpp>
#include <qsboost/preprocessor/tuple/eat.hpp>
#include <qsboost/preprocessor/control/iif.hpp>
#include <qsboost/preprocessor/detail/is_unary.hpp>

//==============================================================================
// Boost.Preprocessor author P. Mensodines confirmed on an Boost email thread
// (subject ``check if a token is a keyword (was "BOOST_PP_IS_UNARY()")'')
// that it is OK to used `PP_IS_UNARY()` to check if tokens match predefined
// "keyword" as it is done by the macros below (even if `PP_IS_UNARY()` is
// technically only part of Boost.Preprocessor private API).
//==============================================================================

//==============================================================================
// `checking_prefix ## tokens` expand to unary (e.g., `(1)`) iff `tokens` start
// with keyword to check.
//==============================================================================
#define QSBOOST_PROTO_DETAILS_KEYWORD_FACILITY_IS_FRONT(T, CHECKING_PREFIX)                           \
    QSBOOST_PP_IS_UNARY(QSBOOST_PP_CAT(CHECKING_PREFIX, T))                                             \
    /**/

//==============================================================================
// `is_front_macro(tokens)` is 1 iff `tokens` start with keyword to remove.
// `removing_prefix ## <keyword-to-remove>` must expand to nothing.
//==============================================================================
#define QSBOOST_PROTO_DETAILS_KEYWORD_FACILITY_REMOVE_FRONT(TOKENS, IS_FRONT_MACRO, REMOVING_PREFIX)  \
    QSBOOST_PP_EXPAND( /* without EXPAND doesn't expand on MSVC */                                    \
        QSBOOST_PP_IIF(                                                                               \
            IS_FRONT_MACRO(TOKENS)                                                                  \
          , QSBOOST_PP_CAT                                                                            \
          , TOKENS QSBOOST_PP_TUPLE_EAT(2)                                                            \
        )(REMOVING_PREFIX, TOKENS)                                                                  \
    )                                                                                               \
    /**/

#define QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_IS_typename (1) /* unary */
#define typename_QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_IS (1) /* unary */
#define QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_REMOVE_typename /* nothing */
#define typename_QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_REMOVE /* nothing */

#define QSBOOST_PROTO_DETAILS_KEYWORD_IS_TYPENAME_FRONT(TOKENS)                                       \
    QSBOOST_PROTO_DETAILS_KEYWORD_FACILITY_IS_FRONT(TOKENS, QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_IS_) \
    /**/

//==============================================================================
/*!
 * \ingroup preprocessor
 * For any symbol \c X, this macro returns the same symbol from which a potential
 * leading \c typename keyword has been removed. If no typename keyword is present,
 * this macros evaluates to \c X itself without error.
 *
 * The original implementation of this macro is from Lorenzo Caminiti.
 *
 * \param X Symbol to remove \c typename from
 */
//==============================================================================
#define QSBOOST_PROTO_REMOVE_TYPENAME(X)                                                              \
    QSBOOST_PROTO_DETAILS_KEYWORD_FACILITY_REMOVE_FRONT(                                              \
        X                                                                                           \
      , QSBOOST_PROTO_DETAILS_KEYWORD_IS_TYPENAME_FRONT                                               \
      , QSBOOST_PROTO_DETAILS_KEYWORD_TYPENAME_REMOVE_                                                \
    )                                                                                               \
    /**/

#endif

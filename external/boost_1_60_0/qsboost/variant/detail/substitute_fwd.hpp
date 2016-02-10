//-----------------------------------------------------------------------------
// boost variant/detail/substitute_fwd.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003
// Eric Friedman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP
#define QSBOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP

#include "qsboost/mpl/aux_/lambda_arity_param.hpp"
#include "qsboost/mpl/aux_/template_arity.hpp"
#include "qsboost/mpl/int_fwd.hpp"


///////////////////////////////////////////////////////////////////////////////
// BOOST_VARIANT_DETAIL_NO_SUBSTITUTE
//
// Defined if 'substitute' is not implementable on the current compiler.
//

#include "qsboost/mpl/aux_/config/ctps.hpp"
#include "qsboost/mpl/aux_/config/ttp.hpp"

#if defined(QSBOOST_NO_TEMPLATE_TEMPLATE_PARAMETERS) \
 && !defined(QSBOOST_VARIANT_DETAIL_NO_SUBSTITUTE)
#   define QSBOOST_VARIANT_DETAIL_NO_SUBSTITUTE
#endif

namespace qsboost {
namespace detail { namespace variant {

#if !defined(QSBOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

///////////////////////////////////////////////////////////////////////////////
// metafunction substitute
//
// Substitutes one type for another in the given type expression.
//
template <
      typename T, typename Dest, typename Source
      QSBOOST_MPL_AUX_LAMBDA_ARITY_PARAM(
          typename Arity = mpl::int_< mpl::aux::template_arity<T>::value >
        )
    >
struct substitute;

#endif // !defined(BOOST_VARIANT_DETAIL_NO_SUBSTITUTE)

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_SUBSTITUTE_FWD_HPP

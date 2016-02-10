//-----------------------------------------------------------------------------
// boost variant/detail/make_variant_list.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003 Eric Friedman, Itay Maman
// Copyright (c) 2013 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_MAKE_VARIANT_LIST_HPP
#define QSBOOST_VARIANT_DETAIL_MAKE_VARIANT_LIST_HPP

#include "qsboost/variant/variant_fwd.hpp"

#include "qsboost/mpl/list.hpp"
#include "qsboost/preprocessor/cat.hpp"
#include "qsboost/preprocessor/enum.hpp"

namespace qsboost {
namespace detail { namespace variant {

///////////////////////////////////////////////////////////////////////////////
// (detail) metafunction make_variant_list
//
// Provides a MPL-compatible sequence with the specified non-void types
// as arguments.
//
// Rationale: see class template convert_void (variant_fwd.hpp) and using-
// declaration workaround (below).
//

#if !defined(QSBOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)

template < typename... T >
struct make_variant_list
{
    typedef typename mpl::list< T... >::type type;
};

#else // defined(BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES)

template < QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
struct make_variant_list
{
public: // metafunction result

    // [Define a macro to convert any void(NN) tags to mpl::void...]
#   define QSBOOST_VARIANT_AUX_CONVERT_VOID(z, N,_)  \
        typename convert_void< QSBOOST_PP_CAT(T,N) >::type

    // [...so that the specified types can be passed to mpl::list...]
    typedef typename mpl::list< 
          QSBOOST_PP_ENUM(
              QSBOOST_VARIANT_LIMIT_TYPES
            , QSBOOST_VARIANT_AUX_CONVERT_VOID
            , _
            )
        >::type type;

    // [...and, finally, the conversion macro can be undefined:]
#   undef QSBOOST_VARIANT_AUX_CONVERT_VOID

};

#endif // BOOST_VARIANT_DO_NOT_USE_VARIADIC_TEMPLATES workaround

}} // namespace detail::variant
} // namespace boost

#endif // BOOST_VARIANT_DETAIL_MAKE_VARIANT_LIST_HPP

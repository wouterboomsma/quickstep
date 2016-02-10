//-----------------------------------------------------------------------------
// boost variant/recursive_wrapper_fwd.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002
// Eric Friedman, Itay Maman
//
// Portions Copyright (C) 2002 David Abrahams
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP
#define QSBOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP

#include "qsboost/mpl/aux_/config/ctps.hpp"
#include "qsboost/mpl/aux_/lambda_support.hpp"
#include <qsboost/type_traits/integral_constant.hpp>

namespace qsboost {

//////////////////////////////////////////////////////////////////////////
// class template recursive_wrapper
//
// Enables recursive types in templates by breaking cyclic dependencies.
//
// For example:
//
//   class my;
//
//   typedef variant< int, recursive_wrapper<my> > var;
//
//   class my {
//     var var_;
//     ...
//   };
//
template <typename T> class recursive_wrapper;

///////////////////////////////////////////////////////////////////////////////
// metafunction is_recursive_wrapper (modeled on code by David Abrahams)
//
// True iff specified type matches recursive_wrapper<T>.
//

namespace detail {


template <typename T>
struct is_recursive_wrapper_impl
    : mpl::false_
{
};

template <typename T>
struct is_recursive_wrapper_impl< recursive_wrapper<T> >
    : mpl::true_
{
};


} // namespace detail

template< typename T > struct is_recursive_wrapper
    : public ::qsboost::integral_constant<bool,(::qsboost::detail::is_recursive_wrapper_impl<T>::value)>
{
public:
    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,is_recursive_wrapper,(T))
};

///////////////////////////////////////////////////////////////////////////////
// metafunction unwrap_recursive
//
// If specified type T matches recursive_wrapper<U>, then U; else T.
//


template <typename T>
struct unwrap_recursive
{
    typedef T type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1,unwrap_recursive,(T))
};

template <typename T>
struct unwrap_recursive< recursive_wrapper<T> >
{
    typedef T type;

    QSBOOST_MPL_AUX_LAMBDA_SUPPORT_SPEC(1,unwrap_recursive,(T))
};


} // namespace boost

#endif // BOOST_VARIANT_RECURSIVE_WRAPPER_FWD_HPP

//-----------------------------------------------------------------------------
// boost variant/detail/apply_visitor_unary.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003 Eric Friedman
// Copyright (c) 2014 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP
#define QSBOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP

#include "qsboost/config.hpp"
#include "qsboost/detail/workaround.hpp"
#include "qsboost/variant/detail/generic_result_type.hpp"

#if QSBOOST_WORKAROUND(__EDG__, QSBOOST_TESTED_AT(302))
#include "qsboost/core/enable_if.hpp"
#include "qsboost/mpl/not.hpp"
#include "qsboost/type_traits/is_const.hpp"
#endif

#if !defined(QSBOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(QSBOOST_NO_CXX11_DECLTYPE_N3276)
#   include <qsboost/mpl/distance.hpp>
#   include <qsboost/mpl/advance.hpp>
#   include <qsboost/mpl/deref.hpp>
#   include <qsboost/mpl/size.hpp>
#   include <qsboost/utility/declval.hpp>
#   include <qsboost/core/enable_if.hpp>
#   include "qsboost/variant/detail/has_result_type.hpp"
#endif

namespace qsboost {

//////////////////////////////////////////////////////////////////////////
// function template apply_visitor(visitor, visitable)
//
// Visits visitable with visitor.
//

//
// nonconst-visitor version:
//

#if !QSBOOST_WORKAROUND(__EDG__, QSBOOST_TESTED_AT(302))

#   define QSBOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    QSBOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
    /**/

#else // EDG-based compilers

#   define QSBOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(V) \
    typename enable_if< \
          mpl::not_< is_const< V > > \
        , QSBOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename V::result_type) \
        >::type \
    /**/

#endif // EDG-based compilers workaround

template <typename Visitor, typename Visitable>
inline
    QSBOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE(Visitor)
apply_visitor(Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}

#undef QSBOOST_VARIANT_AUX_APPLY_VISITOR_NON_CONST_RESULT_TYPE

//
// const-visitor version:
//

template <typename Visitor, typename Visitable>
inline
    QSBOOST_VARIANT_AUX_GENERIC_RESULT_TYPE(typename Visitor::result_type)
apply_visitor(const Visitor& visitor, Visitable& visitable)
{
    return visitable.apply_visitor(visitor);
}


#if !defined(QSBOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(QSBOOST_NO_CXX11_DECLTYPE_N3276)

// C++14
namespace detail { namespace variant {

// This class serves only metaprogramming purposes. none of its methods must be called at runtime!
template <class Visitor, class Variant>
struct result_multideduce1 {
    typedef typename Variant::types                 types;
    typedef typename qsboost::mpl::begin<types>::type begin_it;
    typedef typename qsboost::mpl::advance<
        begin_it, qsboost::mpl::int_<qsboost::mpl::size<types>::type::value - 1>
    >::type                                         last_it;

    // For metaprogramming purposes ONLY! Do not use this method (and class) at runtime!
    static Visitor& vis() QSBOOST_NOEXCEPT {
        // Functions that work with lambdas must be defined in same translation unit.
        // Because of that, we can not use `boost::decval<Visitor&>()` here.
        Visitor&(*f)() = 0; // pointer to function
        return f();
    }

    static decltype(auto) deduce_impl(last_it, unsigned /*helper*/) {
        typedef typename qsboost::mpl::deref<last_it>::type value_t;
        return vis()( qsboost::declval< value_t& >() );
    }

    template <class It>
    static decltype(auto) deduce_impl(It, unsigned helper) {
        typedef typename qsboost::mpl::next<It>::type next_t;
        typedef typename qsboost::mpl::deref<It>::type value_t;
        if (helper == qsboost::mpl::distance<begin_it, It>::type::value) {
            return deduce_impl(next_t(), ++helper);
        }

        return vis()( qsboost::declval< value_t& >() );
    }

    static decltype(auto) deduce() {
        return deduce_impl(begin_it(), 0);
    }
};

template <class Visitor, class Variant>
struct result_wrapper1
{
    typedef decltype(result_multideduce1<Visitor, Variant>::deduce()) result_type;

    Visitor& visitor_;
    explicit result_wrapper1(Visitor& visitor) QSBOOST_NOEXCEPT
        : visitor_(visitor)
    {}

    template <class T>
    result_type operator()(T& val) const {
        return visitor_(val);
    }
};

}} // namespace detail::variant

template <typename Visitor, typename Visitable>
inline decltype(auto) apply_visitor(Visitor& visitor, Visitable& visitable,
    typename qsboost::disable_if<
        qsboost::detail::variant::has_result_type<Visitor>
    >::type* = 0)
{
    qsboost::detail::variant::result_wrapper1<Visitor, Visitable> cpp14_vis(visitor);
    return visitable.apply_visitor(cpp14_vis);
}

template <typename Visitor, typename Visitable>
inline decltype(auto) apply_visitor(const Visitor& visitor, Visitable& visitable,
    typename qsboost::disable_if<
        qsboost::detail::variant::has_result_type<Visitor>
    >::type* = 0)
{
    qsboost::detail::variant::result_wrapper1<const Visitor, Visitable> cpp14_vis(visitor);
    return visitable.apply_visitor(cpp14_vis);
}

#endif // !defined(BOOST_NO_CXX14_DECLTYPE_AUTO) && !defined(BOOST_NO_CXX11_DECLTYPE_N3276)

} // namespace boost

#endif // BOOST_VARIANT_DETAIL_APPLY_VISITOR_UNARY_HPP

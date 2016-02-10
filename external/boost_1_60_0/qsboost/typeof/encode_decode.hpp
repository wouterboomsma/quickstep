// Copyright (C) 2004 Arkadiy Vertleyb

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// boostinspect:nounnamed

#ifndef QSBOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED
#define QSBOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED

#include <qsboost/mpl/deref.hpp>
#include <qsboost/mpl/next.hpp>

#ifndef QSBOOST_TYPEOF_SUPPRESS_UNNAMED_NAMESPACE

#   define QSBOOST_TYPEOF_BEGIN_ENCODE_NS namespace { namespace qsboost_typeof {
#   define QSBOOST_TYPEOF_END_ENCODE_NS }}
#   define QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER qsboost_typeof

#else

#   define QSBOOST_TYPEOF_BEGIN_ENCODE_NS namespace qsboost { namespace type_of {
#   define QSBOOST_TYPEOF_END_ENCODE_NS }}
#   define QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER qsboost::type_of

#   define QSBOOST_TYPEOF_TEXT "unnamed namespace is off"
#   include <qsboost/typeof/message.hpp>

#endif

QSBOOST_TYPEOF_BEGIN_ENCODE_NS

template<class V, class Type_Not_Registered_With_Typeof_System>
struct encode_type_impl;

template<class T, class Iter>
struct decode_type_impl
{
    typedef int type;  // MSVC ETI workaround
};

template<class T>
struct decode_nested_template_helper_impl;

QSBOOST_TYPEOF_END_ENCODE_NS

namespace qsboost { namespace type_of {

    template<class V, class T>
    struct encode_type : QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER::encode_type_impl<V, T>
    {};

    template<class Iter>
    struct decode_type : QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER::decode_type_impl<
        typename Iter::type,
        typename Iter::next
    >
    {};
}}

#endif//BOOST_TYPEOF_ENCODE_DECODE_HPP_INCLUDED

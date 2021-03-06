// Copyright (C) 2004 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_POINTERS_DATA_MEMBERS_HPP_INCLUDED
#define QSBOOST_TYPEOF_POINTERS_DATA_MEMBERS_HPP_INCLUDED

#include <qsboost/typeof/encode_decode_params.hpp>
#include <qsboost/typeof/encode_decode.hpp>

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_BEGIN_ENCODE_NS

enum {PTR_DATA_MEM_ID = QSBOOST_TYPEOF_UNIQUE_ID()};

template<class V, class P0, class P1>
struct encode_type_impl<V, P0 P1::*>
{
    typedef QSBOOST_TYPEOF_ENCODE_PARAMS(2, PTR_DATA_MEM_ID) type;
};

template<class Iter>
struct decode_type_impl<qsboost::mpl::size_t<PTR_DATA_MEM_ID>, Iter>
{
    typedef Iter iter0;
    QSBOOST_TYPEOF_DECODE_PARAMS(2)

    template<class T> struct workaround{
        typedef p0 T::* type;
    };
    typedef typename decode_type_impl<qsboost::mpl::size_t<PTR_DATA_MEM_ID>, Iter>::template workaround<p1>::type type;
    typedef iter2 iter;
};

QSBOOST_TYPEOF_END_ENCODE_NS

#endif//BOOST_TYPEOF_POINTERS_DATA_MEMBERS_HPP_INCLUDED

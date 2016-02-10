// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED
#define QSBOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>

// Assumes iter0 contains initial iterator

#define QSBOOST_TYPEOF_DECODE_PARAM(z, n, text)   \
    typedef qsboost::type_of::decode_type<iter##n> decode##n;     \
    typedef typename decode##n::type p##n;      \
    typedef typename decode##n::iter QSBOOST_PP_CAT(iter, QSBOOST_PP_INC(n));

#define QSBOOST_TYPEOF_DECODE_PARAMS(n)\
    QSBOOST_PP_REPEAT(n, QSBOOST_TYPEOF_DECODE_PARAM, ~)

// The P0, P1, ... PN are encoded and added to V 

#define QSBOOST_TYPEOF_ENCODE_PARAMS_BEGIN(z, n, text)\
    typename qsboost::type_of::encode_type<

#define QSBOOST_TYPEOF_ENCODE_PARAMS_END(z, n, text)\
    , QSBOOST_PP_CAT(P, n)>::type

#define QSBOOST_TYPEOF_ENCODE_PARAMS(n, ID)                   \
    QSBOOST_PP_REPEAT(n, QSBOOST_TYPEOF_ENCODE_PARAMS_BEGIN, ~) \
    typename qsboost::type_of::push_back<V, qsboost::mpl::size_t<ID> >::type      \
    QSBOOST_PP_REPEAT(n, QSBOOST_TYPEOF_ENCODE_PARAMS_END, ~)

#endif//BOOST_TYPEOF_ENCODE_DECODE_PARAMS_HPP_INCLUDED

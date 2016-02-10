// Copyright (C) 2004 Arkadiy Vertleyb
// Copyright (C) 2005 Peder Holt
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED
#define QSBOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing.hpp>
#include <qsboost/preprocessor/control/iif.hpp>
#include <qsboost/preprocessor/detail/is_unary.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/tuple/eat.hpp>
#include <qsboost/preprocessor/seq/transform.hpp>
#include <qsboost/preprocessor/seq/for_each_i.hpp>
#include <qsboost/preprocessor/seq/cat.hpp>

#include <qsboost/typeof/encode_decode.hpp>
#include <qsboost/typeof/int_encoding.hpp>

#include <qsboost/typeof/type_template_param.hpp>
#include <qsboost/typeof/integral_template_param.hpp>
#include <qsboost/typeof/template_template_param.hpp>

#ifdef __BORLANDC__
#define QSBOOST_TYPEOF_QUALIFY(P) self_t::P
#else
#define QSBOOST_TYPEOF_QUALIFY(P) P
#endif
// The template parameter description, entered by the user,
// is converted into a polymorphic "object"
// that is used to generate the code responsible for
// encoding/decoding the parameter, etc.

// make sure to cat the sequence first, and only then add the prefix.
#define QSBOOST_TYPEOF_MAKE_OBJ(elem) QSBOOST_PP_CAT(\
    QSBOOST_TYPEOF_MAKE_OBJ,\
    QSBOOST_PP_SEQ_CAT((_) QSBOOST_TYPEOF_TO_SEQ(elem))\
    )

#define QSBOOST_TYPEOF_TO_SEQ(tokens) QSBOOST_TYPEOF_ ## tokens ## _QSBOOST_TYPEOF

// BOOST_TYPEOF_REGISTER_TEMPLATE

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_EXPLICIT_ID(Name, Params, Id)\
    QSBOOST_TYPEOF_REGISTER_TEMPLATE_IMPL(\
        Name,\
        QSBOOST_TYPEOF_MAKE_OBJS(QSBOOST_TYPEOF_TOSEQ(Params)),\
        QSBOOST_PP_SEQ_SIZE(QSBOOST_TYPEOF_TOSEQ(Params)),\
        Id)

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE(Name, Params)\
    QSBOOST_TYPEOF_REGISTER_TEMPLATE_EXPLICIT_ID(Name, Params, QSBOOST_TYPEOF_UNIQUE_ID())

#define QSBOOST_TYPEOF_OBJECT_MAKER(s, data, elem)\
    QSBOOST_TYPEOF_MAKE_OBJ(elem)

#define QSBOOST_TYPEOF_MAKE_OBJS(Params)\
    QSBOOST_PP_SEQ_TRANSFORM(QSBOOST_TYPEOF_OBJECT_MAKER, ~, Params)

// As suggested by Paul Mensonides:

#define QSBOOST_TYPEOF_TOSEQ(x)\
    QSBOOST_PP_IIF(\
        QSBOOST_PP_IS_UNARY(x),\
        x QSBOOST_PP_TUPLE_EAT(3), QSBOOST_PP_REPEAT\
    )(x, QSBOOST_TYPEOF_TOSEQ_2, ~)

#define QSBOOST_TYPEOF_TOSEQ_2(z, n, _) (class)

// BOOST_TYPEOF_VIRTUAL

#define QSBOOST_TYPEOF_CAT_4(a, b, c, d) QSBOOST_TYPEOF_CAT_4_I(a, b, c, d)
#define QSBOOST_TYPEOF_CAT_4_I(a, b, c, d) a ## b ## c ## d

#define QSBOOST_TYPEOF_VIRTUAL(Fun, Obj)\
    QSBOOST_TYPEOF_CAT_4(QSBOOST_TYPEOF_, QSBOOST_PP_SEQ_HEAD(Obj), _, Fun)

// BOOST_TYPEOF_SEQ_ENUM[_TRAILING][_1]
// Two versions provided due to reentrancy issue

#define QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT(z,n,seq)\
   QSBOOST_PP_SEQ_ELEM(0,seq) (z,n,QSBOOST_PP_SEQ_ELEM(n,QSBOOST_PP_SEQ_ELEM(1,seq)))

#define QSBOOST_TYPEOF_SEQ_ENUM(seq,macro)\
    QSBOOST_PP_ENUM(QSBOOST_PP_SEQ_SIZE(seq),QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#define QSBOOST_TYPEOF_SEQ_ENUM_TRAILING(seq,macro)\
    QSBOOST_PP_ENUM_TRAILING(QSBOOST_PP_SEQ_SIZE(seq),QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT,(macro)(seq))

#define QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1(z,n,seq)\
    QSBOOST_PP_SEQ_ELEM(0,seq) (z,n,QSBOOST_PP_SEQ_ELEM(n,QSBOOST_PP_SEQ_ELEM(1,seq)))

#define QSBOOST_TYPEOF_SEQ_ENUM_1(seq,macro)\
    QSBOOST_PP_ENUM(QSBOOST_PP_SEQ_SIZE(seq),QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1,(macro)(seq))

#define QSBOOST_TYPEOF_SEQ_ENUM_TRAILING_1(seq,macro)\
    QSBOOST_PP_ENUM_TRAILING(QSBOOST_PP_SEQ_SIZE(seq),QSBOOST_TYPEOF_SEQ_EXPAND_ELEMENT_1,(macro)(seq))

//

#define QSBOOST_TYPEOF_PLACEHOLDER(z, n, elem)\
    QSBOOST_TYPEOF_VIRTUAL(PLACEHOLDER, elem)(elem)

#define QSBOOST_TYPEOF_PLACEHOLDER_TYPES(z, n, elem)\
    QSBOOST_TYPEOF_VIRTUAL(PLACEHOLDER_TYPES, elem)(elem, n)

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_ENCODE_PARAM(r, data, n, elem)\
    QSBOOST_TYPEOF_VIRTUAL(ENCODE, elem)(elem, n)

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_DECODE_PARAM(r, data, n, elem)\
    QSBOOST_TYPEOF_VIRTUAL(DECODE, elem)(elem, n)

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR(z, n, elem) \
    QSBOOST_TYPEOF_VIRTUAL(EXPANDTYPE, elem)(elem) QSBOOST_PP_CAT(P, n)

#define QSBOOST_TYPEOF_REGISTER_DEFAULT_TEMPLATE_TYPE(Name,Params,ID)\
    Name< QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params), P) >

//Since we are creating an internal decode struct, we need to use different template names, T instead of P.
#define QSBOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR(z,n,elem) \
    QSBOOST_TYPEOF_VIRTUAL(EXPANDTYPE, elem)(elem) QSBOOST_PP_CAT(T, n)

//Default template param decoding

#define QSBOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TYPE(Name,Params)\
    typedef Name<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params),QSBOOST_TYPEOF_QUALIFY(P))> type;

//Branch the decoding
#define QSBOOST_TYPEOF_TYPEDEF_DECODED_TYPE(Name,Params)\
    QSBOOST_PP_IF(QSBOOST_TYPEOF_HAS_TEMPLATES(Params),\
        QSBOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE,\
        QSBOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TYPE)(Name,Params)

#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_IMPL(Name, Params, Size, ID)\
    QSBOOST_TYPEOF_BEGIN_ENCODE_NS\
    QSBOOST_TYPEOF_REGISTER_TEMPLATE_TEMPLATE_IMPL(Name, Params, ID)\
    template<class V\
        QSBOOST_TYPEOF_SEQ_ENUM_TRAILING(Params, QSBOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR)\
    >\
    struct encode_type_impl<V, Name<QSBOOST_PP_ENUM_PARAMS(Size, P)> >\
    {\
        typedef typename qsboost::type_of::push_back<V, qsboost::mpl::size_t<ID> >::type V0;\
        QSBOOST_PP_SEQ_FOR_EACH_I(QSBOOST_TYPEOF_REGISTER_TEMPLATE_ENCODE_PARAM, ~, Params)\
        typedef QSBOOST_PP_CAT(V, Size) type;\
    };\
    template<class Iter>\
    struct decode_type_impl<qsboost::mpl::size_t<ID>, Iter>\
    {\
        typedef decode_type_impl<qsboost::mpl::size_t<ID>, Iter> self_t;\
        typedef qsboost::mpl::size_t<ID> self_id;\
        typedef Iter iter0;\
        QSBOOST_PP_SEQ_FOR_EACH_I(QSBOOST_TYPEOF_REGISTER_TEMPLATE_DECODE_PARAM, ~, Params)\
        QSBOOST_TYPEOF_TYPEDEF_DECODED_TYPE(Name, Params)\
        typedef QSBOOST_PP_CAT(iter, Size) iter;\
    };\
    QSBOOST_TYPEOF_END_ENCODE_NS

#endif//BOOST_TYPEOF_TEMPLATE_ENCODING_HPP_INCLUDED

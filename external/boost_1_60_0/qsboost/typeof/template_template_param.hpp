// Copyright (C) 2005 Peder Holt
// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED
#define QSBOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED

#include <qsboost/preprocessor/logical/or.hpp>
#include <qsboost/preprocessor/seq/fold_left.hpp>
#include <qsboost/preprocessor/seq/enum.hpp>

#define QSBOOST_TYPEOF_MAKE_OBJ_template(x)   QSBOOST_TYPEOF_TEMPLATE_PARAM(x)
#define QSBOOST_TYPEOF_TEMPLATE(X) template(X) QSBOOST_TYPEOF_EAT
#define QSBOOST_TYPEOF_template(X) (template(X))

#define QSBOOST_TYPEOF_TEMPLATE_PARAM(Params)\
    (TEMPLATE_PARAM)\
    (Params)

#define QSBOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)\
    QSBOOST_TYPEOF_TOSEQ(QSBOOST_PP_SEQ_ELEM(1, This))

//Encode / decode this
#define QSBOOST_TYPEOF_TEMPLATE_PARAM_ENCODE(This, n)\
   typedef typename qsboost::type_of::encode_template<QSBOOST_PP_CAT(V, n),\
       QSBOOST_PP_CAT(P, n)<QSBOOST_TYPEOF_SEQ_ENUM(QSBOOST_TYPEOF_MAKE_OBJS(QSBOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)),QSBOOST_TYPEOF_PLACEHOLDER) >\
   >::type QSBOOST_PP_CAT(V, QSBOOST_PP_INC(n));

#define QSBOOST_TYPEOF_TEMPLATE_PARAM_DECODE(This, n)\
   typedef qsboost::type_of::decode_template< QSBOOST_PP_CAT(iter, n) > QSBOOST_PP_CAT(d, n);\
   typedef typename QSBOOST_PP_CAT(d, n)::type QSBOOST_PP_CAT(P, n);\
   typedef typename QSBOOST_PP_CAT(d, n)::iter QSBOOST_PP_CAT(iter,QSBOOST_PP_INC(n));

// template<class, unsigned int, ...> class
#define QSBOOST_TYPEOF_TEMPLATE_PARAM_EXPANDTYPE(This) \
    template <QSBOOST_PP_SEQ_ENUM(QSBOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(This)) > class

#define QSBOOST_TYPEOF_TEMPLATE_PARAM_PLACEHOLDER(Param)\
    Nested_Template_Template_Arguments_Not_Supported

//'template<class,int> class' is reduced to 'class'
#define QSBOOST_TYPEOF_TEMPLATE_PARAM_DECLARATION_TYPE(Param) class

// T3<int, (unsigned int)0, ...>
#define QSBOOST_TYPEOF_TEMPLATE_PARAM_PLACEHOLDER_TYPES(Param, n)\
    QSBOOST_PP_CAT(T,n)<QSBOOST_TYPEOF_SEQ_ENUM_1(QSBOOST_TYPEOF_MAKE_OBJS(QSBOOST_TYPEOF_TEMPLATE_PARAM_GETPARAMS(Param)),QSBOOST_TYPEOF_PLACEHOLDER) >

#define QSBOOST_TYPEOF_TEMPLATE_PARAM_ISTEMPLATE 1

////////////////////////////
// move to encode_decode?

QSBOOST_TYPEOF_BEGIN_ENCODE_NS

template<class V, class Type_Not_Registered_With_Typeof_System> struct encode_template_impl;
template<class T, class Iter> struct decode_template_impl;

QSBOOST_TYPEOF_END_ENCODE_NS

namespace qsboost { namespace type_of {

    template<class V, class T> struct encode_template
        : QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER::encode_template_impl<V, T>
    {};

    template<class Iter> struct decode_template
        : QSBOOST_TYPEOF_ENCODE_NS_QUALIFIER::decode_template_impl<typename Iter::type, typename Iter::next>
    {};
}}

////////////////////////////
// move to template_encoding.hpp?

//Template template registration
#define QSBOOST_TYPEOF_REGISTER_TYPE_FOR_TEMPLATE_TEMPLATE(Name,Params,ID)\
    template<class V\
        QSBOOST_TYPEOF_SEQ_ENUM_TRAILING(Params,QSBOOST_TYPEOF_REGISTER_TEMPLATE_PARAM_PAIR)\
    >\
    struct encode_template_impl<V,Name<\
        QSBOOST_PP_ENUM_PARAMS(\
        QSBOOST_PP_SEQ_SIZE(Params),\
        P)> >\
        : qsboost::type_of::push_back<V, qsboost::mpl::size_t<ID> >\
    {\
    };\
    template<class Iter> struct decode_template_impl<qsboost::mpl::size_t<ID>, Iter>\
    {\
        QSBOOST_PP_REPEAT(QSBOOST_PP_SEQ_SIZE(Params),QSBOOST_TYPEOF_TYPEDEF_INT_PN,_)\
        typedef Name<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_PLACEHOLDER) > type;\
        typedef Iter iter;\
    };

#define QSBOOST_TYPEOF_TYPEDEF_INT_PN(z,n,Params) typedef int QSBOOST_PP_CAT(P,n);

#ifdef __BORLANDC__
#define QSBOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME QSBOOST_PP_CAT(\
        QSBOOST_PP_CAT(\
            QSBOOST_PP_CAT(\
                decode_nested_template_helper,\
                QSBOOST_TYPEOF_REGISTRATION_GROUP\
            ),0x10000\
        ),__LINE__\
    )
#define QSBOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL(Name,Params,ID)\
    struct QSBOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME {\
        template<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR) >\
        struct decode_params;\
        template<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR) >\
        struct decode_params<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_PLACEHOLDER_TYPES) >\
        {\
            typedef Name<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params),T)> type;\
        };\
    };
//Template template param decoding
#define QSBOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE(Name,Params)\
    typedef typename QSBOOST_TYPEOF_DECODE_NESTED_TEMPLATE_HELPER_NAME::decode_params<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params),P)>::type type;

#else
#define QSBOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL(Name,Params,ID)

//Template template param decoding
#define QSBOOST_TYPEOF_TYPEDEF_DECODED_TEMPLATE_TEMPLATE_TYPE(Name,Params)\
    template<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR) >\
    struct decode_params;\
    template<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_REGISTER_DECODER_TYPE_PARAM_PAIR) >\
    struct decode_params<QSBOOST_TYPEOF_SEQ_ENUM(Params,QSBOOST_TYPEOF_PLACEHOLDER_TYPES) >\
    {\
        typedef Name<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params),T)> type;\
    };\
    typedef typename decode_params<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_SEQ_SIZE(Params),P)>::type type;
#endif
#define QSBOOST_TYPEOF_REGISTER_DECLARE_DECODER_TYPE_PARAM_PAIR(z,n,elem) \
    QSBOOST_TYPEOF_VIRTUAL(DECLARATION_TYPE, elem)(elem) QSBOOST_PP_CAT(T, n)

// BOOST_TYPEOF_HAS_TEMPLATES
#define QSBOOST_TYPEOF_HAS_TEMPLATES(Params)\
    QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_TYPEOF_HAS_TEMPLATES_OP, 0, Params)

#define QSBOOST_TYPEOF_HAS_TEMPLATES_OP(s, state, elem)\
    QSBOOST_PP_OR(state, QSBOOST_TYPEOF_VIRTUAL(ISTEMPLATE, elem))

//Define template template arguments
#define QSBOOST_TYPEOF_REGISTER_TEMPLATE_TEMPLATE_IMPL(Name,Params,ID)\
    QSBOOST_PP_IF(QSBOOST_TYPEOF_HAS_TEMPLATES(Params),\
        QSBOOST_TYPEOF_REGISTER_DECODE_NESTED_TEMPLATE_HELPER_IMPL,\
        QSBOOST_TYPEOF_REGISTER_TYPE_FOR_TEMPLATE_TEMPLATE)(Name,Params,ID)

#endif //BOOST_TYPEOF_TEMPLATE_TEMPLATE_PARAM_HPP_INCLUDED

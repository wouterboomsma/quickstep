// Copyright (C) 2005 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED
#define QSBOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED

#define QSBOOST_TYPEOF_class_QSBOOST_TYPEOF (class)
#define QSBOOST_TYPEOF_typename_QSBOOST_TYPEOF (typename)

#define QSBOOST_TYPEOF_MAKE_OBJ_class QSBOOST_TYPEOF_TYPE_PARAM
#define QSBOOST_TYPEOF_MAKE_OBJ_typename QSBOOST_TYPEOF_TYPE_PARAM

#define QSBOOST_TYPEOF_TYPE_PARAM\
    (TYPE_PARAM)

#define QSBOOST_TYPEOF_TYPE_PARAM_EXPANDTYPE(Param) class

// TYPE_PARAM "virtual functions" implementation

#define QSBOOST_TYPEOF_TYPE_PARAM_ENCODE(This, n)\
    typedef typename qsboost::type_of::encode_type<\
        QSBOOST_PP_CAT(V, n),\
        QSBOOST_PP_CAT(P, n)\
    >::type QSBOOST_PP_CAT(V, QSBOOST_PP_INC(n)); 

#define QSBOOST_TYPEOF_TYPE_PARAM_DECODE(This, n)\
    typedef qsboost::type_of::decode_type< QSBOOST_PP_CAT(iter, n) > QSBOOST_PP_CAT(d, n);\
    typedef typename QSBOOST_PP_CAT(d, n)::type QSBOOST_PP_CAT(P, n);\
    typedef typename QSBOOST_PP_CAT(d, n)::iter QSBOOST_PP_CAT(iter, QSBOOST_PP_INC(n));

#define QSBOOST_TYPEOF_TYPE_PARAM_PLACEHOLDER(Param) int
#define QSBOOST_TYPEOF_TYPE_PARAM_DECLARATION_TYPE(Param) class
#define QSBOOST_TYPEOF_TYPE_PARAM_PLACEHOLDER_TYPES(Param, n) QSBOOST_PP_CAT(T,n)
#define QSBOOST_TYPEOF_TYPE_PARAM_ISTEMPLATE 0

#endif//BOOST_TYPEOF_TYPE_TEMPLATE_PARAM_HPP_INCLUDED

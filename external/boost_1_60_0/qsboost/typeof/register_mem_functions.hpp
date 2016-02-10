// Copyright (C) 2004 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#include <qsboost/typeof/encode_decode_params.hpp>

// member functions

template<class V, class T, class R QSBOOST_PP_ENUM_TRAILING_PARAMS(n, class P)> 
struct encode_type_impl<V, R(T::*)(QSBOOST_PP_ENUM_PARAMS(n, P)) QSBOOST_TYPEOF_qualifier>
{
    typedef R QSBOOST_PP_CAT(P, n);
    typedef T QSBOOST_PP_CAT(P, QSBOOST_PP_INC(n));
    typedef QSBOOST_TYPEOF_ENCODE_PARAMS(QSBOOST_PP_ADD(n, 2), QSBOOST_TYPEOF_id + n) type;
};

template<class Iter>
struct decode_type_impl<qsboost::mpl::size_t<QSBOOST_TYPEOF_id + n>, Iter>
{
    typedef Iter iter0;
    QSBOOST_TYPEOF_DECODE_PARAMS(QSBOOST_PP_ADD(n, 2))
    template<class T> struct workaround{
        typedef QSBOOST_PP_CAT(p, n)(T::*type)(QSBOOST_PP_ENUM_PARAMS(n, p)) QSBOOST_TYPEOF_qualifier;
    };
    typedef typename workaround<QSBOOST_PP_CAT(p, QSBOOST_PP_INC(n))>::type type;
    typedef QSBOOST_PP_CAT(iter, QSBOOST_PP_ADD(n, 2)) iter;
};

// undef parameters

#undef QSBOOST_TYPEOF_id
#undef QSBOOST_TYPEOF_qualifier

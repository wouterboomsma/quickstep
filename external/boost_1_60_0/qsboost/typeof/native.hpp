// Copyright (C) 2006 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_NATIVE_HPP_INCLUDED
#define QSBOOST_TYPEOF_NATIVE_HPP_INCLUDED

#ifndef MSVC_TYPEOF_HACK

#ifdef QSBOOST_NO_SFINAE

namespace qsboost { namespace type_of {

    template<class T> 
        T& ensure_obj(const T&);

}}

#else

#include <qsboost/type_traits/is_function.hpp> 
#include <qsboost/utility/enable_if.hpp>

namespace qsboost { namespace type_of {
# ifdef QSBOOST_NO_SFINAE
    template<class T> 
    T& ensure_obj(const T&);
# else
    template<typename T>
        typename enable_if<is_function<T>, T&>::type
        ensure_obj(T&);

    template<typename T>
        typename disable_if<is_function<T>, T&>::type
        ensure_obj(const T&);
# endif
}}

#endif//BOOST_NO_SFINAE

#define QSBOOST_TYPEOF(expr) QSBOOST_TYPEOF_KEYWORD(qsboost::type_of::ensure_obj(expr))
#define QSBOOST_TYPEOF_TPL QSBOOST_TYPEOF

#define QSBOOST_TYPEOF_NESTED_TYPEDEF_TPL(name,expr) \
    struct name {\
        typedef QSBOOST_TYPEOF_TPL(expr) type;\
    };

#define QSBOOST_TYPEOF_NESTED_TYPEDEF(name,expr) \
    struct name {\
        typedef QSBOOST_TYPEOF(expr) type;\
    };

#endif//MSVC_TYPEOF_HACK

#define QSBOOST_TYPEOF_REGISTER_TYPE(x)
#define QSBOOST_TYPEOF_REGISTER_TEMPLATE(x, params)

#endif//BOOST_TYPEOF_NATIVE_HPP_INCLUDED


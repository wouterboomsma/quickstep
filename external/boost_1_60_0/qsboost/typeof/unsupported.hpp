// Copyright (C) 2010 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_UNSUPPORTED_HPP_INCLUDED
#define QSBOOST_TYPEOF_UNSUPPORTED_HPP_INCLUDED

namespace qsboost { namespace type_of {
    struct typeof_emulation_is_unsupported_on_this_compiler {};
}}

#define QSBOOST_TYPEOF(expr) qsboost::type_of::typeof_emulation_is_unsupported_on_this_compiler
#define QSBOOST_TYPEOF_TPL QSBOOST_TYPEOF

#define QSBOOST_TYPEOF_NESTED_TYPEDEF_TPL(name,expr) \
struct name {\
    typedef QSBOOST_TYPEOF_TPL(expr) type;\
};

#define QSBOOST_TYPEOF_NESTED_TYPEDEF(name,expr) \
struct name {\
    typedef QSBOOST_TYPEOF(expr) type;\
};


#define QSBOOST_TYPEOF_REGISTER_TYPE(x)
#define QSBOOST_TYPEOF_REGISTER_TEMPLATE(x, params)

#endif
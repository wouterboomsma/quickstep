// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_TEMPLATE_PARAMS_HPP_INCLUDED

#include <qsboost/preprocessor/control/expr_if.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>

#define QSBOOST_IOSTREAMS_TEMPLATE_PARAMS(arity, param) \
    QSBOOST_PP_EXPR_IF(arity, template<) \
    QSBOOST_PP_ENUM_PARAMS(arity, typename param) \
    QSBOOST_PP_EXPR_IF(arity, >) \
    /**/

#define QSBOOST_IOSTREAMS_TEMPLATE_ARGS(arity, param) \
    QSBOOST_PP_EXPR_IF(arity, <) \
    QSBOOST_PP_ENUM_PARAMS(arity, param) \
    QSBOOST_PP_EXPR_IF(arity, >) \
    /**/

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_BUFFERS_HPP_INCLUDED

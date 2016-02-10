//  Copyright (c) 2001-2013 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(QSBOOST_SPIRIT_ASSERT_MSG_JUN_23_2009_0836AM)
#define QSBOOST_SPIRIT_ASSERT_MSG_JUN_23_2009_0836AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp>

// Work around the MPL problem in BOOST_MPL_ASSERT_MSG generating
// multiple definition linker errors for certain compilers (VC++ 8).
// BOOST_SPIRIT_DONT_USE_MPL_ASSERT_MSG can also be defined by user.
#if !defined(QSBOOST_SPIRIT_DONT_USE_MPL_ASSERT_MSG)
# if defined(QSBOOST_MSVC) && QSBOOST_MSVC < 1500
#  define QSBOOST_SPIRIT_DONT_USE_MPL_ASSERT_MSG 1
# endif
#endif

#if !defined(QSBOOST_NO_CXX11_STATIC_ASSERT) || QSBOOST_SPIRIT_DONT_USE_MPL_ASSERT_MSG != 0
#include <qsboost/static_assert.hpp>
#define QSBOOST_SPIRIT_ASSERT_MSG(Cond, Msg, Types)                             \
        QSBOOST_STATIC_ASSERT_MSG(Cond, # Msg)
#else
#include <qsboost/mpl/assert.hpp>
#define QSBOOST_SPIRIT_ASSERT_MSG(Cond, Msg, Types)                             \
        QSBOOST_MPL_ASSERT_MSG(Cond, Msg, Types)
#endif

#define QSBOOST_SPIRIT_ASSERT_MATCH(Domain, Expr)                               \
        QSBOOST_SPIRIT_ASSERT_MSG((                                             \
            qsboost::spirit::traits::matches< Domain, Expr >::value             \
        ), error_invalid_expression, (Expr))

// GCC 4.7 will overeagerly instantiate static_asserts in template functions,
// if the assert condition does not depend on template parameters
// (see https://svn.boost.org/trac/boost/ticket/8381).
// There are places where we want to use constant false as the condition in
// template functions to indicate that these function overloads should never
// be called. This allows to generate better error messages. To solve this
// problem we make the condition dependent on the template argument and use
// the following macro in such places.
#include <qsboost/type_traits/is_same.hpp>

#define QSBOOST_SPIRIT_ASSERT_FAIL(TemplateParam, Msg, Types)                   \
        QSBOOST_SPIRIT_ASSERT_MSG((!qsboost::is_same<                             \
            TemplateParam, TemplateParam >::value), Msg, Types)

#endif


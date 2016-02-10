// Copyright (C) 2004 Arkadiy Vertleyb
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED
#define QSBOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED

#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/inc.hpp>
#include <qsboost/preprocessor/dec.hpp>
#include <qsboost/preprocessor/if.hpp>
#include <qsboost/preprocessor/arithmetic/add.hpp>
#include <qsboost/preprocessor/iteration/iterate.hpp>

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

#ifndef QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY
#define QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY 10
#endif

enum 
{
    FUN_ID                          = QSBOOST_TYPEOF_UNIQUE_ID(),
    FUN_PTR_ID                      = FUN_ID +  1 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    FUN_REF_ID                      = FUN_ID +  2 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    MEM_FUN_ID                      = FUN_ID +  3 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    CONST_MEM_FUN_ID                = FUN_ID +  4 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_MEM_FUN_ID             = FUN_ID +  5 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_CONST_MEM_FUN_ID       = FUN_ID +  6 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    FUN_VAR_ID                      = FUN_ID +  7 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    FUN_VAR_PTR_ID                  = FUN_ID +  8 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    FUN_VAR_REF_ID                  = FUN_ID +  9 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    MEM_FUN_VAR_ID                  = FUN_ID + 10 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    CONST_MEM_FUN_VAR_ID            = FUN_ID + 11 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_MEM_FUN_VAR_ID         = FUN_ID + 12 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY),
    VOLATILE_CONST_MEM_FUN_VAR_ID   = FUN_ID + 13 * QSBOOST_PP_INC(QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY)
};

QSBOOST_TYPEOF_BEGIN_ENCODE_NS

# define QSBOOST_PP_ITERATION_LIMITS (0, QSBOOST_TYPEOF_LIMIT_FUNCTION_ARITY)
# define QSBOOST_PP_FILENAME_1 <qsboost/typeof/register_functions_iterate.hpp>
# include QSBOOST_PP_ITERATE()

QSBOOST_TYPEOF_END_ENCODE_NS

#endif//BOOST_TYPEOF_REGISTER_FUNCTIONS_HPP_INCLUDED

///////////////////////////////////////////////////////////////////////////////
/// \file local.hpp
/// Contains macros to ease the generation of repetitious code constructs
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_LOCAL_MACRO
# error "local iteration target macro is not defined"
#endif

#ifndef QSBOOST_PROTO_LOCAL_LIMITS
# define QSBOOST_PROTO_LOCAL_LIMITS (1, QSBOOST_PROTO_MAX_ARITY)
#endif

#ifndef QSBOOST_PROTO_LOCAL_typename_A
# define QSBOOST_PROTO_LOCAL_typename_A QSBOOST_PROTO_typename_A
#endif

#ifndef QSBOOST_PROTO_LOCAL_A
# define QSBOOST_PROTO_LOCAL_A QSBOOST_PROTO_A_const_ref
#endif

#ifndef QSBOOST_PROTO_LOCAL_A_a
# define QSBOOST_PROTO_LOCAL_A_a QSBOOST_PROTO_A_const_ref_a
#endif

#ifndef QSBOOST_PROTO_LOCAL_a
# define QSBOOST_PROTO_LOCAL_a QSBOOST_PROTO_ref_a
#endif

#define QSBOOST_PP_LOCAL_LIMITS QSBOOST_PROTO_LOCAL_LIMITS

#define QSBOOST_PP_LOCAL_MACRO(N)       \
  QSBOOST_PROTO_LOCAL_MACRO(            \
      N                               \
    , QSBOOST_PROTO_LOCAL_typename_A    \
    , QSBOOST_PROTO_LOCAL_A             \
    , QSBOOST_PROTO_LOCAL_A_a           \
    , QSBOOST_PROTO_LOCAL_a             \
  )                                   \
  /**/

#include QSBOOST_PP_LOCAL_ITERATE()

#undef QSBOOST_PROTO_LOCAL_MACRO
#undef QSBOOST_PROTO_LOCAL_LIMITS
#undef QSBOOST_PROTO_LOCAL_typename_A
#undef QSBOOST_PROTO_LOCAL_A
#undef QSBOOST_PROTO_LOCAL_A_a
#undef QSBOOST_PROTO_LOCAL_a

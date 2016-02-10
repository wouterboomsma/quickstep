/* Copyright 2003-2013 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_DETAIL_VARTEMPL_SUPPORT_HPP
#define QSBOOST_MULTI_INDEX_DETAIL_VARTEMPL_SUPPORT_HPP

#if defined(_MSC_VER)
#pragma once
#endif

/* Utilities for emulation of variadic template functions. Variadic packs are
 * replaced by lists of BOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS parameters:
 *
 *   - typename... Args            --> BOOST_MULTI_INDEX_TEMPLATE_PARAM_PACK
 *   - Args&&... args              --> BOOST_MULTI_INDEX_FUNCTION_PARAM_PACK
 *   - std::forward<Args>(args)... --> BOOST_MULTI_INDEX_FORWARD_PARAM_PACK
 *
 * Forwarding emulated with Boost.Move. A template functions foo_imp
 * defined in such way accepts *exactly* BOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS
 * arguments: variable number of arguments is emulated by providing a set of
 * overloads foo forwarding to foo_impl with
 * 
 *   BOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL
 *   BOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_EXTRA_ARG (initial extra arg)
 *
 * which fill the extra args with boost::multi_index::detail::noarg's.
 * boost::multi_index::detail::vartempl_placement_new works the opposite
 * way: it acceps a full a pointer x to Value and a
 * BOOST_MULTI_INDEX_FUNCTION_PARAM_PACK and forwards to
 * new(x) Value(args) where args is the argument pack after discarding
 * noarg's.
 *
 * Emulation decays to the real thing when the compiler supports variadic
 * templates and move semantics natively.
 */

#include <qsboost/config.hpp>

#if defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)||\
    defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES)

#include <qsboost/move/core.hpp>
#include <qsboost/move/utility.hpp>
#include <qsboost/preprocessor/arithmetic/add.hpp>
#include <qsboost/preprocessor/arithmetic/sub.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/facilities/empty.hpp>
#include <qsboost/preprocessor/facilities/intercept.hpp>
#include <qsboost/preprocessor/logical/and.hpp>
#include <qsboost/preprocessor/punctuation/comma.hpp>
#include <qsboost/preprocessor/punctuation/comma_if.hpp>
#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/preprocessor/seq/elem.hpp>

#if !defined(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS)
#define QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS 5
#endif

#define QSBOOST_MULTI_INDEX_TEMPLATE_PARAM_PACK                        \
QSBOOST_PP_ENUM_PARAMS(                                                \
  QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,typename T)

#define QSBOOST_MULTI_INDEX_VARTEMPL_ARG(z,n,_)                        \
QSBOOST_FWD_REF(QSBOOST_PP_CAT(T,n)) QSBOOST_PP_CAT(t,n)

#define QSBOOST_MULTI_INDEX_FUNCTION_PARAM_PACK                        \
QSBOOST_PP_ENUM(                                                       \
  QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,                             \
  QSBOOST_MULTI_INDEX_VARTEMPL_ARG,~)

#define QSBOOST_MULTI_INDEX_VARTEMPL_FORWARD_ARG(z,n,_)                \
qsboost::forward<QSBOOST_PP_CAT(T,n)>(QSBOOST_PP_CAT(t,n))

#define QSBOOST_MULTI_INDEX_FORWARD_PARAM_PACK                         \
QSBOOST_PP_ENUM(                                                       \
  QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,                             \
  QSBOOST_MULTI_INDEX_VARTEMPL_FORWARD_ARG,~)

namespace qsboost{namespace multi_index{namespace detail{
struct noarg{};
}}}

/* call vartempl function without args */

#define QSBOOST_MULTI_INDEX_NULL_PARAM_PACK                            \
QSBOOST_PP_ENUM_PARAMS(                                                \
  QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,                             \
  qsboost::multi_index::detail::noarg() QSBOOST_PP_INTERCEPT)

#define QSBOOST_MULTI_INDEX_TEMPLATE_N(n)                              \
template<QSBOOST_PP_ENUM_PARAMS(n,typename T)>

#define QSBOOST_MULTI_INDEX_TEMPLATE_0(n)

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_AUX(z,n,data)        \
QSBOOST_PP_IF(n,                                                       \
  QSBOOST_MULTI_INDEX_TEMPLATE_N,                                      \
  QSBOOST_MULTI_INDEX_TEMPLATE_0)(n)                                   \
QSBOOST_PP_SEQ_ELEM(0,data) /* ret */                                  \
QSBOOST_PP_SEQ_ELEM(1,data) /* name_from */ (                          \
  QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_ARG,~))                 \
{                                                                    \
  return QSBOOST_PP_SEQ_ELEM(2,data) /* name_to */ (                   \
    QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_FORWARD_ARG,~)        \
    QSBOOST_PP_COMMA_IF(                                               \
      QSBOOST_PP_AND(                                                  \
        n,QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n)))    \
    QSBOOST_PP_ENUM_PARAMS(                                            \
      QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n),         \
      qsboost::multi_index::detail::noarg() QSBOOST_PP_INTERCEPT)        \
  );                                                                 \
}

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL(                     \
  ret,name_from,name_to)                                             \
QSBOOST_PP_REPEAT_FROM_TO(                                             \
  0,QSBOOST_PP_ADD(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,1),           \
  QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_AUX,                       \
  (ret)(name_from)(name_to))

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_EXTRA_ARG_AUX(       \
  z,n,data)                                                          \
QSBOOST_PP_IF(n,                                                       \
  QSBOOST_MULTI_INDEX_TEMPLATE_N,                                      \
  QSBOOST_MULTI_INDEX_TEMPLATE_0)(n)                                   \
QSBOOST_PP_SEQ_ELEM(0,data) /* ret */                                  \
QSBOOST_PP_SEQ_ELEM(1,data) /* name_from */ (                          \
  QSBOOST_PP_SEQ_ELEM(3,data) QSBOOST_PP_SEQ_ELEM(4,data) /* extra arg */\
  QSBOOST_PP_COMMA_IF(n)                                               \
  QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_ARG,~))                 \
{                                                                    \
  return QSBOOST_PP_SEQ_ELEM(2,data) /* name_to */ (                   \
    QSBOOST_PP_SEQ_ELEM(4,data) /* extra_arg_name */                   \
    QSBOOST_PP_COMMA_IF(n)                                             \
    QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_FORWARD_ARG,~)        \
    QSBOOST_PP_COMMA_IF(                                               \
      QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n))         \
    QSBOOST_PP_ENUM_PARAMS(                                            \
      QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n),         \
      qsboost::multi_index::detail::noarg() QSBOOST_PP_INTERCEPT)        \
  );                                                                 \
}

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_EXTRA_ARG(           \
  ret,name_from,name_to,extra_arg_type,extra_arg_name)               \
QSBOOST_PP_REPEAT_FROM_TO(                                             \
  0,QSBOOST_PP_ADD(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,1),           \
  QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_EXTRA_ARG_AUX,             \
  (ret)(name_from)(name_to)(extra_arg_type)(extra_arg_name))

namespace qsboost{
  
namespace multi_index{
  
namespace detail{

#define QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW_AUX(z,n,name)    \
template<                                                            \
  typename Value                                                     \
  QSBOOST_PP_COMMA_IF(n)                                               \
  QSBOOST_PP_ENUM_PARAMS(n,typename T)                                 \
>                                                                    \
Value* name(                                                         \
  Value* x                                                           \
  QSBOOST_PP_COMMA_IF(n)                                               \
  QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_ARG,~)                  \
  QSBOOST_PP_COMMA_IF(                                                 \
    QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n))           \
  QSBOOST_PP_ENUM_PARAMS(                                              \
    QSBOOST_PP_SUB(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,n),           \
    QSBOOST_FWD_REF(noarg) QSBOOST_PP_INTERCEPT))                        \
{                                                                    \
  return new(x) Value(                                               \
    QSBOOST_PP_ENUM(n,QSBOOST_MULTI_INDEX_VARTEMPL_FORWARD_ARG,~));      \
}

#define QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW(name)            \
QSBOOST_PP_REPEAT_FROM_TO(                                             \
  0,QSBOOST_PP_ADD(QSBOOST_MULTI_INDEX_LIMIT_VARTEMPL_ARGS,1),           \
  QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW_AUX,                   \
  name)

QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW(vartempl_placement_new)

#undef QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW_AUX
#undef QSBOOST_MULTI_INDEX_VARTEMPL_TO_PLACEMENT_NEW

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#else

/* native variadic templates support */

#include <utility>

#define QSBOOST_MULTI_INDEX_TEMPLATE_PARAM_PACK typename... Args
#define QSBOOST_MULTI_INDEX_FUNCTION_PARAM_PACK Args&&... args
#define QSBOOST_MULTI_INDEX_FORWARD_PARAM_PACK  std::forward<Args>(args)...
#define QSBOOST_MULTI_INDEX_NULL_PARAM_PACK

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL(                     \
  ret,name_from,name_to)                                             \
template<typename... Args> ret name_from(Args&&... args)             \
{                                                                    \
  return name_to(std::forward<Args>(args)...);                       \
}

#define QSBOOST_MULTI_INDEX_OVERLOADS_TO_VARTEMPL_EXTRA_ARG(           \
  ret,name_from,name_to,extra_arg_type,extra_arg_name)               \
template<typename... Args> ret name_from(                            \
  extra_arg_type extra_arg_name,Args&&... args)                      \
{                                                                    \
  return name_to(extra_arg_name,std::forward<Args>(args)...);        \
}

namespace qsboost{
  
namespace multi_index{
  
namespace detail{

template<typename Value,typename... Args>
Value* vartempl_placement_new(Value*x,Args&&... args)
{
  return new(x) Value(std::forward<Args>(args)...);
}

} /* namespace multi_index::detail */

} /* namespace multi_index */

} /* namespace boost */

#endif
#endif


// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_CONFIG_HPP_INCLUDED
#define QSBOOST_FT_CONFIG_HPP_INCLUDED

#include <qsboost/function_types/config/compiler.hpp>
#include <qsboost/function_types/config/cc_names.hpp>

// maximum allowed arity
#ifndef QSBOOST_FT_MAX_ARITY
#define QSBOOST_FT_MAX_ARITY 20
#endif

// the most common calling conventions for x86 architecture can be enabled at
// once in the compiler config
#ifdef QSBOOST_FT_COMMON_X86_CCs
#   ifndef QSBOOST_FT_CC_CDECL
#   define QSBOOST_FT_CC_CDECL QSBOOST_FT_COMMON_X86_CCs
#   endif
#   ifndef QSBOOST_FT_CC_STDCALL
#   define QSBOOST_FT_CC_STDCALL non_variadic|QSBOOST_FT_COMMON_X86_CCs
#   endif
#   ifndef QSBOOST_FT_CC_FASTCALL
#   define QSBOOST_FT_CC_FASTCALL non_variadic|QSBOOST_FT_COMMON_X86_CCs
#   endif
#endif

// where to place the cc specifier (the common way)
#ifndef QSBOOST_FT_SYNTAX
#   define QSBOOST_FT_SYNTAX(result,lparen,cc_spec,type_mod,name,rparen) \
                        result() lparen() cc_spec() type_mod() name() rparen()
#endif

// param for nullary functions
// set to "void" for compilers that require nullary functions to read 
// "R (void)" in template partial specialization
#ifndef QSBOOST_FT_NULLARY_PARAM
#define QSBOOST_FT_NULLARY_PARAM 
#endif

// there is a pending defect report on cv qualified function types, so support
// for these types is disabled, unless for compilers where it's known to work
#ifndef QSBOOST_FT_NO_CV_FUNC_SUPPORT
#define QSBOOST_FT_NO_CV_FUNC_SUPPORT 1
#endif

// full preprocessing implies preprocessing of the ccs
#if defined(QSBOOST_FT_PREPROCESSING_MODE) && !defined(QSBOOST_FT_CC_PREPROCESSING)
#   define QSBOOST_FT_CC_PREPROCESSING 1
#endif

#endif



// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_CONFIG_CC_NAMES_HPP_INCLUDED
#define QSBOOST_FT_CONFIG_CC_NAMES_HPP_INCLUDED

#define QSBOOST_FT_BUILTIN_CC_NAMES \
  (( IMPLICIT           , implicit_cc , QSBOOST_PP_EMPTY                ))\
  (( CDECL              , cdecl_cc    , QSBOOST_PP_IDENTITY(__cdecl   ) ))\
  (( STDCALL            , stdcall_cc  , QSBOOST_PP_IDENTITY(__stdcall ) ))\
  (( PASCAL             , pascal_cc   , QSBOOST_PP_IDENTITY(pascal    ) ))\
  (( FASTCALL           , fastcall_cc , QSBOOST_PP_IDENTITY(__fastcall) ))\
  (( CLRCALL            , clrcall_cc  , QSBOOST_PP_IDENTITY(__clrcall ) ))\
  (( THISCALL           , thiscall_cc , QSBOOST_PP_IDENTITY(__thiscall) ))\
  (( IMPLICIT_THISCALL  , thiscall_cc , QSBOOST_PP_EMPTY                )) 

// append user-defined cc names to builtin ones
#ifdef QSBOOST_FT_CC_NAMES 
#   define QSBOOST_FT_CC_NAMES_SEQ QSBOOST_FT_BUILTIN_CC_NAMES QSBOOST_FT_CC_NAMES
#   define QSBOOST_FT_CC_PREPROCESSING 1
#else
#   define QSBOOST_FT_CC_NAMES_SEQ QSBOOST_FT_BUILTIN_CC_NAMES
#endif

#endif


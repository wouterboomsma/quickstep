
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusions

#ifndef QSBOOST_FT_DETAIL_PP_LOOP_HPP_INCLUDED
#define QSBOOST_FT_DETAIL_PP_LOOP_HPP_INCLUDED
#   include <qsboost/preprocessor/facilities/expand.hpp>
#   include <qsboost/preprocessor/facilities/empty.hpp>
#   include <qsboost/preprocessor/punctuation/paren.hpp>
#endif

#include <qsboost/function_types/detail/encoding/def.hpp>
#include <qsboost/function_types/detail/encoding/aliases_def.hpp>

#if defined(QSBOOST_FT_PREPROCESSING_MODE)
#   define QSBOOST_FT_loop <qsboost/function_types/detail/pp_cc_loop/master.hpp>
#else
#   define QSBOOST_FT_loop \
        <qsboost/function_types/detail/pp_cc_loop/preprocessed.hpp>
#endif

#if defined(QSBOOST_FT_al_path)

#   define QSBOOST_FT_cc_file \
        <qsboost/function_types/detail/pp_variate_loop/preprocessed.hpp>
#   define QSBOOST_FT_variate_file \
        <qsboost/function_types/detail/pp_arity_loop.hpp>

#   ifndef QSBOOST_FT_type_function
#   define QSBOOST_FT_type_function(cc,name) QSBOOST_FT_SYNTAX( \
      R QSBOOST_PP_EMPTY,QSBOOST_PP_EMPTY,cc,QSBOOST_PP_EMPTY,name,QSBOOST_PP_EMPTY)
#   endif
#   ifndef QSBOOST_FT_type_function_pointer
#   define QSBOOST_FT_type_function_pointer(cc,name) QSBOOST_FT_SYNTAX( \
      R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,* QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)
#   endif
#   ifndef QSBOOST_FT_type_function_reference
#   define QSBOOST_FT_type_function_reference(cc,name) QSBOOST_FT_SYNTAX( \
      R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,& QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)
#   endif
#   ifndef QSBOOST_FT_type_member_function_pointer
#   define QSBOOST_FT_type_member_function_pointer(cc,name) QSBOOST_FT_SYNTAX( \
      R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,T0::* QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)
#   endif

#   include QSBOOST_FT_loop

#   undef QSBOOST_FT_type_function
#   undef QSBOOST_FT_type_function_pointer
#   undef QSBOOST_FT_type_function_reference
#   undef QSBOOST_FT_type_member_function_pointer

#   undef QSBOOST_FT_variations
#   undef QSBOOST_FT_variate_file
#   undef QSBOOST_FT_cc_file
#   undef QSBOOST_FT_al_path

#elif defined(QSBOOST_FT_cc_file)

#   include QSBOOST_FT_loop
#   undef QSBOOST_FT_cc_file

#else

#   error "argument missing"

#endif

#undef QSBOOST_FT_loop

#include <qsboost/function_types/detail/encoding/aliases_undef.hpp>
#include <qsboost/function_types/detail/encoding/undef.hpp>



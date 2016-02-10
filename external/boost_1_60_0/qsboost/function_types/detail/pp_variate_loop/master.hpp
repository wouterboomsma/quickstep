
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif

#if !defined(QSBOOST_FT_PREPROCESSING_MODE)
#   error "this file is only for two-pass preprocessing"
#endif

#if !defined(QSBOOST_PP_VALUE)
#   include <qsboost/preprocessor/slot/slot.hpp>
#   include <qsboost/preprocessor/facilities/empty.hpp>
#   include <qsboost/preprocessor/facilities/expand.hpp>
#   include <qsboost/function_types/detail/encoding/def.hpp>

QSBOOST_PP_EXPAND(#) define QSBOOST_FT_mfp 0
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_syntax QSBOOST_FT_type_function

#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_non_variadic
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_variadic
#   include __FILE__

QSBOOST_PP_EXPAND(#) if !QSBOOST_FT_NO_CV_FUNC_SUPPORT
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_non_variadic|QSBOOST_FT_const
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_variadic|QSBOOST_FT_const
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_non_variadic|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_variadic|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_non_variadic|QSBOOST_FT_const|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_function|QSBOOST_FT_variadic|QSBOOST_FT_const|QSBOOST_FT_volatile
#   include __FILE__
QSBOOST_PP_EXPAND(#) endif


QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_syntax
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_syntax QSBOOST_FT_type_function_pointer

#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_pointer|QSBOOST_FT_non_variadic
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_pointer|QSBOOST_FT_variadic
#   include __FILE__

QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_syntax
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_syntax QSBOOST_FT_type_function_reference

#   define QSBOOST_PP_VALUE \
      QSBOOST_FT_reference|QSBOOST_FT_non_variadic
#   include __FILE__
#   define QSBOOST_PP_VALUE \
      QSBOOST_FT_reference|QSBOOST_FT_variadic
#   include __FILE__

QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_syntax
QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_mfp

QSBOOST_PP_EXPAND(#) define QSBOOST_FT_mfp 1
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_syntax QSBOOST_FT_type_member_function_pointer

#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_non_variadic
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_variadic
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_non_variadic|QSBOOST_FT_const
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_variadic|QSBOOST_FT_const
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_non_variadic|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_variadic|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_non_variadic|QSBOOST_FT_const|QSBOOST_FT_volatile
#   include __FILE__
#   define  QSBOOST_PP_VALUE \
      QSBOOST_FT_member_function_pointer|QSBOOST_FT_variadic|QSBOOST_FT_const|QSBOOST_FT_volatile
#   include __FILE__

QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_syntax
QSBOOST_PP_EXPAND(#) undef  QSBOOST_FT_mfp

#   include <qsboost/function_types/detail/encoding/undef.hpp>
#else 

#   include QSBOOST_PP_ASSIGN_SLOT(1)

#   define  QSBOOST_PP_VALUE QSBOOST_PP_SLOT(1) & QSBOOST_FT_kind_mask
#   include QSBOOST_PP_ASSIGN_SLOT(2)

QSBOOST_PP_EXPAND(#) if !!(QSBOOST_PP_SLOT(2) & (QSBOOST_FT_variations))
QSBOOST_PP_EXPAND(#) if (QSBOOST_PP_SLOT(1) & (QSBOOST_FT_cond)) == (QSBOOST_FT_cond)

#   if ( QSBOOST_PP_SLOT(1) & (QSBOOST_FT_variadic) )
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_ell ...
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_nullary_param
#   else
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_ell
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_nullary_param QSBOOST_FT_NULLARY_PARAM
#   endif

#   if !( QSBOOST_PP_SLOT(1) & (QSBOOST_FT_volatile) )
#     if !( QSBOOST_PP_SLOT(1) & (QSBOOST_FT_const) )
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cv 
#     else
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cv const
#     endif
#   else
#     if !( QSBOOST_PP_SLOT(1) & (QSBOOST_FT_const) )
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cv volatile
#     else
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cv const volatile
#     endif
#   endif
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_flags QSBOOST_PP_SLOT(1)
QSBOOST_PP_EXPAND(#)   include QSBOOST_FT_variate_file

QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_cv
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_ell
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_nullary_param
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_flags
QSBOOST_PP_EXPAND(#) endif
QSBOOST_PP_EXPAND(#) endif
#endif


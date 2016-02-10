
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusions

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif


#if !QSBOOST_PP_IS_ITERATING

#   ifndef QSBOOST_FT_DETAIL_CC_LOOP_MASTER_HPP_INCLUDED
#   define QSBOOST_FT_DETAIL_CC_LOOP_MASTER_HPP_INCLUDED
#     include <qsboost/function_types/config/cc_names.hpp>

#     include <qsboost/preprocessor/cat.hpp>
#     include <qsboost/preprocessor/seq/size.hpp>
#     include <qsboost/preprocessor/seq/elem.hpp>
#     include <qsboost/preprocessor/tuple/elem.hpp>
#     include <qsboost/preprocessor/iteration/iterate.hpp>
#     include <qsboost/preprocessor/facilities/expand.hpp>
#     include <qsboost/preprocessor/arithmetic/inc.hpp>
#   endif

#   include <qsboost/function_types/detail/encoding/def.hpp>
#   include <qsboost/function_types/detail/encoding/aliases_def.hpp>

#   define  QSBOOST_PP_FILENAME_1 \
        <qsboost/function_types/detail/pp_cc_loop/master.hpp>
#   define  QSBOOST_PP_ITERATION_LIMITS \
        (0,QSBOOST_PP_SEQ_SIZE(QSBOOST_FT_CC_NAMES_SEQ)-1)
#   include QSBOOST_PP_ITERATE()
#   if !defined(QSBOOST_FT_config_valid) && QSBOOST_FT_CC_PREPROCESSING
#     define QSBOOST_FT_cc_id 1
#     define QSBOOST_FT_cc_name implicit_cc
#     define QSBOOST_FT_cc QSBOOST_PP_EMPTY
#     define QSBOOST_FT_cond callable_builtin
#     include QSBOOST_FT_cc_file
#     undef QSBOOST_FT_cond
#     undef QSBOOST_FT_cc_name
#     undef QSBOOST_FT_cc
#     undef QSBOOST_FT_cc_id
#   elif !defined(QSBOOST_FT_config_valid) // and generating preprocessed file
QSBOOST_PP_EXPAND(#) ifndef QSBOOST_FT_config_valid
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cc_id 1
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cc_name implicit_cc
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cc QSBOOST_PP_EMPTY
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_cond callable_builtin
#define _()
QSBOOST_PP_EXPAND(#)   include QSBOOST_FT_cc_file
#undef _
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_cond
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_cc_name
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_cc
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_cc_id
QSBOOST_PP_EXPAND(#) else
QSBOOST_PP_EXPAND(#)   undef QSBOOST_FT_config_valid
QSBOOST_PP_EXPAND(#) endif

#   else
#     undef QSBOOST_FT_config_valid
#   endif

#   include <qsboost/function_types/detail/encoding/aliases_undef.hpp>
#   include <qsboost/function_types/detail/encoding/undef.hpp>

#elif QSBOOST_FT_CC_PREPROCESSING

#   define QSBOOST_FT_cc_id  QSBOOST_PP_INC(QSBOOST_PP_FRAME_ITERATION(1))
#   define QSBOOST_FT_cc_inf \
        QSBOOST_PP_SEQ_ELEM(QSBOOST_PP_FRAME_ITERATION(1),QSBOOST_FT_CC_NAMES_SEQ)

#   define QSBOOST_FT_cc_pp_name QSBOOST_PP_TUPLE_ELEM(3,0,QSBOOST_FT_cc_inf)
#   define QSBOOST_FT_cc_name    QSBOOST_PP_TUPLE_ELEM(3,1,QSBOOST_FT_cc_inf)
#   define QSBOOST_FT_cc         QSBOOST_PP_TUPLE_ELEM(3,2,QSBOOST_FT_cc_inf)

#   define QSBOOST_FT_cond QSBOOST_PP_CAT(QSBOOST_FT_CC_,QSBOOST_FT_cc_pp_name)

#   if QSBOOST_FT_cond
#     define QSBOOST_FT_config_valid 1
#     include QSBOOST_FT_cc_file
#   endif

#   undef QSBOOST_FT_cond

#   undef QSBOOST_FT_cc_pp_name
#   undef QSBOOST_FT_cc_name
#   undef QSBOOST_FT_cc

#   undef QSBOOST_FT_cc_id
#   undef QSBOOST_FT_cc_inf

#else // if generating preprocessed file
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_cc_id QSBOOST_PP_INC(QSBOOST_PP_ITERATION())

#   define QSBOOST_FT_cc_inf \
        QSBOOST_PP_SEQ_ELEM(QSBOOST_PP_ITERATION(),QSBOOST_FT_CC_NAMES_SEQ)

#   define QSBOOST_FT_cc_pp_name QSBOOST_PP_TUPLE_ELEM(3,0,QSBOOST_FT_cc_inf)

#   define QSBOOST_FT_CC_DEF(name,index) \
        name QSBOOST_PP_TUPLE_ELEM(3,index,QSBOOST_FT_cc_inf)
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_CC_DEF(QSBOOST_FT_cc_name,1)
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_CC_DEF(QSBOOST_FT_cc,2)
#   undef  QSBOOST_FT_CC_DEF

#   define QSBOOST_FT_cc_cond_v QSBOOST_PP_CAT(QSBOOST_FT_CC_,QSBOOST_FT_cc_pp_name)
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_cond QSBOOST_FT_cc_cond_v
#   undef  QSBOOST_FT_cc_cond_v

#   undef QSBOOST_FT_cc_pp_name
#   undef QSBOOST_FT_cc_inf

QSBOOST_PP_EXPAND(#) if QSBOOST_FT_cond
QSBOOST_PP_EXPAND(#)   define QSBOOST_FT_config_valid 1
#define _()
QSBOOST_PP_EXPAND(#)   include QSBOOST_FT_cc_file
#undef _
QSBOOST_PP_EXPAND(#) endif

QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_cond

QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_cc_name
QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_cc

QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_cc_id

#endif


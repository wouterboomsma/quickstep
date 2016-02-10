
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#ifndef QSBOOST_FT_PREPROCESSING_MODE
// input:  BOOST_FT_mfp        0 or 1 <=> member function pointer?
// input:  BOOST_FT_type_name  BOOST_FT_type --> "R (* ..._type_name)()" (pass2)
#endif
// input:  BOOST_FT_syntax     type macro to use
// input:  BOOST_FT_cc         empty or cc specifier 
// input:  BOOST_FT_ell        empty or "..."
// input:  BOOST_FT_cv         empty or cv qualifiers
// input:  BOOST_FT_flags      single decimal integer encoding the flags
// output: BOOST_FT_n          number of component types (arity+1)
// output: BOOST_FT_arity      current arity
// output: BOOST_FT_type       macro that expands to the type
// output: BOOST_FT_tplargs(p) template arguments with given prefix
// output: BOOST_FT_params(p)  parameters with given prefix

#ifdef __WAVE__
#   pragma wave option(preserve: 0)
#endif

#ifndef QSBOOST_FT_ARITY_LOOP_IS_ITERATING

#   define QSBOOST_FT_AL_PREPROCESSED \
        QSBOOST_FT_AL_FILE(QSBOOST_FT_al_path,QSBOOST_FT_FROM_ARITY,QSBOOST_FT_mfp)

#   define QSBOOST_FT_AL_FILE(base_path,max_arity,mfp) \
        QSBOOST_FT_AL_FILE_I(base_path,max_arity,mfp)
#   define QSBOOST_FT_AL_FILE_I(base_path,max_arity,mfp) \
        <base_path/arity ## max_arity ## _ ## mfp.hpp>

#   if !defined(QSBOOST_FT_PREPROCESSING_MODE)

#     if QSBOOST_FT_MAX_ARITY < 10
#       define QSBOOST_FT_FROM_ARITY 0 
#     elif QSBOOST_FT_MAX_ARITY < 20
#       define QSBOOST_FT_FROM_ARITY 10
#     elif QSBOOST_FT_MAX_ARITY < 30
#       define QSBOOST_FT_FROM_ARITY 20
#     elif QSBOOST_FT_MAX_ARITY < 40
#       define QSBOOST_FT_FROM_ARITY 30
#     endif

#     if QSBOOST_FT_FROM_ARITY
#       include QSBOOST_FT_AL_PREPROCESSED
#     endif

#   elif !defined(QSBOOST_FT_FROM_ARITY) // single pass preprocessing
#     define QSBOOST_FT_FROM_ARITY 0

#   elif QSBOOST_FT_FROM_ARITY > 0       // arity20 includes arity10
QSBOOST_PP_EXPAND(#) include QSBOOST_FT_AL_PREPROCESSED
#   endif

#   undef QSBOOST_FT_AL_PREPROCESSED

#   undef QSBOOST_FT_AL_FILE
#   undef QSBOOST_FT_AL_FILE_I

#   if QSBOOST_FT_MAX_ARITY > QSBOOST_FT_FROM_ARITY

#     ifndef QSBOOST_FT_DETAIL_ARITY_LOOP_HPP_INCLUDED
#     define QSBOOST_FT_DETAIL_ARITY_LOOP_HPP_INCLUDED
#         include <qsboost/preprocessor/cat.hpp>
#         include <qsboost/preprocessor/tuple/eat.hpp>
#         include <qsboost/preprocessor/control/if.hpp>
#         include <qsboost/preprocessor/arithmetic/inc.hpp>
#         include <qsboost/preprocessor/facilities/empty.hpp>
#         include <qsboost/preprocessor/facilities/expand.hpp>
#         include <qsboost/preprocessor/iteration/iterate.hpp>
#         include <qsboost/preprocessor/repetition/enum_params.hpp>
#         include <qsboost/preprocessor/repetition/enum_shifted_params.hpp>
#         include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>
#     endif

#     define QSBOOST_FT_AL_INCLUDE_FILE <QSBOOST_FT_al_path/master.hpp>

#     define QSBOOST_FT_ARITY_LOOP_PREFIX 1
#     include QSBOOST_FT_AL_INCLUDE_FILE
#     undef  QSBOOST_FT_ARITY_LOOP_PREFIX

#     if !QSBOOST_PP_IS_ITERATING
#       define QSBOOST_PP_FILENAME_1 QSBOOST_FT_AL_INCLUDE_FILE
#     elif QSBOOST_PP_ITERATION_DEPTH() == 1
#       define QSBOOST_PP_FILENAME_2 QSBOOST_FT_AL_INCLUDE_FILE
#     else
#       error "loops nested too deeply"
#     endif

#     define QSBOOST_FT_arity QSBOOST_PP_ITERATION()
#     define QSBOOST_FT_n     QSBOOST_PP_INC(QSBOOST_FT_arity)

#     define QSBOOST_FT_type \
          QSBOOST_FT_syntax(QSBOOST_FT_cc,QSBOOST_FT_type_name QSBOOST_PP_EMPTY)\
               (QSBOOST_FT_params(QSBOOST_PP_EMPTY) QSBOOST_FT_ell) QSBOOST_FT_cv

#     define QSBOOST_FT_tplargs(prefx) \
          prefx() R QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_FT_arity,prefx() T)

#     if !QSBOOST_FT_mfp

#       define QSBOOST_FT_params(prefx) \
            QSBOOST_PP_IF(QSBOOST_FT_arity,QSBOOST_PP_ENUM_PARAMS, \
                QSBOOST_FT_nullary_param QSBOOST_PP_TUPLE_EAT(2))( \
                    QSBOOST_FT_arity,prefx() T) 
#     else

#       define QSBOOST_FT_params(prefx) \
            QSBOOST_PP_ENUM_SHIFTED_PARAMS(QSBOOST_FT_arity,prefx() T)

#     endif

#     if !QSBOOST_FT_FROM_ARITY 
#       define QSBOOST_PP_ITERATION_LIMITS (QSBOOST_FT_mfp, QSBOOST_FT_MAX_ARITY)
#     else
#       define QSBOOST_PP_ITERATION_LIMITS \
            (QSBOOST_FT_FROM_ARITY+1, QSBOOST_FT_MAX_ARITY)
#     endif

#     define QSBOOST_FT_ARITY_LOOP_IS_ITERATING 1
#     include QSBOOST_PP_ITERATE()
#     undef  QSBOOST_FT_ARITY_LOOP_IS_ITERATING

#     undef QSBOOST_FT_arity
#     undef QSBOOST_FT_params
#     undef QSBOOST_FT_tplargs
#     undef QSBOOST_FT_type

#     define QSBOOST_FT_ARITY_LOOP_SUFFIX 1
#     include QSBOOST_FT_AL_INCLUDE_FILE
#     undef  QSBOOST_FT_ARITY_LOOP_SUFFIX

#     undef QSBOOST_FT_AL_INCLUDE_FILE
#   endif

#   undef QSBOOST_FT_FROM_ARITY

#else
#   error "attempt to nest arity loops"
#endif


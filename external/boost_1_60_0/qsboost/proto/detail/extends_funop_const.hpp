#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #ifndef QSBOOST_NO_CXX11_VARIADIC_TEMPLATES
        QSBOOST_PROTO_EXTENDS_FUNCTION_()
        QSBOOST_PROTO_DEFINE_FUN_OP_VARIADIC_IMPL_(QSBOOST_PROTO_CONST)
    #else
        #include <qsboost/proto/detail/preprocessed/extends_funop_const.hpp>
    #endif

#else

    #define QSBOOST_PP_LOCAL_MACRO(N)                                                                 \
        QSBOOST_PROTO_DEFINE_FUN_OP_CONST(1, N, ~)                                                    \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/extends_funop_const.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file extends_funop_const.hpp
    /// Definitions for extends\<\>::operator()
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    QSBOOST_PROTO_EXTENDS_FUNCTION_()

    #define QSBOOST_PP_LOCAL_LIMITS                                                                   \
        (0, QSBOOST_PP_DEC(QSBOOST_PROTO_MAX_FUNCTION_CALL_ARITY))
    #include QSBOOST_PP_LOCAL_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#endif

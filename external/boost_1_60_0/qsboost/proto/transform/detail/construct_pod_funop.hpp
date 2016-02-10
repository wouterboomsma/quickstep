#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/construct_pod_funop.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/construct_pod_funop.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file construct_pod_funop.hpp
    /// Overloads of construct_\<\>::operator().
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                         \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/construct_pod_funop.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else

    #define N QSBOOST_PP_ITERATION()

    template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    QSBOOST_FORCEINLINE
    Type operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, &a)) const
    {
        Type that = {QSBOOST_PP_ENUM_PARAMS(N, a)};
        return that;
    }

    #undef N

#endif

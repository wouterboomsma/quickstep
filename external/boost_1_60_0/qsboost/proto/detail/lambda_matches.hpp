#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/lambda_matches.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_DEFINE_LAMBDA_MATCHES(Z, N, DATA)                                           \
        lambda_matches<                                                                             \
            QSBOOST_PP_CAT(Expr, N)                                                                   \
          , QSBOOST_PP_CAT(Grammar, N)                                                                \
        >

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/lambda_matches.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file lambda_matches.hpp
    /// Specializations of the lambda_matches template
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (2, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/lambda_matches.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_DEFINE_LAMBDA_MATCHES

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    template<
        template<QSBOOST_PP_ENUM_PARAMS(N, typename QSBOOST_PP_INTERCEPT)> class T
        QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename Expr)
        QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename Grammar)
    >
    struct lambda_matches<
        T<QSBOOST_PP_ENUM_PARAMS(N, Expr)>
      , T<QSBOOST_PP_ENUM_PARAMS(N, Grammar)>
        QSBOOST_PROTO_TEMPLATE_ARITY_PARAM(N)
    >
      : QSBOOST_PP_CAT(and_, N)<
            QSBOOST_PROTO_DEFINE_LAMBDA_MATCHES(~, 0, ~)::value,
            QSBOOST_PP_ENUM_SHIFTED(N, QSBOOST_PROTO_DEFINE_LAMBDA_MATCHES, ~)
        >
    {};

    #undef N

#endif

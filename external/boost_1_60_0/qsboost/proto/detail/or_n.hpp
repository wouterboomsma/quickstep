#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/or_n.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/or_n.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file or_n.hpp
    /// Definitions of or_N
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (2, QSBOOST_PROTO_MAX_LOGICAL_ARITY, <qsboost/proto/detail/or_n.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    template<bool B, typename Expr, typename BasicExpr, QSBOOST_PP_ENUM_PARAMS(N, typename G)>
    struct QSBOOST_PP_CAT(or_, N)
    #if 2 == N
      : mpl::bool_<matches_<Expr, BasicExpr, typename G1::proto_grammar>::value>
    {
        typedef G1 which;
    };
    #else
      : QSBOOST_PP_CAT(or_, QSBOOST_PP_DEC(N))<
            matches_<Expr, BasicExpr, typename G1::proto_grammar>::value
          , Expr, BasicExpr, QSBOOST_PP_ENUM_SHIFTED_PARAMS(N, G)
        >
    {};
    #endif

    template<typename Expr, typename BasicExpr QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename G)>
    struct QSBOOST_PP_CAT(or_, N)<true, Expr, BasicExpr, QSBOOST_PP_ENUM_PARAMS(N, G)>
      : mpl::true_
    {
        typedef G0 which;
    };

    #undef N

#endif

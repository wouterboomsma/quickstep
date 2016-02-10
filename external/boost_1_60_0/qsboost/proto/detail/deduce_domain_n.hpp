#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/deduce_domain_n.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_COMMON_DOMAIN2(Z, N, DATA)                                                  \
        typedef                                                                                     \
            typename common_domain2<common ## N, A ## N>::type                                      \
        QSBOOST_PP_CAT(common, QSBOOST_PP_INC(N));                                                      \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/deduce_domain_n.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    // deduce_domain_n.hpp
    // Definitions of common_domain[n] and deduce_domain[n] class templates.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (3, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/deduce_domain_n.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_COMMON_DOMAIN2

#else

    #define N QSBOOST_PP_ITERATION()

    template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    struct QSBOOST_PP_CAT(common_domain, N)
    {
        typedef A0 common1;
        QSBOOST_PP_REPEAT_FROM_TO(1, N, QSBOOST_PROTO_COMMON_DOMAIN2, ~)
        typedef QSBOOST_PP_CAT(common, N) type;
        QSBOOST_PROTO_ASSERT_VALID_DOMAIN(type);
    };

    template<QSBOOST_PP_ENUM_PARAMS(N, typename E)>
    struct QSBOOST_PP_CAT(deduce_domain, N)
      : QSBOOST_PP_CAT(common_domain, N)<
            QSBOOST_PP_ENUM_BINARY_PARAMS(
                N
              , typename domain_of<E, >::type QSBOOST_PP_INTERCEPT
            )
        >
    {};

    #undef N

#endif // BOOST_PROTO_DONT_USE_PREPROCESSED_FILES

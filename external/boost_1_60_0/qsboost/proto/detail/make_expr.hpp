#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/make_expr.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_expr.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_expr.hpp
    /// Contains overloads of make_expr() free function.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (2, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/make_expr.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    /// \overload
    ///
    template<typename Tag QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    QSBOOST_FORCEINLINE
    typename lazy_disable_if<
        is_domain<A0>
      , result_of::make_expr<
            Tag
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >
    >::type const
    make_expr(QSBOOST_PP_ENUM_BINARY_PARAMS(N, const A, &a))
    {
        return proto::detail::make_expr_<
            Tag
          , deduce_domain
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >()(QSBOOST_PP_ENUM_PARAMS(N, a));
    }

    /// \overload
    ///
    template<typename Tag, typename Domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename C)>
    QSBOOST_FORCEINLINE
    typename result_of::make_expr<
        Tag
      , Domain
        QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const C)
    >::type const
    make_expr(QSBOOST_PP_ENUM_BINARY_PARAMS(N, const C, &c))
    {
        return proto::detail::make_expr_<
            Tag
          , Domain
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const C)
        >()(QSBOOST_PP_ENUM_PARAMS(N, c));
    }

    #undef N

#endif

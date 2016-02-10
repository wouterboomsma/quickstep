#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/make_expr_.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_expr_.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_expr_.hpp
    /// Contains definition of make_expr_\<\> class template.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    template<
        typename Tag
      , typename Domain
        QSBOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
            QSBOOST_PROTO_MAX_ARITY
          , typename A
          , = void QSBOOST_PP_INTERCEPT
        )
      , typename _ = void
    >
    struct make_expr_
    {};

    template<typename Domain, typename A>
    struct make_expr_<tag::terminal, Domain, A
        QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PROTO_MAX_ARITY, void QSBOOST_PP_INTERCEPT)>
    {
        typedef typename proto::detail::protoify<A, Domain>::result_type result_type;

        QSBOOST_FORCEINLINE
        result_type operator()(typename add_reference<A>::type a) const
        {
            return proto::detail::protoify<A, Domain>()(a);
        }
    };

    template<typename A>
    struct make_expr_<tag::terminal, deduce_domain, A
        QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PROTO_MAX_ARITY, void QSBOOST_PP_INTERCEPT)>
      : make_expr_<tag::terminal, default_domain, A>
    {};

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                         \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/make_expr_.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()
    #define M QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N)

    template<typename Tag, typename Domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make_expr_<Tag, Domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
        QSBOOST_PP_ENUM_TRAILING_PARAMS(M, void QSBOOST_PP_INTERCEPT), void>
    {
        typedef
            QSBOOST_PP_CAT(list, N)<
                QSBOOST_PP_ENUM(N, QSBOOST_PROTO_AS_CHILD_TYPE, (A, ~, Domain))
            >
        proto_args;

        typedef typename base_expr<Domain, Tag, proto_args>::type expr_type;
        typedef typename Domain::proto_generator proto_generator;
        typedef typename proto_generator::template result<proto_generator(expr_type)>::type result_type;

        QSBOOST_FORCEINLINE
        result_type operator()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, typename add_reference<A, >::type a)) const
        {
            expr_type const that = {
                QSBOOST_PP_ENUM(N, QSBOOST_PROTO_AS_CHILD, (A, a, Domain))
            };
            return proto_generator()(that);
        }
    };

    template<typename Tag QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make_expr_<Tag, deduce_domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
        QSBOOST_PP_ENUM_TRAILING_PARAMS(M, void QSBOOST_PP_INTERCEPT), void>
      : make_expr_<
            Tag
          , typename QSBOOST_PP_CAT(deduce_domain, N)<QSBOOST_PP_ENUM_PARAMS(N, A)>::type
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
        >
    {};

    #undef N
    #undef M

#endif

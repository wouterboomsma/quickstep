#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/funop.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_AS_CHILD_TYPE(Z, N, DATA)                                                   \
        typename proto::result_of::as_child<QSBOOST_PP_CAT(A, N), Domain>::type                       \
        /**/

    #define QSBOOST_PROTO_AS_CHILD(Z, N, DATA)                                                        \
        proto::as_child<Domain>(QSBOOST_PP_CAT(a, N))                                                 \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/funop.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    // funop.hpp
    // Contains definition of funop[n]\<\> class template.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (0, QSBOOST_PP_DEC(QSBOOST_PROTO_MAX_FUNCTION_CALL_ARITY), <qsboost/proto/detail/funop.hpp>))
    #include QSBOOST_PP_ITERATE()

    #undef QSBOOST_PROTO_AS_CHILD
    #undef QSBOOST_PROTO_AS_CHILD_TYPE

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else

    /// \brief A helper metafunction for computing the
    /// return type of \c proto::expr\<\>::operator().
    template<typename Expr, typename Domain QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_ITERATION(), typename A)>
    struct QSBOOST_PP_CAT(funop, QSBOOST_PP_ITERATION())
    {
        typedef typename proto::base_expr<
            Domain
          , tag::function
          , QSBOOST_PP_CAT(list, QSBOOST_PP_INC(QSBOOST_PP_ITERATION()))<
                Expr &
                QSBOOST_PP_ENUM_TRAILING(QSBOOST_PP_ITERATION(), QSBOOST_PROTO_AS_CHILD_TYPE, ~)
            >
        >::type type;

        QSBOOST_FORCEINLINE
        static type const call(
            Expr &e
            QSBOOST_PP_ENUM_TRAILING_BINARY_PARAMS(QSBOOST_PP_ITERATION(), A, &a)
        )
        {
            type that = {
                e
                QSBOOST_PP_ENUM_TRAILING(QSBOOST_PP_ITERATION(), QSBOOST_PROTO_AS_CHILD, ~)
            };
            return that;
        }
    };

    /// \brief A helper metafunction for computing the
    /// return type of \c proto::expr\<\>::operator().
    template<typename Expr QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_ITERATION(), typename A), typename This, typename Domain>
    struct funop<Expr(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_ITERATION(), A)), This, Domain>
      : QSBOOST_PP_CAT(funop, QSBOOST_PP_ITERATION())<
            typename detail::same_cv<Expr, This>::type
          , Domain
            QSBOOST_PP_ENUM_TRAILING_BINARY_PARAMS(
                QSBOOST_PP_ITERATION()
              , typename remove_reference<A
              , >::type QSBOOST_PP_INTERCEPT
            )
        >
    {};

#endif // BOOST_PROTO_DONT_USE_PREPROCESSED_FILES

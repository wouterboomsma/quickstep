#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/poly_function_funop.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_NORMALIZE_ARG(Z, N, DATA)                                                   \
        static_cast<typename normalize_arg<QSBOOST_PP_CAT(A, N) const &>                              \
            ::reference>(QSBOOST_PP_CAT(a, N))                                                        \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/poly_function_funop.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    // poly_function_funop.hpp
    // Contains overloads of poly_function\<\>::operator()
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/poly_function_funop.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_NORMALIZE_ARG

#else

    #define N QSBOOST_PP_ITERATION()

    template<typename This QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct result<This(QSBOOST_PP_ENUM_PARAMS(N, A))>
      : Derived::template impl<
            QSBOOST_PP_ENUM_BINARY_PARAMS(
                N
              , typename normalize_arg<A
              , >::type QSBOOST_PP_INTERCEPT
            )
        >
    {
        typedef typename result::result_type type;
    };

    template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    typename result<
        Derived const(
            QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const & QSBOOST_PP_INTERCEPT)
        )
    >::type
    operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const &a)) const
    {
        result<
            Derived const(
                QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const & QSBOOST_PP_INTERCEPT)
            )
        > impl;

        return impl(QSBOOST_PP_ENUM(N, QSBOOST_PROTO_NORMALIZE_ARG, ~));
    }

    #undef N

#endif // BOOST_PROTO_DONT_USE_PREPROCESSED_FILES

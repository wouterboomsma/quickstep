#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/make_expr_funop.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_expr_funop.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_expr_funop.hpp
    /// Contains definition of make_expr\<\>::operator() member functions.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                     \
        (3, (2, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/make_expr_funop.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    template<typename This QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct result<This(QSBOOST_PP_ENUM_PARAMS(N, A))>
    {
        typedef
            typename result_of::make_expr<
                Tag
              , Domain
                QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
            >::type
        type;
    };

    /// \overload
    ///
    template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    QSBOOST_FORCEINLINE
    typename result_of::make_expr<
        Tag
      , Domain
        QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
    >::type const
    operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, const A, &a)) const
    {
        return proto::detail::make_expr_<
            Tag
          , Domain
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >()(QSBOOST_PP_ENUM_PARAMS(N, a));
    }

    #undef N

#endif

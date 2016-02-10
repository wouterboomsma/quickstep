#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/generate_by_value.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/generate_by_value.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file generate_by_value.hpp
    /// Contains definition of by_value_generator_\<\> class template.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/generate_by_value.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    template<typename Tag QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename Arg) >
    struct by_value_generator_<
        proto::expr<Tag, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, Arg)>, N>
    >
    {
        typedef
            QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, Arg)>
        src_args;

        typedef
            QSBOOST_PP_CAT(list, N)<
                QSBOOST_PP_ENUM_BINARY_PARAMS(N, typename uncvref<Arg, >::type QSBOOST_PP_INTERCEPT)
            >
        dst_args;

        typedef proto::expr<Tag, src_args, N> src_type;
        typedef proto::expr<Tag, dst_args, N> type;

        QSBOOST_FORCEINLINE
        static type const call(src_type const &e)
        {
            type that = {
                QSBOOST_PP_ENUM_PARAMS(N, e.child)
            };
            return that;
        }
    };

    template<typename Tag QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename Arg) >
    struct by_value_generator_<
        proto::basic_expr<Tag, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, Arg)>, N>
    >
    {
        typedef
            QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, Arg)>
        src_args;

        typedef
            QSBOOST_PP_CAT(list, N)<
                QSBOOST_PP_ENUM_BINARY_PARAMS(N, typename uncvref<Arg, >::type QSBOOST_PP_INTERCEPT)
            >
        dst_args;

        typedef proto::basic_expr<Tag, src_args, N> src_type;
        typedef proto::basic_expr<Tag, dst_args, N> type;

        QSBOOST_FORCEINLINE
        static type const call(src_type const &e)
        {
            type that = {
                QSBOOST_PP_ENUM_PARAMS(N, e.child)
            };
            return that;
        }
    };

    #undef N

#endif

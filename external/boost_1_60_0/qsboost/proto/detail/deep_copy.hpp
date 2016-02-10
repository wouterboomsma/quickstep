#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/deep_copy.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_DEFINE_DEEP_COPY_TYPE(Z, N, DATA)                                           \
        typename deep_copy_impl<                                                                    \
            typename remove_reference<                                                              \
                typename Expr::QSBOOST_PP_CAT(proto_child, N)                                         \
            >::type::proto_derived_expr                                                             \
        >::result_type                                                                              \
        /**/

    #define QSBOOST_PROTO_DEFINE_DEEP_COPY_FUN(Z, N, DATA)                                            \
        proto::deep_copy(e.proto_base().QSBOOST_PP_CAT(child, N))                                     \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/deep_copy.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file deep_copy.hpp
    /// Replace all nodes stored by reference by nodes stored by value.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/deep_copy.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_DEFINE_DEEP_COPY_FUN
    #undef QSBOOST_PROTO_DEFINE_DEEP_COPY_TYPE

#else

    #define N QSBOOST_PP_ITERATION()

    template<typename Expr>
    struct deep_copy_impl<Expr, N>
    {
        typedef
            typename base_expr<
                typename Expr::proto_domain
              , typename Expr::proto_tag
              , QSBOOST_PP_CAT(list, N)<
                    QSBOOST_PP_ENUM(N, QSBOOST_PROTO_DEFINE_DEEP_COPY_TYPE, ~)
                >
            >::type
        expr_type;

        typedef typename Expr::proto_generator proto_generator;
        typedef typename proto_generator::template result<proto_generator(expr_type)>::type result_type;

        template<typename Expr2, typename S, typename D>
        result_type operator()(Expr2 const &e, S const &, D const &) const
        {
            expr_type const that = {
                QSBOOST_PP_ENUM(N, QSBOOST_PROTO_DEFINE_DEEP_COPY_FUN, ~)
            };

            return proto_generator()(that);
        }
    };

    #undef N

#endif

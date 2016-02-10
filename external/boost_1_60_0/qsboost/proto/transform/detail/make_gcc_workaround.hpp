#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #if QSBOOST_WORKAROUND(__GNUC__, == 3) || (QSBOOST_WORKAROUND(__GNUC__, == 4) && __GNUC_MINOR__ == 0)
        #include <qsboost/proto/transform/detail/preprocessed/make_gcc_workaround.hpp>
    #endif

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_EXPR_MAKE_ARG(Z, M, DATA)                                                   \
        detail::as_lvalue(                                                                          \
            typename when<_, QSBOOST_PP_CAT(A, M)>::template impl<Expr, State, Data>()(e, s, d)       \
        )                                                                                           \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_gcc_workaround.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_gcc_workaround.hpp
    /// Special workaround code to make the make\<\> transform work on certain
    /// versions of gcc.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #if QSBOOST_WORKAROUND(__GNUC__, == 3) || (QSBOOST_WORKAROUND(__GNUC__, == 4) && __GNUC_MINOR__ == 0) || \
        (defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES))

        #define QSBOOST_PP_ITERATION_PARAMS_1                                                         \
            (3, (0, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/make_gcc_workaround.hpp>))
        #include QSBOOST_PP_ITERATE()

    #endif

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_EXPR_MAKE_ARG

#else

    #define N QSBOOST_PP_ITERATION()

    // work around GCC bug
    template<typename Tag, typename Args, long Arity QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make<proto::expr<Tag, Args, Arity>(QSBOOST_PP_ENUM_PARAMS(N, A))>
      : transform<make<proto::expr<Tag, Args, Arity>(QSBOOST_PP_ENUM_PARAMS(N, A))> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl : transform_impl<Expr, State, Data>
        {
            typedef proto::expr<Tag, Args, Arity> result_type;

            QSBOOST_FORCEINLINE
            result_type operator ()(
                typename impl::expr_param   e
              , typename impl::state_param  s
              , typename impl::data_param   d
            ) const
            {
                return proto::expr<Tag, Args, Arity>::make(
                    QSBOOST_PP_ENUM(N, QSBOOST_PROTO_EXPR_MAKE_ARG, DATA)
                );
            }
        };
    };

    template<typename Tag, typename Args, long Arity QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make<proto::basic_expr<Tag, Args, Arity>(QSBOOST_PP_ENUM_PARAMS(N, A))>
      : transform<make<proto::basic_expr<Tag, Args, Arity>(QSBOOST_PP_ENUM_PARAMS(N, A))> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl : transform_impl<Expr, State, Data>
        {
            typedef proto::basic_expr<Tag, Args, Arity> result_type;

            QSBOOST_FORCEINLINE
            result_type operator ()(
                typename impl::expr_param   e
              , typename impl::state_param  s
              , typename impl::data_param   d
            ) const
            {
                return proto::basic_expr<Tag, Args, Arity>::make(
                    QSBOOST_PP_ENUM(N, QSBOOST_PROTO_EXPR_MAKE_ARG, DATA)
                );
            }
        };
    };

    #undef N

#endif

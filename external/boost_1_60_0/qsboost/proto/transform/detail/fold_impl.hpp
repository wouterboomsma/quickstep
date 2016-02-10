#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/fold_impl.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_CHILD_N_TYPE(N)                                                             \
        QSBOOST_PP_CAT(proto_child, N)                                                                \
        /**/

    #define QSBOOST_PROTO_FOLD_STATE_TYPE(Z, N, DATA)                                                 \
        typedef                                                                                     \
            typename when<_, Fun>::template impl<                                                   \
                typename result_of::child_c<Expr, N>::type                                          \
              , QSBOOST_PP_CAT(state, N)                                                              \
              , Data                                                                                \
            >::result_type                                                                          \
        QSBOOST_PP_CAT(state, QSBOOST_PP_INC(N));                                                       \
        /**/

    #define QSBOOST_PROTO_FOLD_STATE(Z, N, DATA)                                                      \
        QSBOOST_PP_CAT(state, QSBOOST_PP_INC(N))                                                        \
        QSBOOST_PP_CAT(s, QSBOOST_PP_INC(N))                                                            \
          = typename when<_, Fun>::template impl<                                                   \
                typename result_of::child_c<Expr, N>::type                                          \
              , QSBOOST_PP_CAT(state, N)                                                              \
              , Data                                                                                \
            >()(                                                                                    \
                proto::child_c<N>(e)                                                                \
              , QSBOOST_PP_CAT(s, N)                                                                  \
              , d                                                                                   \
            );                                                                                      \
        /**/

    #define QSBOOST_PROTO_REVERSE_FOLD_STATE_TYPE(Z, N, DATA)                                         \
        typedef                                                                                     \
            typename when<_, Fun>::template impl<                                                   \
                typename result_of::child_c<                                                        \
                    Expr                                                                            \
                  , QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N))                                             \
                >::type                                                                             \
              , QSBOOST_PP_CAT(state, QSBOOST_PP_SUB(DATA, N))                                          \
              , Data                                                                                \
            >::result_type                                                                          \
        QSBOOST_PP_CAT(state, QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N)));                                   \
        /**/

    #define QSBOOST_PROTO_REVERSE_FOLD_STATE(Z, N, DATA)                                              \
        QSBOOST_PP_CAT(state, QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N)))                                    \
        QSBOOST_PP_CAT(s, QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N)))                                        \
          = typename when<_, Fun>::template impl<                                                   \
                typename result_of::child_c<                                                        \
                    Expr                                                                            \
                  , QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N))                                             \
                >::type                                                                             \
              , QSBOOST_PP_CAT(state, QSBOOST_PP_SUB(DATA, N))                                          \
              , Data                                                                                \
            >()(                                                                                    \
                proto::child_c<QSBOOST_PP_SUB(DATA, QSBOOST_PP_INC(N))>(e)                              \
              , QSBOOST_PP_CAT(s, QSBOOST_PP_SUB(DATA, N))                                              \
              , d                                                                                   \
            );                                                                                      \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/fold_impl.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file fold_impl.hpp
    /// Contains definition of fold_impl<> and reverse_fold_impl<> templates.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/fold_impl.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_REVERSE_FOLD_STATE
    #undef QSBOOST_PROTO_REVERSE_FOLD_STATE_TYPE
    #undef QSBOOST_PROTO_FOLD_STATE
    #undef QSBOOST_PROTO_FOLD_STATE_TYPE
    #undef QSBOOST_PROTO_CHILD_N_TYPE

#else

    #define N QSBOOST_PP_ITERATION()

    template<typename State0, typename Fun, typename Expr, typename State, typename Data>
    struct fold_impl<State0, Fun, Expr, State, Data, N>
      : transform_impl<Expr, State, Data>
    {
        typedef typename when<_, State0>::template impl<Expr, State, Data>::result_type state0;
        QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_FOLD_STATE_TYPE, N)
        typedef QSBOOST_PP_CAT(state, N) result_type;

        result_type operator ()(
            typename fold_impl::expr_param e
          , typename fold_impl::state_param s
          , typename fold_impl::data_param d
        ) const
        {
            state0 s0 =
                typename when<_, State0>::template impl<Expr, State, Data>()(e, s, d);
            QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_FOLD_STATE, N)
            return QSBOOST_PP_CAT(s, N);
        }
    };

    template<typename State0, typename Fun, typename Expr, typename State, typename Data>
    struct reverse_fold_impl<State0, Fun, Expr, State, Data, N>
      : transform_impl<Expr, State, Data>
    {
        typedef typename when<_, State0>::template impl<Expr, State, Data>::result_type QSBOOST_PP_CAT(state, N);
        QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_REVERSE_FOLD_STATE_TYPE, N)
        typedef state0 result_type;

        result_type operator ()(
            typename reverse_fold_impl::expr_param e
          , typename reverse_fold_impl::state_param s
          , typename reverse_fold_impl::data_param d
        ) const
        {
            QSBOOST_PP_CAT(state, N) QSBOOST_PP_CAT(s, N) =
                typename when<_, State0>::template impl<Expr, State, Data>()(e, s, d);
            QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_REVERSE_FOLD_STATE, N)
            return s0;
        }
    };

    #undef N

#endif

#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/and_n.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/and_n.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file and_n.hpp
    /// Definitions of and_N, and_impl
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (2, QSBOOST_PP_MAX(QSBOOST_PROTO_MAX_ARITY, QSBOOST_PROTO_MAX_LOGICAL_ARITY), <qsboost/proto/detail/and_n.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    // Assymetry here between the handling of and_N and or_N because
    // and_N is used by lambda_matches up to BOOST_PROTO_MAX_ARITY,
    // regardless of how low BOOST_PROTO_MAX_LOGICAL_ARITY is.
    template<bool B, QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_DEC(N), typename P)>
    struct QSBOOST_PP_CAT(and_, N)
    #if 2 == N
      : mpl::bool_<P0::value>
    {};
    #else
      : QSBOOST_PP_CAT(and_, QSBOOST_PP_DEC(N))<
            P0::value QSBOOST_PP_COMMA_IF(QSBOOST_PP_SUB(N,2))
            QSBOOST_PP_ENUM_SHIFTED_PARAMS(QSBOOST_PP_DEC(N), P)
        >
    {};
    #endif

    template<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_DEC(N), typename P)>
    struct QSBOOST_PP_CAT(and_, N)<false, QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_DEC(N), P)>
      : mpl::false_
    {};

    #if N <= QSBOOST_PROTO_MAX_LOGICAL_ARITY

        template<QSBOOST_PP_ENUM_PARAMS(N, typename G), typename Expr, typename State, typename Data>
        struct _and_impl<proto::and_<QSBOOST_PP_ENUM_PARAMS(N, G)>, Expr, State, Data>
          : proto::transform_impl<Expr, State, Data>
        {
            #define M0(Z, N, DATA)                                                            \
            typedef                                                                           \
                typename proto::when<proto::_, QSBOOST_PP_CAT(G, N)>                            \
                    ::template impl<Expr, State, Data>                                        \
            QSBOOST_PP_CAT(Gimpl, N);                                                           \
            /**/
            QSBOOST_PP_REPEAT(N, M0, ~)
            #undef M0

            typedef typename QSBOOST_PP_CAT(Gimpl, QSBOOST_PP_DEC(N))::result_type result_type;

            result_type operator()(
                typename _and_impl::expr_param e
              , typename _and_impl::state_param s
              , typename _and_impl::data_param d
            ) const
            {
                // Fix: jfalcou - 12/29/2010
                // Avoid the use of comma operator here so as not to find Proto's
                // by accident.
                // expands to G0()(e,s,d); G1()(e,s,d); ... G{N-1}()(e,s,d);
                #define M0(Z,N,DATA) QSBOOST_PP_CAT(Gimpl,N)()(e,s,d);
                QSBOOST_PP_REPEAT(QSBOOST_PP_DEC(N),M0,~)
                return QSBOOST_PP_CAT(Gimpl,QSBOOST_PP_DEC(N))()(e,s,d);
                #undef M0
            }
        };

    #endif

    #undef N

#endif

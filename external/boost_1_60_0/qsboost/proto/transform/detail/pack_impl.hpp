#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/pack_impl.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/pack_impl.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file pack_impl.hpp
    /// Contains helpers for pseudo-pack expansion.
    //
    //  Copyright 2012 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (0, QSBOOST_PP_DEC(QSBOOST_PROTO_MAX_ARITY), <qsboost/proto/transform/detail/pack_impl.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else
    #if QSBOOST_PP_ITERATION_DEPTH() == 1
        #define N QSBOOST_PP_ITERATION()
        #define M QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N)
        #define M0(Z, X, D)  typename expand_pattern_helper<proto::_child_c<X>, Fun>::type

        template<typename Fun, typename Cont>
        struct expand_pattern<QSBOOST_PP_INC(N), Fun, Cont>
          : Cont::template cat<QSBOOST_PP_ENUM(QSBOOST_PP_INC(N), M0, ~)>
        {
            QSBOOST_MPL_ASSERT_MSG(
                (expand_pattern_helper<proto::_child_c<0>, Fun>::applied::value)
              , NO_PACK_EXPRESSION_FOUND_IN_UNPACKING_PATTERN
              , (Fun)
            );
        };

        template<typename Ret QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct QSBOOST_PP_CAT(expand_pattern_rest_, N)
        {
            template<QSBOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(QSBOOST_PP_INC(M), typename C, void)>
            struct cat;

            #define QSBOOST_PP_ITERATION_PARAMS_2                                                     \
                (3, (1, M, <qsboost/proto/transform/detail/pack_impl.hpp>))
            #include QSBOOST_PP_ITERATE()
        };
        #undef M0
        #undef M
        #undef N
    #else
        #define I QSBOOST_PP_ITERATION()
        #define J QSBOOST_PP_RELATIVE_ITERATION(1)
            template<QSBOOST_PP_ENUM_PARAMS(I, typename C)>
            struct cat<QSBOOST_PP_ENUM_PARAMS(I, C)>
            {
                typedef msvc_fun_workaround<Ret(QSBOOST_PP_ENUM_PARAMS(J, A) QSBOOST_PP_COMMA_IF(J) QSBOOST_PP_ENUM_PARAMS(I, C))> type;
            };
        #undef J
        #undef I
    #endif
#endif

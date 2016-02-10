#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/default_function_impl.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_DEF_FUN_INVOKE_ARG(Z, M, DATA)                                              \
        QSBOOST_PROTO_DEFAULT_EVAL(Z, QSBOOST_PP_ADD(M, 2), DATA)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/default_function_impl.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file default_function_impl.hpp
    /// Contains definition of the default_function_impl, the implementation of the
    /// _default transform for function-like nodes.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (3, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/default_function_impl.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_DEF_FUN_INVOKE_ARG

#else

    #define N QSBOOST_PP_ITERATION()

    template<typename Grammar, typename Expr, typename State, typename Data>
    struct default_function_impl<Grammar, Expr, State, Data, N>
      : transform_impl<Expr, State, Data>
    {
        QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_DEFAULT_EVAL_TYPE, Expr)

        typedef
            typename proto::detail::result_of_fixup<r0>::type
        function_type;

        typedef
            typename QSBOOST_PROTO_RESULT_OF<
                function_type(QSBOOST_PP_ENUM_SHIFTED_PARAMS(N, r))
            >::type
        result_type;

        result_type operator ()(
            typename default_function_impl::expr_param e
          , typename default_function_impl::state_param s
          , typename default_function_impl::data_param d
        ) const
        {
            return this->invoke(e, s, d, is_member_function_pointer<function_type>());
        }

    private:
        result_type invoke(
            typename default_function_impl::expr_param e
          , typename default_function_impl::state_param s
          , typename default_function_impl::data_param d
          , mpl::false_
        ) const
        {
            return QSBOOST_PROTO_DEFAULT_EVAL(~, 0, e)(
                QSBOOST_PP_ENUM_SHIFTED(N, QSBOOST_PROTO_DEFAULT_EVAL, e)
            );
        }

        result_type invoke(
            typename default_function_impl::expr_param e
          , typename default_function_impl::state_param s
          , typename default_function_impl::data_param d
          , mpl::true_
        ) const
        {
            QSBOOST_PROTO_USE_GET_POINTER();
            typedef typename detail::class_member_traits<function_type>::class_type class_type;
            return (
                QSBOOST_PROTO_GET_POINTER(class_type, (QSBOOST_PROTO_DEFAULT_EVAL(~, 1, e))) ->* 
                QSBOOST_PROTO_DEFAULT_EVAL(~, 0, e)
            )(QSBOOST_PP_ENUM(QSBOOST_PP_SUB(N, 2), QSBOOST_PROTO_DEF_FUN_INVOKE_ARG, e));
        }
    };

    #undef N

#endif

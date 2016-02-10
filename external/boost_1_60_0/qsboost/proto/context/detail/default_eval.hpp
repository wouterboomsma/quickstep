#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/context/detail/preprocessed/default_eval.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_DEFAULT_EVAL_SHIFTED(Z, M, DATA)                                            \
        QSBOOST_PROTO_DEFAULT_EVAL(Z, QSBOOST_PP_ADD(M, 2), DATA)                                       \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/default_eval.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file default_eval.hpp
    /// Contains specializations of the default_eval\<\> class template.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (3, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/context/detail/default_eval.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_DEFAULT_EVAL_SHIFTED

#else

    #define N QSBOOST_PP_ITERATION()

    template<typename Expr, typename Context>
    struct default_eval<Expr, Context, proto::tag::function, N>
    {
        typedef
            typename proto::detail::result_of_fixup<
                QSBOOST_PROTO_DEFAULT_EVAL_TYPE(~, 0, Expr)
            >::type
        function_type;

        typedef
            typename QSBOOST_PROTO_RESULT_OF<
                function_type(QSBOOST_PP_ENUM_SHIFTED(N, QSBOOST_PROTO_DEFAULT_EVAL_TYPE, Expr))
            >::type
        result_type;

        result_type operator ()(Expr &expr, Context &context) const
        {
            return this->invoke(expr, context, is_member_function_pointer<function_type>());
        }

    private:
        result_type invoke(Expr &expr, Context &context, mpl::false_) const
        {
            return QSBOOST_PROTO_DEFAULT_EVAL(~, 0, expr)(
                QSBOOST_PP_ENUM_SHIFTED(N, QSBOOST_PROTO_DEFAULT_EVAL, expr)
            );
        }

        result_type invoke(Expr &expr, Context &context, mpl::true_) const
        {
            QSBOOST_PROTO_USE_GET_POINTER();
            typedef typename detail::class_member_traits<function_type>::class_type class_type;
            return (
                QSBOOST_PROTO_GET_POINTER(class_type, (QSBOOST_PROTO_DEFAULT_EVAL(~, 1, expr))) ->*
                QSBOOST_PROTO_DEFAULT_EVAL(~, 0, expr)
            )(QSBOOST_PP_ENUM(QSBOOST_PP_SUB(N, 2), QSBOOST_PROTO_DEFAULT_EVAL_SHIFTED, expr));
        }
    };

    #undef N

#endif

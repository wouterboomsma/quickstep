#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/lazy.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/lazy.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file lazy.hpp
    /// Contains definition of the lazy<> transform.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (0, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/lazy.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else

    #define N QSBOOST_PP_ITERATION()

    /// \brief A PrimitiveTransform that uses <tt>make\<\></tt> to build
    /// a CallableTransform, and then uses <tt>call\<\></tt> to apply it.
    ///
    /// <tt>lazy\<\></tt> is useful as a higher-order transform, when the
    /// transform to be applied depends on the current state of the
    /// transformation. The invocation of the <tt>make\<\></tt> transform
    /// evaluates any nested transforms, and the resulting type is treated
    /// as a CallableTransform, which is evaluated with <tt>call\<\></tt>.
    template<typename Object QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct lazy<Object(QSBOOST_PP_ENUM_PARAMS(N, A))>
      : transform<lazy<Object(QSBOOST_PP_ENUM_PARAMS(N, A))> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl
          : call<
                typename make<Object>::template impl<Expr, State, Data>::result_type
                (QSBOOST_PP_ENUM_PARAMS(N, A))
            >::template impl<Expr, State, Data>
        {};
    };

    #if N > 0
    template<typename Object QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct lazy<Object(QSBOOST_PP_ENUM_PARAMS(N, A)...)>
      : transform<lazy<Object(QSBOOST_PP_ENUM_PARAMS(N, A)...)> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl
          : lazy<
                typename detail::expand_pattern<
                    proto::arity_of<Expr>::value
                  , QSBOOST_PP_CAT(A, QSBOOST_PP_DEC(N))
                  , detail::QSBOOST_PP_CAT(expand_pattern_rest_, QSBOOST_PP_DEC(N))<
                        Object
                        QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_DEC(N), A)
                    >
                >::type
            >::template impl<Expr, State, Data>
        {};
    };
    #endif

    #undef N

#endif

#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/transform/detail/preprocessed/make.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_MAKE_IF(Z, M, DATA)                                                         \
        make_if_<QSBOOST_PP_CAT(A, M), Expr, State, Data>                                             \
        /**/

    #define QSBOOST_PROTO_MAKE_IF_TYPE(Z, M, DATA)                                                    \
        typename QSBOOST_PROTO_MAKE_IF(Z, M, DATA) ::type                                             \
        /**/

    #define QSBOOST_PROTO_MAKE_IF_APPLIED(Z, M, DATA)                                                 \
        QSBOOST_PROTO_MAKE_IF(Z, M, DATA) ::applied ||                                                \
        /**/

    #define QSBOOST_PROTO_CONSTRUCT_ARG(Z, M, DATA)                                                   \
        detail::as_lvalue(                                                                          \
            typename when<_, QSBOOST_PP_CAT(A, M)>::template impl<Expr, State, Data>()(e, s, d)       \
        )                                                                                           \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/make.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make.hpp
    /// Contains definition of the make<> transform.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (0, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/transform/detail/make.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_CONSTRUCT_ARG
    #undef QSBOOST_PROTO_MAKE_IF_APPLIED
    #undef QSBOOST_PROTO_MAKE_IF_TYPE
    #undef QSBOOST_PROTO_MAKE_IF

#else

    #define N QSBOOST_PP_ITERATION()

    namespace detail
    {
        #if N > 0

        template<
            template<QSBOOST_PP_ENUM_PARAMS(N, typename QSBOOST_PP_INTERCEPT)> class R
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
          , typename Expr, typename State, typename Data
        >
        struct make_<
            R<QSBOOST_PP_ENUM_PARAMS(N, A)>
          , Expr, State, Data
            QSBOOST_PROTO_TEMPLATE_ARITY_PARAM(N)
        >
          : nested_type_if<
                R<QSBOOST_PP_ENUM(N, QSBOOST_PROTO_MAKE_IF_TYPE, ~)>
              , (QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_MAKE_IF_APPLIED, ~) false)
            >
        {};

        template<
            template<QSBOOST_PP_ENUM_PARAMS(N, typename QSBOOST_PP_INTERCEPT)> class R
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
          , typename Expr, typename State, typename Data
        >
        struct make_<
            noinvoke<R<QSBOOST_PP_ENUM_PARAMS(N, A)> >
          , Expr, State, Data
            QSBOOST_PROTO_TEMPLATE_ARITY_PARAM(1)
        >
        {
            typedef R<QSBOOST_PP_ENUM(N, QSBOOST_PROTO_MAKE_IF_TYPE, ~)> type;
            static bool const applied = true;
        };

        #endif

        template<typename R QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct is_applyable<R(QSBOOST_PP_ENUM_PARAMS(N, A))>
          : mpl::true_
        {};

        template<typename R QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct is_applyable<R(*)(QSBOOST_PP_ENUM_PARAMS(N, A))>
          : mpl::true_
        {};

        template<typename T, typename A>
        struct construct_<proto::expr<T, A, N>, true>
        {
            typedef proto::expr<T, A, N> result_type;

            template<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_MAX(N, 1), typename A)>
            QSBOOST_FORCEINLINE
            result_type operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PP_MAX(N, 1), A, &a)) const
            {
                return result_type::make(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_MAX(N, 1), a));
            }
        };

        template<typename T, typename A>
        struct construct_<proto::basic_expr<T, A, N>, true>
        {
            typedef proto::basic_expr<T, A, N> result_type;

            template<QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_MAX(N, 1), typename A)>
            QSBOOST_FORCEINLINE
            result_type operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(QSBOOST_PP_MAX(N, 1), A, &a)) const
            {
                return result_type::make(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_MAX(N, 1), a));
            }
        };

        template<typename Type QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        QSBOOST_FORCEINLINE
        Type construct(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, &a))
        {
            return construct_<Type>()(QSBOOST_PP_ENUM_PARAMS(N, a));
        }

    } // namespace detail

    /// \brief A PrimitiveTransform which computes a type by evaluating any
    /// nested transforms and then constructs an object of that type with the
    /// current expression, state and data, transformed according
    /// to \c A0 through \c AN.
    template<typename Object QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make<Object(QSBOOST_PP_ENUM_PARAMS(N, A))>
      : transform<make<Object(QSBOOST_PP_ENUM_PARAMS(N, A))> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl : transform_impl<Expr, State, Data>
        {
            /// \brief <tt>boost::result_of\<make\<Object\>(Expr, State, Data)\>::type</tt>
            typedef typename detail::make_if_<Object, Expr, State, Data>::type result_type;

            /// Let \c ax be <tt>when\<_, Ax\>()(e, s, d)</tt>
            /// for each \c x in <tt>[0,N]</tt>.
            /// Return <tt>result_type(a0, a1,... aN)</tt>.
            ///
            /// \param e The current expression
            /// \param s The current state
            /// \param d An arbitrary data
            QSBOOST_FORCEINLINE
            result_type operator ()(
                typename impl::expr_param   e
              , typename impl::state_param  s
              , typename impl::data_param   d
            ) const
            {
                proto::detail::ignore_unused(e);
                proto::detail::ignore_unused(s);
                proto::detail::ignore_unused(d);
                return detail::construct<result_type>(QSBOOST_PP_ENUM(N, QSBOOST_PROTO_CONSTRUCT_ARG, DATA));
            }
        };
    };

    #if N > 0
    /// \brief A PrimitiveTransform which computes a type by evaluating any
    /// nested transforms and then constructs an object of that type with the
    /// current expression, state and data, transformed according
    /// to \c A0 through \c AN.
    template<typename Object QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
    struct make<Object(QSBOOST_PP_ENUM_PARAMS(N, A)...)>
      : transform<make<Object(QSBOOST_PP_ENUM_PARAMS(N, A)...)> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl
          : make<
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

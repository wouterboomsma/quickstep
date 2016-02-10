#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/traits.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #define QSBOOST_PROTO_CHILD(Z, N, DATA)                                                           \
        /** INTERNAL ONLY */                                                                        \
        typedef QSBOOST_PP_CAT(DATA, N) QSBOOST_PP_CAT(proto_child, N);                                 \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/traits.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file traits.hpp
    /// Definitions of proto::function, proto::nary_expr and proto::result_of::child_c
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (0, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/traits.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_CHILD

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()

    #if N > 0
        /// \brief A metafunction for generating function-call expression types,
        /// a grammar element for matching function-call expressions, and a
        /// PrimitiveTransform that dispatches to the <tt>pass_through\<\></tt>
        /// transform.
        template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
        struct function
        #if N != QSBOOST_PROTO_MAX_ARITY
        <
            QSBOOST_PP_ENUM_PARAMS(N, A)
            QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N), void QSBOOST_PP_INTERCEPT)
        >
        #endif
          : proto::transform<
                function<
                    QSBOOST_PP_ENUM_PARAMS(N, A)
                    QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N), void QSBOOST_PP_INTERCEPT)
                >
              , int
            >
        {
            typedef proto::expr<proto::tag::function, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, A)>, N> type;
            typedef proto::basic_expr<proto::tag::function, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, A)>, N> proto_grammar;

            template<typename Expr, typename State, typename Data>
            struct impl
              : detail::pass_through_impl<function, deduce_domain, Expr, State, Data>
            {};

            /// INTERNAL ONLY
            typedef proto::tag::function proto_tag;
            QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_CHILD, A)
            QSBOOST_PP_REPEAT_FROM_TO(
                N
              , QSBOOST_PROTO_MAX_ARITY
              , QSBOOST_PROTO_CHILD
              , detail::if_vararg<QSBOOST_PP_CAT(A, QSBOOST_PP_DEC(N))> QSBOOST_PP_INTERCEPT
            )
        };

        /// \brief A metafunction for generating n-ary expression types with a
        /// specified tag type,
        /// a grammar element for matching n-ary expressions, and a
        /// PrimitiveTransform that dispatches to the <tt>pass_through\<\></tt>
        /// transform.
        ///
        /// Use <tt>nary_expr\<_, vararg\<_\> \></tt> as a grammar element to match any
        /// n-ary expression; that is, any non-terminal.
        template<typename Tag QSBOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>
        struct nary_expr
        #if N != QSBOOST_PROTO_MAX_ARITY
        <
            Tag
            QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
            QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N), void QSBOOST_PP_INTERCEPT)
        >
        #endif
          : proto::transform<
                nary_expr<
                    Tag
                    QSBOOST_PP_ENUM_TRAILING_PARAMS(N, A)
                    QSBOOST_PP_ENUM_TRAILING_PARAMS(QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N), void QSBOOST_PP_INTERCEPT)
                >
              , int
            >
        {
            typedef proto::expr<Tag, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, A)>, N> type;
            typedef proto::basic_expr<Tag, QSBOOST_PP_CAT(list, N)<QSBOOST_PP_ENUM_PARAMS(N, A)>, N> proto_grammar;

            template<typename Expr, typename State, typename Data>
            struct impl
              : detail::pass_through_impl<nary_expr, deduce_domain, Expr, State, Data>
            {};

            /// INTERNAL ONLY
            typedef Tag proto_tag;
            QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_CHILD, A)
            QSBOOST_PP_REPEAT_FROM_TO(
                N
              , QSBOOST_PROTO_MAX_ARITY
              , QSBOOST_PROTO_CHILD
              , detail::if_vararg<QSBOOST_PP_CAT(A, QSBOOST_PP_DEC(N))> QSBOOST_PP_INTERCEPT
            )
        };

        namespace detail
        {
            template<
                template<QSBOOST_PP_ENUM_PARAMS(N, typename QSBOOST_PP_INTERCEPT)> class T
              , QSBOOST_PP_ENUM_PARAMS(N, typename A)
            >
            struct is_callable_<T<QSBOOST_PP_ENUM_PARAMS(N, A)> QSBOOST_PROTO_TEMPLATE_ARITY_PARAM(N)>
              : is_same<QSBOOST_PP_CAT(A, QSBOOST_PP_DEC(N)), callable>
            {};
        }

    #endif

        namespace result_of
        {
            /// \brief A metafunction that returns the type of the Nth child
            /// of a Proto expression.
            ///
            /// A metafunction that returns the type of the Nth child
            /// of a Proto expression. \c N must be less than
            /// \c Expr::proto_arity::value.
            template<typename Expr>
            struct child_c<Expr, N>
            {
                /// Verify that we are not operating on a terminal
                QSBOOST_STATIC_ASSERT(0 != Expr::proto_arity_c);

                /// The raw type of the Nth child as it is stored within
                /// \c Expr. This may be a value or a reference
                typedef typename Expr::QSBOOST_PP_CAT(proto_child, N) value_type;

                /// The "value" type of the child, suitable for return by value,
                /// computed as follows:
                /// \li <tt>T const &</tt> becomes <tt>T</tt>
                /// \li <tt>T &</tt> becomes <tt>T</tt>
                /// \li <tt>T</tt> becomes <tt>T</tt>
                typedef typename detail::expr_traits<typename Expr::QSBOOST_PP_CAT(proto_child, N)>::value_type type;
            };

            template<typename Expr>
            struct child_c<Expr &, N>
            {
                /// Verify that we are not operating on a terminal
                QSBOOST_STATIC_ASSERT(0 != Expr::proto_arity_c);

                /// The raw type of the Nth child as it is stored within
                /// \c Expr. This may be a value or a reference
                typedef typename Expr::QSBOOST_PP_CAT(proto_child, N) value_type;

                /// The "reference" type of the child, suitable for return by
                /// reference, computed as follows:
                /// \li <tt>T const &</tt> becomes <tt>T const &</tt>
                /// \li <tt>T &</tt> becomes <tt>T &</tt>
                /// \li <tt>T</tt> becomes <tt>T &</tt>
                typedef typename detail::expr_traits<typename Expr::QSBOOST_PP_CAT(proto_child, N)>::reference type;

                /// INTERNAL ONLY
                ///
                QSBOOST_FORCEINLINE
                static type call(Expr &e)
                {
                    return e.proto_base().QSBOOST_PP_CAT(child, N);
                }
            };

            template<typename Expr>
            struct child_c<Expr const &, N>
            {
                /// Verify that we are not operating on a terminal
                QSBOOST_STATIC_ASSERT(0 != Expr::proto_arity_c);

                /// The raw type of the Nth child as it is stored within
                /// \c Expr. This may be a value or a reference
                typedef typename Expr::QSBOOST_PP_CAT(proto_child, N) value_type;

                /// The "const reference" type of the child, suitable for return by
                /// const reference, computed as follows:
                /// \li <tt>T const &</tt> becomes <tt>T const &</tt>
                /// \li <tt>T &</tt> becomes <tt>T &</tt>
                /// \li <tt>T</tt> becomes <tt>T const &</tt>
                typedef typename detail::expr_traits<typename Expr::QSBOOST_PP_CAT(proto_child, N)>::const_reference type;

                /// INTERNAL ONLY
                ///
                QSBOOST_FORCEINLINE
                static type call(Expr const &e)
                {
                    return e.proto_base().QSBOOST_PP_CAT(child, N);
                }
            };
        }

    #undef N

#endif

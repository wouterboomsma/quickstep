#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/unpack_expr_.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE(Z, N, DATA)                                       \
        typedef typename fusion::result_of::next<                                                   \
            QSBOOST_PP_CAT(fusion_iterator, N)>::type                                                 \
                QSBOOST_PP_CAT(fusion_iterator, QSBOOST_PP_INC(N));                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_ITERATORS_TYPE(N)                                                    \
        typedef                                                                                     \
            typename fusion::result_of::begin<Sequence const>::type                                 \
        fusion_iterator0;                                                                           \
        QSBOOST_PP_REPEAT(QSBOOST_PP_DEC(N), QSBOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE, fusion_iterator)    \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
        typename add_const<                                                                         \
            typename fusion::result_of::value_of<                                                   \
                QSBOOST_PP_CAT(fusion_iterator, N)                                                    \
            >::type                                                                                 \
        >::type                                                                                     \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_NEXT_ITERATOR(Z, N, DATA)                                            \
        QSBOOST_PP_CAT(fusion_iterator, QSBOOST_PP_INC(N)) QSBOOST_PP_CAT(it, QSBOOST_PP_INC(N)) =          \
            fusion::next(QSBOOST_PP_CAT(it, N));                                                      \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_ITERATORS(N)                                                         \
        fusion_iterator0 it0 = fusion::begin(sequence);                                             \
        QSBOOST_PP_REPEAT(QSBOOST_PP_DEC(N), QSBOOST_PROTO_FUSION_NEXT_ITERATOR, fusion_iterator)         \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_AT(Z, N, DATA)                                                       \
        *QSBOOST_PP_CAT(it, N)                                                                        \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_AS_CHILD_AT_TYPE(Z, N, DATA)                                         \
        typename detail::protoify<                                                                  \
            QSBOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
          , Domain                                                                                  \
        >::result_type                                                                              \
        /**/

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_FUSION_AS_CHILD_AT(Z, N, DATA)                                              \
        detail::protoify<                                                                           \
            QSBOOST_PROTO_FUSION_AT_TYPE(Z, N, DATA)                                                  \
          , Domain                                                                                  \
        >()(QSBOOST_PROTO_FUSION_AT(Z, N, DATA))                                                      \
        /**/

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/unpack_expr_.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file make_expr_.hpp
    /// Contains definition of make_expr_\<\> class template.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    template<typename Tag, typename Domain, typename Sequence, std::size_t Size>
    struct unpack_expr_
    {};

    template<typename Domain, typename Sequence>
    struct unpack_expr_<tag::terminal, Domain, Sequence, 1u>
    {
        typedef
            typename add_const<
                typename fusion::result_of::value_of<
                    typename fusion::result_of::begin<Sequence>::type
                >::type
            >::type
        terminal_type;

        typedef
            typename proto::detail::protoify<
                terminal_type
              , Domain
            >::result_type
        type;

        QSBOOST_FORCEINLINE
        static type const call(Sequence const &sequence)
        {
            return proto::detail::protoify<terminal_type, Domain>()(fusion::at_c<0>(sequence));
        }
    };

    template<typename Sequence>
    struct unpack_expr_<tag::terminal, deduce_domain, Sequence, 1u>
      : unpack_expr_<tag::terminal, default_domain, Sequence, 1u>
    {};

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                         \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/unpack_expr_.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_FUSION_AT
    #undef QSBOOST_PROTO_FUSION_AT_TYPE
    #undef QSBOOST_PROTO_FUSION_AS_CHILD_AT
    #undef QSBOOST_PROTO_FUSION_AS_CHILD_AT_TYPE
    #undef QSBOOST_PROTO_FUSION_NEXT_ITERATOR
    #undef QSBOOST_PROTO_FUSION_NEXT_ITERATOR_TYPE
    #undef QSBOOST_PROTO_FUSION_ITERATORS
    #undef QSBOOST_PROTO_FUSION_ITERATORS_TYPE

#else // BOOST_PP_IS_ITERATING

    #define N QSBOOST_PP_ITERATION()
    #define M QSBOOST_PP_SUB(QSBOOST_PROTO_MAX_ARITY, N)

    template<typename Tag, typename Domain, typename Sequence>
    struct unpack_expr_<Tag, Domain, Sequence, N>
    {
        QSBOOST_PROTO_FUSION_ITERATORS_TYPE(N)

        typedef
            QSBOOST_PP_CAT(list, N)<
                QSBOOST_PP_ENUM(N, QSBOOST_PROTO_FUSION_AS_CHILD_AT_TYPE, ~)
            >
        proto_args;

        typedef typename base_expr<Domain, Tag, proto_args>::type expr_type;
        typedef typename Domain::proto_generator proto_generator;
        typedef typename proto_generator::template result<proto_generator(expr_type)>::type type;

        QSBOOST_FORCEINLINE
        static type const call(Sequence const &sequence)
        {
            QSBOOST_PROTO_FUSION_ITERATORS(N)
            expr_type const that = {
                QSBOOST_PP_ENUM(N, QSBOOST_PROTO_FUSION_AS_CHILD_AT, ~)
            };
            return proto_generator()(that);
        }
    };

    template<typename Tag, typename Sequence>
    struct unpack_expr_<Tag, deduce_domain, Sequence, N>
    {
        QSBOOST_PROTO_FUSION_ITERATORS_TYPE(N)

        typedef
            unpack_expr_<
                Tag
              , typename QSBOOST_PP_CAT(deduce_domain, N)<
                    QSBOOST_PP_ENUM(N, QSBOOST_PROTO_FUSION_AT_TYPE, ~)
                >::type
              , Sequence
              , N
            >
        other;

        typedef typename other::type type;

        QSBOOST_FORCEINLINE
        static type const call(Sequence const &sequence)
        {
            return other::call(sequence);
        }
    };

    #undef N
    #undef M

#endif

#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/args.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_CHILD_N(Z, N, DATA)                                              \
        typedef QSBOOST_PP_CAT(Arg, N) QSBOOST_PP_CAT(child, N);                                    \
        /**< INTERNAL ONLY */

    /// INTERNAL ONLY
    ///
    #define QSBOOST_PROTO_DEFINE_VOID_N(z, n, data)                                               \
        typedef mpl::void_ QSBOOST_PP_CAT(child, n);                                              \
        /**< INTERNAL ONLY */

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/args.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    /// \file args.hpp
    /// Contains definition of \c term\<\>, \c list1\<\>, \c list2\<\>, ...
    /// class templates.
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    /// \brief A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
    ///
    /// A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
    /// The types in the sequence correspond to the children of a node in an expression tree.
    template< typename Arg0 >
    struct term
    {
        static const long arity = 0;
        typedef Arg0 child0;
        QSBOOST_PP_REPEAT_FROM_TO(1, QSBOOST_PROTO_MAX_ARITY, QSBOOST_PROTO_DEFINE_VOID_N, ~)

        /// INTERNAL ONLY
        ///
        typedef Arg0 back_;
    };

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                         \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/args.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

    #undef QSBOOST_PROTO_DEFINE_VOID_N
    #undef QSBOOST_PROTO_DEFINE_CHILD_N

#else

    #define N QSBOOST_PP_ITERATION()

    /// \brief A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
    ///
    /// A type sequence, for use as the 2nd parameter to the \c expr\<\> class template.
    /// The types in the sequence correspond to the children of a node in an expression tree.
    template< QSBOOST_PP_ENUM_PARAMS(N, typename Arg) >
    struct QSBOOST_PP_CAT(list, N)
    {
        static const long arity = N;
        QSBOOST_PP_REPEAT(N, QSBOOST_PROTO_DEFINE_CHILD_N, ~)
        QSBOOST_PP_REPEAT_FROM_TO(N, QSBOOST_PROTO_MAX_ARITY, QSBOOST_PROTO_DEFINE_VOID_N, ~)

        /// INTERNAL ONLY
        ///
        typedef QSBOOST_PP_CAT(Arg, QSBOOST_PP_DEC(N)) back_;
    };

    #undef N

#endif

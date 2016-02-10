#if !defined(QSBOOST_PROTO_DONT_USE_PREPROCESSED_FILES)

    #include <qsboost/proto/detail/preprocessed/template_arity_helper.hpp>

#elif !defined(QSBOOST_PP_IS_ITERATING)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 2, line: 0, output: "preprocessed/template_arity_helper.hpp")
    #endif

    ///////////////////////////////////////////////////////////////////////////////
    // template_arity_helper.hpp
    // Overloads of template_arity_helper, used by the template_arity\<\> class template
    //
    //  Copyright 2008 Eric Niebler. Distributed under the Boost
    //  Software License, Version 1.0. (See accompanying file
    //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(preserve: 1)
    #endif

    #define QSBOOST_PP_ITERATION_PARAMS_1                                                             \
        (3, (1, QSBOOST_PROTO_MAX_ARITY, <qsboost/proto/detail/template_arity_helper.hpp>))
    #include QSBOOST_PP_ITERATE()

    #if defined(__WAVE__) && defined(QSBOOST_PROTO_CREATE_PREPROCESSED_FILES)
        #pragma wave option(output: null)
    #endif

#else

    #define N QSBOOST_PP_ITERATION()

    template<
        template<QSBOOST_PP_ENUM_PARAMS(N, typename P)> class F
      , QSBOOST_PP_ENUM_PARAMS(N, typename T)
    >
    sized_type<QSBOOST_PP_INC(N)>::type
    template_arity_helper(F<QSBOOST_PP_ENUM_PARAMS(N, T)> **, mpl::int_<N> *);

    #undef N

#endif // BOOST_PROTO_DONT_USE_PREPROCESSED_FILES

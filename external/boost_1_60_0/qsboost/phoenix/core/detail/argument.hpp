/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010-2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

    #define QSBOOST_PHOENIX_ARGUMENT_N_TYPE(_, N, name)                           \
    typedef                                                                     \
        expression::argument<QSBOOST_PP_INC(N)>::type                             \
        QSBOOST_PP_CAT(QSBOOST_PP_CAT(name, QSBOOST_PP_INC(N)), _type);               \
    /**/
    
    #define QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE(_, N, name)                       \
    expression::argument<QSBOOST_PP_INC(N)>::type const                           \
        QSBOOST_PP_CAT(name, QSBOOST_PP_INC(N)) = {{{}}};                           \
    /**/


    namespace placeholders
    {
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_TYPE, arg)
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_TYPE, _)
#ifndef QSBOOST_PHOENIX_NO_PREDEFINED_TERMINALS
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE, arg)
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE, _)
#endif
    }

    namespace arg_names
    {
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_TYPE, arg)
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_TYPE, _)
#ifndef QSBOOST_PHOENIX_NO_PREDEFINED_TERMINALS
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE, arg)
        QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_ARG_LIMIT, QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE, _)
#endif
    }

    #undef QSBOOST_PHOENIX_ARGUMENT_N_TYPE
    #undef QSBOOST_PHOENIX_ARGUMENT_N_INSTANCE


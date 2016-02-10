/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PP_IS_ITERATING

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>

#define QSBOOST_PP_FILENAME_1 \
    <qsboost/spirit/home/qi/nonterminal/detail/fcall.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (1, SPIRIT_ARGUMENTS_LIMIT)
#include QSBOOST_PP_ITERATE()

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(BOOST_PP_IS_ITERATING)

#define N QSBOOST_PP_ITERATION()

    template <QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    typename lazy_enable_if_c<
        (params_size == N)
      , proto::terminal<
            spirit::qi::parameterized_nonterminal<
                parameterized_subject_type
              , fusion::vector<QSBOOST_PP_ENUM_PARAMS(N, A)> >
        >
    >::type
    operator()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const& f)) const
    {
        typedef fusion::vector<QSBOOST_PP_ENUM_PARAMS(N, A)> vector_type;
        typedef spirit::qi::parameterized_nonterminal<
            parameterized_subject_type, vector_type> parameterized_type;
        typedef typename proto::terminal<parameterized_type>::type result_type;

        return result_type::make(
            parameterized_type(
                this->get_parameterized_subject()
              , fusion::make_vector(QSBOOST_PP_ENUM_PARAMS(N, f)))
        );
    }

#undef N
#endif // defined(BOOST_PP_IS_ITERATING)



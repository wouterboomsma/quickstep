///////////////////////////////////////////////////////////////////////////////
// expr1.hpp
// Contains definition of expr\<\>::operator() overloads.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#define N QSBOOST_PP_ITERATION()

        /// \overload
        ///
        template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
        QSBOOST_FORCEINLINE
        typename result_of::QSBOOST_PP_CAT(funop, N)<
            expr const
          , default_domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >::type const
        operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const &a)) const
        {
            return result_of::QSBOOST_PP_CAT(funop, N)<
                expr const
              , default_domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
            >::call(*this QSBOOST_PP_ENUM_TRAILING_PARAMS(N, a));
        }

        #ifdef QSBOOST_PROTO_DEFINE_TERMINAL
        /// \overload
        ///
        template<QSBOOST_PP_ENUM_PARAMS(N, typename A)>
        QSBOOST_FORCEINLINE
        typename result_of::QSBOOST_PP_CAT(funop, N)<
            expr
          , default_domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
        >::type const
        operator ()(QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, const &a))
        {
            return result_of::QSBOOST_PP_CAT(funop, N)<
                expr
              , default_domain QSBOOST_PP_ENUM_TRAILING_PARAMS(N, const A)
            >::call(*this QSBOOST_PP_ENUM_TRAILING_PARAMS(N, a));
        }
        #endif

#undef N


// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

// input:  BOOST_FT_syntax     type macro to use
// input:  BOOST_FT_cc         empty or cc specifier 
// input:  BOOST_FT_ell        empty or "..."
// input:  BOOST_FT_cv         empty or cv qualifiers
// input:  BOOST_FT_flags      single decimal integer encoding the flags
// output: BOOST_FT_n          number of component types (arity+1)
// output: BOOST_FT_arity      current arity
// output: BOOST_FT_type       macro that expands to the type
// output: BOOST_FT_tplargs(p) template arguments with given prefix
// output: BOOST_FT_params(p)  parameters with given prefix

template< typename R >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,0> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (QSBOOST_FT_nullary_param QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,1> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,2> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,3> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,4> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,5> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,6> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,7> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,8> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,9> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 QSBOOST_FT_ell) QSBOOST_FT_cv);
template< typename R , typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 , typename T6 , typename T7 , typename T8 , typename T9 >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,10> ::type
classifier_impl(QSBOOST_FT_syntax(QSBOOST_FT_cc, QSBOOST_PP_EMPTY) (T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 QSBOOST_FT_ell) QSBOOST_FT_cv);


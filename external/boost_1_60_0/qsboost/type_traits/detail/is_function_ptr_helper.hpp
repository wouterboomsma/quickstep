
//  Copyright 2000 John Maddock (john@johnmaddock.co.uk)
//  Copyright 2002 Aleksey Gurtovoy (agurtovoy@meta-comm.com)
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_TT_DETAIL_IS_FUNCTION_PTR_HELPER_HPP_INCLUDED
#define QSBOOST_TT_DETAIL_IS_FUNCTION_PTR_HELPER_HPP_INCLUDED

#if defined(QSBOOST_TT_PREPROCESSING_MODE)
//
// Hide these #include from dependency analysers as
// these are required in maintenance mode only:
//
#define PP1 <qsboost/preprocessor/iterate.hpp>
#include PP1
#undef PP1
#define PP1 <qsboost/preprocessor/enum_params.hpp>
#include PP1
#undef PP1
#define PP1 <qsboost/preprocessor/comma_if.hpp>
#include PP1
#undef PP1
#endif

namespace qsboost {
namespace type_traits {

template <class R>
struct is_function_ptr_helper
{
    QSBOOST_STATIC_CONSTANT(bool, value = false);
};

#if !defined(QSBOOST_TT_PREPROCESSING_MODE)
// preprocessor-generated part, don't edit by hand!

template <class R >
struct is_function_ptr_helper<R (*)()> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R >
struct is_function_ptr_helper<R (*)( ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0>
struct is_function_ptr_helper<R (*)( T0)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0>
struct is_function_ptr_helper<R (*)( T0 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1>
struct is_function_ptr_helper<R (*)( T0 , T1)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1>
struct is_function_ptr_helper<R (*)( T0 , T1 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_function_ptr_helper<R (*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24 ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#else

#undef QSBOOST_STATIC_CONSTANT
#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3, (0, 25, "qsboost/type_traits/detail/is_function_ptr_helper.hpp"))
#include QSBOOST_PP_ITERATE()

#endif // BOOST_TT_PREPROCESSING_MODE

} // namespace type_traits
} // namespace boost

#endif // BOOST_TT_DETAIL_IS_FUNCTION_PTR_HELPER_HPP_INCLUDED

///// iteration

#else
#define QSBOOST_PP_COUNTER QSBOOST_PP_FRAME_ITERATION(1)

template <class R QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_function_ptr_helper<R (*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T))> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
@#ifndef QSBOOST_TT_NO_ELLIPSIS_IN_FUNC_TESTING
template <class R QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_function_ptr_helper<R (*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T) ...)> { QSBOOST_STATIC_CONSTANT(bool, value = true); };
@#endif
#undef QSBOOST_PP_COUNTER
#endif // BOOST_PP_IS_ITERATING

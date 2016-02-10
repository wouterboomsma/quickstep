
//  (C) Copyright Dave Abrahams, Steve Cleary, Beman Dawes, 
//  Aleksey Gurtovoy, Howard Hinnant & John Maddock 2000.  
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#if !defined(QSBOOST_PP_IS_ITERATING)

///// header body

#ifndef QSBOOST_TT_DETAIL_IS_MEM_FUN_POINTER_IMPL_HPP_INCLUDED
#define QSBOOST_TT_DETAIL_IS_MEM_FUN_POINTER_IMPL_HPP_INCLUDED

#include <qsboost/config.hpp>

#if defined(QSBOOST_TT_PREPROCESSING_MODE)
//
// Maintenance mode, hide include dependencies
// from trackers:
//
#define PPI <qsboost/preprocessor/iterate.hpp>
#include PPI
#undef PPI
#define PPI <qsboost/preprocessor/enum_params.hpp>
#include PPI
#undef PPI
#define PPI <qsboost/preprocessor/comma_if.hpp>
#include PPI
#undef PPI
#endif

namespace qsboost {
namespace type_traits {

template <typename T>
struct is_mem_fun_pointer_impl
{
    QSBOOST_STATIC_CONSTANT(bool, value = false);
};

#if !defined(QSBOOST_TT_PREPROCESSING_MODE)
// pre-processed code, don't edit, try GNU cpp with 
// cpp -I../../../ -DBOOST_TT_PREPROCESSING_MODE -x c++ -P filename

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)() > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)( ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)() const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)() volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)() const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)( ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)( ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T >
struct is_mem_fun_pointer_impl<R (T::*)( ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0>
struct is_mem_fun_pointer_impl<R (T::*)( T0 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24 ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24 ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24 ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T , class T0 , class T1 , class T2 , class T3 , class T4 , class T5 , class T6 , class T7 , class T8 , class T9 , class T10 , class T11 , class T12 , class T13 , class T14 , class T15 , class T16 , class T17 , class T18 , class T19 , class T20 , class T21 , class T22 , class T23 , class T24>
struct is_mem_fun_pointer_impl<R (T::*)( T0 , T1 , T2 , T3 , T4 , T5 , T6 , T7 , T8 , T9 , T10 , T11 , T12 , T13 , T14 , T15 , T16 , T17 , T18 , T19 , T20 , T21 , T22 , T23 , T24 ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
#endif

#else

#undef QSBOOST_STATIC_CONSTANT
#define QSBOOST_PP_ITERATION_PARAMS_1 \
    (3, (0, 25, "qsboost/type_traits/detail/is_mem_fun_pointer_impl.hpp"))
#include QSBOOST_PP_ITERATE()

#endif // BOOST_TT_PREPROCESSING_MODE

} // namespace type_traits
} // namespace boost

#endif // BOOST_TT_DETAIL_IS_MEM_FUN_POINTER_IMPL_HPP_INCLUDED

///// iteration

#else
#define QSBOOST_PP_COUNTER QSBOOST_PP_FRAME_ITERATION(1)

template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T)) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
@#ifndef QSBOOST_TT_NO_ELLIPSIS_IN_FUNC_TESTING
template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T) ...) > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
@#endif

@#if !defined(QSBOOST_TT_NO_CV_FUNC_TEST)
template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T)) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T)) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T)) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

@#ifndef QSBOOST_TT_NO_ELLIPSIS_IN_FUNC_TESTING
template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T) ...) const > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T) ...) volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };

template <class R, class T QSBOOST_PP_COMMA_IF(QSBOOST_PP_COUNTER) QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,class T)>
struct is_mem_fun_pointer_impl<R (T::*)(QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_COUNTER,T) ...) const volatile > { QSBOOST_STATIC_CONSTANT(bool, value = true); };
@#endif
@#endif

#undef QSBOOST_PP_COUNTER
#endif // BOOST_PP_IS_ITERATING


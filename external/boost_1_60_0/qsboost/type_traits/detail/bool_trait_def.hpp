
// NO INCLUDE GUARDS, THE HEADER IS INTENDED FOR MULTIPLE INCLUSION

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)

// $Source$
// $Date$
// $Revision$

//
// This header is deprecated and no longer used by type_traits:
//
#if defined(__GNUC__) || defined(_MSC_VER)
# pragma message("NOTE: Use of this header (bool_trait_def.hpp) is deprecated")
#endif

#include <qsboost/type_traits/detail/template_arity_spec.hpp>
#include <qsboost/type_traits/integral_constant.hpp>
#include <qsboost/config.hpp>

//
// Unfortunately some libraries have started using this header without
// cleaning up afterwards: so we'd better undef the macros just in case 
// they've been defined already....
//
#ifdef QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL
#undef QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL
#undef QSBOOST_TT_AUX_BOOL_C_BASE
#undef QSBOOST_TT_AUX_BOOL_TRAIT_DEF1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_DEF2
#undef QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_SPEC2
#undef QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC2
#undef QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2
#undef QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2
#undef QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_PARTIAL_SPEC2_1
#undef QSBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1
#endif

#ifndef QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL
#   define QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) /**/
#endif

#ifndef QSBOOST_TT_AUX_BOOL_C_BASE
#   define QSBOOST_TT_AUX_BOOL_C_BASE(C) : public ::qsboost::integral_constant<bool,C>
#endif 


#define QSBOOST_TT_AUX_BOOL_TRAIT_DEF1(trait,T,C) \
template< typename T > struct trait \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
\
QSBOOST_TT_AUX_TEMPLATE_ARITY_SPEC(1,trait) \
/**/


#define QSBOOST_TT_AUX_BOOL_TRAIT_DEF2(trait,T1,T2,C) \
template< typename T1, typename T2 > struct trait \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
\
QSBOOST_TT_AUX_TEMPLATE_ARITY_SPEC(2,trait) \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_DEF3(trait,T1,T2,T3,C) \
template< typename T1, typename T2, typename T3 > struct trait \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
\
QSBOOST_TT_AUX_TEMPLATE_ARITY_SPEC(3,trait) \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp,C) \
template<> struct trait< sp > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_SPEC2(trait,sp1,sp2,C) \
template<> struct trait< sp1,sp2 > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC1(trait,sp,C) \
template<> struct trait##_impl< sp > \
{ \
public:\
    QSBOOST_STATIC_CONSTANT(bool, value = (C)); \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_SPEC2(trait,sp1,sp2,C) \
template<> struct trait##_impl< sp1,sp2 > \
{ \
public:\
    QSBOOST_STATIC_CONSTANT(bool, value = (C)); \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_1(param,trait,sp,C) \
template< param > struct trait< sp > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC1_2(param1,param2,trait,sp,C) \
template< param1, param2 > struct trait< sp > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_1(param,trait,sp1,sp2,C) \
template< param > struct trait< sp1,sp2 > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_PARTIAL_SPEC2_2(param1,param2,trait,sp1,sp2,C) \
template< param1, param2 > struct trait< sp1,sp2 > \
    QSBOOST_TT_AUX_BOOL_C_BASE(C) \
{ \
public:\
    QSBOOST_TT_AUX_BOOL_TRAIT_VALUE_DECL(C) \
}; \
/**/

#define QSBOOST_TT_AUX_BOOL_TRAIT_IMPL_PARTIAL_SPEC2_1(param,trait,sp1,sp2,C) \
template< param > struct trait##_impl< sp1,sp2 > \
{ \
public:\
    QSBOOST_STATIC_CONSTANT(bool, value = (C)); \
}; \
/**/

#ifndef QSBOOST_NO_CV_SPECIALIZATIONS
#   define QSBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(trait,sp,value) \
    QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp,value) \
    QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp const,value) \
    QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp volatile,value) \
    QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp const volatile,value) \
    /**/
#else
#   define QSBOOST_TT_AUX_BOOL_TRAIT_CV_SPEC1(trait,sp,value) \
    QSBOOST_TT_AUX_BOOL_TRAIT_SPEC1(trait,sp,value) \
    /**/
#endif

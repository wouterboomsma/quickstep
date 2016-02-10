//  boost utility/base_from_member.hpp header file  --------------------------//

//  Copyright 2001, 2003, 2004, 2012 Daryle Walker.  Use, modification, and
//  distribution are subject to the Boost Software License, Version 1.0.  (See
//  accompanying file LICENSE_1_0.txt or a copy at
//  <http://www.boost.org/LICENSE_1_0.txt>.)

//  See <http://www.boost.org/libs/utility/> for the library's home page.

#ifndef QSBOOST_UTILITY_BASE_FROM_MEMBER_HPP
#define QSBOOST_UTILITY_BASE_FROM_MEMBER_HPP

#include <qsboost/config.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/type_traits/remove_cv.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/utility/enable_if.hpp>


//  Base-from-member arity configuration macro  ------------------------------//

// The following macro determines how many arguments will be in the largest
// constructor template of base_from_member.  Constructor templates will be
// generated from one argument to this maximum.  Code from other files can read
// this number if they need to always match the exact maximum base_from_member
// uses.  The maximum constructor length can be changed by overriding the
// #defined constant.  Make sure to apply the override, if any, for all source
// files during project compiling for consistency.

// Contributed by Jonathan Turkanis

#ifndef QSBOOST_BASE_FROM_MEMBER_MAX_ARITY
#define QSBOOST_BASE_FROM_MEMBER_MAX_ARITY  10
#endif


//  An iteration of a constructor template for base_from_member  -------------//

// A macro that should expand to:
//     template < typename T1, ..., typename Tn >
//     base_from_member( T1 x1, ..., Tn xn )
//         : member( x1, ..., xn )
//         {}
// This macro should only persist within this file.

#define QSBOOST_PRIVATE_CTR_DEF( z, n, data )                            \
    template < QSBOOST_PP_ENUM_PARAMS(n, typename T) >                   \
    explicit base_from_member( QSBOOST_PP_ENUM_BINARY_PARAMS(n, T, x) )  \
        : member( QSBOOST_PP_ENUM_PARAMS(n, x) )                         \
        {}                                                             \
    /**/


namespace qsboost
{

namespace detail
{

//  Type-unmarking class template  -------------------------------------------//

// Type-trait to get the raw type, i.e. the type without top-level reference nor
// cv-qualification, from a type expression.  Mainly for function arguments, any
// reference part is stripped first.

// Contributed by Daryle Walker

template < typename T >
struct remove_cv_ref
{
    typedef typename ::qsboost::remove_cv<typename
     ::qsboost::remove_reference<T>::type>::type  type;

};  // boost::detail::remove_cv_ref

//  Unmarked-type comparison class template  ---------------------------------//

// Type-trait to check if two type expressions have the same raw type.

// Contributed by Daryle Walker, based on a work-around by Luc Danton

template < typename T, typename U >
struct is_related
    : public ::qsboost::is_same<
     typename ::qsboost::detail::remove_cv_ref<T>::type,
     typename ::qsboost::detail::remove_cv_ref<U>::type >
{};

//  Enable-if-on-unidentical-unmarked-type class template  -------------------//

// Enable-if on the first two type expressions NOT having the same raw type.

// Contributed by Daryle Walker, based on a work-around by Luc Danton

#ifndef QSBOOST_NO_CXX11_VARIADIC_TEMPLATES
template<typename ...T>
struct enable_if_unrelated
    : public ::qsboost::enable_if_c<true>
{};

template<typename T, typename U, typename ...U2>
struct enable_if_unrelated<T, U, U2...>
    : public ::qsboost::disable_if< ::qsboost::detail::is_related<T, U> >
{};
#endif

}  // namespace boost::detail


//  Base-from-member class template  -----------------------------------------//

// Helper to initialize a base object so a derived class can use this
// object in the initialization of another base class.  Used by
// Dietmar Kuehl from ideas by Ron Klatcho to solve the problem of a
// base class needing to be initialized by a member.

// Contributed by Daryle Walker

template < typename MemberType, int UniqueID = 0 >
class base_from_member
{
protected:
    MemberType  member;

#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) && \
    !defined(QSBOOST_NO_CXX11_VARIADIC_TEMPLATES) && \
    !defined(QSBOOST_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS) && \
    !(defined(__GNUC__) && (__GNUC__ == 4) && (__GNUC_MINOR__ < 4))
    template <typename ...T, typename EnableIf = typename
     ::qsboost::detail::enable_if_unrelated<base_from_member, T...>::type>
    explicit QSBOOST_CONSTEXPR base_from_member( T&& ...x )
        QSBOOST_NOEXCEPT_IF( QSBOOST_NOEXCEPT_EXPR(::new ((void*) 0) MemberType(
         static_cast<T&&>(x)... )) )  // no std::is_nothrow_constructible...
        : member( static_cast<T&&>(x)... )     // ...nor std::forward needed
        {}
#else
    base_from_member()
        : member()
        {}

    QSBOOST_PP_REPEAT_FROM_TO( 1, QSBOOST_PP_INC(QSBOOST_BASE_FROM_MEMBER_MAX_ARITY),
     QSBOOST_PRIVATE_CTR_DEF, _ )
#endif

};  // boost::base_from_member

template < typename MemberType, int UniqueID >
class base_from_member<MemberType&, UniqueID>
{
protected:
    MemberType& member;

    explicit QSBOOST_CONSTEXPR base_from_member( MemberType& x )
        QSBOOST_NOEXCEPT
        : member( x )
        {}

};  // boost::base_from_member

}  // namespace boost


// Undo any private macros
#undef QSBOOST_PRIVATE_CTR_DEF


#endif  // BOOST_UTILITY_BASE_FROM_MEMBER_HPP

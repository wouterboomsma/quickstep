
#ifndef QSBOOST_MPL_HAS_XXX_HPP_INCLUDED
#define QSBOOST_MPL_HAS_XXX_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2006
// Copyright David Abrahams 2002-2003
// Copyright Daniel Walker 2007
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/aux_/na_spec.hpp>
#include <qsboost/mpl/aux_/type_wrapper.hpp>
#include <qsboost/mpl/aux_/yes_no.hpp>
#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/has_xxx.hpp>
#include <qsboost/mpl/aux_/config/msvc_typename.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/static_constant.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/preprocessor/array/elem.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>

#if QSBOOST_WORKAROUND( __BORLANDC__, QSBOOST_TESTED_AT(0x590) )
# include <qsboost/type_traits/is_class.hpp>
#endif

#if !defined(QSBOOST_MPL_CFG_NO_HAS_XXX)

#   if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300)

// agurt, 11/sep/02: MSVC-specific version (< 7.1), based on a USENET 
// newsgroup's posting by John Madsen (comp.lang.c++.moderated, 
// 1999-11-12 19:17:06 GMT); the code is _not_ standard-conforming, but 
// it works way more reliably than the SFINAE-based implementation

// Modified dwa 8/Oct/02 to handle reference types.

#   include <qsboost/mpl/if.hpp>
#   include <qsboost/mpl/bool.hpp>

namespace qsboost { namespace mpl { namespace aux {

struct has_xxx_tag;

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1300)
template< typename U > struct msvc_incomplete_array
{
    typedef char (&type)[sizeof(U) + 1];
};
#endif

template< typename T >
struct msvc_is_incomplete
{
    // MSVC is capable of some kinds of SFINAE.  If U is an incomplete
    // type, it won't pick the second overload
    static char tester(...);

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1300)
    template< typename U >
    static typename msvc_incomplete_array<U>::type tester(type_wrapper<U>);
#else
    template< typename U >
    static char (& tester(type_wrapper<U>) )[sizeof(U)+1];
#endif 
    
    QSBOOST_STATIC_CONSTANT(bool, value = 
          sizeof(tester(type_wrapper<T>())) == 1
        );
};

template<>
struct msvc_is_incomplete<int>
{
    QSBOOST_STATIC_CONSTANT(bool, value = false);
};

}}}

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, default_) \
template< typename T, typename name = ::qsboost::mpl::aux::has_xxx_tag > \
struct QSBOOST_PP_CAT(trait,_impl) : T \
{ \
    static qsboost::mpl::aux::no_tag \
    test(void(*)(::qsboost::mpl::aux::has_xxx_tag)); \
    \
    static qsboost::mpl::aux::yes_tag test(...); \
    \
    QSBOOST_STATIC_CONSTANT(bool, value = \
          sizeof(test(static_cast<void(*)(name)>(0))) \
            != sizeof(qsboost::mpl::aux::no_tag) \
        ); \
    typedef qsboost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = qsboost::mpl::bool_<default_> > \
struct trait \
    : qsboost::mpl::if_c< \
          qsboost::mpl::aux::msvc_is_incomplete<T>::value \
        , qsboost::mpl::bool_<false> \
        , QSBOOST_PP_CAT(trait,_impl)<T> \
        >::type \
{ \
}; \
\
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, void) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, bool) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, char) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed char) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned char) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed short) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned short) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed int) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned int) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, signed long) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, unsigned long) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, float) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, double) \
QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, long double) \
/**/

#   define QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, T) \
template<> struct trait<T> \
{ \
    QSBOOST_STATIC_CONSTANT(bool, value = false); \
    typedef qsboost::mpl::bool_<false> type; \
}; \
/**/

#if !defined(QSBOOST_NO_INTRINSIC_WCHAR_T)
#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
    QSBOOST_MPL_AUX_HAS_XXX_TRAIT_SPEC(trait, wchar_t) \
/**/
#else
#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, unused) \
    QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF_(trait, name, unused) \
/**/
#endif


// SFINAE-based implementations below are derived from a USENET newsgroup's 
// posting by Rani Sharoni (comp.lang.c++.moderated, 2002-03-17 07:45:09 PST)

#   elif QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1400) \
      || (QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1800)) && defined(__CUDACC__)) \
      || QSBOOST_WORKAROUND(__IBMCPP__, <= 700)

// MSVC 7.1 & MSVC 8.0 & VACPP

// agurt, 15/jun/05: replace overload-based SFINAE implementation with SFINAE
// applied to partial specialization to fix some apparently random failures 
// (thanks to Daniel Wallin for researching this!)

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T > \
struct QSBOOST_PP_CAT(trait, _msvc_sfinae_helper) \
{ \
    typedef void type; \
};\
\
template< typename T, typename U = void > \
struct QSBOOST_PP_CAT(trait,_impl_) \
{ \
    QSBOOST_STATIC_CONSTANT(bool, value = false); \
    typedef qsboost::mpl::bool_<value> type; \
}; \
\
template< typename T > \
struct QSBOOST_PP_CAT(trait,_impl_)< \
      T \
    , typename QSBOOST_PP_CAT(trait, _msvc_sfinae_helper)< typename T::name >::type \
    > \
{ \
    QSBOOST_STATIC_CONSTANT(bool, value = true); \
    typedef qsboost::mpl::bool_<value> type; \
}; \
\
template< typename T, typename fallback_ = qsboost::mpl::bool_<default_> > \
struct trait \
    : QSBOOST_PP_CAT(trait,_impl_)<T> \
{ \
}; \
/**/

#   elif QSBOOST_WORKAROUND( __BORLANDC__, QSBOOST_TESTED_AT(0x590) )

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF(trait, trait_tester, name, default_) \
template< typename T, bool IS_CLASS > \
struct trait_tester \
{ \
    QSBOOST_STATIC_CONSTANT( bool,  value = false ); \
}; \
template< typename T > \
struct trait_tester< T, true > \
{ \
    struct trait_tester_impl \
    { \
        template < class U > \
        static int  resolve( qsboost::mpl::aux::type_wrapper<U> const volatile * \
                           , qsboost::mpl::aux::type_wrapper<typename U::name >* = 0 ); \
        static char resolve( ... ); \
    }; \
    typedef qsboost::mpl::aux::type_wrapper<T> t_; \
    QSBOOST_STATIC_CONSTANT( bool, value = ( sizeof( trait_tester_impl::resolve( static_cast< t_ * >(0) ) ) == sizeof(int) ) ); \
}; \
template< typename T, typename fallback_ = qsboost::mpl::bool_<default_> > \
struct trait           \
{                      \
    QSBOOST_STATIC_CONSTANT( bool, value = (trait_tester< T, qsboost::is_class< T >::value >::value) );     \
    typedef qsboost::mpl::bool_< trait< T, fallback_ >::value > type; \
};

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
    QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_BCB_DEF( trait \
                                         , QSBOOST_PP_CAT(trait,_tester)      \
                                         , name       \
                                         , default_ ) \
/**/

#   else // other SFINAE-capable compilers

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = qsboost::mpl::bool_<default_> > \
struct trait \
{ \
    struct gcc_3_2_wknd \
    { \
        template< typename U > \
        static qsboost::mpl::aux::yes_tag test( \
              qsboost::mpl::aux::type_wrapper<U> const volatile* \
            , qsboost::mpl::aux::type_wrapper<QSBOOST_MSVC_TYPENAME U::name>* = 0 \
            ); \
    \
        static qsboost::mpl::aux::no_tag test(...); \
    }; \
    \
    typedef qsboost::mpl::aux::type_wrapper<T> t_; \
    QSBOOST_STATIC_CONSTANT(bool, value = \
          sizeof(gcc_3_2_wknd::test(static_cast<t_*>(0))) \
            == sizeof(qsboost::mpl::aux::yes_tag) \
        ); \
    typedef qsboost::mpl::bool_<value> type; \
}; \
/**/

#   endif // BOOST_WORKAROUND(BOOST_MSVC, <= 1300)


#else // BOOST_MPL_CFG_NO_HAS_XXX

// placeholder implementation

#   define QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(trait, name, default_) \
template< typename T, typename fallback_ = qsboost::mpl::bool_<default_> > \
struct trait \
{ \
    QSBOOST_STATIC_CONSTANT(bool, value = fallback_::value); \
    typedef fallback_ type; \
}; \
/**/

#endif

#define QSBOOST_MPL_HAS_XXX_TRAIT_DEF(name) \
    QSBOOST_MPL_HAS_XXX_TRAIT_NAMED_DEF(QSBOOST_PP_CAT(has_,name), name, false) \
/**/


#if !defined(QSBOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE)

// Create a boolean Metafunction to detect a nested template
// member. This implementation is based on a USENET newsgroup's
// posting by Aleksey Gurtovoy (comp.lang.c++.moderated, 2002-03-19),
// Rani Sharoni's USENET posting cited above, the non-template has_xxx
// implementations above, and discussion on the Boost mailing list.

#   if !defined(QSBOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES)
#     if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1400)
#       define QSBOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES 1
#     else
#       define QSBOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES 0
#     endif
#   endif

#   if !defined(QSBOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION)
#     if (defined(QSBOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS))
#       define QSBOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION 1
#     else
#       define QSBOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION 0
#     endif
#   endif

#   if !defined(QSBOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE)
#     if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1400)
#       define QSBOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE 1
#     else
#       define QSBOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE 0
#     endif
#   endif

// NOTE: Many internal implementation macros take a Boost.Preprocessor
// array argument called args which is of the following form.
//           ( 4, ( trait, name, max_arity, default_ ) )

#   define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
      QSBOOST_PP_CAT(QSBOOST_PP_ARRAY_ELEM(0, args) , _introspect) \
    /**/

#   define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) \
      QSBOOST_PP_CAT(QSBOOST_PP_CAT(QSBOOST_PP_ARRAY_ELEM(0, args) , _substitute), n) \
    /**/

#   define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args) \
      QSBOOST_PP_CAT(QSBOOST_PP_ARRAY_ELEM(0, args) , _test) \
    /**/

// Thanks to Guillaume Melquiond for pointing out the need for the
// "substitute" template as an argument to the overloaded test
// functions to get SFINAE to work for member templates with the
// correct name but different number of arguments.
#   define QSBOOST_MPL_HAS_MEMBER_MULTI_SUBSTITUTE(z, n, args) \
      template< \
          template< QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_INC(n), typename V) > class V \
       > \
      struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) { \
      }; \
    /**/

#   define QSBOOST_MPL_HAS_MEMBER_SUBSTITUTE(args, substitute_macro) \
      QSBOOST_PP_REPEAT( \
          QSBOOST_PP_ARRAY_ELEM(2, args) \
        , QSBOOST_MPL_HAS_MEMBER_MULTI_SUBSTITUTE \
        , args \
      ) \
    /**/

#   if !QSBOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
#     define QSBOOST_MPL_HAS_MEMBER_REJECT(args, member_macro) \
        template< typename V > \
        static qsboost::mpl::aux::no_tag \
        QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)(...); \
      /**/
#   else
#     define QSBOOST_MPL_HAS_MEMBER_REJECT(args, member_macro) \
        static qsboost::mpl::aux::no_tag \
        QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)(...); \
      /**/
#   endif

#   if !QSBOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES
#     define QSBOOST_MPL_HAS_MEMBER_MULTI_ACCEPT(z, n, args) \
        template< typename V > \
        static qsboost::mpl::aux::yes_tag \
        QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)( \
            qsboost::mpl::aux::type_wrapper< V > const volatile* \
          , QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) < \
                V::template QSBOOST_PP_ARRAY_ELEM(1, args) \
            >* = 0 \
        ); \
      /**/
#     define QSBOOST_MPL_HAS_MEMBER_ACCEPT(args, member_macro) \
        QSBOOST_PP_REPEAT( \
            QSBOOST_PP_ARRAY_ELEM(2, args) \
          , QSBOOST_MPL_HAS_MEMBER_MULTI_ACCEPT \
          , args \
        ) \
      /**/
#   else
#     define QSBOOST_MPL_HAS_MEMBER_ACCEPT(args, member_macro) \
        template< typename V > \
        static qsboost::mpl::aux::yes_tag \
        QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)( \
            V const volatile* \
          , member_macro(args, V, T)* = 0 \
        ); \
      /**/
#   endif

#   if !QSBOOST_MPL_HAS_XXX_NO_EXPLICIT_TEST_FUNCTION
#     define QSBOOST_MPL_HAS_MEMBER_TEST(args) \
          sizeof(QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< U >(0)) \
              == sizeof(qsboost::mpl::aux::yes_tag) \
      /**/
#   else
#     if !QSBOOST_MPL_HAS_XXX_NO_WRAPPED_TYPES
#       define QSBOOST_MPL_HAS_MEMBER_TEST(args) \
          sizeof( \
              QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)( \
                  static_cast< qsboost::mpl::aux::type_wrapper< U >* >(0) \
              ) \
          ) == sizeof(qsboost::mpl::aux::yes_tag) \
        /**/
#     else
#       define QSBOOST_MPL_HAS_MEMBER_TEST(args) \
          sizeof( \
              QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)( \
                  static_cast< U* >(0) \
              ) \
          ) == sizeof(qsboost::mpl::aux::yes_tag) \
        /**/
#     endif
#   endif

#   define QSBOOST_MPL_HAS_MEMBER_INTROSPECT( \
               args, substitute_macro, member_macro \
           ) \
      template< typename U > \
      struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) { \
          QSBOOST_MPL_HAS_MEMBER_SUBSTITUTE(args, substitute_macro) \
          QSBOOST_MPL_HAS_MEMBER_REJECT(args, member_macro) \
          QSBOOST_MPL_HAS_MEMBER_ACCEPT(args, member_macro) \
          QSBOOST_STATIC_CONSTANT( \
              bool, value = QSBOOST_MPL_HAS_MEMBER_TEST(args) \
          ); \
          typedef qsboost::mpl::bool_< value > type; \
      }; \
    /**/

#   define QSBOOST_MPL_HAS_MEMBER_IMPLEMENTATION( \
               args, introspect_macro, substitute_macro, member_macro \
           ) \
      template< \
          typename T \
        , typename fallback_ \
              = qsboost::mpl::bool_< QSBOOST_PP_ARRAY_ELEM(3, args) > \
      > \
      class QSBOOST_PP_ARRAY_ELEM(0, args) { \
          introspect_macro(args, substitute_macro, member_macro) \
      public: \
          static const bool value \
              = QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args)< T >::value; \
          typedef typename QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args)< \
              T \
          >::type type; \
      }; \
    /**/

// BOOST_MPL_HAS_MEMBER_WITH_FUNCTION_SFINAE expands to the full
// implementation of the function-based metafunction. Compile with -E
// to see the preprocessor output for this macro.
#   define QSBOOST_MPL_HAS_MEMBER_WITH_FUNCTION_SFINAE( \
               args, substitute_macro, member_macro \
           ) \
      QSBOOST_MPL_HAS_MEMBER_IMPLEMENTATION( \
          args \
        , QSBOOST_MPL_HAS_MEMBER_INTROSPECT \
        , substitute_macro \
        , member_macro \
      ) \
    /**/

#   if QSBOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE

#     if !defined(QSBOOST_MPL_HAS_XXX_NEEDS_NAMESPACE_LEVEL_SUBSTITUTE)
#       if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1400)
#         define QSBOOST_MPL_HAS_XXX_NEEDS_NAMESPACE_LEVEL_SUBSTITUTE 1
#       endif
#     endif

#     if !QSBOOST_MPL_HAS_XXX_NEEDS_NAMESPACE_LEVEL_SUBSTITUTE
#       define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE( \
                   args, n \
               ) \
          QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) \
        /**/
#     else
#       define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE( \
                   args, n \
               ) \
          QSBOOST_PP_CAT( \
              qsboost_mpl_has_xxx_ \
            , QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME(args, n) \
          ) \
        /**/
#     endif

#     define QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME( \
                 args \
             ) \
        QSBOOST_PP_CAT( \
            QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE( \
                args, 0 \
            ) \
          , _tag \
        ) \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE( \
                 z, n, args \
             ) \
        template< \
             template< QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_INC(n), typename U) > class U \
        > \
        struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE( \
                args, n \
               ) { \
            typedef \
                QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args) \
                type; \
        }; \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE( \
                 args, substitute_macro \
             ) \
        typedef void \
            QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args); \
        QSBOOST_PP_REPEAT( \
            QSBOOST_PP_ARRAY_ELEM(2, args) \
          , QSBOOST_MPL_HAS_MEMBER_MULTI_SUBSTITUTE_WITH_TEMPLATE_SFINAE \
          , args \
        ) \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_REJECT_WITH_TEMPLATE_SFINAE( \
                 args, member_macro \
             ) \
        template< \
            typename U \
          , typename V \
                = QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_TAG_NAME(args) \
        > \
        struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args) { \
            QSBOOST_STATIC_CONSTANT(bool, value = false); \
            typedef qsboost::mpl::bool_< value > type; \
        }; \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_MULTI_ACCEPT_WITH_TEMPLATE_SFINAE( \
                 z, n, args \
             ) \
        template< typename U > \
        struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< \
            U \
          , typename \
                QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_SUBSTITUTE_NAME_WITH_TEMPLATE_SFINAE( \
                    args, n \
                )< \
                    QSBOOST_MSVC_TYPENAME U::QSBOOST_PP_ARRAY_ELEM(1, args)< > \
                >::type \
        > { \
            QSBOOST_STATIC_CONSTANT(bool, value = true); \
            typedef qsboost::mpl::bool_< value > type; \
        }; \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_ACCEPT_WITH_TEMPLATE_SFINAE( \
                 args, member_macro \
             ) \
        QSBOOST_PP_REPEAT( \
            QSBOOST_PP_ARRAY_ELEM(2, args) \
          , QSBOOST_MPL_HAS_MEMBER_MULTI_ACCEPT_WITH_TEMPLATE_SFINAE \
          , args \
        ) \
      /**/

#     define QSBOOST_MPL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE( \
                 args, substitute_macro, member_macro \
             ) \
        QSBOOST_MPL_HAS_MEMBER_REJECT_WITH_TEMPLATE_SFINAE(args, member_macro) \
        QSBOOST_MPL_HAS_MEMBER_ACCEPT_WITH_TEMPLATE_SFINAE(args, member_macro) \
        template< typename U > \
        struct QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_NAME(args) \
            : QSBOOST_MPL_HAS_MEMBER_INTROSPECTION_TEST_NAME(args)< U > { \
        }; \
      /**/
 
// BOOST_MPL_HAS_MEMBER_WITH_TEMPLATE_SFINAE expands to the full
// implementation of the template-based metafunction. Compile with -E
// to see the preprocessor output for this macro.
//
// Note that if BOOST_MPL_HAS_XXX_NEEDS_NAMESPACE_LEVEL_SUBSTITUTE is
// defined BOOST_MPL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE needs
// to be expanded at namespace level before
// BOOST_MPL_HAS_MEMBER_WITH_TEMPLATE_SFINAE can be used.
#     define QSBOOST_MPL_HAS_MEMBER_WITH_TEMPLATE_SFINAE( \
                 args, substitute_macro, member_macro \
             ) \
        QSBOOST_MPL_HAS_MEMBER_SUBSTITUTE_WITH_TEMPLATE_SFINAE( \
            args, substitute_macro \
        ) \
        QSBOOST_MPL_HAS_MEMBER_IMPLEMENTATION( \
            args \
          , QSBOOST_MPL_HAS_MEMBER_INTROSPECT_WITH_TEMPLATE_SFINAE \
          , substitute_macro \
          , member_macro \
        ) \
      /**/

#   endif // BOOST_MPL_HAS_XXX_NEEDS_TEMPLATE_SFINAE

// Note: In the current implementation the parameter and access macros
// are no longer expanded.
#   if !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1400)
#     define QSBOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, default_) \
        QSBOOST_MPL_HAS_MEMBER_WITH_FUNCTION_SFINAE( \
            ( 4, ( trait, name, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, default_ ) ) \
          , QSBOOST_MPL_HAS_MEMBER_TEMPLATE_SUBSTITUTE_PARAMETER \
          , QSBOOST_MPL_HAS_MEMBER_TEMPLATE_ACCESS \
        ) \
      /**/
#   else
#     define QSBOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, default_) \
        QSBOOST_MPL_HAS_MEMBER_WITH_TEMPLATE_SFINAE( \
            ( 4, ( trait, name, QSBOOST_MPL_LIMIT_METAFUNCTION_ARITY, default_ ) ) \
          , QSBOOST_MPL_HAS_MEMBER_TEMPLATE_SUBSTITUTE_PARAMETER \
          , QSBOOST_MPL_HAS_MEMBER_TEMPLATE_ACCESS \
        ) \
      /**/
#   endif

#else // BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE

// placeholder implementation

#   define QSBOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF(trait, name, default_) \
      template< typename T \
              , typename fallback_ = qsboost::mpl::bool_< default_ > > \
      struct trait { \
          QSBOOST_STATIC_CONSTANT(bool, value = fallback_::value); \
          typedef fallback_ type; \
      }; \
    /**/

#endif // BOOST_MPL_CFG_NO_HAS_XXX_TEMPLATE

#   define QSBOOST_MPL_HAS_XXX_TEMPLATE_DEF(name) \
      QSBOOST_MPL_HAS_XXX_TEMPLATE_NAMED_DEF( \
          QSBOOST_PP_CAT(has_, name), name, false \
      ) \
    /**/

#endif // BOOST_MPL_HAS_XXX_HPP_INCLUDED

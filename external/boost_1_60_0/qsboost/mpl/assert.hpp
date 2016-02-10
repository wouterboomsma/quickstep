
#ifndef QSBOOST_MPL_ASSERT_HPP_INCLUDED
#define QSBOOST_MPL_ASSERT_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2000-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/not.hpp>
#include <qsboost/mpl/aux_/value_wknd.hpp>
#include <qsboost/mpl/aux_/nested_type_wknd.hpp>
#include <qsboost/mpl/aux_/yes_no.hpp>
#include <qsboost/mpl/aux_/na.hpp>
#include <qsboost/mpl/aux_/adl_barrier.hpp>

#include <qsboost/mpl/aux_/config/nttp.hpp>
#include <qsboost/mpl/aux_/config/dtp.hpp>
#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/msvc.hpp>
#include <qsboost/mpl/aux_/config/gpu.hpp>
#include <qsboost/mpl/aux_/config/static_constant.hpp>
#include <qsboost/mpl/aux_/config/pp_counter.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#include <qsboost/preprocessor/cat.hpp>

#include <qsboost/config.hpp> // make sure 'size_t' is placed into 'std'
#include <cstddef>

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1700)
#include <qsboost/mpl/if.hpp>
#endif

#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
    || (QSBOOST_MPL_CFG_GCC != 0) \
    || QSBOOST_WORKAROUND(__IBMCPP__, <= 600)
#   define QSBOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES
#endif

#if QSBOOST_WORKAROUND(__MWERKS__, < 0x3202) \
    || QSBOOST_WORKAROUND(__EDG_VERSION__, <= 238) \
    || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
    || QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840))
#   define QSBOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
#endif

// agurt, 10/nov/06: use enums for Borland (which cannot cope with static constants) 
// and GCC (which issues "unused variable" warnings when static constants are used 
// at a function scope)
#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610)) \
    || (QSBOOST_MPL_CFG_GCC != 0) || (QSBOOST_MPL_CFG_GPU != 0)
#   define QSBOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) enum { expr }
#else
#   define QSBOOST_MPL_AUX_ASSERT_CONSTANT(T, expr) QSBOOST_STATIC_CONSTANT(T, expr)
#endif


QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN

struct failed {};

// agurt, 24/aug/04: MSVC 7.1 workaround here and below: return/accept 
// 'assert<false>' by reference; can't apply it unconditionally -- apparently it
// degrades the quality of GCC diagnostics
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1310)
#   define AUX778076_ASSERT_ARG(x) x&
#else
#   define AUX778076_ASSERT_ARG(x) x
#endif

template< bool C >  struct assert        { typedef void* type; };
template<>          struct assert<false> { typedef AUX778076_ASSERT_ARG(assert) type; };

template< bool C >
int assertion_failed( typename assert<C>::type );

template< bool C >
struct assertion
{
    static int failed( assert<false> );
};

template<>
struct assertion<true>
{
    static int failed( void* );
};

struct assert_
{
#if !defined(QSBOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
    template< typename T1, typename T2 = na, typename T3 = na, typename T4 = na > struct types {};
#endif
    static assert_ const arg;
    enum relations { equal = 1, not_equal, greater, greater_equal, less, less_equal };
};


#if !defined(QSBOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

bool operator==( failed, failed );
bool operator!=( failed, failed );
bool operator>( failed, failed );
bool operator>=( failed, failed );
bool operator<( failed, failed );
bool operator<=( failed, failed );

#if defined(__EDG_VERSION__)
template< bool (*)(failed, failed), long x, long y > struct assert_relation {};
#   define QSBOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<r,x,y>
#else
template< QSBOOST_MPL_AUX_NTTP_DECL(long, x), QSBOOST_MPL_AUX_NTTP_DECL(long, y), bool (*)(failed, failed) > 
struct assert_relation {};
#   define QSBOOST_MPL_AUX_ASSERT_RELATION(x, y, r) assert_relation<x,y,r>
#endif

#else // BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

qsboost::mpl::aux::weighted_tag<1>::type operator==( assert_, assert_ );
qsboost::mpl::aux::weighted_tag<2>::type operator!=( assert_, assert_ );
qsboost::mpl::aux::weighted_tag<3>::type operator>(  assert_, assert_ );
qsboost::mpl::aux::weighted_tag<4>::type operator>=( assert_, assert_ );
qsboost::mpl::aux::weighted_tag<5>::type operator<( assert_, assert_ );
qsboost::mpl::aux::weighted_tag<6>::type operator<=( assert_, assert_ );

template< assert_::relations r, long x, long y > struct assert_relation {};

#endif 

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1700)

template<class Pred>
struct extract_assert_pred;

template<class Pred>
struct extract_assert_pred<void(Pred)> { typedef Pred type; };

template<class Pred>
struct eval_assert {
    typedef typename extract_assert_pred<Pred>::type P;
    typedef typename P::type p_type;
    typedef typename ::qsboost::mpl::if_c<p_type::value,
        AUX778076_ASSERT_ARG(assert<false>),
        failed ************ P::************
    >::type type;
};

template<class Pred>
struct eval_assert_not {
    typedef typename extract_assert_pred<Pred>::type P;
    typedef typename P::type p_type;
    typedef typename ::qsboost::mpl::if_c<!p_type::value,
        AUX778076_ASSERT_ARG(assert<false>),
        failed ************ ::qsboost::mpl::not_<P>::************
    >::type type;
};

template< typename T >
T make_assert_arg();

#elif !defined(QSBOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)

template< bool > struct assert_arg_pred_impl { typedef int type; };
template<> struct assert_arg_pred_impl<true> { typedef void* type; };

template< typename P > struct assert_arg_pred
{
    typedef typename P::type p_type;
    typedef typename assert_arg_pred_impl< p_type::value >::type type;
};

template< typename P > struct assert_arg_pred_not
{
    typedef typename P::type p_type;
    QSBOOST_MPL_AUX_ASSERT_CONSTANT( bool, p = !p_type::value );
    typedef typename assert_arg_pred_impl<p>::type type;
};

template< typename Pred >
failed ************ (Pred::************ 
      assert_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type )
    );

template< typename Pred >
failed ************ (qsboost::mpl::not_<Pred>::************ 
      assert_not_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type )
    );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_arg( void (*)(Pred), typename assert_arg_pred_not<Pred>::type );

template< typename Pred >
AUX778076_ASSERT_ARG(assert<false>)
assert_not_arg( void (*)(Pred), typename assert_arg_pred<Pred>::type );


#else // BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER
        
template< bool c, typename Pred > struct assert_arg_type_impl
{
    typedef failed      ************ Pred::* mwcw83_wknd;
    typedef mwcw83_wknd ************* type;
};

template< typename Pred > struct assert_arg_type_impl<true,Pred>
{
    typedef AUX778076_ASSERT_ARG(assert<false>) type;
};

template< typename Pred > struct assert_arg_type
    : assert_arg_type_impl< QSBOOST_MPL_AUX_VALUE_WKND(QSBOOST_MPL_AUX_NESTED_TYPE_WKND(Pred))::value, Pred >
{
};

template< typename Pred >
typename assert_arg_type<Pred>::type 
assert_arg(void (*)(Pred), int);

template< typename Pred >
typename assert_arg_type< qsboost::mpl::not_<Pred> >::type 
assert_not_arg(void (*)(Pred), int);

#   if !defined(QSBOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)
template< long x, long y, bool (*r)(failed, failed) >
typename assert_arg_type_impl< false,QSBOOST_MPL_AUX_ASSERT_RELATION(x,y,r) >::type
assert_rel_arg( QSBOOST_MPL_AUX_ASSERT_RELATION(x,y,r) );
#   else
template< assert_::relations r, long x, long y >
typename assert_arg_type_impl< false,assert_relation<r,x,y> >::type
assert_rel_arg( assert_relation<r,x,y> );
#   endif

#endif // BOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER

#undef AUX778076_ASSERT_ARG

QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1700)

// BOOST_MPL_ASSERT((pred<x,...>))

#define QSBOOST_MPL_ASSERT(pred) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          qsboost::mpl::assertion_failed<false>( \
              qsboost::mpl::make_assert_arg< \
                  typename qsboost::mpl::eval_assert<void pred>::type \
                >() \
            ) \
        ) \
    ) \
/**/

// BOOST_MPL_ASSERT_NOT((pred<x,...>))

#define QSBOOST_MPL_ASSERT_NOT(pred) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          qsboost::mpl::assertion_failed<false>( \
              qsboost::mpl::make_assert_arg< \
                  typename qsboost::mpl::eval_assert_not<void pred>::type \
                >() \
            ) \
        ) \
    ) \
/**/

#else

// BOOST_MPL_ASSERT((pred<x,...>))

#define QSBOOST_MPL_ASSERT(pred) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          qsboost::mpl::assertion_failed<false>( \
              qsboost::mpl::assert_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
    ) \
/**/

// BOOST_MPL_ASSERT_NOT((pred<x,...>))

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300)
#   define QSBOOST_MPL_ASSERT_NOT(pred) \
enum { \
      QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          qsboost::mpl::assertion<false>::failed( \
              qsboost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
}\
/**/
#else
#   define QSBOOST_MPL_ASSERT_NOT(pred) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
          qsboost::mpl::assertion_failed<false>( \
              qsboost::mpl::assert_not_arg( (void (*) pred)0, 1 ) \
            ) \
        ) \
   ) \
/**/
#endif

#endif

// BOOST_MPL_ASSERT_RELATION(x, ==|!=|<=|<|>=|>, y)

#if defined(QSBOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES)

#   if !defined(QSBOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
// agurt, 9/nov/06: 'enum' below is a workaround for gcc 4.0.4/4.1.1 bugs #29522 and #29518
#   define QSBOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)      \
enum { QSBOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) }; \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        qsboost::mpl::assertion_failed<QSBOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
            (qsboost::mpl::failed ************ ( qsboost::mpl::assert_relation< \
                  qsboost::mpl::assert_::relations( sizeof( \
                      qsboost::mpl::assert_::arg rel qsboost::mpl::assert_::arg \
                    ) ) \
                , x \
                , y \
                >::************)) 0 ) \
        ) \
    ) \
/**/
#   else
#   define QSBOOST_MPL_ASSERT_RELATION_IMPL(counter, x, rel, y)    \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assert_rel,counter) = sizeof( \
          qsboost::mpl::assert_::arg rel qsboost::mpl::assert_::arg \
        ) \
    ); \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( bool, QSBOOST_PP_CAT(mpl_assert_rel_value,counter) = (x rel y) ); \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        qsboost::mpl::assertion_failed<QSBOOST_PP_CAT(mpl_assert_rel_value,counter)>( \
              qsboost::mpl::assert_rel_arg( qsboost::mpl::assert_relation< \
                  qsboost::mpl::assert_::relations(QSBOOST_PP_CAT(mpl_assert_rel,counter)) \
                , x \
                , y \
                >() ) \
            ) \
        ) \
    ) \
/**/
#   endif

#   define QSBOOST_MPL_ASSERT_RELATION(x, rel, y) \
QSBOOST_MPL_ASSERT_RELATION_IMPL(QSBOOST_MPL_AUX_PP_COUNTER(), x, rel, y) \
/**/

#else // !BOOST_MPL_CFG_ASSERT_USE_RELATION_NAMES

#   if defined(QSBOOST_MPL_CFG_ASSERT_BROKEN_POINTER_TO_POINTER_TO_MEMBER)
#   define QSBOOST_MPL_ASSERT_RELATION(x, rel, y) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        qsboost::mpl::assertion_failed<(x rel y)>( qsboost::mpl::assert_rel_arg( \
              qsboost::mpl::QSBOOST_MPL_AUX_ASSERT_RELATION(x,y,(&qsboost::mpl::operator rel))() \
            ) ) \
        ) \
    ) \
/**/
#   else
#   define QSBOOST_MPL_ASSERT_RELATION(x, rel, y) \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,QSBOOST_MPL_AUX_PP_COUNTER()) = sizeof( \
        qsboost::mpl::assertion_failed<(x rel y)>( (qsboost::mpl::failed ************ ( \
            qsboost::mpl::QSBOOST_MPL_AUX_ASSERT_RELATION(x,y,(&qsboost::mpl::operator rel))::************))0 ) \
        ) \
    ) \
/**/
#   endif

#endif


// BOOST_MPL_ASSERT_MSG( (pred<x,...>::value), USER_PROVIDED_MESSAGE, (types<x,...>) ) 

#if QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3202))
#   define QSBOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ ) \
struct msg; \
typedef struct QSBOOST_PP_CAT(msg,counter) : qsboost::mpl::assert_ \
{ \
    using qsboost::mpl::assert_::types; \
    static qsboost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} QSBOOST_PP_CAT(mpl_assert_arg,counter); \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        qsboost::mpl::assertion<(c)>::failed( QSBOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#else
#   define QSBOOST_MPL_ASSERT_MSG_IMPL( counter, c, msg, types_ )  \
struct msg; \
typedef struct QSBOOST_PP_CAT(msg,counter) : qsboost::mpl::assert_ \
{ \
    static qsboost::mpl::failed ************ (msg::************ assert_arg()) types_ \
    { return 0; } \
} QSBOOST_PP_CAT(mpl_assert_arg,counter); \
QSBOOST_MPL_AUX_ASSERT_CONSTANT( \
      std::size_t \
    , QSBOOST_PP_CAT(mpl_assertion_in_line_,counter) = sizeof( \
        qsboost::mpl::assertion_failed<(c)>( QSBOOST_PP_CAT(mpl_assert_arg,counter)::assert_arg() ) \
        ) \
    ) \
/**/
#endif

#define QSBOOST_MPL_ASSERT_MSG( c, msg, types_ ) \
QSBOOST_MPL_ASSERT_MSG_IMPL( QSBOOST_MPL_AUX_PP_COUNTER(), c, msg, types_ ) \
/**/

#endif // BOOST_MPL_ASSERT_HPP_INCLUDED

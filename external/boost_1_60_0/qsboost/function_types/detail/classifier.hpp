
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_DETAIL_CLASSIFIER_HPP_INCLUDED
#define QSBOOST_FT_DETAIL_CLASSIFIER_HPP_INCLUDED

#include <qsboost/type.hpp>
#include <qsboost/config.hpp>
#include <qsboost/type_traits/is_reference.hpp>
#include <qsboost/type_traits/add_reference.hpp>

#include <qsboost/function_types/config/config.hpp>
#include <qsboost/function_types/property_tags.hpp>

namespace qsboost { namespace function_types { namespace detail {

template<typename T> struct classifier;

template<std::size_t S> struct char_array { typedef char (&type)[S]; };

template<bits_t Flags, bits_t CCID, std::size_t Arity> struct encode_charr
{
  typedef typename char_array<
    ::qsboost::function_types::detail::encode_charr_impl<Flags,CCID,Arity>::value 
  >::type type;
};

#if defined(QSBOOST_MSVC) || (defined(__BORLANDC__) && !defined(QSBOOST_DISABLE_WIN32))
#   define QSBOOST_FT_DECL __cdecl
#else
#   define QSBOOST_FT_DECL /**/
#endif

char QSBOOST_FT_DECL classifier_impl(...);

#define QSBOOST_FT_variations QSBOOST_FT_function|QSBOOST_FT_pointer|\
                            QSBOOST_FT_member_pointer

#define QSBOOST_FT_type_function(cc,name) QSBOOST_FT_SYNTAX( \
    R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,* QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)

#define QSBOOST_FT_type_function_pointer(cc,name) QSBOOST_FT_SYNTAX( \
    R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,** QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)

#define QSBOOST_FT_type_member_function_pointer(cc,name) QSBOOST_FT_SYNTAX( \
    R QSBOOST_PP_EMPTY,QSBOOST_PP_LPAREN,cc,T0::** QSBOOST_PP_EMPTY,name,QSBOOST_PP_RPAREN)

#define QSBOOST_FT_al_path qsboost/function_types/detail/classifier_impl
#include <qsboost/function_types/detail/pp_loop.hpp>

template<typename T> struct classifier_bits
{
  static typename qsboost::add_reference<T>::type tester;

  QSBOOST_STATIC_CONSTANT(bits_t,value = (bits_t)sizeof(
    qsboost::function_types::detail::classifier_impl(& tester) 
  )-1);
};

template<typename T> struct classifier
{
  typedef detail::constant<
    ::qsboost::function_types::detail::decode_bits<
      ::qsboost::function_types::detail::classifier_bits<T>::value
    >::tag_bits > 
  bits;

  typedef detail::full_mask mask;
 
  typedef detail::constant<
    ::qsboost::function_types::detail::decode_bits<
      ::qsboost::function_types::detail::classifier_bits<T>::value
    >::arity > 
  function_arity;
};



} } } // namespace ::boost::function_types::detail

#endif


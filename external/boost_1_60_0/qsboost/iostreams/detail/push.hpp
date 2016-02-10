// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED 

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                    
 
#include <qsboost/config.hpp> // BOOST_MSVC.
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/categories.hpp>
#include <qsboost/iostreams/categories.hpp>
#include <qsboost/iostreams/detail/adapter/range_adapter.hpp>
#include <qsboost/iostreams/detail/config/wide_streams.hpp>
#include <qsboost/iostreams/detail/enable_if_stream.hpp>   
#include <qsboost/iostreams/pipeline.hpp>   
#include <qsboost/iostreams/detail/push_params.hpp>   
#include <qsboost/iostreams/detail/resolve.hpp>
#include <qsboost/mpl/bool.hpp>   
#include <qsboost/preprocessor/cat.hpp> 
#include <qsboost/preprocessor/control/iif.hpp>
#include <qsboost/static_assert.hpp>
#include <qsboost/type_traits/is_convertible.hpp>

//
// Macro: BOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper).
// Description: Defines overloads with name 'name' which forward to a function
//      'helper' which takes a filter or devide by const reference.
//
#define QSBOOST_IOSTREAMS_DEFINE_PUSH_CONSTRUCTOR(name, mode, ch, helper) \
    QSBOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 0, ?) \
    /**/

//
// Macro: BOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper).
// Description: Defines constructors which forward to a function
//      'helper' which takes a filter or device by const reference.
//
#define QSBOOST_IOSTREAMS_DEFINE_PUSH(name, mode, ch, helper) \
    QSBOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, 1, void) \
    /**/

//--------------------Definition of BOOST_IOSTREAMS_DEFINE_PUSH_IMPL----------//
          
#define QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, arg, helper, has_return) \
    this->helper( ::qsboost::iostreams::detail::resolve<mode, ch>(arg) \
                  QSBOOST_IOSTREAMS_PUSH_ARGS() ); \
    /**/

#if !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) && \
    !QSBOOST_WORKAROUND(__BORLANDC__, < 0x600) \
    /**/
# ifndef QSBOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define QSBOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename CharType, typename TraitsType> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_streambuf<CharType, TraitsType>& sb QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_istream<CharType, TraitsType>& is QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_ostream<CharType, TraitsType>& os QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    template<typename CharType, typename TraitsType> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(::std::basic_iostream<CharType, TraitsType>& io QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::qsboost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  QSBOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(const ::qsboost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    QSBOOST_PP_IIF(has_return, result, explicit) \
    name(const T& t QSBOOST_IOSTREAMS_PUSH_PARAMS() QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::qsboost::iostreams::detail::resolve<mode, ch>(t) \
                    QSBOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# else // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#  define QSBOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(::std::streambuf& sb QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, sb, helper, has_return); } \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(::std::istream& is QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_STATIC_ASSERT((!is_convertible<mode, output>::value)); \
      QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, is, helper, has_return); } \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(::std::ostream& os QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_STATIC_ASSERT((!is_convertible<mode, input>::value)); \
      QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, os, helper, has_return); } \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(::std::iostream& io QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_IOSTREAMS_ADAPT_STREAM(mode, ch, io, helper, has_return); } \
    template<typename Iter> \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(const iterator_range<Iter>& rng QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { QSBOOST_PP_EXPR_IF(has_return, return) \
    this->helper( ::qsboost::iostreams::detail::range_adapter< \
                      mode, iterator_range<Iter> \
                  >(rng) \
                  QSBOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename Pipeline, typename Concept> \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(const ::qsboost::iostreams::pipeline<Pipeline, Concept>& p) \
    { p.push(*this); } \
    template<typename T> \
    QSBOOST_PP_EXPR_IF(has_return, result) \
    name(const T& t QSBOOST_IOSTREAMS_PUSH_PARAMS() QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T)) \
    { this->helper( ::qsboost::iostreams::detail::resolve<mode, ch>(t) \
                    QSBOOST_IOSTREAMS_PUSH_ARGS() ); } \
    /**/
# endif // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES
#else // #if VC6, VC7.0, Borland 5.x
# define QSBOOST_IOSTREAMS_DEFINE_PUSH_IMPL(name, mode, ch, helper, has_return, result) \
    template<typename T> \
    void QSBOOST_PP_CAT(name, _msvc_impl) \
    ( ::qsboost::mpl::true_, const T& t QSBOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { t.push(*this); } \
    template<typename T> \
    void QSBOOST_PP_CAT(name, _msvc_impl) \
    ( ::qsboost::mpl::false_, const T& t QSBOOST_IOSTREAMS_PUSH_PARAMS() ) \
    { this->helper( ::qsboost::iostreams::detail::resolve<mode, ch>(t) \
                    QSBOOST_IOSTREAMS_PUSH_ARGS() ); } \
    template<typename T> \
    QSBOOST_PP_IF(has_return, result, explicit) \
    name(const T& t QSBOOST_IOSTREAMS_PUSH_PARAMS()) \
    { \
        this->QSBOOST_PP_CAT(name, _msvc_impl) \
              ( ::qsboost::iostreams::detail::is_pipeline<T>(), \
                t QSBOOST_IOSTREAMS_PUSH_ARGS() ); \
    } \
    /**/
#endif // #if VC6, VC7.0, Borland 5.x

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_PUSH_HPP_INCLUDED

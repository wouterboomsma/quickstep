// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED   

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif                  
 
#include <qsboost/config.hpp> // BOOST_MSVC, BOOST_NO_SFINAE
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/config/limits.hpp>
#include <qsboost/iostreams/detail/push_params.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/preprocessor/punctuation/comma_if.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/type_traits/is_same.hpp>

//------Macros for defining forwarding constructors and open overloads--------//
    
//
// Macro: BOOST_IOSTREAMS_FORWARD(class, impl, device, params, args)
// Description: Defines constructors and overloads of 'open' which construct
//      a device using the specified argument list and pass it to the specified
//      helper function
//   class - The class name
//   impl - The helper function
//   device - The device type
//   params - The list of formal parameters trailing the device parameter in
//     the helper function's signature
//   params - The list of arguments passed to the helper function, following the
//     device argument
//
#define QSBOOST_IOSTREAMS_FORWARD(class, impl, device, params, args) \
    class(const device& t params()) \
    { this->impl(::qsboost::iostreams::detail::wrap(t) args()); } \
    class(device& t params()) \
    { this->impl(::qsboost::iostreams::detail::wrap(t) args()); } \
    class(const ::qsboost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    void open(const device& t params()) \
    { this->impl(::qsboost::iostreams::detail::wrap(t) args()); } \
    void open(device& t params()) \
    { this->impl(::qsboost::iostreams::detail::wrap(t) args()); } \
    void open(const ::qsboost::reference_wrapper<device>& ref params()) \
    { this->impl(ref args()); } \
    QSBOOST_PP_REPEAT_FROM_TO( \
        1, QSBOOST_PP_INC(QSBOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        QSBOOST_IOSTREAMS_FORWARDING_CTOR, (class, impl, device) \
    ) \
    QSBOOST_PP_REPEAT_FROM_TO( \
        1, QSBOOST_PP_INC(QSBOOST_IOSTREAMS_MAX_FORWARDING_ARITY), \
        QSBOOST_IOSTREAMS_FORWARDING_FN, (class, impl, device) \
    ) \
    /**/
#if !QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
# define QSBOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    template< typename U100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
              QSBOOST_PP_ENUM_PARAMS_Z(z, QSBOOST_PP_DEC(n), typename U) > \
    QSBOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    ( U100& u100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
      QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, QSBOOST_PP_DEC(n), const U, &u) \
      QSBOOST_IOSTREAMS_DISABLE_IF_SAME(U100, QSBOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->QSBOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( QSBOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        ( u100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
          QSBOOST_PP_ENUM_PARAMS_Z(z, QSBOOST_PP_DEC(n), u)) ); } \
    /**/
# define QSBOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    template< typename U100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
              QSBOOST_PP_ENUM_PARAMS_Z(z, QSBOOST_PP_DEC(n), typename U) > \
    void open \
    ( U100& u100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
      QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, QSBOOST_PP_DEC(n), const U, &u) \
      QSBOOST_IOSTREAMS_DISABLE_IF_SAME(U100, QSBOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->QSBOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( u100 QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
        QSBOOST_PP_ENUM_PARAMS_Z(z, QSBOOST_PP_DEC(n), u) ); } \
    /**/
#else
# define QSBOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple)
# define QSBOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple)
#endif
#define QSBOOST_IOSTREAMS_FORWARDING_CTOR(z, n, tuple) \
    template<QSBOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    QSBOOST_PP_TUPLE_ELEM(3, 0, tuple) \
    (QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      QSBOOST_IOSTREAMS_DISABLE_IF_SAME(U0, QSBOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->QSBOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( QSBOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (QSBOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    QSBOOST_IOSTREAMS_FORWARDING_CTOR_I(z, n, tuple) \
    /**/
#define QSBOOST_IOSTREAMS_FORWARDING_FN(z, n, tuple) \
    template<QSBOOST_PP_ENUM_PARAMS_Z(z, n, typename U)> \
    void open(QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, n, const U, &u) \
      QSBOOST_IOSTREAMS_DISABLE_IF_SAME(U0, QSBOOST_PP_TUPLE_ELEM(3, 2, tuple))) \
    { this->QSBOOST_PP_TUPLE_ELEM(3, 1, tuple) \
      ( QSBOOST_PP_TUPLE_ELEM(3, 2, tuple) \
        (QSBOOST_PP_ENUM_PARAMS_Z(z, n, u)) ); } \
    QSBOOST_IOSTREAMS_FORWARDING_FN_I(z, n, tuple) \
    /**/

// Disable forwarding constructors if first parameter type is the same
// as the device type
#if !defined(QSBOOST_NO_SFINAE) && \
    !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x592))
# define QSBOOST_IOSTREAMS_DISABLE_IF_SAME(device, param) \
    , typename qsboost::disable_if< qsboost::is_same<device, param> >::type* = 0 \
    /**/
#else 
# define QSBOOST_IOSTREAMS_DISABLE_IF_SAME(device, param)
#endif

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_FORWARD_HPP_INCLUDED

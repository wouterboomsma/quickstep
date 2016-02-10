// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED     

#include <qsboost/config.hpp> // BOOST_STATIC_CONSTANT.
#include <qsboost/iostreams/detail/template_params.hpp>
#include <qsboost/mpl/aux_/lambda_support.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/type_traits/detail/yes_no_type.hpp>
 
// 
// Macro name: BOOST_IOSTREAMS_BOOL_TRAIT_DEF
// Description: Used to generate the traits classes is_istream, is_ostream,
//      etc.
//
#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x582))
# define QSBOOST_IOSTREAMS_TRAIT_NAMESPACE(trait)
#else
# define QSBOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) QSBOOST_PP_CAT(trait, _impl_):: 
#endif
#define QSBOOST_IOSTREAMS_BOOL_TRAIT_DEF(trait, type, arity) \
    namespace QSBOOST_PP_CAT(trait, _impl_) { \
      QSBOOST_IOSTREAMS_TEMPLATE_PARAMS(arity, T) \
      type_traits::yes_type helper \
          (const volatile type QSBOOST_IOSTREAMS_TEMPLATE_ARGS(arity, T)*); \
      type_traits::no_type helper(...); \
      template<typename T> \
      struct impl { \
           QSBOOST_STATIC_CONSTANT(bool, value = \
           (sizeof(QSBOOST_IOSTREAMS_TRAIT_NAMESPACE(trait) \
              helper(static_cast<T*>(0))) == \
                sizeof(type_traits::yes_type))); \
      }; \
    } \
    template<typename T> \
    struct trait \
        : mpl::bool_<QSBOOST_PP_CAT(trait, _impl_)::impl<T>::value> \
    { QSBOOST_MPL_AUX_LAMBDA_SUPPORT(1, trait, (T)) }; \
    /**/

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_BOOL_TRAIT_DEF_HPP_INCLUDED

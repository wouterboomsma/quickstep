/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2009 Francois Barel

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_EXTRACT_PARAM_AUGUST_08_2009_0848AM)
#define QSBOOST_SPIRIT_EXTRACT_PARAM_AUGUST_08_2009_0848AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/support/meta_compiler.hpp>
#include <qsboost/spirit/home/support/nonterminal/locals.hpp>
#include <qsboost/spirit/home/support/unused.hpp>
#include <qsboost/spirit/home/support/common_terminals.hpp>

#include <qsboost/function_types/is_function.hpp>
#include <qsboost/function_types/parameter_types.hpp>
#include <qsboost/function_types/result_type.hpp>
#include <qsboost/fusion/include/as_list.hpp>
#include <qsboost/fusion/include/as_vector.hpp>
#include <qsboost/mpl/deref.hpp>
#include <qsboost/mpl/end.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/find_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/or.hpp>
#include <qsboost/mpl/and.hpp>
#include <qsboost/mpl/placeholders.hpp>
#include <qsboost/type_traits/is_same.hpp>

namespace qsboost { namespace spirit { namespace detail
{
    ///////////////////////////////////////////////////////////////////////////
    // Helpers to extract params (locals, attributes, ...) from nonterminal
    // template arguments
    ///////////////////////////////////////////////////////////////////////////
    template <typename Types, typename Pred, typename Default>
    struct extract_param
    {
        typedef typename mpl::find_if<Types, Pred>::type pos;

        typedef typename
            mpl::eval_if<
                is_same<pos, typename mpl::end<Types>::type>
              , mpl::identity<Default>
              , mpl::deref<pos>
            >::type
        type;
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Types>
    struct extract_locals
      : fusion::result_of::as_vector<
            typename extract_param<
                Types
              , is_locals<mpl::_>
              , locals<>
            >::type
        >
    {};

    ///////////////////////////////////////////////////////////////////////////
    template <typename Domain, typename Types>
    struct extract_component
      : spirit::result_of::compile<
            Domain
          , typename extract_param<
                Types
              , traits::matches<Domain, mpl::_>
              , unused_type
            >::type
        >
    {};

    ///////////////////////////////////////////////////////////////////////////
    template <typename T>
    struct make_function_type : mpl::identity<T()> {};

    ///////////////////////////////////////////////////////////////////////////
    template <typename Types, typename Encoding, typename Domain>
    struct extract_sig
    {
        typedef typename
            extract_param<
                Types
              , mpl::or_<
                    function_types::is_function<mpl::_>
                  , mpl::and_<
                        mpl::not_<is_locals<mpl::_> >
                      , mpl::not_<is_same<mpl::_, Encoding> >
                      , mpl::not_<traits::matches<Domain, mpl::_> >
                      , mpl::not_<is_same<mpl::_, unused_type> >
                    >
                >
              , void()
            >::type
        attr_of_ftype;

        typedef typename
            mpl::eval_if<
                function_types::is_function<attr_of_ftype>
              , mpl::identity<attr_of_ftype>
              , make_function_type<attr_of_ftype>
            >::type
        type;
    };

    template <typename Sig>
    struct attr_from_sig
    {
        typedef typename function_types::result_type<Sig>::type attr;

        typedef typename
            mpl::if_<
                is_same<attr, void>
              , unused_type
              , attr
            >::type
        type;
    };

    template <typename Sig>
    struct params_from_sig
    {
        typedef typename function_types::parameter_types<Sig>::type params;

        typedef typename fusion::result_of::as_list<params>::type type;
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename Types>
    struct extract_encoding
      : extract_param<
            Types
          , is_char_encoding<mpl::_>
          , unused_type
        >
    {};
}}}

#endif

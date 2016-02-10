/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c)      2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_ARGUMENT_FEBRUARY_17_2007_0339PM)
#define QSBOOST_SPIRIT_ARGUMENT_FEBRUARY_17_2007_0339PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/preprocessor/repetition/repeat_from_to.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/spirit/include/phoenix_core.hpp>
#include <qsboost/spirit/home/support/assert_msg.hpp>
#include <qsboost/spirit/home/support/limits.hpp>
#include <qsboost/fusion/include/at.hpp>
#include <qsboost/fusion/include/size.hpp>
#include <qsboost/mpl/size.hpp>
#include <qsboost/mpl/at.hpp>

#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS

#define SPIRIT_DECLARE_ARG(z, n, data)                                        \
    typedef phoenix::actor<argument<n> >                                      \
        QSBOOST_PP_CAT(QSBOOST_PP_CAT(_, QSBOOST_PP_INC(n)), _type);                \
    phoenix::actor<argument<n> > const                                        \
        QSBOOST_PP_CAT(_, QSBOOST_PP_INC(n)) =                                    \
            QSBOOST_PP_CAT(QSBOOST_PP_CAT(_, QSBOOST_PP_INC(n)), _type)();          \
        /***/

#define SPIRIT_USING_ARGUMENT(z, n, data)                                     \
    using spirit::QSBOOST_PP_CAT(QSBOOST_PP_CAT(_, n), _type);                    \
    using spirit::QSBOOST_PP_CAT(_, n);                                         \
        /***/

#else

#define SPIRIT_DECLARE_ARG(z, n, data)                                        \
    typedef phoenix::actor<argument<n> >                                      \
        QSBOOST_PP_CAT(QSBOOST_PP_CAT(_, QSBOOST_PP_INC(n)), _type);                \
        /***/

#define SPIRIT_USING_ARGUMENT(z, n, data)                                     \
    using spirit::QSBOOST_PP_CAT(QSBOOST_PP_CAT(_, n), _type);                    \
        /***/

#endif

namespace qsboost { namespace spirit
{
    template <int N>
    struct argument;

    template <typename Dummy>
    struct attribute_context;
}}

QSBOOST_PHOENIX_DEFINE_CUSTOM_TERMINAL(
    template <int N>
  , qsboost::spirit::argument<N>
  , mpl::false_                 // is not nullary
  , v2_eval(
        proto::make<
            qsboost::spirit::argument<N>()
        >
      , proto::call<
            functional::env(proto::_state)
        >
    )
)

QSBOOST_PHOENIX_DEFINE_CUSTOM_TERMINAL(
    template <typename Dummy>
  , qsboost::spirit::attribute_context<Dummy>
  , mpl::false_                 // is not nullary
  , v2_eval(
        proto::make<
            qsboost::spirit::attribute_context<Dummy>()
        >
      , proto::call<
            functional::env(proto::_state)
        >
    )
)

namespace qsboost { namespace spirit
{
    namespace result_of
    {
        template <typename Sequence, int N>
        struct get_arg
        {
            typedef typename
                fusion::result_of::size<Sequence>::type
            sequence_size;

            // report invalid argument not found (N is out of bounds)
            QSBOOST_SPIRIT_ASSERT_MSG(
                (N < sequence_size::value),
                index_is_out_of_bounds, ());

            typedef typename
                fusion::result_of::at_c<Sequence, N>::type
            type;

            static type call(Sequence& seq)
            {
                return fusion::at_c<N>(seq);
            }
        };

        template <typename Sequence, int N>
        struct get_arg<Sequence&, N> : get_arg<Sequence, N>
        {
        };
    }

    template <int N, typename T>
    typename result_of::get_arg<T, N>::type
    get_arg(T& val)
    {
        return result_of::get_arg<T, N>::call(val);
    }

    template <typename>
    struct attribute_context
    {
        typedef mpl::true_ no_nullary;

        template <typename Env>
        struct result
        {
            // FIXME: is this remove_const really necessary?
            typedef typename
                remove_const<
                    typename mpl::at_c<typename Env::args_type, 0>::type
                >::type
            type;
        };

        template <typename Env>
        typename result<Env>::type
        eval(Env const& env) const
        {
            return fusion::at_c<0>(env.args());
        }
    };

    template <int N>
    struct argument
    {
        typedef mpl::true_ no_nullary;

        template <typename Env>
        struct result
        {
            typedef typename
                mpl::at_c<typename Env::args_type, 0>::type
            arg_type;

            typedef typename result_of::get_arg<arg_type, N>::type type;
        };

        template <typename Env>
        typename result<Env>::type
        eval(Env const& env) const
        {
            return get_arg<N>(fusion::at_c<0>(env.args()));
        }
    };

    // _0 refers to the whole attribute as generated by the lhs parser
    typedef phoenix::actor<attribute_context<void> > _0_type;
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    _0_type const _0 = _0_type();
#endif

    // _1, _2, ... refer to the attributes of the single components the lhs
    // parser is composed of
    typedef phoenix::actor<argument<0> > _1_type;
    typedef phoenix::actor<argument<1> > _2_type;
    typedef phoenix::actor<argument<2> > _3_type;

#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    _1_type const _1 = _1_type();
    _2_type const _2 = _2_type();
    _3_type const _3 = _3_type();
#endif

    // '_pass' may be used to make a match fail in retrospective
    typedef phoenix::arg_names::_3_type _pass_type;
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    _pass_type const _pass = _pass_type();
#endif

    //  Bring in the rest of the arguments and attributes (_4 .. _N+1), using PP
    QSBOOST_PP_REPEAT_FROM_TO(
        3, SPIRIT_ARGUMENTS_LIMIT, SPIRIT_DECLARE_ARG, _)

#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    // You can bring these in with the using directive
    // without worrying about bringing in too much.
    namespace labels
    {
        QSBOOST_PP_REPEAT(SPIRIT_ARGUMENTS_LIMIT, SPIRIT_USING_ARGUMENT, _)
    }
#endif

}}

#undef SPIRIT_DECLARE_ARG
#endif

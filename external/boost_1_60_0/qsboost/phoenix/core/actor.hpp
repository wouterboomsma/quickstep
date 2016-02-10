/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller
    Copyright (c) 2014 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOST_PHOENIX_CORE_ACTOR_HPP
#define QSBOOST_PHOENIX_CORE_ACTOR_HPP

#include <qsboost/phoenix/core/limits.hpp>

#include <qsboost/is_placeholder.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/phoenix/core/domain.hpp>
#include <qsboost/phoenix/core/environment.hpp>
#include <qsboost/phoenix/core/is_nullary.hpp>
#include <qsboost/phoenix/core/meta_grammar.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/phoenix/support/vector.hpp>
#include <qsboost/proto/extends.hpp>
#include <qsboost/proto/make_expr.hpp>
#include <qsboost/utility/result_of.hpp>
#include <qsboost/mpl/void.hpp>
#include <cstring>

#ifdef QSBOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4522) // 'this' used in base member initializer list
#pragma warning(disable: 4510) // default constructor could not be generated
#pragma warning(disable: 4610) // can never be instantiated - user defined cons
#endif

namespace qsboost { namespace phoenix
{
    template <typename Expr>
    struct actor;

    namespace detail
    {
        struct error_expecting_arguments
        {
            template <typename T>
            error_expecting_arguments(T const&) {}
        };
        
        struct error_invalid_lambda_expr
        {
            template <typename T>
            error_invalid_lambda_expr(T const&) {}
        };

        template <typename T>
        struct result_type_deduction_helper
        {
            typedef T const & type;
        };

        template <typename T>
        struct result_type_deduction_helper<T &>
        {
            typedef T & type;
        };

        template <typename T>
        struct result_type_deduction_helper<T const &>
        {
            typedef T const & type;
        };

        struct do_assign
        {
            QSBOOST_PROTO_CALLABLE()

            typedef void result_type;

            template <typename T1, typename T2>
            void operator()(T1 & t1, T2 const & t2) const
            {
                proto::value(t1) = proto::value(t2);
            }
        };

    #define QSBOOST_PHOENIX_ACTOR_ASSIGN_CHILD(N)                                 \
        assign(                                                                 \
            proto::_child_c<N>                                                  \
          , proto::call<                                                        \
                proto::_child_c<N>(proto::_state)                               \
            >                                                                   \
        )                                                                       \
    /**/
    #define QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CHILD(Z, N, D)                     \
       proto::and_<                                                             \
            QSBOOST_PHOENIX_ACTOR_ASSIGN_CHILD(N)                                 \
    /**/
    #define QSBOOST_PHOENIX_ACTOR_END_ASSIGN(Z, N, D)                             \
        >                                                                       \
    /**/
    #define QSBOOST_PHOENIX_ACTOR_ASSIGN_CALL(N)                                  \
           proto::when<                                                        \
                proto::nary_expr<proto::_ ,                                     \
                  QSBOOST_PP_ENUM_PARAMS(N, proto::_ QSBOOST_PP_INTERCEPT)          \
                >                                                               \
                , QSBOOST_PP_ENUM(                                                 \
                     N                                                          \
                  , QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CHILD                     \
                  , _                                                          \
                 )                                                              \
                 QSBOOST_PP_REPEAT(                                               \
                     N                                                          \
                   , QSBOOST_PHOENIX_ACTOR_END_ASSIGN                             \
                   , _                                                          \
                 )                                                              \
            >                                                                   \
      /**/
    #define QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CALL(Z, N, D)                      \
        proto::or_<                                                             \
            QSBOOST_PHOENIX_ACTOR_ASSIGN_CALL(N)                                  \
    /**/
 
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/phoenix/core/preprocessed/actor.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/actor_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif
/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010-2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

        struct assign
            : QSBOOST_PP_ENUM_SHIFTED(
                  QSBOOST_PHOENIX_LIMIT
                , QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CALL
                , _
              )
              , proto::when<
                    proto::terminal<proto::_>
                  , do_assign(proto::_, proto::_state)
                >
              QSBOOST_PP_REPEAT(
                  QSBOOST_PP_DEC(QSBOOST_PHOENIX_LIMIT)
                , QSBOOST_PHOENIX_ACTOR_END_ASSIGN
                , _
              )
        {};

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif
    #undef QSBOOST_PHOENIX_ACTOR_ASSIGN_CALL
    #undef QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CALL
    #undef QSBOOST_PHOENIX_ACTOR_END_ASSIGN_CALL
    #undef QSBOOST_PHOENIX_ACTOR_ASSIGN_CHILD
    #undef QSBOOST_PHOENIX_ACTOR_START_ASSIGN_CHILD
    #undef QSBOOST_PHOENIX_ACTOR_END_ASSIGN_CHILD
    }

    // Bring in the result_of::actor<>
    #include <qsboost/phoenix/core/detail/actor_result_of.hpp>

    ////////////////////////////////////////////////////////////////////////////
    //
    //  actor
    //
    //      The actor class. The main thing! In phoenix, everything is an actor
    //      This class is responsible for full function evaluation. Partial
    //      function evaluation involves creating a hierarchy of actor objects.
    //
    ////////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct actor
    {
        typedef typename
            mpl::eval_if_c<
                mpl::or_<
                    is_custom_terminal<Expr>
                  , mpl::bool_<is_placeholder<Expr>::value>
                >::value
              , proto::terminal<Expr>
              , mpl::identity<Expr>
            >::type
            expr_type;
        
        QSBOOST_PROTO_BASIC_EXTENDS(expr_type, actor<expr_type>, phoenix_domain)

        // providing operator= to be assignable
        actor& operator=(actor const& other)
        {
            detail::assign()(*this, other);
            return *this;
        }
        actor& operator=(actor & other)
        {
            detail::assign()(*this, other);
            return *this;
        }

        template <typename A0>
        typename proto::result_of::make_expr<
            proto::tag::assign
          , phoenix_domain
          , proto_base_expr
          , A0
        >::type const
        operator=(A0 const & a0) const
        {
            return proto::make_expr<proto::tag::assign, phoenix_domain>(this->proto_expr_, a0);
        }

        template <typename A0>
        typename proto::result_of::make_expr<
            proto::tag::assign
          , phoenix_domain
          , proto_base_expr
          , A0
        >::type const
        operator=(A0 & a0) const
        {
            return proto::make_expr<proto::tag::assign, phoenix_domain>(this->proto_expr_, a0);
        }
        
        template <typename A0>
        typename proto::result_of::make_expr<
            proto::tag::subscript
          , phoenix_domain
          , proto_base_expr
          , A0
        >::type const
        operator[](A0 const & a0) const
        {
            return proto::make_expr<proto::tag::subscript, phoenix_domain>(this->proto_expr_, a0);
        }

        template <typename A0>
        typename proto::result_of::make_expr<
            proto::tag::subscript
          , phoenix_domain
          , proto_base_expr
          , A0
        >::type const
        operator[](A0 & a0) const
        {
            return proto::make_expr<proto::tag::subscript, phoenix_domain>(this->proto_expr_, a0);
        }

        template <typename Sig>
        struct result;

        typename result_of::actor<proto_base_expr>::type
        operator()()
        {
            typedef vector1<const actor<Expr> *> env_type;
            env_type env = {this};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

        typename result_of::actor<proto_base_expr>::type
        operator()() const
        {
            typedef vector1<const actor<Expr> *> env_type;
            env_type env = {this};
            
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }

        template <typename Env>
        typename evaluator::impl<
            proto_base_expr const &
          , typename result_of::context<
                Env const &
              , default_actions const &
            >::type
          , proto::empty_env
        >::result_type
        eval(Env const & env) const
        {
            return phoenix::eval(*this, phoenix::context(env, default_actions()));
        }
        
        // Bring in the rest
        #include <qsboost/phoenix/core/detail/actor_operator.hpp>
    };

}}

namespace qsboost
{
    // specialize boost::result_of to return the proper result type
    template <typename Expr>
    struct result_of<phoenix::actor<Expr>()>
        : phoenix::result_of::actor<typename phoenix::actor<Expr>::proto_base_expr>
    {};
    
    template <typename Expr>
    struct result_of<phoenix::actor<Expr> const()>
        : phoenix::result_of::actor<typename phoenix::actor<Expr>::proto_base_expr>
    {};
}


#ifdef QSBOOST_MSVC
#pragma warning(pop)
#endif

#endif


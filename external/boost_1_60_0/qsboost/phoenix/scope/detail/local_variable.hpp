/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTPHOENIX_SCOPE_DETAIL_LOCAL_VARIABLE_HPP
#define QSBOOSTPHOENIX_SCOPE_DETAIL_LOCAL_VARIABLE_HPP

#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/fusion/include/at.hpp>
#include <qsboost/fusion/include/value_at.hpp>
#include <qsboost/preprocessor/enum.hpp>
#include <qsboost/preprocessor/repeat.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/type_traits/is_reference.hpp>

#define QSBOOST_PHOENIX_MAP_LOCAL_TEMPLATE_PARAM(z, n, data) \
    typename T##n = unused<n>

#define QSBOOST_PHOENIX_MAP_LOCAL_DISPATCH(z, n, data)  \
    typedef char(&result##n)[n+2];              \
    static result##n get(T##n*);

namespace qsboost { namespace phoenix
{
    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct scoped_environment;

    namespace detail
    {
        template <typename Key>
        struct local
        {
            typedef Key key_type;
        };

        namespace result_of
        {
            template <typename Locals, typename Context>
            struct initialize_locals;
            
            template <typename Context>
            struct initialize_locals<vector0<>, Context>
            {
                typedef vector0<> type;
            };

        #define M1(Z, N, D)                                                     \
            typename qsboost::phoenix::result_of::eval<                           \
                QSBOOST_PP_CAT(A, N)                                              \
              , Context                                                         \
            >::type                                                             \
        /**/

        #define M0(Z, N, D)                                                     \
            template <QSBOOST_PHOENIX_typename_A(N), typename Context>            \
            struct initialize_locals<                                           \
                QSBOOST_PP_CAT(vector, N)<                                        \
                    QSBOOST_PHOENIX_A(N)                                          \
                >                                                               \
              , Context                                                         \
            >                                                                   \
            {                                                                   \
                typedef                                                         \
                    QSBOOST_PP_CAT(vector, N)<                                    \
                        QSBOOST_PP_ENUM(N, M1, _)                                 \
                    >                                                           \
                    type;                                                       \
            };                                                                  \
        /**/
            QSBOOST_PP_REPEAT_FROM_TO(1, QSBOOST_PHOENIX_LIMIT, M0, _)
        #undef M0
        }

        template <typename Context>
        vector0<>
        initialize_locals(vector0<> const &, Context const &)
        {
            vector0<> vars;
            return vars;
        }
    #define M2(Z, N, D)                                                         \
        eval(locals. QSBOOST_PP_CAT(a, N), ctx)                                   \
    /**/
        
    #define M0(Z, N, D)                                                         \
        template <QSBOOST_PHOENIX_typename_A(N), typename Context>                \
        QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM(N, M1, _)>                        \
        initialize_locals(                                                      \
            QSBOOST_PP_CAT(vector, N)<QSBOOST_PHOENIX_A(N)> const & locals          \
          , Context const & ctx                                                 \
        )                                                                       \
        {                                                                       \
            QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM(N, M1, _)> vars               \
                = {QSBOOST_PP_ENUM(N, M2, _)};                                    \
            return vars;                                                        \
        }                                                                       \
    /**/
        QSBOOST_PP_REPEAT_FROM_TO(1, QSBOOST_PHOENIX_LIMIT, M0, _)
        #undef M0
        #undef M1
        #undef M2

        template <int N>
        struct unused;

        template <
            QSBOOST_PP_ENUM(
                QSBOOST_PHOENIX_LOCAL_LIMIT
              , QSBOOST_PHOENIX_MAP_LOCAL_TEMPLATE_PARAM
              , _
            )
        >
        struct map_local_index_to_tuple
        {
            typedef char(&not_found)[1];
            static not_found get(...);

            QSBOOST_PP_REPEAT(QSBOOST_PHOENIX_LOCAL_LIMIT, QSBOOST_PHOENIX_MAP_LOCAL_DISPATCH, _)
        };
        
        template<typename T>
        T* generate_pointer();

        template <typename Map, typename Tag>
        struct get_index
        {
            QSBOOST_STATIC_CONSTANT(int,
                value = (
                    static_cast<int>((sizeof(Map::get(generate_pointer<Tag>()))) / sizeof(char)) - 2
                ));

            // if value == -1, Tag is not found
            typedef mpl::int_<value> type;
        };

        
        template <typename Local, typename Env>
        struct apply_local;

        template <typename Local, typename Env>
        struct outer_local
        {
            typedef typename
                apply_local<Local, typename Env::outer_env_type>::type
            type;
        };

        template <typename Locals, int Index>
        struct get_local_or_void
        {
            typedef typename
                mpl::eval_if_c<
                    Index < Locals::size_value
                  , fusion::result_of::at_c<Locals, Index>
                  , mpl::identity<fusion::void_>
                >::type
                type;
        };

        template <typename Local, typename Env, int Index>
        struct get_local_from_index
        {
            typedef typename
                mpl::eval_if_c<
                    Index == -1
                  , outer_local<Local, Env>
                  , get_local_or_void<typename Env::locals_type, Index>
                >::type
                type;
        };

        template <typename Local, typename Env>
        struct get_local
        {
            static const int index_value = get_index<typename Env::map_type, Local>::value;

            typedef typename
                get_local_from_index<Local, Env, index_value>::type
            type;
        };

        template <typename Local, typename Env>
        struct apply_local
        {
            // $$$ TODO: static assert that Env is a scoped_environment $$$
            typedef typename get_local<Local, Env>::type type;
        };

        template <typename Key>
        struct eval_local
        {
            template <typename RT, int Index, typename Env>
            static RT
            get(Env const& env, mpl::false_)
            {
                return RT(fusion::at_c<Index>(env.locals));
            }

            template <typename RT, int Index, typename Env>
            static RT
            get(Env const& env, mpl::true_)
            {
                static const int index_value = get_index<typename Env::outer_env_type::map_type, detail::local<Key> >::value;

                return get<RT, index_value>(
                    env.outer_env
                  , mpl::bool_<index_value == -1>());
            }

            template <typename RT, int Index, typename Env>
            static RT
            get(Env const& env)
            {
                return get<RT, Index>(
                    env
                  , mpl::bool_<Index == -1>());
            }
        };
    }
}}

#undef QSBOOST_PHOENIX_MAP_LOCAL_TEMPLATE_PARAM
#undef QSBOOST_PHOENIX_MAP_LOCAL_DISPATCH

#endif

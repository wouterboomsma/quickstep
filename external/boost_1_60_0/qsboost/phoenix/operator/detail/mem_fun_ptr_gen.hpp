
#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_OPERATOR_MEMBER_DETAIL_MEM_FUN_PTR_GEN_HPP
#define QSBOOST_PHOENIX_OPERATOR_MEMBER_DETAIL_MEM_FUN_PTR_GEN_HPP

#include <qsboost/phoenix/core/limits.hpp>
#include <qsboost/phoenix/support/iterate.hpp>
#include <qsboost/phoenix/core/expression.hpp>

#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)

#include <qsboost/phoenix/operator/detail/preprocessed/mem_fun_ptr_gen.hpp>

#else

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/mem_fun_ptr_gen_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

QSBOOST_PHOENIX_DEFINE_EXPRESSION_VARARG(
    (qsboost)(phoenix)(mem_fun_ptr)
  , (meta_grammar)
    (meta_grammar)
  , QSBOOST_PHOENIX_LIMIT
)

namespace qsboost { namespace phoenix
{
    namespace detail {
        template <typename Object, typename MemPtr>
        struct mem_fun_ptr_gen
        {
            mem_fun_ptr_gen(Object const& obj_, MemPtr ptr_)
              : obj(obj_)
              , ptr(ptr_)
            {}

            typename phoenix::expression::mem_fun_ptr<Object, MemPtr>::type const
            operator()() const
            {
                return phoenix::expression::mem_fun_ptr<Object, MemPtr>::make(obj, ptr);
            }

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                          \
        (3, (1, QSBOOST_PHOENIX_MEMBER_LIMIT,                                     \
        <qsboost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>))                   \

#include QSBOOST_PHOENIX_ITERATE()

            Object const& obj;
            MemPtr ptr;

        };

        struct make_mem_fun_ptr_gen
            : proto::callable
        {
            template<typename Sig>
            struct result;

            template<typename This, typename Object, typename MemPtr>
            struct result<This(Object, MemPtr)>
            {
                typedef
                    mem_fun_ptr_gen<
                        typename remove_const<typename remove_reference<Object>::type>::type
                      , typename remove_const<typename remove_reference<MemPtr>::type>::type
                    >
                type;
            };

            template<typename Object, typename MemPtr>
            mem_fun_ptr_gen<Object, MemPtr> operator()(Object const & obj, MemPtr ptr) const
            {
                return mem_fun_ptr_gen<Object, MemPtr>(obj, ptr);
            }
        };
    }
}}

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES

#endif

#else
            template <QSBOOST_PHOENIX_typename_A>
            typename phoenix::expression::mem_fun_ptr<
                Object
              , MemPtr
              , QSBOOST_PHOENIX_A
            >::type const
            operator()(QSBOOST_PHOENIX_A_const_ref_a) const
            {
                return phoenix::expression::mem_fun_ptr<
                    Object
                  , MemPtr
                  , QSBOOST_PHOENIX_A
                >::make(obj, ptr, QSBOOST_PHOENIX_a);
            }
#endif

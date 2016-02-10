/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2009-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_FUSION_ADAPTED_STRUCT_ADAPT_STRUCT_HPP
#define QSBOOST_FUSION_ADAPTED_STRUCT_ADAPT_STRUCT_HPP

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/preprocessor/config/config.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/empty.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/comparison/less.hpp>
#include <qsboost/preprocessor/comparison/equal.hpp>
#include <qsboost/preprocessor/seq/seq.hpp>
#include <qsboost/preprocessor/variadic/to_seq.hpp>
#include <qsboost/type_traits/add_reference.hpp>
#include <qsboost/type_traits/is_const.hpp>
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/remove_const.hpp>

#include <qsboost/fusion/adapted/struct/detail/extension.hpp>
#include <qsboost/fusion/adapted/struct/detail/adapt_base.hpp>
#include <qsboost/fusion/adapted/struct/detail/adapt_base_attr_filler.hpp>
#include <qsboost/fusion/adapted/struct/detail/at_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/is_view_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/is_sequence_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/value_at_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/category_of_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/size_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/begin_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/end_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/value_of_impl.hpp>
#include <qsboost/fusion/adapted/struct/detail/deref_impl.hpp>

#define QSBOOST_FUSION_ADAPT_STRUCT_C(                                            \
    TEMPLATE_PARAMS_SEQ, NAME_SEQ, IS_VIEW, I, ATTRIBUTE)                       \
        QSBOOST_FUSION_ADAPT_STRUCT_C_BASE(                                       \
            TEMPLATE_PARAMS_SEQ,                                                \
            NAME_SEQ,                                                           \
            IS_VIEW,                                                            \
            I,                                                                  \
            QSBOOST_PP_IF(IS_VIEW, QSBOOST_FUSION_PROXY_PREFIX, QSBOOST_PP_EMPTY),    \
            QSBOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR(ATTRIBUTE),                   \
            QSBOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE),              \
            QSBOOST_PP_IF(                                                        \
                QSBOOST_PP_LESS(                                                  \
                    QSBOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE), 2)   \
                , 1, 0))



#if QSBOOST_PP_VARIADICS

#   define QSBOOST_FUSION_ADAPT_TPL_STRUCT(TEMPLATE_PARAMS_SEQ,NAME_SEQ, ...)     \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (1)TEMPLATE_PARAMS_SEQ,                                             \
            (1)NAME_SEQ,                                                        \
            struct_tag,                                                         \
            0,                                                                  \
            QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER(                        \
                QSBOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)),                         \
            QSBOOST_FUSION_ADAPT_STRUCT_C)

#   define QSBOOST_FUSION_ADAPT_STRUCT(...)                                       \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (0),                                                                \
            (0)(QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))),      \
            struct_tag,                                                         \
            0,                                                                  \
            QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER(                        \
              QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))),        \
            QSBOOST_FUSION_ADAPT_STRUCT_C)

#   define QSBOOST_FUSION_ADAPT_STRUCT_AS_VIEW(...)                               \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (0),                                                                \
            (0)(QSBOOST_PP_SEQ_HEAD(QSBOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))),      \
            struct_tag,                                                         \
            1,                                                                  \
            QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER(                        \
              QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))),        \
            QSBOOST_FUSION_ADAPT_STRUCT_C)
        
#else // BOOST_PP_VARIADICS

#   define QSBOOST_FUSION_ADAPT_TPL_STRUCT(                                       \
        TEMPLATE_PARAMS_SEQ,NAME_SEQ, ATTRIBUTES)                               \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (1)TEMPLATE_PARAMS_SEQ,                                             \
            (1)NAME_SEQ,                                                        \
            struct_tag,                                                         \
            0,                                                                  \
            QSBOOST_PP_CAT(                                                       \
                QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,_END),        \
            QSBOOST_FUSION_ADAPT_STRUCT_C)

#   define QSBOOST_FUSION_ADAPT_STRUCT(NAME, ATTRIBUTES)                          \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (0),                                                                \
            (0)(NAME),                                                          \
            struct_tag,                                                         \
            0,                                                                  \
            QSBOOST_PP_CAT(                                                       \
                QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,              \
                _END),                                                          \
            QSBOOST_FUSION_ADAPT_STRUCT_C)

#   define QSBOOST_FUSION_ADAPT_STRUCT_AS_VIEW(NAME, ATTRIBUTES)                  \
        QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
            (0),                                                                \
            (0)(NAME),                                                          \
            struct_tag,                                                         \
            1,                                                                  \
            QSBOOST_PP_CAT(                                                       \
                QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0(0,0)ATTRIBUTES,              \
                _END),                                                          \
            QSBOOST_FUSION_ADAPT_STRUCT_C)


#endif // BOOST_PP_VARIADICS

#endif

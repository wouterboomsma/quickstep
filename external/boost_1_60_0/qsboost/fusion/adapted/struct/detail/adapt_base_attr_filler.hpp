/*=============================================================================
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP
#define QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_ATTR_FILLER_HPP

#include <qsboost/config.hpp>
#include <qsboost/fusion/adapted/struct/detail/preprocessor/is_seq.hpp>

#include <qsboost/preprocessor/empty.hpp>
#include <qsboost/preprocessor/tuple/size.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/preprocessor/facilities/is_empty.hpp>
#include <qsboost/preprocessor/variadic/to_seq.hpp>
#include <qsboost/preprocessor/seq/for_each.hpp>
#include <qsboost/preprocessor/seq/push_front.hpp>


#define QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0(X, Y)                                \
    QSBOOST_FUSION_ADAPT_STRUCT_WRAP_ATTR(X,Y)                                    \
    QSBOOST_FUSION_ADAPT_STRUCT_FILLER_1

#define QSBOOST_FUSION_ADAPT_STRUCT_FILLER_1(X, Y)                                \
    QSBOOST_FUSION_ADAPT_STRUCT_WRAP_ATTR(X,Y)                                    \
    QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0

#define QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0_END
#define QSBOOST_FUSION_ADAPT_STRUCT_FILLER_1_END

#define QSBOOST_FUSION_ADAPT_STRUCT_WRAP_ATTR(X, Y)                               \
    QSBOOST_PP_IF(QSBOOST_PP_IS_EMPTY(X),                                           \
      ((1, (Y))),                                                               \
      ((2, (X,Y)))                                                              \
    )

#define QSBOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR_SIZE(ATTRIBUTE)                   \
  QSBOOST_PP_TUPLE_ELEM(2, 0, ATTRIBUTE)

#define QSBOOST_FUSION_ADAPT_STRUCT_WRAPPEDATTR(ATTRIBUTE)                        \
  QSBOOST_PP_TUPLE_ELEM(2, 1, ATTRIBUTE)


#if QSBOOST_PP_VARIADICS

#   define QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER_OP(r, unused, elem)      \
        QSBOOST_PP_IF(QSBOOST_FUSION_PP_IS_SEQ(elem),                               \
            QSBOOST_PP_CAT( QSBOOST_FUSION_ADAPT_STRUCT_FILLER_0 elem ,_END),       \
            QSBOOST_PP_IF(QSBOOST_PP_IS_EMPTY(elem),                                \
              QSBOOST_PP_EMPTY(),                                                 \
              QSBOOST_FUSION_ADAPT_STRUCT_WRAP_ATTR(QSBOOST_FUSION_ADAPT_AUTO,elem))\
            )

#   define QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER(VA_ARGS_SEQ)             \
        QSBOOST_PP_SEQ_PUSH_FRONT(                                                \
            QSBOOST_PP_SEQ_FOR_EACH(                                              \
                QSBOOST_FUSION_ADAPT_STRUCT_ATTRIBUTES_FILLER_OP,                 \
                unused, VA_ARGS_SEQ),                                           \
            (0,0))

#endif // BOOST_PP_VARIADICS

#endif

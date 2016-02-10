# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
#ifndef QSBOOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP
#define QSBOOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP

#if QSBOOST_PP_VARIADICS_MSVC

#include <qsboost/preprocessor/facilities/empty.hpp>

#define QSBOOST_PP_DETAIL_VD_IBP_CAT(a, b) QSBOOST_PP_DETAIL_VD_IBP_CAT_I(a, b)
#define QSBOOST_PP_DETAIL_VD_IBP_CAT_I(a, b) QSBOOST_PP_DETAIL_VD_IBP_CAT_II(a ## b)
#define QSBOOST_PP_DETAIL_VD_IBP_CAT_II(res) res

#define QSBOOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    QSBOOST_PP_DETAIL_VD_IBP_CAT(QSBOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(QSBOOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__),QSBOOST_PP_EMPTY()) \
/**/

#define QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1 1

#else

#define QSBOOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    QSBOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(QSBOOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__) \
/**/

#define QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1

#endif /* BOOST_PP_VARIADICS_MSVC */

#define QSBOOST_PP_DETAIL_IBP_SPLIT_0(a, ...) a
#define QSBOOST_PP_DETAIL_IBP_SPLIT_1(a, ...) __VA_ARGS__

#define QSBOOST_PP_DETAIL_IBP_CAT(a, ...) QSBOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a,__VA_ARGS__)
#define QSBOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_R_1 1,
#define QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_R_QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_C 0,

#endif /* BOOST_PREPROCESSOR_DETAIL_IS_BEGIN_PARENS_HPP */

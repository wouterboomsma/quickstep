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
# ifndef QSBOOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP
# define QSBOOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP

# include <qsboost/preprocessor/config/config.hpp>

#if QSBOOST_PP_VARIADICS

#include <qsboost/preprocessor/punctuation/detail/is_begin_parens.hpp>

#if QSBOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define QSBOOST_PP_IS_BEGIN_PARENS(param) \
    QSBOOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      QSBOOST_PP_DETAIL_IBP_CAT \
        ( \
        QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_C param \
        ) \
      ) \
/**/

#else

#define QSBOOST_PP_IS_BEGIN_PARENS(...) \
    QSBOOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      QSBOOST_PP_DETAIL_IBP_CAT \
        ( \
        QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        QSBOOST_PP_DETAIL_IBP_IS_VARIADIC_C __VA_ARGS__ \
        ) \
      ) \
/**/

#endif /* BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_PREPROCESSOR_IS_BEGIN_PARENS_HPP */

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
# ifndef QSBOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
# define QSBOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# if QSBOOST_PP_VARIADICS
#
# include <qsboost/preprocessor/punctuation/is_begin_parens.hpp>
# include <qsboost/preprocessor/facilities/detail/is_empty.hpp>
#
#if QSBOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400
#
#define QSBOOST_PP_IS_EMPTY(param) \
    QSBOOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      QSBOOST_PP_IS_BEGIN_PARENS \
        ( \
        param \
        ) \
      ) \
      ( \
      QSBOOST_PP_IS_EMPTY_ZERO, \
      QSBOOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (param) \
/**/
#define QSBOOST_PP_IS_EMPTY_ZERO(param) 0
# else
#define QSBOOST_PP_IS_EMPTY(...) \
    QSBOOST_PP_DETAIL_IS_EMPTY_IIF \
      ( \
      QSBOOST_PP_IS_BEGIN_PARENS \
        ( \
        __VA_ARGS__ \
        ) \
      ) \
      ( \
      QSBOOST_PP_IS_EMPTY_ZERO, \
      QSBOOST_PP_DETAIL_IS_EMPTY_PROCESS \
      ) \
    (__VA_ARGS__) \
/**/
#define QSBOOST_PP_IS_EMPTY_ZERO(...) 0
# endif /* BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
# endif /* BOOST_PP_VARIADICS */
# endif /* BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_VARIADIC_HPP */

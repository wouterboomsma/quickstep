# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_DETAIL_IS_BINARY_HPP
# define QSBOOST_PREPROCESSOR_DETAIL_IS_BINARY_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/detail/check.hpp>
#
# /* BOOST_PP_IS_BINARY */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_IS_BINARY(x) QSBOOST_PP_CHECK(x, QSBOOST_PP_IS_BINARY_CHECK)
# else
#    define QSBOOST_PP_IS_BINARY(x) QSBOOST_PP_IS_BINARY_I(x)
#    define QSBOOST_PP_IS_BINARY_I(x) QSBOOST_PP_CHECK(x, QSBOOST_PP_IS_BINARY_CHECK)
# endif
#
# define QSBOOST_PP_IS_BINARY_CHECK(a, b) 1
# define QSBOOST_PP_CHECK_RESULT_QSBOOST_PP_IS_BINARY_CHECK 0, QSBOOST_PP_NIL
#
# endif

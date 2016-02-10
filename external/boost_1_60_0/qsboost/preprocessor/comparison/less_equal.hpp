# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
# define QSBOOST_PREPROCESSOR_COMPARISON_LESS_EQUAL_HPP
#
# include <qsboost/preprocessor/arithmetic/sub.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/logical/not.hpp>
#
# /* BOOST_PP_LESS_EQUAL */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LESS_EQUAL(x, y) QSBOOST_PP_NOT(QSBOOST_PP_SUB(x, y))
# else
#    define QSBOOST_PP_LESS_EQUAL(x, y) QSBOOST_PP_LESS_EQUAL_I(x, y)
#    define QSBOOST_PP_LESS_EQUAL_I(x, y) QSBOOST_PP_NOT(QSBOOST_PP_SUB(x, y))
# endif
#
# /* BOOST_PP_LESS_EQUAL_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LESS_EQUAL_D(d, x, y) QSBOOST_PP_NOT(QSBOOST_PP_SUB_D(d, x, y))
# else
#    define QSBOOST_PP_LESS_EQUAL_D(d, x, y) QSBOOST_PP_LESS_EQUAL_D_I(d, x, y)
#    define QSBOOST_PP_LESS_EQUAL_D_I(d, x, y) QSBOOST_PP_NOT(QSBOOST_PP_SUB_D(d, x, y))
# endif
#
# endif

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
# ifndef QSBOOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
# define QSBOOST_PREPROCESSOR_COMPARISON_EQUAL_HPP
#
# include <qsboost/preprocessor/comparison/not_equal.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/logical/compl.hpp>
#
# /* BOOST_PP_EQUAL */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_EQUAL(x, y) QSBOOST_PP_COMPL(QSBOOST_PP_NOT_EQUAL(x, y))
# else
#    define QSBOOST_PP_EQUAL(x, y) QSBOOST_PP_EQUAL_I(x, y)
#    define QSBOOST_PP_EQUAL_I(x, y) QSBOOST_PP_COMPL(QSBOOST_PP_NOT_EQUAL(x, y))
# endif
#
# /* BOOST_PP_EQUAL_D */
#
# define QSBOOST_PP_EQUAL_D(d, x, y) QSBOOST_PP_EQUAL(x, y)
#
# endif

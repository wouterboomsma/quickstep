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
# ifndef QSBOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
# define QSBOOST_PREPROCESSOR_ARITHMETIC_DETAIL_DIV_BASE_HPP
#
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/arithmetic/sub.hpp>
# include <qsboost/preprocessor/comparison/less_equal.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/while.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_DIV_BASE */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_DIV_BASE(x, y) QSBOOST_PP_WHILE(QSBOOST_PP_DIV_BASE_P, QSBOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define QSBOOST_PP_DIV_BASE(x, y) QSBOOST_PP_DIV_BASE_I(x, y)
#    define QSBOOST_PP_DIV_BASE_I(x, y) QSBOOST_PP_WHILE(QSBOOST_PP_DIV_BASE_P, QSBOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_DIV_BASE_P(d, rxy) QSBOOST_PP_DIV_BASE_P_IM(d, QSBOOST_PP_TUPLE_REM_3 rxy)
#    define QSBOOST_PP_DIV_BASE_P_IM(d, im) QSBOOST_PP_DIV_BASE_P_I(d, im)
# else
#    define QSBOOST_PP_DIV_BASE_P(d, rxy) QSBOOST_PP_DIV_BASE_P_I(d, QSBOOST_PP_TUPLE_ELEM(3, 0, rxy), QSBOOST_PP_TUPLE_ELEM(3, 1, rxy), QSBOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define QSBOOST_PP_DIV_BASE_P_I(d, r, x, y) QSBOOST_PP_LESS_EQUAL_D(d, y, x)
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_DIV_BASE_O(d, rxy) QSBOOST_PP_DIV_BASE_O_IM(d, QSBOOST_PP_TUPLE_REM_3 rxy)
#    define QSBOOST_PP_DIV_BASE_O_IM(d, im) QSBOOST_PP_DIV_BASE_O_I(d, im)
# else
#    define QSBOOST_PP_DIV_BASE_O(d, rxy) QSBOOST_PP_DIV_BASE_O_I(d, QSBOOST_PP_TUPLE_ELEM(3, 0, rxy), QSBOOST_PP_TUPLE_ELEM(3, 1, rxy), QSBOOST_PP_TUPLE_ELEM(3, 2, rxy))
# endif
#
# define QSBOOST_PP_DIV_BASE_O_I(d, r, x, y) (QSBOOST_PP_INC(r), QSBOOST_PP_SUB_D(d, x, y), y)
#
# /* BOOST_PP_DIV_BASE_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_DIV_BASE_D(d, x, y) QSBOOST_PP_WHILE_ ## d(QSBOOST_PP_DIV_BASE_P, QSBOOST_PP_DIV_BASE_O, (0, x, y))
# else
#    define QSBOOST_PP_DIV_BASE_D(d, x, y) QSBOOST_PP_DIV_BASE_D_I(d, x, y)
#    define QSBOOST_PP_DIV_BASE_D_I(d, x, y) QSBOOST_PP_WHILE_ ## d(QSBOOST_PP_DIV_BASE_P, QSBOOST_PP_DIV_BASE_O, (0, x, y))
# endif
#
# endif

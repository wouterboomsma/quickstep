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
# ifndef QSBOOST_PREPROCESSOR_COMPARISON_LESS_HPP
# define QSBOOST_PREPROCESSOR_COMPARISON_LESS_HPP
#
# include <qsboost/preprocessor/comparison/less_equal.hpp>
# include <qsboost/preprocessor/comparison/not_equal.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/iif.hpp>
# include <qsboost/preprocessor/logical/bitand.hpp>
# include <qsboost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_LESS */
#
# if QSBOOST_PP_CONFIG_FLAGS() & (QSBOOST_PP_CONFIG_MWCC() | QSBOOST_PP_CONFIG_DMC())
#    define QSBOOST_PP_LESS(x, y) QSBOOST_PP_BITAND(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL(x, y))
# elif ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LESS(x, y) QSBOOST_PP_IIF(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL, 0 QSBOOST_PP_TUPLE_EAT_2)(x, y)
# else
#    define QSBOOST_PP_LESS(x, y) QSBOOST_PP_LESS_I(x, y)
#    define QSBOOST_PP_LESS_I(x, y) QSBOOST_PP_IIF(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL, 0 QSBOOST_PP_TUPLE_EAT_2)(x, y)
# endif
#
# /* BOOST_PP_LESS_D */
#
# if QSBOOST_PP_CONFIG_FLAGS() & (QSBOOST_PP_CONFIG_MWCC() | QSBOOST_PP_CONFIG_DMC())
#    define QSBOOST_PP_LESS_D(d, x, y) QSBOOST_PP_BITAND(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL_D(d, x, y))
# elif ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LESS_D(d, x, y) QSBOOST_PP_IIF(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL_D, 0 QSBOOST_PP_TUPLE_EAT_3)(d, x, y)
# else
#    define QSBOOST_PP_LESS_D(d, x, y) QSBOOST_PP_LESS_D_I(d, x, y)
#    define QSBOOST_PP_LESS_D_I(d, x, y) QSBOOST_PP_IIF(QSBOOST_PP_NOT_EQUAL(x, y), QSBOOST_PP_LESS_EQUAL_D, 0 QSBOOST_PP_TUPLE_EAT_3)(d, x, y)
# endif
#
# endif

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
# ifndef QSBOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
# define QSBOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
#
# include <qsboost/preprocessor/arithmetic/detail/div_base.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_MOD */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_MOD(x, y) QSBOOST_PP_TUPLE_ELEM(3, 1, QSBOOST_PP_DIV_BASE(x, y))
# else
#    define QSBOOST_PP_MOD(x, y) QSBOOST_PP_MOD_I(x, y)
#    define QSBOOST_PP_MOD_I(x, y) QSBOOST_PP_TUPLE_ELEM(3, 1, QSBOOST_PP_DIV_BASE(x, y))
# endif
#
# /* BOOST_PP_MOD_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_MOD_D(d, x, y) QSBOOST_PP_TUPLE_ELEM(3, 1, QSBOOST_PP_DIV_BASE_D(d, x, y))
# else
#    define QSBOOST_PP_MOD_D(d, x, y) QSBOOST_PP_MOD_D_I(d, x, y)
#    define QSBOOST_PP_MOD_D_I(d, x, y) QSBOOST_PP_TUPLE_ELEM(3, 1, QSBOOST_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif

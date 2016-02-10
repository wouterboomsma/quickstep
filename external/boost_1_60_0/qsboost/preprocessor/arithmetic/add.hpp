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
# ifndef QSBOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP
# define QSBOOST_PREPROCESSOR_ARITHMETIC_ADD_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/while.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ADD */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ADD(x, y) QSBOOST_PP_TUPLE_ELEM(2, 0, QSBOOST_PP_WHILE(QSBOOST_PP_ADD_P, QSBOOST_PP_ADD_O, (x, y)))
# else
#    define QSBOOST_PP_ADD(x, y) QSBOOST_PP_ADD_I(x, y)
#    define QSBOOST_PP_ADD_I(x, y) QSBOOST_PP_TUPLE_ELEM(2, 0, QSBOOST_PP_WHILE(QSBOOST_PP_ADD_P, QSBOOST_PP_ADD_O, (x, y)))
# endif
#
# define QSBOOST_PP_ADD_P(d, xy) QSBOOST_PP_TUPLE_ELEM(2, 1, xy)
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_ADD_O(d, xy) QSBOOST_PP_ADD_O_I xy
# else
#    define QSBOOST_PP_ADD_O(d, xy) QSBOOST_PP_ADD_O_I(QSBOOST_PP_TUPLE_ELEM(2, 0, xy), QSBOOST_PP_TUPLE_ELEM(2, 1, xy))
# endif
#
# define QSBOOST_PP_ADD_O_I(x, y) (QSBOOST_PP_INC(x), QSBOOST_PP_DEC(y))
#
# /* BOOST_PP_ADD_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ADD_D(d, x, y) QSBOOST_PP_TUPLE_ELEM(2, 0, QSBOOST_PP_WHILE_ ## d(QSBOOST_PP_ADD_P, QSBOOST_PP_ADD_O, (x, y)))
# else
#    define QSBOOST_PP_ADD_D(d, x, y) QSBOOST_PP_ADD_D_I(d, x, y)
#    define QSBOOST_PP_ADD_D_I(d, x, y) QSBOOST_PP_TUPLE_ELEM(2, 0, QSBOOST_PP_WHILE_ ## d(QSBOOST_PP_ADD_P, QSBOOST_PP_ADD_O, (x, y)))
# endif
#
# endif

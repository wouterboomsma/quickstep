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
# ifndef QSBOOST_PREPROCESSOR_LIST_REVERSE_HPP
# define QSBOOST_PREPROCESSOR_LIST_REVERSE_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/list/fold_left.hpp>
#
# /* BOOST_PP_LIST_REVERSE */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LIST_REVERSE(list) QSBOOST_PP_LIST_FOLD_LEFT(QSBOOST_PP_LIST_REVERSE_O, QSBOOST_PP_NIL, list)
# else
#    define QSBOOST_PP_LIST_REVERSE(list) QSBOOST_PP_LIST_REVERSE_I(list)
#    define QSBOOST_PP_LIST_REVERSE_I(list) QSBOOST_PP_LIST_FOLD_LEFT(QSBOOST_PP_LIST_REVERSE_O, QSBOOST_PP_NIL, list)
# endif
#
# define QSBOOST_PP_LIST_REVERSE_O(d, s, x) (x, s)
#
# /* BOOST_PP_LIST_REVERSE_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LIST_REVERSE_D(d, list) QSBOOST_PP_LIST_FOLD_LEFT_ ## d(QSBOOST_PP_LIST_REVERSE_O, QSBOOST_PP_NIL, list)
# else
#    define QSBOOST_PP_LIST_REVERSE_D(d, list) QSBOOST_PP_LIST_REVERSE_D_I(d, list)
#    define QSBOOST_PP_LIST_REVERSE_D_I(d, list) QSBOOST_PP_LIST_FOLD_LEFT_ ## d(QSBOOST_PP_LIST_REVERSE_O, QSBOOST_PP_NIL, list)
# endif
#
# endif

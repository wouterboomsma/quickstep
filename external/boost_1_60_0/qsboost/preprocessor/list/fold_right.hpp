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
# ifndef QSBOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
# define QSBOOST_PREPROCESSOR_LIST_FOLD_RIGHT_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/control/while.hpp>
# include <qsboost/preprocessor/debug/error.hpp>
# include <qsboost/preprocessor/detail/auto_rec.hpp>
#
# if 0
#    define QSBOOST_PP_LIST_FOLD_RIGHT(op, state, list)
# endif
#
# define QSBOOST_PP_LIST_FOLD_RIGHT QSBOOST_PP_CAT(QSBOOST_PP_LIST_FOLD_RIGHT_, QSBOOST_PP_AUTO_REC(QSBOOST_PP_WHILE_P, 256))
#
# define QSBOOST_PP_LIST_FOLD_RIGHT_257(o, s, l) QSBOOST_PP_ERROR(0x0004)
#
# define QSBOOST_PP_LIST_FOLD_RIGHT_D(d, o, s, l) QSBOOST_PP_LIST_FOLD_RIGHT_ ## d(o, s, l)
# define QSBOOST_PP_LIST_FOLD_RIGHT_2ND QSBOOST_PP_LIST_FOLD_RIGHT
# define QSBOOST_PP_LIST_FOLD_RIGHT_2ND_D QSBOOST_PP_LIST_FOLD_RIGHT_D
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    include <qsboost/preprocessor/list/detail/edg/fold_right.hpp>
# else
#    include <qsboost/preprocessor/list/detail/fold_right.hpp>
# endif
#
# endif

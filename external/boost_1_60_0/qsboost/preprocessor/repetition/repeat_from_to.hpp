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
# ifndef QSBOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
# define QSBOOST_PREPROCESSOR_REPETITION_REPEAT_FROM_TO_HPP
#
# include <qsboost/preprocessor/arithmetic/add.hpp>
# include <qsboost/preprocessor/arithmetic/sub.hpp>
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/while.hpp>
# include <qsboost/preprocessor/debug/error.hpp>
# include <qsboost/preprocessor/detail/auto_rec.hpp>
# include <qsboost/preprocessor/repetition/repeat.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_REPEAT_FROM_TO */
#
# if 0
#    define QSBOOST_PP_REPEAT_FROM_TO(first, last, macro, data)
# endif
#
# define QSBOOST_PP_REPEAT_FROM_TO QSBOOST_PP_CAT(QSBOOST_PP_REPEAT_FROM_TO_, QSBOOST_PP_AUTO_REC(QSBOOST_PP_REPEAT_P, 4))
#
# define QSBOOST_PP_REPEAT_FROM_TO_1(f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_1(QSBOOST_PP_AUTO_REC(QSBOOST_PP_WHILE_P, 256), f, l, m, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_2(f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_2(QSBOOST_PP_AUTO_REC(QSBOOST_PP_WHILE_P, 256), f, l, m, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_3(f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_3(QSBOOST_PP_AUTO_REC(QSBOOST_PP_WHILE_P, 256), f, l, m, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_4(f, l, m, dt) QSBOOST_PP_ERROR(0x0003)
#
# define QSBOOST_PP_REPEAT_FROM_TO_1ST QSBOOST_PP_REPEAT_FROM_TO_1
# define QSBOOST_PP_REPEAT_FROM_TO_2ND QSBOOST_PP_REPEAT_FROM_TO_2
# define QSBOOST_PP_REPEAT_FROM_TO_3RD QSBOOST_PP_REPEAT_FROM_TO_3
#
# /* BOOST_PP_REPEAT_FROM_TO_D */
#
# if 0
#    define QSBOOST_PP_REPEAT_FROM_TO_D(d, first, last, macro, data)
# endif
#
# define QSBOOST_PP_REPEAT_FROM_TO_D QSBOOST_PP_CAT(QSBOOST_PP_REPEAT_FROM_TO_D_, QSBOOST_PP_AUTO_REC(QSBOOST_PP_REPEAT_P, 4))
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) QSBOOST_PP_REPEAT_1(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define QSBOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) QSBOOST_PP_REPEAT_2(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define QSBOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) QSBOOST_PP_REPEAT_3(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# else
#    define QSBOOST_PP_REPEAT_FROM_TO_D_1(d, f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt)
#    define QSBOOST_PP_REPEAT_FROM_TO_D_2(d, f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt)
#    define QSBOOST_PP_REPEAT_FROM_TO_D_3(d, f, l, m, dt) QSBOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt)
#    define QSBOOST_PP_REPEAT_FROM_TO_D_1_I(d, f, l, m, dt) QSBOOST_PP_REPEAT_1(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_1, (d, f, m, dt))
#    define QSBOOST_PP_REPEAT_FROM_TO_D_2_I(d, f, l, m, dt) QSBOOST_PP_REPEAT_2(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_2, (d, f, m, dt))
#    define QSBOOST_PP_REPEAT_FROM_TO_D_3_I(d, f, l, m, dt) QSBOOST_PP_REPEAT_3(QSBOOST_PP_SUB_D(d, l, f), QSBOOST_PP_REPEAT_FROM_TO_M_3, (d, f, m, dt))
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, QSBOOST_PP_TUPLE_REM_4 dfmd)
#    define QSBOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, QSBOOST_PP_TUPLE_REM_4 dfmd)
#    define QSBOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, QSBOOST_PP_TUPLE_REM_4 dfmd)
#    define QSBOOST_PP_REPEAT_FROM_TO_M_1_IM(z, n, im) QSBOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, im)
#    define QSBOOST_PP_REPEAT_FROM_TO_M_2_IM(z, n, im) QSBOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, im)
#    define QSBOOST_PP_REPEAT_FROM_TO_M_3_IM(z, n, im) QSBOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, im)
# else
#    define QSBOOST_PP_REPEAT_FROM_TO_M_1(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, QSBOOST_PP_TUPLE_ELEM(4, 0, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 1, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 2, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define QSBOOST_PP_REPEAT_FROM_TO_M_2(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, QSBOOST_PP_TUPLE_ELEM(4, 0, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 1, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 2, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 3, dfmd))
#    define QSBOOST_PP_REPEAT_FROM_TO_M_3(z, n, dfmd) QSBOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, QSBOOST_PP_TUPLE_ELEM(4, 0, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 1, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 2, dfmd), QSBOOST_PP_TUPLE_ELEM(4, 3, dfmd))
# endif
#
# define QSBOOST_PP_REPEAT_FROM_TO_M_1_I(z, n, d, f, m, dt) QSBOOST_PP_REPEAT_FROM_TO_M_1_II(z, QSBOOST_PP_ADD_D(d, n, f), m, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_M_2_I(z, n, d, f, m, dt) QSBOOST_PP_REPEAT_FROM_TO_M_2_II(z, QSBOOST_PP_ADD_D(d, n, f), m, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_M_3_I(z, n, d, f, m, dt) QSBOOST_PP_REPEAT_FROM_TO_M_3_II(z, QSBOOST_PP_ADD_D(d, n, f), m, dt)
#
# define QSBOOST_PP_REPEAT_FROM_TO_M_1_II(z, n, m, dt) m(z, n, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_M_2_II(z, n, m, dt) m(z, n, dt)
# define QSBOOST_PP_REPEAT_FROM_TO_M_3_II(z, n, m, dt) m(z, n, dt)
#
# endif

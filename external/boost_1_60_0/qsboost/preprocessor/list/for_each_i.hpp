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
# ifndef QSBOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
# define QSBOOST_PREPROCESSOR_LIST_LIST_FOR_EACH_I_HPP
#
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/list/adt.hpp>
# include <qsboost/preprocessor/repetition/for.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_LIST_FOR_EACH_I */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG() && ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_LIST_FOR_EACH_I(macro, data, list) QSBOOST_PP_FOR((macro, data, list, 0), QSBOOST_PP_LIST_FOR_EACH_I_P, QSBOOST_PP_LIST_FOR_EACH_I_O, QSBOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define QSBOOST_PP_LIST_FOR_EACH_I(macro, data, list) QSBOOST_PP_LIST_FOR_EACH_I_I(macro, data, list)
#    define QSBOOST_PP_LIST_FOR_EACH_I_I(macro, data, list) QSBOOST_PP_FOR((macro, data, list, 0), QSBOOST_PP_LIST_FOR_EACH_I_P, QSBOOST_PP_LIST_FOR_EACH_I_O, QSBOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_LIST_FOR_EACH_I_P(r, x) QSBOOST_PP_LIST_FOR_EACH_I_P_D x
#    define QSBOOST_PP_LIST_FOR_EACH_I_P_D(m, d, l, i) QSBOOST_PP_LIST_IS_CONS(l)
# else
#    define QSBOOST_PP_LIST_FOR_EACH_I_P(r, x) QSBOOST_PP_LIST_IS_CONS(QSBOOST_PP_TUPLE_ELEM(4, 2, x))
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_LIST_FOR_EACH_I_O(r, x) QSBOOST_PP_LIST_FOR_EACH_I_O_D x
#    define QSBOOST_PP_LIST_FOR_EACH_I_O_D(m, d, l, i) (m, d, QSBOOST_PP_LIST_REST(l), QSBOOST_PP_INC(i))
# else
#    define QSBOOST_PP_LIST_FOR_EACH_I_O(r, x) (QSBOOST_PP_TUPLE_ELEM(4, 0, x), QSBOOST_PP_TUPLE_ELEM(4, 1, x), QSBOOST_PP_LIST_REST(QSBOOST_PP_TUPLE_ELEM(4, 2, x)), QSBOOST_PP_INC(QSBOOST_PP_TUPLE_ELEM(4, 3, x)))
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LIST_FOR_EACH_I_M(r, x) QSBOOST_PP_LIST_FOR_EACH_I_M_D(r, QSBOOST_PP_TUPLE_ELEM(4, 0, x), QSBOOST_PP_TUPLE_ELEM(4, 1, x), QSBOOST_PP_TUPLE_ELEM(4, 2, x), QSBOOST_PP_TUPLE_ELEM(4, 3, x))
# else
#    define QSBOOST_PP_LIST_FOR_EACH_I_M(r, x) QSBOOST_PP_LIST_FOR_EACH_I_M_I(r, QSBOOST_PP_TUPLE_REM_4 x)
#    define QSBOOST_PP_LIST_FOR_EACH_I_M_I(r, x_e) QSBOOST_PP_LIST_FOR_EACH_I_M_D(r, x_e)
# endif
#
# define QSBOOST_PP_LIST_FOR_EACH_I_M_D(r, m, d, l, i) m(r, d, i, QSBOOST_PP_LIST_FIRST(l))
#
# /* BOOST_PP_LIST_FOR_EACH_I_R */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) QSBOOST_PP_FOR_ ## r((macro, data, list, 0), QSBOOST_PP_LIST_FOR_EACH_I_P, QSBOOST_PP_LIST_FOR_EACH_I_O, QSBOOST_PP_LIST_FOR_EACH_I_M)
# else
#    define QSBOOST_PP_LIST_FOR_EACH_I_R(r, macro, data, list) QSBOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list)
#    define QSBOOST_PP_LIST_FOR_EACH_I_R_I(r, macro, data, list) QSBOOST_PP_FOR_ ## r((macro, data, list, 0), QSBOOST_PP_LIST_FOR_EACH_I_P, QSBOOST_PP_LIST_FOR_EACH_I_O, QSBOOST_PP_LIST_FOR_EACH_I_M)
# endif
#
# endif

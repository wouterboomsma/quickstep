# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_PRODUCT_HPP
# define QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_PRODUCT_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/if.hpp>
# include <qsboost/preprocessor/repetition/for.hpp>
# include <qsboost/preprocessor/seq/seq.hpp>
# include <qsboost/preprocessor/seq/size.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_FOR_EACH_PRODUCT */
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT(macro, sets) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E(QSBOOST_PP_FOR, macro, sets)
#
# /* BOOST_PP_SEQ_FOR_EACH_PRODUCT_R */
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_R(r, macro, sets) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E(QSBOOST_PP_FOR_ ## r, macro, sets)
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E(impl, macro, sets) impl((QSBOOST_PP_SEQ_HEAD(sets)(nil), QSBOOST_PP_SEQ_TAIL(sets)(nil), (nil), macro), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_0)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E(impl, macro, sets) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E_I(impl, macro, sets)
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_E_I(impl, macro, sets) impl((QSBOOST_PP_SEQ_HEAD(sets)(nil), QSBOOST_PP_SEQ_TAIL(sets)(nil), (nil), macro), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_0)
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P_I data
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P_I(cset, rset, res, macro) QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(cset))
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P(r, data) QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(4, 0, data)))
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O_I data
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O_I(cset, rset, res, macro) (QSBOOST_PP_SEQ_TAIL(cset), rset, res, macro)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O(r, data) (QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_TUPLE_ELEM(4, 0, data)), QSBOOST_PP_TUPLE_ELEM(4, 1, data), QSBOOST_PP_TUPLE_ELEM(4, 2, data), QSBOOST_PP_TUPLE_ELEM(4, 3, data))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, i) QSBOOST_PP_IF(QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(QSBOOST_PP_TUPLE_ELEM(4, 1, data))), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_ ## i, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I)
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I_I(r, QSBOOST_PP_TUPLE_ELEM(4, 0, data), QSBOOST_PP_TUPLE_ELEM(4, 1, data), QSBOOST_PP_TUPLE_ELEM(4, 2, data), QSBOOST_PP_TUPLE_ELEM(4, 3, data))
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I_IM(r, QSBOOST_PP_TUPLE_REM_4 data)
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I_IM(r, im) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I_I(r, im)
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_I_I(r, cset, rset, res, macro) macro(r, QSBOOST_PP_SEQ_TAIL(res (QSBOOST_PP_SEQ_HEAD(cset))))
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H_I data
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H_I(QSBOOST_PP_TUPLE_ELEM(4, 0, data), QSBOOST_PP_TUPLE_ELEM(4, 1, data), QSBOOST_PP_TUPLE_ELEM(4, 2, data), QSBOOST_PP_TUPLE_ELEM(4, 3, data))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H_I(cset, rset, res, macro) (QSBOOST_PP_SEQ_HEAD(rset)(nil), QSBOOST_PP_SEQ_TAIL(rset), res (QSBOOST_PP_SEQ_HEAD(cset)), macro)
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_0(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 0)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_1(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 1)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_2(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 2)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_3(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 3)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_4(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 4)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_5(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 5)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_6(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 6)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_7(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 7)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_8(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 8)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_9(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 9)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_10(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 10)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_11(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 11)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_12(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 12)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_13(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 13)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_14(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 14)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_15(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 15)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_16(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 16)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_17(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 17)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_18(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 18)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_19(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 19)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_20(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 20)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_21(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 21)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_22(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 22)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_23(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 23)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_24(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 24)(r, data)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_25(r, data) QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_C(data, 25)(r, data)
#
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_0(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_1)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_1(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_2)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_2(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_3)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_3(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_4)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_4(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_5)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_5(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_6)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_6(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_7)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_7(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_8)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_8(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_9)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_9(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_10)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_10(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_11)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_11(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_12)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_12(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_13)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_13(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_14)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_14(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_15)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_15(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_16)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_16(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_17)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_17(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_18)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_18(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_19)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_19(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_20)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_20(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_21)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_21(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_22)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_22(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_23)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_23(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_24)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_24(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_25)
# define QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_N_25(r, data) QSBOOST_PP_FOR_ ## r(QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_H(data), QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_P, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_O, QSBOOST_PP_SEQ_FOR_EACH_PRODUCT_M_26)
#
# endif

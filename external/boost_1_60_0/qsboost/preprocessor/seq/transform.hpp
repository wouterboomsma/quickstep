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
# ifndef QSBOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
# define QSBOOST_PREPROCESSOR_SEQ_TRANSFORM_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/seq/fold_left.hpp>
# include <qsboost/preprocessor/seq/seq.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_TRANSFORM */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_TRANSFORM(op, data, seq) QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_TUPLE_ELEM(3, 2, QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define QSBOOST_PP_SEQ_TRANSFORM(op, data, seq) QSBOOST_PP_SEQ_TRANSFORM_I(op, data, seq)
#    define QSBOOST_PP_SEQ_TRANSFORM_I(op, data, seq) QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_TUPLE_ELEM(3, 2, QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_TRANSFORM_O(s, state, elem) QSBOOST_PP_SEQ_TRANSFORM_O_IM(s, QSBOOST_PP_TUPLE_REM_3 state, elem)
#    define QSBOOST_PP_SEQ_TRANSFORM_O_IM(s, im, elem) QSBOOST_PP_SEQ_TRANSFORM_O_I(s, im, elem)
# else
#    define QSBOOST_PP_SEQ_TRANSFORM_O(s, state, elem) QSBOOST_PP_SEQ_TRANSFORM_O_I(s, QSBOOST_PP_TUPLE_ELEM(3, 0, state), QSBOOST_PP_TUPLE_ELEM(3, 1, state), QSBOOST_PP_TUPLE_ELEM(3, 2, state), elem)
# endif
#
# define QSBOOST_PP_SEQ_TRANSFORM_O_I(s, op, data, res, elem) (op, data, res (op(s, data, elem)))
#
# /* BOOST_PP_SEQ_TRANSFORM_S */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_TUPLE_ELEM(3, 2, QSBOOST_PP_SEQ_FOLD_LEFT_ ## s(QSBOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# else
#    define QSBOOST_PP_SEQ_TRANSFORM_S(s, op, data, seq) QSBOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq)
#    define QSBOOST_PP_SEQ_TRANSFORM_S_I(s, op, data, seq) QSBOOST_PP_SEQ_TAIL(QSBOOST_PP_TUPLE_ELEM(3, 2, QSBOOST_PP_SEQ_FOLD_LEFT_ ## s(QSBOOST_PP_SEQ_TRANSFORM_O, (op, data, (nil)), seq)))
# endif
#
# endif

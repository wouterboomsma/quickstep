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
# ifndef QSBOOST_PREPROCESSOR_SEQ_REVERSE_HPP
# define QSBOOST_PREPROCESSOR_SEQ_REVERSE_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/facilities/empty.hpp>
# include <qsboost/preprocessor/seq/fold_left.hpp>
#
# /* BOOST_PP_SEQ_REVERSE */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_REVERSE(seq) QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_PP_SEQ_REVERSE_O, QSBOOST_PP_EMPTY, seq)()
# else
#    define QSBOOST_PP_SEQ_REVERSE(seq) QSBOOST_PP_SEQ_REVERSE_I(seq)
#    define QSBOOST_PP_SEQ_REVERSE_I(seq) QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_PP_SEQ_REVERSE_O, QSBOOST_PP_EMPTY, seq)()
# endif
#
# define QSBOOST_PP_SEQ_REVERSE_O(s, state, elem) (elem) state
#
# /* BOOST_PP_SEQ_REVERSE_S */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_REVERSE_S(s, seq) QSBOOST_PP_SEQ_FOLD_LEFT_ ## s(QSBOOST_PP_SEQ_REVERSE_O, QSBOOST_PP_EMPTY, seq)()
# else
#    define QSBOOST_PP_SEQ_REVERSE_S(s, seq) QSBOOST_PP_SEQ_REVERSE_S_I(s, seq)
#    define QSBOOST_PP_SEQ_REVERSE_S_I(s, seq) QSBOOST_PP_SEQ_FOLD_LEFT_ ## s(QSBOOST_PP_SEQ_REVERSE_O, QSBOOST_PP_EMPTY, seq)()
# endif
#
# endif

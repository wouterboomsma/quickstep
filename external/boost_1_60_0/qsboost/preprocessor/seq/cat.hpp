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
# ifndef QSBOOST_PREPROCESSOR_SEQ_CAT_HPP
# define QSBOOST_PREPROCESSOR_SEQ_CAT_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/if.hpp>
# include <qsboost/preprocessor/seq/fold_left.hpp>
# include <qsboost/preprocessor/seq/seq.hpp>
# include <qsboost/preprocessor/seq/size.hpp>
# include <qsboost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_SEQ_CAT */
#
# define QSBOOST_PP_SEQ_CAT(seq) \
    QSBOOST_PP_IF( \
        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(seq)), \
        QSBOOST_PP_SEQ_CAT_I, \
        QSBOOST_PP_SEQ_HEAD \
    )(seq) \
    /**/
# define QSBOOST_PP_SEQ_CAT_I(seq) QSBOOST_PP_SEQ_FOLD_LEFT(QSBOOST_PP_SEQ_CAT_O, QSBOOST_PP_SEQ_HEAD(seq), QSBOOST_PP_SEQ_TAIL(seq))
#
# define QSBOOST_PP_SEQ_CAT_O(s, st, elem) QSBOOST_PP_SEQ_CAT_O_I(st, elem)
# define QSBOOST_PP_SEQ_CAT_O_I(a, b) a ## b
#
# /* BOOST_PP_SEQ_CAT_S */
#
# define QSBOOST_PP_SEQ_CAT_S(s, seq) \
    QSBOOST_PP_IF( \
        QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(seq)), \
        QSBOOST_PP_SEQ_CAT_S_I_A, \
        QSBOOST_PP_SEQ_CAT_S_I_B \
    )(s, seq) \
    /**/
# define QSBOOST_PP_SEQ_CAT_S_I_A(s, seq) QSBOOST_PP_SEQ_FOLD_LEFT_ ## s(QSBOOST_PP_SEQ_CAT_O, QSBOOST_PP_SEQ_HEAD(seq), QSBOOST_PP_SEQ_TAIL(seq))
# define QSBOOST_PP_SEQ_CAT_S_I_B(s, seq) QSBOOST_PP_SEQ_HEAD(seq)
#
# endif

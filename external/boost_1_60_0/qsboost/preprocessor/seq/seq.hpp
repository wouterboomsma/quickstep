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
# ifndef QSBOOST_PREPROCESSOR_SEQ_SEQ_HPP
# define QSBOOST_PREPROCESSOR_SEQ_SEQ_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/seq/elem.hpp>
#
# /* BOOST_PP_SEQ_HEAD */
#
# define QSBOOST_PP_SEQ_HEAD(seq) QSBOOST_PP_SEQ_ELEM(0, seq)
#
# /* BOOST_PP_SEQ_TAIL */
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_SEQ_TAIL(seq) QSBOOST_PP_SEQ_TAIL_1((seq))
#    define QSBOOST_PP_SEQ_TAIL_1(par) QSBOOST_PP_SEQ_TAIL_2 ## par
#    define QSBOOST_PP_SEQ_TAIL_2(seq) QSBOOST_PP_SEQ_TAIL_I ## seq
# elif QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_SEQ_TAIL(seq) QSBOOST_PP_SEQ_TAIL_ID(QSBOOST_PP_SEQ_TAIL_I seq)
#    define QSBOOST_PP_SEQ_TAIL_ID(id) id
# elif QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_TAIL(seq) QSBOOST_PP_SEQ_TAIL_D(seq)
#    define QSBOOST_PP_SEQ_TAIL_D(seq) QSBOOST_PP_SEQ_TAIL_I seq
# else
#    define QSBOOST_PP_SEQ_TAIL(seq) QSBOOST_PP_SEQ_TAIL_I seq
# endif
#
# define QSBOOST_PP_SEQ_TAIL_I(x)
#
# /* BOOST_PP_SEQ_NIL */
#
# define QSBOOST_PP_SEQ_NIL(x) (x)
#
# endif

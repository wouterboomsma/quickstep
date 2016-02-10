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
# ifndef QSBOOST_PREPROCESSOR_SEQ_SUBSEQ_HPP
# define QSBOOST_PREPROCESSOR_SEQ_SUBSEQ_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/seq/first_n.hpp>
# include <qsboost/preprocessor/seq/rest_n.hpp>
#
# /* BOOST_PP_SEQ_SUBSEQ */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_SUBSEQ(seq, i, len) QSBOOST_PP_SEQ_FIRST_N(len, QSBOOST_PP_SEQ_REST_N(i, seq))
# else
#    define QSBOOST_PP_SEQ_SUBSEQ(seq, i, len) QSBOOST_PP_SEQ_SUBSEQ_I(seq, i, len)
#    define QSBOOST_PP_SEQ_SUBSEQ_I(seq, i, len) QSBOOST_PP_SEQ_FIRST_N(len, QSBOOST_PP_SEQ_REST_N(i, seq))
# endif
#
# endif

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
# ifndef QSBOOST_PREPROCESSOR_SEQ_POP_BACK_HPP
# define QSBOOST_PREPROCESSOR_SEQ_POP_BACK_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/seq/first_n.hpp>
# include <qsboost/preprocessor/seq/size.hpp>
#
# /* BOOST_PP_SEQ_POP_BACK */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_POP_BACK(seq) QSBOOST_PP_SEQ_FIRST_N(QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(seq)), seq)
# else
#    define QSBOOST_PP_SEQ_POP_BACK(seq) QSBOOST_PP_SEQ_POP_BACK_I(seq)
#    define QSBOOST_PP_SEQ_POP_BACK_I(seq) QSBOOST_PP_SEQ_FIRST_N(QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(seq)), seq)
# endif
#
# endif

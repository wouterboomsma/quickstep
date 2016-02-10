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
# ifndef QSBOOST_PREPROCESSOR_SEQ_TO_TUPLE_HPP
# define QSBOOST_PREPROCESSOR_SEQ_TO_TUPLE_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/seq/enum.hpp>
#
# /* BOOST_PP_SEQ_TO_TUPLE */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_TO_TUPLE(seq) (QSBOOST_PP_SEQ_ENUM(seq))
# else
#    define QSBOOST_PP_SEQ_TO_TUPLE(seq) QSBOOST_PP_SEQ_TO_TUPLE_I(seq)
#    define QSBOOST_PP_SEQ_TO_TUPLE_I(seq) (QSBOOST_PP_SEQ_ENUM(seq))
# endif
#
# endif

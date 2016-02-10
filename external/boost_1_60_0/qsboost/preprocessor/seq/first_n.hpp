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
# ifndef QSBOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
# define QSBOOST_PREPROCESSOR_SEQ_FIRST_N_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/if.hpp>
# include <qsboost/preprocessor/seq/detail/split.hpp>
# include <qsboost/preprocessor/tuple/eat.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_SEQ_FIRST_N */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FIRST_N(n, seq) QSBOOST_PP_IF(n, QSBOOST_PP_TUPLE_ELEM, QSBOOST_PP_TUPLE_EAT_3)(2, 0, QSBOOST_PP_SEQ_SPLIT(n, seq (nil)))
# else
#    define QSBOOST_PP_SEQ_FIRST_N(n, seq) QSBOOST_PP_SEQ_FIRST_N_I(n, seq)
#    define QSBOOST_PP_SEQ_FIRST_N_I(n, seq) QSBOOST_PP_IF(n, QSBOOST_PP_TUPLE_ELEM, QSBOOST_PP_TUPLE_EAT_3)(2, 0, QSBOOST_PP_SEQ_SPLIT(n, seq (nil)))
# endif
#
# endif

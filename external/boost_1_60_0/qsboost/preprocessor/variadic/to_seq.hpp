# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
# define QSBOOST_PREPROCESSOR_VARIADIC_TO_SEQ_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/tuple/to_seq.hpp>
#
# /* BOOST_PP_VARIADIC_TO_SEQ */
#
# if QSBOOST_PP_VARIADICS
#    define QSBOOST_PP_VARIADIC_TO_SEQ(...) QSBOOST_PP_TUPLE_TO_SEQ((__VA_ARGS__))
# endif
#
# endif

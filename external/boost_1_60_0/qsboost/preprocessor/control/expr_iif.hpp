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
# ifndef QSBOOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
# define QSBOOST_PREPROCESSOR_CONTROL_EXPR_IIF_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_EXPR_IIF */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_EXPR_IIF(bit, expr) QSBOOST_PP_EXPR_IIF_I(bit, expr)
# else
#    define QSBOOST_PP_EXPR_IIF(bit, expr) QSBOOST_PP_EXPR_IIF_OO((bit, expr))
#    define QSBOOST_PP_EXPR_IIF_OO(par) QSBOOST_PP_EXPR_IIF_I ## par
# endif
#
# define QSBOOST_PP_EXPR_IIF_I(bit, expr) QSBOOST_PP_EXPR_IIF_ ## bit(expr)
#
# define QSBOOST_PP_EXPR_IIF_0(expr)
# define QSBOOST_PP_EXPR_IIF_1(expr) expr
#
# endif

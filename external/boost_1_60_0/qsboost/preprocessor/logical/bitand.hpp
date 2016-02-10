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
# ifndef QSBOOST_PREPROCESSOR_LOGICAL_BITAND_HPP
# define QSBOOST_PREPROCESSOR_LOGICAL_BITAND_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_BITAND */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_BITAND(x, y) QSBOOST_PP_BITAND_I(x, y)
# else
#    define QSBOOST_PP_BITAND(x, y) QSBOOST_PP_BITAND_OO((x, y))
#    define QSBOOST_PP_BITAND_OO(par) QSBOOST_PP_BITAND_I ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_BITAND_I(x, y) QSBOOST_PP_BITAND_ ## x ## y
# else
#    define QSBOOST_PP_BITAND_I(x, y) QSBOOST_PP_BITAND_ID(QSBOOST_PP_BITAND_ ## x ## y)
#    define QSBOOST_PP_BITAND_ID(res) res
# endif
#
# define QSBOOST_PP_BITAND_00 0
# define QSBOOST_PP_BITAND_01 0
# define QSBOOST_PP_BITAND_10 0
# define QSBOOST_PP_BITAND_11 1
#
# endif

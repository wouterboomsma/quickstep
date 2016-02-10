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
# ifndef QSBOOST_PREPROCESSOR_LOGICAL_BITOR_HPP
# define QSBOOST_PREPROCESSOR_LOGICAL_BITOR_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_BITOR */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_BITOR(x, y) QSBOOST_PP_BITOR_I(x, y)
# else
#    define QSBOOST_PP_BITOR(x, y) QSBOOST_PP_BITOR_OO((x, y))
#    define QSBOOST_PP_BITOR_OO(par) QSBOOST_PP_BITOR_I ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_BITOR_I(x, y) QSBOOST_PP_BITOR_ ## x ## y
# else
#    define QSBOOST_PP_BITOR_I(x, y) QSBOOST_PP_BITOR_ID(QSBOOST_PP_BITOR_ ## x ## y)
#    define QSBOOST_PP_BITOR_ID(id) id
# endif
#
# define QSBOOST_PP_BITOR_00 0
# define QSBOOST_PP_BITOR_01 1
# define QSBOOST_PP_BITOR_10 1
# define QSBOOST_PP_BITOR_11 1
#
# endif

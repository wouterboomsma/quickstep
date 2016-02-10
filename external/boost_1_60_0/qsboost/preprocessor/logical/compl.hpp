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
# ifndef QSBOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
# define QSBOOST_PREPROCESSOR_LOGICAL_COMPL_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_COMPL */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_COMPL(x) QSBOOST_PP_COMPL_I(x)
# else
#    define QSBOOST_PP_COMPL(x) QSBOOST_PP_COMPL_OO((x))
#    define QSBOOST_PP_COMPL_OO(par) QSBOOST_PP_COMPL_I ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_COMPL_I(x) QSBOOST_PP_COMPL_ ## x
# else
#    define QSBOOST_PP_COMPL_I(x) QSBOOST_PP_COMPL_ID(QSBOOST_PP_COMPL_ ## x)
#    define QSBOOST_PP_COMPL_ID(id) id
# endif
#
# define QSBOOST_PP_COMPL_0 1
# define QSBOOST_PP_COMPL_1 0
#
# endif

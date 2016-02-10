# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
# define QSBOOST_PREPROCESSOR_FACILITIES_EXPAND_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC() && ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_DMC()
#    define QSBOOST_PP_EXPAND(x) QSBOOST_PP_EXPAND_I(x)
# else
#    define QSBOOST_PP_EXPAND(x) QSBOOST_PP_EXPAND_OO((x))
#    define QSBOOST_PP_EXPAND_OO(par) QSBOOST_PP_EXPAND_I ## par
# endif
#
# define QSBOOST_PP_EXPAND_I(x) x
#
# endif

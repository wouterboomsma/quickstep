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
# ifndef QSBOOST_PREPROCESSOR_COMPARISON_GREATER_HPP
# define QSBOOST_PREPROCESSOR_COMPARISON_GREATER_HPP
#
# include <qsboost/preprocessor/comparison/less.hpp>
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_GREATER */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_GREATER(x, y) QSBOOST_PP_LESS(y, x)
# else
#    define QSBOOST_PP_GREATER(x, y) QSBOOST_PP_GREATER_I(x, y)
#    define QSBOOST_PP_GREATER_I(x, y) QSBOOST_PP_LESS(y, x)
# endif
#
# /* BOOST_PP_GREATER_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_GREATER_D(d, x, y) QSBOOST_PP_LESS_D(d, y, x)
# else
#    define QSBOOST_PP_GREATER_D(d, x, y) QSBOOST_PP_GREATER_D_I(d, x, y)
#    define QSBOOST_PP_GREATER_D_I(d, x, y) QSBOOST_PP_LESS_D(d, y, x)
# endif
#
# endif

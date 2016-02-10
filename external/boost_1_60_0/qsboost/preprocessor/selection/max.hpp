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
# ifndef QSBOOST_PREPROCESSOR_SELECTION_MAX_HPP
# define QSBOOST_PREPROCESSOR_SELECTION_MAX_HPP
#
# include <qsboost/preprocessor/comparison/less_equal.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/iif.hpp>
#
# /* BOOST_PP_MAX */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_MAX(x, y) QSBOOST_PP_IIF(QSBOOST_PP_LESS_EQUAL(x, y), y, x)
# else
#    define QSBOOST_PP_MAX(x, y) QSBOOST_PP_MAX_I(x, y)
#    define QSBOOST_PP_MAX_I(x, y) QSBOOST_PP_IIF(QSBOOST_PP_LESS_EQUAL(x, y), y, x)
# endif
#
# /* BOOST_PP_MAX_D */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_MAX_D(d, x, y) QSBOOST_PP_IIF(QSBOOST_PP_LESS_EQUAL_D(d, x, y), y, x)
# else
#    define QSBOOST_PP_MAX_D(d, x, y) QSBOOST_PP_MAX_D_I(d, x, y)
#    define QSBOOST_PP_MAX_D_I(d, x, y) QSBOOST_PP_IIF(QSBOOST_PP_LESS_EQUAL_D(d, x, y), y, x)
# endif
#
# endif

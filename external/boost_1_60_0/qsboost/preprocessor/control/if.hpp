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
# ifndef QSBOOST_PREPROCESSOR_CONTROL_IF_HPP
# define QSBOOST_PREPROCESSOR_CONTROL_IF_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/iif.hpp>
# include <qsboost/preprocessor/logical/bool.hpp>
#
# /* BOOST_PP_IF */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_IF(cond, t, f) QSBOOST_PP_IIF(QSBOOST_PP_BOOL(cond), t, f)
# else
#    define QSBOOST_PP_IF(cond, t, f) QSBOOST_PP_IF_I(cond, t, f)
#    define QSBOOST_PP_IF_I(cond, t, f) QSBOOST_PP_IIF(QSBOOST_PP_BOOL(cond), t, f)
# endif
#
# endif

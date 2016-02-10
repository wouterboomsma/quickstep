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
# ifndef QSBOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
# define QSBOOST_PREPROCESSOR_REPETITION_ENUM_PARAMS_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/punctuation/comma_if.hpp>
# include <qsboost/preprocessor/repetition/repeat.hpp>
#
# /* BOOST_PP_ENUM_PARAMS */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ENUM_PARAMS(count, param) QSBOOST_PP_REPEAT(count, QSBOOST_PP_ENUM_PARAMS_M, param)
# else
#    define QSBOOST_PP_ENUM_PARAMS(count, param) QSBOOST_PP_ENUM_PARAMS_I(count, param)
#    define QSBOOST_PP_ENUM_PARAMS_I(count, param) QSBOOST_PP_REPEAT(count, QSBOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# define QSBOOST_PP_ENUM_PARAMS_M(z, n, param) QSBOOST_PP_COMMA_IF(n) param ## n
#
# /* BOOST_PP_ENUM_PARAMS_Z */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ENUM_PARAMS_Z(z, count, param) QSBOOST_PP_REPEAT_ ## z(count, QSBOOST_PP_ENUM_PARAMS_M, param)
# else
#    define QSBOOST_PP_ENUM_PARAMS_Z(z, count, param) QSBOOST_PP_ENUM_PARAMS_Z_I(z, count, param)
#    define QSBOOST_PP_ENUM_PARAMS_Z_I(z, count, param) QSBOOST_PP_REPEAT_ ## z(count, QSBOOST_PP_ENUM_PARAMS_M, param)
# endif
#
# endif

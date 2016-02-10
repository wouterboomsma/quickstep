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
# ifndef QSBOOST_PREPROCESSOR_LOGICAL_NOT_HPP
# define QSBOOST_PREPROCESSOR_LOGICAL_NOT_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/logical/bool.hpp>
# include <qsboost/preprocessor/logical/compl.hpp>
#
# /* BOOST_PP_NOT */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_NOT(x) QSBOOST_PP_COMPL(QSBOOST_PP_BOOL(x))
# else
#    define QSBOOST_PP_NOT(x) QSBOOST_PP_NOT_I(x)
#    define QSBOOST_PP_NOT_I(x) QSBOOST_PP_COMPL(QSBOOST_PP_BOOL(x))
# endif
#
# endif

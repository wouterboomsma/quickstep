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
# ifndef QSBOOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
# define QSBOOST_PREPROCESSOR_PUNCTUATION_COMMA_IF_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/if.hpp>
# include <qsboost/preprocessor/facilities/empty.hpp>
# include <qsboost/preprocessor/punctuation/comma.hpp>
#
# /* BOOST_PP_COMMA_IF */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_COMMA_IF(cond) QSBOOST_PP_IF(cond, QSBOOST_PP_COMMA, QSBOOST_PP_EMPTY)()
# else
#    define QSBOOST_PP_COMMA_IF(cond) QSBOOST_PP_COMMA_IF_I(cond)
#    define QSBOOST_PP_COMMA_IF_I(cond) QSBOOST_PP_IF(cond, QSBOOST_PP_COMMA, QSBOOST_PP_EMPTY)()
# endif
#
# endif

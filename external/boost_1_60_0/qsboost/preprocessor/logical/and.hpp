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
# ifndef QSBOOST_PREPROCESSOR_LOGICAL_AND_HPP
# define QSBOOST_PREPROCESSOR_LOGICAL_AND_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/logical/bool.hpp>
# include <qsboost/preprocessor/logical/bitand.hpp>
#
# /* BOOST_PP_AND */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_AND(p, q) QSBOOST_PP_BITAND(QSBOOST_PP_BOOL(p), QSBOOST_PP_BOOL(q))
# else
#    define QSBOOST_PP_AND(p, q) QSBOOST_PP_AND_I(p, q)
#    define QSBOOST_PP_AND_I(p, q) QSBOOST_PP_BITAND(QSBOOST_PP_BOOL(p), QSBOOST_PP_BOOL(q))
# endif
#
# endif

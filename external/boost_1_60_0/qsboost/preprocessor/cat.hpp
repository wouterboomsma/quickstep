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
# ifndef QSBOOST_PREPROCESSOR_CAT_HPP
# define QSBOOST_PREPROCESSOR_CAT_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_CAT */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_CAT(a, b) QSBOOST_PP_CAT_I(a, b)
# else
#    define QSBOOST_PP_CAT(a, b) QSBOOST_PP_CAT_OO((a, b))
#    define QSBOOST_PP_CAT_OO(par) QSBOOST_PP_CAT_I ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_CAT_I(a, b) a ## b
# else
#    define QSBOOST_PP_CAT_I(a, b) QSBOOST_PP_CAT_II(~, a ## b)
#    define QSBOOST_PP_CAT_II(p, res) res
# endif
#
# endif

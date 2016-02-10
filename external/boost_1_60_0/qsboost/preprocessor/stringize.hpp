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
# ifndef QSBOOST_PREPROCESSOR_STRINGIZE_HPP
# define QSBOOST_PREPROCESSOR_STRINGIZE_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_STRINGIZE */
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_STRINGIZE(text) QSBOOST_PP_STRINGIZE_A((text))
#    define QSBOOST_PP_STRINGIZE_A(arg) QSBOOST_PP_STRINGIZE_I arg
# elif QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_STRINGIZE(text) QSBOOST_PP_STRINGIZE_OO((text))
#    define QSBOOST_PP_STRINGIZE_OO(par) QSBOOST_PP_STRINGIZE_I ## par
# else
#    define QSBOOST_PP_STRINGIZE(text) QSBOOST_PP_STRINGIZE_I(text)
# endif
#
# define QSBOOST_PP_STRINGIZE_I(text) #text
#
# endif

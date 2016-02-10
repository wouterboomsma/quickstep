# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_CONTROL_IIF_HPP
# define QSBOOST_PREPROCESSOR_CONTROL_IIF_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_IIF(bit, t, f) QSBOOST_PP_IIF_I(bit, t, f)
# else
#    define QSBOOST_PP_IIF(bit, t, f) QSBOOST_PP_IIF_OO((bit, t, f))
#    define QSBOOST_PP_IIF_OO(par) QSBOOST_PP_IIF_I ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_IIF_I(bit, t, f) QSBOOST_PP_IIF_ ## bit(t, f)
# else
#    define QSBOOST_PP_IIF_I(bit, t, f) QSBOOST_PP_IIF_II(QSBOOST_PP_IIF_ ## bit(t, f))
#    define QSBOOST_PP_IIF_II(id) id
# endif
#
# define QSBOOST_PP_IIF_0(t, f) f
# define QSBOOST_PP_IIF_1(t, f) t
#
# endif

# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# ifndef QSBOOST_PREPROCESSOR_DETAIL_SPLIT_HPP
# define QSBOOST_PREPROCESSOR_DETAIL_SPLIT_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_SPLIT */
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_SPLIT(n, im) QSBOOST_PP_SPLIT_I((n, im))
#    define QSBOOST_PP_SPLIT_I(par) QSBOOST_PP_SPLIT_II ## par
#    define QSBOOST_PP_SPLIT_II(n, a, b) QSBOOST_PP_SPLIT_ ## n(a, b)
# elif QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_SPLIT(n, im) QSBOOST_PP_SPLIT_I(n((im)))
#    define QSBOOST_PP_SPLIT_I(n) QSBOOST_PP_SPLIT_ID(QSBOOST_PP_SPLIT_II_ ## n)
#    define QSBOOST_PP_SPLIT_II_0(s) QSBOOST_PP_SPLIT_ID(QSBOOST_PP_SPLIT_0 s)
#    define QSBOOST_PP_SPLIT_II_1(s) QSBOOST_PP_SPLIT_ID(QSBOOST_PP_SPLIT_1 s)
#    define QSBOOST_PP_SPLIT_ID(id) id
# else
#    define QSBOOST_PP_SPLIT(n, im) QSBOOST_PP_SPLIT_I(n)(im)
#    define QSBOOST_PP_SPLIT_I(n) QSBOOST_PP_SPLIT_ ## n
# endif
#
# define QSBOOST_PP_SPLIT_0(a, b) a
# define QSBOOST_PP_SPLIT_1(a, b) b
#
# endif

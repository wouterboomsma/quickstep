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
# ifndef QSBOOST_PREPROCESSOR_ARRAY_SIZE_HPP
# define QSBOOST_PREPROCESSOR_ARRAY_SIZE_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_SIZE */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ARRAY_SIZE(array) QSBOOST_PP_TUPLE_ELEM(2, 0, array)
# else
#    define QSBOOST_PP_ARRAY_SIZE(array) QSBOOST_PP_ARRAY_SIZE_I(array)
#    define QSBOOST_PP_ARRAY_SIZE_I(array) QSBOOST_PP_ARRAY_SIZE_II array
#    define QSBOOST_PP_ARRAY_SIZE_II(size, data) size
# endif
#
# endif

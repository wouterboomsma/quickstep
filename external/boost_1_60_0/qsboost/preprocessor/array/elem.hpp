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
# ifndef QSBOOST_PREPROCESSOR_ARRAY_ELEM_HPP
# define QSBOOST_PREPROCESSOR_ARRAY_ELEM_HPP
#
# include <qsboost/preprocessor/array/data.hpp>
# include <qsboost/preprocessor/array/size.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ARRAY_ELEM */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ARRAY_ELEM(i, array) QSBOOST_PP_TUPLE_ELEM(QSBOOST_PP_ARRAY_SIZE(array), i, QSBOOST_PP_ARRAY_DATA(array))
# else
#    define QSBOOST_PP_ARRAY_ELEM(i, array) QSBOOST_PP_ARRAY_ELEM_I(i, array)
#    define QSBOOST_PP_ARRAY_ELEM_I(i, array) QSBOOST_PP_TUPLE_ELEM(QSBOOST_PP_ARRAY_SIZE(array), i, QSBOOST_PP_ARRAY_DATA(array))
# endif
#
# endif

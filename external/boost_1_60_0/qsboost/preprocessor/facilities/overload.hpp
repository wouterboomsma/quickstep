# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
# define QSBOOST_PREPROCESSOR_FACILITIES_OVERLOAD_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/variadic/size.hpp>
#
# /* BOOST_PP_OVERLOAD */
#
# if QSBOOST_PP_VARIADICS
#    define QSBOOST_PP_OVERLOAD(prefix, ...) QSBOOST_PP_CAT(prefix, QSBOOST_PP_VARIADIC_SIZE(__VA_ARGS__))
# endif
#
# endif

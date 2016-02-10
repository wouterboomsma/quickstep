# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_TUPLE_SIZE_HPP
# define QSBOOST_PREPROCESSOR_TUPLE_SIZE_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/variadic/size.hpp>
#
# if QSBOOST_PP_VARIADICS
#    if QSBOOST_PP_VARIADICS_MSVC
#        define QSBOOST_PP_TUPLE_SIZE(tuple) QSBOOST_PP_CAT(QSBOOST_PP_VARIADIC_SIZE tuple,)
#    else
#        define QSBOOST_PP_TUPLE_SIZE(tuple) QSBOOST_PP_VARIADIC_SIZE tuple
#    endif
# endif
#
# endif

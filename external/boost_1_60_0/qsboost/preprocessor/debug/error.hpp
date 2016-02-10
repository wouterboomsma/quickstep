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
# ifndef QSBOOST_PREPROCESSOR_DEBUG_ERROR_HPP
# define QSBOOST_PREPROCESSOR_DEBUG_ERROR_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_ERROR */
#
# if QSBOOST_PP_CONFIG_ERRORS
#    define QSBOOST_PP_ERROR(code) QSBOOST_PP_CAT(QSBOOST_PP_ERROR_, code)
# endif
#
# define QSBOOST_PP_ERROR_0x0000 QSBOOST_PP_ERROR(0x0000, QSBOOST_PP_INDEX_OUT_OF_BOUNDS)
# define QSBOOST_PP_ERROR_0x0001 QSBOOST_PP_ERROR(0x0001, QSBOOST_PP_WHILE_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0002 QSBOOST_PP_ERROR(0x0002, QSBOOST_PP_FOR_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0003 QSBOOST_PP_ERROR(0x0003, QSBOOST_PP_REPEAT_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0004 QSBOOST_PP_ERROR(0x0004, QSBOOST_PP_LIST_FOLD_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0005 QSBOOST_PP_ERROR(0x0005, QSBOOST_PP_SEQ_FOLD_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0006 QSBOOST_PP_ERROR(0x0006, QSBOOST_PP_ARITHMETIC_OVERFLOW)
# define QSBOOST_PP_ERROR_0x0007 QSBOOST_PP_ERROR(0x0007, QSBOOST_PP_DIVISION_BY_ZERO)
#
# endif

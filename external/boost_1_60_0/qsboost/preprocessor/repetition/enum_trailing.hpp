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
# ifndef QSBOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_HPP
# define QSBOOST_PREPROCESSOR_REPETITION_ENUM_TRAILING_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/debug/error.hpp>
# include <qsboost/preprocessor/detail/auto_rec.hpp>
# include <qsboost/preprocessor/repetition/repeat.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_ENUM_TRAILING */
#
# if 0
#    define QSBOOST_PP_ENUM_TRAILING(count, macro, data)
# endif
#
# define QSBOOST_PP_ENUM_TRAILING QSBOOST_PP_CAT(QSBOOST_PP_ENUM_TRAILING_, QSBOOST_PP_AUTO_REC(QSBOOST_PP_REPEAT_P, 4))
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ENUM_TRAILING_1(c, m, d) QSBOOST_PP_REPEAT_1(c, QSBOOST_PP_ENUM_TRAILING_M_1, (m, d))
#    define QSBOOST_PP_ENUM_TRAILING_2(c, m, d) QSBOOST_PP_REPEAT_2(c, QSBOOST_PP_ENUM_TRAILING_M_2, (m, d))
#    define QSBOOST_PP_ENUM_TRAILING_3(c, m, d) QSBOOST_PP_REPEAT_3(c, QSBOOST_PP_ENUM_TRAILING_M_3, (m, d))
# else
#    define QSBOOST_PP_ENUM_TRAILING_1(c, m, d) QSBOOST_PP_ENUM_TRAILING_1_I(c, m, d)
#    define QSBOOST_PP_ENUM_TRAILING_2(c, m, d) QSBOOST_PP_ENUM_TRAILING_2_I(c, m, d)
#    define QSBOOST_PP_ENUM_TRAILING_3(c, m, d) QSBOOST_PP_ENUM_TRAILING_3_I(c, m, d)
#    define QSBOOST_PP_ENUM_TRAILING_1_I(c, m, d) QSBOOST_PP_REPEAT_1(c, QSBOOST_PP_ENUM_TRAILING_M_1, (m, d))
#    define QSBOOST_PP_ENUM_TRAILING_2_I(c, m, d) QSBOOST_PP_REPEAT_2(c, QSBOOST_PP_ENUM_TRAILING_M_2, (m, d))
#    define QSBOOST_PP_ENUM_TRAILING_3_I(c, m, d) QSBOOST_PP_REPEAT_3(c, QSBOOST_PP_ENUM_TRAILING_M_3, (m, d))
# endif
#
# define QSBOOST_PP_ENUM_TRAILING_4(c, m, d) QSBOOST_PP_ERROR(0x0003)
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_ENUM_TRAILING_M_1(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_1_IM(z, n, QSBOOST_PP_TUPLE_REM_2 md)
#    define QSBOOST_PP_ENUM_TRAILING_M_2(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_2_IM(z, n, QSBOOST_PP_TUPLE_REM_2 md)
#    define QSBOOST_PP_ENUM_TRAILING_M_3(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_3_IM(z, n, QSBOOST_PP_TUPLE_REM_2 md)
#    define QSBOOST_PP_ENUM_TRAILING_M_1_IM(z, n, im) QSBOOST_PP_ENUM_TRAILING_M_1_I(z, n, im)
#    define QSBOOST_PP_ENUM_TRAILING_M_2_IM(z, n, im) QSBOOST_PP_ENUM_TRAILING_M_2_I(z, n, im)
#    define QSBOOST_PP_ENUM_TRAILING_M_3_IM(z, n, im) QSBOOST_PP_ENUM_TRAILING_M_3_I(z, n, im)
# else
#    define QSBOOST_PP_ENUM_TRAILING_M_1(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_1_I(z, n, QSBOOST_PP_TUPLE_ELEM(2, 0, md), QSBOOST_PP_TUPLE_ELEM(2, 1, md))
#    define QSBOOST_PP_ENUM_TRAILING_M_2(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_2_I(z, n, QSBOOST_PP_TUPLE_ELEM(2, 0, md), QSBOOST_PP_TUPLE_ELEM(2, 1, md))
#    define QSBOOST_PP_ENUM_TRAILING_M_3(z, n, md) QSBOOST_PP_ENUM_TRAILING_M_3_I(z, n, QSBOOST_PP_TUPLE_ELEM(2, 0, md), QSBOOST_PP_TUPLE_ELEM(2, 1, md))
# endif
#
# define QSBOOST_PP_ENUM_TRAILING_M_1_I(z, n, m, d) , m(z, n, d)
# define QSBOOST_PP_ENUM_TRAILING_M_2_I(z, n, m, d) , m(z, n, d)
# define QSBOOST_PP_ENUM_TRAILING_M_3_I(z, n, m, d) , m(z, n, d)
#
# endif

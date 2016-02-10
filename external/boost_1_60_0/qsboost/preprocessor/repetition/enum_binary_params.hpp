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
# ifndef QSBOOST_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
# define QSBOOST_PREPROCESSOR_REPETITION_ENUM_BINARY_PARAMS_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/punctuation/comma_if.hpp>
# include <qsboost/preprocessor/repetition/repeat.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_ENUM_BINARY_PARAMS */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ENUM_BINARY_PARAMS(count, p1, p2) QSBOOST_PP_REPEAT(count, QSBOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define QSBOOST_PP_ENUM_BINARY_PARAMS(count, p1, p2) QSBOOST_PP_ENUM_BINARY_PARAMS_I(count, p1, p2)
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_I(count, p1, p2) QSBOOST_PP_REPEAT(count, QSBOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M(z, n, pp) QSBOOST_PP_ENUM_BINARY_PARAMS_M_IM(z, n, QSBOOST_PP_TUPLE_REM_2 pp)
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M_IM(z, n, im) QSBOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, im)
# else
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M(z, n, pp) QSBOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, QSBOOST_PP_TUPLE_ELEM(2, 0, pp), QSBOOST_PP_TUPLE_ELEM(2, 1, pp))
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) QSBOOST_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2)
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M_II(z, n, p1, p2) QSBOOST_PP_COMMA_IF(n) p1 ## n p2 ## n
# else
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_M_I(z, n, p1, p2) QSBOOST_PP_COMMA_IF(n) QSBOOST_PP_CAT(p1, n) QSBOOST_PP_CAT(p2, n)
# endif
#
# /* BOOST_PP_ENUM_BINARY_PARAMS_Z */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) QSBOOST_PP_REPEAT_ ## z(count, QSBOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# else
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_Z(z, count, p1, p2) QSBOOST_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2)
#    define QSBOOST_PP_ENUM_BINARY_PARAMS_Z_I(z, count, p1, p2) QSBOOST_PP_REPEAT_ ## z(count, QSBOOST_PP_ENUM_BINARY_PARAMS_M, (p1, p2))
# endif
#
# endif

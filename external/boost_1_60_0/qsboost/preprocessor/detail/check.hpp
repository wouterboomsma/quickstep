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
# ifndef QSBOOST_PREPROCESSOR_DETAIL_CHECK_HPP
# define QSBOOST_PREPROCESSOR_DETAIL_CHECK_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_CHECK */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_CHECK(x, type) QSBOOST_PP_CHECK_D(x, type)
# else
#    define QSBOOST_PP_CHECK(x, type) QSBOOST_PP_CHECK_OO((x, type))
#    define QSBOOST_PP_CHECK_OO(par) QSBOOST_PP_CHECK_D ## par
# endif
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC() && ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_DMC()
#    define QSBOOST_PP_CHECK_D(x, type) QSBOOST_PP_CHECK_1(QSBOOST_PP_CAT(QSBOOST_PP_CHECK_RESULT_, type x))
#    define QSBOOST_PP_CHECK_1(chk) QSBOOST_PP_CHECK_2(chk)
#    define QSBOOST_PP_CHECK_2(res, _) res
# elif QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#    define QSBOOST_PP_CHECK_D(x, type) QSBOOST_PP_CHECK_1(type x)
#    define QSBOOST_PP_CHECK_1(chk) QSBOOST_PP_CHECK_2(chk)
#    define QSBOOST_PP_CHECK_2(chk) QSBOOST_PP_CHECK_3((QSBOOST_PP_CHECK_RESULT_ ## chk))
#    define QSBOOST_PP_CHECK_3(im) QSBOOST_PP_CHECK_5(QSBOOST_PP_CHECK_4 im)
#    define QSBOOST_PP_CHECK_4(res, _) res
#    define QSBOOST_PP_CHECK_5(res) res
# else /* DMC */
#    define QSBOOST_PP_CHECK_D(x, type) QSBOOST_PP_CHECK_OO((type x))
#    define QSBOOST_PP_CHECK_OO(par) QSBOOST_PP_CHECK_0 ## par
#    define QSBOOST_PP_CHECK_0(chk) QSBOOST_PP_CHECK_1(QSBOOST_PP_CAT(QSBOOST_PP_CHECK_RESULT_, chk))
#    define QSBOOST_PP_CHECK_1(chk) QSBOOST_PP_CHECK_2(chk)
#    define QSBOOST_PP_CHECK_2(res, _) res
# endif
#
# define QSBOOST_PP_CHECK_RESULT_1 1, QSBOOST_PP_NIL
#
# endif

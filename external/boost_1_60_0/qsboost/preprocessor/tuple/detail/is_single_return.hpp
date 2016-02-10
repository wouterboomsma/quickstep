# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
# define QSBOOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_TUPLE_IS_SINGLE_RETURN */
#
# if QSBOOST_PP_VARIADICS && QSBOOST_PP_VARIADICS_MSVC
# include <qsboost/preprocessor/control/iif.hpp>
# include <qsboost/preprocessor/facilities/is_1.hpp>
# include <qsboost/preprocessor/tuple/size.hpp>
# define QSBOOST_PP_TUPLE_IS_SINGLE_RETURN(sr,nsr,tuple)	\
	QSBOOST_PP_IIF(QSBOOST_PP_IS_1(QSBOOST_PP_TUPLE_SIZE(tuple)),sr,nsr) \
	/**/
# endif /* BOOST_PP_VARIADICS && BOOST_PP_VARIADICS_MSVC */
#
# endif /* BOOST_PREPROCESSOR_TUPLE_DETAIL_IS_SINGLE_RETURN_HPP */

# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2015.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_SEQ_DETAIL_IS_EMPTY_HPP
# define QSBOOST_PREPROCESSOR_SEQ_DETAIL_IS_EMPTY_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/logical/bool.hpp>
# include <qsboost/preprocessor/logical/compl.hpp>
# include <qsboost/preprocessor/seq/size.hpp>
#
/* An empty seq is one that is just BOOST_PP_SEQ_NIL */
#
# define QSBOOST_PP_SEQ_DETAIL_IS_EMPTY(seq) \
	QSBOOST_PP_COMPL \
		( \
		QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq) \
		) \
/**/
#
# define QSBOOST_PP_SEQ_DETAIL_IS_EMPTY_SIZE(size) \
	QSBOOST_PP_COMPL \
		( \
		QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size) \
		) \
/**/
#
# define QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq) \
	QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(QSBOOST_PP_SEQ_DETAIL_EMPTY_SIZE(seq)) \
/**/
#
# define QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size) \
	QSBOOST_PP_BOOL(size) \
/**/
#
# define QSBOOST_PP_SEQ_DETAIL_EMPTY_SIZE(seq) \
	QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(seq (nil))) \
/**/
#
# endif

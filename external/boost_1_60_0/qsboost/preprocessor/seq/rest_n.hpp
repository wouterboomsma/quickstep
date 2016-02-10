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
# ifndef QSBOOST_PREPROCESSOR_SEQ_REST_N_HPP
# define QSBOOST_PREPROCESSOR_SEQ_REST_N_HPP
#
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/comparison/not_equal.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/expr_iif.hpp>
# include <qsboost/preprocessor/facilities/identity.hpp>
# include <qsboost/preprocessor/logical/bitand.hpp>
# include <qsboost/preprocessor/seq/detail/is_empty.hpp>
# include <qsboost/preprocessor/seq/detail/split.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_SEQ_REST_N */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_REST_N(n, seq) QSBOOST_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, QSBOOST_PP_SEQ_DETAIL_EMPTY_SIZE(seq))
# else
#    define QSBOOST_PP_SEQ_REST_N(n, seq) QSBOOST_PP_SEQ_REST_N_I(n, seq)
#    define QSBOOST_PP_SEQ_REST_N_I(n, seq) QSBOOST_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, QSBOOST_PP_SEQ_DETAIL_EMPTY_SIZE(seq))
# endif
#
#    define QSBOOST_PP_SEQ_REST_N_DETAIL_EXEC(n, seq, size) \
		QSBOOST_PP_EXPR_IIF \
			( \
			QSBOOST_PP_BITAND \
				( \
				QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY_SIZE(size), \
				QSBOOST_PP_NOT_EQUAL(n,size) \
				), \
			QSBOOST_PP_TUPLE_ELEM(2, 1, QSBOOST_PP_SEQ_SPLIT(QSBOOST_PP_INC(n), QSBOOST_PP_IDENTITY( (nil) seq )))() \
			) \
/**/
#
# endif

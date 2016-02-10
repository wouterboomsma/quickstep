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
# ifndef QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
# define QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_I_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/control/if.hpp>
# include <qsboost/preprocessor/control/iif.hpp>
# include <qsboost/preprocessor/repetition/for.hpp>
# include <qsboost/preprocessor/seq/seq.hpp>
# include <qsboost/preprocessor/seq/size.hpp>
# include <qsboost/preprocessor/seq/detail/is_empty.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/tuple/rem.hpp>
#
# /* BOOST_PP_SEQ_FOR_EACH_I */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define QSBOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq)
# endif
#
#    define QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EXEC(macro, data, seq) QSBOOST_PP_FOR((macro, data, seq, 0, QSBOOST_PP_SEQ_SIZE(seq)), QSBOOST_PP_SEQ_FOR_EACH_I_P, QSBOOST_PP_SEQ_FOR_EACH_I_O, QSBOOST_PP_SEQ_FOR_EACH_I_M)
#    define QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EMPTY(macro, data, seq)
#
#    define QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK(macro, data, seq) \
		QSBOOST_PP_IIF \
			( \
			QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EXEC, \
			QSBOOST_PP_SEQ_FOR_EACH_I_DETAIL_CHECK_EMPTY \
			) \
		(macro, data, seq) \
/**/
#
# define QSBOOST_PP_SEQ_FOR_EACH_I_P(r, x) QSBOOST_PP_TUPLE_ELEM(5, 4, x)
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_FOR_EACH_I_O(r, x) QSBOOST_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_I_O(r, x) QSBOOST_PP_SEQ_FOR_EACH_I_O_I(QSBOOST_PP_TUPLE_ELEM(5, 0, x), QSBOOST_PP_TUPLE_ELEM(5, 1, x), QSBOOST_PP_TUPLE_ELEM(5, 2, x), QSBOOST_PP_TUPLE_ELEM(5, 3, x), QSBOOST_PP_TUPLE_ELEM(5, 4, x))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i, sz) \
	QSBOOST_PP_SEQ_FOR_EACH_I_O_I_DEC(macro, data, seq, i, QSBOOST_PP_DEC(sz)) \
/**/
# define QSBOOST_PP_SEQ_FOR_EACH_I_O_I_DEC(macro, data, seq, i, sz) \
	( \
	macro, \
	data, \
	QSBOOST_PP_IF \
		( \
		sz, \
		QSBOOST_PP_SEQ_FOR_EACH_I_O_I_TAIL, \
		QSBOOST_PP_SEQ_FOR_EACH_I_O_I_NIL \
		) \
	(seq), \
	QSBOOST_PP_INC(i), \
	sz \
	) \
/**/
# define QSBOOST_PP_SEQ_FOR_EACH_I_O_I_TAIL(seq) QSBOOST_PP_SEQ_TAIL(seq)
# define QSBOOST_PP_SEQ_FOR_EACH_I_O_I_NIL(seq) QSBOOST_PP_NIL
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_FOR_EACH_I_M(r, x) QSBOOST_PP_SEQ_FOR_EACH_I_M_IM(r, QSBOOST_PP_TUPLE_REM_5 x)
#    define QSBOOST_PP_SEQ_FOR_EACH_I_M_IM(r, im) QSBOOST_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_I_M(r, x) QSBOOST_PP_SEQ_FOR_EACH_I_M_I(r, QSBOOST_PP_TUPLE_ELEM(5, 0, x), QSBOOST_PP_TUPLE_ELEM(5, 1, x), QSBOOST_PP_TUPLE_ELEM(5, 2, x), QSBOOST_PP_TUPLE_ELEM(5, 3, x), QSBOOST_PP_TUPLE_ELEM(5, 4, x))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i, sz) macro(r, data, i, QSBOOST_PP_SEQ_HEAD(seq))
#
# /* BOOST_PP_SEQ_FOR_EACH_I_R */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq)
# endif
#
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EXEC(r, macro, data, seq) QSBOOST_PP_FOR_ ## r((macro, data, seq, 0, QSBOOST_PP_SEQ_SIZE(seq)), QSBOOST_PP_SEQ_FOR_EACH_I_P, QSBOOST_PP_SEQ_FOR_EACH_I_O, QSBOOST_PP_SEQ_FOR_EACH_I_M)
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EMPTY(r, macro, data, seq)
#
#    define QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK(r, macro, data, seq) \
		QSBOOST_PP_IIF \
			( \
			QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EXEC, \
			QSBOOST_PP_SEQ_FOR_EACH_I_R_DETAIL_CHECK_EMPTY \
			) \
		(r, macro, data, seq) \
/**/
#
# endif

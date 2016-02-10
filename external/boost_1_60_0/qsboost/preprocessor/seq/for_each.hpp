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
# ifndef QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
# define QSBOOST_PREPROCESSOR_SEQ_FOR_EACH_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
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
# /* BOOST_PP_SEQ_FOR_EACH */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_D(macro, data, seq)
#    define QSBOOST_PP_SEQ_FOR_EACH_D(macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq)
# endif
#
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC(macro, data, seq) QSBOOST_PP_FOR((macro, data, seq, QSBOOST_PP_SEQ_SIZE(seq)), QSBOOST_PP_SEQ_FOR_EACH_P, QSBOOST_PP_SEQ_FOR_EACH_O, QSBOOST_PP_SEQ_FOR_EACH_M)
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY(macro, data, seq)
#
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK(macro, data, seq) \
		QSBOOST_PP_IIF \
			( \
			QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC, \
			QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY \
			) \
		(macro, data, seq) \
/**/
#
# define QSBOOST_PP_SEQ_FOR_EACH_P(r, x) QSBOOST_PP_TUPLE_ELEM(4, 3, x)
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_FOR_EACH_O(r, x) QSBOOST_PP_SEQ_FOR_EACH_O_I x
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_O(r, x) QSBOOST_PP_SEQ_FOR_EACH_O_I(QSBOOST_PP_TUPLE_ELEM(4, 0, x), QSBOOST_PP_TUPLE_ELEM(4, 1, x), QSBOOST_PP_TUPLE_ELEM(4, 2, x), QSBOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_O_I(macro, data, seq, sz) \
	QSBOOST_PP_SEQ_FOR_EACH_O_I_DEC(macro, data, seq, QSBOOST_PP_DEC(sz)) \
/**/
# define QSBOOST_PP_SEQ_FOR_EACH_O_I_DEC(macro, data, seq, sz) \
	( \
	macro, \
	data, \
	QSBOOST_PP_IF \
		( \
		sz, \
		QSBOOST_PP_SEQ_FOR_EACH_O_I_TAIL, \
		QSBOOST_PP_SEQ_FOR_EACH_O_I_NIL \
		) \
	(seq), \
	sz \
	) \
/**/
# define QSBOOST_PP_SEQ_FOR_EACH_O_I_TAIL(seq) QSBOOST_PP_SEQ_TAIL(seq)
# define QSBOOST_PP_SEQ_FOR_EACH_O_I_NIL(seq) QSBOOST_PP_NIL
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_STRICT()
#    define QSBOOST_PP_SEQ_FOR_EACH_M(r, x) QSBOOST_PP_SEQ_FOR_EACH_M_IM(r, QSBOOST_PP_TUPLE_REM_4 x)
#    define QSBOOST_PP_SEQ_FOR_EACH_M_IM(r, im) QSBOOST_PP_SEQ_FOR_EACH_M_I(r, im)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_M(r, x) QSBOOST_PP_SEQ_FOR_EACH_M_I(r, QSBOOST_PP_TUPLE_ELEM(4, 0, x), QSBOOST_PP_TUPLE_ELEM(4, 1, x), QSBOOST_PP_TUPLE_ELEM(4, 2, x), QSBOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define QSBOOST_PP_SEQ_FOR_EACH_M_I(r, macro, data, seq, sz) macro(r, data, QSBOOST_PP_SEQ_HEAD(seq))
#
# /* BOOST_PP_SEQ_FOR_EACH_R */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_EDG()
#    define QSBOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq)
# else
#    define QSBOOST_PP_SEQ_FOR_EACH_R(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq)
#    define QSBOOST_PP_SEQ_FOR_EACH_R_I(r, macro, data, seq) QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq)
# endif
#
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC_R(r, macro, data, seq) QSBOOST_PP_FOR_ ## r((macro, data, seq, QSBOOST_PP_SEQ_SIZE(seq)), QSBOOST_PP_SEQ_FOR_EACH_P, QSBOOST_PP_SEQ_FOR_EACH_O, QSBOOST_PP_SEQ_FOR_EACH_M)
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY_R(r, macro, data, seq)
#
#    define QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_R(r, macro, data, seq) \
		QSBOOST_PP_IIF \
			( \
			QSBOOST_PP_SEQ_DETAIL_IS_NOT_EMPTY(seq), \
			QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EXEC_R, \
			QSBOOST_PP_SEQ_FOR_EACH_DETAIL_CHECK_EMPTY_R \
			) \
		(r, macro, data, seq) \
/**/
#
# endif

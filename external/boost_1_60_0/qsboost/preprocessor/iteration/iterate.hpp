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
# ifndef QSBOOST_PREPROCESSOR_ITERATION_ITERATE_HPP
# define QSBOOST_PREPROCESSOR_ITERATION_ITERATE_HPP
#
# include <qsboost/preprocessor/arithmetic/dec.hpp>
# include <qsboost/preprocessor/arithmetic/inc.hpp>
# include <qsboost/preprocessor/array/elem.hpp>
# include <qsboost/preprocessor/array/size.hpp>
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/slot/slot.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_ITERATION_DEPTH */
#
# define QSBOOST_PP_ITERATION_DEPTH() 0
#
# /* BOOST_PP_ITERATION */
#
# define QSBOOST_PP_ITERATION() QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_, QSBOOST_PP_ITERATION_DEPTH())
#
# /* BOOST_PP_ITERATION_START && BOOST_PP_ITERATION_FINISH */
#
# define QSBOOST_PP_ITERATION_START() QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_START_, QSBOOST_PP_ITERATION_DEPTH())
# define QSBOOST_PP_ITERATION_FINISH() QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_FINISH_, QSBOOST_PP_ITERATION_DEPTH())
#
# /* BOOST_PP_ITERATION_FLAGS */
#
# define QSBOOST_PP_ITERATION_FLAGS() (QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_FLAGS_, QSBOOST_PP_ITERATION_DEPTH())())
#
# /* BOOST_PP_FRAME_ITERATION */
#
# define QSBOOST_PP_FRAME_ITERATION(i) QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_, i)
#
# /* BOOST_PP_FRAME_START && BOOST_PP_FRAME_FINISH */
#
# define QSBOOST_PP_FRAME_START(i) QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_START_, i)
# define QSBOOST_PP_FRAME_FINISH(i) QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_FINISH_, i)
#
# /* BOOST_PP_FRAME_FLAGS */
#
# define QSBOOST_PP_FRAME_FLAGS(i) (QSBOOST_PP_CAT(QSBOOST_PP_ITERATION_FLAGS_, i)())
#
# /* BOOST_PP_RELATIVE_ITERATION */
#
# define QSBOOST_PP_RELATIVE_ITERATION(i) QSBOOST_PP_CAT(QSBOOST_PP_RELATIVE_, i)(QSBOOST_PP_ITERATION_)
#
# define QSBOOST_PP_RELATIVE_0(m) QSBOOST_PP_CAT(m, QSBOOST_PP_ITERATION_DEPTH())
# define QSBOOST_PP_RELATIVE_1(m) QSBOOST_PP_CAT(m, QSBOOST_PP_DEC(QSBOOST_PP_ITERATION_DEPTH()))
# define QSBOOST_PP_RELATIVE_2(m) QSBOOST_PP_CAT(m, QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_ITERATION_DEPTH())))
# define QSBOOST_PP_RELATIVE_3(m) QSBOOST_PP_CAT(m, QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_ITERATION_DEPTH()))))
# define QSBOOST_PP_RELATIVE_4(m) QSBOOST_PP_CAT(m, QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_DEC(QSBOOST_PP_ITERATION_DEPTH())))))
#
# /* BOOST_PP_RELATIVE_START && BOOST_PP_RELATIVE_FINISH */
#
# define QSBOOST_PP_RELATIVE_START(i) QSBOOST_PP_CAT(QSBOOST_PP_RELATIVE_, i)(QSBOOST_PP_ITERATION_START_)
# define QSBOOST_PP_RELATIVE_FINISH(i) QSBOOST_PP_CAT(QSBOOST_PP_RELATIVE_, i)(QSBOOST_PP_ITERATION_FINISH_)
#
# /* BOOST_PP_RELATIVE_FLAGS */
#
# define QSBOOST_PP_RELATIVE_FLAGS(i) (QSBOOST_PP_CAT(QSBOOST_PP_RELATIVE_, i)(QSBOOST_PP_ITERATION_FLAGS_)())
#
# /* BOOST_PP_ITERATE */
#
# define QSBOOST_PP_ITERATE() QSBOOST_PP_CAT(QSBOOST_PP_ITERATE_, QSBOOST_PP_INC(QSBOOST_PP_ITERATION_DEPTH()))
#
# define QSBOOST_PP_ITERATE_1 <qsboost/preprocessor/iteration/detail/iter/forward1.hpp>
# define QSBOOST_PP_ITERATE_2 <qsboost/preprocessor/iteration/detail/iter/forward2.hpp>
# define QSBOOST_PP_ITERATE_3 <qsboost/preprocessor/iteration/detail/iter/forward3.hpp>
# define QSBOOST_PP_ITERATE_4 <qsboost/preprocessor/iteration/detail/iter/forward4.hpp>
# define QSBOOST_PP_ITERATE_5 <qsboost/preprocessor/iteration/detail/iter/forward5.hpp>
#
# endif

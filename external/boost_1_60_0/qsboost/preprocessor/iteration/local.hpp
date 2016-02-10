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
# ifndef QSBOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
# define QSBOOST_PREPROCESSOR_ITERATION_LOCAL_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/slot/slot.hpp>
# include <qsboost/preprocessor/tuple/elem.hpp>
#
# /* BOOST_PP_LOCAL_ITERATE */
#
# define QSBOOST_PP_LOCAL_ITERATE() <qsboost/preprocessor/iteration/detail/local.hpp>
#
# define QSBOOST_PP_LOCAL_C(n) (QSBOOST_PP_LOCAL_S) <= n && (QSBOOST_PP_LOCAL_F) >= n
# define QSBOOST_PP_LOCAL_R(n) (QSBOOST_PP_LOCAL_F) <= n && (QSBOOST_PP_LOCAL_S) >= n
#
# endif

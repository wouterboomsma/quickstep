# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_FACILITIES_IS_1_HPP
# define QSBOOST_PREPROCESSOR_FACILITIES_IS_1_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/facilities/is_empty.hpp>
#
# /* BOOST_PP_IS_1 */
#
# define QSBOOST_PP_IS_1(x) QSBOOST_PP_IS_EMPTY(QSBOOST_PP_CAT(QSBOOST_PP_IS_1_HELPER_, x))
# define QSBOOST_PP_IS_1_HELPER_1
#
# endif

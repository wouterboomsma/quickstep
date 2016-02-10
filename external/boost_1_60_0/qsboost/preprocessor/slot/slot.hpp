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
# ifndef QSBOOST_PREPROCESSOR_SLOT_SLOT_HPP
# define QSBOOST_PREPROCESSOR_SLOT_SLOT_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/slot/detail/def.hpp>
#
# /* BOOST_PP_ASSIGN_SLOT */
#
# define QSBOOST_PP_ASSIGN_SLOT(i) QSBOOST_PP_CAT(QSBOOST_PP_ASSIGN_SLOT_, i)
#
# define QSBOOST_PP_ASSIGN_SLOT_1 <qsboost/preprocessor/slot/detail/slot1.hpp>
# define QSBOOST_PP_ASSIGN_SLOT_2 <qsboost/preprocessor/slot/detail/slot2.hpp>
# define QSBOOST_PP_ASSIGN_SLOT_3 <qsboost/preprocessor/slot/detail/slot3.hpp>
# define QSBOOST_PP_ASSIGN_SLOT_4 <qsboost/preprocessor/slot/detail/slot4.hpp>
# define QSBOOST_PP_ASSIGN_SLOT_5 <qsboost/preprocessor/slot/detail/slot5.hpp>
#
# /* BOOST_PP_SLOT */
#
# define QSBOOST_PP_SLOT(i) QSBOOST_PP_CAT(QSBOOST_PP_SLOT_, i)()
#
# endif

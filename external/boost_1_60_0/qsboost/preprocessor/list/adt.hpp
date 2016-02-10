# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  *
#  * See http://www.boost.org for most recent version.
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# ifndef QSBOOST_PREPROCESSOR_LIST_ADT_HPP
# define QSBOOST_PREPROCESSOR_LIST_ADT_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
# include <qsboost/preprocessor/detail/is_binary.hpp>
# include <qsboost/preprocessor/logical/compl.hpp>
# include <qsboost/preprocessor/tuple/eat.hpp>
#
# /* BOOST_PP_LIST_CONS */
#
# define QSBOOST_PP_LIST_CONS(head, tail) (head, tail)
#
# /* BOOST_PP_LIST_NIL */
#
# define QSBOOST_PP_LIST_NIL QSBOOST_PP_NIL
#
# /* BOOST_PP_LIST_FIRST */
#
# define QSBOOST_PP_LIST_FIRST(list) QSBOOST_PP_LIST_FIRST_D(list)
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_LIST_FIRST_D(list) QSBOOST_PP_LIST_FIRST_I list
# else
#    define QSBOOST_PP_LIST_FIRST_D(list) QSBOOST_PP_LIST_FIRST_I ## list
# endif
#
# define QSBOOST_PP_LIST_FIRST_I(head, tail) head
#
# /* BOOST_PP_LIST_REST */
#
# define QSBOOST_PP_LIST_REST(list) QSBOOST_PP_LIST_REST_D(list)
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_LIST_REST_D(list) QSBOOST_PP_LIST_REST_I list
# else
#    define QSBOOST_PP_LIST_REST_D(list) QSBOOST_PP_LIST_REST_I ## list
# endif
#
# define QSBOOST_PP_LIST_REST_I(head, tail) tail
#
# /* BOOST_PP_LIST_IS_CONS */
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_BCC()
#    define QSBOOST_PP_LIST_IS_CONS(list) QSBOOST_PP_LIST_IS_CONS_D(list)
#    define QSBOOST_PP_LIST_IS_CONS_D(list) QSBOOST_PP_LIST_IS_CONS_ ## list
#    define QSBOOST_PP_LIST_IS_CONS_(head, tail) 1
#    define QSBOOST_PP_LIST_IS_CONS_QSBOOST_PP_NIL 0
# else
#    define QSBOOST_PP_LIST_IS_CONS(list) QSBOOST_PP_IS_BINARY(list)
# endif
#
# /* BOOST_PP_LIST_IS_NIL */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_BCC()
#    define QSBOOST_PP_LIST_IS_NIL(list) QSBOOST_PP_COMPL(QSBOOST_PP_IS_BINARY(list))
# else
#    define QSBOOST_PP_LIST_IS_NIL(list) QSBOOST_PP_COMPL(QSBOOST_PP_LIST_IS_CONS(list))
# endif
#
# endif

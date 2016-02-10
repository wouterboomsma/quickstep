# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2003.
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
# define QSBOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP
#
# include <qsboost/preprocessor/config/config.hpp>
#
# if QSBOOST_PP_VARIADICS
#
# include <qsboost/preprocessor/facilities/is_empty_variadic.hpp>
#
# else
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC() && ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
# include <qsboost/preprocessor/tuple/elem.hpp>
# include <qsboost/preprocessor/facilities/identity.hpp>
# else
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/detail/split.hpp>
# endif
#
# /* BOOST_PP_IS_EMPTY */
#
# if ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC() && ~QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MWCC()
#    define QSBOOST_PP_IS_EMPTY(x) QSBOOST_PP_IS_EMPTY_I(x QSBOOST_PP_IS_EMPTY_HELPER)
#    define QSBOOST_PP_IS_EMPTY_I(contents) QSBOOST_PP_TUPLE_ELEM(2, 1, (QSBOOST_PP_IS_EMPTY_DEF_ ## contents()))
#    define QSBOOST_PP_IS_EMPTY_DEF_QSBOOST_PP_IS_EMPTY_HELPER 1, QSBOOST_PP_IDENTITY(1)
#    define QSBOOST_PP_IS_EMPTY_HELPER() , 0
# else
#    if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_MSVC()
#        define QSBOOST_PP_IS_EMPTY(x) QSBOOST_PP_IS_EMPTY_I(QSBOOST_PP_IS_EMPTY_HELPER x ())
#        define QSBOOST_PP_IS_EMPTY_I(test) QSBOOST_PP_IS_EMPTY_II(QSBOOST_PP_SPLIT(0, QSBOOST_PP_CAT(QSBOOST_PP_IS_EMPTY_DEF_, test)))
#        define QSBOOST_PP_IS_EMPTY_II(id) id
#    else
#        define QSBOOST_PP_IS_EMPTY(x) QSBOOST_PP_IS_EMPTY_I((QSBOOST_PP_IS_EMPTY_HELPER x ()))
#        define QSBOOST_PP_IS_EMPTY_I(par) QSBOOST_PP_IS_EMPTY_II ## par
#        define QSBOOST_PP_IS_EMPTY_II(test) QSBOOST_PP_SPLIT(0, QSBOOST_PP_CAT(QSBOOST_PP_IS_EMPTY_DEF_, test))
#    endif
#    define QSBOOST_PP_IS_EMPTY_HELPER() 1
#    define QSBOOST_PP_IS_EMPTY_DEF_1 1, QSBOOST_PP_NIL
#    define QSBOOST_PP_IS_EMPTY_DEF_QSBOOST_PP_IS_EMPTY_HELPER 0, QSBOOST_PP_NIL
# endif
#
# endif /* BOOST_PP_VARIADICS */
#
# endif /* BOOST_PREPROCESSOR_FACILITIES_IS_EMPTY_HPP */

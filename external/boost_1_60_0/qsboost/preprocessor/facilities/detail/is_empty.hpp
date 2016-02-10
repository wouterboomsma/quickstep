# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2014.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
#ifndef QSBOOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP
#define QSBOOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP

#include <qsboost/preprocessor/punctuation/is_begin_parens.hpp>

#if QSBOOST_PP_VARIADICS_MSVC

# pragma warning(once:4002)

#define QSBOOST_PP_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define QSBOOST_PP_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define QSBOOST_PP_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define QSBOOST_PP_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif

#if QSBOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define QSBOOST_PP_DETAIL_IS_EMPTY_PROCESS(param) \
	QSBOOST_PP_IS_BEGIN_PARENS \
    	( \
        QSBOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C param () \
        ) \
/**/

#else

#define QSBOOST_PP_DETAIL_IS_EMPTY_PROCESS(...) \
	QSBOOST_PP_IS_BEGIN_PARENS \
        ( \
        QSBOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
/**/

#endif

#define QSBOOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define QSBOOST_PP_DETAIL_IS_EMPTY_IIF(bit) QSBOOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(QSBOOST_PP_DETAIL_IS_EMPTY_IIF_,bit)
#define QSBOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C(...) ()

#endif /* BOOST_PREPROCESSOR_DETAIL_IS_EMPTY_HPP */

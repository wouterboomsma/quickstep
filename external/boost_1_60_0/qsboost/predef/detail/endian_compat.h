/*
Copyright Rene Rivera 2013
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef QSBOOST_PREDEF_DETAIL_ENDIAN_COMPAT_H
#define QSBOOST_PREDEF_DETAIL_ENDIAN_COMPAT_H

#include <qsboost/predef/other/endian.h>

#if QSBOOST_ENDIAN_BIG_BYTE
#   define QSBOOST_BIG_ENDIAN
#   define QSBOOST_BYTE_ORDER 4321
#endif
#if QSBOOST_ENDIAN_LITTLE_BYTE
#   define QSBOOST_LITTLE_ENDIAN
#   define QSBOOST_BYTE_ORDER 1234
#endif
#if QSBOOST_ENDIAN_LITTLE_WORD
#   define QSBOOST_PDP_ENDIAN
#   define QSBOOST_BYTE_ORDER 2134
#endif

#endif

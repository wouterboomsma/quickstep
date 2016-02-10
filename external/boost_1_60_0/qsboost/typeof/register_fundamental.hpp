// Copyright (C) 2004 Arkadiy Vertleyb
// Copyright (C) 2004 Peder Holt
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_REGISTER_FUNDAMENTAL_HPP_INCLUDED
#define QSBOOST_TYPEOF_REGISTER_FUNDAMENTAL_HPP_INCLUDED

#include <qsboost/typeof/typeof.hpp>

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TYPE(unsigned char)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned short)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned int)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned long)

QSBOOST_TYPEOF_REGISTER_TYPE(signed char)
QSBOOST_TYPEOF_REGISTER_TYPE(signed short)
QSBOOST_TYPEOF_REGISTER_TYPE(signed int)
QSBOOST_TYPEOF_REGISTER_TYPE(signed long)

QSBOOST_TYPEOF_REGISTER_TYPE(bool)
QSBOOST_TYPEOF_REGISTER_TYPE(char)

QSBOOST_TYPEOF_REGISTER_TYPE(float)
QSBOOST_TYPEOF_REGISTER_TYPE(double)
QSBOOST_TYPEOF_REGISTER_TYPE(long double)

#ifndef QSBOOST_NO_INTRINSIC_WCHAR_T
// If the following line fails to compile and you're using the Intel
// compiler, see http://lists.boost.org/MailArchives/boost-users/msg06567.php,
// and define BOOST_NO_INTRINSIC_WCHAR_T on the command line.
QSBOOST_TYPEOF_REGISTER_TYPE(wchar_t)
#endif

#if (defined(QSBOOST_MSVC) && (QSBOOST_MSVC == 1200)) \
    || (defined(QSBOOST_INTEL_CXX_VERSION) && defined(_MSC_VER) && (QSBOOST_INTEL_CXX_VERSION <= 600)) \
    || (defined(__BORLANDC__) && (__BORLANDC__ == 0x600) && (_MSC_VER == 1200))
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned __int8)
QSBOOST_TYPEOF_REGISTER_TYPE(__int8)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned __int16)
QSBOOST_TYPEOF_REGISTER_TYPE(__int16)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned __int32)
QSBOOST_TYPEOF_REGISTER_TYPE(__int32)
#ifdef __BORLANDC__
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned __int64)
QSBOOST_TYPEOF_REGISTER_TYPE(__int64)
#endif
#endif

# if defined(QSBOOST_HAS_LONG_LONG)
QSBOOST_TYPEOF_REGISTER_TYPE(::qsboost::ulong_long_type)
QSBOOST_TYPEOF_REGISTER_TYPE(::qsboost::long_long_type)
#elif defined(QSBOOST_HAS_MS_INT64)
QSBOOST_TYPEOF_REGISTER_TYPE(unsigned __int64)
QSBOOST_TYPEOF_REGISTER_TYPE(__int64)
#endif

QSBOOST_TYPEOF_REGISTER_TYPE(void)

#endif//BOOST_TYPEOF_REGISTER_FUNDAMENTAL_HPP_INCLUDED

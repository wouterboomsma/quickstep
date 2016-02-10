#ifndef QSBOOSTUUID_AA15E74A856F11E08B8D93F24824019B
#define QSBOOSTUUID_AA15E74A856F11E08B8D93F24824019B
#if (__GNUC__*100+__GNUC_MINOR__>301) && !defined(QSBOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma GCC system_header
#endif
#if defined(_MSC_VER) && !defined(QSBOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(push,1)
#endif

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  boost/throw_exception.hpp
//
//  Copyright (c) 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  http://www.boost.org/libs/utility/throw_exception.html
//

#include <qsboost/detail/workaround.hpp>
#include <qsboost/config.hpp>
#include <exception>

#if !defined( QSBOOST_EXCEPTION_DISABLE ) && defined( __BORLANDC__ ) && QSBOOST_WORKAROUND( __BORLANDC__, QSBOOST_TESTED_AT(0x593) )
# define QSBOOST_EXCEPTION_DISABLE
#endif

#if !defined( QSBOOST_EXCEPTION_DISABLE ) && defined( QSBOOST_MSVC ) && QSBOOST_WORKAROUND( QSBOOST_MSVC, < 1310 )
# define QSBOOST_EXCEPTION_DISABLE
#endif

#if !defined( QSBOOST_EXCEPTION_DISABLE )
# include <qsboost/exception/exception.hpp>
#if !defined(QSBOOST_THROW_EXCEPTION_CURRENT_FUNCTION)
# include <qsboost/current_function.hpp>
# define QSBOOST_THROW_EXCEPTION_CURRENT_FUNCTION QSBOOST_CURRENT_FUNCTION
#endif
# define QSBOOST_THROW_EXCEPTION(x) ::qsboost::exception_detail::throw_exception_(x,QSBOOST_THROW_EXCEPTION_CURRENT_FUNCTION,__FILE__,__LINE__)
#else
# define QSBOOST_THROW_EXCEPTION(x) ::qsboost::throw_exception(x)
#endif

namespace qsboost
{
#ifdef QSBOOST_NO_EXCEPTIONS

void throw_exception( std::exception const & e ); // user defined

#else

inline void throw_exception_assert_compatibility( std::exception const & ) { }

template<class E> QSBOOST_NORETURN inline void throw_exception( E const & e )
{
    //All boost exceptions are required to derive from std::exception,
    //to ensure compatibility with BOOST_NO_EXCEPTIONS.
    throw_exception_assert_compatibility(e);

#ifndef QSBOOST_EXCEPTION_DISABLE
    throw enable_current_exception(enable_error_info(e));
#else
    throw e;
#endif
}

#endif

#if !defined( QSBOOST_EXCEPTION_DISABLE )
    namespace
    exception_detail
    {
        template <class E>
        QSBOOST_NORETURN
        void
        throw_exception_( E const & x, char const * current_function, char const * file, int line )
        {
            qsboost::throw_exception(
                set_info(
                    set_info(
                        set_info(
                            enable_error_info(x),
                            throw_function(current_function)),
                        throw_file(file)),
                    throw_line(line)));
        }
    }
#endif
} // namespace boost

#if defined(_MSC_VER) && !defined(QSBOOST_EXCEPTION_ENABLE_WARNINGS)
#pragma warning(pop)
#endif
#endif

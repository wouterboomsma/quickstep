#ifndef QSBOOST_CORE_DEMANGLE_HPP_INCLUDED
#define QSBOOST_CORE_DEMANGLE_HPP_INCLUDED

// core::demangle
//
// Copyright 2014 Peter Dimov
// Copyright 2014 Andrey Semashev
//
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt

#include <qsboost/config.hpp>
#include <string>

#if defined(QSBOOST_HAS_PRAGMA_ONCE)
# pragma once
#endif

#if defined( __clang__ ) && defined( __has_include )
# if __has_include(<cxxabi.h>)
#  define QSBOOST_CORE_HAS_CXXABI_H
# endif
#elif defined( __GLIBCXX__ ) || defined( __GLIBCPP__ )
# define QSBOOST_CORE_HAS_CXXABI_H
#endif

#if defined( QSBOOST_CORE_HAS_CXXABI_H )
# include <cxxabi.h>
// For some archtectures (mips, mips64, x86, x86_64) cxxabi.h in Android NDK is implemented by gabi++ library
// (https://android.googlesource.com/platform/ndk/+/master/sources/cxx-stl/gabi++/), which does not implement
// abi::__cxa_demangle(). We detect this implementation by checking the include guard here.
# if defined( __GABIXX_CXXABI_H__ )
#  undef QSBOOST_CORE_HAS_CXXABI_H
# else
#  include <cstdlib>
#  include <cstddef>
# endif
#endif

namespace qsboost
{

namespace core
{

inline char const * demangle_alloc( char const * name ) QSBOOST_NOEXCEPT;
inline void demangle_free( char const * name ) QSBOOST_NOEXCEPT;

class scoped_demangled_name
{
private:
    char const * m_p;

public:
    explicit scoped_demangled_name( char const * name ) QSBOOST_NOEXCEPT :
        m_p( demangle_alloc( name ) )
    {
    }

    ~scoped_demangled_name() QSBOOST_NOEXCEPT
    {
        demangle_free( m_p );
    }

    char const * get() const QSBOOST_NOEXCEPT
    {
        return m_p;
    }

    QSBOOST_DELETED_FUNCTION(scoped_demangled_name( scoped_demangled_name const& ))
    QSBOOST_DELETED_FUNCTION(scoped_demangled_name& operator= ( scoped_demangled_name const& ))
};


#if defined( QSBOOST_CORE_HAS_CXXABI_H )

inline char const * demangle_alloc( char const * name ) QSBOOST_NOEXCEPT
{
    int status = 0;
    std::size_t size = 0;
    return abi::__cxa_demangle( name, NULL, &size, &status );
}

inline void demangle_free( char const * name ) QSBOOST_NOEXCEPT
{
    std::free( const_cast< char* >( name ) );
}

inline std::string demangle( char const * name )
{
    scoped_demangled_name demangled_name( name );
    char const * const p = demangled_name.get();
    if( p )
    {
        return p;
    }
    else
    {
        return name;
    }
}

#else

inline char const * demangle_alloc( char const * name ) QSBOOST_NOEXCEPT
{
    return name;
}

inline void demangle_free( char const * ) QSBOOST_NOEXCEPT
{
}

inline std::string demangle( char const * name )
{
    return name;
}

#endif

} // namespace core

} // namespace boost

#undef QSBOOST_CORE_HAS_CXXABI_H

#endif // #ifndef BOOST_CORE_DEMANGLE_HPP_INCLUDED

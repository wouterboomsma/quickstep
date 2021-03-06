// Copyright (C) 2002 Brad King (brad.king@kitware.com)
//                    Douglas Gregor (gregod@cs.rpi.edu)
//
// Copyright (C) 2002, 2008, 2013 Peter Dimov
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#ifndef QSBOOST_CORE_ADDRESSOF_HPP
#define QSBOOST_CORE_ADDRESSOF_HPP

# include <qsboost/config.hpp>
# include <qsboost/detail/workaround.hpp>
# include <cstddef>

namespace qsboost
{

namespace detail
{

template<class T> struct addr_impl_ref
{
    T & v_;

    QSBOOST_FORCEINLINE addr_impl_ref( T & v ): v_( v ) {}
    QSBOOST_FORCEINLINE operator T& () const { return v_; }

private:
    addr_impl_ref & operator=(const addr_impl_ref &);
};

template<class T> struct addressof_impl
{
    static QSBOOST_FORCEINLINE T * f( T & v, long )
    {
        return reinterpret_cast<T*>(
            &const_cast<char&>(reinterpret_cast<const volatile char &>(v)));
    }

    static QSBOOST_FORCEINLINE T * f( T * v, int )
    {
        return v;
    }
};

#if !defined( QSBOOST_NO_CXX11_NULLPTR )

#if !defined( QSBOOST_NO_CXX11_DECLTYPE ) && ( ( defined( __clang__ ) && !defined( _LIBCPP_VERSION ) ) || defined( __INTEL_COMPILER ) )

    typedef decltype(nullptr) addr_nullptr_t;

#else

    typedef std::nullptr_t addr_nullptr_t;

#endif

template<> struct addressof_impl< addr_nullptr_t >
{
    typedef addr_nullptr_t T;

    static QSBOOST_FORCEINLINE T * f( T & v, int )
    {
        return &v;
    }
};

template<> struct addressof_impl< addr_nullptr_t const >
{
    typedef addr_nullptr_t const T;

    static QSBOOST_FORCEINLINE T * f( T & v, int )
    {
        return &v;
    }
};

template<> struct addressof_impl< addr_nullptr_t volatile >
{
    typedef addr_nullptr_t volatile T;

    static QSBOOST_FORCEINLINE T * f( T & v, int )
    {
        return &v;
    }
};

template<> struct addressof_impl< addr_nullptr_t const volatile >
{
    typedef addr_nullptr_t const volatile T;

    static QSBOOST_FORCEINLINE T * f( T & v, int )
    {
        return &v;
    }
};

#endif

} // namespace detail

template<class T>
QSBOOST_FORCEINLINE
T * addressof( T & v )
{
#if (defined( __BORLANDC__ ) && QSBOOST_WORKAROUND( __BORLANDC__, QSBOOST_TESTED_AT( 0x610 ) ) ) || (defined(__SUNPRO_CC) && QSBOOST_WORKAROUND(__SUNPRO_CC, <= 0x5120))

    return qsboost::detail::addressof_impl<T>::f( v, 0 );

#else

    return qsboost::detail::addressof_impl<T>::f( qsboost::detail::addr_impl_ref<T>( v ), 0 );

#endif
}

#if defined( __SUNPRO_CC ) && QSBOOST_WORKAROUND( __SUNPRO_CC, QSBOOST_TESTED_AT( 0x590 ) )

namespace detail
{

template<class T> struct addressof_addp
{
    typedef T * type;
};

} // namespace detail

template< class T, std::size_t N >
QSBOOST_FORCEINLINE
typename detail::addressof_addp< T[N] >::type addressof( T (&t)[N] )
{
    return &t;
}

#endif

// Borland doesn't like casting an array reference to a char reference
// but these overloads work around the problem.
#if defined( __BORLANDC__ ) && QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x564))
template<typename T,std::size_t N>
QSBOOST_FORCEINLINE
T (*addressof(T (&t)[N]))[N]
{
   return reinterpret_cast<T(*)[N]>(&t);
}

template<typename T,std::size_t N>
QSBOOST_FORCEINLINE
const T (*addressof(const T (&t)[N]))[N]
{
   return reinterpret_cast<const T(*)[N]>(&t);
}
#endif

} // namespace boost

#endif // BOOST_CORE_ADDRESSOF_HPP

#ifndef QSBOOST_SMART_PTR_DETAIL_SPINLOCK_W32_HPP_INCLUDED
#define QSBOOST_SMART_PTR_DETAIL_SPINLOCK_W32_HPP_INCLUDED

// MS compatible compilers support #pragma once

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

//
//  Copyright (c) 2008 Peter Dimov
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//

#include <qsboost/smart_ptr/detail/sp_interlocked.hpp>
#include <qsboost/smart_ptr/detail/yield_k.hpp>

// BOOST_COMPILER_FENCE

#if defined(__INTEL_COMPILER)

#define QSBOOST_COMPILER_FENCE __memory_barrier();

#elif defined( _MSC_VER ) && _MSC_VER >= 1310

extern "C" void _ReadWriteBarrier();
#pragma intrinsic( _ReadWriteBarrier )

#define QSBOOST_COMPILER_FENCE _ReadWriteBarrier();

#elif defined(__GNUC__)

#define QSBOOST_COMPILER_FENCE __asm__ __volatile__( "" : : : "memory" );

#else

#define QSBOOST_COMPILER_FENCE

#endif

//

namespace qsboost
{

namespace detail
{

class spinlock
{
public:

    long v_;

public:

    bool try_lock()
    {
        long r = QSBOOST_SP_INTERLOCKED_EXCHANGE( &v_, 1 );

        QSBOOST_COMPILER_FENCE

        return r == 0;
    }

    void lock()
    {
        for( unsigned k = 0; !try_lock(); ++k )
        {
            qsboost::detail::yield( k );
        }
    }

    void unlock()
    {
        QSBOOST_COMPILER_FENCE
        *const_cast< long volatile* >( &v_ ) = 0;
    }

public:

    class scoped_lock
    {
    private:

        spinlock & sp_;

        scoped_lock( scoped_lock const & );
        scoped_lock & operator=( scoped_lock const & );

    public:

        explicit scoped_lock( spinlock & sp ): sp_( sp )
        {
            sp.lock();
        }

        ~scoped_lock()
        {
            sp_.unlock();
        }
    };
};

} // namespace detail
} // namespace boost

#define QSBOOST_DETAIL_SPINLOCK_INIT {0}

#endif // #ifndef BOOST_SMART_PTR_DETAIL_SPINLOCK_W32_HPP_INCLUDED

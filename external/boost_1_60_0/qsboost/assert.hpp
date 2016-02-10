//
//  boost/assert.hpp - BOOST_ASSERT(expr)
//                     BOOST_ASSERT_MSG(expr, msg)
//                     BOOST_VERIFY(expr)
//                     BOOST_VERIFY_MSG(expr, msg)
//                     BOOST_ASSERT_IS_VOID
//
//  Copyright (c) 2001, 2002 Peter Dimov and Multi Media Ltd.
//  Copyright (c) 2007, 2014 Peter Dimov
//  Copyright (c) Beman Dawes 2011
//  Copyright (c) 2015 Ion Gaztanaga
//
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//  Note: There are no include guards. This is intentional.
//
//  See http://www.boost.org/libs/assert/assert.html for documentation.
//

//
// Stop inspect complaining about use of 'assert':
//
// boostinspect:naassert_macro
//

//
// BOOST_ASSERT, BOOST_ASSERT_MSG, BOOST_ASSERT_IS_VOID
//

#undef QSBOOST_ASSERT
#undef QSBOOST_ASSERT_MSG
#undef QSBOOST_ASSERT_IS_VOID

#if defined(QSBOOST_DISABLE_ASSERTS) || ( defined(QSBOOST_ENABLE_ASSERT_DEBUG_HANDLER) && defined(NDEBUG) )

# define QSBOOST_ASSERT(expr) ((void)0)
# define QSBOOST_ASSERT_MSG(expr, msg) ((void)0)
# define QSBOOST_ASSERT_IS_VOID

#elif defined(QSBOOST_ENABLE_ASSERT_HANDLER) || ( defined(QSBOOST_ENABLE_ASSERT_DEBUG_HANDLER) && !defined(NDEBUG) )

#include <qsboost/config.hpp> // for BOOST_LIKELY
#include <qsboost/current_function.hpp>

namespace qsboost
{
    void assertion_failed(char const * expr, char const * function, char const * file, long line); // user defined
    void assertion_failed_msg(char const * expr, char const * msg, char const * function, char const * file, long line); // user defined
} // namespace boost

#define QSBOOST_ASSERT(expr) (QSBOOST_LIKELY(!!(expr))? ((void)0): ::qsboost::assertion_failed(#expr, QSBOOST_CURRENT_FUNCTION, __FILE__, __LINE__))
#define QSBOOST_ASSERT_MSG(expr, msg) (QSBOOST_LIKELY(!!(expr))? ((void)0): ::qsboost::assertion_failed_msg(#expr, msg, QSBOOST_CURRENT_FUNCTION, __FILE__, __LINE__))

#else

# include <assert.h> // .h to support old libraries w/o <cassert> - effect is the same

# define QSBOOST_ASSERT(expr) assert(expr)
# define QSBOOST_ASSERT_MSG(expr, msg) assert((expr)&&(msg))
#if defined(NDEBUG)
# define QSBOOST_ASSERT_IS_VOID
#endif

#endif

//
// BOOST_VERIFY, BOOST_VERIFY_MSG
//

#undef QSBOOST_VERIFY
#undef QSBOOST_VERIFY_MSG

#if defined(QSBOOST_DISABLE_ASSERTS) || ( !defined(QSBOOST_ENABLE_ASSERT_HANDLER) && defined(NDEBUG) )

# define QSBOOST_VERIFY(expr) ((void)(expr))
# define QSBOOST_VERIFY_MSG(expr, msg) ((void)(expr))

#else

# define QSBOOST_VERIFY(expr) QSBOOST_ASSERT(expr)
# define QSBOOST_VERIFY_MSG(expr, msg) QSBOOST_ASSERT_MSG(expr,msg)

#endif

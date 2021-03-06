/*
 * Distributed under the Boost Software License, Version 1.0.(See accompanying 
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)
 * 
 * See http://www.boost.org/libs/iostreams for documentation.

 * File:        boost/iostreams/detail/execute.hpp
 * Date:        Thu Dec 06 13:21:54 MST 2007
 * Copyright:   2007-2008 CodeRage, LLC
 * Author:      Jonathan Turkanis
 * Contact:     turkanis at coderage dot com

 * Defines the overloaded function template 
 * boost::iostreams::detail::execute_all() and the function template 
 * boost::iostreams::detail::execute_foreach().
 *
 * execute_all() invokes a primary operation and performs a sequence of cleanup 
 * operations, returning the result of the primary operation if no exceptions
 * are thrown. If one of the operations throws an exception, performs the
 * remaining operations and rethrows the initial exception.
 *
 * execute_foreach() is a variant of std::foreach which invokes a function 
 * object for each item in a sequence, catching all execptions and rethrowing
 * the first caught exception after the function object has been invoked on each
 * item.
 */

#ifndef QSBOOST_IOSTREAMS_DETAIL_EXECUTE_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_EXECUTE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/config/limits.hpp>   // MAX_EXECUTE_ARITY
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/iteration/local.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/preprocessor/punctuation/comma_if.hpp>
#include <qsboost/utility/result_of.hpp>

namespace qsboost { namespace iostreams { namespace detail {

// Helper for class template execute_traits.
template<typename Result>
struct execute_traits_impl {
    typedef Result result_type;
    template<typename Op>
    static Result execute(Op op) { return op(); }
};

// Specialization for void return. For simplicity, execute() returns int 
// for operations returning void. This could be avoided with additional work.
template<>
struct execute_traits_impl<void> {
    typedef int result_type;
    template<typename Op>
    static int execute(Op op) { op(); return 0; }
};

// Deduces the result type of Op and allows uniform treatment of operations 
// returning void and non-void.
template< typename Op, 
          typename Result = // VC6.5 workaround.
              #if !defined(QSBOOST_NO_RESULT_OF) && \
                  !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x592))
                  typename qsboost::result_of<Op()>::type
              #else
                  QSBOOST_DEDUCED_TYPENAME Op::result_type
              #endif
          >
struct execute_traits 
    : execute_traits_impl<Result>
    { };

// Implementation with no cleanup operations.
template<typename Op>
typename execute_traits<Op>::result_type 
execute_all(Op op) 
{ 
    return execute_traits<Op>::execute(op);
}

// Implementation with one or more cleanup operations
#define QSBOOST_PP_LOCAL_MACRO(n) \
   template<typename Op, QSBOOST_PP_ENUM_PARAMS(n, typename C)> \
   typename execute_traits<Op>::result_type \
   execute_all(Op op, QSBOOST_PP_ENUM_BINARY_PARAMS(n, C, c)) \
   { \
       typename execute_traits<Op>::result_type r; \
       try { \
           r = qsboost::iostreams::detail::execute_all( \
                   op QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(n)) \
                   QSBOOST_PP_ENUM_PARAMS(QSBOOST_PP_DEC(n), c) \
               ); \
       } catch (...) { \
           try { \
               QSBOOST_PP_CAT(c, QSBOOST_PP_DEC(n))(); \
           } catch (...) { } \
           throw; \
       } \
       QSBOOST_PP_CAT(c, QSBOOST_PP_DEC(n))(); \
       return r; \
   } \
   /**/

#define QSBOOST_PP_LOCAL_LIMITS (1, QSBOOST_IOSTREAMS_MAX_EXECUTE_ARITY)
#include QSBOOST_PP_LOCAL_ITERATE()
#undef QSBOOST_PP_LOCAL_MACRO

template<class InIt, class Op>
Op execute_foreach(InIt first, InIt last, Op op)
{
    if (first == last)
        return op;
    try {
        op(*first);
    } catch (...) {
        try {
            ++first;
            qsboost::iostreams::detail::execute_foreach(first, last, op);
        } catch (...) { }
        throw;
    }
    ++first;
    return qsboost::iostreams::detail::execute_foreach(first, last, op);
}

} } } // End namespaces detail, iostreams, boost.

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_EXECUTE_HPP_INCLUDED

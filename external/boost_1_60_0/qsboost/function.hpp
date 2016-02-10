// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/function

// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

#include <functional> // unary_function, binary_function

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/detail/workaround.hpp>

#ifndef QSBOOST_FUNCTION_MAX_ARGS
#  define QSBOOST_FUNCTION_MAX_ARGS 10
#endif // BOOST_FUNCTION_MAX_ARGS

// Include the prologue here so that the use of file-level iteration
// in anything that may be included by function_template.hpp doesn't break
#include <qsboost/function/detail/prologue.hpp>

// Older Visual Age C++ version do not handle the file iteration well
#if QSBOOST_WORKAROUND(__IBMCPP__, >= 500) && QSBOOST_WORKAROUND(__IBMCPP__, < 800)
#  if QSBOOST_FUNCTION_MAX_ARGS >= 0
#    include <qsboost/function/function0.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 1
#    include <qsboost/function/function1.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 2
#    include <qsboost/function/function2.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 3
#    include <qsboost/function/function3.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 4
#    include <qsboost/function/function4.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 5
#    include <qsboost/function/function5.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 6
#    include <qsboost/function/function6.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 7
#    include <qsboost/function/function7.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 8
#    include <qsboost/function/function8.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 9
#    include <qsboost/function/function9.hpp>
#  endif
#  if QSBOOST_FUNCTION_MAX_ARGS >= 10
#    include <qsboost/function/function10.hpp>
#  endif
#else
// What is the '3' for?
#  define QSBOOST_PP_ITERATION_PARAMS_1 (3,(0,QSBOOST_FUNCTION_MAX_ARGS,<qsboost/function/detail/function_iterate.hpp>))
#  include QSBOOST_PP_ITERATE()
#  undef QSBOOST_PP_ITERATION_PARAMS_1
#endif

//  Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_MATH_TOOLS_REAL_CAST_HPP
#define QSBOOST_MATH_TOOLS_REAL_CAST_HPP

#include <qsboost/math/tools/config.hpp>

#ifdef _MSC_VER
#pragma once
#endif

namespace qsboost{ namespace math
{
  namespace tools
  {
    template <class To, class T>
    inline QSBOOST_MATH_CONSTEXPR To real_cast(T t) QSBOOST_NOEXCEPT_IF(QSBOOST_MATH_IS_FLOAT(T) && QSBOOST_MATH_IS_FLOAT(To))
    {
       return static_cast<To>(t);
    }
  } // namespace tools
} // namespace math
} // namespace boost

#endif // BOOST_MATH_TOOLS_REAL_CAST_HPP




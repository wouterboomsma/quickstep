// (C) Copyright David Abrahams 2001.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPE_DWA20010120_HPP
# define QSBOOST_TYPE_DWA20010120_HPP

namespace qsboost {

  // Just a simple "type envelope". Useful in various contexts, mostly to work
  // around some MSVC deficiencies.
  template <class T>
  struct type {};

}

#endif // BOOST_TYPE_DWA20010120_HPP

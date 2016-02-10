// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_DIMENSIONLESS_UNIT_HPP
#define QSBOOST_UNITS_DIMENSIONLESS_UNIT_HPP

///
/// \file
/// \brief Utility class to simplify construction of dimensionless units in a system.
///

#include <qsboost/units/dimensionless_type.hpp>
#include <qsboost/units/unit.hpp>

namespace qsboost {

namespace units {

/// Utility class to simplify construction of dimensionless units in a system.
template<class System>
struct dimensionless_unit
{
    typedef unit<dimensionless_type,System> type;
};

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_DIMENSIONLESS_UNIT_HPP

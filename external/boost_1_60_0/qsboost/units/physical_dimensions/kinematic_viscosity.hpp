// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_KINEMATIC_VISCOSITY_DERIVED_DIMENSION_HPP
#define QSBOOST_UNITS_KINEMATIC_VISCOSITY_DERIVED_DIMENSION_HPP

#include <qsboost/units/derived_dimension.hpp>
#include <qsboost/units/physical_dimensions/length.hpp>
#include <qsboost/units/physical_dimensions/time.hpp>

namespace qsboost {

namespace units {

/// derived dimension for kinematic viscosity : L^2 T^-1
typedef derived_dimension<length_base_dimension,2,
                          time_base_dimension,-1>::type kinematic_viscosity_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_KINEMATIC_VISCOSITY_DERIVED_DIMENSION_HPP

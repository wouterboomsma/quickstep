// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_MASS_DENSITY_HPP
#define QSBOOST_UNITS_SI_MASS_DENSITY_HPP

#include <qsboost/units/systems/si/base.hpp>
#include <qsboost/units/physical_dimensions/mass_density.hpp>

namespace qsboost {

namespace units { 

namespace si {

typedef unit<mass_density_dimension,si::system>  mass_density;

QSBOOST_UNITS_STATIC_CONSTANT(kilogram_per_cubic_meter,mass_density);
QSBOOST_UNITS_STATIC_CONSTANT(kilograms_per_cubic_meter,mass_density);
QSBOOST_UNITS_STATIC_CONSTANT(kilogramme_per_cubic_metre,mass_density);
QSBOOST_UNITS_STATIC_CONSTANT(kilogrammes_per_cubic_metre,mass_density);

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MASS_DENSITY_HPP

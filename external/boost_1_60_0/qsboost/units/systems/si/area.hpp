// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_AREA_HPP
#define QSBOOST_UNITS_SI_AREA_HPP

#include <qsboost/units/systems/si/base.hpp>
#include <qsboost/units/physical_dimensions/area.hpp>

namespace qsboost {

namespace units { 

namespace si {

typedef unit<area_dimension,si::system>      area;
    
QSBOOST_UNITS_STATIC_CONSTANT(square_meter,area);
QSBOOST_UNITS_STATIC_CONSTANT(square_meters,area);
QSBOOST_UNITS_STATIC_CONSTANT(square_metre,area);
QSBOOST_UNITS_STATIC_CONSTANT(square_metres,area);

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_AREA_HPP

// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_CGS_BIOT_BASE_UNIT_HPP
#define QSBOOST_UNITS_CGS_BIOT_BASE_UNIT_HPP

#include <qsboost/units/scaled_base_unit.hpp>
#include <qsboost/units/base_units/si/ampere.hpp>

namespace qsboost {

namespace units {

namespace cgs {

typedef scaled_base_unit<qsboost::units::si::ampere_base_unit, scale<10, static_rational<-1> > > biot_base_unit;

} // namespace cgs 

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_BIOT_BASE_UNIT_HPP

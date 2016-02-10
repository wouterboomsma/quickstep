// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_METER_BASE_UNIT_HPP
#define QSBOOST_UNITS_SI_METER_BASE_UNIT_HPP

#include <string>

#include <qsboost/units/config.hpp>
#include <qsboost/units/base_unit.hpp>
#include <qsboost/units/scaled_base_unit.hpp>
#include <qsboost/units/physical_dimensions/length.hpp>

namespace qsboost {

namespace units {

namespace si {

struct meter_base_unit : public base_unit<meter_base_unit, length_dimension, -9>
{
    static std::string name()   { return("meter"); }
    static std::string symbol() { return("m"); }
};

} // namespace si

} // namespace units

} // namespace boost

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TYPE(qsboost::units::si::meter_base_unit)

#endif

//#include <boost/units/base_units/detail/conversions.hpp>

#endif // BOOST_UNITS_SI_METER_BASE_UNIT_HPP


// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP
#define QSBOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP

#include <qsboost/units/config.hpp>
#include <qsboost/units/base_dimension.hpp>

namespace qsboost {

namespace units { 

/// base dimension of solid angle
struct solid_angle_base_dimension : 
    qsboost::units::base_dimension<solid_angle_base_dimension,-1> 
{ };               

} // namespace units

} // namespace boost

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TYPE(qsboost::units::solid_angle_base_dimension)

#endif

namespace qsboost {

namespace units {

/// base dimension of solid angle (QS)
typedef solid_angle_base_dimension::dimension_type    solid_angle_dimension;

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SOLID_ANGLE_BASE_DIMENSION_HPP

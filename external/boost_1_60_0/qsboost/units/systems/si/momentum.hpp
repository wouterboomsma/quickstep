// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_MOMENTUM_HPP
#define QSBOOST_UNITS_SI_MOMENTUM_HPP

#include <qsboost/units/systems/si/base.hpp>
#include <qsboost/units/physical_dimensions/momentum.hpp>

namespace qsboost {

namespace units { 

namespace si {

typedef unit<momentum_dimension,si::system>  momentum;

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_MOMENTUM_HPP

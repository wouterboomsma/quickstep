// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP
#define QSBOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP

#include <qsboost/units/derived_dimension.hpp>
#include <qsboost/units/systems/si/base.hpp>

namespace qsboost {

namespace units { 

namespace si {

/// catalytic activity : T^-1 A^1
typedef derived_dimension<time_base_dimension,-1,amount_base_dimension,1>::type                             catalytic_activity_dim;    

typedef unit<si::catalytic_activity_dim,si::system>                                    catalytic_activity;

QSBOOST_UNITS_STATIC_CONSTANT(katal,catalytic_activity);
QSBOOST_UNITS_STATIC_CONSTANT(katals,catalytic_activity);

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_CATALYTIC_ACTIVITY_HPP

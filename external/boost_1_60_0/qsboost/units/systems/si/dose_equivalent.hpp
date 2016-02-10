// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_DOSE_EQUIVALENT_HPP
#define QSBOOST_UNITS_SI_DOSE_EQUIVALENT_HPP

#include <qsboost/units/systems/si/base.hpp>
#include <qsboost/units/physical_dimensions/dose_equivalent.hpp>

namespace qsboost {

namespace units { 

namespace si {

typedef unit<dose_equivalent_dimension,si::system>     dose_equivalent;
    
QSBOOST_UNITS_STATIC_CONSTANT(sievert,dose_equivalent);  
QSBOOST_UNITS_STATIC_CONSTANT(sieverts,dose_equivalent); 

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_DOSE_EQUIVALENT_HPP

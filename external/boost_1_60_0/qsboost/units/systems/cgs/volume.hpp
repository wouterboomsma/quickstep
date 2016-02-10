// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_CGS_VOLUME_HPP
#define QSBOOST_UNITS_CGS_VOLUME_HPP

#include <qsboost/units/systems/cgs/base.hpp>
#include <qsboost/units/physical_dimensions/volume.hpp>

namespace qsboost {

namespace units { 

namespace cgs {

typedef unit<volume_dimension,cgs::system>   volume;
    
QSBOOST_UNITS_STATIC_CONSTANT(cubic_centimeter,volume);   
QSBOOST_UNITS_STATIC_CONSTANT(cubic_centimeters,volume);  
QSBOOST_UNITS_STATIC_CONSTANT(cubic_centimetre,volume);   
QSBOOST_UNITS_STATIC_CONSTANT(cubic_centimetres,volume);  

} // namespace cgs

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_VOLUME_HPP

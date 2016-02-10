// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_CGS_MASS_HPP
#define QSBOOST_UNITS_CGS_MASS_HPP

#include <qsboost/units/systems/cgs/base.hpp>

namespace qsboost {

namespace units { 

namespace cgs {

typedef unit<mass_dimension,cgs::system>     mass;
    
QSBOOST_UNITS_STATIC_CONSTANT(gram,mass); 
QSBOOST_UNITS_STATIC_CONSTANT(grams,mass);    
QSBOOST_UNITS_STATIC_CONSTANT(gramme,mass);   
QSBOOST_UNITS_STATIC_CONSTANT(grammes,mass);  


} // namespace cgs

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_CGS_MASS_HPP

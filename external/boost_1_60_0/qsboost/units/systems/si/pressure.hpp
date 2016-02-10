// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SI_PRESSURE_HPP
#define QSBOOST_UNITS_SI_PRESSURE_HPP

#include <qsboost/units/systems/si/base.hpp>
#include <qsboost/units/physical_dimensions/pressure.hpp>

namespace qsboost {

namespace units { 

namespace si {

typedef unit<pressure_dimension,si::system>      pressure;

// windef.h #defines pascal on Metrowerks compilers
#if defined(__MWERKS__)
   #if !__option(only_std_keywords)
       #define QSBOOST_UNITS_NO_PASCAL 1
   #elif defined(pascal)
       #define QSBOOST_UNITS_NO_PASCAL 1
   #endif
#elif defined(pascal)
   #define QSBOOST_UNITS_NO_PASCAL 1
#elif QSBOOST_MSVC
   #define QSBOOST_UNITS_NO_PASCAL 1
#endif

#ifndef QSBOOST_UNITS_NO_PASCAL
QSBOOST_UNITS_STATIC_CONSTANT(pascal,pressure);   
#endif
QSBOOST_UNITS_STATIC_CONSTANT(pascals,pressure);  

} // namespace si

} // namespace units

} // namespace boost

#endif // BOOST_UNITS_SI_PRESSURE_HPP

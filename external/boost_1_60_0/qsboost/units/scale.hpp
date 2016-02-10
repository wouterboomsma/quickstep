// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_SCALE_HPP_INCLUDED
#define QSBOOST_UNITS_SCALE_HPP_INCLUDED

///
/// \file
/// \brief 10^3 Engineering & 2^10 binary scaling factors for autoprefixing.
/// \details
///

#include <string>

#include <qsboost/units/config.hpp>
#include <qsboost/units/static_rational.hpp>
#include <qsboost/units/units_fwd.hpp>
#include <qsboost/units/detail/one.hpp>
#include <qsboost/units/detail/static_rational_power.hpp>

namespace qsboost {

namespace units {

template<class S, class Scale>
struct scaled_base_unit;

/// class representing a scaling factor such as 10^3
/// The exponent must be a static rational.
template<long Base, class Exponent>
struct scale
{
    static const long base = Base;
    typedef Exponent exponent;
    typedef double value_type;
    static value_type value() { return(detail::static_rational_power<Exponent>(static_cast<double>(base))); }
    // These need to be defined in specializations for
    // printing to work.
    // static std::string name();
    // static std::string symbol();
};

template<long Base, class Exponent>
const long scale<Base, Exponent>::base;

/// INTERNAL ONLY
template<long Base>
struct scale<Base, static_rational<0> >
{
    static const long base = Base;
    typedef static_rational<0> exponent;
    typedef one value_type;
    static one value() { one result; return(result); }
    static std::string name() { return(""); }
    static std::string symbol() { return(""); }
};

template<long Base>
const long scale<Base, static_rational<0> >::base;

template<long Base,class Exponent>
std::string symbol_string(const scale<Base,Exponent>&)
{
    return scale<Base,Exponent>::symbol();
}

template<long Base,class Exponent>
std::string name_string(const scale<Base,Exponent>&)
{
    return scale<Base,Exponent>::name();
}

#ifndef QSBOOST_UNITS_DOXYGEN

#define QSBOOST_UNITS_SCALE_SPECIALIZATION(base_,exponent_,val_,name_,symbol_) \
template<>                                                                   \
struct scale<base_, exponent_ >                                              \
{                                                                            \
    static const long base = base_;                                          \
    typedef exponent_ exponent;                                              \
    typedef double value_type;                                               \
    static value_type value()   { return(val_); }                            \
    static std::string name()   { return(#name_); }                          \
    static std::string symbol() { return(#symbol_); }                        \
}

#define QSBOOST_UNITS_SCALE_DEF(exponent_,value_,name_,symbol_)                 \
QSBOOST_UNITS_SCALE_SPECIALIZATION(10,static_rational<exponent_>,value_, name_, symbol_)

QSBOOST_UNITS_SCALE_DEF(-24, 1e-24, yocto, y);
QSBOOST_UNITS_SCALE_DEF(-21, 1e-21, zepto, z);
QSBOOST_UNITS_SCALE_DEF(-18, 1e-18, atto, a);
QSBOOST_UNITS_SCALE_DEF(-15, 1e-15, femto, f);
QSBOOST_UNITS_SCALE_DEF(-12, 1e-12, pico, p);
QSBOOST_UNITS_SCALE_DEF(-9, 1e-9, nano, n);
QSBOOST_UNITS_SCALE_DEF(-6, 1e-6, micro, u);
QSBOOST_UNITS_SCALE_DEF(-3, 1e-3, milli, m);
QSBOOST_UNITS_SCALE_DEF(-2, 1e-2, centi, c);
QSBOOST_UNITS_SCALE_DEF(-1, 1e-1, deci, d);

QSBOOST_UNITS_SCALE_DEF(1, 1e1, deka, da);
QSBOOST_UNITS_SCALE_DEF(2, 1e2, hecto, h);
QSBOOST_UNITS_SCALE_DEF(3, 1e3, kilo, k);
QSBOOST_UNITS_SCALE_DEF(6, 1e6, mega, M);
QSBOOST_UNITS_SCALE_DEF(9, 1e9, giga, G);
QSBOOST_UNITS_SCALE_DEF(12, 1e12, tera, T);
QSBOOST_UNITS_SCALE_DEF(15, 1e15, peta, P);
QSBOOST_UNITS_SCALE_DEF(18, 1e18, exa, E);
QSBOOST_UNITS_SCALE_DEF(21, 1e21, zetta, Z);
QSBOOST_UNITS_SCALE_DEF(24, 1e24, yotta, Y);

QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<10>, 1024.0, kibi, Ki);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<20>, 1048576.0, mebi, Mi);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<30>, 1073741824.0, gibi, Gi);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<40>, 1099511627776.0, tebi, Ti);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<50>, 1125899906842624.0, pebi, Pi);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<60>, 1152921504606846976.0, exbi, Ei);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<70>, 1180591620717411303424.0, zebi, Zi);
QSBOOST_UNITS_SCALE_SPECIALIZATION(2, static_rational<80>, 1208925819614629174706176.0, yobi, Yi);

#undef QSBOOST_UNITS_SCALE_DEF
#undef QSBOOST_UNITS_SCALE_SPECIALIZATION

#endif

} // namespace units

} // namespace boost

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TEMPLATE(qsboost::units::scale, (long)(class))

#endif

#endif

#ifndef QUICKSTEP_UNITS_H
#define QUICKSTEP_UNITS_H

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/io.hpp>
#include <boost/units/base_units/metric/angstrom.hpp>

namespace quickstep {

// mass
struct dalton_base_unit :
        boost::units::base_unit<dalton_base_unit, boost::units::mass_dimension, 2>  {
    static std::string name() { return "Dalton"; }
    static std::string symbol() { return "Da"; }
};

typedef dalton_base_unit::unit_type dalton_unit;
BOOST_UNITS_STATIC_CONSTANT(dalton, dalton_unit);
BOOST_UNITS_STATIC_CONSTANT(daltons, dalton_unit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, dalton_unit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, dalton_unit);
typedef boost::units::quantity<dalton_unit> mass_t;



// position
typedef boost::units::metric::angstrom_base_unit::unit_type angstrom_unit;
BOOST_UNITS_STATIC_CONSTANT(angstrom, angstrom_unit);
typedef boost::units::quantity<angstrom_unit> coordinate_t;

typedef boost::units::scaled_base_unit<
    boost::units::si::meter_base_unit,
    boost::units::scale<10, boost::units::static_rational<-9> > > nanometer_base_unit;
typedef nanometer_base_unit::unit_type nanometer_unit;
BOOST_UNITS_STATIC_CONSTANT(nanometer, nanometer_unit);

//// Operators for mixed nanometer, angstrom
//bool operator<(const boost::units::quantity<angstrom_unit> value1, const boost::units::quantity<nanometer_unit> value2) {
//    return value1 < (boost::units::quantity<angstrom_unit>)value2;
//}

}

#endif

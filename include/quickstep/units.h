#ifndef QUICKSTEP_UNITS_H
#define QUICKSTEP_UNITS_H

#include <boost/units/conversion.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/io.hpp>
#include <boost/units/base_units/metric/angstrom.hpp>
#include <boost/units/conversion.hpp>

namespace quickstep {

namespace units {

////////////
// Length //
////////////

// Nanometer
typedef boost::units::scaled_base_unit<
        boost::units::si::meter_base_unit,
        boost::units::scale<10, boost::units::static_rational<-9> > > NanometerBaseUnit;

// Angstrom
typedef boost::units::metric::angstrom_base_unit AngstromBaseUnit;


//////////
// Mass //
//////////

// Dalton
struct DaltonBaseUnit :
        boost::units::base_unit<DaltonBaseUnit, boost::units::mass_dimension, 2> {
    static std::string name() {
        return "Dalton";
    }

    static std::string symbol() {
        return "Da";
    }
};


//////////
// time //
//////////

// Picosecond
typedef boost::units::scaled_base_unit<
        boost::units::si::second_base_unit,
        boost::units::scale<10, boost::units::static_rational < -12> > > PicosecondBaseUnit;


// Define Quantity types
typedef NanometerBaseUnit::unit_type NanometerUnit;
BOOST_UNITS_STATIC_CONSTANT(nanometer, NanometerUnit);
BOOST_UNITS_STATIC_CONSTANT(nanometers, NanometerUnit);
BOOST_UNITS_STATIC_CONSTANT(nm, NanometerUnit);
typedef boost::units::quantity<NanometerUnit> LengthNm;

typedef AngstromBaseUnit::unit_type AngstromUnit;
BOOST_UNITS_STATIC_CONSTANT(angstrom, AngstromUnit);
typedef boost::units::quantity<AngstromUnit> LengthAA;

typedef DaltonBaseUnit::unit_type DaltonUnit;
BOOST_UNITS_STATIC_CONSTANT(dalton, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(daltons, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, DaltonUnit);
typedef boost::units::quantity<DaltonUnit> MassDa;

typedef PicosecondBaseUnit::unit_type PicosecondUnit;
BOOST_UNITS_STATIC_CONSTANT(picosecond, PicosecondUnit);
BOOST_UNITS_STATIC_CONSTANT(picoseconds, PicosecondUnit);
typedef boost::units::quantity<PicosecondUnit> TimePs;




// position

//// Operators for mixed nanometer, angstrom
//bool operator<(const boost::units::quantity<angstrom_unit> value1, const boost::units::quantity<nanometer_unit> value2) {
//    return value1 < (boost::units::quantity<angstrom_unit>)value2;
//}

}
}

// Conversions
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(
        quickstep::units::DaltonBaseUnit,
        si::kilogram_base_unit,
        double, 1.6605388628e-27);

#endif

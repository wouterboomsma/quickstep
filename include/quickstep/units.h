#ifndef QUICKSTEP_UNITS_H
#define QUICKSTEP_UNITS_H

#include <boost/units/systems/si.hpp>
//#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/base_units/metric/angstrom.hpp>
//#include <boost/units/conversion.hpp>
#include <boost/units/systems/si/codata/physico-chemical_constants.hpp>
#include <Eigen/Quantity>
//#include <boost/units/systems/cgs.hpp>
//#include <boost/units/systems/cgs/mass.hpp>
//#include <boost/units/quantity.hpp>
//#include <boost/units/detail/dimension_impl.hpp>
//#include <boost/units/detail/unscale.hpp>
//#include <boost/units/heterogeneous_system.hpp>
//#include <boost/units/systems/si/prefixes.hpp>
//#include <boost/units/unit.hpp>
//#include <boost/units/scaled_base_unit.hpp>

namespace quickstep {

namespace units {

////////////
// Length //
////////////

// Nanometer
typedef boost::units::scaled_base_unit<
        boost::units::si::meter_base_unit,
        boost::units::scale<10, boost::units::static_rational<-9> > > NanometerBaseUnit;
typedef NanometerBaseUnit::unit_type NanometerUnit;
BOOST_UNITS_STATIC_CONSTANT(nanometer, NanometerUnit);
BOOST_UNITS_STATIC_CONSTANT(nanometers, NanometerUnit);
BOOST_UNITS_STATIC_CONSTANT(nm, NanometerUnit);
typedef boost::units::quantity<NanometerUnit> Length_nm;
typedef Length_nm Length;

// Angstrom
typedef boost::units::metric::angstrom_base_unit AngstromBaseUnit;
typedef AngstromBaseUnit::unit_type AngstromUnit;
BOOST_UNITS_STATIC_CONSTANT(angstrom, AngstromUnit);
typedef boost::units::quantity<AngstromUnit> Length_AA;


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
typedef DaltonBaseUnit::unit_type DaltonUnit;
BOOST_UNITS_STATIC_CONSTANT(dalton, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(daltons, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, DaltonUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, DaltonUnit);
typedef boost::units::quantity<DaltonUnit> Mass_Da;


//////////
// Time //
//////////

// Picosecond
typedef boost::units::scaled_base_unit<
        boost::units::si::second_base_unit,
        boost::units::scale<10, boost::units::static_rational<-12> > > PicosecondBaseUnit;
typedef PicosecondBaseUnit::unit_type PicosecondUnit;
BOOST_UNITS_STATIC_CONSTANT(picosecond, PicosecondUnit);
BOOST_UNITS_STATIC_CONSTANT(picoseconds, PicosecondUnit);
typedef boost::units::quantity<PicosecondUnit> Time_ps;

// Femtosecond
typedef boost::units::scaled_base_unit<
        boost::units::si::second_base_unit,
        boost::units::scale<10, boost::units::static_rational<-15> > > FemtosecondBaseUnit;
typedef FemtosecondBaseUnit::unit_type FemtosecondUnit;
BOOST_UNITS_STATIC_CONSTANT(femtosecond, FemtosecondUnit);
BOOST_UNITS_STATIC_CONSTANT(femtoseconds, FemtosecondUnit);
typedef boost::units::quantity<FemtosecondUnit> Time_fs;



///////// UNIT SYSTEM /////////
// Creating a system is not necessary for using and converting
// between units. However, it makes it possible to express
// derived units easily. For instance, a rate in Ps can be
// expressed as:
// typedef boost::units::quantity<boost::units::unit<boost::units::frequency_dimension, quickstep::units::atomic_system> > RatePs;
typedef boost::units::make_system<
        NanometerBaseUnit,
        DaltonBaseUnit,
        PicosecondBaseUnit,
        boost::units::si::kelvin_base_unit,
        boost::units::si::mole_base_unit
>::type atomic_system;


// Containers of coordinates
// typedef std::array<Length,3> Coordinate;
typedef Eigen::QuantityArray<Length, 1, 3> Coordinate;
//typedef std::vector<std::array<Length,3>> Coordinates;
typedef Eigen::QuantityArray<Length, Eigen::Dynamic, 3> Coordinates;
// typedef std::array<Length_AA,3> CoordinateAA;
typedef Eigen::QuantityArray<Length_AA, 1, 3> CoordinateAA;
//typedef std::vector<std::array<Length_AA,3>> CoordinatesAA;
typedef Eigen::QuantityArray<Length_AA, Eigen::Dynamic, 3> CoordinatesAA;

}}

// Conversion linking Dalton units to corresponding SI mass unit
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(
        quickstep::units::DaltonBaseUnit,
        si::kilogram_base_unit,
        double, boost::units::si::constants::codata::m_u.value().value());

#endif

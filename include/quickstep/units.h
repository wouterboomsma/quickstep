#ifndef QUICKSTEP_UNITS_H
#define QUICKSTEP_UNITS_H

#include <boost/units/systems/si.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/base_units/metric/angstrom.hpp>
#include <boost/units/base_units/angle/radian.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/si/codata/physico-chemical_constants.hpp>
//#include <Eigen/Quantity>
//#include <Eigen/QuantityGeometry>

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

//// Dalton
//struct DaltonBaseUnit :
//        boost::units::base_unit<DaltonBaseUnit, boost::units::mass_dimension, 2> {
//    static std::string name() {
//        return "Dalton";
//    }
//
//    static std::string symbol() {
//        return "Da";
//    }
//};
//typedef DaltonBaseUnit::unit_type DaltonUnit;
//BOOST_UNITS_STATIC_CONSTANT(dalton, DaltonUnit);
//BOOST_UNITS_STATIC_CONSTANT(daltons, DaltonUnit);
//BOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, DaltonUnit);
//BOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, DaltonUnit);
//typedef boost::units::quantity<DaltonUnit> Mass_Da;

//////////
// Time //
//////////

// Current
// Hack: define base unit for atomic current to allow
// specification of charge in elementary units
struct AtomicCurrentBaseUnit
        : boost::units::base_unit<AtomicCurrentBaseUnit, boost::units::current_dimension, 12> {
    static std::string name() {
        return "Artificial Current base unit for producing elementary charge unit";
    }

    static std::string symbol() {
        return "INVALID";
    }
};


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
        //DaltonBaseUnit,
        boost::units::cgs::gram_base_unit,
        AtomicCurrentBaseUnit,
        PicosecondBaseUnit,
        boost::units::si::kelvin_base_unit,
        boost::units::si::mole_base_unit,
        boost::units::angle::radian_base_unit
>::type atomic_system;


typedef boost::units::unit<
        boost::units::derived_dimension<boost::units::mass_base_dimension,1,
                                        boost::units::amount_base_dimension,-1>::type, quickstep::units::atomic_system> MolarMassUnit;
BOOST_UNITS_STATIC_CONSTANT(dalton, MolarMassUnit);
BOOST_UNITS_STATIC_CONSTANT(daltons, MolarMassUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, MolarMassUnit);
BOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, MolarMassUnit);
typedef boost::units::quantity<MolarMassUnit> Mass_Da;
typedef Mass_Da MolarMass;

// Angle
typedef boost::units::unit<boost::units::plane_angle_dimension, atomic_system> AngleUnit;
BOOST_UNITS_STATIC_CONSTANT(radians, AngleUnit);
BOOST_UNITS_STATIC_CONSTANT(rad, AngleUnit);
typedef boost::units::quantity<AngleUnit> Angle_rad;
typedef Angle_rad Angle;
typedef boost::units::quantity<boost::units::degree::plane_angle> Angle_degr;
using boost::units::degree::degrees;


//// Charge
//// Elementary charge unit can now be directly extracted using the charge dimension in the calorie-system
typedef boost::units::unit<boost::units::electric_charge_dimension, atomic_system> ChargeUnit_e;
typedef boost::units::quantity<ChargeUnit_e> Charge_e;
typedef boost::units::quantity<boost::units::si::electric_charge> Charge_coulomb;
typedef Charge_e Charge;
BOOST_UNITS_STATIC_CONSTANT(e, ChargeUnit_e);

}}

// Add scale conversion of atomic current unit
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(
        quickstep::units::AtomicCurrentBaseUnit,
        boost::units::si::ampere_base_unit,
        double, 1.602176487e-19 * 1e12);

//// Conversion linking Dalton units to corresponding SI mass unit
//BOOST_UNITS_DEFINE_CONVERSION_FACTOR(
//        quickstep::units::DaltonBaseUnit,
//        si::kilogram_base_unit,
//        double, boost::units::si::constants::codata::m_u.value().value());

namespace boost {
namespace units {
inline std::string name_string(const boost::units::reduce_unit<quickstep::units::ChargeUnit_e>::type&) { return "elementary charge"; }
inline std::string symbol_string(const boost::units::reduce_unit<quickstep::units::ChargeUnit_e>::type&) { return "e"; }
}}

#endif

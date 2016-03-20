#ifndef QUICKSTEP_UNITS_H
#define QUICKSTEP_UNITS_H

#include <qsboost/units/systems/si.hpp>
#include <qsboost/units/io.hpp>
#include <qsboost/units/systems/si/io.hpp>
#include <qsboost/units/base_units/metric/angstrom.hpp>
#include <qsboost/units/base_units/angle/radian.hpp>
#include <qsboost/units/systems/angle/degrees.hpp>
#include <qsboost/units/systems/si/codata/physico-chemical_constants.hpp>
//#include <Eigen/Quantity>
//#include <Eigen/QuantityGeometry>

namespace quickstep {

namespace units {

////////////
// Length //
////////////

// Nanometer
typedef qsboost::units::scaled_base_unit<
        qsboost::units::si::meter_base_unit,
        qsboost::units::scale<10, qsboost::units::static_rational<-9> > > NanometerBaseUnit;
typedef NanometerBaseUnit::unit_type NanometerUnit;
QSBOOST_UNITS_STATIC_CONSTANT(nanometer, NanometerUnit);
QSBOOST_UNITS_STATIC_CONSTANT(nanometers, NanometerUnit);
QSBOOST_UNITS_STATIC_CONSTANT(nm, NanometerUnit);
typedef qsboost::units::quantity<NanometerUnit> Length_nm;
typedef Length_nm Length;

// Angstrom
typedef qsboost::units::metric::angstrom_base_unit AngstromBaseUnit;
typedef AngstromBaseUnit::unit_type AngstromUnit;
QSBOOST_UNITS_STATIC_CONSTANT(angstrom, AngstromUnit);
typedef qsboost::units::quantity<AngstromUnit> Length_AA;


//////////
// Mass //
//////////

//// Dalton
//struct DaltonBaseUnit :
//        qsboost::units::base_unit<DaltonBaseUnit, qsboost::units::mass_dimension, 2> {
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
//typedef qsboost::units::quantity<DaltonUnit> Mass_Da;

//////////
// Time //
//////////

// Current
// Hack: define base unit for atomic current to allow
// specification of charge in elementary units
struct AtomicCurrentBaseUnit
        : qsboost::units::base_unit<AtomicCurrentBaseUnit, qsboost::units::current_dimension, 12> {
    static std::string name() {
        return "Artificial Current base unit for producing elementary charge unit";
    }

    static std::string symbol() {
        return "INVALID";
    }
};


// Picosecond
typedef qsboost::units::scaled_base_unit<
        qsboost::units::si::second_base_unit,
        qsboost::units::scale<10, qsboost::units::static_rational<-12> > > PicosecondBaseUnit;
typedef PicosecondBaseUnit::unit_type PicosecondUnit;
QSBOOST_UNITS_STATIC_CONSTANT(picosecond, PicosecondUnit);
QSBOOST_UNITS_STATIC_CONSTANT(picoseconds, PicosecondUnit);
QSBOOST_UNITS_STATIC_CONSTANT(ps, PicosecondUnit);
typedef qsboost::units::quantity<PicosecondUnit> Time_ps;

// Femtosecond
typedef qsboost::units::scaled_base_unit<
        qsboost::units::si::second_base_unit,
        qsboost::units::scale<10, qsboost::units::static_rational<-15> > > FemtosecondBaseUnit;
typedef FemtosecondBaseUnit::unit_type FemtosecondUnit;
QSBOOST_UNITS_STATIC_CONSTANT(femtosecond, FemtosecondUnit);
QSBOOST_UNITS_STATIC_CONSTANT(femtoseconds, FemtosecondUnit);
QSBOOST_UNITS_STATIC_CONSTANT(fs, FemtosecondUnit);
typedef qsboost::units::quantity<FemtosecondUnit> Time_fs;



///////// UNIT SYSTEM /////////
// Creating a system is not necessary for using and converting
// between units. However, it makes it possible to express
// derived units easily. For instance, a rate in Ps can be
// expressed as:
// typedef qsboost::units::quantity<qsboost::units::unit<qsboost::units::frequency_dimension, quickstep::units::atomic_system> > RatePs;
typedef qsboost::units::make_system<
        NanometerBaseUnit,
        //DaltonBaseUnit,
        qsboost::units::cgs::gram_base_unit,
        AtomicCurrentBaseUnit,
        PicosecondBaseUnit,
        qsboost::units::si::kelvin_base_unit,
        qsboost::units::si::mole_base_unit,
        qsboost::units::angle::radian_base_unit
>::type atomic_system;


typedef qsboost::units::unit<
        qsboost::units::derived_dimension<qsboost::units::mass_base_dimension,1,
                                        qsboost::units::amount_base_dimension,-1>::type, quickstep::units::atomic_system> MolarMassUnit;
QSBOOST_UNITS_STATIC_CONSTANT(dalton, MolarMassUnit);
QSBOOST_UNITS_STATIC_CONSTANT(daltons, MolarMassUnit);
QSBOOST_UNITS_STATIC_CONSTANT(atomic_mass_unit, MolarMassUnit);
QSBOOST_UNITS_STATIC_CONSTANT(atomic_mass_units, MolarMassUnit);
typedef qsboost::units::quantity<MolarMassUnit> Mass_Da;
typedef Mass_Da MolarMass;

// Angle
typedef qsboost::units::unit<qsboost::units::plane_angle_dimension, atomic_system> AngleUnit;
QSBOOST_UNITS_STATIC_CONSTANT(radians, AngleUnit);
QSBOOST_UNITS_STATIC_CONSTANT(rad, AngleUnit);
typedef qsboost::units::quantity<AngleUnit> Angle_rad;
typedef Angle_rad Angle;
typedef qsboost::units::quantity<qsboost::units::degree::plane_angle> Angle_degr;
using qsboost::units::degree::degrees;


//// Charge
//// Elementary charge unit can now be directly extracted using the charge dimension in the calorie-system
typedef qsboost::units::unit<qsboost::units::electric_charge_dimension, atomic_system> ChargeUnit_e;
typedef qsboost::units::quantity<ChargeUnit_e> Charge_e;
typedef qsboost::units::quantity<qsboost::units::si::electric_charge> Charge_coulomb;
typedef Charge_e Charge;
QSBOOST_UNITS_STATIC_CONSTANT(e, ChargeUnit_e);

}}

// Add scale conversion of atomic current unit
QSBOOST_UNITS_DEFINE_CONVERSION_FACTOR(
        quickstep::units::AtomicCurrentBaseUnit,
        qsboost::units::si::ampere_base_unit,
        double, 1.602176487e-19 * 1e12);

//// Conversion linking Dalton units to corresponding SI mass unit
//BOOST_UNITS_DEFINE_CONVERSION_FACTOR(
//        quickstep::units::DaltonBaseUnit,
//        si::kilogram_base_unit,
//        double, qsboost::units::si::constants::codata::m_u.value().value());

namespace qsboost {
namespace units {
inline std::string name_string(const qsboost::units::reduce_unit<quickstep::units::ChargeUnit_e>::type&) { return "elementary charge"; }
inline std::string symbol_string(const qsboost::units::reduce_unit<quickstep::units::ChargeUnit_e>::type&) { return "e"; }
}}

#endif

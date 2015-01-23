#ifndef QUICKSTEP_ELEMENT_H
#define QUICKSTEP_ELEMENT_H

#include <map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "quickstep/units.h"

namespace quickstep {

class Element {
public:
    Element(unsigned int number, std::string name, std::string symbol, units::MassDa mass);

    static const Element &get_by_symbol(std::string symbol);

    static const Element &get_by_atomic_number(unsigned int number);

    static std::string create_signature(const std::vector<Element> &elements);

    static std::map<Element, int> get_counts(const std::vector<Element> &elements);



    //    bool operator==(const Element &other) {
//        return (mass == other.mass);
//    }

    friend bool operator!=(const Element &element1, const Element &element2) {
        return (element1.mass != element2.mass);
    }

    friend bool operator==(const Element &element1, const Element &element2) {
        return (element1.mass == element2.mass);
    }

    friend bool operator<(const Element &element1, const Element &element2) {
        return (element1.mass < element2.mass);
    }

    friend std::ostream& operator<<(std::ostream& os, const Element& obj) {
        os << obj.name;
        return os;
    }

    static const Element HYDROGEN;
    static const Element DEUTERIUM;
    static const Element HELIUM;
    static const Element LITHIUM;
    static const Element BERYLLIUM;
    static const Element BORON;
    static const Element CARBON;
    static const Element NITROGEN;
    static const Element OXYGEN;
    static const Element FLUORINE;
    static const Element NEON;
    static const Element SODIUM;
    static const Element MAGNESIUM;
    static const Element ALUMINIUM;
    static const Element SILICON;
    static const Element PHOSPHORUS;
    static const Element SULPHUR;
    static const Element CHLORINE;
    static const Element ARGON;
    static const Element POTASSIUM;
    static const Element CALCIUM;
    static const Element SCANDIUM;
    static const Element TITANIUM;
    static const Element VANADIUM;
    static const Element CHROMIUM;
    static const Element MANGANESE;
    static const Element IRON;
    static const Element COBALT;
    static const Element NICKEL;
    static const Element COPPER;
    static const Element ZINC;
    static const Element GALLIUM;
    static const Element GERMANIUM;
    static const Element ARSENIC;
    static const Element SELENIUM;
    static const Element BROMINE;
    static const Element KRYPTON;
    static const Element RUBIDIUM;
    static const Element STRONTIUM;
    static const Element YTTRIUM;
    static const Element ZIRCONIUM;
    static const Element NIOBIUM;
    static const Element MOLYBDENUM;
    static const Element TECHNETIUM;
    static const Element RUTHENIUM;
    static const Element RHODIUM;
    static const Element PALLADIUM;
    static const Element SILVER;
    static const Element CADMIUM;
    static const Element INDIUM;
    static const Element TIN;
    static const Element ANTIMONY;
    static const Element TELLURIUM;
    static const Element IODINE;
    static const Element XENON;
    static const Element CESIUM;
    static const Element BARIUM;
    static const Element LANTHANUM;
    static const Element CERIUM;
    static const Element PRASEODYMIUM;
    static const Element NEODYMIUM;
    static const Element PROMETHIUM;
    static const Element SAMARIUM;
    static const Element EUROPIUM;
    static const Element GADOLINIUM;
    static const Element TERBIUM;
    static const Element DYSPROSIUM;
    static const Element HOLMIUM;
    static const Element ERBIUM;
    static const Element THULIUM;
    static const Element YTTERBIUM;
    static const Element LUTETIUM;
    static const Element HAFNIUM;
    static const Element TANTALUM;
    static const Element TUNGSTEN;
    static const Element RHENIUM;
    static const Element OSMIUM;
    static const Element IRIDIUM;
    static const Element PLATINUM;
    static const Element GOLD;
    static const Element MERCURY;
    static const Element THALLIUM;
    static const Element LEAD;
    static const Element BISMUTH;
    static const Element POLONIUM;
    static const Element ASTATINE;
    static const Element RADON;
    static const Element FRANCIUM;
    static const Element RADIUM;
    static const Element ACTINIUM;
    static const Element THORIUM;
    static const Element PROTACTINIUM;
    static const Element URANIUM;
    static const Element NEPTUNIUM;
    static const Element PLUTONIUM;
    static const Element AMERICIUM;
    static const Element CURIUM;
    static const Element BERKELIUM;
    static const Element CALIFORNIUM;
    static const Element EINSTEINIUM;
    static const Element FERMIUM;
    static const Element MENDELEVIUM;
    static const Element NOBELIUM;
    static const Element LAWRENCIUM;
    static const Element RUTHERFORDIUM;
    static const Element DUBNIUM;
    static const Element SEABORGIUM;
    static const Element BOHRIUM;
    static const Element HASSIUM;
    static const Element MEITNERIUM;
    static const Element DARMSTADTIUM;
    static const Element ROENTGENIUM;
    static const Element UNUNBIUM;
    static const Element UNUNTRIUM;
    static const Element UNUNQUADIUM;
    static const Element UNUNPENTIUM;
    static const Element UNUNHEXIUM;

    static const Element UNKNOWN;

    // Alternative spelling variants
    static const Element ALUMINUM;
    static const Element SULFUR;

    unsigned int number;
    std::string name;
    std::string symbol;
    units::MassDa mass;

private:

    static std::map<std::string, Element> elements_by_symbol;
    static std::map<unsigned int, Element> elements_by_number;
};

}

#endif

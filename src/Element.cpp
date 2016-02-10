#include "quickstep/Element.h"
#include <string>
#include <algorithm>
#include <qsboost/algorithm/string.hpp>
#include "prettyprint.hpp"

namespace quickstep {

using namespace units;

Element::Element(unsigned int number, std::string name, std::string symbol, units::Mass_Da mass)
     : number(number), name(name), symbol(symbol), mass(mass) {
          
     std::string symbol_upper = qsboost::to_upper_copy(qsboost::trim_copy(symbol));

     // Make sure symbol is not already present
     assert(elements_by_symbol.count(symbol) == 0);
     elements_by_symbol.insert(std::make_pair(symbol_upper, *this));

     // In case of two elements with the same atom number,
     // choose the lightest variant (e.g. hydrogen vs deuterium)
     if (elements_by_number.count(number)) {
          const Element &alternative = elements_by_number.at(number);
          if (mass < alternative.mass)
               elements_by_number.insert(std::make_pair(number, *this));
     } else {
          elements_by_number.insert(std::make_pair(number, *this));
     }
}


const Element &Element::get_by_symbol(std::string symbol) {
     std::string symbol_upper = qsboost::to_upper_copy(qsboost::trim_copy(symbol));
     if (elements_by_symbol.count(symbol_upper))
          return elements_by_symbol.at(symbol_upper);
     else 
          return UNKNOWN;
}

const Element &Element::get_by_atomic_number(unsigned int number) {
     return elements_by_number.at(number);
}


std::map<Element, int> Element::get_counts(const std::vector<Element> &elements) {
     std::map<Element, int> counts;
     for (const Element &element: elements) {
          if (!counts.count(element))
               counts.insert(std::make_pair(element, 0));
          counts.at(element) += 1;
     }
     return counts;
}

std::string Element::create_signature(const std::vector<Element> &elements) {
     std::map<Element, int> counts = get_counts(elements);
     std::vector<std::pair<Element, int> > signature_vec;
     for (const auto &entry:counts) {
          signature_vec.push_back(entry);
     }
     std::sort(signature_vec.begin(), signature_vec.end());
     std::string signature = "";
     for (const auto &entry:signature_vec) {
          signature += entry.first.symbol+std::to_string(entry.second);
     }
     return signature;
}

std::string Element::create_bonded_signature(const std::vector<Element> &elements,
                                             const std::vector<std::pair<int,int>> &bonds) {

     std::vector<std::set<int>> adjacency_list(elements.size());
     for (auto bond:bonds) {
          adjacency_list[bond.first].insert(bond.second);
          adjacency_list[bond.second].insert(bond.first);
     }

     std::vector<std::tuple<Element, double, int> > signature_vec;
     for (unsigned int i=0; i<elements.size(); ++i) {
          const Element &element = elements[i];
          double neighbour_mass = 0;
          for (int index1: adjacency_list[i]) {
               neighbour_mass += elements[index1].mass.value();
               for (int index2: adjacency_list[index1]) {
                    neighbour_mass += elements[index2].mass.value();
               }
          }
          signature_vec.push_back(std::make_tuple(element, neighbour_mass, i));
     }
     std::sort(signature_vec.rbegin(), signature_vec.rend());

     std::vector<int> index_map(elements.size());
     for (unsigned int i=0; i<signature_vec.size(); ++i) {
          //index_map[i] = std::get<2>(signature_vec[i]);
          index_map[std::get<2>(signature_vec[i])] = i;
     }

     std::string signature = "";
     for (const auto &entry: signature_vec) {
          signature += std::get<0>(entry).symbol;
          std::string value_str = "";
          bool first = true;
          for (int index: adjacency_list[std::get<2>(entry)]) {
               if (index_map[std::get<2>(entry)] > index_map[index]) {
                    if (!first)
                         value_str += ",";
                    value_str += std::to_string(index_map[index]);
                    first = false;
               }
          }
          if (value_str != "")
               signature += ":" + value_str;
          signature += ";";
     }
     return signature;
}




std::map<std::string, Element> Element::elements_by_symbol = std::map<std::string, Element>();
std::map<unsigned int, Element> Element::elements_by_number = std::map<unsigned int, Element>();

const Element Element::HYDROGEN =       Element(  1, "hydrogen", "H", 1.007947*dalton);
const Element Element::DEUTERIUM =      Element(  1, "deuterium", "D", 2.01355321270*dalton);
const Element Element::HELIUM =         Element(  2, "helium", "He", 4.003*dalton);
const Element Element::LITHIUM =        Element(  3, "lithium", "Li", 6.9412*dalton);
const Element Element::BERYLLIUM =      Element(  4, "beryllium", "Be", 9.0121823*dalton);
const Element Element::BORON =          Element(  5, "boron", "B", 10.8117*dalton);
const Element Element::CARBON =         Element(  6, "carbon", "C", 12.01078*dalton);
const Element Element::NITROGEN =       Element(  7, "nitrogen", "N", 14.00672*dalton);
const Element Element::OXYGEN =         Element(  8, "oxygen", "O", 15.99943*dalton);
const Element Element::FLUORINE =       Element(  9, "fluorine", "F", 18.99840325*dalton);
const Element Element::NEON =           Element( 10, "neon", "Ne", 20.17976*dalton);
const Element Element::SODIUM =         Element( 11, "sodium", "Na", 22.989769282*dalton);
const Element Element::MAGNESIUM =      Element( 12, "magnesium", "Mg", 24.30506*dalton);
const Element Element::ALUMINIUM =      Element( 13, "aluminium", "Al", 26.98153868*dalton);
const Element Element::SILICON =        Element( 14, "silicon", "Si", 28.08553*dalton);
const Element Element::PHOSPHORUS =     Element( 15, "phosphorus", "P", 30.9737622*dalton);
const Element Element::SULPHUR =        Element( 16, "sulphur", "S", 32.0655*dalton);
const Element Element::CHLORINE =       Element( 17, "chlorine", "Cl", 35.4532*dalton);
const Element Element::ARGON =          Element( 18, "argon", "Ar", 39.9481*dalton);
const Element Element::POTASSIUM =      Element( 19, "potassium", "K", 39.09831*dalton);
const Element Element::CALCIUM =        Element( 20, "calcium", "Ca", 40.0784*dalton);
const Element Element::SCANDIUM =       Element( 21, "scandium", "Sc", 44.9559126*dalton);
const Element Element::TITANIUM =       Element( 22, "titanium", "Ti", 47.8671*dalton);
const Element Element::VANADIUM =       Element( 23, "vanadium", "V", 50.94151*dalton);
const Element Element::CHROMIUM =       Element( 24, "chromium", "Cr", 51.99616*dalton);
const Element Element::MANGANESE =      Element( 25, "manganese", "Mn", 54.9380455*dalton);
const Element Element::IRON =           Element( 26, "iron", "Fe", 55.8452*dalton);
const Element Element::COBALT =         Element( 27, "cobalt", "Co", 58.9331955*dalton);
const Element Element::NICKEL =         Element( 28, "nickel", "Ni", 58.69342*dalton);
const Element Element::COPPER =         Element( 29, "copper", "Cu", 63.5463*dalton);
const Element Element::ZINC =           Element( 30, "zinc", "Zn", 65.4094*dalton);
const Element Element::GALLIUM =        Element( 31, "gallium", "Ga", 69.7231*dalton);
const Element Element::GERMANIUM =      Element( 32, "germanium", "Ge", 72.641*dalton);
const Element Element::ARSENIC =        Element( 33, "arsenic", "As", 74.921602*dalton);
const Element Element::SELENIUM =       Element( 34, "selenium", "Se", 78.963*dalton);
const Element Element::BROMINE =        Element( 35, "bromine", "Br", 79.9041*dalton);
const Element Element::KRYPTON =        Element( 36, "krypton", "Kr", 83.7982*dalton);
const Element Element::RUBIDIUM =       Element( 37, "rubidium", "Rb", 85.46783*dalton);
const Element Element::STRONTIUM =      Element( 38, "strontium", "Sr", 87.621*dalton);
const Element Element::YTTRIUM =        Element( 39, "yttrium", "Y", 88.905852*dalton);
const Element Element::ZIRCONIUM =      Element( 40, "zirconium", "Zr", 91.2242*dalton);
const Element Element::NIOBIUM =        Element( 41, "niobium", "Nb", 92.906382*dalton);
const Element Element::MOLYBDENUM =     Element( 42, "molybdenum", "Mo", 95.942*dalton);
const Element Element::TECHNETIUM =     Element( 43, "technetium", "Tc", 98*dalton);
const Element Element::RUTHENIUM =      Element( 44, "ruthenium", "Ru", 101.072*dalton);
const Element Element::RHODIUM =        Element( 45, "rhodium", "Rh", 102.905502*dalton);
const Element Element::PALLADIUM =      Element( 46, "palladium", "Pd", 106.421*dalton);
const Element Element::SILVER =         Element( 47, "silver", "Ag", 107.86822*dalton);
const Element Element::CADMIUM =        Element( 48, "cadmium", "Cd", 112.4118*dalton);
const Element Element::INDIUM =         Element( 49, "indium", "In", 114.8183*dalton);
const Element Element::TIN =            Element( 50, "tin", "Sn", 118.7107*dalton);
const Element Element::ANTIMONY =       Element( 51, "antimony", "Sb", 121.7601*dalton);
const Element Element::TELLURIUM =      Element( 52, "tellurium", "Te", 127.603*dalton);
const Element Element::IODINE =         Element( 53, "iodine", "I", 126.904473*dalton);
const Element Element::XENON =          Element( 54, "xenon", "Xe", 131.2936*dalton);
const Element Element::CESIUM =         Element( 55, "cesium", "Cs", 132.90545192*dalton);
const Element Element::BARIUM =         Element( 56, "barium", "Ba", 137.3277*dalton);
const Element Element::LANTHANUM =      Element( 57, "lanthanum", "La", 138.905477*dalton);
const Element Element::CERIUM =         Element( 58, "cerium", "Ce", 140.1161*dalton);
const Element Element::PRASEODYMIUM =   Element( 59, "praseodymium", "Pr", 140.907652*dalton);
const Element Element::NEODYMIUM =      Element( 60, "neodymium", "Nd", 144.2423*dalton);
const Element Element::PROMETHIUM =     Element( 61, "promethium", "Pm", 145*dalton);
const Element Element::SAMARIUM =       Element( 62, "samarium", "Sm", 150.362*dalton);
const Element Element::EUROPIUM =       Element( 63, "europium", "Eu", 151.9641*dalton);
const Element Element::GADOLINIUM =     Element( 64, "gadolinium", "Gd", 157.253*dalton);
const Element Element::TERBIUM =        Element( 65, "terbium", "Tb", 158.925352*dalton);
const Element Element::DYSPROSIUM =     Element( 66, "dysprosium", "Dy", 162.5001*dalton);
const Element Element::HOLMIUM =        Element( 67, "holmium", "Ho", 164.930322*dalton);
const Element Element::ERBIUM =         Element( 68, "erbium", "Er", 167.2593*dalton);
const Element Element::THULIUM =        Element( 69, "thulium", "Tm", 168.934212*dalton);
const Element Element::YTTERBIUM =      Element( 70, "ytterbium", "Yb", 173.043*dalton);
const Element Element::LUTETIUM =       Element( 71, "lutetium", "Lu", 174.9671*dalton);
const Element Element::HAFNIUM =        Element( 72, "hafnium", "Hf", 178.492*dalton);
const Element Element::TANTALUM =       Element( 73, "tantalum", "Ta", 180.947882*dalton);
const Element Element::TUNGSTEN =       Element( 74, "tungsten", "W", 183.841*dalton);
const Element Element::RHENIUM =        Element( 75, "rhenium", "Re", 186.2071*dalton);
const Element Element::OSMIUM =         Element( 76, "osmium", "Os", 190.233*dalton);
const Element Element::IRIDIUM =        Element( 77, "iridium", "Ir", 192.2173*dalton);
const Element Element::PLATINUM =       Element( 78, "platinum", "Pt", 195.0849*dalton);
const Element Element::GOLD =           Element( 79, "gold", "Au", 196.9665694*dalton);
const Element Element::MERCURY =        Element( 80, "mercury", "Hg", 200.592*dalton);
const Element Element::THALLIUM =       Element( 81, "thallium", "Tl", 204.38332*dalton);
const Element Element::LEAD =           Element( 82, "lead", "Pb", 207.21*dalton);
const Element Element::BISMUTH =        Element( 83, "bismuth", "Bi", 208.980401*dalton);
const Element Element::POLONIUM =       Element( 84, "polonium", "Po", 209*dalton);
const Element Element::ASTATINE =       Element( 85, "astatine", "At", 210*dalton);
const Element Element::RADON =          Element( 86, "radon", "Rn", 222.018*dalton);
const Element Element::FRANCIUM =       Element( 87, "francium", "Fr", 223*dalton);
const Element Element::RADIUM =         Element( 88, "radium", "Ra", 226*dalton);
const Element Element::ACTINIUM =       Element( 89, "actinium", "Ac", 227*dalton);
const Element Element::THORIUM =        Element( 90, "thorium", "Th", 232.038062*dalton);
const Element Element::PROTACTINIUM =   Element( 91, "protactinium", "Pa", 231.035882*dalton);
const Element Element::URANIUM =        Element( 92, "uranium", "U", 238.028913*dalton);
const Element Element::NEPTUNIUM =      Element( 93, "neptunium", "Np", 237*dalton);
const Element Element::PLUTONIUM =      Element( 94, "plutonium", "Pu", 244*dalton);
const Element Element::AMERICIUM =      Element( 95, "americium", "Am", 243*dalton);
const Element Element::CURIUM =         Element( 96, "curium", "Cm", 247*dalton);
const Element Element::BERKELIUM =      Element( 97, "berkelium", "Bk", 247*dalton);
const Element Element::CALIFORNIUM =    Element( 98, "californium", "Cf", 251*dalton);
const Element Element::EINSTEINIUM =    Element( 99, "einsteinium", "Es", 252*dalton);
const Element Element::FERMIUM =        Element(100, "fermium", "Fm", 257*dalton);
const Element Element::MENDELEVIUM =    Element(101, "mendelevium", "Md", 258*dalton);
const Element Element::NOBELIUM =       Element(102, "nobelium", "No", 259*dalton);
const Element Element::LAWRENCIUM =     Element(103, "lawrencium",     "Lr", 262*dalton);
const Element Element::RUTHERFORDIUM =  Element(104, "rutherfordium",  "Rf", 261*dalton);
const Element Element::DUBNIUM =        Element(105, "dubnium",        "Db", 262*dalton);
const Element Element::SEABORGIUM =     Element(106, "seaborgium",     "Sg", 266*dalton);
const Element Element::BOHRIUM =        Element(107, "bohrium",        "Bh", 264*dalton);
const Element Element::HASSIUM =        Element(108, "hassium",        "Hs", 269*dalton);
const Element Element::MEITNERIUM =     Element(109, "meitnerium",     "Mt", 268*dalton);
const Element Element::DARMSTADTIUM =   Element(110, "darmstadtium",   "Ds", 281*dalton);
const Element Element::ROENTGENIUM =    Element(111, "roentgenium",    "Rg", 272*dalton);
const Element Element::UNUNBIUM =       Element(112, "ununbium",       "Uub", 285*dalton);
const Element Element::UNUNTRIUM =      Element(113, "ununtrium",      "Uut", 284*dalton);
const Element Element::UNUNQUADIUM =    Element(114, "ununquadium",    "Uuq", 289*dalton);
const Element Element::UNUNPENTIUM =    Element(115, "ununpentium",    "Uup", 288*dalton);
const Element Element::UNUNHEXIUM =     Element(116, "ununhexium",     "Uuh", 292*dalton);

const Element Element::UNKNOWN =        Element(-1, "unknown",     "unknown", 0*dalton);

const Element Element::ALUMINUM = ALUMINIUM;
const Element Element::SULFUR   = SULPHUR;

}

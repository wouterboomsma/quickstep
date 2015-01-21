#include "quickstep/Element.h"
#include <string>
#include <algorithm>

namespace quickstep {

Element::Element(unsigned int number, std::string name, std::string symbol, mass_t mass)
     : number(number), name(name), symbol(symbol), mass(mass) {
          
     std::string symbol_upper = boost::to_upper_copy(boost::trim_copy(symbol));

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
     std::string symbol_upper = boost::to_upper_copy(boost::trim_copy(symbol));
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
     for (const auto &entry:counts) {
          signature += entry.first.symbol+std::to_string(entry.second);
     }
     return signature;
}




std::map<std::string, Element> Element::elements_by_symbol = std::map<std::string, Element>();
std::map<unsigned int, Element> Element::elements_by_number = std::map<unsigned int, Element>();

const Element Element::HYDROGEN =       Element(  1, "hydrogen", "H", 1.007947*daltons);
const Element Element::DEUTERIUM =      Element(  1, "deuterium", "D", 2.01355321270*daltons);
const Element Element::HELIUM =         Element(  2, "helium", "He", 4.003*daltons);
const Element Element::LITHIUM =        Element(  3, "lithium", "Li", 6.9412*daltons);
const Element Element::BERYLLIUM =      Element(  4, "beryllium", "Be", 9.0121823*daltons);
const Element Element::BORON =          Element(  5, "boron", "B", 10.8117*daltons);
const Element Element::CARBON =         Element(  6, "carbon", "C", 12.01078*daltons);
const Element Element::NITROGEN =       Element(  7, "nitrogen", "N", 14.00672*daltons);
const Element Element::OXYGEN =         Element(  8, "oxygen", "O", 15.99943*daltons);
const Element Element::FLUORINE =       Element(  9, "fluorine", "F", 18.99840325*daltons);
const Element Element::NEON =           Element( 10, "neon", "Ne", 20.17976*daltons);
const Element Element::SODIUM =         Element( 11, "sodium", "Na", 22.989769282*daltons);
const Element Element::MAGNESIUM =      Element( 12, "magnesium", "Mg", 24.30506*daltons);
const Element Element::ALUMINIUM =      Element( 13, "aluminium", "Al", 26.98153868*daltons);
const Element Element::SILICON =        Element( 14, "silicon", "Si", 28.08553*daltons);
const Element Element::PHOSPHORUS =     Element( 15, "phosphorus", "P", 30.9737622*daltons);
const Element Element::SULPHUR =        Element( 16, "sulphur", "S", 32.0655*daltons);
const Element Element::CHLORINE =       Element( 17, "chlorine", "Cl", 35.4532*daltons);
const Element Element::ARGON =          Element( 18, "argon", "Ar", 39.9481*daltons);
const Element Element::POTASSIUM =      Element( 19, "potassium", "K", 39.09831*daltons);
const Element Element::CALCIUM =        Element( 20, "calcium", "Ca", 40.0784*daltons);
const Element Element::SCANDIUM =       Element( 21, "scandium", "Sc", 44.9559126*daltons);
const Element Element::TITANIUM =       Element( 22, "titanium", "Ti", 47.8671*daltons);
const Element Element::VANADIUM =       Element( 23, "vanadium", "V", 50.94151*daltons);
const Element Element::CHROMIUM =       Element( 24, "chromium", "Cr", 51.99616*daltons);
const Element Element::MANGANESE =      Element( 25, "manganese", "Mn", 54.9380455*daltons);
const Element Element::IRON =           Element( 26, "iron", "Fe", 55.8452*daltons);
const Element Element::COBALT =         Element( 27, "cobalt", "Co", 58.9331955*daltons);
const Element Element::NICKEL =         Element( 28, "nickel", "Ni", 58.69342*daltons);
const Element Element::COPPER =         Element( 29, "copper", "Cu", 63.5463*daltons);
const Element Element::ZINC =           Element( 30, "zinc", "Zn", 65.4094*daltons);
const Element Element::GALLIUM =        Element( 31, "gallium", "Ga", 69.7231*daltons);
const Element Element::GERMANIUM =      Element( 32, "germanium", "Ge", 72.641*daltons);
const Element Element::ARSENIC =        Element( 33, "arsenic", "As", 74.921602*daltons);
const Element Element::SELENIUM =       Element( 34, "selenium", "Se", 78.963*daltons);
const Element Element::BROMINE =        Element( 35, "bromine", "Br", 79.9041*daltons);
const Element Element::KRYPTON =        Element( 36, "krypton", "Kr", 83.7982*daltons);
const Element Element::RUBIDIUM =       Element( 37, "rubidium", "Rb", 85.46783*daltons);
const Element Element::STRONTIUM =      Element( 38, "strontium", "Sr", 87.621*daltons);
const Element Element::YTTRIUM =        Element( 39, "yttrium", "Y", 88.905852*daltons);
const Element Element::ZIRCONIUM =      Element( 40, "zirconium", "Zr", 91.2242*daltons);
const Element Element::NIOBIUM =        Element( 41, "niobium", "Nb", 92.906382*daltons);
const Element Element::MOLYBDENUM =     Element( 42, "molybdenum", "Mo", 95.942*daltons);
const Element Element::TECHNETIUM =     Element( 43, "technetium", "Tc", 98*daltons);
const Element Element::RUTHENIUM =      Element( 44, "ruthenium", "Ru", 101.072*daltons);
const Element Element::RHODIUM =        Element( 45, "rhodium", "Rh", 102.905502*daltons);
const Element Element::PALLADIUM =      Element( 46, "palladium", "Pd", 106.421*daltons);
const Element Element::SILVER =         Element( 47, "silver", "Ag", 107.86822*daltons);
const Element Element::CADMIUM =        Element( 48, "cadmium", "Cd", 112.4118*daltons);
const Element Element::INDIUM =         Element( 49, "indium", "In", 114.8183*daltons);
const Element Element::TIN =            Element( 50, "tin", "Sn", 118.7107*daltons);
const Element Element::ANTIMONY =       Element( 51, "antimony", "Sb", 121.7601*daltons);
const Element Element::TELLURIUM =      Element( 52, "tellurium", "Te", 127.603*daltons);
const Element Element::IODINE =         Element( 53, "iodine", "I", 126.904473*daltons);
const Element Element::XENON =          Element( 54, "xenon", "Xe", 131.2936*daltons);
const Element Element::CESIUM =         Element( 55, "cesium", "Cs", 132.90545192*daltons);
const Element Element::BARIUM =         Element( 56, "barium", "Ba", 137.3277*daltons);
const Element Element::LANTHANUM =      Element( 57, "lanthanum", "La", 138.905477*daltons);
const Element Element::CERIUM =         Element( 58, "cerium", "Ce", 140.1161*daltons);
const Element Element::PRASEODYMIUM =   Element( 59, "praseodymium", "Pr", 140.907652*daltons);
const Element Element::NEODYMIUM =      Element( 60, "neodymium", "Nd", 144.2423*daltons);
const Element Element::PROMETHIUM =     Element( 61, "promethium", "Pm", 145*daltons);
const Element Element::SAMARIUM =       Element( 62, "samarium", "Sm", 150.362*daltons);
const Element Element::EUROPIUM =       Element( 63, "europium", "Eu", 151.9641*daltons);
const Element Element::GADOLINIUM =     Element( 64, "gadolinium", "Gd", 157.253*daltons);
const Element Element::TERBIUM =        Element( 65, "terbium", "Tb", 158.925352*daltons);
const Element Element::DYSPROSIUM =     Element( 66, "dysprosium", "Dy", 162.5001*daltons);
const Element Element::HOLMIUM =        Element( 67, "holmium", "Ho", 164.930322*daltons);
const Element Element::ERBIUM =         Element( 68, "erbium", "Er", 167.2593*daltons);
const Element Element::THULIUM =        Element( 69, "thulium", "Tm", 168.934212*daltons);
const Element Element::YTTERBIUM =      Element( 70, "ytterbium", "Yb", 173.043*daltons);
const Element Element::LUTETIUM =       Element( 71, "lutetium", "Lu", 174.9671*daltons);
const Element Element::HAFNIUM =        Element( 72, "hafnium", "Hf", 178.492*daltons);
const Element Element::TANTALUM =       Element( 73, "tantalum", "Ta", 180.947882*daltons);
const Element Element::TUNGSTEN =       Element( 74, "tungsten", "W", 183.841*daltons);
const Element Element::RHENIUM =        Element( 75, "rhenium", "Re", 186.2071*daltons);
const Element Element::OSMIUM =         Element( 76, "osmium", "Os", 190.233*daltons);
const Element Element::IRIDIUM =        Element( 77, "iridium", "Ir", 192.2173*daltons);
const Element Element::PLATINUM =       Element( 78, "platinum", "Pt", 195.0849*daltons);
const Element Element::GOLD =           Element( 79, "gold", "Au", 196.9665694*daltons);
const Element Element::MERCURY =        Element( 80, "mercury", "Hg", 200.592*daltons);
const Element Element::THALLIUM =       Element( 81, "thallium", "Tl", 204.38332*daltons);
const Element Element::LEAD =           Element( 82, "lead", "Pb", 207.21*daltons);
const Element Element::BISMUTH =        Element( 83, "bismuth", "Bi", 208.980401*daltons);
const Element Element::POLONIUM =       Element( 84, "polonium", "Po", 209*daltons);
const Element Element::ASTATINE =       Element( 85, "astatine", "At", 210*daltons);
const Element Element::RADON =          Element( 86, "radon", "Rn", 222.018*daltons);
const Element Element::FRANCIUM =       Element( 87, "francium", "Fr", 223*daltons);
const Element Element::RADIUM =         Element( 88, "radium", "Ra", 226*daltons);
const Element Element::ACTINIUM =       Element( 89, "actinium", "Ac", 227*daltons);
const Element Element::THORIUM =        Element( 90, "thorium", "Th", 232.038062*daltons);
const Element Element::PROTACTINIUM =   Element( 91, "protactinium", "Pa", 231.035882*daltons);
const Element Element::URANIUM =        Element( 92, "uranium", "U", 238.028913*daltons);
const Element Element::NEPTUNIUM =      Element( 93, "neptunium", "Np", 237*daltons);
const Element Element::PLUTONIUM =      Element( 94, "plutonium", "Pu", 244*daltons);
const Element Element::AMERICIUM =      Element( 95, "americium", "Am", 243*daltons);
const Element Element::CURIUM =         Element( 96, "curium", "Cm", 247*daltons);
const Element Element::BERKELIUM =      Element( 97, "berkelium", "Bk", 247*daltons);
const Element Element::CALIFORNIUM =    Element( 98, "californium", "Cf", 251*daltons);
const Element Element::EINSTEINIUM =    Element( 99, "einsteinium", "Es", 252*daltons);
const Element Element::FERMIUM =        Element(100, "fermium", "Fm", 257*daltons);
const Element Element::MENDELEVIUM =    Element(101, "mendelevium", "Md", 258*daltons);
const Element Element::NOBELIUM =       Element(102, "nobelium", "No", 259*daltons);
const Element Element::LAWRENCIUM =     Element(103, "lawrencium",     "Lr", 262*daltons);
const Element Element::RUTHERFORDIUM =  Element(104, "rutherfordium",  "Rf", 261*daltons);
const Element Element::DUBNIUM =        Element(105, "dubnium",        "Db", 262*daltons);
const Element Element::SEABORGIUM =     Element(106, "seaborgium",     "Sg", 266*daltons);
const Element Element::BOHRIUM =        Element(107, "bohrium",        "Bh", 264*daltons);
const Element Element::HASSIUM =        Element(108, "hassium",        "Hs", 269*daltons);
const Element Element::MEITNERIUM =     Element(109, "meitnerium",     "Mt", 268*daltons);
const Element Element::DARMSTADTIUM =   Element(110, "darmstadtium",   "Ds", 281*daltons);
const Element Element::ROENTGENIUM =    Element(111, "roentgenium",    "Rg", 272*daltons);
const Element Element::UNUNBIUM =       Element(112, "ununbium",       "Uub", 285*daltons);
const Element Element::UNUNTRIUM =      Element(113, "ununtrium",      "Uut", 284*daltons);
const Element Element::UNUNQUADIUM =    Element(114, "ununquadium",    "Uuq", 289*daltons);
const Element Element::UNUNPENTIUM =    Element(115, "ununpentium",    "Uup", 288*daltons);
const Element Element::UNUNHEXIUM =     Element(116, "ununhexium",     "Uuh", 292*daltons);

const Element Element::UNKNOWN =        Element(-1, "unknown",     "unknown", 0*daltons);

const Element Element::ALUMINUM = ALUMINIUM;
const Element Element::SULFUR   = SULPHUR;

}

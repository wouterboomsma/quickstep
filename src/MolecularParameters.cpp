#include "quickstep/MolecularParameters.h"
#include "quickstep/Topology.h"
#include "quickstep/Element.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/range/adaptor/transformed.hpp>

namespace quickstep {



void MolecularParameters::parse_from_XML(const std::string &filename) {
    boost::filesystem::ifstream ifs(filename);
    boost::property_tree::ptree parameter_input;
    boost::property_tree::read_xml(ifs, parameter_input, boost::property_tree::xml_parser::trim_whitespace);
    parse_from_XML(parameter_input);
}

void MolecularParameters::parse_from_XML(const boost::property_tree::ptree &parameter_input) {

    const auto atom_type_nodes = parameter_input.begin()->second.get_child_optional("AtomTypes");
    if (atom_type_nodes) {
        for (const auto &atom_type_node: *atom_type_nodes) {

            if (atom_type_node.first == "Type") {
                auto &node_value = atom_type_node.second;
                std::string name_attr = node_value.get<std::string>("<xmlattr>.name");
                std::string class_attr = node_value.get<std::string>("<xmlattr>.class");
                double mass_attr = node_value.get<double>("<xmlattr>.mass");

                Element element = Element::UNKNOWN;
                boost::optional<std::string> element_attr = node_value.get_optional<std::string>("<xmlattr>.element");
                if (element_attr)
                    element = Element::get_by_symbol(*element_attr);

                if (atom_types.count(name_attr)) {
                    BOOST_THROW_EXCEPTION(FatalError() <<
                                          "Multiple definitions of atom type: " << name_attr);
                }
                atom_types.insert(std::make_pair(name_attr,
                                                 AtomTypeData({class_attr,
                                                               mass_attr,
                                                               element})));
            } else if (atom_type_node.first == "<xmlcomment>") {
                continue;
            } else if (atom_type_node.first != "<xmlattr>") {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Unknown node attribute in AtomTypes entry: " << atom_type_node.first);
            }
        }
    }


    for (const auto &residues_node: parameter_input.begin()->second.get_child("Residues")) {
    	if (residues_node.first=="<xmlcomment>")
    		continue;

    	if (residues_node.first!="Residue"){
    	    BOOST_THROW_EXCEPTION(FatalError() <<
    	    		"Only <Residue name=\"...\"> entries allowed in Residues section: " << residues_node.first << ".");
    	}

        std::string residue_name = residues_node.second.get<std::string>("<xmlattr>.name");

        if (templates.count(residue_name)) {
            BOOST_THROW_EXCEPTION(FatalError() <<
                                  "Multiple <Residue> entries for " << residue_name << ".");
        }

        TemplateData &residue_template =
                (templates.insert(std::make_pair(residue_name, TemplateData({residue_name})))).first->second;

        for (const auto &residue_node: residues_node.second) {

            if (residue_node.first == "Atom") {
                residue_template.atoms.push_back(TemplateAtomData());

                std::string atom_name = residue_node.second.get<std::string>("<xmlattr>.name");
                residue_template.atoms.back().name = atom_name;
                residue_template.atom_name_lookup.insert(std::make_pair(atom_name, residue_template.atoms.size()-1));

                // Check if atom information is given through atom type
                boost::optional<std::string> atom_type = residue_node.second.get_optional<std::string>("<xmlattr>.type");
                if (atom_type)
                    residue_template.atoms.back().element = atom_types.at(*atom_type).element;
                else {

                    Element element = Element::UNKNOWN;
                    boost::optional<std::string> element_attr = residue_node.second.get_optional<std::string>("<xmlattr>.element");
                    if (element_attr)
                        element = Element::get_by_symbol(*element_attr);
                    residue_template.atoms.back().element = element;
                }

            } else if (residue_node.first == "VirtualSite") {
                int index = residue_node.second.get<int>("<xmlattr>.index");
                std::string type = residue_node.second.get<std::string>("<xmlattr>.type");
                residue_template.virtual_sites.push_back(VirtualSiteData({index, type}));
                if (type == "average2") {
                    residue_template.virtual_sites.back().atoms =
                            {residue_node.second.get<int>("<xmlattr>.atom1"),
                             residue_node.second.get<int>("<xmlattr>.atom2")};
                    residue_template.virtual_sites.back().weights =
                            {residue_node.second.get<double>("<xmlattr>.weight1"),
                             residue_node.second.get<double>("<xmlattr>.weight2")};
                } else if (type == "average3") {
                    residue_template.virtual_sites.back().atoms =
                            {residue_node.second.get<int>("<xmlattr>.atom1"),
                             residue_node.second.get<int>("<xmlattr>.atom2"),
                             residue_node.second.get<int>("<xmlattr>.atom3")};
                    residue_template.virtual_sites.back().weights =
                            {residue_node.second.get<double>("<xmlattr>.weight1"),
                             residue_node.second.get<double>("<xmlattr>.weight2"),
                             residue_node.second.get<double>("<xmlattr>.weight3")};
                } else if (type == "outOfPlane") {
                    residue_template.virtual_sites.back().atoms =
                            {residue_node.second.get<int>("<xmlattr>.atom1"),
                             residue_node.second.get<int>("<xmlattr>.atom2"),
                             residue_node.second.get<int>("<xmlattr>.atom3")};
                    residue_template.virtual_sites.back().weights =
                            {residue_node.second.get<double>("<xmlattr>.weight12"),
                             residue_node.second.get<double>("<xmlattr>.weight13"),
                             residue_node.second.get<double>("<xmlattr>.weightCross")};
                } else if (type == "localCoords") {
                    residue_template.virtual_sites.back().atoms =
                            {residue_node.second.get<int>("<xmlattr>.atom1"),
                             residue_node.second.get<int>("<xmlattr>.atom2"),
                             residue_node.second.get<int>("<xmlattr>.atom3")};
                    residue_template.virtual_sites.back().origin_weights =
                            {residue_node.second.get<double>("<xmlattr>.wo1"),
                             residue_node.second.get<double>("<xmlattr>.wo2"),
                             residue_node.second.get<double>("<xmlattr>.wo3")};
                    residue_template.virtual_sites.back().x_weights =
                            {residue_node.second.get<double>("<xmlattr>.wx1"),
                             residue_node.second.get<double>("<xmlattr>.wx2"),
                             residue_node.second.get<double>("<xmlattr>.wx3")};
                    residue_template.virtual_sites.back().y_weights =
                            {residue_node.second.get<double>("<xmlattr>.wy1"),
                             residue_node.second.get<double>("<xmlattr>.wy2"),
                             residue_node.second.get<double>("<xmlattr>.wy3")};
                    residue_template.virtual_sites.back().local_position =
                            {residue_node.second.get<double>("<xmlattr>.p1"),
                             residue_node.second.get<double>("<xmlattr>.p2"),
                             residue_node.second.get<double>("<xmlattr>.p3")};
                } else {
                    BOOST_THROW_EXCEPTION(FatalError() <<
                                          "Unknown virtual site type: " << type);
                }

                auto exclude_with = residue_node.second.get_optional<int>("<xmlattr>.excludeWith");
                if (exclude_with) {
                    residue_template.virtual_sites.back().exclude_with = *exclude_with;
                } else {
                    residue_template.virtual_sites.back().exclude_with = residue_template.virtual_sites.back().atoms[0];
                }

            } else if (residue_node.first == "Bond") {
                int atom_from = residue_node.second.get<int>("<xmlattr>.from");
                int atom_to = residue_node.second.get<int>("<xmlattr>.to");
                residue_template.bonds.push_back(std::make_pair(atom_from, atom_to));
                residue_template.atoms[atom_from].bonded_to.push_back(atom_to);
                residue_template.atoms[atom_to].bonded_to.push_back(atom_from);
            } else if (residue_node.first == "ExternalBond") {
                int atom_from = residue_node.second.get<int>("<xmlattr>.from");
                residue_template.external_bonds.push_back(atom_from);
                residue_template.atoms[atom_from].external_bonds += 1;
            } else if (residue_node.first != "<xmlattr>") {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Unknown node attribute in Residues entry: " << residue_node.first);
            }
        }
    }


    for (auto &template_entry:templates) {
        const TemplateData &template_data = template_entry.second;
        //        std::string signature =
        //                Element::create_bonded_signature(
        //                        // Create vector of elements from atom vector
        //                        boost::copy_range<std::vector<Element> >(
        //                                template_data.atoms |
        //                                boost::adaptors::transformed(
        //                                        [](const TemplateAtomData &atom) {
        //                                            return atom.element;
        //                                        })),
        //                template_data.bonds);
        std::string signature =
                Element::create_signature(
                        // Create vector of elements from atom vector
                        boost::copy_range<std::vector<Element> >(
                                template_data.atoms |
                                boost::adaptors::transformed(
                                        [](const TemplateAtomData &atom) {
                                            return atom.element;
                                        })));
        templates_from_signature[signature].push_back(template_data);
        signature_from_residue_name[template_data.name] = signature;
    }

}


bool MolecularParameters::find_atom_matches(const std::vector<unsigned int> residue_atom_indices,
                                            const std::vector<Topology::Atom> &atoms,
                                            const TemplateData &residue_template,
                                            const std::vector<std::vector<int> > &bonded_to,
                                            const std::vector<int> &external_bonds,
                                            std::vector<int> &matches,
                                            std::vector<bool> &has_match,
                                            int position) const {

    if (position == residue_atom_indices.size())
        return true;

    const Topology::Atom &res_atom = atoms[residue_atom_indices[position]];
    const Element &element = res_atom.element;
    const std::string &name = res_atom.name;

    for (unsigned int i=0; i<residue_atom_indices.size(); ++i) {
        const auto &atom = residue_template.atoms[i];
        if (((atom.element != Element::UNKNOWN && atom.element == element)
             ||
             (atom.element == Element::UNKNOWN && atom.name == name))
            && !has_match[i]
            && atom.bonded_to.size() == bonded_to[position].size()
            && atom.external_bonds == external_bonds[position]) {

            bool all_bonds_match = true;
            for (auto bonded:bonded_to[position]) {
                all_bonds_match &= (bonded > position
                                    ||
                                    std::find(atom.bonded_to.begin(), atom.bonded_to.end(), matches[bonded]) != atom.bonded_to.end());
                // If bonds match, call recursively on next atom in residue
                if (all_bonds_match) {
                    matches[position] = i;
                    has_match[i] = true;

                    if (find_atom_matches(residue_atom_indices, atoms, residue_template, bonded_to, external_bonds, matches, has_match, position+1))
                        return true;

                    has_match[i] = false;
                }
            }
        }
    }


    return false;
}


std::vector<int> MolecularParameters::match_residue_atoms(const Topology::Residue &residue,
                                                          const std::vector<Topology::Atom> &atoms,
                                                          const TemplateData &residue_template,
                                                          const std::vector<std::set<int> > &bonded_to_atom) const {

    if (residue.atom_indices.size() != residue_template.atoms.size())
        return {};

    std::vector<int> matches(residue.atom_indices.size(), 0);
    std::vector<bool> has_match(residue.atom_indices.size(), false);

    std::map<int,int> atom_renumber_map;
    for (int i=0; i<residue.atom_indices.size(); ++i) {
        const Topology::Atom &atom = atoms[residue.atom_indices[i]];
        atom_renumber_map[atom.index] = i;
    }

    std::vector<std::vector<int> > bonded_to;
    std::vector<int> external_bonds;
    for (unsigned int atom_index: residue.atom_indices) {
        const Topology::Atom &atom = atoms[atom_index];
        bonded_to.push_back({});
        external_bonds.push_back(0);
        for (int bond_index: bonded_to_atom[atom.index]) {
            if (atom_renumber_map.count(bond_index)) {
                bonded_to.back().push_back(atom_renumber_map.at(bond_index));
            } else {
                external_bonds.back()++;
            }
        }
    }

    std::map<std::tuple<Element, int, int>, int> residue_type_count;
    for (int i=0; i<residue.atom_indices.size(); ++i) {
        const Topology::Atom &atom = atoms[residue.atom_indices[i]];
        std::tuple<Element, int, int> key{atom.element, bonded_to[i].size(), external_bonds[i]};
        residue_type_count[key] += 1;
    }

    std::map<std::tuple<Element, int, int>, int> template_type_count;
    for (int i=0; i<residue_template.atoms.size(); ++i) {
        const auto &atom = residue_template.atoms[i];
        std::tuple<Element, int, int> key{atom.element, atom.bonded_to.size(), atom.external_bonds};
        template_type_count[key] += 1;
    }

    if (residue_type_count != template_type_count)
        return {};

    if (find_atom_matches(residue.atom_indices, atoms, residue_template, bonded_to, external_bonds, matches, has_match)) {
        return matches;
    }

    return {};
}


std::string MolecularParameters::find_match_errors(const Topology::Residue &residue,
                                                   const std::vector<Topology::Atom> &atoms) const {

    std::vector<Element> residue_elements;
    for (unsigned int atom_index: residue.atom_indices) {residue_elements.push_back(atoms[atom_index].element);}
    auto residue_counts = Element::get_counts(residue_elements);

    int num_residue_atoms = 0;
    int num_residue_heavy_atoms = 0;
    for (auto pair: residue_counts) {
        num_residue_atoms += pair.second;
        if (pair.first != Element::UNKNOWN && pair.first != Element::HYDROGEN)
            num_residue_heavy_atoms += pair.second;
    }


    // Find closest maching template
    std::string best_match_name = "";
    //    int num_best_match_atoms = 3*num_residue_atoms;
    //    int num_best_match_heavy_atoms = 2*num_residue_heavy_atoms;
    int num_best_match_missing_atoms = 3*num_residue_atoms;
    int num_best_match_missing_heavy_atoms = 2*num_residue_heavy_atoms;
    int num_best_match_extra_atoms;
    for (const auto &template_item: templates) {
        const std::string &template_name = template_item.first;
        //bool bla = (template_name == "THR");
        const TemplateData &residue_template = template_item.second;

        std::vector<Element> template_elements;
        for (const auto &atom: residue_template.atoms) {template_elements.push_back(atom.element);}
        auto template_residue_counts = Element::get_counts(template_elements);

        // Skip if residue has any atoms not present in template
        bool any_atom_mismatch = false;
        for (const auto &item: residue_counts) {
            const Element &element = item.first;
            if (template_residue_counts.count(element) == 0 ||
                template_residue_counts.at(element) < residue_counts.at(element)) {
                any_atom_mismatch = true;
                break;
            }
        }
        if (any_atom_mismatch)
            continue;


        // Skip if residue has too many missing atoms
        int num_missing_atoms = 0;
        int num_missing_heavy_atoms = 0;
        for (auto pair: template_residue_counts) {
            int num_atoms = 0;
            if (residue_counts.count(pair.first))
                num_atoms = residue_counts.at(pair.first);
            num_missing_atoms += (pair.second - num_atoms);
            if (pair.first != Element::UNKNOWN && pair.first != Element::HYDROGEN) {
                num_missing_heavy_atoms += (pair.second - num_atoms);
            }
        }
        if (num_missing_heavy_atoms > num_best_match_missing_heavy_atoms)
            continue;
        else if ((num_missing_heavy_atoms == num_best_match_missing_heavy_atoms) &&
                 (num_missing_atoms > num_best_match_missing_atoms))
            continue;


        // If new candidate has the same number of mismatches as a previous
        // best, compare the names
        if (num_missing_atoms == num_best_match_missing_atoms) {
            if (best_match_name == residue.name || template_name.find(residue.name) == std::string::npos) {
                continue;
            }
        }

        // If non of the tests above fail, this becomes the new best candidate
        best_match_name = template_name;
        num_best_match_missing_atoms = num_missing_atoms;
        num_best_match_missing_heavy_atoms = num_missing_heavy_atoms;
        num_best_match_extra_atoms = (int) std::count_if(residue_template.atoms.begin(),
                                                         residue_template.atoms.end(),
                                                         [](const decltype(*residue_template.atoms.begin()) &atom){return atom.element == Element::UNKNOWN;});
    }

    if (num_best_match_missing_atoms == 0) {
        const auto &chain_residues = residue.chain.residues;
        std::string output_str = "The set of atoms matches template " + best_match_name + ", but the bonds are different.";
        if (chain_residues.size() > 1 && (residue.index == chain_residues[0].index ||
                                          residue.index == chain_residues[chain_residues.size()-1].index)) {
            return output_str + " Missing terminal group?";
        }
        return output_str;
    } else if (best_match_name != "") {
        std::string output_str = "The set of atoms is similar to template " + best_match_name + ", but is missing " + std::to_string(num_best_match_missing_atoms);
        if (num_best_match_missing_heavy_atoms == 0) {
            int num_residue_extra_atoms = (int) std::count_if(residue.atom_indices.begin(),
                                                              residue.atom_indices.end(),
                                                              [&](unsigned int atom_index){return atoms[atom_index].element == Element::UNKNOWN;});
            if (num_residue_extra_atoms == 0 && num_best_match_extra_atoms == 0) {
                return output_str + " hydrogen atoms.";
            } else if (num_best_match_extra_atoms - num_residue_extra_atoms == num_best_match_missing_atoms) {
                return output_str + " extra particles. ";
            }
        } else {
            return output_str + " atoms.";
        }
    } else {
        return "Your input topology is missing some atoms or bonds, or you are using the wrong force field.";
    }

    return "";
}


}



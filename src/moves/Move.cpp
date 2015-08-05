#include "quickstep/moves/Move.h"
#include "quickstep/MoveFactory.h"
#include "quickstep/MoveParameters.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <quickstep/FatalError.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <quickstep/moves/CompositeMove.h>
#include "quickstep_config.h"

namespace quickstep {


void parse_dofs(const boost::property_tree::ptree &parameter_input, std::vector<std::string> group_names = {}) {
    std::map<std::string, std::vector<MoveParameters::DofData>> dof_data;
    for (const auto &dofs_node: parameter_input) {

//        std::cout << "DOF: " << dofs_node.first << " " << group_names << "\n";
        if (dofs_node.first == "Group") {
            std::vector<std::string> group_names_local = group_names;
            group_names_local.push_back(dofs_node.second.get<std::string>("<xmlattr>.name"));
            parse_dofs(dofs_node.second, group_names_local);

        } else if (dofs_node.first == "Dihedral") {

            std::string name = dofs_node.second.get<std::string>("<xmlattr>.name");
            boost::optional<int> atomtype1 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype1");
            boost::optional<int> atomtype2 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype2");
            boost::optional<int> atomtype3 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype3");
            boost::optional<int> atomtype4 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype4");

            if (atomtype1 && atomtype2 && atomtype3 && atomtype4) {
                if (dof_data.count(name) == 0)
                    dof_data[name] = {};
                MoveParameters::DofData data;
                data.atom_types = {*atomtype1, *atomtype2, *atomtype3, *atomtype4};

                dof_data.at(name).push_back(data);

                for (const std::string &group_name: group_names) {
                    if (dof_data.count(group_name) == 0)
                        dof_data[group_name] = {};
                    dof_data.at(group_name).push_back(data);
                }
            }
        }
//        TemplateData &residue_template =
//                (templates.insert(std::make_pair(residue_name, TemplateData({residue_name})))).first->second;
//
//        for (const auto &residue_node: residues_node.second) {
//
//            if (residue_node.first == "Atom") {
//                std::string atom_name = residue_node.second.get<std::string>("<xmlattr>.name");
//                std::string atom_type = residue_node.second.get<std::string>("<xmlattr>.type");
//                residue_template.atoms.push_back(TemplateAtomData());
//                residue_template.atoms.back().name = atom_name;
//                residue_template.atoms.back().type = atom_type;
//                residue_template.atoms.back().element = atom_types.at(atom_type).element;
//
//            } else if (residue_node.first != "<xmlattr>") {
//                BOOST_THROW_EXCEPTION(FatalError() <<
//                                      "Unknown node attribute in Residues entry: " << residue_node.first);
//            }
//        }
    }

//    for (const auto &val: dof_data) {
//        std::cout << val.first << " ";
//        for (const auto &val2: val.second) {
//            std::cout << val2.atom_types  << "\n";
//        }
//    }

}


std::unique_ptr<Move> Move::parse(const std::string &xml_filename, const std::shared_ptr<Topology> &topology) {

    auto filename = boost::filesystem::path(QUICKSTEP_DATA_DIR) / xml_filename;

    if (!boost::filesystem::exists(filename)) {
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "File not found: " << filename.string());
    }

    boost::filesystem::ifstream ifs(filename);
    boost::property_tree::ptree parameter_input;
    boost::property_tree::read_xml(ifs, parameter_input, boost::property_tree::xml_parser::trim_whitespace);

    MoveParameters parameters;
    parameters.parse_from_XML(parameter_input);

    for (const auto signature: parameters.get_residue_signatures()) {
        for (const auto template_data: signature.second) {
            auto residue_matches = topology->get_residues_by_signature(signature.first);
            for (const auto residue: residue_matches) {
                std::vector<int> matches = parameters.match_residue_atoms(residue, topology->get_atoms(), template_data,
                                                                          topology->get_bond_adjacency_list());


            }
        }

//        if (!residue_matches.empty()) {
//
//        }
    }


//    // Atom types
//    std::map<std::string, AtomTypeData> atom_types;
//    for (const auto &atom_type_node: parameter_input.begin()->second.get_child("AtomTypes")) {
//
//        if (atom_type_node.first == "Type") {
//            auto &node_value = atom_type_node.second;
//            std::string name_attr = node_value.get<std::string>("<xmlattr>.name");
//            std::string class_attr = node_value.get<std::string>("<xmlattr>.class");
//            double mass_attr = node_value.get<double>("<xmlattr>.mass");
//
//            Element element = Element::UNKNOWN;
//            boost::optional<std::string> element_attr = node_value.get_optional<std::string>("<xmlattr>.element");
//            if (element_attr)
//                element = Element::get_by_symbol(*element_attr);
//
//            if (atom_types.count(name_attr)) {
//                BOOST_THROW_EXCEPTION(FatalError() <<
//                                      "Multiple definitions of atom type: " << name_attr);
//            }
//            atom_types.insert(std::make_pair(name_attr,
//                                             AtomTypeData({class_attr,
//                                                           mass_attr,
//                                                           element})));
//        } else if (atom_type_node.first == "<xmlcomment>") {
//            continue;
//        } else if (atom_type_node.first != "<xmlattr>") {
//            BOOST_THROW_EXCEPTION(FatalError() <<
//                                  "Unknown node attribute in AtomTypes entry: " << atom_type_node.first);
//        }
//    }
//
//    // Residue templates
//    std::map<std::string, TemplateData> templates;
//    for (const auto &residues_node: parameter_input.begin()->second.get_child("Residues")) {
//
//        std::string residue_name = residues_node.second.get<std::string>("<xmlattr>.name");
//
//        TemplateData &residue_template =
//                (templates.insert(std::make_pair(residue_name, TemplateData({residue_name})))).first->second;
//
//        for (const auto &residue_node: residues_node.second) {
//
//            if (residue_node.first == "Atom") {
//                residue_template.atoms.push_back(TemplateAtomData());
//
//                std::string atom_name = residue_node.second.get<std::string>("<xmlattr>.name");
//                residue_template.atoms.back().name = atom_name;
//
//                // Check if atom information is given through atom type
//                boost::optional<std::string> atom_type = residue_node.second.get_optional<std::string>("<xmlattr>.type");
//                if (atom_type)
//                    residue_template.atoms.back().element = atom_types.at(*atom_type).element;
//                else {
//
//                    Element element = Element::UNKNOWN;
//                    boost::optional<std::string> element_attr = residue_node.second.get_optional<std::string>("<xmlattr>.element");
//                    if (element_attr)
//                        element = Element::get_by_symbol(*element_attr);
//                    residue_template.atoms.back().element = element;
//                }
//
//            } else if (residue_node.first == "Bond") {
//                int atom_from = residue_node.second.get<int>("<xmlattr>.from");
//                int atom_to = residue_node.second.get<int>("<xmlattr>.to");
//                residue_template.bonds.push_back(std::make_pair(atom_from, atom_to));
//                residue_template.atoms[atom_from].bonded_to.push_back(atom_to);
//                residue_template.atoms[atom_to].bonded_to.push_back(atom_from);
//            } else if (residue_node.first == "ExternalBond") {
//                int atom_from = residue_node.second.get<int>("<xmlattr>.from");
//                residue_template.external_bonds.push_back(atom_from);
//                residue_template.atoms[atom_from].external_bonds += 1;
//            } else if (residue_node.first != "<xmlattr>") {
//                BOOST_THROW_EXCEPTION(FatalError() <<
//                                      "Unknown node attribute in Residues entry: " << residue_node.first);
//            }
//        }
//    }
//
//
//    std::map<std::string, std::vector<TemplateData> > template_signatures;
//    for (auto &template_entry:templates) {
//        TemplateData template_data = template_entry.second;
////        std::string signature =
////                Element::create_bonded_signature(
////                        // Create vector of elements from atom vector
////                        boost::copy_range<std::vector<Element> >(
////                                template_data.atoms |
////                                boost::adaptors::transformed(
////                                        [](const TemplateAtomData &atom) {
////                                            return atom.element;
////                                        })),
////                template_data.bonds);
//        std::string signature =
//                Element::create_signature(
//                        // Create vector of elements from atom vector
//                        boost::copy_range<std::vector<Element> >(
//                                template_data.atoms |
//                                boost::adaptors::transformed(
//                                        [](const TemplateAtomData &atom) {
//                                            return atom.element;
//                                        })));
//        std::cout << "Signature: " << template_data.name << " " << signature << "\n";
//        std::cout << "In topology: " << topology->get_residues_by_signature(signature) << "\n";
//        template_signatures[signature].push_back(template_data);
//    }
//
//
//    // dofs
//    parse_dofs(parameter_input.begin()->second.get_child("Dofs"));

    auto root_node = parameter_input.begin();
    const std::string &node_name = root_node->first;
    if (MoveFactory::get().has_generator(node_name)) {
        auto &&moves = MoveFactory::get().at(node_name)(root_node->second, *topology.get(), parameters);
        if (moves.size() == 1)
            return std::move(moves[0]);
        else {
            auto composite = std::make_unique<CompositeMove>();
            for (auto &move: moves) {
                composite->add_move(std::move(move));
            }
            return std::move(composite);
        }
    } else {
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "No MoveGenerator found for : " << node_name);
    }



}

}
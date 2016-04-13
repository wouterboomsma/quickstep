#include "quickstep/MoveParameters.h"
#include <qsboost/algorithm/string.hpp>
//#include "quickstep/Topology.h"
//#include "quickstep/Element.h"
#include "quickstep/FatalError.h"
//#include <boost/filesystem/fstream.hpp>
#include <qsboost/property_tree/ptree.hpp>
//#include <boost/property_tree/xml_parser.hpp>
//#include <boost/range/adaptor/transformed.hpp>

namespace quickstep {


void MoveParameters::parse_dofs(const qsboost::property_tree::ptree &parameter_input, std::vector<std::string> group_names) {
    for (const auto &dofs_node: parameter_input) {

//        std::cout << "DOF: " << dofs_node.first << " " << group_names << "\n";
        if (dofs_node.first == "Group") {
            std::vector<std::string> group_names_local = group_names;
            group_names_local.push_back(dofs_node.second.get<std::string>("<xmlattr>.name"));
            parse_dofs(dofs_node.second, group_names_local);

        } else if (dofs_node.first == "Dihedral") {

            std::string name = dofs_node.second.get<std::string>("<xmlattr>.name");

            MoveParameters::DofData data;

            std::string residue = dofs_node.second.get<std::string>("<xmlattr>.residue");
            qsboost::split(data.residue_names, residue, qsboost::is_any_of("|"));

            std::string atom1 = dofs_node.second.get<std::string>("<xmlattr>.atom1");
            std::string atom2 = dofs_node.second.get<std::string>("<xmlattr>.atom2");
            std::string atom3 = dofs_node.second.get<std::string>("<xmlattr>.atom3");
            std::string atom4 = dofs_node.second.get<std::string>("<xmlattr>.atom4");
            data.atom_names = {atom1, atom2, atom3, atom4};

            if (dof_data.count(name) > 0) {
                QSBOOST_THROW_EXCEPTION(FatalError() <<
                                      "Multiple definitions of dof: " << name);
            }
            dof_data[name] = data;
        } else if (dofs_node.first == "BondAngle") {

            std::string name = dofs_node.second.get<std::string>("<xmlattr>.name");

            MoveParameters::DofData data;

            std::string residue = dofs_node.second.get<std::string>("<xmlattr>.residue");
            qsboost::split(data.residue_names, residue, qsboost::is_any_of("|"));

            std::string atom1 = dofs_node.second.get<std::string>("<xmlattr>.atom1");
            std::string atom2 = dofs_node.second.get<std::string>("<xmlattr>.atom2");
            std::string atom3 = dofs_node.second.get<std::string>("<xmlattr>.atom3");
            data.atom_names = {atom1, atom2, atom3};

            std::cout << data.atom_names << "\n";

            if (dof_data.count(name) > 0) {
                QSBOOST_THROW_EXCEPTION(FatalError() <<
                                        "Multiple definitions of dof: " << name);
            }
            dof_data[name] = data;
        } else if (dofs_node.first == "BondLength") {

            std::string name = dofs_node.second.get<std::string>("<xmlattr>.name");

            MoveParameters::DofData data;

            std::string residue = dofs_node.second.get<std::string>("<xmlattr>.residue");
            qsboost::split(data.residue_names, residue, qsboost::is_any_of("|"));

            std::string atom1 = dofs_node.second.get<std::string>("<xmlattr>.atom1");
            std::string atom2 = dofs_node.second.get<std::string>("<xmlattr>.atom2");
            data.atom_names = {atom1, atom2};

            if (dof_data.count(name) > 0) {
                QSBOOST_THROW_EXCEPTION(FatalError() <<
                                        "Multiple definitions of dof: " << name);
            }
            dof_data[name] = data;
        }

//            if (atom1 && atom2 && atom3 && atom4) {
//                for (std::string residue: residues) {
//                    MoveParameters::DofData data;
//                    data.residue_name = residue;
//                    data.atom_names = {*atom1, *atom2, *atom3, *atom4};
//                    dof_data.at(name).push_back(data);
//
//                    for (const std::string &group_name: group_names) {
//                        if (dof_data.count(group_name) == 0)
//                            dof_data[group_name] = {};
//                        dof_data.at(group_name).push_back(data);
//                    }
//                }
//            }
//        }

//            qsboost::optional<int> atomtype1 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype1");
//            qsboost::optional<int> atomtype2 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype2");
//            qsboost::optional<int> atomtype3 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype3");
//            qsboost::optional<int> atomtype4 = dofs_node.second.get_optional<int>("<xmlattr>.atomtype4");
//
//            qsboost::optional<std::string> atom1 = dofs_node.second.get_optional<std::string>("<xmlattr>.atom1");
//            qsboost::optional<std::string> atom2 = dofs_node.second.get_optional<std::string>("<xmlattr>.atom2");
//            qsboost::optional<std::string> atom3 = dofs_node.second.get_optional<std::string>("<xmlattr>.atom3");
//            qsboost::optional<std::string> atom4 = dofs_node.second.get_optional<std::string>("<xmlattr>.atom4");
//
//            if (atomtype1 && atomtype2 && atomtype3 && atomtype4) {
//                if (dof_data.count(name) == 0)
//                    dof_data[name] = {};
//                MoveParameters::DofData data;
//                data.atom_types = {*atomtype1, *atomtype2, *atomtype3, *atomtype4};
//
//                dof_data.at(name).push_back(data);
//
//                for (const std::string &group_name: group_names) {
//                    if (dof_data.count(group_name) == 0)
//                        dof_data[group_name] = {};
//                    dof_data.at(group_name).push_back(data);
//                }
//            } else if (atom1 && atom2 && atom3 && atom4) {
//
//            }
//        }
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

void MoveParameters::parse_from_XML(const qsboost::property_tree::ptree &parameter_input) {
    MolecularParameters::parse_from_XML(parameter_input);

    // dofs
    parse_dofs(parameter_input.begin()->second.get_child("Dofs"));

}

}



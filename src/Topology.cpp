#include "quickstep/Topology.h"

#include <fstream>
#include <vector>
#include <array>
#include <boost/units/cmath.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <quickstep_config.h>
#include "quickstep/FatalError.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include "prettyprint.hpp"
#include <boost/range/adaptor/transformed.hpp>

namespace quickstep {

std::map<std::string, std::vector<std::pair<std::string, std::string> > > Topology::standard_bond_definitions = std::map<std::string, std::vector<std::pair<std::string, std::string> > >();

void Topology::load_bond_definitions(const boost::filesystem::path &filename) {

    if (!boost::filesystem::exists(filename)) {
        //    	throw "File not found";
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "File not found: " << filename.string());
    }

    boost::property_tree::ptree ptree;
    std::ifstream ifs(filename.string());
    boost::property_tree::read_xml(ifs, ptree);

    // First parse general entries
    for (auto res_node: ptree.get_child("Residues")) {

        std::string residue_name = res_node.second.get_child("<xmlattr>.name").data();

        auto &bonds = (standard_bond_definitions.insert(std::make_pair(residue_name,
                                                                       std::vector<std::pair<std::string, std::string> >())).first->second);
        for (auto bond_node: res_node.second) {
            if (bond_node.first == "Bond") {
                bonds.push_back(std::make_pair(bond_node.second.get<std::string>("<xmlattr>.from"),
                                               bond_node.second.get<std::string>("<xmlattr>.to")));
            }
        }
    }
}

void Topology::create_standard_bonds() {
    if (Topology::standard_bond_definitions.empty()) {
        load_bond_definitions(boost::filesystem::path(QUICKSTEP_DATA_DIR) / "openmm" / "residues.xml");
    }

    std::vector<std::map<std::string, std::reference_wrapper<Atom> > > atom_maps;
    for (Chain &chain:chains) {
        for (Residue &residue:chain.residues) {
            atom_maps.push_back(std::map<std::string, std::reference_wrapper<Atom> >());
            //<<<<<<< HEAD:external/quickstep/src/Topology.cpp
            //            for (Atom &atom:residue.atoms) {
            ////                atom_maps.back().insert(std::make_pair(atom.name, std::reference_wrapper<Atom>(atom)));
            //                atom_maps.back().insert(std::pair<std::string,std::reference_wrapper<Atom> >(atom.name, std::reference_wrapper<Atom>(atom)));
            //
            //                std::cout << "****" << atom_maps.back() << " ";
            //                std::cout << atom << "\n";
            //                std::cout << residue.index << "\n";
            //=======
            for (unsigned int &atom_index: residue.atom_indices) {
                Atom &atom = atoms[atom_index];
                atom_maps.back().insert(std::make_pair(atom.name, std::reference_wrapper<Atom>(atom)));
                //>>>>>>> 4f62ba27dab83711a0e465479c0e9b3550e3b881:src/Topology.cpp
            }
        }

        for (int i = 0; i < chain.residues.size(); ++i) {
            Residue &residue = chain.residues[i];
            std::string name = residue.name;
            auto bond_vec_it = standard_bond_definitions.find(name);
            int from_residue;
            int to_residue;
            std::string from_atom;
            std::string to_atom;
            if (bond_vec_it != standard_bond_definitions.end()) {
                for (auto bond: bond_vec_it->second) {
                    if (bond.first[0] == '-' && i > 0) {
                        from_residue = i - 1;
                        from_atom = bond.first.substr(1);
                    }
                    else if (bond.first[0] == '+' && i < chain.residues.size()) {
                        from_residue = i + 1;
                        from_atom = bond.first.substr(1);
                    }
                    else {
                        from_residue = i;
                        from_atom = bond.first;
                    }

                    if (bond.second[0] == '-' && i > 0) {
                        to_residue = i - 1;
                        to_atom = bond.second.substr(1);
                    }
                    else if (bond.second[0] == '+' && i < chain.residues.size()) {
                        to_residue = i + 1;
                        to_atom = bond.second.substr(1);
                    }
                    else {
                        to_residue = i;
                        to_atom = bond.second;
                    }

                    auto from_atom_it = atom_maps[from_residue].find(from_atom);
                    auto to_atom_it = atom_maps[to_residue].find(to_atom);
                    if (from_atom_it != atom_maps[from_residue].end() &&
                        to_atom_it != atom_maps[to_residue].end())
                        this->add_bond(from_atom_it->second,
                                       to_atom_it->second);
                }
            }
        }
    }
}


void Topology::create_disulfide_bonds(const units::Coordinates &positions) {


    auto is_cyx = [&](const Residue &residue) {
        std::set<std::string> atom_names;
        for (unsigned int atom_index: residue.atom_indices) {
            const Atom &atom = this->atoms[atom_index];
            atom_names.insert(atom.name);
        }
        return (atom_names.count("SG") and !atom_names.count("HG"));
    };

    std::vector<std::reference_wrapper<const Residue> > cyx;
    for (const Chain &chain: chains) {
        for (const Residue &residue: chain.residues) {
            if (residue.name == "CYS" and is_cyx(residue)) {
                cyx.push_back(std::reference_wrapper<const Residue>(residue));
            }
        }
    }

    std::vector<std::map<std::string, std::reference_wrapper<const Atom> > > cyx_atoms_by_name;
    for (const Residue &residue: cyx) {
        cyx_atoms_by_name.push_back(std::map<std::string, std::reference_wrapper<const Atom> >());
        for (unsigned int atom_index: residue.atom_indices) {
            const Atom &atom = atoms[atom_index];
            cyx_atoms_by_name.back().insert(std::make_pair(atom.name, std::reference_wrapper<const Atom>(atom)));
        }
    }

    for (int i = 0; i < cyx.size(); ++i) {
        const Atom &sg1 = cyx_atoms_by_name[i].at("SG");
        auto pos1 = positions.col(sg1.index);
        for (int j = 0; j < i; ++j) {
            const Atom &sg2 = cyx_atoms_by_name[j].at("SG");
            auto &pos2 = positions.col(sg2.index);
            units::Length distance = boost::units::root<2>(boost::units::pow<2>(pos2[0] - pos1[0]) +
                                                           boost::units::pow<2>(pos2[1] - pos1[1]) +
                                                           boost::units::pow<2>(pos2[2] - pos1[2]));
            if (distance < 0.3 * units::nm) {
                this->add_bond(sg1, sg2);
            }
        }
    }
}

const std::vector<std::reference_wrapper<const Topology::Residue>> &Topology::get_residues_by_signature(const std::string &query_signature) {

    if (residue_template_signatures.empty()) {
        for (const auto &chain: get_chains()) {
            for (const auto &residue: chain.residues) {
                std::map<int,int> atom_index_map;
                std::vector<std::pair<int,int> > residue_bonds;
                for (unsigned int i=0; i<residue.atom_indices.size(); ++i) {
                    int atom_index = residue.atom_indices[i];
                    atom_index_map[atom_index] = i;
                }

                for (unsigned int i=0; i<residue.atom_indices.size(); ++i) {
                    int atom_index = residue.atom_indices[i];
                    for (int bonded_atom_index: get_bond_adjacency_list().at(atom_index)) {
                        // adjacency list includes external bonds - which we exclude here
                        if (atom_index_map.count(bonded_atom_index)) {
                            residue_bonds.push_back(std::make_pair(i,
                                                                   atom_index_map.at(bonded_atom_index)));
                        }
                    }
                }

                std::string signature =
                        Element::create_bonded_signature(
                                // Create vector of elements from atom vector
                                boost::copy_range<std::vector<Element> >(
                                        residue.atom_indices |
                                        boost::adaptors::transformed(
                                                [&](unsigned int atom_index) {
                                                    return get_atoms()[atom_index].element;
                                                }
                                        )
                                ),
                                residue_bonds
                        );
                // map::operator[] implicitly adds empty vector if key is not found
//                residue_template_signatures[signature].push_back(std::make_pair(chain.index, residue.index));
                residue_template_signatures[signature].push_back(std::cref(residue));
            }
        }
        // Add empty entry used when match fails
        residue_template_signatures[""] = {};
    }

    auto it = residue_template_signatures.find(query_signature);
    if (it != residue_template_signatures.end())
        return it->second;
    else
        return residue_template_signatures.at("");
}

const std::vector<std::set<int>> &Topology::get_bond_adjacency_list() {
    if (bond_adjacency_list.empty()) {
        for (int i = 0; i < n_atoms; ++i) {
            bond_adjacency_list.push_back(std::set<int>());
        }
        for (const auto &bond: bonds) {
            bond_adjacency_list[bond.first.get().index].insert(bond.second.get().index);
            bond_adjacency_list[bond.second.get().index].insert(bond.first.get().index);
        }
    }
    return bond_adjacency_list;
}

}
#ifndef QUICKSTEP_TOPOLOGY_H
#define QUICKSTEP_TOPOLOGY_H

#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <list>

//#include <boost/filesystem/path.hpp>
#include <qsboost/optional/optional.hpp>
//#include <optional.hpp>
#include "prettyprint.hpp"

#include "quickstep/Element.h"
#include "quickstep/units.h"
#include "utils.h"

namespace quickstep {

class Selection;

class Topology {
public:

    class Residue;

    class Chain;

    Topology()
            : n_atoms(0) { }

    Topology(Topology &&other) = default;


    class Atom {
    public:
        Atom(std::string name, const Element &element, unsigned int index, const Residue &residue) :
                name(name),
                element(element),
                index(index),
                residue(residue) {
        }

        std::string name;
        Element element;
        unsigned int index;
        const Residue &residue;

        friend bool operator<(const Atom &atom1, const Atom &atom2) {
            return atom1.index < atom2.index;
        }

        //! Overload output operator
        friend std::ostream &operator<<(std::ostream &o, const Atom &atom) {
            o << "{"
            << "name:" << atom.name << ","
            << "element:" << atom.element << ","
            << "index:" << atom.index << "}";
            return o;
        }
    };

    class Residue {
    public:
        Residue(std::string name, unsigned int index, Chain &chain)
                : name(name),
                  index(index),
                  chain(chain) {
        }

        std::vector<std::reference_wrapper<const Atom>> get_atoms_by_name(const std::string &name) const {
            std::vector<std::reference_wrapper<const Atom>> matches;
            for (int atom_index: atom_indices) {
                const Topology::Atom &atom = chain.topology.atoms[atom_index];
                if (atom.name == name)
                    matches.push_back(std::ref(atom));
            }
            return std::move(matches);
        }
        //        std::string create_signature() const {
        //            std::map<Element, int> counts;
        //            for (const Atom &atom: atoms) {
        //                if (!counts.count(atom.element))
        //                    counts.insert(std::make_pair(atom.element, 0));
        //                counts.at(atom.element) += 1;
        //            }
        //            std::vector<std::pair<Element, int> > signature_vec;
        //            for (const auto &entry:counts) {
        //                signature_vec.push_back(entry);
        //            }
        //            std::sort(signature_vec.begin(), signature_vec.end());
        //            std::string signature = "";
        //            for (const auto &entry:counts) {
        //                signature += entry.first.symbol+std::to_string(entry.second);
        //            }
        ////            std::cout << signature_vec << " " << signature << "\n";
        //            return signature;
        //        }

        std::string name;
        unsigned int index;
        const Chain &chain;
        std::vector<unsigned int> atom_indices;

        //! Overload output operator
        friend std::ostream &operator<<(std::ostream &o, const Residue &residue) {
            o << "{"
            << "name:" << residue.name << ","
            << "index:" << residue.index << "}";
            return o;
        }

    };

    class Chain {
    public:
        Chain(unsigned int index, const Topology &topology)
                : index(index),
                  topology(topology) {
        }

        unsigned int index;
        const Topology &topology;
        std::list<Residue> residues;
    };

    Chain &add_chain() {
        chains.push_back(Chain(chains.size(), *this));
        n_residues.push_back(0);
        return chains.back();
    }

    Residue &add_residue(std::string name, Chain &chain) {
        chain.residues.push_back(Residue(name, n_residues[chain.index], chain));
        n_residues[chain.index]++;
        return chain.residues.back();
    }

    Atom &add_atom(std::string name, const Element &element, Residue &residue) {
        atoms.push_back(Atom(name, element, n_atoms, residue));
        residue.atom_indices.push_back(n_atoms);
        n_atoms++;
        return atoms.back();
    }

    void add_bond(int atom_idx1, int atom_idx2) {
        int atom_min_idx = std::min(atom_idx1, atom_idx2);
        int atom_max_idx = std::max(atom_idx1, atom_idx2);
        bonds.insert(std::make_pair(atom_min_idx, atom_max_idx));
    }

    void add_bond(const Atom &atom1, const Atom &atom2) {
        const Atom &atom_min_idx = std::min(atom1, atom2);
        const Atom &atom_max_idx = std::max(atom1, atom2);
        //        bonds.insert(std::make_pair(std::reference_wrapper<const Atom>(atom_min_idx),
        //                                    std::reference_wrapper<const Atom>(atom_max_idx)));
        bonds.insert(std::make_pair(atom_min_idx.index, atom_max_idx.index));
    }

    void create_standard_bonds();

    void create_disulfide_bonds(const Coordinates &positions);

    std::list<Chain> const &get_chains() const {
        return chains;
    }

    std::vector<Atom> const &get_atoms() const {
        return atoms;
    }

    std::set<std::pair<int, int> > const &get_bonds() const {
        return bonds;
    }

    const qsboost::optional<Array3d> &get_unit_cell_dimensions() const {
        return unit_cell_dimensions;
    }

    void set_unit_cell_dimensions(const Array3d &dimensions) {
        unit_cell_dimensions = dimensions;
    }

    //    const std::vector<std::pair<int,int>> &get_residues_by_signature(const std::string &signature_str);
    const std::vector<std::reference_wrapper<const Residue>> &get_residues_by_signature(
            const std::string &signature_str);

    const std::vector<std::set<int>> &get_bond_adjacency_list();

    std::vector<unsigned int> n_residues;
    unsigned int n_atoms;

    std::vector<Atom> atoms;

    std::list<Chain> chains;

    Selection select(const std::string &selection_string);

    //    std::set<std::pair<std::reference_wrapper<const Atom>, std::reference_wrapper<const Atom> > > bonds;
    std::set<std::pair<int, int> > bonds;

    std::map<std::string, std::vector<std::reference_wrapper<const Residue>>> residue_template_signatures;

private:

    static void load_bond_definitions(const std::string &filename);

    static std::map<std::string, std::vector<std::pair<std::string, std::string> > > standard_bond_definitions;

    //    std::map<std::string, std::vector<std::pair<int,int> > > residue_template_signatures;
    //std::map<std::string, std::vector<std::reference_wrapper<const Residue>>> residue_template_signatures;
    std::vector<std::set<int>> bond_adjacency_list;

    qsboost::optional<Array3d> unit_cell_dimensions;

    // Prevent copying
    Topology(const Topology &other) = delete;

    Topology &operator=(const Topology &other) = delete;
};


Topology filter(const Selection &selection, const Topology &source);


}

#endif

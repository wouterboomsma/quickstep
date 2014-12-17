#ifndef QUICKSTEP_TOPOLOGY_H
#define QUICKSTEP_TOPOLOGY_H

#include <iostream>
#include <vector>
#include <set>
#include <boost/filesystem/path.hpp>

#include "quickstep/Element.h"

namespace quickstep {

class Topology {
public:

    class Residue;
    class Chain;

    Topology()
            :n_atoms(0),
             n_residues(0){}

    class Atom {
    public:
        Atom(std::string name, const Element &element, unsigned int index, const Residue &residue):
                name(name),
                element(element),
                index(index),
                residue(residue) {
        }

        std::string name;
        Element element;
        unsigned int index;
        const Residue &residue;

        friend bool operator< (const Atom &atom1, const Atom &atom2) {
            return atom1.index < atom2.index;
        }

        //! Overload oudtput operator
        friend std::ostream& operator<<(std::ostream& o, const Atom &atom) {
            o << "{"
              << "name:" << atom.name << ","
              << "element:" << atom.element << ","
              << "index:"<< atom.index << "}";
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
        std::string name;
        unsigned int index;
        const Chain &chain;
        std::vector<Atom> atoms;
    };

    class Chain {
    public:
        Chain(unsigned int index, const Topology &topology)
                : index(index),
                  topology(topology) {
        }
        unsigned int index;
        const Topology &topology;
        std::vector<Residue> residues;
    };

    Chain &add_chain(){
        chains.push_back(Chain(chains.size(), *this));
        return chains.back();
    }

    Residue &add_residue(std::string name, Chain &chain){
        chain.residues.push_back(Residue(name, n_residues, chain));
        n_residues++;
        return chain.residues.back();
    }

    Atom &add_atom(std::string name, const Element &element, Residue &residue) {
        residue.atoms.push_back(Atom(name, element, n_atoms, residue));
        n_atoms++;
        std::cout << "Adding: " << name << " " <<  n_atoms << "\n";
        return residue.atoms.back();
    }

    void add_bond(const Atom &atom1, const Atom &atom2) {
        const Atom &atom_min_idx = std::min(atom1, atom2);
        const Atom &atom_max_idx = std::max(atom1, atom2);
        bonds.insert(std::make_pair(std::reference_wrapper<const Atom>(atom_min_idx),
                                    std::reference_wrapper<const Atom>(atom_max_idx)));
    }

    void create_standard_bonds();
    void create_disulfide_bonds(const std::vector<std::array<coordinate_t, 3> > &positions);


    std::vector<Chain> const &get_chains() const {
        return chains;
    }

    std::set<std::pair<std::reference_wrapper<const Atom>, std::reference_wrapper<const Atom> > > const &get_bonds() const {
//    std::set<std::pair<int,int > > const &get_bonds() const {
        return bonds;
    }

private:
    std::vector<Chain> chains;
    unsigned int n_residues;
    unsigned int n_atoms;
    std::set<std::pair<std::reference_wrapper<const Atom>, std::reference_wrapper<const Atom> > > bonds;
//    std::set<std::pair<int,int> > bonds;


    static void load_bond_definitions(const boost::filesystem::path &filename);
    static std::map<std::string, std::vector<std::pair<std::string, std::string> > > standard_bond_definitions;

};

}

#endif

#include "quickstep/dofs/DihedralDof.h"
#include "quickstep/KinematicForest.h"

using namespace quickstep;

//DihedralDof::DihedralDof(KinematicForest &forest,
//                         std::vector<int> atom_indices,
//                         std::vector<std::string> atom_names)
//        : Dof(forest, atom_indices.back()) {
//    if (!atom_names.empty() && !forest.atom_matches_names(atom_indices.back(), atom_names)) {
//        BOOST_THROW_EXCEPTION(FatalError() <<
//                              "Length Dof (" << atom_names << ") is not found in KinematicForest.");
//    }
//
//
//}

DihedralDof::DihedralDof(KinematicForest &forest, int atom_index)
    : Dof(forest, atom_index, Dof::DIHEDRAL){

    //Collect all children of parent
    int parent_index = forest.get_parent(atom_index);
    sibling_atom_indices = forest.get_children(parent_index);
}

double DihedralDof::get_value() {
    return forest.get_torsion(this->atom_index).value();
};

void DihedralDof::add_value(double delta_value) {
    for(int i: sibling_atom_indices)
        forest.change_torsion(i, units::Angle::from_value(delta_value));
}

double DihedralDof::log_jacobian(double value) {
    return 0.;
}

double DihedralDof::wrap_to_domain(double value) {
    return std::fmod(std::fmod(value + M_PI, 2 * M_PI) + 2 * M_PI, 2 * M_PI) - M_PI;
};



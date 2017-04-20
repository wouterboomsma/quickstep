#include "quickstep/dofs/LengthDof.h"
#include "quickstep/KinematicForest.h"

using namespace quickstep;

//LengthDof::LengthDof(KinematicForest &forest,
//                     std::vector<int> atom_indices,
//                     std::vector<std::string> atom_names)
//        : Dof(forest, atom_indices.back()) {
//    if (!atom_names.empty() && !forest.atom_matches_names(atom_indices.back(), atom_names)) {
//        BOOST_THROW_EXCEPTION(FatalError() <<
//                              "Length Dof (" << atom_names << ") is not found in KinematicForest.");
//    }
//}

//LengthDof::LengthDof(KinematicForest &forest, int atom_index):
LengthDof::LengthDof(std::vector<int> atom_indices):
        Dof(atom_indices, Dof::LENGTH) {}

//double LengthDof::get_value() {
//    return forest.get_length(this->atom_index).value();
//};
//
//void LengthDof::add_value(double delta_value) {
//    forest.change_length(this->atom_index, units::Length::from_value(delta_value));
//}

double LengthDof::log_jacobian(double value) {
    return 2.*std::log(value);
}

double LengthDof::wrap_to_domain(double value) {
    return value;
};



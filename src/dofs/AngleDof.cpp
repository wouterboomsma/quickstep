#include "quickstep/dofs/AngleDof.h"
#include "quickstep/KinematicForest.h"

using namespace quickstep;

//AngleDof::AngleDof(KinematicForest &forest,
//                   std::vector<int> atom_indices,
//                   std::vector<std::string> atom_names)
//        : Dof(forest, atom_indices.back()) {
//    if (!atom_names.empty() && !forest.atom_matches_names(atom_indices.back(), atom_names)) {
//        BOOST_THROW_EXCEPTION(FatalError() <<
//                              "Length Dof (" << atom_names << ") is not found in KinematicForest.");
//    }
//}

AngleDof::AngleDof(KinematicForest &forest, int atom_index):
        Dof(forest, atom_index, Dof::ANGLE){}

double AngleDof::get_value() {
    return forest.get_angle(this->atom_index).value();
};

void AngleDof::add_value(double delta_value) {
    forest.change_angle(this->atom_index, units::Angle::from_value(delta_value));
};



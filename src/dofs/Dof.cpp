#include "quickstep/dofs/Dof.h"
#include "quickstep/dofs/LengthDof.h"
#include "quickstep/dofs/AngleDof.h"
#include "quickstep/dofs/DihedralDof.h"
#include "quickstep/KinematicForest.h"

using namespace quickstep;

std::unique_ptr<Dof> Dof::construct(KinematicForest &forest,
                                    const std::vector<int> &atom_indices,
                                    const std::vector<std::string> &atom_names) {

    if (!atom_names.empty() && !forest.atom_matches_names(atom_indices.back(), atom_names)) {
        QSBOOST_THROW_EXCEPTION(FatalError() <<
                              "Dof (" << atom_names << ") is not found in KinematicForest.");
    }

    // Either use first or last index in atom array as representative
    switch (atom_indices.size()) {
        case 2:
            return std::make_unique<LengthDof>(forest,
                                               ((forest.get_parent(atom_indices[0]) == atom_indices[1]) ?
                                                atom_indices[0] : atom_indices[1]));
        case 3:
            return std::make_unique<AngleDof>(forest,
                                              ((forest.get_parent(atom_indices[0]) == atom_indices[1]) ?
                                               atom_indices[0] : atom_indices[2]));
        case 4:
            return std::make_unique<DihedralDof>(forest,
                                                 ((forest.get_parent(atom_indices[0]) == atom_indices[1]) ?
                                                  atom_indices[0] : atom_indices[3]));
        default:
            QSBOOST_THROW_EXCEPTION(FatalError() <<
                                  "Unexpected number of atoms specified for DoF (" << atom_indices.size() << ")");
    }
}


void Dof::set_value(double value) {
    add_value( - get_value() + value);
}

const int Dof::get_atom_index() { return atom_index; }

const std::vector<std::vector<int>> Dof::get_atoms() {
    return {forest.get_ancestors(atom_index, type)};
}

Dof::Type Dof::get_type() {
    return type;
}

KinematicForest &Dof::get_forest() {
    return forest;
}



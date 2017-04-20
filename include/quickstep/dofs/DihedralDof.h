#ifndef QUICKSTEP_DIHEDRAL_DOF_H
#define QUICKSTEP_DIHEDRAL_DOF_H

#include "quickstep/dofs/Dof.h"

namespace quickstep {

class DihedralDof: public Dof {
public:
    //DihedralDof(KinematicForest &forest,
    //         std::vector<int> atom_indices,
    //         std::vector<std::string> atom_names);

    //DihedralDof(KinematicForest &forest,
    //            int atom_index);
    DihedralDof(std::vector<int> atom_indices,
                std::vector<int> sibling_atom_indices);

    //double get_value() override;
    //
    //void add_value(double delta_value) override;

    double log_jacobian(double value) override;

    double wrap_to_domain(double value) override;

private:
    std::vector<int> sibling_atom_indices;

};

}

#endif //PHAISTOS_DIHEDRAL_DOF_H

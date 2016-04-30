#ifndef QUICKSTEP_ANGLE_DOF_H
#define QUICKSTEP_ANGLE_DOF_H

#include "quickstep/dofs/Dof.h"

namespace quickstep {

class AngleDof: public Dof {
public:
    //AngleDof(KinematicForest &forest,
    //         std::vector<int> atom_indices,
    //         std::vector<std::string> atom_names);

    AngleDof(KinematicForest &forest,
             int atom_index);

    double get_value() override;

    void add_value(double delta_value) override;

    double log_jacobian(double value) override;

    double wrap_to_domain(double value) override;

};

}

#endif //PHAISTOS_ANGLE_DOF_H

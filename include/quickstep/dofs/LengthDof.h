#ifndef QUICKSTEP_LENGTH_DOF_H
#define QUICKSTEP_LENGTH_DOF_H

#include "quickstep/dofs/Dof.h"

namespace quickstep {

class LengthDof: public Dof {
public:
    //LengthDof(KinematicForest &forest,
    //          std::vector<int> atom_indices,
    //          std::vector<std::string> atom_names);

    //LengthDof(KinematicForest &forest,
    //          int atom_index);
    LengthDof(std::vector<int> atom_indices);

    //double get_value() override;
    //
    //void add_value(double delta_value) override;

    double log_jacobian(double value) override;

    virtual double wrap_to_domain(double value) override;

};

}

#endif //PHAISTOS_LENGTH_DOF_H

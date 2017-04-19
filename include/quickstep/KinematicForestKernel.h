#ifndef QUICKSTEP_KINEMATIC_FOREST_KERNEL_H
#define QUICKSTEP_KINEMATIC_FOREST_KERNEL_H

#include <string>
#include "quickstep/KernelImpl.h"
#include "quickstep/dofs/Dof.h"

namespace quickstep {

class KinematicForest;

class KinematicForestKernel: public KernelImpl {
public:
    static const std::string Name() {
        return "KinematicForest";
    }

    virtual void initialize(const KinematicForest& kinematic_forest) = 0;

    virtual void update_positions(std::vector<std::pair<Dof, double> >) = 0;

};

}

#endif

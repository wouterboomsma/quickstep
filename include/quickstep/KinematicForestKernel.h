#ifndef QUICKSTEP_KINEMATIC_FOREST_KERNEL_H
#define QUICKSTEP_KINEMATIC_FOREST_KERNEL_H

#include <string>
#include <vector>
#include "quickstep/KernelImpl.h"
#include "quickstep/dofs/Dof.h"

namespace quickstep {

class KinematicForest;

class KinematicForestKernel: public KernelImpl {
public:
    static const std::string Name() {
        return "KinematicForest";
    }

    virtual void initialize(const KinematicForest& kinematic_forest,
                            std::vector<std::vector<std::pair<int, int> > > &adjacency_list,
                            std::vector<int> &roots) = 0;

    virtual void update_positions(const std::vector<std::pair<std::reference_wrapper<Dof>, double> > &modified_dofs) = 0;
    //virtual void forward_propagate_transformations(std::vector<int> subtree_root_indices) = 0;
    virtual int get_parent(int v) const = 0;
    virtual double get_length(int atom_index) const = 0;
    virtual void increment_length(int atom_index, double value) = 0;
    virtual void restore_positions() = 0;
};

}

#endif

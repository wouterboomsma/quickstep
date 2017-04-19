#ifndef QUICKSTEP_REFERENCE_KINEMATIC_FOREST_KERNEL_H
#define QUICKSTEP_REFERENCE_KINEMATIC_FOREST_KERNEL_H

#include "quickstep/KinematicForestKernel.h"

#include <vector>
#include <Eigen/Geometry>
#include "quickstep/utils.h"

namespace quickstep {

class GaussianMove;

class ReferenceKinematicForestKernel: public KinematicForestKernel {
public:

    void initialize(const KinematicForest &kinetic_forest);

    int parent(int v) const;

    /**
     * \brief Recurse through the tree, update transformations, apply them to atoms, and
     * reset transformation to identity.
     *
     * Assumes that forwardPropagateTransformations(parent(a)) has been called for any
     * atom a that is not root. If a is a root the previous transformation is assumed to
     * be identity.
     */
    void update_positions(std::vector<std::pair<Dof, double> >);

private:

    typedef Eigen::Transform<double, 3, Eigen::AffineCompact> QSTransform;

    /// Indices of root-atoms
    std::vector<int> roots;

    /// Adjacency list specifying edges in the tree
    std::vector< std::vector< std::pair<int,int> > > adjacency_list;

    /// Each atom has an associated transformation
    std::vector< QSTransform > transformations;

    /// Positions of atoms
    std::unique_ptr<CoordinatesWrapper> positions;
    Coordinates stored_positions;

    std::unordered_set<int> stored_indices;

    /**
     * Set v to be the parent of all adjacent vertices except p. This function is
     * called recursively on all children of v with an indication that v should be
     * their parent.
     */
    void root_tree(int v, int p);

};

}

#endif

#ifndef QUICKSTEP_REFERENCE_KINEMATIC_FOREST_KERNEL_H
#define QUICKSTEP_REFERENCE_KINEMATIC_FOREST_KERNEL_H

#include "quickstep/KinematicForestKernel.h"

#include <vector>
#include <Eigen/Geometry>
#include <unordered_set>

#include "quickstep/utils.h"

namespace quickstep {

class ReferenceKinematicForestKernel: public KinematicForestKernel {
public:

    void initialize(const KinematicForest &kinetic_forest,
                    std::vector<std::vector<std::pair<int, int> > > &adjacency_list,
                    std::vector<int> &roots);

    /**
     * \brief Recurse through the tree, update transformations, apply them to atoms, and
     * reset transformation to identity.
     *
     * Assumes that forwardPropagateTransformations(parent(a)) has been called for any
     * atom a that is not root. If a is a root the previous transformation is assumed to
     * be identity.
     */
    void update_positions(const std::vector<std::pair<std::reference_wrapper<Dof>, double> > &modified_dofs) override;

    int get_parent(int v) const;

    CoordinatesWrapper::ColXpr get_position(int atom_index) const;

    double get_length(int atom_index) const;

    void increment_length(int atom_index, double value);

    void restore_positions();

private:

    typedef Eigen::Transform<double, 3, Eigen::AffineCompact> QSTransform;

    unsigned long n_atoms;

    /// Indices of root-atoms
    std::vector<int> roots;

    /// Adjacency list specifying edges in the tree
    std::vector<std::vector<std::pair<int, int> > > adjacency_list;

    /// Each atom has an associated transformation
    std::vector<QSTransform> transformations;

    /// Positions of atoms
    std::unique_ptr<CoordinatesWrapper> positions;

    /// Backup of coordinates for restore functionality
    std::unordered_set<int> stored_indices;
    Coordinates stored_positions;

    /** Indices of all roots of all subtrees that had their positions changed. When only few atoms are moving this
    presents a significant speedup. */
    std::unordered_set<int> moved_subtrees;

    /// Keep track of pseudo root separately
    Coordinates pseudo_root_positions;
    std::unique_ptr<CoordinatesWrapper> pseudo_root_positions_wrapper;

    /**
     * Set v to be the parent of all adjacent vertices except p. This function is
     * called recursively on all children of v with an indication that v should be
     * their parent.
     */
    void root_tree(int v, int p);

    void forward_propagate_transformations(int atom);

    bool is_ancestor_of(int v1, int v2) const;

    void update_pseudo_roots();

};

}

#endif

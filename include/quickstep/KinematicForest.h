#ifndef KINEMATICFOREST_H
#define KINEMATICFOREST_H

#include <vector>
#include <utility>
#include <unordered_map>

#include "math/primitives.h"
#include "quickstep/Topology.h"
#include <Eigen/Geometry>

namespace quickstep{

/**
 * @brief A collection of kinematic trees.
 * A kinematic tree is a rooted tree with atoms as vertices and bonds as directed
 * edges. Each vertex is associated with 3 degrees of freedom, a length-DOF indicating
 * the length of its parent-edge, an angle-DOF indicating the angle between its parent-
 * edge and its parents parent-edge, and finally a torsion-DOF indicating the torsional
 * angle of its parents parent-edge.
 *
 * Changing a DOF for a particular atom, a, will affect the position of a and all
 * its children but nothing else. Calling the changeDOF* functions will set the
 * transformation matrices, but positions will only actually be updated after calling
 * updatePositions.
 */
class KinematicForest
{
public:
    /** Construct a kinematic forest spanning all atoms in the topology. */
    KinematicForest(quickstep::Topology& topology, quickstep::units::Coordinates* coordinates);

    KinematicForest();

    /** Get a reference to the vector of positions. Subsequent changes to DOFs will be
     * reflected in the returned vector. */
    units::Coordinates* getPositions();
//    std::vector< Math3D::Vector3 >& getPositions();

    int getRoots();
    int getAtoms();

    double getDOFLength(int atom);
    double getDOFAngle(int atom);
    double getDOFTorsion(int atom);

    void changeDOFLength(int atom, double value);
    void changeDOFAngle(int atom, double value);
    void changeDOFTorsion(int atom, double value);

//    void changeDOFglobal(int chain, Math3D::RigidTransform t);
    void changeDOFglobal(int chain, Eigen::Transform<double, 3, Eigen::Affine>& t);

    /**
     * Goes through the forest and updates positions so they reflect the requested
     * changes to DOFs. Stores the state of the tree so positions can be restored
     * using the restorePositions function.
     */
    void updatePositions();

    /**
     * Restores all positions to the coordinates before the last call to
     * updatePositions.
     */
    void restorePositions();


    // Various helper functions below here

    /** Print a textual representation of the forest for debugging purposes. */
    void print();

    Topology* getTopology();

    const Topology::Atom& getAtom(int atom);

    /** Indicate if atom is the last in the sequence of atom_names */
    bool atomMatchesNames(int atom, std::vector<std::string>& atom_names);

private:

    typedef Eigen::Transform<double, 3, Eigen::AffineCompact> QSTransform;

    quickstep::Topology* topology;

    std::unordered_map<int, const quickstep::Topology::Atom*> id_atom_map;

    /**
     * Set v to be the parent of all adjacent vertices except p. This function is
     * called recursively on all children of v with an indication that v should be
     * their parent.
     */
    void rootTree(int v, int p);

    /**
     * Return the parent of vertex v. If v is a root return -1,
     * if v<0 return (v-1)
     */
    int parent(int v);

    ///Number of atoms
    int n_atoms;

    /// Indices of root-atoms
    std::vector<int> roots;

    /// Adjacency list specifying edges in the tree
    std::vector< std::vector< std::pair<int,int> > > adjacencyList;

    /// Positions of atoms
//    std::vector< Math3D::Vector3 > positions;
    quickstep::units::Coordinates* positions;
    quickstep::units::Coordinates stored_positions;

    /// Get the position of atom index i. If i==-1 return p0
    /// if i==-2 return p1, and if i==-3 return p2
    units::Coordinate& pos(int i);
//    Math3D::Vector3& pos(int i);

//    Math3D::Vector3 p0;
//    Math3D::Vector3 p1;
//    Math3D::Vector3 p2;

    /// Each atom has an associated transformation
//    std::vector< Math3D::RigidTransform > transformations;
//    std::vector< std::vector< Math3D::RigidTransform > > transformations_queue;
    std::vector< QSTransform > transformations;
    std::vector< std::vector< QSTransform > > transformations_queue;

    //std::vector< Math3D::RigidTransform > transformations_l;
    //std::vector< Math3D::RigidTransform > transformations_a;
    //std::vector< Math3D::RigidTransform > transformations_t;

    /**
     * \brief Recurse through the tree, update transformations, apply them to atoms, and
     * reset transformation to identity.
     *
     * Assumes that forwardPropagateTransformations(parent(a)) has been called for any
     * atom a that is not root. If a is a root the previous transformation is assumed to
     * be identity.
     */
    void forwardPropagateTransformations(int a=-1);

    bool pseudoRootsSet = false;
    void updatePseudoRoots();

    friend class CofMMove;
    friend class FreeBondRotateMove;
};

}

#endif // KINEMATICFOREST_H

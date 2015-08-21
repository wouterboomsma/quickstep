#ifndef KINEMATICFOREST_H
#define KINEMATICFOREST_H

#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

#include "math/primitives.h"
#include "quickstep/Topology.h"
#include "quickstep/FatalError.h"
#include "quickstep/utils.h"
#include <Eigen/QuantityGeometry>
#include <Eigen/Geometry>

namespace quickstep{

class KinematicForest;

/**
 * Indicates the index of a DOF in the KinematicForest. Each DOF is defined by an atom-index
 * indicating the first atom whose position is affected by the DOF and a DOF type indicating
 * whether the bond-length, bond-angle or bond-torsion preceeding the atom should be indexed.
 */
struct DOFIndex{
    DOFIndex(unsigned int ai, unsigned int dt): atom_index(ai), dof_type(dt) {}
    DOFIndex(): DOFIndex(0,0) {}
    DOFIndex(const DOFIndex &other): DOFIndex(other.atom_index, other.dof_type) {}

    std::vector<int> get_atoms(const KinematicForest &forest) const;

	unsigned int atom_index;
	unsigned int dof_type; ///< 0 is bond-length, 1 is bond angle, and 2 is bond torsion
};


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
    class LengthDoF;
    class AngleDoF;
    class TorsionDoF;

    class DoF {
    public:
        DoF(KinematicForest &forest,
            int atom_index)
                : forest(forest),
                  atom_index(atom_index) {}

        virtual DOFIndex get_dofindex() = 0;

        virtual double get_value() = 0;

        virtual void add_value(double value) = 0;

        virtual void set_value(double value) {
            add_value( - get_value() + value);
        }

        static std::unique_ptr<DoF> construct(KinematicForest &forest,
                                              std::vector<int> atom_indices,
                                              std::vector<std::string> atom_names) {
            switch (atom_indices.size()) {
                case 2:
                    return std::make_unique<LengthDoF>(forest, atom_indices, atom_names);
                    break;
                case 3:
                    return std::make_unique<AngleDoF>(forest, atom_indices, atom_names);
                    break;
                case 4:
                    return std::make_unique<TorsionDoF>(forest, atom_indices, atom_names);
                    break;
                default:
                    BOOST_THROW_EXCEPTION(FatalError() <<
                                          "Unexpected number of atoms specified for DoF (" << atom_indices.size() << ")");
                    break;
            }
        }

        const int get_atom_index(){ return atom_index; }
    protected:
        KinematicForest &forest;
        int atom_index;
    };

    class LengthDoF: public DoF {
    public:
        LengthDoF(KinematicForest &forest,
                  std::vector<int> atom_indices,
                  std::vector<std::string> atom_names)
                : DoF(forest, atom_indices.back()) {
            if (!forest.atom_matches_names(atom_indices.back(), atom_names)) {
//                : DoF(forest, forest.find_dof_atom_index(atom_indices, atom_names)) {
//            if (atom_index == -1) {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Length DoF (" << atom_names << ") is not found in KinematicForest.");
            }
        }

        double get_value() override {
            return forest.get_length(this->atom_index).value();
        };

        DOFIndex get_dofindex(){ return DOFIndex(atom_index, 0); }

        void add_value(double delta_value) override {
            forest.change_length(this->atom_index, units::Length::from_value(delta_value));
        };
    };

    class AngleDoF: public DoF {
    public:
        AngleDoF(KinematicForest &forest,
                 std::vector<int> atom_indices,
                 std::vector<std::string> atom_names)
                : DoF(forest, atom_indices.back()) {
            if (!forest.atom_matches_names(atom_indices.back(), atom_names)) {
//                : DoF(forest, forest.find_dof_atom_index(atom_indices, atom_names)) {
//            if (atom_index == -1) {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Angle DoF (" << atom_names << ") is not found in KinematicForest.");
            }
        }

        double get_value() override {
            return forest.get_angle(this->atom_index).value();
        };

        DOFIndex get_dofindex(){ return DOFIndex(atom_index, 1); }

        void add_value(double delta_value) override {
            forest.change_angle(this->atom_index, units::Angle::from_value(delta_value));
        };
    };

    class TorsionDoF: public DoF {
    public:

        TorsionDoF(KinematicForest &forest,
                   std::vector<int> atom_indices,
                   std::vector<std::string> atom_names)
                : DoF(forest, atom_indices.back()) {

            if (!forest.atom_matches_names(atom_indices.back(), atom_names)) {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Torsion DoF (" << atom_names << ") is not found in KinematicForest.");
            }

            int parent_index = forest.parent(atom_index);

            //Collect all children of parent
            for(size_t i=0; i<forest.adjacency_list[parent_index].size();++i){
            	if( 	forest.adjacency_list[parent_index][i].first == parent_index){
            		sibling_atom_indices.push_back(forest.adjacency_list[parent_index][i].second);
            	}
            }
        }

        double get_value() override {
            return forest.get_torsion(this->atom_index).value();
        };

        DOFIndex get_dofindex(){ return DOFIndex(atom_index, 2); }

        void add_value(double delta_value) override {
            for(int i: sibling_atom_indices)
            	forest.change_torsion(i, units::Angle::from_value(delta_value));
        };

    private:
        std::vector<int> sibling_atom_indices;
    };

    class IndependentTorsionDoF: public DoF {
    public:

        IndependentTorsionDoF(KinematicForest &forest,
                   std::vector<int> atom_indices,
                   std::vector<std::string> atom_names)
                : DoF(forest, atom_indices.back()) {
            if (!forest.atom_matches_names(atom_indices.back(), atom_names)) {
//                : DoF(forest, forest.find_dof_atom_index(atom_indices, atom_names)) {
//            if (atom_index == -1) {
                BOOST_THROW_EXCEPTION(FatalError() <<
                                      "Independent torsion DoF (" << atom_names << ") is not found in KinematicForest.");
            }
        }

        double get_value() override {
            return forest.get_torsion(this->atom_index).value();
        };

        DOFIndex get_dofindex(){ return DOFIndex(atom_index, 2); }

        void add_value(double delta_value) override {
            forest.change_torsion(this->atom_index, units::Angle::from_value(delta_value));
        };

    };

    /** Construct a kinematic forest spanning all atoms in the topology. */
    KinematicForest(quickstep::Topology& topology, const units::CoordinatesWrapper &coordinates);

    KinematicForest();

    /** Get a reference to the vector of positions. Subsequent changes to DOFs will be
     * reflected in the returned vector. */
    units::CoordinatesWrapper &get_positions();
//    std::vector< Math3D::Vector3 >& getPositions();

    int get_num_roots();
    int get_root_atom(int chain_idx);
    int get_num_atoms();

    units::Length get_length(int atom);
    units::Angle get_angle(int atom);
    units::Angle get_torsion(int atom) const;

    void change_length(int atom, units::Length value);
    void change_angle(int atom, units::Angle value);
    void change_torsion(int atom, units::Angle value);

//    void changeDOFglobal(int chain, Math3D::RigidTransform t);
    void change_global(int chain, Eigen::Transform<units::Length, 3, Eigen::Affine>& t);

    /**
     * Goes through the forest and updates positions so they reflect the requested
     * changes to DOFs. Stores the state of the tree so positions can be restored
     * using the restorePositions function.
     */
    void update_positions();

    /**
     * Restores all positions to the coordinates before the last call to
     * updatePositions.
     */
    void restore_positions();


    // Various helper functions below here

    /** Print a textual representation of the forest for debugging purposes. */
    void print();

    Topology* get_topology();

    const Topology::Atom& get_atom(int atom);

    /** Indicate if atom is the last in the sequence of atom_names */
    bool atom_matches_names(int atom, const std::vector<std::string>& atom_names);

private:
    friend class DOFIndex;

    typedef Eigen::Transform<units::Length, 3, Eigen::AffineCompact> QSTransform;

    quickstep::Topology* topology;

    std::unordered_map<int, const quickstep::Topology::Atom*> id_atom_map;

    /**
     * Set v to be the parent of all adjacent vertices except p. This function is
     * called recursively on all children of v with an indication that v should be
     * their parent.
     */
    void root_tree(int v, int p);

    /**
     * Return the parent of vertex v. If v is a root return -1,
     * if v<0 return (v-1)
     */
    int parent(int v) const;

    /** Return true iff v1 is an ancestor of v2 */
    bool ancestor_of(int v1, int v2);

    /// Number of atoms
    int n_atoms;

    /// Indices of root-atoms
    std::vector<int> roots;

    /// Adjacency list specifying edges in the tree
    std::vector< std::vector< std::pair<int,int> > > adjacency_list;

    /// Positions of atoms
    std::unique_ptr<units::CoordinatesWrapper> positions;
    units::Coordinates stored_positions;

    units::Coordinates pseudo_root_positions;
//    units::Coordinates stored_pseudo_root_positions;

    /**
     * Get the position of atom index i.
     * If n_atoms <= i < n_atoms+roots.size()*2 the corresponding member of pseudo_roots
     * is returned.
     */
    units::CoordinatesWrapper::ColXpr pos(int i);
    units::Coordinate pos(int i) const;

    void backup_pos(int i);

//    void apply_transformation_at_pos(int i);


    /// Each atom has an associated transformation
    std::vector< QSTransform > transformations;

    /**
     * \brief Recurse through the tree, update transformations, apply them to atoms, and
     * reset transformation to identity.
     *
     * Assumes that forwardPropagateTransformations(parent(a)) has been called for any
     * atom a that is not root. If a is a root the previous transformation is assumed to
     * be identity.
     */
    void forward_propagate_transformations(int a=-1);

    /** Indices of all roots of all subtrees that had their positions changed. When only few atoms are moving this
    presents a significant speedup. */
    std::unordered_set<int> moved_subtrees;

    std::unordered_set<int> stored_indices;

//    bool pseudoRootsSet = false;
    void update_pseudo_roots();


    friend class CofMMove;
    friend class FreeBondRotateMove;
    friend class GaussianMove;
};

}

#endif // KINEMATICFOREST_H

#include "ReferenceKinematicForestKernel.h"
#include "quickstep/KinematicForest.h"
#include "quickstep/DisjointSet.h"
#include "quickstep/platforms/ReferencePlatform.h"

namespace quickstep {

void ReferenceKinematicForestKernel::initialize(const KinematicForest &kinematic_forest,
                                                std::vector<std::vector<std::pair<int, int> > > &adjacency_list,
                                                std::vector<int> &roots) {
    std::cout << "Initializing ReferenceKinematicForestKernel\n";

    const Topology *topology = kinematic_forest.get_topology();

    n_atoms = topology->get_atoms().size();

    this->adjacency_list = adjacency_list;
    roots = roots;

    // Allocate space for tree, positions and transformations
    //adjacency_list.resize(n_atoms);
    transformations.resize(n_atoms);

    // Allocate space for pseudo roots
    pseudo_root_positions.resize(3,3);
    pseudo_root_positions_wrapper = std::make_unique<CoordinatesWrapper>(pseudo_root_positions.data(), 3, 3);

    //// Kruskals algorithm for finding minimum spanning forest
    //DisjointSet ds(n_atoms);
    //for (auto bond: topology->get_bonds()) {
    //    const quickstep::Topology::Atom &a1 = topology->atoms[bond.first];
    //    const quickstep::Topology::Atom &a2 = topology->atoms[bond.second];
    //    if (!ds.connected(a1.index, a2.index)) {
    //        adjacency_list[a1.index].push_back(std::make_pair(a1.index, a2.index));
    //        adjacency_list[a2.index].push_back(std::make_pair(a1.index, a2.index));
    //        ds.merge(a1.index, a2.index);
    //    }
    //}
    //
    //// Root all trees
    //roots.push_back(0);
    //root_tree(0, -1);
    //for (int v = 1; v < n_atoms; v++) {
    //    bool v_should_be_root = true;
    //    for (int r = 0; r < roots.size(); r++) {
    //        if (ds.connected(roots[r], v)) {
    //            v_should_be_root = false;
    //            break;
    //        }
    //    }
    //
    //    if (v_should_be_root) {
    //        roots.push_back(v);
    //        root_tree(v, -1);
    //    }
    //}
    //update_pseudo_roots();

    //Reset transformations
    for (int i = 0; i < n_atoms; i++) {
        transformations[i].setIdentity();
    }
}

void ReferenceKinematicForestKernel::root_tree(int v, int p) {

    for (int c = 0; c < adjacency_list[v].size(); c++) {
        if (adjacency_list[v][c].second == v && adjacency_list[v][c].first != p) {
            //Switch direction of edge
            int v2 = adjacency_list[v][c].first;
            adjacency_list[v][c].first = v;
            adjacency_list[v][c].second = v2;

            for (int c2 = 0; c2 < adjacency_list[v2].size(); c2++) {
                if (adjacency_list[v2][c2].second == v) {
                    adjacency_list[v2][c2].first = v;
                    adjacency_list[v2][c2].second = v2;
                    break;
                }
            }
        }
        if (adjacency_list[v][c].second != v)
            root_tree(adjacency_list[v][c].second, v);
    }
}


int ReferenceKinematicForestKernel::get_parent(int v) const {
    if (v < 0) return v - 1;

    for (int c = 0; c < adjacency_list[v].size(); c++) {
        if (adjacency_list[v][c].second == v)
            return adjacency_list[v][c].first;

    }
    return -1;
}

bool ReferenceKinematicForestKernel::is_ancestor_of(int v1, int v2) const {
    int v = get_parent(v2);
    while (v > 0) {
        if (v == v1) return true;
        v = get_parent(v);
    }
    return false;
}

void ReferenceKinematicForestKernel::update_positions(
        const std::vector<std::pair<std::reference_wrapper<Dof>, double> > &modified_dofs) {

    /// TODO: Do the actual updating of transforms

    //Ensure that moved_subtrees dont contain two vertices where one is an ancestor of the other
    std::unordered_set<int> to_remove;
    for (const int &r1: moved_subtrees) {
        for (const int &r2: moved_subtrees) {
            if (r1 == r2) break;
            if (is_ancestor_of(r1, r2)) to_remove.insert(r2);
            else if (is_ancestor_of(r2, r1)) to_remove.insert(r1);
        }
    }
    for (const int &r: to_remove) {
        moved_subtrees.erase(r);
        //cout << "Removed " << r << " from subtrees to be moved"<<endl;
    }

    stored_indices.clear();

    for (const int &subtree_root: moved_subtrees) {
        //cout<<"Moving subtree "<<subtree_root<<endl;
        forward_propagate_transformations(subtree_root);
    }

    moved_subtrees.clear();

}

void ReferenceKinematicForestKernel::forward_propagate_transformations(int atom) {

    std::cout << "Calling forward_propagate_transformations\n";
    if (atom < 0) {
        for (size_t i = 0; i < roots.size(); i++) {
            forward_propagate_transformations(roots[i]);
        }
    } else {
        // Retrieve transformation from parent
        int p = get_parent(atom);
        if (p >= 0)
            transformations[atom] = transformations[p] * transformations[atom];

        // Save position
        stored_positions.col(atom) = positions->col(atom);
        stored_indices.insert(atom);

        // Apply transformation
        positions->col(atom) = transformations[atom] * positions->col(atom).matrix();

        // Call recursively
        for (int c = 0; c < adjacency_list[atom].size(); c++) {
            if (adjacency_list[atom][c].second != atom)
                forward_propagate_transformations(adjacency_list[atom][c].second);
        }

        // Reset transformation at current index
        transformations[atom].setIdentity();
    }
}

//void ReferenceKinematicForestKernel::update_pseudo_roots() {
//    pseudo_root_positions.resize(3,3);
//
//	for(int r=0;r<roots.size();r++){
//		int idxr = roots[r];
//		adjacency_list[idxr].push_back( std::make_pair( -1, idxr ));
//	}
//}

double ReferenceKinematicForestKernel::get_length(int atom_index) const {
    assert(atom_index>=0 && atom_index<n_atoms);

    int a1 = get_parent(atom_index);
    Vector3d v = get_position(atom_index)-get_position(a1);

    return v.norm();
}

void ReferenceKinematicForestKernel::increment_length(int atom_index, double value) {
    assert(atom_index>=0 && atom_index<n_atoms);

    int a1 = get_parent(atom_index);

    Vector3d d = (get_position(atom_index)-get_position(a1)).matrix().normalized() * value;
    transformations[atom_index] = transformations[atom_index]*Eigen::Translation<double,3>(d);

    moved_subtrees.insert(atom_index);
}

CoordinatesWrapper::ColXpr ReferenceKinematicForestKernel::get_position(int atom_index) const {
    if(atom_index<0 && atom_index>-4){
        return pseudo_root_positions_wrapper->col(atom_index+3);
    }
    return positions->col(atom_index);
}

void ReferenceKinematicForestKernel::restore_positions() {
    for (int atom_index: stored_indices) {
    	positions->col(atom_index) = stored_positions.col(atom_index);
    }
}

}
#include "ReferenceKinematicForestKernel.h"
#include "quickstep/KinematicForest.h"
#include "quickstep/DisjointSet.h"
#include "quickstep/platforms/ReferencePlatform.h"

namespace quickstep {

void ReferenceKinematicForestKernel::initialize(const KinematicForest &kinematic_forest) {
    std::cout << "Initializing ReferenceKinematicForestKernel\n";

    const Topology *topology = kinematic_forest.get_topology();

    int n_atoms = topology->get_atoms().size();

    //Allocate space for tree, positions and transformations
    adjacency_list.resize(n_atoms);
    transformations.resize(n_atoms);

    //Kruskals algorithm for finding minimum spanning forest
    DisjointSet ds(n_atoms);
    for( auto bond: topology->get_bonds() ){
        const quickstep::Topology::Atom& a1 = topology->atoms[bond.first];
        const quickstep::Topology::Atom& a2 = topology->atoms[bond.second];
        int a1Idx = a1.index;
        int a2Idx = a2.index;
        if(!ds.connected(a1Idx, a2Idx)){
            adjacency_list[a1Idx].push_back( std::make_pair(a1Idx, a2Idx) );
            adjacency_list[a2Idx].push_back( std::make_pair(a1Idx, a2Idx) );
            ds.merge(a1Idx, a2Idx);
        }
    }

    //Root all trees
    roots.push_back(0);
    root_tree(0, -1);
    for(int v=1;v<n_atoms;v++){
        bool vShouldBeRoot = true;
        for(int r=0;r<roots.size();r++){
            if(ds.connected(roots[r], v)){
                vShouldBeRoot = false;
                break;
            }
        }

        if(vShouldBeRoot){
            roots.push_back(v);
            root_tree(v,-1);
        }
    }
    update_pseudo_roots();

    //Reset transformations
    for(int i=0;i<n_atoms;i++){
        transformations[i].setIdentity();
    }
}

void ReferenceKinematicForestKernel::root_tree(int v, int p)
{

    for(int c=0;c<adjacency_list[v].size();c++){
        if(adjacency_list[v][c].second==v && adjacency_list[v][c].first!=p){
            //Switch direction of edge
            int v2 = adjacency_list[v][c].first;
            adjacency_list[v][c].first = v;
            adjacency_list[v][c].second = v2;

            for(int c2=0;c2<adjacency_list[v2].size();c2++){
                if(adjacency_list[v2][c2].second==v){
                    adjacency_list[v2][c2].first = v;
                    adjacency_list[v2][c2].second = v2;
                    break;
                }
            }
        }
        if(adjacency_list[v][c].second != v)
            root_tree(adjacency_list[v][c].second, v);
    }
}



int ReferenceKinematicForestKernel::parent(int v) const
{
    if(v<0) return v-1;

    for(int c=0;c<adjacency_list[v].size();c++){
        if(adjacency_list[v][c].second==v)
            return adjacency_list[v][c].first;

    }
    return -1;
}


void ReferenceKinematicForestKernel::update_positions(std::vector<std::pair<Dof, double> >) {
    std::cout << "Calling forward_propagate_transformations\n";
    if(atom<0) {
        for(size_t i=0;i<roots.size();i++){
            forward_propagate_transformations(roots[i]);
        }
    } else {
        // Retrieve transformation from parent
        int p = parent(atom);
        if(p>=0)
            transformations[atom] = transformations[p]*transformations[atom];

        // Save position
        stored_positions.col(atom) = positions->col(atom);
        stored_indices.insert(atom);

        // Apply transformation
        positions->col(atom) = transformations[atom] * positions->col(atom).matrix();

        // Call recursively
        for(int c=0;c<adjacency_list[atom].size();c++){
            if(adjacency_list[atom][c].second!=atom)
                forward_propagate_transformations(adjacency_list[atom][c].second);
        }

        // Reset transformation at current index
        transformations[atom].setIdentity();
    }
}


}

#include "quickstep/KinematicForest.h"

#include <iostream>
#include <math.h>
#include <assert.h>     /* assert */
#include <functional>   // reference_wrapper
#include <cassert>

#include "quickstep/utils.h"
#include "quickstep/DisjointSet.h"


using namespace std;
using namespace quickstep;

KinematicForest::KinematicForest():
		n_atoms(0),
		topology(NULL)
{

//	Eigen::Transform translation_A(Eigen::Translation<float,3>(Eigen::Vector3f(1,1,1)));
	Eigen::Translation<float,3> translation_A(Eigen::Vector3f(1,1, 1));
	Eigen::Translation<float,3> translation_B(Eigen::Vector3f(1,1,-1));
	Eigen::AngleAxis<float> aa(0.1, Eigen::Vector3f(1,0,0));
	Eigen::Transform<float,3,Eigen::Affine> trans(translation_A);

}

KinematicForest::KinematicForest(quickstep::Topology &topology, const units::CoordinatesWrapper &coordinates):
		topology(&topology),
		positions(make_unique<units::CoordinatesWrapper>(coordinates)),
		stored_positions(coordinates.rows(), coordinates.cols()) // Stored positions is a matrix and must be initialized with two sizes
{
	//Associate each atom with a unique index between 0 and the total number of atoms
	n_atoms = 0;
	unordered_map<int, int> atomIdxMap;
	for( const quickstep::Topology::Chain& chain: topology.get_chains() ){
		for( const quickstep::Topology::Residue& res: chain.residues ){
			//for( const quickstep::Topology::Atom& atom: res.atoms ){
			for( unsigned int atom_idx: res.atom_indices){
//				atomIdxMap[atom.index] = n_atoms;
//				id_atom_map[n_atoms] = &atom;
				atomIdxMap[atom_idx] = n_atoms;
				id_atom_map[n_atoms] = &topology.atoms[atom_idx];
				n_atoms++;
			}
		}
	}

	//Allocate space for tree, positions and transformations
	adjacency_list.resize(n_atoms);
	transformations.resize(n_atoms);
//	transformations_queue.resize(n_atoms);

    //Kruskals algorithm for finding minimum spanning forest
    DisjointSet ds(n_atoms);
    for( auto bond: topology.get_bonds() ){
    	const quickstep::Topology::Atom& a1 = bond.first;
    	const quickstep::Topology::Atom& a2 = bond.second;
    	int a1Idx = atomIdxMap[a1.index];
    	int a2Idx = atomIdxMap[a2.index];
    	if(!ds.connected(a1Idx, a2Idx)){
    		adjacency_list[a1Idx].push_back( pair<int,int>(a1Idx, a2Idx) );
    		adjacency_list[a2Idx].push_back( pair<int,int>(a1Idx, a2Idx) );
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

units::CoordinatesWrapper &KinematicForest::get_positions()
{
    return *positions.get();
}

int KinematicForest::get_num_roots()
{
	return roots.size();
}

int KinematicForest::get_root_atom(int chain_idx)
{
	return roots[chain_idx];
}

int KinematicForest::get_num_atoms()
{
	return n_atoms;
}

units::Length KinematicForest::get_length(int atom)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();

    int a1 = parent(atom);
    units::Vector3L v = pos(atom)-pos(a1);

    return v.norm();
}

units::Angle KinematicForest::get_angle(int atom)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of ColXpr instead of standard references
    units::CoordinatesWrapper::ColXpr a0_pos = pos(atom);
    units::CoordinatesWrapper::ColXpr a1_pos = pos(a1);
    units::CoordinatesWrapper::ColXpr a2_pos = pos(a2);
    units::Vector3L v1 = a2_pos-a1_pos;
    units::Vector3L v2 = a0_pos-a1_pos;
    units::Length v1_len = v1.norm();
    units::Length v2_len = v2.norm();
    return acos(v1.dot(v2).value()/(v1_len*v2_len).value()) * units::radians;
}

units::Angle KinematicForest::get_torsion(int atom)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();

    int a1 = parent(atom);
    int a2 = parent(a1);
    int a3 = parent(a2);

    units::CoordinatesWrapper::ColXpr a0_pos = pos(atom);
    units::CoordinatesWrapper::ColXpr a1_pos = pos(a1);
    units::CoordinatesWrapper::ColXpr a2_pos = pos(a2);
    units::CoordinatesWrapper::ColXpr a3_pos = pos(a3);

    units::Vector3L v01 = a1_pos - a0_pos;
    units::Vector3L v12 = a2_pos - a1_pos;
    units::Vector3L v23 = a3_pos - a2_pos;
    units::Vector3L::UnitLess cross1 {v01.cross(v12).normalized()};
    units::Vector3L::UnitLess cross2 {v12.cross(v23).normalized()};
    double product = cross1.dot(cross2);
    if (product > 1.)
        product = 1.;
    if (product < -1.)
        product = -1.;
    double torsion = acos(product);

    if (cross1.dot(v23.value()) < 0.)
        torsion *= -1;

    return torsion * units::radians;
};


void KinematicForest::change_length(int atom, units::Length value)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();
//    if(atom==0) return;

    int a1 = parent(atom);

    units::Vector3L d = (pos(atom)-pos(a1)).matrix().normalized() * value;
    transformations[atom] = transformations[atom]*Eigen::Translation<units::Length,3>(d);
}

void KinematicForest::change_angle(int atom, units::Angle value)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();
//    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of ColXpr instead of standard references
    units::CoordinatesWrapper::ColXpr pos_a = pos(atom);
    units::CoordinatesWrapper::ColXpr pos_a1 = pos(a1);
    units::CoordinatesWrapper::ColXpr pos_a2 = pos(a2);
    units::Vector3L v1 = pos_a2- pos_a1;
    units::Vector3L v2 = pos_a - pos_a1;
    units::Vector3L axis = v1.cross(v2).normalized() * units::Vector3L::Unit();

    transformations[atom] = transformations[atom] *
    		Eigen::Translation<units::Length, 3>(pos_a1)*
			Eigen::AngleAxis<units::Length>(value, axis)*
			Eigen::Translation<units::Length, 3>(-pos_a1);
}

void KinematicForest::change_torsion(int atom, units::Angle value)
{
    assert(atom>=0 && atom<n_atoms);
//    if(!pseudoRootsSet)	update_pseudo_roots();
//    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of ColXpr instead of standard references
    units::CoordinatesWrapper::ColXpr pos_a1 = pos(a1);
    units::CoordinatesWrapper::ColXpr pos_a2 = pos(a2);

    units::Vector3L axis = (pos_a2 - pos_a1).matrix().normalized() * units::Vector3L::Unit();

    transformations[atom] = transformations[atom]*
        		Eigen::Translation<units::Length, 3>( pos_a1) *
    			Eigen::AngleAxis<units::Length>(-value, axis) *
    			Eigen::Translation<units::Length, 3>(-pos_a1);

}

void KinematicForest::change_global(int chain, Eigen::Transform<units::Length, 3, Eigen::Affine>& t)
{
//	if(!pseudoRootsSet)	update_pseudo_roots();
//	int idx1 = parent(parent(roots[chain]));
    int idx1 = roots[chain];
	transformations[idx1] = transformations[idx1] * t;//Eigen::Transform<units::Length, 3, Eigen::Affine>(t);
}

void KinematicForest::update_positions()
{
//	if(!pseudoRootsSet)	update_pseudo_roots();
    forward_propagate_transformations(-1);
}


void KinematicForest::forward_propagate_transformations(int atom)
{
//	std::cout<<"forwardPropagateTransformations "<<atom<<std::endl;
    if(atom<0){
        for(size_t i=0;i<roots.size();i++){
//            forward_propagate_transformations(parent(parent(roots[i])));

            forward_propagate_transformations(roots[i]);
        }
    }else{
        int p = parent(atom);

        if(p>=0)
        	transformations[atom] = transformations[p]*transformations[atom];

        backup_pos(atom);

//        apply_transformation_at_pos(atom);
        positions->col(atom) = transformations[atom] * positions->col(atom).matrix();


        for(int c=0;c<adjacency_list[atom].size();c++){
            if(adjacency_list[atom][c].second!=atom)
                forward_propagate_transformations(adjacency_list[atom][c].second);
        }
        transformations[atom].setIdentity();

//        transformations_queue[atom].clear();
    }
}

void KinematicForest::restore_positions()
{
	for(int i=0;i<n_atoms;i++){
		positions->col(i) = stored_positions.col(i);
	}
//	for(int i=0;i<stored_pseudo_root_positions.cols();i++){
//		pseudo_root_positions.col(i) = stored_pseudo_root_positions.col(i);
//	}
}

units::CoordinatesWrapper::ColXpr KinematicForest::pos(int i)
{
//    assert(i>-4 && i<n_atoms);

//    if(i>=n_atoms){
//    	units::CoordinatesWrapper wrapper =
//    			units::CoordinatesWrapper::UnitLess(pseudo_root_positions.data(), 3, pseudo_root_positions.cols()) * units::nm ;
//    	return wrapper.col(i-n_atoms);
//    }
    if(i<0 && i>-4){
        units::CoordinatesWrapper wrapper =
                units::CoordinatesWrapper::UnitLess( pseudo_root_positions.data(), 3, pseudo_root_positions.cols() ) * units::nm;
        return wrapper.col(i+3);
    }

    return positions->col(i);
}

void KinematicForest::backup_pos(int i)
{
    assert(i>=0 && i<n_atoms);

    stored_positions.col(i) = positions->col(i);

//    if(i>=n_atoms){
//    	stored_pseudo_root_positions.col(i-n_atoms) = pseudo_root_positions.col(i-n_atoms);
//    }else{
//    	stored_positions.col(i) = positions->col(i);
//    }
}

//void KinematicForest::apply_transformation_at_pos(int i)
//{
//    assert( i>=0 && i<n_atoms );
//    positions->col(i) = transformations[i] * positions->col(i).matrix();
//
////    if(i>=n_atoms){
////    	pseudo_root_positions.col(i-n_atoms) = transformations[i]*pseudo_root_positions.col(i-n_atoms).matrix();
////    }else{
////    	positions->col(i) = transformations[i]*positions->col(i).matrix();
////    }
//}

void KinematicForest::root_tree(int v, int p)
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

int KinematicForest::parent(int v)
{
    if(v<0) return v-1;

    for(int c=0;c<adjacency_list[v].size();c++){
        if(adjacency_list[v][c].second==v)
            return adjacency_list[v][c].first;

    }
    return -1;
}

void KinematicForest::print()
{
    std::cout<<"KinematicForest:"<<std::endl;
    for(int v=0;v<adjacency_list.size();v++){
        std::cout<<"  adjacencies["<<v<<"]: ";
        for(int a=0;a<adjacency_list[v].size();a++){
            if(adjacency_list[v][a].second!=v)
                std::cout<<" "<<adjacency_list[v][a].second;
        }

        std::cout<<std::endl;
    }

}

Topology* KinematicForest::get_topology()
{
	return topology;
}

const Topology::Atom& KinematicForest::get_atom(int atom)
{
	assert(atom>=0 && atom<n_atoms);

	return *id_atom_map[atom];
}


bool KinematicForest::atom_matches_names(int atom, const std::vector<std::string>& dofNames)
{

	int a = atom;

	bool matches = true;

	for (int p=0;p<dofNames.size();p++) {
		if(a<0 || a>=n_atoms || get_atom(a).name!=dofNames[p]) {
            matches = false;
            break;
        }
		a = parent(a);
	}

    if (matches)
        return matches;

    a = atom;
    matches = true;
    for (int p=dofNames.size()-1; p>=0; --p) {
        if(a >= n_atoms || get_atom(a).name != dofNames[p]) {
            matches = false;
            break;
        }
        a = parent(a);

    }

	return matches;
}


void KinematicForest::update_pseudo_roots()
{
//    // NOTE: resize of matrix requires two size arguments
//	pseudo_root_positions.resize(3, roots.size()*2);
//	stored_pseudo_root_positions.resize(3, roots.size()*2);
    pseudo_root_positions.resize(3,3);

	for(int r=0;r<roots.size();r++){
		int idxr = roots[r];
//		int idx0 = n_atoms;
//		int idx1 = idx0+1;
//
//		units::Coordinate p0 = positions->col( idxr ) + units::Coordinate(0.1* units::nm, 0.0* units::nm, 0.0* units::nm) ;
//		units::Coordinate p1 = positions->col( idxr ) + units::Coordinate(0.1* units::nm, 0.1* units::nm, 0.0* units::nm);
//		pseudo_root_positions.col(r*2  ) = p0;
//		pseudo_root_positions.col(r*2+1) = p1;
//
//		adjacency_list.push_back( std::vector< pair<int,int> >() );
//		adjacency_list[idx0].push_back( std::make_pair( idx0, idxr ) );
//		adjacency_list[idxr].push_back( std::make_pair( idx0, idxr ) );

		adjacency_list[idxr].push_back( std::make_pair( -1, idxr ));

//		adjacency_list.push_back( std::vector< pair<int,int> >() );
//		adjacency_list[idx1].push_back( std::make_pair( idx1, idx0 ) );
//		adjacency_list[idx0].push_back( std::make_pair( idx1, idx0 ) );
//
//		transformations.push_back(QSTransform::Identity());
//		transformations.push_back(QSTransform::Identity());
	}
//
//	pseudoRootsSet = true;


}




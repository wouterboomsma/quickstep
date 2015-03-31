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

//Old version using BondGraph
//KinematicForest::KinematicForest(BondGraph &graph):
//    adjacencyList(graph.numberOfAtoms()),
//    positions(graph.numberOfAtoms(), Math3D::Vector3(0,0,0)),
////    p0(0,0,0), p1(1,0,0), p2(0,1,0),
//    atoms(graph.numberOfAtoms()),
//    transformations(graph.numberOfAtoms()),
//    transformations_queue(graph.numberOfAtoms())
//{
//
//    //Kruskals algorithm for finding minimum spanning forest
//    DisjointSet ds(graph.numberOfAtoms());
//    for(int v1=0;v1<graph.numberOfAtoms();v1++){
//        for(int i=0;i<graph.adjacencyList[v1].size();i++){
//            int v2 = graph.adjacencyList[v1][i];
//            if(!ds.connected(v1,v2)){
//                adjacencyList[v1].push_back( std::make_pair(v1,v2) );
//                adjacencyList[v2].push_back( std::make_pair(v1,v2) );
//                ds.merge(v1,v2);
//            }
//        }
//    }
//
//    print();
//
//    //Root all trees
//    roots.push_back(0);
//    rootTree(0, -1);
//    for(int v=1;v<graph.numberOfAtoms();v++){
//        bool vShouldBeRoot = true;
//        for(int r=0;r<roots.size();r++){
//            if(ds.connected(roots[r], v)){
//                vShouldBeRoot = false;
//                break;
//            }
//        }
//
//        if(vShouldBeRoot){
//            roots.push_back(v);
//
//            rootTree(v,-1);
//        }
//    }
//
//    //Reset transformations
//    for(int i=0;i<graph.numberOfAtoms();i++){
//        transformations[i].setIdentity();
//    }
//
//}

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

KinematicForest::KinematicForest(quickstep::Topology &topology, quickstep::units::Coordinates* coordinates):
		topology(&topology),
		positions(coordinates),
        // NOTE: stored posisions is a matrix and must be initialized with two sizes
		stored_positions(coordinates->rows(), coordinates->cols())
//    adjacencyList(topology.graph.numberOfAtoms()),
//    positions(graph.numberOfAtoms(), Math3D::Vector3(0,0,0)),
////    p0(0,0,0), p1(1,0,0), p2(0,1,0),
//    atoms(graph.numberOfAtoms()),
//    transformations(graph.numberOfAtoms()),
//    transformations_queue(graph.numberOfAtoms())
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
	adjacencyList.resize(n_atoms);
//	positions.resize(n_atoms, Math3D::Vector3(0,0,0));
	transformations.resize(n_atoms);
	transformations_queue.resize(n_atoms);

    //Kruskals algorithm for finding minimum spanning forest
    DisjointSet ds(n_atoms);
    for( auto bond: topology.get_bonds() ){
    	const quickstep::Topology::Atom& a1 = bond.first;
    	const quickstep::Topology::Atom& a2 = bond.second;
    	int a1Idx = atomIdxMap[a1.index];
    	int a2Idx = atomIdxMap[a2.index];
    	if(!ds.connected(a1Idx, a2Idx)){
    		adjacencyList[a1Idx].push_back( pair<int,int>(a1Idx, a2Idx) );
    		adjacencyList[a2Idx].push_back( pair<int,int>(a1Idx, a2Idx) );
    		ds.merge(a1Idx, a2Idx);
    	}
    }
//    for(int v1=0;v1<n_atoms;v1++){
//        for(int i=0;i<graph.adjacencyList[v1].size();i++){
//            int v2 = graph.adjacencyList[v1][i];
//            if(!ds.connected(v1,v2)){
//                adjacencyList[v1].push_back( std::make_pair(v1,v2) );
//                adjacencyList[v2].push_back( std::make_pair(v1,v2) );
//                ds.merge(v1,v2);
//            }
//        }
//    }

//    print();

    //Root all trees
    roots.push_back(0);
    rootTree(0, -1);
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

            rootTree(v,-1);
        }
    }

    //Reset transformations
    for(int i=0;i<n_atoms;i++){
//    	transformations[i] = QSTransform::Identity()
        transformations[i].setIdentity();
    }

}

//std::vector< Math3D::Vector3 >& KinematicForest::getPositions()
units::Coordinates* KinematicForest::getPositions()
{
    return positions;
}

int KinematicForest::getRoots()
{
	return roots.size();
}

int KinematicForest::getAtoms()
{
	return n_atoms;
}

units::Length KinematicForest::getDOFLength(int atom)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    units::Vector3L v = pos(atom)-pos(a1);

    return v.norm();
}

units::Angle KinematicForest::getDOFAngle(int atom)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of RowXpr instead of standard references
    units::Coordinates::RowXpr a0_pos = pos(atom);
    units::Coordinates::RowXpr a1_pos = pos(a1);
    units::Coordinates::RowXpr a2_pos = pos(a2);
    units::Vector3L v1 = a2_pos-a1_pos;
    units::Vector3L v2 = a0_pos-a1_pos;
    units::Length v1_len = v1.norm();
    units::Length v2_len = v2.norm();
    return acos(v1.dot(v2).value()/(v1_len*v2_len).value()) * units::radians;
    //return (v2-v1).angle( v0-v1 );
}

units::Length KinematicForest::getDOFTorsion(int atom)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    int a2 = parent(a1);
    int a3 = parent(a2);

//    Math3D::Vector3& v0 = pos(atom);
//    Math3D::Vector3& v1 = pos(a1);
//    Math3D::Vector3& v2 = pos(a2);
//    Math3D::Vector3& v3 = pos(a3);

    //TODO: Finish
    return 0;
}


void KinematicForest::changeDOFLength(int atom, units::Length value)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);

    units::Vector3L d = pos(atom)-pos(a1);
    d.normalize();
    d *= value;
    transformations_queue[atom].push_back(Eigen::Translation<units::Length,3>(d));
}

void KinematicForest::changeDOFAngle(int atom, units::Angle value)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of RowXpr instead of standard references
    units::Coordinates::RowXpr pos_a = pos(atom);
    units::Coordinates::RowXpr pos_a1 = pos(a1);
    units::Coordinates::RowXpr pos_a2 = pos(a2);
    units::Vector3L v1 = pos_a2- pos_a1;
    units::Vector3L v2 = pos_a - pos_a1;
    units::Vector3L axis = v1.cross(v2);
    axis.normalize();

//    // INSERTED TO ALLOW COMPILATION - should be replaced by actual angular value
//    units::Angle angle_value = 0. * units::radians;

    // NOTE: value has been replaced by angle_value for construction of AngleAxis
    transformations_queue[atom].push_back(
    		Eigen::Translation<units::Length, 3>(pos_a1)*
			Eigen::AngleAxis<units::Length>(value, axis)*
			Eigen::Translation<units::Length, 3>(-pos_a1)
    );
}

void KinematicForest::changeDOFTorsion(int atom, units::Angle value)
{
    assert(atom>=0 && atom<n_atoms);
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    // Note the use of RowXpr instead of standard references
    units::Coordinates::RowXpr pos_a1 = pos(a1);
    units::Coordinates::RowXpr pos_a2 = pos(a2);

    units::Vector3L axis = (pos_a2- pos_a1);
    axis.normalize();

//     INSERTED TO ALLOW COMPILATION - should be replaced by actual angular value
//    units::Angle angle_value = 0. * units::radians;

    transformations_queue[atom].push_back(
    		Eigen::Translation<units::Length, 3>( pos_a1) *
			Eigen::AngleAxis<units::Length>(value, axis) *
			Eigen::Translation<units::Length, 3>(-pos_a1)
			);

}

void KinematicForest::changeDOFglobal(int chain, Eigen::Transform<units::Length, 3, Eigen::Affine>& t)
{
	if(!pseudoRootsSet)	updatePseudoRoots();
	int idx1 = parent(parent(roots[chain]));
	transformations_queue[idx1].push_back( Eigen::Transform<units::Length, 3, Eigen::Affine>(t) );
}

void KinematicForest::updatePositions()
{
	if(!pseudoRootsSet)	updatePseudoRoots();
    forwardPropagateTransformations(-1);
}


void KinematicForest::forwardPropagateTransformations(int atom)
{
//	std::cout<<"forwardPropagateTransformations "<<atom<<std::endl;
    if(atom<0){
        for(size_t i=0;i<roots.size();i++){
            forwardPropagateTransformations(parent(parent(roots[i])));
        }
    }else{
        int p = parent(atom);

        if(p>=0)
        	transformations[atom] = transformations[p];
        else
        	transformations[atom].setIdentity();

        for(int i=0;i<transformations_queue[atom].size();i++){
        	transformations[atom] = transformations[atom] * transformations_queue[atom][i];
        }

        units::Coordinate orig_coord = units::Coordinate(positions->row(atom));
        stored_positions.row(atom) = orig_coord;
        QSTransform transform = transformations[atom];
        // NOTE: the .tranpose is necessary to obtain a column matrix. The .matrix
        // proved to be necessary to avoid a strange mistake about noalias.
        units::Coordinate new_coord = transform * orig_coord.matrix().transpose();
        positions->row(atom) = new_coord;


        for(int c=0;c<adjacencyList[atom].size();c++){
            if(adjacencyList[atom][c].second!=atom)
                forwardPropagateTransformations(adjacencyList[atom][c].second);
        }
        transformations[atom].setIdentity();
        transformations_queue[atom].clear();
    }
}

void KinematicForest::restorePositions()
{

}

units::Coordinates::RowXpr KinematicForest::pos(int i)
{
    assert(i>-4 && i<n_atoms);

//    switch(i){
//    case -3: return p2;
//    case -2: return p1;
//    case -1: return p0;
//    default: return positions[i];
//    }

    return positions->row(i);
}

void KinematicForest::rootTree(int v, int p)
{

    for(int c=0;c<adjacencyList[v].size();c++){
        if(adjacencyList[v][c].second==v && adjacencyList[v][c].first!=p){
            //Switch direction of edge
            int v2 = adjacencyList[v][c].first;
            adjacencyList[v][c].first = v;
            adjacencyList[v][c].second = v2;

            for(int c2=0;c2<adjacencyList[v2].size();c2++){
                if(adjacencyList[v2][c2].second==v){
                    adjacencyList[v2][c2].first = v;
                    adjacencyList[v2][c2].second = v2;
                    break;
                }
            }
        }
        if(adjacencyList[v][c].second != v)
            rootTree(adjacencyList[v][c].second, v);
    }
}

int KinematicForest::parent(int v)
{
//    if(v<0) return v-1;

    for(int c=0;c<adjacencyList[v].size();c++){
        if(adjacencyList[v][c].second==v)
            return adjacencyList[v][c].first;

    }
    return -1;
}

void KinematicForest::print()
{
    std::cout<<"KinematicForest:"<<std::endl;
    for(int v=0;v<adjacencyList.size();v++){
        std::cout<<"  adjacencies["<<v<<"]: ";
        for(int a=0;a<adjacencyList[v].size();a++){
            if(adjacencyList[v][a].second!=v)
                std::cout<<" "<<adjacencyList[v][a].second;
            //std::cout<<" "<<adjacencyList[v][a].first<<"->"<<adjacencyList[v][a].second;
        }

        std::cout<<std::endl;
    }

}

Topology* KinematicForest::getTopology()
{
	return topology;
}

const Topology::Atom& KinematicForest::getAtom(int atom)
{
	assert(atom>=0 && atom<n_atoms);

	return *id_atom_map[atom];
}


bool KinematicForest::atomMatchesNames(int atom, std::vector<std::string>& dofNames)
{

	int p1 = 0;
	int p2 = dofNames.size()-1;
	int a = atom;

	bool matchesForward = true;

	for(int p=0;p<dofNames.size();p++){
		if(a<0 || getAtom(a).name!=dofNames[p]) { matchesForward = false; break; }
		a = parent(a);
	}

	return matchesForward;

	//FIXME: Also look backward through dofNames and take special care of DoFs around roots of trees
//	a = atom;
//	for(int p=dofNames.size()-1;p>=0;p--){
//		if(getAtom(a).name!=dofNames[p]) { matchesForward = false; break; }
//		a = parent(a);
//	}
//
//	return false;
}


void KinematicForest::updatePseudoRoots()
{
    // NOTE: resize of matrix requires two size arguments
	pseudo_root_positions.resize(roots.size()*2, Eigen::NoChange);

	for(int r=0;r<roots.size();r++){
		int idxr = roots[r];
		int idx0 = n_atoms;
		int idx1 = idx0+1;

        // EXAMPLE: All four versions below work (complication is that Coordinate is an array, while Vector3 is a matrix)
        units::Coordinate p0 = positions->col( idxr ) + Eigen::Array3d(0.1, 0.0, 0.0)*units::nm;
        units::Coordinate p1 = positions->col( idxr ) + Eigen::Array3d(0.1, 0.1, 0.0)*units::nm;
        // units::Coordinate p0 = positions->col( idxr ) + (Vector3<double>(0.1, 0.0, 0.0)*units::nm).array() ;
        // units::Coordinate p1 = positions->col( idxr ) + (Vector3<double>(0.1, 0.1, 0.0)*units::nm).array();
        // units::Coordinate p0 = positions->col( idxr ) + units::Vector3L(0.1* units::nm, 0.0* units::nm, 0.0* units::nm).array() ;
        // units::Coordinate p1 = positions->col( idxr ) + units::Vector3L(0.1* units::nm, 0.1* units::nm, 0.0* units::nm).array();
		// units::Coordinate p0 = positions->col( idxr ) + units::Coordinate(0.1* units::nm, 0.0* units::nm, 0.0* units::nm) ;
		// units::Coordinate p1 = positions->col( idxr ) + units::Coordinate(0.1* units::nm, 0.1* units::nm, 0.0* units::nm);
		pseudo_root_positions.col(r*2  ) = p0;
		pseudo_root_positions.col(r*2+1) = p1;

		adjacencyList.push_back( std::vector< pair<int,int> >() );
		adjacencyList[idx0].push_back( std::make_pair( idx0, idxr ) );
		adjacencyList[idxr].push_back( std::make_pair( idx0, idxr ) );

		adjacencyList.push_back( std::vector< pair<int,int> >() );
		adjacencyList[idx1].push_back( std::make_pair( idx1, idx0 ) );
		adjacencyList[idx0].push_back( std::make_pair( idx1, idx0 ) );

		transformations.push_back(QSTransform::Identity());
		transformations.push_back(QSTransform::Identity());

		transformations_queue.push_back(std::vector<QSTransform>());
		transformations_queue.push_back(std::vector<QSTransform>());
	}

	pseudoRootsSet = true;
}




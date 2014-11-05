#include "quickstep/KinematicForest.h"

#include <iostream>
#include <math.h>
#include <assert.h>     /* assert */

#include "quickstep/DisjointSet.h"


using namespace std;
using namespace quickstep;

KinematicForest::KinematicForest(BondGraph &graph):
    adjacencyList(graph.numberOfAtoms()),
    positions(graph.numberOfAtoms(), Math3D::Vector3(0,0,0)),
//    p0(0,0,0), p1(1,0,0), p2(0,1,0),
    atoms(graph.numberOfAtoms()),
    transformations(graph.numberOfAtoms()),
    transformations_queue(graph.numberOfAtoms())
{

    //Kruskals algorithm for finding minimum spanning forest
    DisjointSet ds(graph.numberOfAtoms());
    for(int v1=0;v1<graph.numberOfAtoms();v1++){
        for(int i=0;i<graph.adjacencyList[v1].size();i++){
            int v2 = graph.adjacencyList[v1][i];
            if(!ds.connected(v1,v2)){
                adjacencyList[v1].push_back( std::make_pair(v1,v2) );
                adjacencyList[v2].push_back( std::make_pair(v1,v2) );
                ds.merge(v1,v2);
            }
        }
    }

    print();

    //Root all trees
    roots.push_back(0);
    rootTree(0, -1);
    for(int v=1;v<graph.numberOfAtoms();v++){
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
    for(int i=0;i<graph.numberOfAtoms();i++){
        transformations[i].setIdentity();
    }

}

std::vector< Math3D::Vector3 >& KinematicForest::getPositions()
{
    return positions;
}

int KinematicForest::getRoots()
{
	return roots.size();
}

int KinematicForest::getAtoms()
{
	return atoms;
}

double KinematicForest::getDOFLength(int atom)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    Math3D::Vector3& v0 = pos(atom);
    Math3D::Vector3& v1 = pos(a1);

    return v0.distance(v1);
}

double KinematicForest::getDOFAngle(int atom)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    int a2 = parent(a1);

    Math3D::Vector3& v0 = pos(atom);
    Math3D::Vector3& v1 = pos(a1);
    Math3D::Vector3& v2 = pos(a2);

    return (v2-v1).angle( v0-v1 );
}

double KinematicForest::getDOFTorsion(int atom)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();

    int a1 = parent(atom);
    int a2 = parent(a1);
    int a3 = parent(a2);

    Math3D::Vector3& v0 = pos(atom);
    Math3D::Vector3& v1 = pos(a1);
    Math3D::Vector3& v2 = pos(a2);
    Math3D::Vector3& v3 = pos(a3);

    //TODO: Finish
    return 0;
}


void KinematicForest::changeDOFLength(int atom, double value)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);

    Math3D::Vector3 d = pos(atom)-pos(a1);
    d*=value/d.length();
    Math3D::RigidTransform t;
    t.setIdentity();
    t.setTranslate(d);
    transformations_queue[atom].push_back(t);
}

void KinematicForest::changeDOFAngle(int atom, double value)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    Math3D::Vector3 v1 = pos(a2)-pos(a1);
    Math3D::Vector3 v2 = pos(atom)-pos(a1);
    Math3D::Vector3 axis = Math3D::cross(v1,v2);
    axis.inplaceNormalize();
    Math3D::RigidTransform t1; t1.setIdentity(); t1.setTranslate( pos(a1));
    Math3D::RigidTransform t2; t2.setIdentity(); t2.setRotate(axis, value);
    Math3D::RigidTransform t3; t3.setIdentity(); t3.setTranslate(-pos(a1));
    transformations_queue[atom].push_back( t1*t2*t3 );
}

void KinematicForest::changeDOFTorsion(int atom, double value)
{
    assert(atom>=0 && atom<positions.size());
    if(!pseudoRootsSet)	updatePseudoRoots();
    if(atom==0) return;

    int a1 = parent(atom);
    int a2 = parent(a1);

    Math3D::Vector3 axis = pos(a1)-pos(a2);
    axis.inplaceNormalize();

    Math3D::RigidTransform t1; t1.setIdentity(); t1.setTranslate( pos(a1));
    Math3D::RigidTransform t2; t2.setIdentity(); t2.setRotate(axis, value);
    Math3D::RigidTransform t3; t3.setIdentity(); t3.setTranslate(-pos(a1));
    transformations_queue[atom].push_back( t1*t2*t3 );

}

void KinematicForest::changeDOFglobal(int chain, Math3D::RigidTransform t)
{
	if(!pseudoRootsSet)	updatePseudoRoots();
//	cout<<"changeDOFglobal 1 .. "<<chain<<endl;
//	cout<<"changeDOFglobal 2 .. "<<roots[chain]<<endl;
//	cout<<"changeDOFglobal 3 .. "<<parent(roots[chain])<<endl;
	int idx1 = parent(parent(roots[chain]));
	transformations_queue[idx1].push_back(t);
}

void KinematicForest::updatePositions()
{
	if(!pseudoRootsSet)	updatePseudoRoots();

    forwardPropagateTransformations(-1);
}

void KinematicForest::forwardPropagateTransformations(int atom)
{
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
        	transformations[atom] *= transformations_queue[atom][i];
        }

        positions[atom] = transformations[atom]*positions[atom];

        for(int c=0;c<adjacencyList[atom].size();c++){
            if(adjacencyList[atom][c].second!=atom)
                forwardPropagateTransformations(adjacencyList[atom][c].second);
        }
        transformations[atom].setIdentity();
        transformations_queue[atom].clear();
    }
}


Math3D::Vector3& KinematicForest::pos(int i)
{
    assert(i>-4 && i<(int)positions.size());

//    switch(i){
//    case -3: return p2;
//    case -2: return p1;
//    case -1: return p0;
//    default: return positions[i];
//    }

    return positions[i];
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

void KinematicForest::updatePseudoRoots()
{
	for(int r=0;r<roots.size();r++){
		int idxr = roots[r];
		int idx0 = positions.size();
		int idx1 = idx0+1;

		Math3D::Vector3 p0 = positions[ idxr ] + Math3D::Vector3(0.1, 0.0, 0.0);
		Math3D::Vector3 p1 = positions[ idxr ] + Math3D::Vector3(0.1, 0.1, 0.0);
		positions.push_back(p0);
		positions.push_back(p1);

		adjacencyList.push_back( std::vector< pair<int,int> >() );
		adjacencyList[idx0].push_back( std::make_pair( idx0, idxr ) );
		adjacencyList[idxr].push_back( std::make_pair( idx0, idxr ) );

		adjacencyList.push_back( std::vector< pair<int,int> >() );
		adjacencyList[idx1].push_back( std::make_pair( idx1, idx0 ) );
		adjacencyList[idx0].push_back( std::make_pair( idx1, idx0 ) );

		transformations.push_back(Math3D::RigidTransform());
		transformations[idx0].setIdentity();

		transformations.push_back(Math3D::RigidTransform());
		transformations[idx1].setIdentity();

		transformations_queue.push_back(std::vector<Math3D::RigidTransform>());
		transformations_queue.push_back(std::vector<Math3D::RigidTransform>());
	}

	pseudoRootsSet = true;
}




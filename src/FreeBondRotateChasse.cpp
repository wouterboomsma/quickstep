/*
 * FreeBondRotateChasse.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include <quickstep/FreeBondRotateChasse.h>

#include <quickstep/math/primitives.h>

#include <algorithm>
#include <stack>

namespace quickstep {

FreeBondRotateChasse::FreeBondRotateChasse(float rotationMagnitude_):
		rotationMagnitude(rotationMagnitude_),
		cachedKinematicForest(0)
{

}

//FreeBondRotateChasse::~FreeBondRotateChasse() {
//	// TODO Auto-generated destructor stub
//}

bool FreeBondRotateChasse::step(KinematicForest& kf)
{
	//Ensure that rotatableBonds is in sync with kf
	prepareRotatableBonds(kf);

	//Find a random bond
	int bondAtom = rotatableBonds[ Math3D::Random01()*rotatableBonds.size() ];

	//Find a random angle
	float angle = Math3D::RandomAngleUniform(rotationMagnitude);

	//Perform torsion-change on all children leaving bondAtom
	for(int a=0;a<kf.adjacencyList[bondAtom].size();a++){
		int childAtom = kf.adjacencyList[bondAtom][a].second;
		if(childAtom!=bondAtom) //Not the parent edge
			kf.changeDOFTorsion( childAtom, angle );
	}

	return true;
}

void FreeBondRotateChasse::prepareRotatableBonds(KinematicForest& kf)
{
	if(cachedKinematicForest == &kf) return;

	rotatableBonds.clear();

	for(int r=0;r<kf.getRoots();r++){
			//Perform depth-first search starting from root r and collect rotatable atoms
			std::stack<int> stack;
			stack.push(kf.roots[r]);
			while(!stack.empty()){
				int v = stack.top();
				stack.pop();

				//v is only rotatable if its not a root
				auto it0 = std::find(kf.roots.begin(), kf.roots.end(), v);
				if(it0==kf.roots.end())
					rotatableBonds.push_back(v);

				for(int a=0;a<kf.adjacencyList[v].size();a++)
					if(kf.adjacencyList[v][a].first==v)
						stack.push(kf.adjacencyList[v][a].second);
			}
		}

		cachedKinematicForest = &kf;
}

} /* namespace quickstep */

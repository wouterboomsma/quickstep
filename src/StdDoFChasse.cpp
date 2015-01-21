/*
 * StdDoFChasse.cpp
 *
 *  Created on: Jan. 21, 2015
 *      Author: rfonseca
 */

#include <quickstep/StdDoFChasse.h>


namespace quickstep {

StdDoFChasse::StdDoFChasse(quickstep::KinematicForest &kf, std::string &dofs):
		dofController(kf, dofs)
{
}

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

} /* namespace quickstep */

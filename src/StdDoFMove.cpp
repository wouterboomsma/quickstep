/*
 * StdDoFMove.cpp
 *
 *  Created on: Jan. 21, 2015
 *      Author: rfonseca
 */

#include <quickstep/StdDoFMove.h>


namespace quickstep {

StdDoFMove::StdDoFMove(quickstep::KinematicForest &kf, std::vector< std::string > &dofs):
		dofController(kf, dofs)
{
}

bool StdDoFMove::step(KinematicForest& kf)
{
//	dofController.get
//	//Ensure that rotatableBonds is in sync with kf
//	prepareRotatableBonds(kf);
//
//	//Find a random bond
//	int bondAtom = rotatableBonds[ Math3D::Random01()*rotatableBonds.size() ];
//
//	//Find a random angle
//	float angle = Math3D::RandomAngleUniform(rotationMagnitude);
//
//	//Perform torsion-change on all children leaving bondAtom
//	for(int a=0;a<kf.adjacencyList[bondAtom].size();a++){
//		int childAtom = kf.adjacencyList[bondAtom][a].second;
//		if(childAtom!=bondAtom) //Not the parent edge
//			kf.changeDOFTorsion( childAtom, angle );
//	}
	int dof_num = dofController.numberOfDoFs();
	int dof_idx = (int)(Math3D::Random01()*dof_num);
	float angle = Math3D::RandomAngleUniform(1*3.1415/180.0);//1 degree
	dofController.changeDoF(dof_idx, angle);

	return true;
}

} /* namespace quickstep */

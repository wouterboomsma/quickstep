/*
 * StdDoFController.h
 *
 *  Created on: Dec 11, 2014
 *      Author: rfonseca
 */

#ifndef EXTERNAL_QUICKSTEP_SRC_DOFCONTROLLERS_STDDOFCONTROLLER_H_
#define EXTERNAL_QUICKSTEP_SRC_DOFCONTROLLERS_STDDOFCONTROLLER_H_

#include "quickstep/KinematicForest.h"

#include <string>
#include <vector>

using namespace std;

namespace quickstep{

/**
 * A class to conveniently control the degrees-of-freedom (DoFs) in a kinematic forest.
 * DoFs in the KinematicForest might not always be convenient to work with. For instance changing
 * the phi-angle of an alanine residue implies changing DOFs of all edges leaving the CA-atom.
 * Furthermore, DOFs are not named in a KinematicForest. The StdDoFController takes care of this
 * by taking a string representation of desired DoFs (either bond-length, angle, or torsion) in the
 * constructor and giving access to them through the DoFType and changeDoF functions.
 */
class StdDoFController {
public:
	/**
	 * TODO document
	 * Example of dofs for a protein backbone: "N-CA,CA-C,C-N,N-CA-C,N-CA-C-N,C-N-CA-C".
	 * This will make all backbone bond-lengths variable as well as the CA bond
	 * angle and phi+psi torsions.
	 */
	StdDoFController(KinematicForest &kf, vector< string > dofs);

	virtual ~StdDoFController();

	int numberOfDoFs();
	void changeDoF(int DoFIdx, double changeValueBy);
	int DoFType(int DoFIdx);
    void updatePositions();



	static const int DOF_BOND_LENGTH  = 0;
	static const int DOF_BOND_ANGLE   = 1;
	static const int DOF_BOND_TORSION = 2;
private:
	KinematicForest* kinematicForest;

	vector<int> dofAtoms;
	vector<int> dofTypes;

	vector<string>& split(const string &s, char delim, vector<string> &elems);
	vector<string>  split(const string &s, char delim);
};

}

#endif /* EXTERNAL_QUICKSTEP_SRC_DOFCONTROLLERS_STDDOFCONTROLLER_H_ */

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

class StdDoFController {
public:
	StdDoFController(KinematicForest &kf, vector< string > dofs);

	virtual ~StdDoFController();

	int numberOfDoFs();

	void changeDoF(int DoFIdx, double changeValueBy);

	int DoFType(int DoFIdx);


	static const int DOF_BOND_LENGTH  = 0;
	static const int DOF_BOND_ANGLE   = 1;
	static const int DOF_BOND_TORSION = 2;
private:
	KinematicForest* kinematicForest;

	vector<string>& split(const string &s, char delim, vector<string> &elems);
	vector<string>  split(const string &s, char delim);
};

}

#endif /* EXTERNAL_QUICKSTEP_SRC_DOFCONTROLLERS_STDDOFCONTROLLER_H_ */

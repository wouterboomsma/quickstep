/*
 * StdDoFController.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rfonseca
 */

#include <quickstep/dofControllers/stdDoFController.h>

#include <sstream>

using namespace std;

namespace quickstep{

StdDoFController::StdDoFController(KinematicForest &kf, vector< string > dofs): kinematicForest(&kf)
{
	kinematicForest = &kf;

	//Vectors containing atom-names. For instance
	//{ {"CA","CB"}, {"N","CA","C","N"}, {"CA","C","N","CA"}, ... }
	vector< vector<string> > dof_matches;

	//Parse dofs. Put result in dofMatches
	for( string& dof_str: dofs ){
		vector<string> tokens = split(dof_str, '-');
		dof_matches.push_back(tokens);
		reverse(tokens.begin(), tokens.end());
		dof_matches.push_back(tokens);
	}

	//Go through each atom. If it matches dofMatches, add a DoF
	Topology* top = kf.getTopology();
	for(int a=0; a<kf.getAtoms(); a++){
		for(int d=0;d<dof_matches.size();d++){
			if(kf.atomMatchesNames(a, dof_matches[d])){
				int atoms_in_dof = dof_matches[d].size();
				int dof_type = -1;
				switch(atoms_in_dof){
				case 2: dof_type = DOF_BOND_LENGTH; 	break;
				case 3: dof_type = DOF_BOND_ANGLE; 		break;
				case 4: dof_type = DOF_BOND_TORSION;	break;
				}
				dofAtoms.push_back(a);
				dofTypes.push_back(dof_type);
			}
		}
	}


}

StdDoFController::~StdDoFController() {


}

int StdDoFController::numberOfDoFs()
{
	return dofAtoms.size();
}

void StdDoFController::changeDoF(int DoFIdx, double changeValueBy)
{
	switch(dofTypes[DoFIdx]){
	case DOF_BOND_LENGTH: 	kinematicForest->changeDOFLength(	dofAtoms[DoFIdx], changeValueBy); 	break;
	case DOF_BOND_ANGLE: 	kinematicForest->changeDOFAngle(	dofAtoms[DoFIdx], changeValueBy); 	break;
	case DOF_BOND_TORSION: 	kinematicForest->changeDOFTorsion(	dofAtoms[DoFIdx], changeValueBy); 	break;
	}
}

int StdDoFController::DoFType(int DoFIdx)
{
	return dofTypes[DoFIdx];
}

void StdDoFController::updatePositions()
{
	kinematicForest->updatePositions();
}


vector<string>& StdDoFController::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> StdDoFController::split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

}

/*
 * StdDoFController.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rfonseca
 */

#include <quickstep/dofControllers/StdDoFController.h>

#include <sstream>

using namespace std;

namespace quickstep{

StdDoFController::StdDoFController(){}


StdDoFController::StdDoFController(KinematicForest &kf, vector< string > dofs): kinematic_forest(&kf)
{
	kinematic_forest = &kf;

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
	Topology* top = kf.get_topology();
	for(int a=0; a<kf.get_num_atoms(); a++){
		for(int d=0;d<dof_matches.size();d++){
			if(kf.atom_matches_names(a, dof_matches[d])){
				int atoms_in_dof = dof_matches[d].size();
				int dof_type = -1;
				switch(atoms_in_dof){
				case 2: dof_type = DOF_BOND_LENGTH; 	break;
				case 3: dof_type = DOF_BOND_ANGLE; 		break;
				case 4: dof_type = DOF_BOND_TORSION;	break;
				}
				dof_atoms.push_back(a);
				dof_types.push_back(dof_type);
			}
		}
	}


}

StdDoFController::~StdDoFController() {


}

int StdDoFController::numberOfDoFs()
{
	return dof_atoms.size();
}

void StdDoFController::changeDoF(int DoFIdx, double changeValueBy)
{
	switch(dof_types[DoFIdx]){
	case DOF_BOND_LENGTH: 	kinematic_forest->change_length(	dof_atoms[DoFIdx], changeValueBy*units::nm); 	break;
	case DOF_BOND_ANGLE: 	kinematic_forest->change_angle(	dof_atoms[DoFIdx], changeValueBy*units::rad); 	break;
	case DOF_BOND_TORSION: 	kinematic_forest->change_torsion(	dof_atoms[DoFIdx], changeValueBy*units::rad); 	break;
	}
}

int StdDoFController::DoFType(int DoFIdx)
{
	return dof_types[DoFIdx];
}

void StdDoFController::updatePositions()
{
	kinematic_forest->update_positions();
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

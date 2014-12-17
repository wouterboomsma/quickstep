/*
 * StdDoFController.cpp
 *
 *  Created on: Dec 11, 2014
 *      Author: rfonseca
 */

#include <StdDoFController.h>

#include <sstream>

using namespace std;

namespace quickstep{

StdDoFController::StdDoFController(KinematicForest &kf, vector< string > dofs): kinematicForest(&kf)
{
	//Vectors containing atom-names. For instance
	//{ {"N","CA","C","N"}, {"CA","C","N","CA"}, ... }
	vector< vector<string> > dof_matches;

	//Parse dofs. Put result in dofMatches
	for( string& dof_str: dofs ){
		vector<string> tokens = split(dof_str, '-');
		dof_matches.push_back(tokens);
		reverse(tokens.begin(), tokens.end());
		dof_matches.push_back(tokens);
	}

	//Go through each atom. If it matches the head or tail of an element in dofMatches check for a DoF
	Topology* top = kf.getTopology();
	for(int a=0; a<kf.getAtoms(); a++){
		string a0_name = kf.getAtom(a);
		kf.
	}
}

StdDoFController::~StdDoFController() {


}

int StdDoFController::numberOfDoFs()
{
	return 0;
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

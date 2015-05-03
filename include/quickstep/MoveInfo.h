/*
 * MoveInfo.h
 *
 *  Created on: 23/04/2015
 *      Author: rfonseca
 */

#ifndef EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_
#define EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_

#include <list>
#include <utility> //pair

#include "quickstep/KinematicForest.h"

namespace quickstep{

struct SubTree{
	int root_atom;
	std::list<int> excluded_atoms;
};

class SpecificMoveInfo{
public:
	virtual ~SpecificMoveInfo();
protected:
};

class MoveInfo{
public:
	MoveInfo(SpecificMoveInfo& smi);
	MoveInfo(const MoveInfo&); //Copy constructor
	~MoveInfo();
	SpecificMoveInfo specific_info;
//	std::list<std::pair<quickstep::DOFIndex, double>> dof_deltas;
	std::list<SubTree> affected_atoms;
};

}

#endif /* EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_ */

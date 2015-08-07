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

//struct SubTree{
//	int root_atom;
//	std::list<int> excluded_atoms;
//};

//class SpecificMoveInfo{
//public:
//	virtual ~SpecificMoveInfo();
//};


class MoveInfo {
public:
    MoveInfo(){}
    MoveInfo(const MoveInfo &other): dof_deltas(other.dof_deltas) {}
//	MoveInfo(std::unique_ptr<SpecificMoveInfo>&& smi);
//	std::unique_ptr<SpecificMoveInfo> specific_info;
//	std::list<SubTree> affected_atoms;
    std::list< std::pair<DOFIndex, double> > dof_deltas;
};

}

#endif /* EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_ */

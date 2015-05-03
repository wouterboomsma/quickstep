/*
 * StdDoFMove.cpp
 *
 *  Created on: Jan. 21, 2015
 *      Author: rfonseca
 */

#include <quickstep/StdDoFMove.h>

#include <vector>
#include <boost/algorithm/string.hpp>
#include "quickstep/utils.h"

namespace quickstep {

// "N-CA-C-N,C-N-CA-C,CA-C,N-CA-C"

StdDoFMove::StdDoFMove(std::string dofs):
		dofs(dofs)
{
}

MoveInfo StdDoFMove::step(KinematicForest& kf, bool suggest_only)
{
	if(!dof_controller || dof_controller->kinematic_forest != &kf){
		std::vector<std::string> dof_tokens;
		boost::split(dof_tokens, dofs, boost::is_any_of(","));
		dof_controller = make_unique<StdDoFController>(kf, dof_tokens);
	}

	int dof_num = dof_controller->numberOfDoFs();
	int dof_idx = rand()%dof_num;
	double value = ((rand()/RAND_MAX)-0.5)*2*3.1415/180.0;
//	units::Angle angle = ((rand()/RAND_MAX)-0.5)*2*3.1415/180.0 * units::rad;
	dof_controller->changeDoF(dof_idx, value);

	StdDoFMoveInfo info;
	DOFIndex dof = {dof_controller->dof_atoms[dof_idx], dof_controller->dof_types[dof_idx] };
	info.index = dof;
	info.delta_value = value;

	MoveInfo ret(info);

	SubTree affected_tree;
	affected_tree.root_atom = dof_controller->dof_atoms[dof_idx];
	ret.affected_atoms.push_back(affected_tree);

	return ret;
}

MoveInfo step_fractional(KinematicForest&, MoveInfo&);

} /* namespace quickstep */

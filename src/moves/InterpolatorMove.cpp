/*
 * CompositeMove.cpp
 *
 *  Created on: April 28, 2014
 *      Author: rfonseca
 */

#include "quickstep/moves/InterpolatorMove.h"

#include <memory>
#include <assert.h>
#include <iostream>

namespace quickstep {

InterpolatorMove::InterpolatorMove(std::shared_ptr<Move> move,
								   int interpolation_steps,
								   double max_dof_delta_per_interpolation_step):
		child_move(move),
		interpolation_steps(interpolation_steps),
		max_dof_delta_per_interpolation_step(max_dof_delta_per_interpolation_step),
		current_step(0)
{
}

void InterpolatorMove::setup_move(KinematicForest& kf) {

	current_move_info = std::make_unique<MoveInfo>( std::move(child_move->propose(kf)) );

	for( auto &dd: current_move_info->dof_deltas) {
		double dof_delta = dd.second / interpolation_steps;
		if (dof_delta > max_dof_delta_per_interpolation_step) {
			interpolation_steps = (int) ceil(dd.second / max_dof_delta_per_interpolation_step);
			std::cout << "Changing interpolation steps to: " << interpolation_steps << "\n";
		}
	}
}

MoveInfo InterpolatorMove::propose(KinematicForest& kf)
{
	if(current_step==interpolation_steps) {
		current_step = 0;
		current_move_info = nullptr;
	}

	if(current_step==0){
		if (!current_move_info)
			setup_move(kf);
	}

	//Scale each dof-change by a factor 1/interpolation_steps
	MoveInfo move_info(*current_move_info.get());
	for( auto &dd: move_info.dof_deltas){
		dd.second/=interpolation_steps;
	}

//	child_move->step_fractional(kf, *(current_move_info.get()), 1.0/interpolation_steps);

//	MoveInfo ret{ make_unique<InterpolationMoveInfo>() };
//	ret.affected_atoms = current_move_info->affected_atoms;

	current_step++;

	return move_info;
}

//void InterpolatorMove::step_fractional(KinematicForest&, MoveInfo&, double fraction)
//{
//	std::cerr<<"InterpolatorMove::step_fractional not implemented."<<std::endl;
//	//TODO: Throw proper exception
//}

MoveInfo *InterpolatorMove::get_current_move_info() {
	return current_move_info.get();
}

void InterpolatorMove::reject() {
	current_step = interpolation_steps;
}

int InterpolatorMove::get_interpolation_steps(KinematicForest &kf) {
	if (!current_move_info)
		setup_move(kf);
	return interpolation_steps;
}

} /* namespace quickstep */


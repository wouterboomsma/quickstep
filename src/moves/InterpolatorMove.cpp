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

InterpolatorMove::InterpolatorMove(std::unique_ptr<Move> m, int interpolation_steps):
		child_move(std::move(m)),
		interpolation_steps(interpolation_steps),
		current_step(0)
{
}

MoveInfo InterpolatorMove::propose(KinematicForest& kf)
{
	if(current_step==interpolation_steps)
		current_step = 0;

	if(current_step==0){
		current_move_info = std::make_unique<MoveInfo>( std::move(child_move->propose(kf)) );

	}

	//Scale each dof-change by a facter 1/interpolation_steps
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
} /* namespace quickstep */

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

MoveInfo InterpolatorMove::step(KinematicForest& kf, bool suggest_only)
{
	if(current_step==interpolation_steps){
		current_step = 0;
		current_move_info = make_unique<MoveInfo>( std::move(child_move->step(kf, true)) );
	}
	child_move->step_fractional(kf, *(current_move_info.get()), 1.0/interpolation_steps);

	MoveInfo ret{ make_unique<InterpolationMoveInfo>() };
//	InterpolationMoveInfo& spec_info = *dynamic_cast<InterpolationMoveInfo*>(ret.specific_info.get());
	ret.affected_atoms = current_move_info->affected_atoms;

	return ret;
}

void InterpolatorMove::step_fractional(KinematicForest&, MoveInfo&, double fraction)
{
	std::cerr<<"InterpolatorMove::step_fractional not implemented."<<std::endl;
	//TODO: Throw proper exception
}

} /* namespace quickstep */

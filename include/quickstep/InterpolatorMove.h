/*
 * InterpolatorMove.h
 *
 *  Created on: Apr 28, 2014
 *      Author: rfonseca
 */

#ifndef INTERPOLATORMOVE_H_
#define INTERPOLATORMOVE_H_

#include <quickstep/Move.h>
#include <quickstep/StdDoFMove.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/utils.h>

namespace quickstep {

class InterpolatorMove: public Move {
public:
	InterpolatorMove(std::unique_ptr<Move> move, int interpolation_steps=2048);

	MoveInfo step(KinematicForest&, bool suggest_only=false);
	MoveInfo step_fractional(KinematicForest&, MoveInfo&, double fraction);

private:
	std::unique_ptr<MoveInfo> current_move_info;

	int interpolation_steps;
	int current_step;
	std::unique_ptr<Move> child_move;
};

} /* namespace quickstep */

#endif /* INTERPOLATORMOVE_H_ */

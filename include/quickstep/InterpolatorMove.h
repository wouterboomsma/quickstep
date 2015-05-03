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
	InterpolatorMove(std::unique_ptr<Move> move);

	MoveInfo step(KinematicForest&, bool suggest_only=false);

private:
	std::unique_ptr<Move> child_move;
};

} /* namespace quickstep */

#endif /* INTERPOLATORMOVE_H_ */

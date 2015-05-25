/*
 * Move.h
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "quickstep/KinematicForest.h"
#include <quickstep/MoveInfo.h>

namespace quickstep {

/**
 * Interface for classes that can perform a conformational move to a kinematic forest.
 */
class Move {
public:
	Move(){}

	static std::unique_ptr<Move> parse(const std::string &xml_filename, const std::shared_ptr<Topology> &topology);

	virtual ~Move(){}

	/** Perform a conformational move with the kinematic forest.  */
	virtual MoveInfo step(KinematicForest&, bool suggest_only=false) = 0;

	/** Perform a conformational move toward   */
	virtual void step_fractional(KinematicForest&, MoveInfo&, double fraction) = 0;

};

struct StepFractionalNotImplementedError{
	StepFractionalNotImplementedError(){}
};


} /* namespace quickstep */

#endif /* MOVE_H_ */

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

	/** Suggest a conformational move using the provided kinematic forest.  */
	virtual MoveInfo propose(KinematicForest&) = 0;

	void perform(MoveInfo&);

};

} /* namespace quickstep */

#endif /* MOVE_H_ */

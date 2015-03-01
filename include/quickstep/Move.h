/*
 * Move.h
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#ifndef CHASSE_H_
#define CHASSE_H_

#include "quickstep/KinematicForest.h"

namespace quickstep {

/**
 * Interface for classes that can perform a conformational move to a kinematic forest.
 *
 * Wikipedia: Move or chassé (Fr. "to chase") is a dance step used in many dances in many variations.
 * All variations are triple-step patterns of gliding character in a "step-together-step" pattern. The
 * word came from ballet terminology.
 */
class Move {
public:
	Move(){}
	virtual ~Move(){}

	/** Perform a conformational move with the kinematic forest.  */
	virtual bool step(KinematicForest&) = 0;
};

} /* namespace quickstep */

#endif /* CHASSE_H_ */

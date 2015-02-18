/*
 * FreeBondRotateMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef STDDOFCHASSE_H_
#define STDDOFCHASSE_H_

#include <quickstep/Move.h>
#include <quickstep/dofControllers/StdDoFController.h>

#include <string>

namespace quickstep {

class StdDoFMove: public Move {
public:
	StdDoFMove(std::string dofs);

	bool step(KinematicForest&);

private:
	StdDoFController dof_controller;
	std::string dofs;
};

} /* namespace quickstep */

#endif /* STDDOFCHASSE_H_ */

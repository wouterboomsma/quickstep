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

#include <vector>

namespace quickstep {

class StdDoFMove: public Move {
public:
	StdDoFMove(quickstep::KinematicForest &kf, std::vector< std::string > &dofs);

	bool step(KinematicForest&);

private:
	StdDoFController dofController;
};

} /* namespace quickstep */

#endif /* STDDOFCHASSE_H_ */

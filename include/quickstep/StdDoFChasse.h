/*
 * FreeBondRotateChasse.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef STDDOFCHASSE_H_
#define STDDOFCHASSE_H_

#include <quickstep/Chasse.h>
#include <quickstep/dofControllers/StdDoFController.h>

#include <vector>

namespace quickstep {

class StdDoFChasse: public Chasse {
public:
	StdDoFChasse(quickstep::KinematicForest &kf, std::string &dofs);

	bool step(KinematicForest&);

private:
	StdDoFController dofController;
};

} /* namespace quickstep */

#endif /* STDDOFCHASSE_H_ */

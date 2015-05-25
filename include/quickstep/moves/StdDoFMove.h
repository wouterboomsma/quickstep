/*
 * StdDoFMove.h
 *
 *  Created on: Jan, 2015
 *      Author: rfonseca
 */

#ifndef STDDOFMOVE_H_
#define STDDOFMOVE_H_

#include <quickstep/moves/Move.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/dofControllers/StdDoFController.h>

#include <string>

namespace quickstep {

class StdDoFMove: public Move {
public:
	StdDoFMove(std::string dofs, double std=0.1);

	MoveInfo step(KinematicForest&, bool suggest_only=false);
	void step_fractional(KinematicForest&, MoveInfo&, double fraction);
private:
	std::unique_ptr<StdDoFController> dof_controller;
	std::string dofs;
	double std_deviation;
};


class StdDoFMoveInfo: public SpecificMoveInfo
{
public:
	DOFIndex index;
	int std_dof_index;
	double delta_value;
};

} /* namespace quickstep */

#endif /* STDDOFMOVE_H_ */

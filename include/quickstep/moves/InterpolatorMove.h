/*
 * InterpolatorMove.h
 *
 *  Created on: Apr 28, 2014
 *      Author: rfonseca
 */

#ifndef INTERPOLATORMOVE_H_
#define INTERPOLATORMOVE_H_

#include <quickstep/moves/Move.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/utils.h>

namespace quickstep {

class InterpolatorMove: public Move {
public:
	InterpolatorMove(std::shared_ptr<Move> move, int interpolation_steps=2048,
					 double max_dof_delta_per_interpolation_step=std::numeric_limits<double>::infinity());

	MoveInfo propose(KinematicForest&);
//	void step_fractional(KinematicForest&, MoveInfo&, double fraction);

	MoveInfo *get_current_move_info();

    virtual void accept() override;

    virtual void reject() override;

    int get_interpolation_steps();

private:

    void setup_move(KinematicForest& kf);

	std::unique_ptr<MoveInfo> current_move_info;

	int interpolation_steps;
    double max_dof_delta_per_interpolation_step;
	int current_step;
		int interpolation_steps_original;
	std::shared_ptr<Move> child_move;
};

//class InterpolationMoveInfo: public SpecificMoveInfo{
//public:
//	//TODO: Fill out in case we want to interpolate interpolations
//};


} /* namespace quickstep */

#endif /* INTERPOLATORMOVE_H_ */

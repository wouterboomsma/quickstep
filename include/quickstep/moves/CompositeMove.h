/*
 * CompositeMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef COMPOSITEMOVE_H_
#define COMPOSITEMOVE_H_

#include <quickstep/Move.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/utils.h>

#include <vector>
#include <random>

namespace quickstep {

class CompositeMove: public Move {
public:
	CompositeMove();
	~CompositeMove(){}

	MoveInfo step(KinematicForest&, bool suggest_only=false);

	void step_fractional(KinematicForest&, MoveInfo&, double);

	void add_move(std::unique_ptr<Move> c, double weight);

	static std::unique_ptr<CompositeMove> create_standard_move(std::default_random_engine &rand_eng);

private:
	std::vector<std::unique_ptr<Move>> moves;
	std::vector<double> accumWeights;
};

class CompositeMoveInfo: public SpecificMoveInfo
{
public:
	int chosen_move;
	std::unique_ptr<MoveInfo> chosen_info;
};

} /* namespace quickstep */

#endif /* COMPOSITEMOVE_H_ */

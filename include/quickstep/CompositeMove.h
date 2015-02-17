/*
 * CompositeMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef COMPOSITECHASSE_H_
#define COMPOSITECHASSE_H_

#include <quickstep/Move.h>
#include <quickstep/KinematicForest.h>

#include <vector>
#include <random>

namespace quickstep {

class CompositeMove: public Move {
public:
	CompositeMove();
//	virtual ~VarietyMove();

	bool step(KinematicForest&);

	void add_move(std::unique_ptr<Move> &c, double weight);

	static std::unique_ptr<CompositeMove> create_standard_move(std::default_random_engine &rand_eng);

private:
	std::vector<std::unique_ptr<Move>> chasses;
	std::vector<double> accumWeights;
};

} /* namespace quickstep */

#endif /* COMPOSITECHASSE_H_ */

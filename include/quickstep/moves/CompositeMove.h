/*
 * CompositeMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef COMPOSITE_MOVE_H_
#define COMPOSITE_MOVE_H_

#include <quickstep/moves/Move.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/MoveFactory.h>
#include <quickstep/utils.h>

#include <vector>
#include <random>
#include <qsboost/property_tree/ptree_fwd.hpp>

namespace quickstep {


class CompositeMove: public Move {
public:

    class MoveGenerator: public MoveFactory::MoveGenerator {
	public:
		virtual std::vector<std::unique_ptr<Move>> operator()(const qsboost::property_tree::ptree &parameter_input,
															  Topology &topology,
															  const MoveCommonDefinitions &move_common_defs,
															  const std::vector<std::shared_ptr<MoveSettings>> &move_settings) override;

		// NOTE: the registrator variable must be explicitly defined in the .cpp file as well
		const static struct Registrator {
			Registrator() {
				MoveFactory::get().register_generator("CompositeMove", std::make_unique<CompositeMove::MoveGenerator>());
			}
		} registrator;
	};

	CompositeMove();
	~CompositeMove(){}
	CompositeMove(CompositeMove &&other) = default;

	virtual MoveInfo propose(KinematicForest& kf);

//	MoveInfo step(KinematicForest&, bool suggest_only=false);
//
//	void step_fractional(KinematicForest&, MoveInfo&, double);

	Move *add_move(std::unique_ptr<Move> c, double weight=1.);

	static std::unique_ptr<CompositeMove> create_standard_move(std::default_random_engine &rand_eng);

	const std::vector<std::unique_ptr<Move>> &get_moves() const;

protected:
	std::vector<std::unique_ptr<Move>> moves;
	std::vector<double> accum_weights;
};

//class CompositeMoveInfo: public SpecificMoveInfo
//{
//public:
//	int chosen_move;
//	std::unique_ptr<MoveInfo> chosen_info;
//};

} /* namespace quickstep */

#endif /* COMPOSITE_MOVE_H_ */

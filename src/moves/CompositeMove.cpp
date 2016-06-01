/*
 * CompositeMove.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/moves/CompositeMove.h"

#include <memory>
#include <assert.h>
#include <quickstep/moves/CofMMove.h>
#include <quickstep/moves/FreeBondRotateMove.h>
#include <quickstep/MoveFactory.h>
#include <quickstep/MoveCommonDefinitions.h>
#include <qsboost/property_tree/ptree.hpp>

namespace quickstep {

CompositeMove::CompositeMove() {

}

MoveInfo CompositeMove::propose(KinematicForest& kf)
{
	assert(accum_weights.size()>0);

	float randVal = accum_weights.back() * (rand()*1.0/RAND_MAX);

	for(int i=0;i<accum_weights.size();i++){
		if(randVal<=accum_weights[i]){

//			MoveInfo ret{ make_unique<CompositeMoveInfo>() };
//			CompositeMoveInfo& spec_info = *dynamic_cast<CompositeMoveInfo*>(ret.specific_info.get());
//			spec_info.chosen_info = make_unique<MoveInfo>( std::move(moves[i]->step(kf, suggest_only)) );
//			spec_info.chosen_move = i;

		    MoveInfo ret = moves[i]->propose(kf);
			return ret;
		}
	}

	throw "Error: Sampled a random value higher than total accumulated weight";
}

//void CompositeMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
//{
//	CompositeMoveInfo* cmi = static_cast<CompositeMoveInfo*>(mi.specific_info.get());
//	moves[cmi->chosen_move]->step_fractional(kf, *cmi->chosen_info.get(), fraction);
//}

//void CompositeMove::add_move(std::unique_ptr<Move> m, double weight)
Move *CompositeMove::add_move(std::unique_ptr<Move> m, double weight)
{
	moves.push_back( std::move(m) );

	double weightSum = accum_weights.empty()?0.0:accum_weights[accum_weights.size()-1];
	accum_weights.push_back(weightSum+weight);
	return moves.back().get();
}

std::unique_ptr<CompositeMove> CompositeMove::create_standard_move(std::default_random_engine &rand_eng)
{
	std::unique_ptr<CompositeMove> ret(new CompositeMove());

	ret->add_move( std::make_unique<CofMMove>(0.01*units::nm, 0.05*units::radians), 0.05);      // max-translation: 0.1Å, max-rotation ~1 degree
	ret->add_move( std::make_unique<FreeBondRotateMove>(0.17*units::radians), 0.05);  // max-rotation: ~1 degree

	return ret;
}

// Register move generator with factory
const CompositeMove::MoveGenerator::Registrator CompositeMove::MoveGenerator::registrator;

std::vector<std::unique_ptr<Move>> CompositeMove::MoveGenerator::operator()(const qsboost::property_tree::ptree &parameter_input,
																			Topology &topology,
																			const MoveCommonDefinitions &move_common_defs,
																			const std::vector<std::shared_ptr<MoveSettings>> &move_settings) {
	auto root_node = parameter_input.begin();
	const std::string &node_name = root_node->first;
	// std::cout << "Initializing..." << node_name << "\n";
	auto move = std::make_unique<CompositeMove>();

	const auto name_attr = root_node->second.get_optional<std::string>("name");
	// if (name_attr)
	// 	std::cout << "name_attr: " << name_attr << "\n";
	const auto weight_attr = root_node->second.get_optional<std::string>("weight");
	// if (weight_attr)
	// 	std::cout << "weight_attr: " << weight_attr << "\n";

	for (const auto &child_node: parameter_input) {
		const std::string &node_name = child_node.first;
		if (node_name == "<xmlattr>" || node_name == "<xmlcomment>" || node_name == "Residues" || node_name == "Dofs") {
			continue;
		} else if (MoveFactory::get().has_generator(node_name)) {
			qsboost::optional<double> child_total_weight_attr = child_node.second.begin()->second.get_optional<double>("weight");
			double child_weight = 1.0;
			if (child_total_weight_attr)
				child_weight = *child_total_weight_attr;
			auto &&child_moves = MoveFactory::get().at(node_name)(child_node.second, topology, move_common_defs, move_settings);

			child_weight /= child_moves.size();

			for (auto &child_move: child_moves) {
				move->add_move(std::move(child_move), child_weight);
				// std::cout << "Added move with weight " << child_weight << " " << (child_total_weight_attr?*child_total_weight_attr:-1.) << " " << child_moves.size() << "\n";
			}
		} else {
			QSBOOST_THROW_EXCEPTION(FatalError() <<
									"No MoveGenerator found for : " << node_name);
		}
	}
	std::vector<std::unique_ptr<Move>> return_value;
	if (move->moves.size() > 0)
		return_value.push_back(std::move(move));
	return std::move(return_value);
}

const std::vector<std::unique_ptr<Move>> &CompositeMove::get_moves() const {
	return moves;
}
} /* namespace quickstep */
